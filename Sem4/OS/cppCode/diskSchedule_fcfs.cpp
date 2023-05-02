#include <iostream>
#include <cmath>
#define MAX 200

void calculateTotalHeadMovement(int req[], int head, int size)
{
	int totalMovement = 0;
	int current = head;
    
	for (int i = 0; i < size; i++) {
    	totalMovement += abs(current - req[i]);
    	current = req[i];
	}
    
	std::cout << "Total head movement = " << totalMovement << std::endl;
}

int main()
{
	int n, head, req[MAX];
    
	std::cout << "Enter the size of the request queue: ";
	std::cin >> n;
    
	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> head;
    
	std::cout << "Enter the request queue: ";
	for (int i = 0; i < n; i++) {
    	std::cin >> req[i];
	}
    
	calculateTotalHeadMovement(req, head, n);
    
	return 0;
}
