# SFMLvania
SFMLvania is the creative title I came up with for the Castlevania inspired game I wanted to make using SFML.

## Current Features

Built in level editor
  - Save and loads level data to and from file
  - Customizeable tiles
  - Mouse compatability
  
Player (only partially implemented)
  - Gravity
  - Tile collision
  - Animated
  - Camera
  
Game engine stuff
  - Game state machine
  - Resource manager
  - Event system

## Building for Window's Visual Studio
[Download SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) and follow [this tutorial](https://www.youtube.com/watch?v=axIgxBQVBg0) to set up VS project with SFML. Then download this repository, placing ``src`` and ``res`` into the new VS project's directory (default path: ``source\repos\(project name)``).

## Controls
  - WASD and Space for player movement
  ### Editor Controls:
  - Arrow keys for camera movement in editor state
  - E to toggle between states
  - LShift to cycle through tile property types
  - LClick to place tiles, MClick to copy selected tile, RClick through tile properties

## Todo
  - ~~Fix memory leak when changing gamestates~~
  - Expand player class into complete entity component system
  - Fix horizontal player movement
  - Refactor and generify tile collision
  - Add gameplay (whip, enemies, more levels)

## Screenshots
![Screenshot](https://cdn.discordapp.com/attachments/746538931192987696/807424158811422750/unknown.png)
![Screenshot](https://cdn.discordapp.com/attachments/746538931192987696/807424521325248532/unknown.png)
![Screenshot](https://cdn.discordapp.com/attachments/746538931192987696/807426447450832927/unknown.png)
