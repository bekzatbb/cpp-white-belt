
#include <iostream>

#include <fstream>

#include <iomanip>

#include <map>

#include <vector>

#include <algorithm>

using namespace std;

int main() {
    ifstream input ("input.txt");
    int n;
    int m;
    input >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            input >> x;
            input.ignore(1);
            if (j != m - 1) {
                cout << setw(10) << x << " ";
            }
            else {
                cout << setw(10) << x;
            }
        }
        if (i != n - 1) {
            cout << endl;
        }
    }
    return 0;
}
