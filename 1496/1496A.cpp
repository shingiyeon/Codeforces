//# Author : godgiyeon =========================#
//# Problem Title : Split it! ==============#
//# Time Stamp : 2021-03-12T22:11:30 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        if( n < 2 * k + 1) {
            cout << "NO" << "\n";
            continue;
        }
        bool flag = true;
        for(int i=0; i<k; i++) {
            if(str[i] != str[str.size()-1-i]) {
                flag = false;
            }
        }

        if(flag) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

    }
}