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
    int btc[4];
    for(int i=0;i<5;i++){
        btc[i] = bt[i];
    }
    int timefin[4];
    for(int i=0;i<22;i++){
        int shortest_pid_index=0, min_time=10000;
        for(int j=0;j<4;j++){
            if(btc[j]==0){
                continue;
            }
            if(at[j]<=rn){
                if(bt[j]<min_time){
                    shortest_pid_index=j;
                    min_time=bt[shortest_pid_index];
                }
            }
        }
        //cout<<min_time<<endl;
        rn+=1;
        btc[shortest_pid_index]--;
        cout<<rn<<" : "<<shortest_pid_index<<": "<<btc[shortest_pid_index]<<endl;
        if(btc[shortest_pid_index]==0){
            timefin[shortest_pid_index]=rn;
        }
    }
    for(int i=0;i<4;i++){
        tat[i] = timefin[i] - at[i];
        wt[i] = tat[i] - bt[i];
        cout<<pid[i]<<" "<<tat[i]<<" "<<wt[i]<<" "<<timefin[i]<<endl;
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\n\n\n"<<awt;
}