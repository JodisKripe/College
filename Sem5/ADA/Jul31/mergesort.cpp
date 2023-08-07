#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1; //1
    int n2 = high - mid; //1
    int left[n1]; //1
    int right[n2]; //1
    for (int i = 0; i < n1; i++) { //n1+1
        left[i] = arr[low + i]; //n1
    }
    for (int i = 0; i < n2; i++) { //n2+1
        right[i] = arr[mid + 1 + i]; //n2
    }
    int i = 0; //1
    int j = 0; //1
    int k = low; //1
    while (i < n1 && j < n2) { //n1+n2+1
        if (left[i] <= right[j]) { //1
            arr[k] = left[i]; //1
            i++; //1
        } else { //1
            arr[k] = right[j]; //1
            j++; //1
        }
        k++; //1
    }
    while (i < n1) { //n1+1
        arr[k] = left[i]; //n1
        i++; //1
        k++; //1
    }
    while (j < n2) { //n2+1
        arr[k] = right[j]; //n2
        j++; //1
        k++; //1
    }
}

void mergesort(int arr[], int low, int high) {
    if (low < high) { //1
        int mid = (low + high) / 2; //1
        mergesort(arr, low, mid); //T(n/2)
        mergesort(arr, mid + 1, high); //T(n/2)
        merge(arr, low, mid, high); //n
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
    mergesort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;//1
}
// T(n) = 2T(n/2) + n
// T(n) = O(nlogn)
