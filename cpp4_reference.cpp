#include <iostream>
#include <cstdlib>
using namespace std;

int soma(int &x){     
    x = x + 8;
    cout<<"x = "<<x <<"\n";    
    return x;
}

int main(int argc, char** argv) {
	int n = 30;
	soma(n);
	cout << "n = "<< n << "\n";
return 0;       
}