// WAP to make a round robin queue for processes and calculate TAT and AWT
#include <iostream>
using namespace std;



int main(){
    int pid[4],at[4],bt[4],tat[4],wt[4],tl[4];
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
        tl[i]=bt[i];
    }
    for(int i=0;i<22;i++){
        int maxInd=0,maxPrio=at[0];
        for(int j=0;j<4;j++){
            if(at[j]>rn){
                continue;
                cout<<"skipped";
            }
            if(at[j]<maxPrio){
                maxPrio=at[j];
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
            at[maxInd]=100;
        }
    }
    for(int i=0;i<4;i++){
        awt+=wt[i];
    }
    awt = awt/4;
    cout<<"\n\n\n\n"<<awt;
}