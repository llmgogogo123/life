#include <iostream>
using namespace std;

class P {
public:
    string n;
    P(string s) : n(s) { cout << "+" << n; }
    ~P() { cout << "-" << n; }
};

void f(P p) {
    cout << "[" << p.n << "]";
}

int main() {
    P a("a");
    f(a);
    P b("b");
    return 0;
}