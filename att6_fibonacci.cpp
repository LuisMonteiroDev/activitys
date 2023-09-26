#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long fibonacci(long number)
{
    if((number == 0) or (number == 1))
        return number;
    else
        return fibonacci(number - 1) + fibonacci(number - 2);
}

int main() {
    std::cout<<"Inform the value: ";
    int valor = 0;
    std::cin>>valor;
    cout<<"Fibonacci of value "<<valor<<" = "<< fibonacci(valor) << endl;

    return 0;
}