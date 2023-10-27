#ifndef BOARD_HPP
#define BOARD_HPP

#include "tile.hpp"

class Board
{
    private:
        int width;
        int height;

        TileSet* tileSet;

    public:
        Board(int size[], TileSet* tileSetPtr);
        ~Board();

        void spawnTiles();
        void drawBoard();
        void moveTiles();  // RUINED

        bool chkLoss(); // RUINED
        bool chkWin();  // RUINED
};

#endif
