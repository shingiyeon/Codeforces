//# Author : godgiyeon =========================#
//# Problem Title : Old Floppy Drive  ======#
//# Time Stamp : 2021-03-04T09:40:16 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long ll;
using namespace std;

int a[200005], x[200005];
ll sum[200005];
ll r_sum[200005];
ll min_v[200005];

vector<pair<ll, int> > v;

ll BS(int left, int right, ll max_v, ll end_v, int ref) {
    if(left > right) {
        return left;
    }
    int mid = (left + right) / 2;
    if(end_v * mid + max_v >= (ll)ref) {
        return BS(left, mid-1, max_v, end_v, ref);
    }
    return BS(mid+1, right, max_v, end_v, ref);
}

ll LB(int left, int right, ll val) {
    if(left > right) {
        return left;
    }
    int mid = (left+right) / 2;
    if(v[mid].first >= val) {
        return LB(left, mid-1, val);
    }
    return LB(mid+1, right, val);
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        v.clear();
        int n, m; cin >> n >> m;
        ll max_v = -200000000000000LL;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(i==0) {
                sum[i] = a[i];
            }
            else sum[i] = sum[i-1] + a[i];
            max_v = max(max_v, sum[i]);
        }
        for(int i=0; i<n; i++) {
            v.push_back( {sum[i], i});
        }
        sort(v.begin(), v.end());
        min_v[v.size()-1] = (ll)v[v.size()-1].second;
        for(int i=v.size()-2; i>=0; i--) {
            min_v[i] = min(min_v[i+1], (ll)v[i].second);
        }
        for(int i=0; i<m; i++) {
            cin >> x[i];
        }
        for(int i=0; i<m; i++) {
            int end;
            if(sum[n-1] == 0) end = (int)x[i];
            else end = max(0, (int)(x[i] / sum[n-1]) + 1);
            ll tmp_x = BS(0, end , max_v, sum[n-1], x[i]);
            if(tmp_x > (ll)end) {
                cout << "-1" << " ";
            }
            else {
                ll tmp_v = x[i] - (sum[n-1] * tmp_x);
                ll idx = LB(0, v.size()-1, tmp_v);
                cout << v.size() * tmp_x + min_v[idx] << " ";
            }
        }
        cout << "\n";




    }
}