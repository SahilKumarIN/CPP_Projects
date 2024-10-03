#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
    cout<<"<***************************WELCOME TO STONE,PAPER & SCISSOR GAME******************************>\n";
    string player_name;
    cout<<"Please Enter Your Name:\n";
    getline(cin,player_name);
    cout<<"<**********************************Let's Start The Game**********************************>\n";
    int round,i;
    cout<<"<-----------------------How many rounds you want------------------------->\n";
    cin>>round;
    int call,random;
    int player_points=0,bot_points=0;
    for(i=0;i<round;i++)
    {
        come:
        cout<<player_name<<" Enter Your Call\n1. Stone\n2. Paper\n3. Scissor\n";
        cin>>call;
        if(call==1)
        {
            random=1+(rand()%10);
            if(random>=4 && random<=6)
            {
                cout<<"Bot Win This Round\n";
                bot_points++;
            }
            else if(random>=7 && random<=9)
            {
                cout<<player_name<<" win this Round\n";
                player_points++;
            }
            else
            {
                cout<<"Round Draw\n";
            }
        }
        else if(call==2)
        {
            random=1+(rand()%10);
            if(random>=1 && random<=3)
            {
                cout<<player_name<<" win this Round\n";
                player_points++;
            }
            else if(random>=7 && random<=10)
            {
                cout<<"Bot win this Round\n";
                bot_points++;
            }
            else
            {
                cout<<"Round Draw\n";
            }
        }
        else if(call==3)
        {
            random=1+(rand()%10);
            if(random>=1 && random<=3)
            {
                cout<<"Bot win this Round\n";
                bot_points++;
            }
            else if(random>=4 && random<=10)
            {
                cout<<player_name<<" win this Round\n";
                player_points++;
            }
            else{
                cout<<"Round Draw\n";
            }
        }
        else
        {
            cout<<"Invalid Input\nPlease Recall Again............\n";
            goto come;
        }
    }
    if(player_points > bot_points)
    {
        cout<<player_name<<" Won The Game\n";
    }
    else if(player_points < bot_points)
    {
        cout<<"Bot Won This Game\n";
    }
    else
    {
        cout<<"Match Draw....\n";
    }
    return 0;
}