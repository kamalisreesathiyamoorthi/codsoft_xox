#include <iostream>
using namespace std;

//printing the board
void print(char a[3][3]) {
    cout << "\n ------------- \n";
    for(int i = 0; i < 3; i++) {
        cout << " | ";
        for(int j = 0; j < 3; j++) {
            cout << a[i][j] << " | ";
        }
        cout << "\n ------------- \n";
    }
}
 //checking for the win
int checkwin(char b[3][3]) {
    for(int i = 0; i < 3; i++) {
        if((b[i][0] == 'x' && b[i][1] == 'x' && b[i][2] == 'x') || (b[i][0] == 'o' && b[i][1] == 'o' && b[i][2] == 'o') 
        || (b[0][0] =='o' && b[1][1]=='o'  && b[2][2] == 'o')|| (b[0][0]=='x'  && b[1][1]=='x' && b[2][2] == 'x'))
        {
            return 1; 
        }
    }
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int r, c; // row and column
    int turn;
    char player = 'x';
    
    for( turn = 0; turn < 9; turn++) {
        print(board); // printing the board
        cout << "player = " << player << endl;
        cout << "enter row and column :  ";
        cin >> r >> c;
        
        if(r < 0 || r >= 3 || c < 0 || c >= 3)
         {
            cout << "Invalid move....!\n";
            turn--;
        }
         else if(board[r][c] != ' ')
          {
            cout << "Cell already occupied....!\n";
            turn--;
        }
         else
          {
            board[r][c] = player;
            if(checkwin(board) == 1) 
            {
                print(board);
                cout<<"-\n";
                cout<<player<<" win the game \n"<<" congratulations!\n";
                break;
              }  
            }
             player = (player == 'x') ? 'o' : 'x'; // toggle players
        }
        //checking match draw
    if(turn==9)
    {
        cout<<"-- \n the match was draw\n";
    }

    
    return 0;
}
