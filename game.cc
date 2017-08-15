#include <iostream>
#include <cstdlib>
using namespace std;
int arena[3][3] = {0};
void display()
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

void compMove()
{
    int r, c;
    while(true)
    {
        r = rand()%3;
        c = rand()%3;
        if(arena[r][c]==0)
        {
           break;        
        }
    }
    arena[r][c] = 2;
}

int checkWin()
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
    if(arena[0][2]!=0 && (arena[0][2]==arena[1][1]&&arena[0][2]==arena[2][1]))
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
        if(mc<9) compMove();
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
    }
}
