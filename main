#include <iostream>    
#include <string>  
#include<cstring>                         // NOT COMPLETE
using namespace std;
int lives = 5;
int score = 0;
class LV1
{
    private:
    string words[2] = {"late", "tale"};
    char l1[5];
    char l2[5];
    char l3[5];
    char l4[5];
    int correct;
    int total;
    
    public:
    LV1() {
        correct = 0;
        total = 2;   
        strcpy(l1, "a");
        strcpy(l2, "t");
        strcpy(l3, "l");
        strcpy(l4, "e");

        
    }
    void play()
    {
        cout << "\t\t\t\tWELCOME TO LVL: 1" << endl;

           while (true) {
            bool match = false;
            string guess;
            cout << "Total words you have to guess: " << total << endl;
            cout<<"Total lives: "<<lives<<endl;
            cout << "Enter a word formed by these letters" << endl;
        //    cout << "(1) a\t(2) t\t(3) l\t(4) e" << endl;     REMOVE LATER
            cout<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<endl;
            cin >> guess;

            for (int i = 0; i<total + 1; i++) {
                if (guess == words[i]) {
                    correct++;
                    total--;
                    match = true;
                    score++;
                    cout<<"Nice you got that right\n";
                    cout<<"Your score is: "<<score<<endl;

                }
            }

            if (!match) {
                lives--;
                cout<<"Yikes! Be careful you got that wrong\n";
                cout<<"You have "<<lives<<" left\n";
            }

            if (correct == 2) {
                cout<<"Congrats you guessed them all right\n";
                score=score+2;
                cout<<"The score is: "<<score;
                break;
            }
            if (lives == 0)
            {
                cout<<"You have lost\n";
                break;
            }
        }

    }
};
//string array[3] = {"late", "tale" , "alte"};  //remove this later on
void introline()
{
    for(int i=0;i<139;i++)
    {
        cout<<"-";
    }
}
void lvlmenu()
{
    cout<<"LV: 1\n";
    cout<<"LV: 2\n";
    cout<<"LV: 3\n";
    cout<<"LV: 4\n";
}

int main()
{
    introline();
    cout<<"\n";
    cout<<"\t\t\t\t\t\t\tWELCOME TO WORDLY"<<endl;
    cout<<"\t\t\t\t\t\tThe best guessing game on net\n";
    introline();
    cout<<"\nRULES OF THE GAME:\n";
    cout<<"1) You will be given 4 letters and you would have to come up with a word from combination of those 4 letters\n2) You will have to guess a total of two to three words per level to move on\n3) You will have a total of five lives\n\n";
    introline();
    cout<<"\n";
    lvlmenu();
    LV1 game;
    game.play();

    
    
    return 0;
}
