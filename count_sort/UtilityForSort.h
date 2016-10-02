#pragma once
#include<vector>
#include<list>

namespace UtilityForSort 
{
	std::vector<int> count_sort(const std::vector<int>& inputArray);
	int max_element_index(const std::vector<int>& inputArray);
	int min_element_index(const std::vector<int>& inputArray);

	std::vector<int> merge_sort(std::vector<int> inputArray);
	std::vector<int> merge(std::vector<int> array1, std::vector<int> array2);
};
