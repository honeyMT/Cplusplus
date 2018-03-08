#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> insertionSortList(vector<int> head) {
	vector<int> arr;
	if (head.empty())
		return arr;

	list<int> l1;

	for (int i = 0; i < head.size(); ++i)
	{
		l1.push_back(head[i]);
	}

	auto it1 = l1.begin();
	auto it2 = l1.begin();

	for (it1 = l1.begin(); it1 != l1.end(); ++it1)
	{
		if (it1 != l1.begin())
		{
			auto tmp = *it1;
			auto it = it1;
			it2 = --it1;
			it1 = it;
			while (it2 != l1.begin() && (*it2) > tmp)
			{
				*(--it2) = *it2;
			}
			*(++it2) = tmp;
		}
	}

	return arr;
}


void Test()
{
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(5);

	insertionSortList(arr);

	system("pause");
}