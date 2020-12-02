#include <cstdlib>

#include "compMove.hpp"
#include "arena.hpp"

void compMove()
{
    int r, c;
    while (true)
    {
        r = rand() % 3;
        c = rand() % 3;
        if (arena[r][c] == 0)
        {
           break;
        }
    }
    arena [r][c] = 2;
}
