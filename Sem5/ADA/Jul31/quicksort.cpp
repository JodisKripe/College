#include <iostream>

using namespace std;

// WAP to write a quick sort program

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main(){ 
    int n; //0
    cout << "Enter the size of the array: "; //1
    cin >> n; //1
    int arr[n]; //0
    cout << "Enter  the elements of the array: "; //1
    for (int i = 0; i < n; i++) { //n+1
        cin >> arr[i]; //n
    }
    quicksort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;//1
}

// T(n) = T(n/2) + T(n/2) + n