#include <cstdlib>

#include "checkWin.hpp"
#include "arena.hpp"

int checkWin()
{
    for (int i = 0 ; i < 3 ; i++)
    {
// here checking rows for 3 symbols in one line
        
        if (arena[i][0] != 0)
        {
            if (arena[i][0] == arena[i][1] && arena[i][0] == arena[i][2])
            {
                if (arena[i][0] == 1)
                    {
                        return 10;
                    }
                else if (arena[i][0] == 2)
                    {
                        return -10;
                    }
            }
        }
// here checking columns for 3 symbols in one column
        
        if (arena[0][i] != 0)
        {
            if (arena[0][i] == arena[1][i] && arena[2][i] == arena[0][i])
            {
                if (arena[0][i] == 1)
                    {
                        return 10;
                    }
                else if (arena[0][i] == 2)
                    {
                        return -10;
                    }
            }
        }
    }
            
// here checking diagonality [0][0] to [2][2]
    
    if (arena[0][0] != 0 && (arena[0][0] == arena[1][1] && arena[0][0] == arena[2][2]))
    {
        if (arena[0][0] == 1)
        {
            return 10;
        }
        else if (arena[0][0] == 2)
        {
            return -10;
        }
    }
    
// here checking diagonality [0][2] to [2][0]
    
    if (arena[0][2] !=0 && (arena[0][2] == arena[1][1] && arena[0][2] == arena[2][0])) 
    {
        if (arena[0][2] == 1)
            {
                return 10;
            }
        else if (arena[0][2] == 2)
            {
                return -10;
            }
    }
    return 0;
}
