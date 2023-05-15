
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

//Global Functions
bool ingame_condition = true;
// file handling function
void view_score(string path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cout << "Couldn't Open file" << endl;
        return;
    }
    string line, name, score;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, score, ',');
        cout << "Name: " << name << "\tScore: " << score << endl;
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


//HangMan
string Easy[15] = {"Cat", "Dog", "Hat", "Car", "Sun", "Bed", "Cup", "Ball", "Tree", "Book", "Rain", "Lamp", "Duck", "Fish", "Bird"};
string Medium[15] = {"Guitar", "Pizza", "Tiger", "Apple", "Snake", "Rabbit", "Robot", "Tadpole", "Monkey", "Chair", "Banana", "Mouse", "House", "Water", "Music"};
string Hard[15] = {"Elephant", "Chocolate", "Butterfly", "Universe", "Ecosystem", "Trampoline", "Parachute", " Symphony ", "Xylophone", "Kangaroo", "Chameleon", "Pharaoh", "Cucumber", "Labyrinth", "Pterodactyl"};

void hangman_Store_in_file(int newscore, string &path)
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
void hang(int a)
{
    system("cls");
    if (a == 1)
    {
        cout << "\t\t\t\t\t\t   0" << endl;
    }
    else if (a == 2)
    {
        cout << "\t\t\t\t\t\t    0" << endl;
        cout << "\t\t\t\t\t\t    |" << endl;
    }
    else if (a == 3)
    {
        cout << "\t\t\t\t\t\t    0" << endl;
        cout << "\t\t\t\t\t\t   \\|" << endl;
    }
    else if (a == 4)
    {
        cout << "\t\t\t\t\t\t    0" << endl;
        cout << "\t\t\t\t\t\t   \\|/" << endl;
    }
    else if (a == 5)
    {
        cout << "\t\t\t\t\t\t    0" << endl;
        cout << "\t\t\t\t\t\t   \\|/" << endl;
        cout << "\t\t\t\t\t\t   /" << endl;
    }
    else if (a == 6)
    {
        cout << "\t\t\t\t\t\t    0" << endl;
        cout << "\t\t\t\t\t\t   \\|/" << endl;
        cout << "\t\t\t\t\t\t   / \\" << endl;
    }
    else if (a == 7)
    {
        cout << "\t\t\t\t\t\t YOU LOST" << endl;
        cout << "\t\t\t\t\t\t   _0_" << endl;
        cout << "\t\t\t\t\t\t   \\|/" << endl;
        cout << "\t\t\t\t\t\t   / \\" << endl;
    }
    else
    {
        cout << endl;
    }
}
void Hangman()
{
    int score = 0, Multiplier;
    cout << "<<<<<<-----------------Welcome to Hangman--------------------->>>>>>" << endl;
    cout << "Enter difficulty\n";
    cout << "(1)Easy\n(2)Medium\n(3)hard\n";
    int diff;
    cin >> diff;
    if (diff <= 0 || diff > 3)
    {
        cout << "Invalid Difficulty" << endl;
        return;
    }

    for (int start = 0; start < 15; start++)
    {
        vector<char> letters;
        string arr, word;
        bool roundclear = false;
        if (diff == 1)
        {
            arr = Easy[start];
            Multiplier = 5;
        }
        else if (diff == 2)
        {
            arr = Medium[start];
            Multiplier = 10;
        }
        else
        {
            arr = Hard[start];
            Multiplier = 15;
        }
        word = arr;

        int length = arr.length();
        char array[length];
        for (int i = 0; i < length; i++)
        {
            arr[i] = tolower(arr[i]);
            array[i] = '_';
        }
        system("cls");
        cout << "The word has " << length << " letters" << endl;
        char letter;
        int lives = 7;
        bool win = false;
        int answers = 0;
        while (lives != 0)
        {
            bool used = false;
            bool correct = false;
            if (lives < 7)
            {
                cout << "Letters  used" << endl;
                for (int i = 0; i < 7 - lives; i++)
                {
                    cout << letters.at(i) << ",\t";
                }
            }
            cout << "\nLives Left: " << lives;
            cout << "\nEnter a Letter: ";
            cin >> letter;
            letter = tolower(letter);
            if (!isalpha(letter))
            {
                cout << "Only from english Alphabets" << endl;
                continue;
            }
            for (int j = 0; j < length; j++)
            {
                if (array[j] == letter)
                {
                    cout << "This letter already used" << endl;
                    used = true;
                    break;
                }
            }
            if (used)
            {
                continue;
            }
            for (int i = 0; i < length; i++)
            {
                if (arr[i] == letter)
                {
                    correct = true;
                    array[i] = letter;
                    answers++;
                }
                cout << array[i];
            }
            cout << endl;
            if (correct != true)
            {
                lives--;
                letters.push_back(letter);
                hang(7 - lives);
            }
            else if (answers == length)
            {
                break;
            }
            else
            {
                hang(7 - lives);
            }
            for (int i = 0; i < length; i++)
            {
                cout << array[i];
            }
            cout << endl;
        }
        if (lives == 0)
        {
            cout << "You lost" << endl;
            cout << "\nthe word was " << word << endl;
            cout << "Score: " << score << endl;
            break;
        }
        else
        {
            cout << "Congrats Champ. You Won!!";
            score = score + Multiplier;
            roundclear = true;
        }
        cout << "\nthe word was " << word << endl;
        cout << "Score: " << score << endl;
        if (roundclear == true)
        {
            cout << "Do you want to proceed?\n";
            int option;
            cout << "(1)Yes\t(2)No" << endl;
            cin >> option;
            if (option != 1)
            {
                break;
            }
        }
    }
    string path = "ScoreHangman.csv";
    Store_in_file(score, path);
}


