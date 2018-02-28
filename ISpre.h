#include<iostream>
#include<Windows.h>
#include<assert.h>
#include<vector>

using namespace std;


bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty() || sequence.size() == 1)
		return true;
	int i = 0;
	bool flag = false;
	int end = sequence.size();
	int minIndex = end - 1;

	for (i = 1; i < end; ++i)
	{
		if (sequence[i] < sequence[i - 1])
			flag = true;
	}

	if (flag == true)
		return true;

	flag = false;

	for (i = 0; i < end; ++i)
	{
		if (i + 1 < end)
		{
			if (sequence[minIndex] > sequence[i] && sequence[minIndex] < sequence[i + 1])
			{
				flag = true;
				break;	
			}
		}
	}

	if (flag == false)
	{
		for (i = 1; i < end; ++i)
		{
			if (sequence[i - 1] > sequence[i])
				return false;
		}
	}
	else{
		vector<int> arr1(sequence.begin(), sequence.begin() + i + 1);
		vector<int> arr2(sequence.begin() + i + 1, sequence.end()-1);
		return VerifySquenceOfBST(arr1) && VerifySquenceOfBST(arr2);
	}
	return true;
}

void Test()
{
	int a[] = { 4, 8, 6, 12, 16, 14, 10 };

	vector<int> arr;
	//arr.push_back(4);
	//arr.push_back(8);
	//arr.push_back(6);
	//arr.push_back(12);
	//arr.push_back(16);
	//arr.push_back(14);
	//arr.push_back(10);

	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(1);
	

	cout << VerifySquenceOfBST(arr) << endl;
	system("pause");
}