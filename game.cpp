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
    
    int row, col, mc = 0;
    
    while (true)
    {
        display();
        std::cout << "row : ";
        std::cin >> row;
        std::cout << "column : ";
        std::cin >> col;
        
        if (arena[row - 1][col - 1] != 0 || row > 3 || col > 3 || row <= 0 || col <= 0)
        {
            std::cout << "Invalid input!!" << std::endl << std::endl;
            continue;
        }
        mc++;
        
        arena[row - 1][col - 1] = 1;
        
        if (mc < 9)
        {
            compMove();
        }
        
        int w = checkWin();
        
        // condition for wining
        if (w > 0)
        {
            display();
            std::cout << "You Win!!" << std::endl << std::endl;
            break;
        }
        
        // condition for losing
        if (w < 0)
        {
            display();
            std::cout << "You Lose!!" << std::endl << std::endl;
            break;
        }
        mc++;
        
        // condition for draw
        if (mc > 9)
        {
            std::cout << "Draw!!" << std::endl << std::endl;
            break;
        }
    }
}
