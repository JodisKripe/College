#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_REQUESTS 200

void cScan(int requests[], int head, int numRequests)
{
	int totalMovement = 0;
	int current = head;
	int startIndex = 0;
	int i;

	// Sort the request queue in ascending order
	for (i = 0; i < numRequests; i++)
	{
    	for (int j = i+1; j < numRequests; j++)
    	{
        	if (requests[i] > requests[j])
        	{
            	int temp = requests[i];
            	requests[i] = requests[j];
            	requests[j] = temp;
        	}
    	}
	}

	// Find the index at which the head starts moving towards the end of the disk
	for (i = 0; i < numRequests; i++)
	{
    	if (requests[i] > head)
    	{
        	startIndex = i;
        	break;
    	}
	}

	// Traverse the request queue in the direction of the head movement
	for (i = startIndex; i < numRequests; i++)
	{
    	totalMovement += std::abs(current - requests[i]);
    	current = requests[i];
	}

	// If the last request is not at the end of the disk, move to the end of the disk
	if (requests[numRequests-1] != 199)
	{
    	totalMovement += std::abs(current - 199);
    	current = 199;
	}

	// Move to the beginning of the disk
	totalMovement += 199;
	current = 0;

	// Traverse the request queue in the direction of the head movement again
	for (i = 0; i < startIndex; i++)
	{
    	totalMovement += std::abs(current - requests[i]);
    	current = requests[i];
	}

	std::cout << "Total head movement = " << totalMovement << std::endl;
}

int main()
{
	int numRequests, head, requests[MAX_REQUESTS];

	std::cout << "Enter the size of the request queue: ";
	std::cin >> numRequests;

	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> head;

	std::cout << "Enter the request queue: ";
	for (int i = 0; i < numRequests; i++)
	{
    	std::cin >> requests[i];
	}

	cScan(requests, head, numRequests);

	return 0;
}
