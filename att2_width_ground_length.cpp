#include <iostream>

using namespace std;

int main()
{
    float c, l, a, p;
    int qe, qaf, qf;
    qe = 0;
    qf = 8;
    qaf = 0;
    
    cout<<"Digite o comprimento: ";
    cin>>c;
    
    cout<<"Digite a largura: ";
    cin>>l;
    
    a=c*l;
    
    p = c+l+c+l;    
    qe = (p/2)+1;
    qaf = qf*p;
    
    cout<<"Perimetro: "<<p;
    cout<<"\nQFA: "<<qaf;
    cout<<"\nÁrea = "<< a;

    return 0;
}
