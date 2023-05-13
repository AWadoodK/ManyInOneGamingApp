#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;
int i_size = 30;
int j_size = 30;
int foodspawn;
int board[30][30];
char boarddisplay[30][30];
int yourfinalscore = 0;
void makeboard()
{
    for (int i = 0; i < i_size; i++)
    {
        for (int j = 0; j < j_size; j++)
        {
            board[i][j] = i * 30 + j;
            if (i == 0 || j == 0 || i == i_size - 1 || j == j_size - 1)
            {
                boarddisplay[i][j] = 'O';
            }
            else
            {
                boarddisplay[i][j] = ' ';
            }
        }
    }
}
class Snake
{
private:
    int headX;
    int headY;
    vector<int> body;
    int length;
    int currentposition;
    char currentdirection;
    friend void gamestart(Snake *s);

public:
    Snake()
    {
        headX = 15;
        headY = 15;
        body.push_back(465);
        length = 1;
        currentposition = 465;
        currentdirection = 'd';
    }
    void updateposition(int x)
    {
        headX = x / 30;
        headY = x % 30;
        currentposition = x;
        body.erase(body.begin() + 0);
        body.push_back(x);
    }
    void updateboardsnake()
    {
        for (int k = 0; k < body.size(); k++)
        {
            int x, y;
            x = body[k] / 30;
            y = body[k] % 30;
            for (int i = 0; i < i_size; i++)
            {
                for (int j = 0; j < j_size; j++)
                {
                    if (i == x && j == y)
                    {
                        boarddisplay[i][j] = '*';
                    }
                }
            }
        }
    }
    void displayboard()
    {
        system("cls");
        for (int i = 0; i < i_size; i++)
        {
            for (int j = 0; j < j_size; j++)
            {
                cout << boarddisplay[i][j];
            }
            cout << endl;
        }
    }
    int move()
    {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                    currentdirection = 'a';
                    headY--;
                    break;
                case 'd':
                    currentdirection = 'd';
                    headY++;
                    break;
                case 'w':
                    currentdirection = 'w';
                    headX--;
                    break;
                case 's':
                    currentdirection = 's';
                    headX++;
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (currentdirection)
            {
                 case 'a':
                    headY--;
                    break;
                case 'd':
                    headY++;
                    break;
                case 'w':
                    headX--;
                    break;
                case 's':
                    headX++;
                    break;
                default:
                    break;
            }
        }
        return headX*30 + headY;

    }
    void gamestart()
    {
        while(true)
        {
            displayboard();
            int x = move();
            cout<<x<<endl;
            updateposition(x);
            updateboardsnake();
            Sleep(100);
        }
    }
};
void hideCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = false; // Hide the cursor
    SetConsoleCursorInfo(handle, &cursorInfo);
}
int main()
{
    Snake s;
    hideCursor();
    makeboard();
    s.updateboardsnake();
    s.displayboard();
    int play;
    cout << "Press w to move up" << endl;
    cout << "Press a to move left" << endl;
    cout << "Press s to move down" << endl;
    cout << "Press d to move right" << endl;
    cout << "Press 1 key to start the game" << endl;
    cin >> play;
    if (play == 1)
    {
        s.gamestart();
    }
    else
    {
        cout << "Have a good day sir" << endl;
    }
}