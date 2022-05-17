#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main() {
    ifstream input("input.txt");
    string line;
    ofstream output("output.txt", ios::app);
    while (getline(input, line)) {
        cout << line << "\n"; 
    }
    return 0;
}