//# Author : godgiyeon =========================#
//# Problem Title : K-divisible Sum ========#
//# Time Stamp : 2021-02-25T13:09:24 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;
int upper(int a, int b) {
    return (a / b) + (a % b != 0);
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t, a, b; cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << upper(upper(a, b) * b, a) << "\n";
    }
}