//# Author : godgiyeon =========================#
//# Problem Title : Wizard of Orz ==========#
//# Time Stamp : 2021-01-19T22:23:00 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>

using namespace std;

int t;
string str = "8901234567";
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << "9";
        for(int i=0; i< (n-1)/10; i++) {
            cout << str;
        }
        for (int i = 0; i < (n-1)%10; i++) {
            cout << str[i];
        }
        cout << "\n";
    }
}