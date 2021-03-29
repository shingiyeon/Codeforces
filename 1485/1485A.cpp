//# Author : godgiyeon =========================#
//# Problem Title : Add and Divide =========#
//# Time Stamp : 2021-02-13T23:30:44 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int calc(int a, int b) {
    int num = 0;
    while(a) {
        a /= b;
        num++;
    }
    return num;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int ans = 0;
        int n = 0;
        int a, b; cin >> a >> b;
        if(b == 1) {
            n++; b++;
        }
        ans = calc(a, b) + n;
        for(int i=b+1; i<=ans; i++) {
            n++;
            ans = min( calc(a, i) + n, ans);
        }
        cout << ans << "\n";
    }
}