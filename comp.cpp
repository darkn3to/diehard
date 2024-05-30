#include <iostream>
#include <string.h>
using namespace std;
void rem(char *str, int j, int len) {
    for (int i=j; i<len; i++) {
        str[i]=str[i+1];
    }
}
int main() {
    char str[50];
    cout<<"Enter a string: ";
    cin>>str;
    int x=strlen(str);
    for (int i=0; i<x-1; i++) {
        if (str[i]==str[i+1]) {
            rem(str, i+1, x);
            i--;
            x--;
        }
    }
    cout<<"The modified string is: "<<str;
    return 0;
}