try {  
    // do something  
    throw exception;  
} catch (exception declaration) {  
    //  excepetion handling code   
    // throw or no  
} catch (exception declaration) {  
    //  another excepetion handling code   
    // throw or no  
}  

//****************************************************************************//
//****************************************************************************//

class myexception : public std::exception {  
public :  
  myexception(std::string s) : exception(s.c_str()) {  
  
  }  
  virtual const char *what() const {  
    return exception::what();  
  }  
};  
  
void Func() {  
  try{  
    int *p = NULL;  
    if (p == NULL) {  
      throw myexception("p is NULL");  
    }  
  }  
  catch(myexception e) {  
    printf("%s\n", e.what());  
    throw;    //重新抛出异常，异常类型为myexception  
  }  
  catch (std::exception e) {  
    printf("%s", e.what());  
  }  
}  

//****************************************************************************//
//****************************************************************************//


class myexception : public std::exception {  
public :  
  myexception(std::string s) : exception(s.c_str()) {  
  
  }  
  virtual const char *what() const {  
    return exception::what();  
  }  
};  
  
class A {  
public :  
  ~A() {  
    printf("A's destructor\n");  
  }  
  
};  
  
class B {  
public :  
  ~B() {  
    printf("B's destructor\n");  
  }  
  
};  
  
void Func() {  
  A a;  
  throw myexception("p is NULL");  
  try{  
    int *p = NULL;  
    if (p == NULL) {  
      //throw myexception("p is NULL");  
    }  
  }  
  catch(myexception e) {  
    printf("%s\n", e.what());  
    throw;  
  }  
  catch (std::exception e) {  
    printf("%s", e.what());  
  }  
  
  B b;  
}  
  
  
void Func2() {  
  Func();  
}  
//****************************************************************************//
//****************************************************************************//
#include <cstdio>  
#include <cstdlib>  
#include <exception>  
#include <string>  
  
class myexception : public std::exception {  
public :  
  myexception(std::string s) : exception(s.c_str()) {  
  
  }  
  virtual ~myexception() {  
    printf("myexception's destructor\n");  
  }  
  virtual const char *what() const {  
    return exception::what();  
  }  
public :  
  std::string _s;  
};  
  
class A {  
public :  
  ~A() {  
    printf("A's destructor\n");  
  }  
  
};  
  
class B {  
public :  
  ~B() {  
    printf("B's destructor\n");  
  }  
  
};  
  
void Func() {  
  A a;  
   printf("dasd\n");  
   myexception e("p is NULL");  
   e._s = "haha";  
  try{  
    int *p = NULL;  
    if (p == NULL) {  
      throw e;  
    }  
  }  
  catch(myexception &e) {  
    e._s = "heiheihei";  
    printf("%s\n", e.what());  
    throw;  
  }  
  
  printf("%s\n", e._s.c_str());  
  
  B b;  
}  
  
void Func2() {  
  try {  
    Func();  
  }  
  catch (myexception &e) {  
    printf("Func2 : %s\n", e._s.c_str());  
    throw;  
  }  
}  
  
int main() {  
  try {  
    Func2();  
  }  
  catch (myexception &e) {  
    printf("main: %s\n", e._s.c_str());  
  }  
  printf ("hahah\n");  
  
  system("PAUSE");  
  return 0;  
}  

