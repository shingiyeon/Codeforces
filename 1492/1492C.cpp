//# Author : godgiyeon =========================#
//# Problem Title : Maximum width ==========#
//# Time Stamp : 2021-02-23T18:45:13 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
using namespace std;

int pos[200001][2];

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int idx = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == b[idx]) {
            pos[idx][0] = i;
            idx++;
        }
        if(idx >= m) break;
    }
    idx = m-1;
    for(int i=n-1; i>=0; i--) {
        if(a[i] == b[idx]) {
            pos[idx][1] = i;
            idx--;
        }
        if(idx < 0) break;
    }
    int ans = 0;
    for(int i=0; i<m-1; i++) {
        ans = max(ans, pos[i+1][1] - pos[i][0]);
    }
    cout << ans;
}