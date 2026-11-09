#include<iostream>
#include<chrono>
#include<string>
using namespace std;
class ScopedTimer{
    string name;
        chrono::steady_clock::time_point start;
        public:
      explicit ScopedTimer(string n) : name(move(n)), start(chrono::steady_clock::now()) {
    }
    ~ScopedTimer(){
      auto now=chrono::steady_clock::now() ;
      auto ms = chrono::duration<double, milli>(now - start).count();
      cout << name << ": " << ms << " ms" << endl;
    }
    ScopedTimer(const ScopedTimer& o)=delete;
    ScopedTimer& operator=(const ScopedTimer&o)=delete;
};

int main(){
       {
        ScopedTimer t("空转");
    }

    {
        ScopedTimer t("循环");
        volatile long long sum = 0;
        for (int i = 0; i < 100000000; i++) sum += i;
    }
  return 0;
}