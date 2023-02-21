// WAP to implement a priority process queue with burst time and arrival time and compute Waiting time and Turn around time
#include <iostream>

using namespace std;

int main()
{
    int pid[4], at[4],bt[4],pt[4],tat[4],wt[4];
    int rn=0;
    float awt;
    for(int i=0;i<4;i++){
        cout<<"PID: ";
        cin>>pid[i];
        cout<<"Arrival Time: ";
        cin>>at[i];
        cout<<"Burst Time: ";
        cin>>bt[i];
        cout<<"Priority: ";
        cin>>pt[i];
    }
    for(int i=0;i<4;i++){
        int maxInd,maxPrio=pt[0];
        for(int j=0;j<4;j++){
            if(at[j]>rn){
                continue;
            }
            if(pt[i]>maxPrio){
                maxPrio=pt[i];
                maxInd=i;
            }
        }
        cout << pid[maxInd];
        rn+=bt[maxInd];
        tat[maxInd]=rn-at[maxInd];
        wt[maxInd]=tat[maxInd]-bt[maxInd];
        pt[maxInd]=0;
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\n\n\n"<<awt;
}