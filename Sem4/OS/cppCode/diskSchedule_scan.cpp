#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_REQUESTS 200

void disk_scan(int requests[], int head, int size)
{
	int total_movement = 0;
	int current_pos = head;
	int start_index = 0;
	int i;
    
	// Sort the request queue in ascending order
	std::sort(requests, requests + size);
    
	// Find the index at which the head starts moving towards the end of the disk
	for (i = 0; i < size; i++) {
    	if (requests[i] > head) {
        	start_index = i;
        	break;
    	}
	}
    
	// Traverse the request queue in the direction of the head movement
	for (i = start_index; i < size; i++) {
    	total_movement += std::abs(current_pos - requests[i]);
    	current_pos = requests[i];
	}
    
	// Add the movement to the end of the disk
	total_movement += std::abs(current_pos - 199);
	current_pos = 199;
    
	// Reverse direction and move towards the beginning of the disk
	for (i = start_index-1; i >= 0; i--) {
    	total_movement += std::abs(current_pos - requests[i]);
    	current_pos = requests[i];
	}
    
	std::cout << "Total head movement = " << total_movement << std::endl;
}

int main()
{
	int num_requests, head_pos, requests[MAX_REQUESTS];
    
	std::cout << "Enter the number of requests: ";
	std::cin >> num_requests;
    
	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> head_pos;
    
	std::cout << "Enter the requests: ";
	for (int i = 0; i < num_requests; i++) {
    	std::cin >> requests[i];
	}
    
	disk_scan(requests, head_pos, num_requests);
    
	return 0;
}
