#include<iostream>

using namespace std;


int feb(int n)
{
	int f = 1;
	int g = 1;

	while (--n)
	{
		g += f;
		f = g - f;
	}
	return f;
}



void Test()
{
	cout << feb(1);
	cout << feb(2);
	cout << feb(3);
	cout << feb(4);
	cout << feb(5);

	system("pause");

}