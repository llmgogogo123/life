#include<iostream>
using namespace std;
class Five{
    public:
    int* p;
    Five() : p(new int (0)){
        cout<<"默认构造"<<endl;
    } 
    Five(const Five& o) : p(new int(*o.p)){
        cout<<"拷贝构造"<<endl;
    }
    Five(Five&& o) noexcept : p(o.p){
        o.p=nullptr;
        cout<<"移动构造"<<endl;
    }
    Five& operator=(Five& o) {
        cout<<"拷贝赋值"<<endl;
        if(this != &o){
            delete p;
            p=new int(*o.p);
        }
        return *this;
    }
    Five& operator=(Five&& o) noexcept{
        cout<<"移动赋值"<<endl;
        if(this != &o){
            delete p;
            p=o.p;
            o.p=nullptr;
        }
        return *this;
    }
    ~Five(){
        cout<<"析构"<<endl;
        delete p;
    }
};
int main(){
    Five a;
    Five b=a;
    Five c=std::move(a);
    b=c;
    c=std::move(b);
    return 0;
}