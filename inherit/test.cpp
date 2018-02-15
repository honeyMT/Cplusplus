# define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
#include<istream>
#include<ostream>
#include<string>
using namespace std;


class Person
{
public:
	string _name;   // 姓名
};

class Student : virtual public Person
{
protected:
	int _num;   //学号
};

class Teacher : virtual public Person
{
protected:
	int _id;     // 职工编号
};

class Assistant : virtual public Student, virtual public Teacher
{
protected:
	string _majorCourse;     // 主修课程
};

void Test()
{
	// 显示指定访问哪个父类的成员
	Assistant a;
	a.Student::_name = "听风";
	a.Teacher::_name = "听檒";

	Student* p = &a;
	Teacher* p2 = &a;

	cout << a.Student::_name << endl;
	cout << a.Teacher::_name << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}



//class Person
//{
//public:
//	void Display()
//	{
//		cout << _name << endl;
//	}
//
//protected:
//	string _name;   // 姓名
//};
//
//class Student : public Person
//{
//public:
//	int _num;   // 学号
//};
//
//void Test()
//{
//	Person p;
//	Student s;
//	// 4.子类的指针/引用不能指向父类对象
//	//（可以通过强制类型转换完成）
//	Student* p2 = (Student*)& p;
//	Student& r2 = (Student&)p;
//	
//	p2->_num = 10;
//	r2._num = 20;
//
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
//// 1.子类对象可以赋值给父类对象（切割 /切片）
//p = s;
//// 2.父类对象不能赋值给子类对象
////s = p;

//// 3.父类的指针/引用可以指向子类对象
//Person* p1 = &s;
//Person& r1 = s;

//// 4.子类的指针/引用不能指向父类对象（可以通过强制类型转换完成）
//Student* p2 = (Student*)& p;
//Student& r2 = (Student&)p;

//// 这里会发生什么？
//p2->_num = 10;
//r2._num = 20;

//class A
//{
//public:
//	A()
//	{
//		cout << "调用了父类的A" << endl;
//	}
//	void c()
//	{
//		cout << "调用了A.C" << endl;
//	}
//private:
//	int i;
//};


/*lass B:public A
 {
 public:
 void c()
 {
 cout << "调用了b.c" << endl;
 }
 B()
 {
 cout << "调用了B" << endl;
 }

 private:
 int m;
 };
 int main()
 {
 B s;
 s.c();
 system("pause");
 }*/