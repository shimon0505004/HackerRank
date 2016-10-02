#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;


int max_element_index(const vector<int>& inputArray)
{
	int maxElementIndex = -1;
	if (inputArray.size() >= 1)
	{
		maxElementIndex = 0;
		for (int index = 1; index < inputArray.size(); index++)
		{
			if (inputArray[index] > inputArray[maxElementIndex])
			{
				maxElementIndex = index;
			}
		}
	}
	return maxElementIndex;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int inputSize;
	cin >> inputSize;
	vector<int> input(inputSize);
	for (vector<int>::iterator inputIterator = input.begin(); inputIterator != input.end(); inputIterator++)
	{
		cin >> *inputIterator;
	}

	int countSize = input[max_element_index(input)]+1;
	vector<int> count(countSize);
	
	try
	{
		for (vector<int>::iterator inputIterator = input.begin(); inputIterator != input.end(); inputIterator++)
		{
			if (*inputIterator < 0)
			{
				throw exception();
			}
			count[*inputIterator] += 1;
		}

		for (vector<int>::iterator countIterator = count.begin(); countIterator != count.end(); countIterator++)
		{
			cout << *countIterator << " ";
		}
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
