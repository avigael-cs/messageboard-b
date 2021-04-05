#include "Board.hpp"
using namespace std;

namespace ariel {
   
    void Board::post(unsigned int row, unsigned int col, Direction drct, string const &msg) 
    {
        //Updates the board according to the message
        this->maxRow = max(this->maxRow, row);
        this->minRow = min(this->minRow, row);
        this->maxCol = max(this->maxCol, col);
        this->minCol = min(this->minCol, col);
        
        unsigned int length = 0;

        //Write the message on the board
        for(char c: msg)
        {
            this->myBoard[row][col].entry = c;
            if(drct == Direction::Horizontal){
                col++;
            }
            else
            {
                row++;
            }
            length++;
        }
        if(drct == Direction::Horizontal){
                maxCol+=length;
            }
            else
            {
                maxRow+=length;
            }
    }

    
    std::string Board::read(unsigned int row, unsigned int col, Direction drct, unsigned int length) 
    {
        string msg;
        for(unsigned int i=0; i<length; i++){
            msg += this->myBoard[row][col].entry;
            if(drct == Direction::Horizontal){
                col++;
            }
            else
            {
                row++;
            }        
        }
        return msg;
    }

    
    //brief Displays the board to the screen
    void Board::show() 
    {
        for (unsigned int row = this->minRow; row <= this->maxRow; row++) 
        {
            for (unsigned int col = this->minCol; col <= this->maxCol; col++) 
            {
                cout << this->myBoard[row][col].entry;
            }
            cout << endl;
        }
    }
}