#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

//void swap(string& array, unsigned int i, unsigned int j)
//{
//	char t = array[i];
//	array[i] = array[j];
//	array[j] = t;
//}
//
//void FullArray(string array, vector<string>& arr, unsigned int index)
//{
//	size_t array_size = array.size();
//	if (index >= array_size)
//	{
//		arr.push_back(array);
//		return;
//	}
//
//	for (unsigned int i = index; i < array_size; ++i)
//	{
//		swap(array, i, index);
//
//		FullArray(array, arr, index + 1);
//
//		swap(array, i, index);
//	}
//}
//
//vector<string> Permutation(string str) {
//	set<char> arr;
//	vector<string> arr2;
//
//	for (int i = 0; i< str.size(); ++i)
//	{
//		arr.insert(str[i]);
//	}
//	str.clear();
//	set<char>::iterator it1 = arr.begin();
//	while (it1 != arr.end())
//	{
//		str += *it1;
//		++it1;
//	}
//	FullArray(str, arr2, 0);
//	return arr2;
//}
//template <typename T>
//inline void swap(T* array, unsigned int i, unsigned int j)
//{
//	T t = array[i];
//	array[i] = array[j];
//	array[j] = t;
//}
//
///*
//* 递归输出序列的全排列
//*/
//void FullArray(char* array, size_t array_size, unsigned int index)
//{
//	if (index >= array_size)
//	{
//		for (unsigned int i = 0; i < array_size; ++i)
//		{
//			cout << array[i] << ' ';
//		}
//
//		cout << '\n';
//
//		return;
//	}
//
//	for (unsigned int i = index; i < array_size; ++i)
//	{
//		swap(array, i, index);
//
//		FullArray(array, array_size, index + 1);
//
//		swap(array, i, index);
//	}
//}

void swap(string& array, unsigned int i, unsigned int j)
{
	char t = array[i];
	array[i] = array[j];
	array[j] = t;
}

void FullArray(string array, set<string>& arr, unsigned int index)
{
	size_t array_size = array.size();
	if (index >= array_size)
	{
		arr.insert(array);
		return;
	}

	for (unsigned int i = index; i < array_size; ++i)
	{
		swap(array, i, index);

		FullArray(array, arr, index + 1);

		swap(array, i, index);
	}
}

vector<string> Permutation(string str) {
	set<string> arr;
	vector<string> arr2;
	if (str.empty())
		return arr2;

	FullArray(str, arr, 0);

	set<string>::iterator it1 = arr.begin();
	while (it1 != arr.end())
	{
		arr2.push_back(*it1);
		++it1;
	}

	return arr2;
}


void Test()
{
	string arr = "";
	vector<string> b = Permutation(arr);

	system("pause");
}