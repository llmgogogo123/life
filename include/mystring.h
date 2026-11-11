#pragma once
#include <cstddef>      // size_t

class MyString {
public:
    MyString();                                  // 默认构造
    MyString(const char* s);                     // 从 C 字符串
    MyString(const MyString& o);                 // 拷贝构造
    MyString(MyString&& o) noexcept;             // 移动构造
    MyString& operator=(const MyString& o);      // 拷贝赋值
    MyString& operator=(MyString&& o) noexcept;  // 移动赋值
    ~MyString();

    std::size_t size() const;
    const char* c_str() const;

private:
    char* data;
    std::size_t len;
};