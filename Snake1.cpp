#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
int i_size = 20;
int j_size = 50;
int boardposition[20][50];
char board[20][50];
using namespace std;
class Snake
{
    int current_head;
    vector<int>body;
    int size;

};
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
int main()
{
    cout << "Snake Game Easy lvl" << endl;
    vector<int> snake;
    int count = 10;
    boardrefresh();
    while (count > 0)
    {
        count--;
        boardrefresh();
        foodspawn(count);
        boarddisplay();
    }
}