#include<iostream>
using namespace std;
template<typename T> 
class MySharedPtr{
    T* ptr;
    int* count;
    public:
    explicit MySharedPtr(T* p=nullptr) : ptr(p),count(new int(1)) {};
    ~MySharedPtr(){
        (*count)--;
        if(*count==0){
            delete ptr;
            delete count;
        }
    }
    MySharedPtr(const MySharedPtr& o){
        ptr=o.ptr;
        count=o.count;
        (*count)++;
    }
    int use_count() const {return *count;}
    T& get  () const {return *ptr;}
    T& operator*(){return *ptr;}
    T* operator->(){return ptr;}
    MySharedPtr& operator=(const MySharedPtr& o){
        if(this!=&o){
            (*count)--;
            if((*count)==0){
                delete ptr;
                delete count;
            }
            ptr=o.ptr;
            count=o.count;
            (*count)++;
        }
        return *this;
    }
};
struct Node{
    int v;
    Node(int x) : v(x){
        cout<<"构造"<<endl;
    }
    ~Node(){
        cout<<"销毁"<<endl;
    }
};
int main(){
    {
    MySharedPtr<Node> a(new Node(1));
    cout<<"a:"<<a.use_count()<<endl;
    MySharedPtr<Node> b=a;
    cout<<"a:"<<a.use_count()<<endl;
    cout<<"b:"<<b.use_count()<<endl;
    {
        MySharedPtr<Node> c=b;
        cout<<"c:"<<c.use_count()<<endl;
    }
    cout<<"b:"<<b.use_count()<<endl;
    }
     MySharedPtr<Node> a(new Node(1));
      MySharedPtr<Node> b(new Node(1));
        a=b;
    cout<<"a:"<<a.use_count()<<endl;
    cout<<"b:"<<b.use_count()<<endl;    
    return 0;
}