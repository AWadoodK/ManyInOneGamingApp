#include<iostream>
#include<vector>
using namespace std;
void Singleplayer()
{
    int option;
    bool condition = true;
    do
    {
        cout<<"Choose a game"<<endl;
        cout<<"(1)Snake Game"<<endl;
        cout<<"(2)Hangman"<<endl;
        cout<<"(3)Wordly"<<endl;
        cout<<"(4)Back to main"<<endl;
        cin>>option;
        cout<<endl<<endl;
        switch (option)
        {
            case 1:
                //Snake();
                break;

            case 2:
                //Hangman();
                break;
            case 3:
                //Wordly();
                break;
            case 4:
                condition = false;
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
    {
        cout<<"Choose a game"<<endl;
        cout<<"(1)TicTacToe"<<endl;
        cout<<"(2)Truth And Dare"<<endl;
        cout<<"(3)Back to Main"<<endl;
        cin>>option;
        cout<<endl<<endl;
        switch (option)
        {
            case 1:
                //TicTacToe();
                break;

            case 2:
                //Truth_n_Dare();
                break;

            case 3:
                condition = false;
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
        cout << "\t\tX         Game Menu           X" << endl;
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
            
            Singleplayer();
        }
        else if(option == 2)
        {
            Multiplayer();
        }
        else if(option == 3)
        {
            break;
        }
        else
        {
            cout<<"Invalid Option. Try again"<<endl;
        }
    }while(true);
    return 0;
}