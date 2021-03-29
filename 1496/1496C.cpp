//# Author : godgiyeon =========================#
//# Problem Title : Diamond Miner ==========#
//# Time Stamp : 2021-03-12T22:50:09 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        long double ans = 0;
        ll x, y;
        vector<ll> X, Y;
        int n; scanf("%d", &n);
        n = n + n;
        while(n--) {
            scanf("%lld%lld", &x, &y);
            if(x < 0) x = -x;
            if(y < 0) y = -y;
            if(x == 0) {
                Y.push_back(y);
            }
            if(y == 0) {
                X.push_back(x);
            }
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        for(int i=0; i<X.size(); i++) {
            long long tmpX = X[i] * X[i];
            long long tmpY = Y[i] * Y[i];
            ans += sqrtl((long double)tmpX + tmpY);
        }
        printf("%.20Lf\n", ans);
    }
}