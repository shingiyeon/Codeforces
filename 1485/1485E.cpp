//# Author : godgiyeon =========================#
//# Problem Title : Move and Swap ==========#
//# Time Stamp : 2021-02-16T10:44:14 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

vector<int> adj[200005];
vector<int> depth_idx[200005];
ll arr[200005], dy[200005];
ll depth_min[200005], depth_max[200005];
int p[200005];
int depth[200005];

void bfs(int start) {
    queue<pair<int, int> > q;
    q.push({start, 1});
    depth[start] = 1;
    depth_idx[1].push_back(1);
    while(!q.empty()) {
        auto info = q.front(); q.pop();
        int cur = info.first; int lv = info.second;
        for(auto next: adj[cur]) {
            if(depth[next]) continue;
            p[next] = cur;
            depth[next] = lv + 1;
            depth_idx[lv+1].push_back(next);
            q.push({next, lv+1});
        }
    }
    return;
}

void calc_min_max(int n) {
    for(int i=1; depth_idx[i].size() > 0; i++) {
        for(auto node: depth_idx[i]) {
            depth_min[i] = min(depth_min[i], arr[node]);
            depth_max[i] = max(depth_max[i], arr[node]);
        }
    }
    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >>t ;
    while(t--) {
        int n; cin >> n;
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            depth_idx[i].clear();
            adj[i].clear();
            p[i] = i; depth[i] = 0;
            depth_min[i] = 1000000001;
            depth_max[i] = -1;
            dy[i] = -1;
        }
        for(int i=2; i<=n; i++) {
            cin >> p[i];
            adj[p[i]].push_back(i);
        }
        for(int i=2; i<=n; i++) {
            cin >> arr[i];
        }
        bfs(1);
        calc_min_max(n);
        dy[1] = 0;
        for(int i=2; depth_idx[i].size() > 0; i++) {
            ll candi1, candi2;
            candi1 = candi2 = -1000000001;
            for(auto node: depth_idx[i]) {
                dy[node] = max(dy[node], dy[p[node]] + max(abs(arr[node] - depth_max[i]), abs(arr[node] - depth_min[i])));
                candi1 = max(candi1, dy[p[node]] + arr[node]);
                candi2 = max(candi2, dy[p[node]] - arr[node]);
            }
            for(auto node: depth_idx[i]) {
                dy[node] = max(dy[node], candi1 - arr[node]);
                dy[node] = max(dy[node], candi2 + arr[node]);
            }
        }

        for(int i=1; i<=n; i++) ans = max(ans, dy[i]);

        cout << ans << "\n";

    }
}