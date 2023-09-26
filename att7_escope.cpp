#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** agrv) {
    int x;
    x = 10;
    if (x > 0) {
        int x = 20;
        std::cout<<"Value of x in scope "<<x;
    }
    std::cout<<"\nValue of x out of scope "<<x;


    return 0;
}