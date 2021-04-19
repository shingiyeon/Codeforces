#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;

ll upper(ll a, ll b) {
    if(a % b == 0) {
        return a / b;
    }
    else {
        return (a/b) + 1;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        ll n, c; cin >> n >> c;
        vector<ll> a, b;
        for(int i=0; i<n; i++) {
            ll tmp; cin >> tmp;
            a.push_back(tmp);
        }
        for(int i=0; i<n-1; i++) {
            ll tmp; cin >> tmp;
            b.push_back(tmp);
        }   

        ll rest = 0;
        ll day = 0;
        ll ans = 9876543210LL;
        for(ll i=0; i<n; i++) {
            ans = min(ans, day + max(0LL, c - rest + a[i] - 1) / a[i] );
           // cout << ans << "\n";
            if(i == n-1) break;
            ll tmp_day = max(0LL, b[i] - rest + a[i] - 1) / a[i];
           // cout << "td: " << tmp_day << "\n";
            rest += (tmp_day * a[i]) - b[i];
           // cout << "rest: " << rest << "\n";
            day += tmp_day + 1;
        }
        cout << ans << "\n";

    }
}