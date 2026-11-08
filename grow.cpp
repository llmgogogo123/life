#include<iostream>
#include<vector>
using namespace std;
class Buf{
    public:
    int* p;
    int n;
    Buf(int size) : p(new int [size]),n(size){
        cout<<"构造("<<n<<")"<<endl;
    }
    Buf(const Buf& o) /*noexcept*/: p(new int [o.n]),n(o.n){
        for(int i=0;i<n;i++) p[i]=o.p[i];
        cout<<"拷贝("<<n<<")"<<endl;
    }
    Buf(Buf&& o)  : p(o.p),n(o.n){
        o.p=nullptr;
        o.n=0;
        cout<<"移动("<<n<<")"<<endl;
    }
    ~Buf(){
        delete [] p;
    }
};
int main(){
    vector<Buf> v;
    /*v.reserve(3);
    v.push_back(Buf(100));
    v.push_back(Buf(100));
    v.push_back(Buf(100));*/
    cout<<"push三个"<<endl;
    v.emplace_back(100);
    v.emplace_back(100);
    v.emplace_back(100);
    cout<<"结束"<<endl;
    return 0;
}