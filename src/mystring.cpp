#include "mystring.h"
#include <cstring>

MyString::MyString() : data(new char[1]), len(0) {
    data[0] = '\0';
}

MyString::MyString(const char* s) {
    // TODO: 算长度、分配、拷贝
    len=std::strlen(s);
    data=new char[len+1];
    std::strcpy(data,s);
}

MyString::MyString(const MyString& o) {
    // TODO: 深拷贝
    len=o.len;
    data=new char[len+1];
    std::strcpy(data,o.data);
}

MyString::MyString(MyString&& o) noexcept {
    // TODO: 偷指针 + 置空
    len=o.len;
    o.len=0;
    data=o.data;
    o.data=nullptr;
}

MyString& MyString::operator=(const MyString& o) {
    // TODO: 自赋值检查 → 释放旧 → 新分配 → 拷贝
    if(this!=&o){
        delete[] data;
        len=o.len;
        data=new char[len+1];
        std::strcpy(data,o.data);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& o) noexcept {
    // TODO: 自赋值检查 → 释放旧 → 接指针 → 置空
    if(this!=&o){
        delete[] data;
        len=o.len;
        data=o.data;
        o.data=nullptr;
        o.len=0;
    }
    return *this;
}

MyString::~MyString() {
    delete[] data;
}

std::size_t MyString::size() const {
    return len;
}

const char* MyString::c_str() const {
    return data;
}