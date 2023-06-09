#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include<sstream>
using namespace std;
int i_size = 30;
int j_size = 30;
int foodspawn;
int board[30][30];
char boarddisplay[30][30];
int yourfinalscore = 0;
void file(int diff, int score);
void makeboard()
{
    for (int i = 0; i < i_size; i++)
    {
        for (int j = 0; j < j_size; j++)
        {
            board[i][j] = i * 30 + j;
            if (i == 0 || j == 0 || i == i_size - 1 || j == j_size - 1)
            {
                boarddisplay[i][j] = 'X';
            }
            else
            {
                boarddisplay[i][j] = ' ';
            }
        }
    }
}
void Store_in_file(int newscore, string &path)
{
    ifstream file(path);
    stringstream updateContent;
    bool namefound = false;
    string line;
    string name;
    cout << "Enter your name: ";
    cin >> name;
    string player;
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, player, ',');
        if (name == player)
        {
            namefound = true;
            string currentscore;
            getline(ss, currentscore, ',');
            int score = stoi(currentscore);
            if (score < newscore)
            {
                // Update the Score
                updateContent << name << "," << newscore << endl;
            }
            else
            {
                // Keep the current Score
                updateContent << line << endl;
            }
        }
        else
        {
            updateContent << line << endl;
        }
    }
    if (!namefound)
    {
        updateContent << name << "," << newscore << endl;
    }
    file.close();
    ofstream write(path);
    if (!write.is_open())
    {
        cout << "Couldn't Open the file" << endl;
        return;
    }
    write << updateContent.str();
    write.close();
    cout << "Score Saved Successfully" << endl;
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
        headX = x / i_size;
        headY = x % i_size;
        currentposition = x;
        bool b = false;
        if (x == foodspawn)
        {
            b = true;
            food();
            body.push_back(x);
            currentposition = x;
            length++;
        }
        else
        {
            body.erase(body.begin() + 0);
            body.push_back(x);
            currentposition = x;
        }
    }
    void updateboardsnake()
    {
        for (int i = 0; i < i_size; i++)
        {
            for (int j = 0; j < j_size; j++)
            {
                if (i == 0 || j == 0 || i == i_size - 1 || j == j_size - 1)
                {
                    boarddisplay[i][j] = 'X';
                }
                else
                {
                    boarddisplay[i][j] = ' ';
                }
            }
        }
        for (int k = 0; k < length; k++)
        {
            int x, y;
            x = body[k] / i_size;
            y = body[k] % i_size;
            boarddisplay[x][y] = '+';
        }
        int x = foodspawn / 30;
        int y = foodspawn % 30;
        boarddisplay[x][y] = '0';
    }
    void displayboard(bool cond)
    {
        if (cond)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        }
        for (int i = 0; i < i_size; i++)
        {
            for (int j = 0; j < j_size; j++)
            {
                cout << boarddisplay[i][j];
            }
            cout << endl;
        }
    }
    int food_y_pos()
    {
        int food_y;
        food_y = rand() % i_size + 1;
        if (food_y == j_size - 1)
        {
            food_y = food_y_pos();
        }
        return food_y;
    }
    int food_x_pos()
    {
        int food_x;
        food_x = rand() % i_size + 1;
        if (food_x == i_size - 1)
        {
            food_x = food_x_pos();
        }
        return food_x;
    }
    void food()
    {
        int x = food_x_pos();
        int y = food_y_pos();
        if (boarddisplay[x][y] == ' ')
        {
            foodspawn = x * i_size + y;
            boarddisplay[x][y] = 'O';
        }
        else
        {
            food();
        }
    }
    int move()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
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
        return headX * i_size + headY;
    }
    bool gameover()
    {
        bool condition = false;
        int x, y;
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (body[i] == body[j])
                {
                    condition = true;
                    break;
                }
            }
        }
        for (int i = 0; i < length; i++)
        {
            x = body[i] / i_size;
            y = body[i] % i_size;
            if (x == i_size - 1 || x == 0 || y == j_size - 1 || y == 0)
            {
                condition = true;
            }
        }
        return condition;
    }
    void gamestart(int Score_Multiplier, int refresh_rate, int difficulty_factor)
    {
        food();
        int score;
        string path = "ScoreSnake.csv";
        while (true)
        {
            bool game = gameover();
            displayboard(true);
            int x = move();
            updateposition(x);
            updateboardsnake();
            score = (length -1)*Score_Multiplier;
            cout << "Score: " << score << endl;

            cout << endl;
            Sleep(refresh_rate);
            if (game)
            {
                cout << "you lost" << endl;
                break;
            }
        }
        Store_in_file(score,path);
    }
};
void file(int diff, int score)
{
    ifstream file("Snakescore.csv",ios::app);
    
}
void hideCursor()
{
    
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = false; // Hide the cursor
    SetConsoleCursorInfo(handle, &cursorInfo);
}
void Snakegame()
{
    int difficulty;
    Snake s;
    makeboard();
    s.food();
    s.updateboardsnake();
    s.displayboard(false);
    cout << "\n\n\t\tWelcome to Snake Game\n\n";
    cout << "Select Difficulty (default Easy)\n";
    cout << "(1)Easy (Slow Snake,  Score Multiplier 5)\n";
    cout << "(2)Intermediate (Fast Snake, Score Multiplier 10)\n";
    cout << "(3)Hard (Faster Snake, Score Multiplier 15)\n";
    cin >> difficulty;
    int Score_Multiplier, Refresh_Rate;
    if (difficulty == 2)
    {
        Score_Multiplier = 10;
        Refresh_Rate = 100;
    }
    else if (difficulty == 3)
    {
        Score_Multiplier = 15;
        Refresh_Rate = 60;
    }
    else
    {
        Score_Multiplier = 5;
        Refresh_Rate = 150;
    }
    system("cls");
    hideCursor();
    makeboard();
    s.food();
    s.updateboardsnake();
    s.displayboard(false);
    int play, score;
    cout << "Press w to move up" << endl;
    cout << "Press a to move left" << endl;
    cout << "Press s to move down" << endl;
    cout << "Press d to move right" << endl;
    cout << "Press 1 key to start the game" << endl;
    cin >> play;
    if (play == 1)
    {
        system("cls");
        s.gamestart(Score_Multiplier, Refresh_Rate, difficulty);
    }
    else
    {
        cout << "Have a good day sir" << endl;
    }
}
int main()
{
    Snakegame();
    return 0;
}