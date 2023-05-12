#include<iostream>
using namespace std;

int main()
{
    int board[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == 0 || j == 0 || i == 9 || j == 9)
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = i*100 + j;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<board[i][j]<<"|";
        }
        cout<<endl;
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout<<"\tx="<<board[i][j]/100;
            cout<<"j="<<board[i][j] %100;
        }
    }
}