#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int min_Units(vector<int> weights)
{
	sort(weights.begin(), weights.end());  //nlogn
	int lowerLimit = -1;
	int upperLimit = -1;
	int unit = 0;
	for (int index = 0; index < weights.size(); index++)
	{
		if (weights[index] >= lowerLimit && weights[index] <= upperLimit)
		{
			//skip count
		}
		else 
		{
			lowerLimit = weights[index];
			upperLimit = lowerLimit + 4;
			unit++;
		}
	}
	return unit;
}

int main(void)
{
	int N;
	cin >> N;
	vector<int> weights(N);
	for (int index = 0; index < N; index++)
	{
		cin >> weights[index];
	}
	cout << min_Units(weights) << std::endl;
	return  0;
}
