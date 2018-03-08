#include<iostream>
#include<Windows.h>
#include<deque>
#include<vector>
#include<queue>

using namespace std;

//vector<int> maxInWindows(const vector<int>& num, unsigned int size)
//{
//	vector<int> maxnum;
//	priority_queue<int> sizemaxnum;
//	int start = 0;
//	int end = 0;
//	int tmp = 0;
//	int i = 0;
//	if (num.empty())
//	{
//		return maxnum;
//	}
//	if (size > num.size() || size <= 0)
//	{
//		return maxnum;
//	}
//	//定义start最多走到哪里，再++，end就会越界
//	while(i < num.size()-size+1)
//	{
//		start = i;
//		end = start;
//		tmp = size;
//		while (--tmp > 0)
//		{
//			end++;
//		}
//		while (start <= end)
//		{
//			sizemaxnum.push(num[start++]);
//		}
// 		maxnum.push_back(sizemaxnum.top());
//		while (!sizemaxnum.empty())
//		{
//			sizemaxnum.pop();
//		}
//		++i;
//	}
//	return maxnum;
//}





int getsum(int num)
{
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int addrowcol(int rows, int cols)
{
	return getsum(rows) + getsum(cols);
}

bool check(int threshold, int rows, int cols, bool* arr, int i, int j)
{
	if (rows >= 0 && rows < i && cols >= 0 && cols< j
		&& addrowcol(rows, cols) <= threshold
		&& arr[i*rows + cols] == false)
		return true;
	return false;
}

int movingCountcore(int threshold, int rows, int cols, bool* arr, int i, int j)
{
	int count = 0;
	if (check(threshold, rows, cols, arr, i, j))
	{

		arr[rows*i + cols] = true;
		count = movingCountcore(threshold, rows - 1, cols, arr, i, j)
			+ movingCountcore(threshold, rows, cols - 1, arr, i, j)
			+ movingCountcore(threshold, rows + 1, cols, arr, i, j)
			+ movingCountcore(threshold, rows, cols + 1, arr, i, j) + 1;
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (rows && cols && threshold)
	{
		bool* arr = new bool[rows*cols];
		for (int i = 0; i<rows*cols; i++)
			arr[i] = false;
		int count = movingCountcore(threshold, 0, 0, arr, rows, cols);//从（0,0）坐标开始访问;
		delete[] arr;
		return count;
	}
	return 0;
}

void Test()
{
	movingCount(4, 3, 3);
	system("pause");

}