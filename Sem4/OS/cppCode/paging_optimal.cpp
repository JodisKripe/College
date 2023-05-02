#include <iostream>
using namespace std;

bool search(int A[], int np, int p) {
	bool found = false;
	for(int i = 0; i < np; i++) {
    	if(p == A[i]) {
        	found = true;
        	break;
    	}
	}
	return found;
}

int *replace(int A[], int np, int p1, int p2) {
	for(int i = 0; i < np; i++) {
    	if(A[i] == p1) {
        	A[i] = p2;
        	break;
    	}
	}
	return A;
}

int toReplace(int A[], int i, int np, int f[], int nf) {
	int toReplace = -1;
	int lastUse = -1;
	for(int j = 0; j < nf; j++) {
    	if(f[j] == -1) {
        	toReplace = -1;
        	break;
    	}
    	else {
        	for(int k = i; k < np; k++) {
            	if(A[k] == f[j]) {
                	if(lastUse == -1) {
                    	toReplace = f[j];
                    	lastUse = k;
                	}
                	else if(lastUse < k) {
                    	toReplace = f[j];
                    	lastUse = k;
                	}
                	break;
            	}
            	else if(k == np - 1) {
                	toReplace = f[j];
                	lastUse = k;
            	}
        	}
    	}
	}
	return toReplace;
}

int main() {
	int np;
	cout << "Enter the number of pages: ";
	cin >> np;
	int nf;
	cout << "Enter the number of frames: ";
	cin >> nf;
	int* frame = new int[nf];
	int* pages = new int[np];

	for(int i = 0; i < nf; i++) {
    	frame[i] = -1;
	}

	for(int i = 0; i < np; i++) {
    	cout << "Enter page " << i << ": ";
    	cin >> pages[i];
    	cout << endl;
	}

	int hit = 0;
	int fault = 0;
	for(int i = 0; i < np; i++) {
    	//cout << pages[i] << " ";

    	if(search(frame, nf, pages[i]) == true) {
        	//cout << " Hit" << endl;
        	hit += 1;
    	}
    	else {
        	//cout << "Fault " << toReplace(pages, i, np, frame, nf) << endl;
        	int replacePage = toReplace(pages, i, np, frame, nf);
        	fault += 1;
        	frame = replace(frame, nf, replacePage, pages[i]);
    	}
    	//cout << endl;
	}

	cout << "Total Hit: " << hit << endl;
	cout << "Total Fault: " << fault << endl;

	delete[] frame;
	delete[] pages;

	return 0;
}
