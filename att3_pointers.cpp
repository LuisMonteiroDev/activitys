#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	int *pont1;
	int *w = NULL;
	int x = 12, z;
	pont1 = &x;
	cout<<"x = "<<x<<"\n\n";
	cout<<"pont1 = "<<pont1<<"\n\n";
	z = *pont1;
	cout<<"z = "<<z<<" -> "<<&z<<"\n\n";
	cout<<"x = "<<x<<" -> "<<&x<<"\n\n";
	cout<<"w = "<<w<<" -> "<<&w<<"\n\n";	
	return 0;
}