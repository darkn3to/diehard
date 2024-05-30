#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cout<<"Enter the three numbers: "<<endl;
    cin>>a>>b>>c;
    if (a>=b && a>=c) cout<<a<<" is greatest number."<<endl;
    else if (b>=a && b>=c) cout<<b<<" is greatest number."<<endl;
    else cout<<c<<" is greatest number."<<endl;
}