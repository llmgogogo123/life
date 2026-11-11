#include<iostream>
#include<memory>
using namespace std;
struct Child;

struct Parent{
    shared_ptr<Child> child;
    ~Parent(){
        cout<<"父 销毁"<<endl;
    }
};
struct Child{
    //shared_ptr<Parent> parent;
    weak_ptr<Parent> parent;
    ~Child(){
        cout<<"子 销毁"<<endl;
    }
};
int main(){
    auto p=make_shared<Parent>();
    auto c=make_shared<Child>();
    p->child=c;
    c->parent=p;
    cout<<"父的计数："<<p.use_count()<<endl;
    cout<<"子的计数："<<c.use_count()<<endl;
    cout<<"结束"<<endl;
    return 0;
}