#include <iostream>

using namespace std;

int main() {
    int n; //0
    cout << "Enter the size of the array: "; //1
    cin >> n; //1
    int arr[n]; //0
    cout << "Enter  the elements of the array: "; //1
    for (int i = 0; i < n; i++) { //n+1
        cin >> arr[i]; //n
    }
    for (int i = 0; i < n - 1; i++) { //n
        int min = i; //1
        for (int j = i + 1; j < n; j++) { //n^2
            if (arr[j] < arr[min]) { //1
                min = j; //1
            }
        }
        int temp = arr[i]; //1
        arr[i] = arr[min]; //1
        arr[min] = temp; //1
    }
    cout << "The sorted array is: "; //1
    for (int i = 0; i < n; i++) { //n+1
        cout << arr[i] << " "; //n
    }
    cout << endl; //1
    return 0; //1
}