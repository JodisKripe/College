// WAP to implement a priority process queue with burst time and arrival time and compute Waiting time and Turn around time
// 0 0 10 2 1 1 6 5 2 3 2 3 3 5 4 1

#include <iostream>

using namespace std;

int main()
{
    int pid[4], at[4],bt[4],pt[4],tat[4],wt[4],tl[4];
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
        tl[i]=bt[i];
    }
    for(int i=0;i<22;i++){
        int maxInd=0,maxPrio=pt[0];
        for(int j=0;j<4;j++){
            if(at[j]>rn){
                continue;
                cout<<"skipped";
            }
            if(pt[j]>maxPrio){
                maxPrio=pt[j];
                maxInd=j;
            }
        }
        cout << maxInd <<"  "<<pid[maxInd]<<"  "<<tl[maxInd]<<endl;
        rn+=1;
        if(tl[maxInd]>0){tl[maxInd]--;}
        if(tl[maxInd] == 0){
            cout<<"Process Fin"<<endl;
            tat[maxInd]=rn-at[maxInd];
            wt[maxInd]=tat[maxInd]-bt[maxInd];
            pt[maxInd]=0;
        }
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\nAverage Waiting Time: "<<awt<<endl;
}