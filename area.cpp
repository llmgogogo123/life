#include<iostream>
#include<vector>
#include<memory>
using namespace std;
class Shape{
    public:
    virtual double area() const =0;
    virtual~Shape(){
        cout<<"~Shape"<<endl;
    }
};
class Circle : public Shape{
    double r;
    public:
    Circle(double r_) : r(r_) {}
    double area() const override{
        return 3.1415926*r*r;
    }
};
class Rect : public Shape{
    double w,h;
    public:
    Rect(double w_,double h_) : w(w_),h(h_) {}
    double area() const override {
        return w*h;
    }
};
int main(){
    double total=0;
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(2));
    shapes.push_back(make_unique<Rect>(3,4));
    for(const auto & s :shapes){
        double a=s->area();
        cout<<a<<endl;
        total+=a;

    }
    cout<<"总面积:"<<total<<endl;
}