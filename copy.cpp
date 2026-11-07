#include<iostream>
using namespace std;
class Tracked{
    public:
    int id;
    Tracked(int i) : id(i){
        cout<<"构造"<<id<<endl;
    }
    Tracked(const Tracked &other) : id(other.id){
        cout<<"拷贝"<<id<<endl;
    }
    ~Tracked(){
        cout<<"析构"<<id<<endl;
    }
};
    void takeByValue(Tracked t){
        cout<<"[值传递] id ="<<t.id<<endl;
    }
    void takeByRef(const Tracked &t){
        cout<<"[引用] id ="<<t.id<<endl;
    }

int main(){
    Tracked a(1);
    cout<<"..按值传递"<<endl;
    takeByValue(Tracked(99));
    cout<<"..引用传递"<<endl;
    takeByRef(a);
    cout<<"..main结束"<<endl;
    return 0;
}