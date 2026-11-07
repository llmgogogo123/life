#include<iostream>
using namespace std;
class Probe{
    public:
    string name;
    Probe(const string& n) : name(n){
        cout<<"构造"<<name<<endl;
    }
    ~Probe(){
        cout<<"析构"<<name<<endl;
    }
};
class Owner{
    public:
    Probe inner;
    Owner() : inner("成员") {
        cout<<"构造Owner本体"<<endl;
    }
    ~ Owner(){
        cout<<"析构Owner本体"<<endl;
    }
};
int main(){
    cout<<"....main开始"<<endl;
    Probe a("a");
    {
        Probe b("b");
        Probe c("c");
        cout<<"...内层作用域结束"<<endl;
    }
    cout<<"....main结束"<<endl;
    Owner o;
    return 0;
}