#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string str1, str2, str3;
    int n1, n2;
    char tmp;

    cin >> str1 >> str2;

    n1 = str1.size();
    n2 = str2.size();

    str3 = str1 + str2;

    tmp = str3[0];
    str3[0] = str3[n1];
    str3[n1] = tmp;

    cout << n1 << " " << n2 << endl;

    cout << str1 + str2 << endl;

    for(int i = 0; i < n1;i++){
        cout << str3[i];
    }
    cout << " ";
    
    for(int i = n1; i < str3.size(); i++){
        cout << str3[i];
    }
    cout << endl;
    
    return 0;
}