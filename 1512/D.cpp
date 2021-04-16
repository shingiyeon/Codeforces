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
void solve() {
    vector<ll> v;
    int n; cin >> n;
    for(int i=1; i<=n+2; i++) {
        ll num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for(int i=0; i<n; i++) {
        sum += v[i];
    }
    if(sum == v[n]) {
        for(int i=0; i<n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    sum += v[n];
    for(int i=0; i<=n; i++) {
        if(sum - v[i] == v[n+1]) {
            for(int j=0; j<=n; j++) {
                if(j == i) continue;
                cout << v[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}