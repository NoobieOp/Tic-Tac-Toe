#include<iostream>

using namespace std;
char board [3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char currentMarker;
int currentPlayer;

void drawBoard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"------------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"------------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
bool placeMarker(int slot)
{
    int row=slot/3;
    int col;

    if(slot%3==0)
    {
        row=row-1;
        col=2;
    }
    else
    {
        col=(slot%3)-1;
    }
   if(board[row][col]!='X' && board[row][col]!='O')
   {
    board[row][col]=currentMarker;
    return true;
   }
   else return false;
}
void swap()
{
    if(currentMarker=='X') currentMarker='O';
    else currentMarker='X';

    if(currentPlayer==1) currentPlayer=2;
    else currentPlayer=1;  
}
int winner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return currentPlayer;

        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return currentPlayer;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return currentPlayer;

        if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return currentPlayer;

        return 0;
}  
void game()
{
    cout<<"Welcome to the Tic Tac Toe game\n";
    cout<<"Player 1, choose your marker\n";  
    cout<<"X or O\n";

    currentPlayer=1;

    char markerP1;
    cin>>markerP1;

    drawBoard();

    currentMarker=markerP1;
    int playerWon;

    for(int i=0;i<9;i++)
    {
        cout<<"it's Player "<<currentPlayer<<"'s turn, Please select the slot\n";
         int slot;
         cin>>slot;

         if(slot<1 || slot>9)
         {
              cout<<"Invalid!, Please try another slot\n";
             i--;
             continue;
         }
         if(!placeMarker(slot))
         {
             cout<<"This slot is already occupied!, Please try another slot\n";
             i--;
             continue;
         }
         drawBoard();
         
         
         playerWon=winner();
         if(playerWon==1) {cout<<"Player 1 won the match\n"; break;}
         if(playerWon==2) {cout<<"player 2 won the match\n"; break;}
         swap();

    }
    if(playerWon==0)
    {
        cout<<"It's a tie\n";
    }
} 

int main()
{
    game();
    return 0;
}

