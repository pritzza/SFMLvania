#include "Game.h"

int main()
{
    Game game("SFMLvania", 1920/2, 1080/2, 60);

    game.gameLoop();

    return 0;
}