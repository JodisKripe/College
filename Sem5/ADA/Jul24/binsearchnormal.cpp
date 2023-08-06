#include <iostream>

using namespace std;

// WAP to write a binary search program without recursion

int binsearch(int arr[], int key, int low, int high) {
    while (low <= high) { // log2(n) + 1
        int mid = (low + high) / 2; //1
        if (arr[mid] == key) {//1
            return mid;//1
        } else if (arr[mid] > key) {//1
            high = mid - 1;//1
        } else {//1
            low = mid + 1;//1
        }
    }
    return -1;//1
}

int main(){
    int n, key;//0
    cout << "Enter the size of the array: ";//1
    cin >> n;//1
    int arr[n];//0
    cout << "Enter the elements of the array: "; //1
    for (int i = 0; i < n; i++) {//n+1
        cin >> arr[i];//1
    }
    cout << "Enter the key to be searched: "; //1
    cin >> key; //1
    int index = binsearch(arr, key, 0, n - 1); //1
    if (index == -1) { //1 
        cout << "Key not found" << endl; //1
    } else { //1
        cout << "Key found at index " << index << endl; //1
    }
    return 0; //1
}