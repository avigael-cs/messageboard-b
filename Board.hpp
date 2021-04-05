#include <iostream>
#include <string>
#include <map>
#include <limits.h>
#include "Direction.hpp"

#define DEAFULT_CHAR '_'
using namespace std;

struct cube{
    char entry = DEAFULT_CHAR;
};

namespace ariel {
    class Board {
        unsigned int minRow, maxRow, minCol, maxCol;
        map<unsigned int, map<unsigned int, cube>> myBoard;
    public:
        Board() { 
            maxRow = 0;
            minRow = UINT_MAX;  
            maxCol = 0;
            minCol = UINT_MAX;
        }
        ~Board() {}
        void post(unsigned int row, unsigned int col, Direction direction, string const &msg);
        string read(unsigned int row, unsigned int col, Direction direction, uint length);
        void show();
    };
}