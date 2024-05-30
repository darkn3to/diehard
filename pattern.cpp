#include <iostream>
using namespace std;
int main() {
    int a=100;
    float d=*(float *)a;
    printf("%f", d);
    return 0;
}