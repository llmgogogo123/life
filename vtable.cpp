#include<iostream>
using namespace std;
class Base{
    public:
    virtual ~Base(){
        cout<<"~Base"<<endl;
    }
};
class Dirived : public Base{
    public:
    int* Big=new int [100];
    ~Dirived(){
        cout<<"~Dirived"<<endl;
        delete [] Big;
    }
};
int main(){
    Base* p=new Dirived();
    delete p;
    return 0;
}
