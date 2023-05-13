#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <windows.h>
#include <conio.h>
int i_size = 30;
int j_size = 30;
int direction;
int boardposition[30][30];
char board[30][30];
using namespace std;
class Snake
{
    public:
    int current_headX;
    int current_headY;
    vector<int>body;
    int size;
    char currentdirection;
    Snake()
    {
        current_headX = 15;
        current_headY = 15;
        body.push_back(150);
        size = 1;
        currentdirection = 'd';
    }
};
void control()
{
    cout<<"w for up"<<endl;
    cout<<"a for left"<<endl;
    cout<<"d for right"<<endl;
    cout<<"s for down"<<endl;

}
void hideCursor() {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = false; // Hide the cursor
        SetConsoleCursorInfo(handle, &cursorInfo);
    }
int food_y_pos()
{
    int food_y;
    food_y = rand() % i_size + 1;
    if(food_y == j_size-1)
    {
        food_y = food_y_pos();
    }
    return food_y;
}
int food_x_pos()
{
    int food_x;
    food_x = rand() % i_size + 1;
    if(food_x == i_size - 1)
    {
        food_x = food_y_pos();
    }
    return food_x;
}
void boardrefresh()
{
    for (int i = 0; i < i_size; i++)
    {
        for (int j = 0; j < j_size; j++)
        {
            if (i == 0 || j == 0 || i == i_size - 1 || j == j_size - 1)
            {
                board[i][j] = '*';
                boardposition[i][j] = 0;
            }
            else
            {
                board[i][j] = ' ';
                boardposition[i][j] = 2;
            }
        }
    }
}
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
bool gameover()
{
    
}
void checkinput(Snake *s)
{
    if(kbhit())
    {
        char c = getch();
        switch(c)
        {
            case 'a':
                    direction = 1;
                    break;
            case 'w':
                    direction = 2;
                    break;
            case 'd':
                    direction = 3;
                    break;
            case 's':
                    direction = 4;
                    break;
            default:
                break;
        }
    }
    else
    {
        direction = s->currentdirection;
    }
}
void movement(Snake *s)
{
    if(direction == 1)
    {
        s->current_headX++;
    }
    else if(direction == 2)
    {
        s->current_headY++;
    }
    else if(direction == 3)
    {
        s->current_headX--;
    }
    else if(direction == 4)
    {
        s->current_headY--;
    }
}
int main()
{
    cout << "Snake Game Easy lvl" << endl;
    Snake s;
    int count = 1;
    hideCursor();
    boardrefresh();
    
    while(!gameover())
    {
        count++;
        foodspawn(count);
        boarddisplay();
        checkinput(&s);
        movement(&s);
        Sleep(100);
        control();
    }
}