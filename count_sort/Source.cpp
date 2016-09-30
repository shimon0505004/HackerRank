#include<iostream>
#include<vector>
#include "UtilityForSort.h"

using namespace std;

int main(void)
{
	vector<int> inputArray = { 34, 1 , 231, 2 , 1, 2, -1 };
	vector<int> outputArray = UtilityForSort::count_sort(inputArray);
	for (int index = 0; index < outputArray.size(); index++)
	{
		cout << outputArray[index] << endl;
	}

	return 0;

}
