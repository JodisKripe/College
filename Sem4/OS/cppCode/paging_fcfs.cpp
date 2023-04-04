#include <iostream>
using namespace std;
// 3 20 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6


int main() {
    int frames,c, pages,p, pageFaults = 0, pointer = 0;
    bool isFull = false;
    
    
    cout << "Enter the number of frames: ";
    cin >> frames;
    c=frames;
    
    int buffer[frames];
    for(int i = 0; i < frames; i++) buffer[i] = -1; // Initialize buffer with -1
    
    cout << "Enter the number of pages: ";
    cin >> pages;
    p=pages;
    
    int arr[pages];
    cout << "Enter the page reference string: ";
    for(int i = 0; i < pages; i++) cin >> arr[i];
    //for(int i = 0; i < pages; i++) cout << arr[i];
    
    for(int i = 0; i < pages; i++) {
        frames=c;
        int pf=0;
        //cout<<arr[i];
        bool isHit = false;
        for(int j = 0; j < frames; j++) {
            if(buffer[j] == arr[i]) { // Page hit
                //cout << "\nHIT";
                isHit = true;
                break;
            }
        }
        if(!isHit) { // Page fault
            frames=c;
            buffer[pointer] = arr[i];
            //cout<<":"<<pointer<<endl;
            buffer[i] = arr[i];
            pointer++;
            if(pointer >= frames) {
                pointer = 0;
                isFull = true;
            }
            if(pageFaults<pf) pageFaults = pf +1;
            pf=pageFaults++;

        }
        cout << endl << arr[i];
        // for(int k = 0; k < frames; k++) {
        //     cout << buffer[k] << " ";
        // }
        pages=p;
    }
    
    cout << endl << "Total Page Faults: " << pageFaults;
    return 0;
}
