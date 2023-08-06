#include <iostream>

using namespace std;

// WAP to write a linear search program

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to be searched: ";
    cin >> key;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Key found at index " << i << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "Key not found" << endl;
    }
    return 0;
}