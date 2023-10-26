#include <iostream>
#include "Board.hpp"
#include "Tile.hpp"

#define CTL (char)218 // ┌
#define CTR (char)191 // ┐
#define CBL (char)192 // └
#define CBR (char)217 // ┘
#define IPD (char)194 // ┬
#define IPU (char)193 // ┴
#define IPR (char)195 // ├
#define IPL (char)180 // ┤
#define SLV (char)179 // │
#define SLH (char)196 // ─
#define ICR (char)197 // ┼

// Constructor
Board::Board(int size[])
{
    this->width = size[0];
    this->height = size[1];
}

// Destructor
Board::~Board()
{
    std::cout << "BOARD WAS PURGED\n";
}

/** \brief
 * Tile Generator
 */
void Board::spawnTiles()
{
    std::cout << "J'ai ouvert la saint christie\n";

    int St;
    if (St >= 1)
    {
        for (int i = 0; i < St; i++)
        {
            int coord[] = { 1 + (rand() % 4), 1 + (rand() % 4) };
            std::cout << "Coord l40\n";

            // Check if the coordinate is empty
            if ((coord)) {
                if (rand() % 10 < 7) new Tile(2, coord);
                else new Tile(4, coord);

                std::cout << St << "<--- Coord l45\n";
            }
        }
        St = 1;
    }
    else
    {
        int coord[] = { 1 + (rand() % 4), 1 + (rand() % 4) };
        std::cout << St << "<--- Coord l40\n";

        // Check if the coordinate is empty
        if (rand() % 10 < 7) new Tile(2, coord);
        else new Tile(4, coord);
    }
}

/** \brief
 * Board drawing function
 * Can adapt to any size board
 * If there is data that would render outside of the board, they will not cause an issue, instead they'll never be read
 */
void Board::drawBoard()
{
    // Drawing top of board
    std::cout << CTL << SLH;
    for(int w = 0;  w < width-1;  w++)
    {
        std::cout << IPD << SLH;
    }
    std::cout << CTR << "\n";


    bool dataPrinted = false;                                       // Used to stop the while loop after a print for the tile place
    std::vector<Tile*>::const_iterator it = Tile::tileList.begin(); // Used in the while loop to access but not edit the Tiles' data

    // Drawing tiles and spacers
    for(int h = 0;  h < height;  h++)
    {
        std::cout << SLV;
        for(int w = 0;  w < width;  w++)
        {
            while(!dataPrinted && it != Tile::tileList.end()) // Scours the vector for every existing tiles
            {
                if((*it)->coord[0] == h+1 && (*it)->coord[1] == w+1) // Check if coordinates of tile matches
                {
                    // TODO : Replace with a switch case to print letters instead of values
                    std::cout << (*it)->value << SLV;
                    dataPrinted = true;
                }
                else{ ++it; }
            }
            if(!dataPrinted) { std::cout << ' ' << SLV; } // Prints a blank space if no match was found in the previous while loop
            it = Tile::tileList.begin();
            dataPrinted = false;
        }
        std::cout << "\n";

        // Drawing spacers
        if(h < height-1)
        {
            std::cout << IPR << SLH;
            for(int w = 0;  w < width-1;  w++)
            {
                std::cout << ICR << SLH;
            }
            std::cout << IPL << "\n";
        }
    }

    // Drawing bottom of board
    std::cout << CBL << SLH;
    for(int w = 0;  w < width-1;  w++)
    {
        std::cout << IPU << SLH;
    }
    std::cout << CBR << "\n";
}

/** \brief
 * Move and Fuse tiles upon input
 */
void Board::moveTiles()
{
    for (auto i : Tile::tileList)
    {
        std::cout << i << ", " << i->value << ", [" << i->coord[0] << "," << i->coord[1] << "]\n";
    }
};


/** \brief
 * Check condition for losing the game
 * This function isn't in main() since it needs access to the private data of the Tile class
 * Board is the friend of Tile
 *
 * \return Boolean used in main to update the gameOver variable
 */
 bool Board::chkLoss()
 {
    // if(Tile::tileList.size() == 16)
    if(true)
    {
        std::cout << "\n\nTILE LIST FULL\n\n";

        // Goes through all tiles to test every pairs (vertically and horizontally)
        for(Tile* testTile: Tile::tileList)
        {
            std::cout << "Testing on : [" << testTile->coord[0] << ", " << testTile->coord[1] << "]... ";

            // Tests if testTile is in the bottom-left corner
            if(testTile->coord[0] == this->height && testTile->coord[1] == this->width)
            {
                std::cout << "RED\n";
            }

            // If not, tests if testTile is in the bottom-most row
            else if(testTile->coord[0] == this->height)
            {
                std::cout << "BLUE\n";
            }

            // If not, tests if testTile is in the left-most column
            else if(testTile->coord[1] == this->width)
            {
                std::cout << "ORANGE\n";
            }

            else
            {
                std::cout << "GREEN\n";
            }

        }
    }
    return false;
 }

 /** \brief
  * Check condition for wining the game
  * This function isn't in main() since it needs access to the private data of the Tile class
  * Board is the friend of Tile
  *
  * \return Boolean used in main() to update the gameOver variable
  */
bool Board::chkWin()
{
    for(Tile* t: Tile::tileList)
    {
        if(t->value == 2048)
        {
            std::cout << "\nWow you did it ! :D\n\n\n" << std::endl;
            return true;
        }
    }
}
