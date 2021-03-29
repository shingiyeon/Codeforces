//# Author : godgiyeon =========================#
//# Problem Title : Yet Another String Game #
//# Time Stamp : 2021-03-11T22:38:32 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        string a; cin >> a;
        string b = "";
        for(int i=0; i<a.size(); i++) {
            if( !(i%2) ) {
                if(a[i] == 'a') b += "b";
                else b += "a";
            }
            else {
                if(a[i] == 'z') b += "y";
                else b += "z";
            }
        }
        cout << b << "\n";
    }
}