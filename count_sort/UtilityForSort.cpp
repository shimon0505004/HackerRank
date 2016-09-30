#include "UtilityForSort.h"
#include<vector>
#include<algorithm>

using namespace std;

int UtilityForSort::max_element_index(const vector<int>& inputArray)
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

int UtilityForSort::min_element_index(const vector<int>& inputArray)
{
	int minElementIndex = -1;
	if (inputArray.size() >= 1)
	{
		minElementIndex = 0;
		for (int index = 1; index < inputArray.size(); index++)
		{
			if (inputArray[index] < inputArray[minElementIndex])
			{
				minElementIndex = index;
			}
		}
	}
	return minElementIndex;
}

//count sort
vector<int> UtilityForSort::count_sort(vector<int> inputArray)
{
	int maxElementIndex = max_element_index(inputArray);
	int minElementIndex = min_element_index(inputArray);
	if (maxElementIndex >= 0 &&
		minElementIndex >= 0 &&
		inputArray[minElementIndex] >= 0)
	{
		int countArrSize = inputArray[maxElementIndex] + 1;

		vector<int> count(countArrSize);
		for (int index = 0; index < inputArray.size(); index++)
		{
			count[inputArray[index]] += 1;
		}

		vector<int> position(count.size());
		position[0] = 0;
		for (int index = 1; index < count.size(); index++)
		{
			position[index] = position[index - 1] + count[index - 1];
		}

		vector<int> returnArray(inputArray.size());
		for (int index = 0; index < inputArray.size(); index++)
		{
			returnArray[position[inputArray[index]]] = inputArray[index];
			position[inputArray[index]] += 1;
		}

		return returnArray;
	}
	//Count sort is not possible. go back to O(nlogn) comparison sort
	vector<int> returnArray = inputArray;
	sort(returnArray.begin(), returnArray.end(), [](int first, int second) { 
		return first < second; });
	return returnArray;
}
