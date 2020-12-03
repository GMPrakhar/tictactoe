#include <cstdlib>

#include "compMove.hpp"
#include "arena.hpp"

void compMove()
{
    int row, col;
    
    // comp is trying first get middle field
    // because that way is more chance to win
    
    if (arena[1][1] == 0)
    {
        arena[1][1] = 2;
    }
    
    // if in the middle fild already checked by player, then:
    
    else
    {
        while (true)
        {
            row = rand() % 3;
            col = rand() % 3;
            if (arena[row][col] == 0)
            {
               break;
            }
        }
        arena [row][col] = 2;
    }
}
