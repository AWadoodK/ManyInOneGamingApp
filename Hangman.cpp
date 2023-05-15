#include <iostream>
#include <string.h>
#include <vector>
#include <conio.h>
using namespace std;
// Wadood shall make this hangman look better
void hang(int a)
{
    system("cls");
    if (a == 1)
    {
        cout << "   0" << endl;
    }
    else if (a == 2)
    {
        cout << "   0" << endl;
        cout << "   |" << endl;
    }
    else if (a == 3)
    {
        cout << "   0" << endl;
        cout << "  \\|" << endl;
    }
    else if (a == 4)
    {
        cout << "   0" << endl;
        cout << "  \\|/" << endl;
    }
    else if (a == 5)
    {
        cout << "   0" << endl;
        cout << "  \\|/" << endl;
        cout << "  /" << endl;
    }
    else if (a == 6)
    {
        cout << "   0" << endl;
        cout << "  \\|/" << endl;
        cout << "  / \\" << endl;
    }
    else if (a == 7)
    {
        cout << "YOU LOST" << endl;
        cout << "  _0_" << endl;
        cout << "  \\|/" << endl;
        cout << "  / \\" << endl;
    }
    else
    {
        cout << endl;
    }
}
int main()
{
    cout << "<<<<<<-----------------Welcome to Hangman--------------------->>>>>>" << endl;
    vector<char> letters;
    string arr;
    cout << "Enter the word" << endl;
    cin >> arr;
    int size = arr.length();
    string array(arr,'_');
    for (int i = 0; i < size; i++)
    {
        arr[i] = tolower(arr[i]);
        array[i] = '_';
    }
    system("cls");
    // i want to add system cls shit. For the new Screen
    cout << "The word has " << size << " letters" << endl;
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
        for (int j = 0; j < size; j++)
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
        for (int i = 0; i < size; i++)
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
        else if (answers == size)
        {
            break;
        }
        else
        {
            hang(7 - lives);
        }
    }
    if (lives == 0)
    {
        cout << "You lost" << endl;
    }
    else
    {
        cout << "Congrats Champ. You Won!!";
    }
    cout << "\nthe word was " << arr << endl;
    return 0;
}