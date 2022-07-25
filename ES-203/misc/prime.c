#include <stdio.h>
#include <stdbool.h>

void main(){
    int n;
    bool prime;
    printf("Enter Number:");
    scanf("%d",&n);
    prime=false;
    for(int i=2;i<n;i++){
        if(n%i==0){
            prime=false;
            break;
        }
        prime=true;
    }
    if(prime){
        printf("Number is prime");
    }
    else{printf("Number isn't Prime");}
}