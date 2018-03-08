#include<iostream>
#include<Windows.h>
#include<queue>
#include<algorithm>
#include<vector>


using namespace std;

priority_queue<int, vector<int>, less<int>> pless;  //Ð¡¶Ñ
priority_queue<int, vector<int>, greater<int> >pGreater;         //´ó¶Ñ

void Insert(int num)
{
	if (pless.empty() || num <= pless.top()) //Ð¡¶Ñ¶¥
		pless.push(num);
	else
		pGreater.push(num);

	if (pless.empty() == pGreater.size() + 2)
	{
		pGreater.push(pless.top());
		pless.pop();
	}

	if (pless.size() + 2 == pGreater.size())
	{
		pless.push(pGreater.top());
		pGreater.pop();
	}
}




int maxnum(vector<int> array)
{
	if (array.empty())
		return 0;

	int Maxnum = 0;
	int count = 0;

	for (int i = 0; i < array.size(); ++i)
	{
		count += array[i];
		if (count > Maxnum)
			Maxnum = count;

		if (count < 0)
		{
			count = 0;
		}
	}
	return Maxnum;
}

void Test()
{
	int arr[] = { 1, 7, 8, 4, 3, 6, 2, 10, 11 };
	for (int i = 0; i < 9; ++i)
	{
		Insert(arr[i]);
	}

	system("pause");
}
