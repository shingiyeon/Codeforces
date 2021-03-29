//# Author : godgiyeon =========================#
//# Problem Title : Dogeforces =============#
//# Time Stamp : 2021-03-09T14:38:30 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int arr[501][501];
int p[1001];
int val[1001];
int dp[1001];
int parent(int cur) {
    if(p[cur] == cur) return cur;
    return p[cur] = parent(p[cur]);
}

void merge(int a, int b, int idx, int c) {
    int pA = parent(a);
    int pB = parent(b);
    dp[pA] = idx;
    dp[pB] = idx;
    p[pA] = idx;
    p[pB] = idx;
    val[idx] = c;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    vector< pair<int, pair<int, int> > > v;
    int n; cin >> n;
    for(int i=1; i<=2*n-1; i++) {
        p[i] = i;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        val[i] = arr[i][i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(i == j) continue;
            v.push_back( {arr[i][j], {i, j}});
        }
    }
    sort(v.begin(), v.end());

    int idx = n+1;
    for(auto info: v) {
        int tmp_val = info.first; int a = info.second.first; int b = info.second.second;
        //cout << a << " " << b << " " << parent(a) << " " << parent(b) << " " << val[parent(a)] << " " << val[parent(b)] << "\n";
        if(parent(a) == parent(b)) continue;
        if(tmp_val > val[parent(a)] && tmp_val > val[parent(b)]) {
            merge(a, b, idx, tmp_val);
            idx++;
        }
        else if(tmp_val == val[parent(a)]) {
            dp[parent(b)] = parent(a);
            p[parent(b)] = parent(a);
        }

        else if(tmp_val == val[parent(b)]) {
            dp[parent(a)] = parent(b);
            p[parent(a)] = parent(b);
        }
    }
    cout << idx -1 << "\n";
    for(int i=1; i<idx; i++) {
        cout << val[i] << " ";
    }
    cout << "\n";
    cout << parent(1) << "\n";
    for(int i=1; i<idx; i++) {
        if(i == parent(1)) continue;
        cout << i << " " << dp[i] << "\n";
    }
    
}