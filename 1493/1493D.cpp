//# Author : godgiyeon =========================#
//# Problem Title : GCD of an Array ========#
//# Time Stamp : 2021-03-07T23:57:28 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <map>
#include <set>
#define MOD 1000000007LL
typedef long long ll;
using namespace std;

int n, q;
multiset<int> ms[200005];
map<int, int> m[200005];
map<int, int> s;
int spf[200005], pr[200005];
int pn = 0;

ll pow(ll x, int a) {
    ll ans = 1;
    while(a >= 1) {
        if(a % 2) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        a /= 2;
    }
    return ans;
}
ll calc_gcd(ll a, ll b) {
    while(a % b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}
ll get_gcd(int idx, int val, ll gcd, int sz) {
    map<int, int> tm;
    while(val > 1) {
        tm[spf[val]]++;
        val /= spf[val];
    }

    for(auto it=tm.begin(); it!=tm.end(); it++) {
        int num = it->first; int val = it->second;
        if(m[idx][num] != 0){
            auto it = ms[num].find(m[idx][num]);
            int ms_val = *it;
            ms[num].erase(it);
            ms[num].insert(ms_val + val);
        }
        else {
            ms[num].insert(val);
        }
        m[idx][num] += val;
        if(ms[num].size() == sz) {
            int min_val = *ms[num].begin();
            gcd = ( gcd * pow(num , min_val - s[num] ) ) % MOD;
            s[num] = min_val;
        }
        else {
            s[num] = 0;
        }
    }
    return gcd;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    
    for(int i=2; i<=200000; i++) {
        if(!spf[i]) spf[i] = pr[pn++] = i;
        for(int j=0; i*pr[j] <= 200000; j++) {
            spf[i * pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
        
    }
    cin >> n >> q;
    vector<ll> tmp;
    for(int i=1; i<=n; i++) {
        int val; cin >> val;
        tmp.push_back(val);
        ll tmp = get_gcd(i, val, 1, n);
    }
    ll gcd = tmp[0];
    for(int i=1; i<tmp.size(); i++) {
        gcd = calc_gcd(gcd, tmp[i]);
    }
    for(int i=1; i<=q; i++) {
        int idx, val; cin >> idx >> val;
        gcd = get_gcd(idx, val, gcd, n);
        cout << gcd << "\n";
    }
}