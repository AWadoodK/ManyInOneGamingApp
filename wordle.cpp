#include<iostream>
using namespace std;
string array[3] = {"late", "tale" , "alte"};

int main()
{
    cout<<"Wordly"<<endl;
    //a t l e
    int correct = 0;
    int total = 3;
    int lives = 5;
    while(true)
    {  
        bool match = false;
        char arr[5];
        cout<<"Total: "<<total<<endl;
        cout<<"Enter  a word formed by these letters"<<endl;

        cout<<"(1)a \t (2) t \t(3)l \t(4) e"<<endl;
        cin>>arr;
        for(int i =0; i < 3; i++)
        {
            if(arr == array[i])
            {
                correct++;
                total -- ;
                match = true;
            }
        }
        if(match == false)
        {
            lives--;
        }
        if(correct == 3)
        {
            break;
        }
    }
    return 0;
}