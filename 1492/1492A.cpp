//# Author : godgiyeon =========================#
//# Problem Title : Three swimmers =========#
//# Time Stamp : 2021-02-23T18:20:29 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#define MAX 1000000000000000000LL
typedef long long ll;

using namespace std;


ll upper(ll p, ll k) {
    ll start = 0;
     ll end = (MAX / k) + 1;
    ll mid = (start + end) / 2;

    while(start <= end) {
        if(p <= (mid * k)) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return start;
}

int main() {
    cin.tie(NULL); //cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        ll p, a, b, c; cin >> p >> a >> b >> c;
        ll ans = MAX;
        ans = min(ans , a * upper(p, a) - p);
        ans = min(ans , b * upper(p, b) - p);
        ans = min(ans , c * upper(p, c) - p);
        cout << ans << "\n";
    }
}