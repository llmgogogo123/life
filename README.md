# life

C++ 学习项目：对象模型、RAII、智能指针与工程化实践。

## 目录结构

- `include/` — 公共头文件
- `src/` — 实现
- `tests/` — 单元测试
- `*.cpp`（根目录） — 早期单文件实验

## 构建

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j

## 测试

cd build && ctest --output-on-failure

## 内容

- `mystring` — 手写字符串类，演示三/五法则
- 早期实验：对象生命周期、移动语义、虚函数与虚表、RAII、智能指针
