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
        int shortest_pid_index=0, min_time=10000;
        for(int j=0;j<4;j++){
            if(pid[j]==99999999){
                continue;
            }
            if(at[j]<rn){
                if(bt[j]<min_time){
                    shortest_pid_index=j;
                    min_time=bt[shortest_pid_index];
                }
            }
        }
        //cout<<min_time<<endl;
        cout<<shortest_pid_index<<"\n";
        rn+=bt[shortest_pid_index];
        tat[shortest_pid_index]=rn-at[shortest_pid_index];
        wt[shortest_pid_index]=tat[shortest_pid_index]-bt[shortest_pid_index];
        pid[shortest_pid_index]=99999999;
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\n\n\n"<<awt;
}