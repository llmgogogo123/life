#include<iostream>
using namespace std;
class A{};
class B{int x;};
class C{int x;virtual void f(){}};
class D : public C{int y;};
int main(){
    cout<<"A:"<<sizeof(A)<<endl;
     cout<<"B:"<<sizeof(B)<<endl;
      cout<<"C:"<<sizeof(C)<<endl;
       cout<<"D:"<<sizeof(D)<<endl;
}