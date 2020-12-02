#include <iostream>
#include <cstdlib>

#include "display.hpp"
#include "arena.hpp"

void display()
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            if (arena[i][j] == 1)
            {
                std::cout << "X";
            }
            
            else if (arena[i][j] == 2)
            {
                std::cout << "O";
            }
            
            if (j < 2)
            {
                std::cout << "   | ";
            }
        }
        
        std::cout << std::endl;
        
        if (i < 2)
        {
            std::cout << "------------" << std::endl;
        }
        
        else
            {
                std::cout << std::endl;
            }
    }
}
