//# Author : godgiyeon =========================#
//# Problem Title : Floor and Mod ==========#
//# Time Stamp : 2021-02-13T13:27:42 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int x, y; cin >> x >> y;
        ll ans = 0;
        for(int i=1; i<=(int)sqrt(x); i++) {
            ans += max( min( (x/i)-1, y) - i , 0);
        }
        cout << ans << endl;
    }
}