void INGAME_Hangman()
{
    int ingame_option;
    do
    {   system("cls");
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t         Hangman Game          " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. Continue to Game              " << endl;
        cout << "\t\t   2. View High Scores                " << endl;
        cout << "\t\t   3. Back to Main            " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cin>>ingame_option;
        cout<<endl<<endl;
        switch (ingame_option)
        {
            case 1:
                Hangman();
                break;

            case 2:
                //highscore code;
                break;
            case 3:
                ingame_condition = false;
                system("cls");
                break;
            default:
                cout<<"Invalid Option";
                break;
        }
    } while (ingame_condition);
    

}





// SNAKE GAME
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
        int score;
        string path = "ScoreSnake.csv";
        food();
        while (true)
        {
            bool game = gameover();
            displayboard(true);
            int x = move();
            updateposition(x);
            updateboardsnake();
            score = (length - 1) * Score_Multiplier;
            cout << "Score: " << score << endl;

            cout << endl;
            Sleep(refresh_rate);
            if (game)
            {
                cout << "you lost" << endl;
                break;
            }
        }
        Store_in_file(score, path);
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
void INGAME_Snake()
{
    int ingame_option;
    do
    {   system("cls");
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t         Snake Game          " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. Continue to Game              " << endl;
        cout << "\t\t   2. View High Scores                " << endl;
        cout << "\t\t   3. Back to Main            " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cin>>ingame_option;
        cout<<endl<<endl;
        switch (ingame_option)
        {
            case 1:
                Snakegame();
                break;

            case 2:
                //highscore code;
                break;
            case 3:
                ingame_condition = false;
                system("cls");
                break;
            default:
                cout<<"Invalid Option";
                break;
        }
    } while (ingame_condition);
    

}


// TIC TAC TOE
char show;
int again = 0;
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
            cout << "\t" << tictactoe_board[i][j];
            if (j < 2)
            {
                cout << "\t|";
            }
        }

        cout << endl;
        cout << "\t\t---------------------------------------------------" << endl;
    }
    cout << endl;
}

int tictactoe()
{
    do
    {
        system("cls");
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\n\n\t\t\t\tTic-Tac-Toe\n\n\n";
        cout << "\t\t---------------------------------------------------" << endl;
        int titactoeoption;
        int t = 1;
        cout << "\t\t---------------------------------------------------" << endl;
        cout << "\t\t\t\tPlayer 1 = " << tictactoe_p1 << endl;
        cout << "\t\t\t\tplayer 2 = " << tictactoe_p2 << endl;
        cout << "\t\t---------------------------------------------------" << endl;
        int tictactoe_turn = 0;
        tictactoe_output();
        while (tictactoe_turn < 9)
        {
            show = tictactoe_p1;
            cout << "\t\tPlayer " << t << " enter a number to Replace " << show << " with: \t";
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
            if (t == 1)
            {
                t = 2;
                show = tictactoe_p2;
            }
            else
            {
                t = 1;
                show = tictactoe_p1;
            }
            tictactoe_turn++;
        }
        if (tictactoe_game() == false)
        {
            cout << "Its a Draw" << endl;
        }
        cout << "\n";
        cout << "Enter 1 to Exit or 0 to Play Again?\n";
        cin >> again;
    } while (again == 0);
    return 0;
    
}



