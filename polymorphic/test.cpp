# define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<Windows.h>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << " 买票" << endl;
//	}
//
//protected:
//	string _name;   // 姓名  
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTickets()
//	{
//		cout << " 买票-半价 " << endl;
//	}
//
//protected:
//	int _num;   //学号  
//};
//
//void Fun(Person& p)
//{
//	p.BuyTickets();
//}
//
//void Test()
//{
//	Person p;
//	Student s;
//	Fun(p);
//	Fun(s);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//
//class A
//{
//public:
//	void foo()
//	{
//		printf("1\n");
//	}
//	virtual void fun()
//	{
//		printf("2\n");
//	}
//};
//class B : public A
//{
//public:
//	void foo()
//	{
//		printf("3\n");
//	}
//	void fun()
//	{
//		printf("4\n");
//	}
//};
//int main(void)
//{
//	A a;
//	//B b;
//	//A *p = &a;
//	//p->foo();
//	//p->fun();
//	//p = &b;
//	//p->foo();
//	//p->fun();
//	B *ptr = (B *)&a; 
//	ptr->foo(); 
//	ptr->fun();
//	system("pause");
//	return 0;
//}


//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1" << endl;
//	}
//};
//class Base1:public Base
//{
//public:
//
//	virtual void func2()
//	{
//		cout << "Base1::func2" << endl;
//	}
//
//private:
//	int b1;
//};
//
//class Base2 :public Base
//{
//public:
//
//	virtual void func3()
//	{
//		cout << "Base2::func3" << endl;
//	}
//
//private:
//	int b2;
//};
//
//
//class Derive : public Base1, public Base2
//{
//public:
//
//	virtual void func4()
//	{
//		cout << "Derive::func3" << endl;
//	}
//
//private:
//	int d1;
//};


class Base1
{
public:
	virtual void func1()
	{
		cout << "Base1::func1" << endl;
	}

	virtual void func2()
	{
		cout << "Base1::func2" << endl;
	}

private:
	int b1;
};

class Base2
{
public:
	virtual void func1()
	{
		cout << "Base2::func1" << endl;
	}

	virtual void func2()
	{
		cout << "Base2::func2" << endl;
	}

private:
	int b2;
};


class Derive : public Base1, public Base2
{
public:
	virtual void func1()
	{
		cout << "Derive::func1" << endl;
	}

	virtual void func3()
	{
		cout << "Derive::func3" << endl;
	}

private:
	int d1;
};

typedef void(*FUNC) ();
void PrintVTable(int* VTable)
{
	cout << " 虚表地址>" << VTable << endl;

	for (int i = 0; VTable[i] != 0; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, VTable[i]);
		FUNC f = (FUNC)VTable[i];
		f();
	}
	cout << endl;
}


void Test1()
{
	Derive d1;
	//Base2虚函数表在对象Base1后面  
	int* VTable = (int*)(*(int*)&d1);
	PrintVTable(VTable);
	int* VTable2 = (int *)(*((int*)&d1 + sizeof (Base1) / 4));
	PrintVTable(VTable2);
}
int main()
{
	Test1();
	system("pause");
	return 0;
}
