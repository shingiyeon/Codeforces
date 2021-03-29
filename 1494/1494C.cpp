//# Author : godgiyeon =========================#
//# Problem Title : 1D Sokoban =============#
//# Time Stamp : 2021-03-05T15:36:17 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> am, vector<int> bm) {
    int max_val = 0;
    int sum[200002];
    for(int i=0; i<200002; i++) sum[i] = 0;
    for(int i=0; i<am.size(); i++) {
        if(binary_search(bm.begin(), bm.end(), am[i])) {
            sum[i]++;
        }
        if(i>0) sum[i] += sum[i-1];
    }
    for(int i=0; i<bm.size(); i++) {
        int val = bm[i];
        int idx = lower_bound(am.begin(), am.end(), val) - am.begin();
        int num = am.size() - idx;
        int tmp = 0;
        if(idx > 0) tmp += sum[idx-1];
        if(num > 0) {
            int cidx = lower_bound(bm.begin(), bm.end(), val + num) - bm.begin() - 1;
            tmp += cidx - i + 1;
        }
        max_val = max(max_val, tmp);
    }
    return max_val;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> am, ap, bm, bp;
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            if(tmp > 0) ap.push_back(tmp);
            else am.push_back(tmp);
        }
        for(int i=0; i<m; i++) {
            int tmp; cin >> tmp;
            if(tmp > 0) bp.push_back(tmp);
            else bm.push_back(tmp);
        }
        int ans = 0;
        ans = solve(am, bm);
        vector<int> tam, tbm;
        for(int i=ap.size()-1; i>=0; i--) {
            tam.push_back(-ap[i]);
        }
        for(int i=bp.size()-1; i>=0; i--) {
            tbm.push_back(-bp[i]);
        }
        ans += solve(tam, tbm);
        cout << ans << "\n";
    }
}