void INGAME_tictactoe()
{
    int ingame_option;
    do
    {   system("cls");
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t         Tic Tac Toe Game          " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. Continue to Game              " << endl;
        cout << "\t\t   2. View High Scores                " << endl;
        cout << "\t\t   3. Back to Main            " << endl;
        cout<<"\t\t------------------------------"<<endl;
        cin>>ingame_option;
        cout<<endl<<endl;
        switch (ingame_option)
        {
            case 1:
                tictactoe();
                break;

            case 2:
                //highscore code;
                break;
            case 3:
                ingame_condition = false;
                system("cls");
                break;
            default:
                cout<<"Invalid Option";
                break;
        }
    } while (ingame_condition);
    

}





//Truth and Dare
void truthdare() {
    string pername;
    int choice, rand_num;
    bool playing = true;

    srand(time(NULL)); //initialize random seed

    cout << "Welcome to Truth and Dare!" << endl;
    cout << "What's your name? ";
    getline(cin, pername);
    cout << "Hi, " << pername << "! Let's play!" << endl;

    while (playing) {
        cout << endl;
        cout << "Choose your option:" << endl;
        cout << "1. Truth" << endl;
        cout << "2. Dare" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl;
                cout << "Truth: ";
                //generate random number between 1 and 25
                rand_num = rand() % 25 + 1;
                switch (rand_num) {
                    case 1:
                        cout << "What is your biggest fear?" << endl;
                        break;
                    case 2:
                        cout << "What is your biggest secret?" << endl;
                        break;
                    case 3:
                        cout << "What is your favorite food?" << endl;
                        break;
                    case 4:
                        cout << "What is your favorite movie?" << endl;
                        break;
                    case 5:
                        cout << "What is your favorite song?" << endl;
                        break;
                    case 6:
                        cout << "What is your most embarrassing moment?" << endl;
                        break;
                    case 7:
                        cout << "Have you ever cheated on a test or exam?" << endl;
                        break;
                    case 8:
                        cout << "What is the craziest thing you've ever done?" << endl;
                        break;
                    case 9:
                        cout << "What is your biggest regret?" << endl;
                        break;
                    case 10:
                        cout << "What is your favorite hobby?" << endl;
                        break;
                    case 11:
                        cout << "What is your dream job?" << endl;
                        break;
                    case 12:
                        cout << "What is your favorite book?" << endl;
                        break;
                    case 13:
                        cout << "What is your biggest accomplishment?" << endl;
                        break;
                    case 14:
                        cout << "What is the one thing you cannot live without?" << endl;
                        break;
                    case 15:
                        cout << "What is the most expensive thing you've ever bought?" << endl;
                        break;
                    case 16:
                        cout << "What is the one thing you would change about yourself?" << endl;
                        break;
                    case 17:
                        cout << "What is the one thing you would change about the world?" << endl;
                        break;
                    case 18:
                        cout << "What is your biggest pet peeve?" << endl;
                        break;
                    case 19:
                        cout << "What is the one thing you are most proud of?" << endl;
                        break;
                    case 20:
                        cout << "What is the most embarrassing thing in your room?" << endl;
                        break;
                    case 21:
                        cout << "What is your favorite childhood memory?" << endl;
                        break;
                    case 22:
                        cout << "What is the one thing you've always wanted to do?" << endl;
                        break;
                    case 23:
                        cout << "What is the craziest thing you've ever done in public?" << endl;
                        break;
                    case 24:
                        cout << "What is the worst date you've ever been on?" << endl;
                        break;
                    case 25:
                        cout << "What is the most embarrassing thing you've ever said?" << endl;
                        break;
                }
                break;
            case 2:
                cout << endl;
                cout << "Dare: ";
                //generate random number between 1 and 25
                rand_num = rand() % 25 + 1;
                switch (rand_num) {
                    case 1:
                        cout << "Sing a song out loud in a public place." << endl;
                        break;
                    case 2:
                        cout << "Do 10 pushups." << endl;
                        break;
                    case 3:
                        cout << "Do the Macarena dance." << endl;
                        break;
                    case 4:
                        cout << "Say the alphabet backwards." << endl;
                        break;
                    case 5:
                        cout << "Call a friend and sing happy birthday to them." << endl;
                        break;
                    case 6:
                        cout << "Eat a spoonful of mustard." << endl;
                        break;
                    case 7:
                        cout << "Do a handstand against the wall for 10 seconds." << endl;
                        break;
                    case 8:
                        cout << "Hop on one foot for 30 seconds." << endl;
                        break;
                    case 9:
                        cout << "Do 10 jumping jacks." << endl;
                        break;
                    case 10:
                        cout << "Put an ice cube down your shirt and let it melt." << endl;
                        break;
                    case 11:
                        cout << "Do a silly dance." << endl;
                        break;
                    case 12:
                        cout << "Go outside and take a picture with a stranger." << endl;
                        break;
                    case 13:
                        cout << "Do 10 burpees." << endl;
                        break;
                    case 14:
                        cout << "Eat a spoonful of hot sauce." << endl;
                        break;
                    case 15:
                        cout << "Do a cartwheel." << endl;
                        break;
                    case 16:
                        cout << "Do a backbend." << endl;
                        break;
                    case 17:
                        cout << "Balance a book on your head and walk in a straight line." << endl;
                        break;
                    case 18:
                        cout << "Draw a self-portrait blindfolded." << endl;
                        break;
                    case 19:
                        cout << "Take a shot of lemon juice." << endl;
                        break;
                    case 20:
                        cout << "Try to do the splits." << endl;
                        break;
                    case 21:
                        cout << "Speak in a fake accent for the next hour." << endl;
                        break;
                    case 22:
                        cout << "Wear your clothes backwards for the rest of the game." << endl;
                        break;
                    case 23:
                        cout << "Do 20 jumping jacks while holding your breath." << endl;
                        break;
                    case 24:
                        cout << "Run in place for 30 seconds." << endl;
                        break;
                    case 25:
                        cout << "Go up to a stranger and ask for a piggyback ride." << endl;
                        break;
                }
                break;
            case 3:
                cout << endl;
                cout << "Thanks for playing, " << pername << "!" << endl;
                playing = false;
                break;
            default:
            cout << "Invalid input. Please choose 1, 2, or 3." << endl;
            break;
        }
}
}



