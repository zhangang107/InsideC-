#include <iostream>

using namespace std;

class X {};
class Y:public virtual X {};
class Z:public virtual X {};
class A:public Y, public Z {};

int main(int argc, char const *argv[]) {
    cout<<"sizeof X\t"<<sizeof(X)<<endl;
    cout<<"sizeof Y\t"<<sizeof(Y)<<endl;
    cout<<"sizeof Z\t"<<sizeof(Z)<<endl;
    cout<<"sizeof A\t"<<sizeof(A)<<endl;
    return 0;
}
