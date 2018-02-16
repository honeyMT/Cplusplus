//new and delete

class Array  
{  
public :  
     Array (size_t size = 10)  
        : _size(size )  
        , _a(0)  
    {  
         cout<<"Array(size_t size)" <<endl;  
         if (_size > 0)  
        {  
             _a = new int[ size];  
        }  
    }  
  
    ~ Array()  
    {  
         cout<<"~Array()" <<endl;  
         if (_a )  
        {  
             delete[] _a ;  
             _a = 0;  
             _size = 0;  
        }  
    }  
private :  
     int*_a ;  
     size_t   _size ;  
};  
  
void Test ()  
{  
     Array* p1 = (Array*) malloc(sizeof (Array));  
     Array* p2 = new Array;  
     Array* p3 = new Array(20);  
     Array* p4 = new Array[10];  
  
     free(p1 );  
     delete p2 ;  
     delete p3 ;  
     delete[] p4 ;  
}  

//********************************************************************//
//********************************************************************//
class A  
{  
public:  
    A()  
    :_num(10)  
    {  
        cout << "构造函数调用了" << endl;  
    }  
    ~A()  
    {  
        cout << "析构函数调用了" << endl;  
    }  
private:  
    int _num;  
};  
int main()  
{  
    A* i = new A[10];  
    delete[] i;  
    system("pause");  
    return 0;  
}

//********************************************************************//
//********************************************************************//


class Array  
{  
public :  
     Array (size_t size = 10)  
        : _size(size )  
        , _a(0)  
    {  
         cout<<"Array(size_t size)" <<endl;  
         if (_size > 0)  
        {  
             _a = new int[ size];  
        }  
    }  
  
    ~ Array()  
    {  
         cout<<"~Array()" <<endl;  
         if (_a )  
        {  
             delete[] _a ;  
             _a = 0;  
             _size = 0;  
        }  
    }  
private :  
     int*    _a ;  
     size_t  _size ;  
};  
  
void Test ()  
{  
     // 1.malloc/free + 定位操作符new()/显示调用析构函数，模拟 new和delete 的行为  
     Array* p1 = (Array*) malloc(sizeof (Array));  
     new(p1 ) Array(100);  
  
     p1->~Array ();  
     free(p1 );  
  
     // 1.malloc/free + 多次调用定位操作符new()/显示调用析构函数，模拟 new[]和delete[] 的行为  
     Array* p2 = (Array*) malloc(sizeof (Array)*10);  
     for(int i = 0; i < 10; ++i )  
    {  
         new(p2 +i) Array;  
    }  
  
     for(int i = 0; i < 10; ++i )  
    {  
         p2[i ].~Array();  
    }  
     free(p2 );  
}
