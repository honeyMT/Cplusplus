#include<iostream>
#include<Windows.h>
#include<assert.h>

using namespace std;

//class AA
//{
//public:
//
//	virtual void fun1()
//	{
//		cout << "hehe" << endl;
//	}
//public:
//	int a;
//};
//
//class BB :public AA
//{
//public:
//
//	virtual void fun1()
//	{
//		cout << "heh2e" << endl;
//	}
//public:
//	int c;
//};
//int main()
//{
//	AA* q = new AA();
//	BB* p = new BB();
//	AA* a;
//	BB* b;
//
//	b = dynamic_cast<BB*>(q);
//	if (b == NULL)
//	{
//		cout << "AA为基类" << endl;
//	}
//	else{
//		cout << "AA为子类" << endl;
//	}
//
//	a = dynamic_cast<AA*>(p);
//	if (a == NULL)
//	{
//		cout << "BB为基类" << endl;
//	}
//	else
//	{
//		cout << "BB为子类" << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	volatile const int a = 2;
	int *p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
	system("pause");
	return 0;
}