#include <iostream>
#include <cstdlib>
#include <iterator>
int checkWin();
using namespace std;

int arena[3][3] = {0};  //The array where main game occurs
int cop[3][3] = {0};    //Copy array for use of minimax move function
int nextEmpty()         //Finds next empty cell in the game, if none found it returns 0
{
    int i, j;
    for(i = 0 ;i < 3; i++)
    {
        for( j = 0; j < 3; j++)
        {
            if(arena[i][j]==0)  //If null found break the loop
            break;
        }
    }
    if(i==3&&j==3)              //If the array ran full without incurring any empty cell
    {
        return -1;
    }
    return (i*3+j);             //returning two elements at once, since we know that i,j wil be less than 3
}
void display()                  //displays the whole board to the user
{
    for(int i = 0 ;i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            
            if(arena[i][j]==1) cout<<"X";
            else if(arena[i][j] == 2) cout<<"O";
            if(j<2) cout<<"   | ";
        }
        cout<<endl;
        if(i<2) cout<<"------------"<<endl;
        else cout<<endl;
    }
}

void randCompMove()             //Move generation in Version 1.0 : random moves, for newer see compMove()
{
    int r, c;
    while(true)
    {
        r = rand()%3;           //generates a random number less than 3 and greater than 0
        c = rand()%3;
        if(arena[r][c]==0)      //checks if the cell at the rth row and cth column is empty
        {
           break;        
        }                       //else continue generating random numbers until empty cell found
    }
    arena[r][c] = 2;            //Put O in the place
}

int minimax(int r, int c, int maxplayer, int depth)     //The heart of Move Generation algorithm
{
    int n = checkWin();             //checks if the current board position is a win for anyone
    if(n==10) return n;             //
    if(n==-10) return n;            //
    if(nextEmpty()==-1)             // if there is no empty cell found return drawn position because Win is already checked for.
    {
        return 0;
    }
    if(maxplayer)                   // if the current player to move is 'X'
    {
        int best = -1000;           // initialize best to negative value
        for(int i = 0; i < 3; i++)      //iterate through all possible combinations
        {
            for(int j = 0; j < 3; j++)
            {
                if(arena[i][j]==0)          //if cell is empty
                {
                    arena[i][j] = 1;        //set cell to 'X'
                    best = max(best, minimax(i,j,0,depth+1));       // and compute best value between the current best and minimax of next moves
                    arena[i][j] = 0;                                //reset the cell value
                }
            }
        }
        return best-depth;                                          // An improved version of simple return best, it will look for faster win
    }
    else
    {
        int best = 1000;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(arena[i][j]==0)
                {
                    arena[i][j] = 2;
                    best = min(best, minimax(i,j,1,depth+1));
                    arena[i][j] = 0;
                }
            }
        }
        return best+depth;                                  // similarly improved version which will look for slower loss
    }
    
}

void compMove()                 //Move Generation Algorithm Version 1.1 : using minimax (under development)
{
    int r, c;
    int bestMove = 1000;
   for(int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 3; j++)
       {
           if(arena[i][j]==0)
           {
               arena[i][j] = 2;
               int t = minimax(i,j,1,1);
               arena[i][j] = 0;
               if(t<bestMove)
               {
                   r = i; c = j;
                   bestMove = t;
               }
               
           }
       }
   }
   arena[r][c] = 2;
}

int checkWin()                  //Checks if there is a win for the computer or the user
{
    for(int i = 0; i < 3;i++)
    {
        if(arena[i][0]!=0)
        {
            if(arena[i][0]==arena[i][1]&&arena[i][0]==arena[i][2])
            {
                if(arena[i][0] == 1) return 10;
                else if(arena[i][0] == 2) return -10;
            }
        }
        if(arena[0][i]!=0)
        {
            if(arena[0][i]==arena[1][i]&&arena[2][i]==arena[0][i])
            {
                if(arena[0][i] == 1) return 10;
                else if(arena[0][i] == 2) return -10;
            }
        }
        
    }
    
    if(arena[0][0]!=0 && (arena[0][0]==arena[1][1]&&arena[0][0]==arena[2][2]))
    {
        if(arena[0][0] == 1) return 10;
        else if(arena[0][0] == 2) return -10;
    }
    if(arena[0][2]!=0 && (arena[0][2]==arena[1][1]&&arena[0][2]==arena[2][0]))
    {
        if(arena[0][2] == 1) return 10;
        else if(arena[0][2] == 2) return -10;
    }
    return 0;
    
}

int main() {
    
    int r, c, mc = 0;
    while(true)
    {
        display();
        cout<<"User Turn : ";
        cin>>r>>c;
        if(arena[r-1][c-1]!=0||r>3||c>3||r<=0||c<=0)
        {
           cout<<"Invalid input!!"<<endl<<endl;
           continue;
        }
        mc++;
        arena[r-1][c-1] = 1;
        //copy(start(arena), end(arena), start(cop));     //copies data of arena to cop array
        if(mc<9) compMove();                            //only checks for moves if board has empty cell
        int w = checkWin();
        if(w>0)
        {
            display();
            cout<<"You Win!!"<<endl;
            break;
        }
        else if(w<0)
        {
            display();
            cout<<"You Lose!!"<<endl;
            break;
        }
        mc++;
        if(mc==10)
        {
            cout<<"Match Drawn"<<endl;
            break;
        }
    }
}
