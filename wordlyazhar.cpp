#include <iostream>
#include <vector>    
#include <string>  
#include<cstring>                         // NOT COMPLETE
using namespace std;
int score=0;
int lives=5;
int lvlupdate = 1;
string name;
void introline()
{
    for(int i=0;i<139;i++)
    {
        cout<<"-";
    }
}
void leveldisplay()
{
   
    cout << "*************" <<endl;
    cout << "*           *" <<endl;
    cout << "*  Welcome  *" <<endl;
    cout << "*     to    *" <<endl;
    cout << "*   Level "<<lvlupdate<<" *"<<endl;
    cout << "*           *" <<endl;
    cout << "*************" <<endl;
}
class Game
{
    private:
    
    string words[10];
    protected:
    int correct;   //This is your right answers
    int total;     //This is your number of words that you have to guess
    int limit;     // Used as a check mark when correct == limit
    public:
    friend class LV1;
    friend class LV2;
    Game()
    {}
    Game(int x,int y,int z, string *arr)
    {   
        correct = x;
        total = y;
        limit = z;
        for(int i=0;i<y;i++)
        {
            words[i] = arr[i];
        }
         
    }
    public:
    void play()
    {       int iter=total;
            while (true) {
            bool match = false;
            string guess;
            cout << "Total words you have to guess: " << total << endl;
            cout<<"Total lives: "<<lives<<endl;
            cout << "Enter a word formed by these letters" << endl;
        
            cout<<words[0][2]<<" "<<words[0][3]<<" "<<words[0][0]<<" "<<words[0][1]<<endl;
            
            cin >> guess;
            
            for (int i = 0; i<iter; i++) {
                
                if (guess == words[i]) {
                    correct++;
                    total--;
                    match = true;
                    score++;
                    cout<<"Nice "<<name<<" you got that right\n";
                    cout<<"Your score is: "<<score<<endl;
                    introline();

                }
            }
            
            if (match == false) {
                lives--;
                cout<<"Yikes! Be careful "<<name<<" got that wrong\n";
                cout<<"You have "<<lives<<" lives left\n";
            }
            
            if (correct == limit) {
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
    friend void wordle();
    friend void wordleplay();



};

class LV1
{
    string word[2]= {"tale","late"};
    public:
    LV1(){
        Game lv1(0,2,2,word);
        lv1.play();
        }  
   
};
class LV2
{
    string lab[6] = {"opts","tops","spot","pots","post","stop"};
    public:
    LV2()
    {
        Game lv2(0,6,6,lab);
        lv2.play();
    }
};

void lvlmenu()
{
    cout<<"LV: 1\n";
    cout<<"LV: 2\n";
    cout<<"LV: 3\n";
    cout<<"LV: 4\n";
}
void wordleplay()
{
     leveldisplay();
    LV1 abc;
    cout<<"\n";
    introline();
    cout<<"\n"; 
    if(lives!=0)
    {   
        lvlupdate++;
        leveldisplay();
        LV2 bac;
    }
    else
    {
        cout<<name<<" your total score is: "<<score;
    }
}

void wordle()
{
    int press = 0;
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
    cout<<"What is your name\n";
    cin>>name;
    cout<<"1)Play\n";
    cout<<"2)Check high score\n\n";
    
    cout<<"Press 1 or 2\n";
    cin>>press;
    if(press==1)
    {
        wordleplay();
    }
    else if(press == 2)
    {
        //add the highscore file
    }
    else
    {
        cout<<"Invalid option! try again\n";
        wordle();
    }

}


int main()
{
    
     wordle();

    
    
    return 0;
}