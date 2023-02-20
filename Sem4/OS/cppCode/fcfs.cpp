#include <iostream>

using namespace std;

int main()
{
    int pid[4], at[4],bt[4],tat[4],wt[4];
    int rn=0;
    float awt;
    for(int i=0;i<4;i++){
        cout<<"PID: ";
        cin>>pid[i];
        cout<<"Arrival Time: ";
        cin>>at[i];
        cout<<"Burst Time: ";
        cin>>bt[i];
    }
    for(int i=0;i<4;i++){
        if(rn<at[i]){
            rn=at[i];
        }
        rn+=bt[i];
        tat[i]=rn-at[i];
        wt[i]=tat[i]-bt[i];
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\n\n\n"<<awt;
}
