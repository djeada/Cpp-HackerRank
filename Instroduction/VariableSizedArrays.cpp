#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    cin >> n >> q ;

    vector<int> arr[n];

    int k;
    for(int i = 0; i < n; i++)
    {
        cin >> k; 
        for (int j = 0; j < k; j++)
        {
            int val;
            cin >> val;
            arr[i].push_back(val);
        }
    };

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << arr[x][y] << '\n';
    }

    return 0;
}