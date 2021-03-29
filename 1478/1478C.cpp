//# Author : godgiyeon =========================#
//# Problem Title : Nezzar and Symmetric Array #
//# Time Stamp : 2021-03-14T23:15:37 ===========#
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
        vector<ll> v;
        vector<ll> ans;
        map<ll, int> cnt;
        ll tmp;
        for(int i=1; i<=2*n; i++) {
            cin >> tmp; v.push_back(tmp);
            cnt[tmp]++;
        }        
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        //cout << "size: " << v.size() << "\n";
        bool flag = true;
        for(auto it = cnt.begin(); it!=cnt.end(); it++) {
            if(it->second != 2) {
                flag = false;
            }
        }
        if(v.size() != n) {
            flag = false;
        }
        ll sum = 0;
        for(int i=n-1; i>=0; i--) {
            ll div = (ll)(i+1) * 2;
            //cout << v[i] << " " << sum << " " << v[i] - sum << " " << div << " " << (v[i]-sum) % div << "\n";
            if(v[i]-sum < 0) {
                flag = false;
                break;
            }
            if( (v[i]-sum) % div) {
                flag = false;
                break;
            }
            ans.push_back( (v[i]-sum) / div);
            ans.push_back( -(v[i]-sum) / div);
            sum += 2 * ( (v[i]-sum) /div);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        // for(auto val: ans) {
        //     cout << val << " ";
        // }
        // cout << "\n";
        if(ans.size() != 2 *n) {
            flag = false;
        }
        if(flag) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}