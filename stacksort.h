#include<iostream>
#include<Windows.h>
#include<stack>

using namespace std;

void stacksork(stack<int>& p)
{
	stack<int> q;
	int tmp = 0;
	while (!p.empty())
	{
		tmp = p.top();
		p.pop();

		while (!q.empty() && tmp > q.top())
		{
			p.push(q.top());
			q.pop();
		}
		q.push(tmp);
	}

	while (!q.empty())
	{
		p.push(q.top());
		q.pop();
	}
}
int fun()
{
	return true;
}
void Test()
{
	stack<int> arr;
	arr.push(4);
	arr.push(9);
	arr.push(1);
	arr.push(3);
	arr.push(2);
	arr.push(10);

	cout << fun() + 1 << endl;
	
 
	stacksork(arr);
	system("pause");
}