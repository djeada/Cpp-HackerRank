#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int foo [3];
    int sum = 0;
    for(int i = 0; i < 3; i++){
        cin >> foo[i];
        sum += foo[i];
    }
    cout << sum << endl;
    return 0;
}
