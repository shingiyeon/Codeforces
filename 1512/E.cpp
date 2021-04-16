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
void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    vector<int> v(n+1, 0);
    vector<bool> visited(n+1, false);
    int diff = (r - l);
    int sum = (2*n - diff) * (diff + 1) / 2;
    if(s > sum) {
        cout << "-1\n";
        return;
    }
    int num = (r - l + 1);
    for(int i=n; i>=1; i--) {
        if(num == 0) break;
        int tmp = (num) * (num-1) / 2;
        if(i < num) {
            cout << "-1\n";
            return;
        }
        if(tmp + i <= s) {
            v[r - num + 1] = i;
            s -= i;
            visited[i] = true;
            num--;
        }
    }

    int idx = 1;
    for(int i=1; i<=n; i++) {
        while(visited[idx] == true) idx++;
        if(v[i] == 0) {
            v[i] = idx;
            visited[idx] = true;
        }
    }
    for(int i=1; i<=n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
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
