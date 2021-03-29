//# Author : godgiyeon =========================#
//# Problem Title : Full Turn ==============#
//# Time Stamp : 2020-12-26T00:12:13 ===========#
//# Language : GNU C++17 =======================#

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int t;

int gcd(int a, int b) {
    int c;
    while(b>0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int a, b, c, d, vx, vy;
int main() {
    scanf("%d", &t);
    while(t--) {
        vector<pair<int, int> > v;
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            vx = c - a; vy = d - b;
            if(vx == 0 && vy > 0) v.push_back({0, 1});
            else if(vx == 0 && vy < 0) v.push_back({0, -1});
            else if(vy == 0 && vx > 0) v.push_back({1, 0});
            else if(vy == 0 && vx < 0 ) v.push_back({-1, 0 });
            else {
                int pvx = vx > 0 ? 1: -1;
                int pvy = vy > 0 ? 1: -1;
                int gd = gcd(pvx*vx, pvy*vy);
                v.push_back({vx/gd, vy/gd});
            }
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for(auto val: v) {
            auto lo_it = lower_bound(v.begin(), v.end(), pair<int, int> (-val.first, -val.second), comp) - v.begin();
            auto up_it = upper_bound(v.begin(), v.end(), pair<int, int> (-val.first, -val.second), comp) - v.begin();
            ans += (long long)up_it - lo_it;
        }
        printf("%lld\n", ans / 2);
    }
}