#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) { //n
        int key = arr[i]; //1
        int j = i - 1; //1
        while (j >= 0 && arr[j] > key) { //n^2
            arr[j + 1] = arr[j]; //1
            j--; //1
        }
        arr[j + 1] = key; //1
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) { //n+1
        cout << arr[i] << " "; //n
    }
    cout << endl; //1
}

int main() {
    int n; //0
    cout << "Enter the size of the array: "; //1
    cin >> n; //1
    int arr[n]; //0
    cout << "Enter  the elements of the array: "; //1
    for (int i = 0; i < n; i++) { //n+1
        cin >> arr[i]; //n
    }
    insertionSort(arr, n); //n^2
    cout << "The sorted array is: "; //1
    printArray(arr, n); //n
    return 0; //1
}