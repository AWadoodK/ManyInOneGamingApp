#include<iostream>
#include<conio.h>
#include<vector>
#include<windows.h>
using namespace std;
int i_size = 20;
int j_size = 20;
char board[20][20];
//Copied Code
void hideCursor() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = false; // Hide the cursor
        SetConsoleCursorInfo(handle, &cursorInfo);
    }
//Copied Code
void boarddisplay()
{
    for (int i = 0; i < i_size; i++)
        {
            cout << "\t\t";
            for (int j = 0; j < j_size; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
}
void foodspawn(int count)
{
    srand(time(0) + count);
    int food_x = food_x_pos();
    int food_y = food_y_pos();
    for (int i = 0; i < i_size; i++)
        {
            for (int j = 0; j < j_size; j++)
            {
                if (i == food_x && j == food_y && i != i_size && j != j_size)
                {
                    board[i][j] = 'O';
                }
            }
        }
}
void checkinput()
{

}
int main()
{
    cout<<"Snake"<<endl;
    hideCursor();
    while(true)
    {
        boarddisplay();
        checkinput();
    }
    return 0;
}