
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;





//SNAKE GAME
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
        while (true)
        {
            bool game = gameover();
            displayboard(true);
            int x = move();
            updateposition(x);
            updateboardsnake();
            cout << "Score: " << (length - 1) * Score_Multiplier << endl;

            cout << endl;
            Sleep(refresh_rate);
            if (game)
            {
                cout << "you lost" << endl;
                break;
            }
        }
        file(difficulty_factor, (length - 1) * 10);
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



//TIC TAC TOE
char show;
int again=0;
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
            if(j<2){
            cout<<"\t|";
            }
        }
        
        cout << endl;
        cout<<"\t\t---------------------------------------------------"<<endl;
    }
    cout << endl;
}
int tictactoe()
{ do{
    system("cls");
    cout<<"\t\t---------------------------------------------------"<<endl;
    cout << "\n\n\t\t\t\tTic-Tac-Toe\n\n\n";
    cout<<"\t\t---------------------------------------------------"<<endl;
    int titactoeoption;
    int t = 1;
    cout<<"\t\t---------------------------------------------------"<<endl;
    cout << "\t\t\t\tPlayer 1 = " << tictactoe_p1 << endl;
    cout << "\t\t\t\tplayer 2 = " << tictactoe_p2 << endl;
    cout<<"\t\t---------------------------------------------------"<<endl;
    int tictactoe_turn = 0;
    tictactoe_output();
    while (tictactoe_turn < 9)
    {
        show=tictactoe_p1;
        cout << "\t\tPlayer " <<t<<" enter a number to Replace "<<show <<" with: \t";
        cin >> titactoeoption;
        if (titactoeoption < 1 || titactoeoption > 9)
        {
            cout << "Invalid titactoeoption" << endl;
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
        if (t == 1){
            t = 2;
            show=tictactoe_p2;
            }
        else{
            t = 1;
            show=tictactoe_p1;
        }
        tictactoe_turn++;
    }
    if (tictactoe_game() == false)
    {
        cout << "Its a Draw" << endl;
    }
    cout<<"\n";
    cout<<"Enter 1 to Exit or 0 to Play Again?\n";
    cin>>again;
}while(again==0);
return 0;
}





void Singleplayer()
{
    int option;
    bool condition = true;
    do
    {   system("cls");
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t         Game Menu           " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. Snake Game              " << endl;
        cout << "\t\t   2. Hangman                 " << endl;
        cout << "\t\t   3. Wordly                  " << endl;
        cout << "\t\t   4. Back to Main            " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cin>>option;
        cout<<endl<<endl;
        switch (option)
        {
            case 1:
                Snakegame();
                break;

            case 2:
                //Hangman();
                break;
            case 3:
                //Wordly();
                break;
            case 4:
                condition = false;
                system("cls");
                break;
            default:
                cout<<"Invalid Option";
                break;
        }
    } while (condition);
    

}
void Multiplayer()
{
    int option;
    bool condition = true;
    do
    {   system("cls");
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t          Game Menu           " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                             " << endl;
        cout << "\t\t                             " << endl;
        cout << "\t\t   1. TicTacToe               " << endl;
        cout << "\t\t   2. Truth And Dare          " << endl;
        cout << "\t\t   3. Back to Main            " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cin>>option;
        cout<<endl<<endl;
        switch (option)
        {
            case 1:
                tictactoe();
                break;

            case 2:
                //Truth_n_Dare();
                break;

            case 3:
                condition = false;
                system("cls");
                break;

            default:
                cout<<"Invalid Option";

                break;
        }
    }while(condition);
}
int main()
{   cout<<"\t\t------------------------------"<<endl;
    cout<<"\n\n\t\t   Welcome to ManyInOneGames\n\n";
    cout<<"\t\t-------------------------------"<<endl;
    int option;
    do{
        
        cout << "\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        cout << "\t\tX         Main Menu           X" << endl;
        cout << "\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        cout << "\t\tX  Select from the following  X" << endl;
        cout << "\t\tX                             X" << endl;
    	cout << "\t\tX                             X" << endl;
        cout << "\t\tX  1. Single Player Games     X" << endl;
        cout << "\t\tX  2. Multiplayer Games       X" << endl;
        cout << "\t\tX  3. Quit                    X" << endl;
        cout << "\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
      
        cin>>option;
        if(option == 1)
        {
            system("cls");
            Singleplayer();

        }
        else if(option == 2)
        {   system("cls");
            Multiplayer();
        }
        else if(option == 3)
        {
            break;
            system("cls");
        }
        else
        {
            cout<<"Invalid Option. Try again"<<endl;
        }
    }while(true);
    return 0;
}