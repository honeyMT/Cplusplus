#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

int FirstNotRepeatingChar(string str) {
	if (str.empty())
		return -1;
	char arr[256] = { 0 };
	int size = str.size();
	for (int i = 0; i < size; ++i)
	{
		++arr[str[i]];
	}

	for (int i = 0; i < size; ++i)
	{
		if (arr[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

void Test()
{
	string arr = "google";

	cout << FirstNotRepeatingChar(arr);

	system("pause");
}