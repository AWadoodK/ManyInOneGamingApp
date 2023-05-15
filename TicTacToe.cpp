#include <iostream>
using namespace std;
char tictactoe_p1 = 'X';
char tictactoe_p2 = '0';
char tictactoe_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
bool tictactoe_game()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (tictactoe_board[i][0] == tictactoe_board[i][1] && tictactoe_board[i][1] == tictactoe_board[i][2])
            return true;
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (tictactoe_board[0][i] == tictactoe_board[1][i] && tictactoe_board[1][i] == tictactoe_board[2][i])
            return true;
    }
    // check diagonals
    if (tictactoe_board[0][0] == tictactoe_board[1][1] && tictactoe_board[1][1] == tictactoe_board[2][2])
        return true;
    if (tictactoe_board[2][0] == tictactoe_board[1][1] && tictactoe_board[1][1] == tictactoe_board[0][2])
        return true;
    return false;
}
void tictactoe_output()
{
    // display tictactoe_board
    cout << "\n\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < 3; j++)
        {
            cout <<"\t"<< tictactoe_board[i][j];
        }
        cout << endl<<endl;
    }
    cout << endl;
}
int main()
{
    cout << "\n\n\t\tTic-Tac-Toe\n\n\n";
    int titactoeoption;
    int t = 1;
    cout << "\t\tPlayer 1 = " << tictactoe_p1 << endl;
    cout << "\t\tplayer 2 = " << tictactoe_p2 << endl;
    int tictactoe_turn = 0;
    tictactoe_output();
    while (tictactoe_turn < 9)
    {
        cout << "\t\tPlayer " <<t<<" enter a number: \t";
        cin >> titactoeoption;
        if (titactoeoption < 1 || titactoeoption > 9)
        {
            cout << "invalid titactoeoption" << endl;
            system("cls");
            tictactoe_output();
            continue;
        }
        int tictactoe_row, tictactoe_col;
        // check if the box is already taken
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (tictactoe_board[i][j] == titactoeoption + '0')
                {
                    tictactoe_row = i;
                    tictactoe_col = j;
                }
            }
        }
        if (tictactoe_board[tictactoe_row][tictactoe_col] == tictactoe_p1 || tictactoe_board[tictactoe_row][tictactoe_col] == tictactoe_p2)
        {
            system("cls");
            cout << "This box is taken" << endl;
            cout << "TRY AGAIN" << endl;
            tictactoe_output();
            continue;
        }
        else
        {
            if (t == 1)
                tictactoe_board[tictactoe_row][tictactoe_col] = tictactoe_p1;
            else
                tictactoe_board[tictactoe_row][tictactoe_col] = tictactoe_p2;
        }
        system("cls");
        tictactoe_output();
        if (tictactoe_game() == true)
        {
            cout << "Player" << t << " Won!!" << endl;
            break;
        }
        if (t == 1)
            t = 2;
        else
            t = 1;
        tictactoe_turn++;
    }
    if (tictactoe_game() == false)
    {
        cout << "Its a Draw" << endl;
    }
}