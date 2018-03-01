#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

int StrToInt(string str) {
	char tmp;
	bool flag = true;
	int num = 0;
	if (str.empty())
		return 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[0] == '+');
			else
				flag = false;

			str[0] = 1;
			continue;
		}

		if (str[i] == '\0')
			return 0;

		if (isdigit(str[i]))
		{
			num = 10 * num + (str[i] - '0');
		}
		else
		{
			return 0;
		}
	}

	if (flag)
		return num;
	else
		return -1 * num;
}

void Test()
{
	string str = "+1221312aeq3";
	cout<<StrToInt(str)<<endl;

	system("pause");
}