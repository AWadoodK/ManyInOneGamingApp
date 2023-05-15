int snake_i_size = 30;
int snake_j_size = 30;
int snake_foodspawn;
int snake_board[30][30];
char snake_boarddisplay[30][30];
int yourfinalscore = 0;
void file(int diff, int score);
void makesnake_board()
{
    for (int i = 0; i < snake_i_size; i++)
    {
        for (int j = 0; j < snake_j_size; j++)
        {
            snake_board[i][j] = i * 30 + j;
            if (i == 0 || j == 0 || i == snake_i_size - 1 || j == snake_j_size - 1)
            {
                snake_boarddisplay[i][j] = 'X';
            }
            else
            {
                snake_boarddisplay[i][j] = ' ';
            }
        }
    }
}
class Snake
{
private:
    int snake_headX;
    int snake_headY;
    vector<int> body;
    int snake_length;
    int snake_currentposition;
    char currentdirection;

public:
    Snake()
    {
        snake_headX = 15;
        snake_headY = 15;
        body.push_back(465);
        snake_length = 1;
        snake_currentposition = 465;
        currentdirection = 'd';
    }
    void snake_updateposition(int x)
    {
        snake_headX = x / snake_i_size;
        snake_headY = x % snake_i_size;
        snake_currentposition = x;
        bool b = false;
        if (x == snake_foodspawn)
        {
            b = true;
            food();
            body.push_back(x);
            snake_currentposition = x;
            snake_length++;
        }
        else
        {
            body.erase(body.begin() + 0);
            body.push_back(x);
            snake_currentposition = x;
        }
    }
    void updatesnake_boardsnake()
    {
        for (int i = 0; i < snake_i_size; i++)
        {
            for (int j = 0; j < snake_j_size; j++)
            {
                if (i == 0 || j == 0 || i == snake_i_size - 1 || j == snake_j_size - 1)
                {
                    snake_boarddisplay[i][j] = 'X';
                }
                else
                {
                    snake_boarddisplay[i][j] = ' ';
                }
            }
        }
        for (int k = 0; k < snake_length; k++)
        {
            int x, y;
            x = body[k] / snake_i_size;
            y = body[k] % snake_i_size;
            snake_boarddisplay[x][y] = '+';
        }
        int x = snake_foodspawn / 30;
        int y = snake_foodspawn % 30;
        snake_boarddisplay[x][y] = '0';
    }
    void displaysnake_board(bool cond)
    {
        if (cond)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        }
        for (int i = 0; i < snake_i_size; i++)
        {
            for (int j = 0; j < snake_j_size; j++)
            {
                cout << snake_boarddisplay[i][j];
            }
            cout << endl;
        }
    }
    int food_y_pos()
    {
        int food_y;
        food_y = rand() % snake_i_size + 1;
        if (food_y == snake_j_size - 1)
        {
            food_y = food_y_pos();
        }
        return food_y;
    }
    int food_x_pos()
    {
        int food_x;
        food_x = rand() % snake_i_size + 1;
        if (food_x == snake_i_size - 1)
        {
            food_x = food_x_pos();
        }
        return food_x;
    }
    void food()
    {
        int x = food_x_pos();
        int y = food_y_pos();
        if (snake_boarddisplay[x][y] == ' ')
        {
            snake_foodspawn = x * snake_i_size + y;
            snake_boarddisplay[x][y] = 'O';
        }
        else
        {
            food();
        }
    }
    int snake_move()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                currentdirection = 'a';
                snake_headY--;
                break;
            case 'd':
                currentdirection = 'd';
                snake_headY++;
                break;
            case 'w':
                currentdirection = 'w';
                snake_headX--;
                break;
            case 's':
                currentdirection = 's';
                snake_headX++;
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
                snake_headY--;
                break;
            case 'd':
                snake_headY++;
                break;
            case 'w':
                snake_headX--;
                break;
            case 's':
                snake_headX++;
                break;
            default:
                break;
            }
        }
        return snake_headX * snake_i_size + snake_headY;
    }
    bool gameover()
    {
        bool condition = false;
        int x, y;
        for (int i = 0; i < snake_length; i++)
        {
            for (int j = i + 1; j < snake_length; j++)
            {
                if (body[i] == body[j])
                {
                    condition = true;
                    break;
                }
            }
        }
        for (int i = 0; i < snake_length; i++)
        {
            x = body[i] / snake_i_size;
            y = body[i] % snake_i_size;
            if (x == snake_i_size - 1 || x == 0 || y == snake_j_size - 1 || y == 0)
            {
                condition = true;
            }
        }
        return condition;
    }
    void gamestart(int Score_Multiplier, int refresh_rate, int difficulty_factor)
    {
        food();
        while (true)
        {
            bool game = gameover();
            displaysnake_board(true);
            int x = snake_move();
            snake_updateposition(x);
            updatesnake_boardsnake();
            cout << "Score: " << (snake_length - 1) * Score_Multiplier << endl;

            cout << endl;
            Sleep(refresh_rate);
            if (game)
            {
                cout << "you lost" << endl;
                break;
            }
        }
        file(difficulty_factor, (snake_length - 1) * 10);
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
    makesnake_board();
    s.food();
    s.updatesnake_boardsnake();
    s.displaysnake_board(false);
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
    makesnake_board();
    s.food();
    s.updatesnake_boardsnake();
    s.displaysnake_board(false);
    int play, score;
    cout << "Press w to snake_move up" << endl;
    cout << "Press a to snake_move left" << endl;
    cout << "Press s to snake_move down" << endl;
    cout << "Press d to snake_move right" << endl;
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