#include <iostream>
#include <cstdlib>
#include <ctime>

#include "arena.hpp"
#include "display.hpp"
#include "compMove.hpp"
#include "checkWin.hpp"

int main()
{
    srand (time (NULL)); //  to use the seed once to get all the results from a rand in compMove()
    
    int r, c, mc = 0;
    while (true)
    {
        display();
        std::cout << "row : ";
        std::cin >> r;
        std::cout << "column : ";
        std::cin >> c;
        
        if (arena[r - 1][c - 1] != 0 || r > 3 || c > 3 || r <= 0 || c <= 0)
        {
            std::cout << "Invalid input!!" << std::endl << std::endl;
            continue;
        }
        mc++;
        arena[r - 1][c - 1] = 1;
        if (mc < 9) compMove();
        int w = checkWin();
        if (w > 0)
        {
            display();
            std::cout << "You Win!!" << std::endl;
            break;
        }
        else if (w < 0)
        {
            display();
            std::cout << "You Lose!!" << std::endl;
            break;
        }
        mc++;
    }
}
