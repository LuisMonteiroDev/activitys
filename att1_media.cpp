#include <iostream>

using namespace std;

int main()
{
    float note1, note2, note3, note4, media;
    cout<<"enter your note1: ";
    cin>>note1;
    cout<<"enter your note2: ";
    cin>>note2;
    cout<<"enter your note3: ";
    cin>>note3;
    cout<<"enter your note4: ";
    cin>>note4;
    media = (note1+note2+note3+note4)/4;
    
    
    if (media >= 6.0) {
        cout<<"Approved!";
        cout<<"\nyour average is: "<<media;
    } else {
        cout<<"Disapproved!";
        cout<<"\nyour average is: "<<media;
    }

    return 0;
}