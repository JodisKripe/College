#include <iostream>
using namespace std;

float volume(float);
float volume(float, float);
float volume(float, float, float);

int main()
{
    int choice;

    cout << "Enter 0 for calculating volume of cube, 1 for calculating volume of cylinder, and 2 for calculating volume of cuboid: ";
    cin >> choice;

    switch (choice)
    {
    case 0:
        float side;
        cout << "Enter the length of the side of the cube: ";
        cin >> side;
        cout << "Volume of the given cube is: " << volume(side) << endl;
        break;

    case 1:
        float radius, height;
        cout << "Enter the radius of the cylinder: ";
        cin >> radius;
        cout << "Enter the height of the cylinder: ";
        cin >> height;
        cout << "Volume of the given cylinder is: " << volume(radius, height) << endl;
        break;

    case 2:
        float l, b, h;
        cout << "Enter the length of the cuboid: ";
        cin >> l;
        cout << "Enter the breadth of the cuboid: ";
        cin >> b;
        cout << "Enter the height of the cuboid: ";
        cin >> h;
        cout << "Volume of the given cuboid is: " << volume(l, b, h) << endl;
        break;
    
    default:
        cout << "Invalid Input!" << endl;
        break;
    }

    return 0;
}

float volume(float side)
{
    float volume = side*side*side;
    return volume;
}

float volume(float radius, float height)
{
    float volume = 2*3.14*radius*height;
    return volume;
}

float volume(float l, float b, float h)
{
    float volume = l*b*h;
    return volume;
}