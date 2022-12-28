// program to find the length of a string

#include <stdio.h>

void main(){
    char str[]="";
    gets(str);
    int i, n = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        n++;
    }
    printf("Length of string is %d\n", n);
}