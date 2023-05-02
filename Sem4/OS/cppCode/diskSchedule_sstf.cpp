#include <iostream>
#include <cmath>
#include <limits>

#define MAX_REQUESTS 200

void shortestSeekTimeFirst(int requests[], int start, int size)
{
	int totalMovement = 0;
	int visited[MAX_REQUESTS] = {0};
	int current = start;
    
	for (int i = 0; i < size; i++) {
    	int shortestDistance = std::numeric_limits<int>::max();
    	int selected = -1;
    	for (int j = 0; j < size; j++) {
        	if (!visited[j]) {
            	int distance = std::abs(current - requests[j]);
            	if (distance < shortestDistance) {
                	shortestDistance = distance;
                	selected = j;
            	}
        	}
    	}
    	visited[selected] = 1;
    	totalMovement += shortestDistance;
    	current = requests[selected];
	}
    
	std::cout << "Total head movement = " << totalMovement << std::endl;
}

int main()
{
	int numRequests, start, requests[MAX_REQUESTS];
    
	std::cout << "Enter the number of requests: ";
	std::cin >> numRequests;
    
	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> start;
    
	std::cout << "Enter the request queue: ";
	for (int i = 0; i < numRequests; i++) {
    	std::cin >> requests[i];
	}
    
	shortestSeekTimeFirst(requests, start, numRequests);
    
	return 0;
}
