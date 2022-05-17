#include <iostream>
#include <cmath>
using namespace std;

int Factorial(int n){
    unsigned long factorial;
    factorial = 1;
    if (n<0){
        return 1;
    }
    // Processing
    for (int i = 1; i < n + 1; i++)
    {
        factorial *= i;
    }
    return factorial;
}
