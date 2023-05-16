#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <conio.h>
#include <fstream>
using namespace std;
string Easy[15] = {"Cat", "Dog", "Hat", "Car", "Sun", "Bed", "Cup", "Ball", "Tree", "Book", "Rain", "Lamp", "Duck", "Fish", "Bird"};
string Medium[15] = {"Guitar", "Pizza", "Tiger", "Apple", "Snake", "Rabbit", "Robot", "Tadpole", "Monkey", "Chair", "Banana", "Mouse", "House", "Water", "Music"};
string Hard[15] = {"Elephant", "Chocolate", "Butterfly", "Universe", "Ecosystem", "Trampoline", "Parachute", " Symphony ", "Xylophone", "Kangaroo", "Chameleon", "Pharaoh", "Cucumber", "Labyrinth", "Pterodactyl"};
// Wadood shall make this hangman look better
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
                // cout << array[i];
            }
            cout << endl;
            if (correct != true)
            {
                bool repeated = false;
                for (int k = 0; k < letters.size(); k++)
                {
                    if (letter == letters[k])
                    {
                        repeated = true;
                    }
                }
                if (!repeated)
                {
                    lives--;
                    letters.push_back(letter);
                    hang(7 - lives);
                }
                else
                {
                    cout<<"Letter already used"<<endl;
                }
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
int main()
{
    Hangman();
    return 0;
}