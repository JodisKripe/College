#include <iostream>
#include <algorithm>

#define MAX 200

void custom_c_look(int requests[], int head, int n)
{
	int total_movement = 0;
	int current = head;
	int start_index = 0;
	int end_index = n - 1;

	// Sort the request queue in ascending order
	for (int i = 0; i < n; i++)
	{
    	for (int j = i + 1; j < n; j++)
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
	for (int i = 0; i < n; i++)
	{
    	if (requests[i] > head)
    	{
        	start_index = i;
        	break;
    	}
	}

	// If the head moves towards the end of the disk
	if (start_index != 0)
	{
    	end_index = start_index - 1;
	}

	// Traverse the request queue in the direction of the head movement
	for (int i = start_index; i < n; i++)
	{
    	total_movement += abs(current - requests[i]);
    	current = requests[i];
	}

	for (int i = 0; i <= end_index; i++)
	{
    	total_movement += abs(current - requests[i]);
    	current = requests[i];
	}

	std::cout << "Total head movement = " << total_movement << "\n";
}

int main()
{
	int n, head, requests[MAX];

	std::cout << "Enter the size of the request queue: ";
	std::cin >> n;

	std::cout << "Enter the initial position of the disk head: ";
	std::cin >> head;

	std::cout << "Enter the request queue: ";
	for (int i = 0; i < n; i++)
	{
    	std::cin >> requests[i];
	}

	custom_c_look(requests, head, n);

	return 0;
}
