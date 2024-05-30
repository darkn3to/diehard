#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char str[50];
    cout<<"Enter a string: ";
    cin>>str;
    int a[26]={0};
    for (int i=0; i<strlen(str); i++) ++a[str[i]-'a'];
    for (int i=0; i<strlen(str); i++) {
        if (a[str[i]-'a']) {
            printf("%c", str[i]);
            a[str[i]-'a']=0;
        }
    }
    return 0;
}