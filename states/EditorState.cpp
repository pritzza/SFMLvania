#include "EditorState.h"

#include "../util/GameData.h"

#include "../events/StateEvent.h"

EditorState::EditorState(GameData& data, const std::string& levelFileName)
	:
	State(data),
	levelFileName(levelFileName)
{}

void EditorState::init()
{
	this->initialized = true;

	ResourceManagers& rs = data.resourceManagers;

	// sets up debug text
	t.setFont(*rs.fontManager.load(FONTS::DEFAULT));
	t.setScale(.2f, .2f);
	t.setPosition(1, -1);

	rs.textureManager.add(TEXTURES::TILESET);

	l.tileMap.load(levelFileName, rs.textureManager);
	editor.init(rs.textureManager);

	p.init(*rs.textureManager.load(rs.textureManager.add(TEXTURES::SIMON)),
		0,  // id
		16,	// w
		32,  // h
		1,  // scale
		((l.tileMap.getWidth() * l.tileMap.getTile(0).getSize()) / 2) - (p.s.getPixelWidth()), // x
		((l.tileMap.getHeight() * l.tileMap.getTile(0).getSize()) / 2) - (p.s.getPixelHeight()),	// y
		4,	// key frames
		8	// tweens
	);

	data.camera.setPos(p.s.getPos().x , p.s.getPos().y);
	data.camera.setView();
}

EditorState::~EditorState()
{
	l.tileMap.save(this->levelFileName);

	data.resourceManagers.textureManager.remove(TEXTURES::TILESET);
	data.resourceManagers.textureManager.remove(TEXTURES::SIMON);
}

void EditorState::handleInput()
{
	// editor inputs
	const int mx = data.mouse.getPos().x + (data.camera.getPos().x * data.window.PIXEL_SIZE) - data.window.WINDOW_WIDTH/2;
	const int my = data.mouse.getPos().y + (data.camera.getPos().y * data.window.PIXEL_SIZE) - data.window.WINDOW_HEIGHT/2;
	TileMap& tm = l.tileMap;
	const int ts = Tile::LENGTH * Tile::SCALE * data.window.PIXEL_SIZE;	// tile size

	if (mx > 0 && mx < ts * tm.getWidth() && my > 0 && my < ts * tm.getHeight())	// if mouse is in bounds of tileMap
	{
		if (data.mouse.left.isTapped() || data.mouse.left.isHeld())	// put a tile down where the mouse is with the same properties of the tempTile
			editor.placeTile(data.eventHandler, l.tileMap, mx / ts, my / ts);

		if (data.mouse.middle.isTapped())	// copy the properties of the tile you're mouse is over to the tempTile
			editor.copyTile(tm.getTile(mx / ts + ((my / ts) * tm.getWidth())));
	}

	if (data.keyBoard.shift.isTapped())	// iterate over the property you have selected for the tempTile
		editor.iterateProperties();

	if (data.mouse.right.isTapped())	// iterate through the elements of the current property
		editor.iterateElements();


	// player movement
	if (data.keyBoard.space.isHeld() || data.keyBoard.space.isTapped())
		p.jump();
	else if (data.keyBoard.space.isReleased())
		p.stopJump();

	if (data.keyBoard.w.isHeld() || data.keyBoard.w.isTapped())
		p.move(0, -1, data.keyBoard.w.isTapped());
	if (data.keyBoard.a.isHeld() || data.keyBoard.a.isTapped())
		p.move(-1, 0, data.keyBoard.a.isTapped());
	if (data.keyBoard.s.isHeld() || data.keyBoard.s.isTapped())
		p.move(0, 1, data.keyBoard.s.isTapped());
	if (data.keyBoard.d.isHeld() || data.keyBoard.d.isTapped())
		p.move(1, 0, data.keyBoard.d.isTapped());

	// camera movement
	if (data.keyBoard.up.isHeld() || data.keyBoard.up.isTapped())
		data.camera.move(0, -1);
	if (data.keyBoard.left.isHeld() || data.keyBoard.left.isTapped())
		data.camera.move(-1, 0);
	if (data.keyBoard.down.isHeld() || data.keyBoard.down.isTapped())
		data.camera.move(0, 1);
	if (data.keyBoard.right.isHeld() || data.keyBoard.right.isTapped())
		data.camera.move(1, 0);

	// toggle state
	if (data.keyBoard.e.isTapped())	
	{
		data.eventHandler.addEvent(std::make_unique<StateEvent>(data, STATES::EDITOR, STATE_EVENT_TYPE::REMOVE));
		data.eventHandler.addEvent(std::make_unique<StateEvent>(data, STATES::GAME, STATE_EVENT_TYPE::ADD, LEVEL::CHAMBER));
		data.eventHandler.addEvent(std::make_unique<StateEvent>(data, STATES::GAME, STATE_EVENT_TYPE::CHANGE));
	}
}

void EditorState::update(const float dt, const int f)
{
	const int ts = Tile::LENGTH * Tile::SCALE * data.window.PIXEL_SIZE;	// tile size
	const int x = (data.mouse.getPos().x + (data.camera.getPos().x * data.window.PIXEL_SIZE) - data.window.WINDOW_WIDTH  / 2) / ts;
	const int y = (data.mouse.getPos().y + (data.camera.getPos().y * data.window.PIXEL_SIZE) - data.window.WINDOW_HEIGHT / 2) / ts;

	editor.update(x, y);

	for (int i = 0; i < l.tileMap.getHeight() * l.tileMap.getWidth(); ++i)
		l.tileMap.getTile(i).setOutlineThickness(1);

	p.update(dt, l.tileMap);

	t.setPosition(data.camera.getPos().x - (data.window.WINDOW_WIDTH / (2 * data.window.PIXEL_SIZE)), data.camera.getPos().y - (data.window.WINDOW_HEIGHT / (2 * data.window.PIXEL_SIZE)));
	t.setString(
		"F: " + std::to_string(f) +
		"\nFPS : " + std::to_string(1.f / dt) +
		"\nx: " + std::to_string(static_cast<int>(p.s.getPos().x)) + " + " + std::to_string(p.getVel().x) + " + " + std::to_string(p.getAcc().x) +
		"\ny: " + std::to_string(static_cast<int>(p.s.getPos().y)) + " + " + std::to_string(p.getVel().y) + " + " + std::to_string(p.getAcc().y) +
		"\n(" + std::to_string(x) + ", " + std::to_string(y) + ")"
	);

	data.camera.setView();
}

void EditorState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w, true);

	editor.getTile().draw(w, true);

	p.s.draw(w, true);

	for (int i = 0; i < (p.s.bb.getSize().x + 1) * (p.s.bb.getSize().y + 1); ++i)
		w.draw(p.boundingBoxes[i].getRect());

	w.draw(t);

	w.endDraw();
}
