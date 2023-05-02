#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_REQUESTS 200

void lookAlgorithm(int requestQueue[], int initialHeadPosition, int queueSize)
{
	int totalHeadMovement = 0;
	int currentPosition = initialHeadPosition;
	int startIndex = 0;
	int endIndex = queueSize - 1;

	// Sort the request queue in ascending order
	for (int i = 0; i < queueSize; i++)
	{
    	for (int j = i + 1; j < queueSize; j++)
    	{
        	if (requestQueue[i] > requestQueue[j])
        	{
            	int temp = requestQueue[i];
            	requestQueue[i] = requestQueue[j];
            	requestQueue[j] = temp;
        	}
    	}
	}

	// Find the index at which the head starts moving towards the end of the disk
	for (int i = 0; i < queueSize; i++)
	{
    	if (requestQueue[i] > initialHeadPosition)
    	{
        	startIndex = i;
        	break;
    	}
	}

	// If the head moves towards the end of the disk
	if (startIndex != 0)
	{
    	endIndex = startIndex - 1;
	}

	// Traverse the request queue in the direction of the head movement
	for (int i = startIndex; i < queueSize; i++)
	{
    	totalHeadMovement += abs(currentPosition - requestQueue[i]);
    	currentPosition = requestQueue[i];
	}

	for (int i = endIndex; i >= 0; i--)
	{
    	totalHeadMovement += abs(currentPosition - requestQueue[i]);
    	currentPosition = requestQueue[i];
	}

	std::cout << "Total head movement = " << totalHeadMovement << std::endl;
}

int main()
{
	int n, initialHeadPosition, requestQueue[MAX_REQUESTS];

	std::cout << "Enter the size of the request queue: ";
	std::cin >> n;

	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> initialHeadPosition;

	std::cout << "Enter the request queue: ";
	for (int i = 0; i < n; i++)
	{
    	std::cin >> requestQueue[i];
	}

	lookAlgorithm(requestQueue, initialHeadPosition, n);

	return 0;
}
