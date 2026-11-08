# life

C++ 对象生命周期实验：构造、析构、拷贝与作用域。

## 文件

- order.cpp — 构造/析构顺序，以及成员对象的生灭
- copy.cpp — 按值传递与按引用传递的代价对比
- guess.cpp — 输出顺序预测练习

## 编译运行

g++ -std=c++17 -Wall order.cpp -o a.out && ./a.out
