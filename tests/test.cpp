#include<iostream>
#include<string>
#include"mystring.h"
using namespace std;
int pass=0,fail=0;
#define CHECK(cond)\
    do{\
        if(cond) pass++;\
        else{\
            fail++;\
            cout<<"失败"<<__FILE__<<fail<<__LINE__<<' '<<#cond<<endl;\
        }\
    }while(0)
int main(){
    MyString a("hello");
    CHECK(a.size()==5);
    CHECK(string(a.c_str())=="hello");
    MyString b=a;
    CHECK(b.size()==5);
    CHECK(a.c_str()!=b.c_str());
    MyString c=std::move(a);
    CHECK(c.size()==5);
    CHECK(a.size()==0);
    MyString d("world");
    d=b;
    CHECK(string(d.c_str())=="hello");
    d=std::move(c);
    CHECK(d.size()==5);
    CHECK(c.size()==0);
    cout<<"通过:"<<pass<<' '<<"失败"<<fail<<endl;
    return fail==0 ? 0:1;
}