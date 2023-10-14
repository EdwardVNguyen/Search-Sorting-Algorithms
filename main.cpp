// This program is for educational purposes for understanding how to create sorting & search algorithms.

#include <iostream>
#include <vector>

int linear_search(std::vector<int>& vector, int targetNum);
int binary_search(std::vector<int>& vector, int targetNum);

int main()
{
	std::vector<int> vect;

	for (int i = 1; i <= 100; ++i) // Vector of size 100, this will be the list we will be working with. This is vary to change for testing purposes.
	{
		vect.push_back(i);
	}

	binary_search(vect, 55);
}

int linear_search(std::vector<int>& vector, int targetNum)
{
	int numSteps = 1;

	for (int i = 0; i < vector.size(); ++i)
	{
		if (vector.at(i) == targetNum)
		{
			std::cout << "Target number of " << targetNum << " is found at index " << i << "\n";
			std::cout << "It has taken " << numSteps << " amounts of steps to find\n";
			return 0;
		}
		numSteps++;
	}
	
	std::cout << "Target number not found in vector\n";
	return 1;
}

int binary_search(std::vector<int>& vector, int targetNum)
{
	int numSteps = 1;

	int start = 0;
	int middle = vector.size() / 2;
	int end = vector.size() - 1;

	while (true)
	{
		if (vector.at(middle) == targetNum)
		{
			std::cout << "Target number of " << targetNum << " is found at index " << middle << "\n";
			std::cout << "It has taken " << numSteps << " amount of steps to find\n";
			return 0;
		}
		else if (vector.at(middle) >= targetNum)
		{
			end = middle - 1;
			numSteps++;
		}
		else
		{
			start = middle + 1;
			numSteps++;
		}
		
		middle = (start + end) / 2;

		if (start > end)
		{
			std::cout << "Target number not found in list\n";
			return 1;
		}
	}
}