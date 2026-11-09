#include<iostream>
using namespace std;
template <typename T>
class MyUniquePtr{
    T* ptr;
    public:
    explicit MyUniquePtr(T* p=nullptr) : ptr(p) {};
    ~MyUniquePtr(){
        delete ptr;
        cout<<"释放"<<endl;
    }
    MyUniquePtr(const MyUniquePtr& o)=delete;
    MyUniquePtr& operator=(const MyUniquePtr& o)=delete;
    MyUniquePtr(MyUniquePtr&& o) noexcept : ptr(o.ptr){
        o.ptr=nullptr;
    }
    MyUniquePtr& operator=(MyUniquePtr&& o) noexcept {
        if(this!=&o){
            delete ptr;
            ptr=o.ptr;
            o.ptr=nullptr;
        }
        return *this;
    }
    T& operator*() const {return *ptr;};
    T* operator->() const {return ptr;};
    T* get() const {return ptr;};
};
int main(){
    MyUniquePtr<int> a(new int(5));
    cout<<*a<<endl;
    MyUniquePtr<int> b=std::move(a);
    cout<<*b<<endl;
    cout<<(a.get()==nullptr)<<endl;
   // MyUniquePtr<int> c=a;
    return 0;
}