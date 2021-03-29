//# Author : godgiyeon =========================#
//# Problem Title : Equalize the Array =====#
//# Time Stamp : 2021-03-03T10:30:15 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> m;
        vector<int> v;
        int tmp;
        for(int i=1; i<=n; i++) {
            cin >> tmp;
            if(m.find(tmp) == m.end()) {
                m[tmp] = 1;
            }
            else{
                m[tmp]++;
            }
        }
        for(auto it=m.begin(); it!=m.end(); it++) {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end());
        ll sum = 0, ans = 0;
        for(auto val: v) {
            sum += (ll)val;
        }
        ans = sum;
        for(int i=0; i<v.size(); i++) {
            ans = min(ans, sum - (ll)(v.size()-i) * v[i]);
        }
        cout << ans << "\n";

    }
}