//MAIN FUNCTIONS
void Singleplayer()
{   
    int option;
    bool condition = true;
    
    do
    {
        system("cls");
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t         Game Menu           " << endl;
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. Snake Game              " << endl;
        cout << "\t\t   2. Hangman                 " << endl;
        cout << "\t\t   3. Wordly                  " << endl;
        cout << "\t\t   4. Back to Main            " << endl;
        cout << "\t\t------------------------------" << endl;
        cin >> option;
        cout << endl
             << endl;
        switch (option)
        {
        case 1:
            INGAME_Snake();
            if(ingame_condition==false)
            {
                break;
            }
            else{
                Snakegame();
            }
            
            break;

        case 2:
            INGAME_Hangman();
            if(ingame_condition==false)
            {
                break;
            }
            else{
                Hangman();
            }
            
            break;
        case 3:
            // Wordly();
            break;
        case 4:
            condition = false;
            system("cls");
            break;
        default:
            cout << "Invalid Option";
            break;
        }
    } while (condition);
}
void Multiplayer()
{
    int option;
    bool condition = true;
    do
    {
        system("cls");
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t          Game Menu           " << endl;
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t   Select from the following  " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t                              " << endl;
        cout << "\t\t   1. TicTacToe               " << endl;
        cout << "\t\t   2. Truth And Dare          " << endl;
        cout << "\t\t   3. Back to Main            " << endl;
        cout << "\t\t------------------------------" << endl;
        cin >> option;
        cout << endl
             << endl;
        switch (option)
        {
        case 1:
            INGAME_tictactoe();
            if(ingame_condition==false)
            {
                break;
            }
            else{
                tictactoe();
            }
            
            break;

        case 2:
            truthdare();
            break;

        case 3:
            condition = false;
            system("cls");
            break;

        default:
            cout << "Invalid Option";

            break;
        }
    } while (condition);
}
int main()
{
    cout << "\t\t------------------------------" << endl;
    cout << "\n\n\t\t   Welcome to ManyInOneGames\n\n";
    cout << "\t\t-------------------------------" << endl;
    int option;
    do
    {

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

        cin >> option;
        if (option == 1)
        {
            system("cls");
            Singleplayer();
        }
        else if (option == 2)
        {
            system("cls");
            Multiplayer();
        }
        else if (option == 3)
        {
            break;
            system("cls");
        }
        else
        {
            cout << "Invalid Option. Try again" << endl;
        }
    } while (true);
    return 0;
}