#include<iostream>
using namespace std;
struct VTable{
    void (*speak)(void*);
};
struct Animal{
    VTable* vt;
};
void dogspeak(void*){cout<<"汪汪"<<endl;}
void catspeak(void*){cout<<"喵喵"<<endl;}
int main(){
    VTable dogVT={dogspeak};
    VTable catVT={catspeak};
    Animal a1,a2;
    a1.vt=&dogVT;
    a2.vt=&catVT;
    a1.vt->speak(&a1);
    a2.vt->speak(&a2);
    
}