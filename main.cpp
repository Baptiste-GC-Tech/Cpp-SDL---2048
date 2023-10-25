#include <iostream>
#include "Class/board.hpp"
#include "Class/tile.hpp"

int main()
{
    // Values and utilities
    int boardSize[] = {4, 4};
    Board board(boardSize);

    int coord1[] = {1, 1};
    Tile test1(2, coord1);
    int coord2[] = {2, 3};
    Tile test2(8, coord2);
    int coord3[] = {1, 4};
    Tile test3(4, coord3);

    Tile::peek();
    board.drawBoard();

    return 0;
}
