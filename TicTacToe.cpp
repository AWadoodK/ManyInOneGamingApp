#include <iostream>
using namespace std;
char player1 = 'X';
char player2 = '0';
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
bool game()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;
    return false;
}
void output()
{
    // display board
    cout << "\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < 3; j++)
        {
            cout <<"\t"<< board[i][j];
        }
        cout << endl<<endl;
    }
    cout << endl;
}
int main()
{
    cout << "\n\n\t\tTic-Tac-Toe\n\n\n";
    int option;
    int t = 1;
    cout << "\t\tPlayer 1 = " << player1 << endl;
    cout << "\t\tplayer 2 = " << player2 << endl;
    int turn = 0;
    output();
    while (turn < 9)
    {
        cout << "Enter player " << t << endl;
        cin >> option;
        if (option < 1 || option > 9)
        {
            cout << "invalid option" << endl;
            output();
            continue;
        }
        int row, col;
        // check if the box is already taken
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == option + '0')
                {
                    row = i;
                    col = j;
                }
            }
        }
        if (board[row][col] == player1 || board[row][col] == player2)
        {
            cout << "This box is taken" << endl;
            cout << "TRY AGAIN" << endl;
            output();
            continue;
        }
        else
        {
            if (t == 1)
                board[row][col] = player1;
            else
                board[row][col] = player2;
        }
        output();
        if (game() == true)
        {
            cout << "Player" << t << " Won!!" << endl;
            break;
        }
        if (t == 1)
            t = 2;
        else
            t = 1;
        turn++;
    }
    if (game() == false)
    {
        cout << "Its a Draw" << endl;
    }
}