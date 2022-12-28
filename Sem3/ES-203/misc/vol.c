#include <stdio.h>
#include <stdbool.h>

//code to calculate volume of solid objects

void main(){
    float area,volume;
    int choice;
    printf("Enter the choice of shape:\n1.Cube\n2.Sphere\n3.Cylinder\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the area of cube:");
            scanf("%f",&area);
            volume=area*6;
            printf("Volume of cube is:%f",volume);
            break;
        case 2:
            printf("Enter the area of sphere:");
            scanf("%f",&area);
            volume=area*(4/3)*3.14;
            printf("Volume of sphere is:%f",volume);
            break;
        case 3:
            printf("Enter the area of cylinder:");
            scanf("%f",&area);
            printf("Enter the height of cylinder:");
            scanf("%f",&volume);
            volume=area*volume;
            printf("Volume of cylinder is:%f",volume);
            break;
        default:
            printf("Invalid choice");
    }
}