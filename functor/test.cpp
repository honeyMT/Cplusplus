#include <stdio.h>    
#include <stdlib.h>    
//int sort_function( const void *a, const void *b);    
int sort_function( const void *a, const void *b)    
{       
    return *(int*)a-*(int*)b;    
}    
    
int main()    
{    
       
   int list[5] = { 54, 21, 11, 67, 22 };    
   qsort((void *)list, 5, sizeof(list[0]), sort_function);//起始地址，个数，元素大小，回调函数     
   int  x;    
   for (x = 0; x < 5; x++)    
          printf("%i\n", list[x]);    
                      
   return 0;    
} 

//****************************************************************************//
//****************************************************************************//

template<class T>  
struct A  
{  
    bool operator()(const T& a,const T& b)  
    {  
        return (a == b);  
    }  
};  
  
int main()  
{  
    A<int>a;  
    cout << a(1, 2) << endl;  
    system("pause");  
    return 0;  
}  

//****************************************************************************//
//****************************************************************************//



template<class T>  
class Delete  
{  
public:  
    Delete()  
    {}  
    void operator()(T* _ptr)  
    {  
        cout << "delete" << endl;  
        delete _ptr;  
        _ptr = NULL;  
    }  
    ~Delete()  
    {}  
protected:  
    T* _ptr;  
};  
  
  
//使用delete[]释放空间的仿函数    
template<class T>  
class DeleteArray  
{  
public:  
    DeleteArray()  
    {}  
    void operator()(T* _ptr)  
    {  
        cout << "delete[]" << endl;  
        delete[] _ptr;  
        _ptr = NULL;  
    }  
    ~DeleteArray()  
    {}  
  
};  
  
  
template<class T, class Del = Delete<T>>  
class Shared_Ptr  
{  
public:  
    Shared_Ptr( T* ptr)  
    :_ptr(ptr)  
    , _nums(new int(1))  
    {}  
  
    Shared_Ptr(const Shared_Ptr<T>& cur)  
        :_ptr(cur._ptr)  
        , _nums(cur._nums)  
    {  
        ++(*nums);  
    }  
  
    Shared_Ptr<T>& operator = (Shared_Ptr<T>& cur)  
    {  
        if (this != &cur)  
        {  
            _ptr = cur._ptr;  
            _nums = cur._nums;  
            ++(*_nums);  
        }  
        return *this;  
    }  
  
    T& operator*()  
    {  
        return _ptr;  
    }  
  
    T* operator->()  
    {  
        return _ptr;  
    }  
  
    ~Shared_Ptr()  
    {  
        Relese();  
    }  
  
    void Relese()  
    {  
        if (--(*_nums) == 0)  
        {  
            delete _nums;  
            Del _del;  
            _del(_ptr);  
            _nums = NULL;  
            _ptr = NULL;  
        }  
    }  
protected:  
    T* _ptr;  
    int* _nums;  
  
};  
  
void Test()  
{  
    Shared_Ptr<int> ptr(new int(1));  
    Shared_Ptr<string, DeleteArray<string>> ptr2(new string[20]);  
}  