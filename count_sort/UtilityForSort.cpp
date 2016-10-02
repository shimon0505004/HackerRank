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

//count sort. if the elements are 
vector<int> UtilityForSort::count_sort(const std::vector<int>& inputArray)
{
	int maxElementIndex = max_element_index(inputArray);
	int minElementIndex = min_element_index(inputArray);
	if (maxElementIndex >= 0 &&
		minElementIndex >= 0 &&
		inputArray[minElementIndex] >= 0)
	{
		if (inputArray.size() >= 0)
		{
			int countArrSize = inputArray[maxElementIndex] + 1;
			vector<int> count(countArrSize);
			for (int index = 0; index < inputArray.size(); index++)
			{
				count[inputArray[index]] += 1;
			}

			vector<int> position(count.size());
			if (position.size() >= 0)
			{
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
		}
		return vector<int>(0);
	}
	//Count sort is not possible. go back to O(nlogn) comparison sort
	vector<int> returnArray = inputArray;
	sort(returnArray.begin(), returnArray.end(), [](int first, int second) { 
		return first < second; });
	return returnArray;
}

std::vector<int> UtilityForSort::merge_sort(std::vector<int> inputArray)
{
	if (inputArray.size() <= 1)
	{
		return inputArray;
	}

	int pivotPosition = floor( inputArray.size() / 2 );
	vector<int>::iterator pivotPositionIterator = inputArray.begin() + pivotPosition;
	vector<int> lowerHalf(inputArray.begin(), pivotPositionIterator);
	vector<int> upperHalf(pivotPositionIterator, inputArray.end());
	vector<int> lowerHalf_Sorted = merge_sort(lowerHalf);
	vector<int> upperHalf_Sorted = merge_sort(upperHalf);
	return UtilityForSort::merge(lowerHalf_Sorted, upperHalf_Sorted);
}

std::vector<int> UtilityForSort::merge(std::vector<int> array1, std::vector<int> array2)
{
	vector<int>::iterator array1Iterator = array1.begin();
	vector<int>::iterator array2Iterator = array2.begin();

	vector<int> returnArray;
	while (array1Iterator != array1.end() && array2Iterator != array2.end())
	{
		if (*array1Iterator <= *array2Iterator)
		{
			returnArray.push_back(*array1Iterator);
			array1Iterator++;
		}
		else
		{
			returnArray.push_back(*array2Iterator);
			array2Iterator++;
		}
	}
	if (array1Iterator == array1.end())
	{
		returnArray.insert(returnArray.end(),array2Iterator, array2.end());	
	}
	else
	{
		returnArray.insert(returnArray.end(), array1Iterator, array1.end());
	}

	return returnArray;
}
