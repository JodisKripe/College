#include <iostream>
using namespace std;

bool isPresent(int arr[], int size, int item) {
	for (int i = 0; i < size; i++) {
    	if (item == arr[i]) {
        	return true;
    	}
	}
	return false;
}

int* replace(int arr[], int size, int oldItem, int newItem) {
	for (int i = 0; i < size; i++) {
    	if (arr[i] == oldItem) {
        	arr[i] = newItem;
        	break;
    	}
	}
	return arr;
}

int getReplacementIndex(int arr[], int index, int frames[], int size) {
	int replacementIndex = -1;
	int lastUse = -1;
	for (int j = 0; j < size; j++) {
    	if (frames[j] == -1) {
        	replacementIndex = -1;
        	break;
    	} else {
        	for (int k = index; k >= 0; k--) {
            	if (arr[k] == frames[j]) {
                	if (lastUse == -1) {
                    	replacementIndex = frames[j];
                    	lastUse = k;
                	} else if (lastUse > k) {
                    	replacementIndex = frames[j];
                    	lastUse = k;
                	}
                	break;
            	}
        	}
    	}
	}
	return replacementIndex;
}

int main() {
	int numPages;
	cout << "Enter the number of pages: ";
	cin >> numPages;

	int numFrames;
	cout << "Enter the number of frames: ";
	cin >> numFrames;

	int* frames = new int[numFrames];
	int* pages = new int[numPages];

	for (int i = 0; i < numFrames; i++) {
    	frames[i] = -1;
	}

	for (int i = 0; i < numPages; i++) {
    	cout << "Enter page " << i << ": ";
    	cin >> pages[i];
    	cout << endl;
	}

	int numHits = 0;
	int numFaults = 0;
	for (int i = 0; i < numPages; i++) {
    	if (isPresent(frames, numFrames, pages[i])) {
        	//cout << "Hit\n";
        	numHits++;
    	} else {
        	int replacePage = getReplacementIndex(pages, i, frames, numFrames);
        	//cout << "Fault " << replacePage << endl;
        	numFaults++;
        	frames = replace(frames, numFrames, replacePage, pages[i]);
    	}

	}

	cout << "Total Hit: " << numHits << endl;
	cout << "Total Fault: " << numFaults << endl;

	delete[] frames;
	delete[] pages;
	return 0;
}
