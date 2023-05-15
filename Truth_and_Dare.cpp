#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    string name;
    int choice, rand_num;
    bool playing = true;

    srand(time(NULL)); //initialize random seed

    cout << "Welcome to Truth and Dare!" << endl;
    cout << "What's your name? ";
    getline(cin, name);
    cout << "Hi, " << name << "! Let's play!" << endl;

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
                cout << "Thanks for playing, " << name << "!" << endl;
                playing = false;
                break;
            default:
            cout << "Invalid input. Please choose 1, 2, or 3." << endl;
            break;
        }
}

return 0;
}
