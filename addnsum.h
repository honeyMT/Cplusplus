#include<iostream>
#include<Windows.h>
#include<vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	int start = 1;
	int end = 0;
	int count = 0;
	vector<int> arr;
	vector<vector<int>> arr2;

	while (start != sum)
	{
		count = start;
		end = start;
		while (count < sum)
		{
			arr.push_back(end);
			end = arr[arr.size() - 1] + 1;
			count += end;
		}

		if (count > sum)
			arr.clear();
		else
		{
			arr.push_back(arr[arr.size() - 1] + 1);
			arr2.push_back(arr);
		}
		++start;
	}
	return arr2;
}

void Test()
{
	vector<vector<int>> arr;

	arr = FindContinuousSequence(9);

	system("pause");
}