//# Author : godgiyeon =========================#
//# Problem Title : Road Reform ============#
//# Time Stamp : 2021-03-11T22:30:01 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
typedef long long ll;
using namespace std;

int p[200005];
int sz[200005];
int parent(int cur) {
    if(p[cur] == cur) return cur;
    return p[cur] = parent(p[cur]);
}

void merge(int a, int b) {
    int pA = parent(a); int pB = parent(b);
    if(pA == pB) return;
    if(sz[pA] > sz[pB]) swap(pA, pB);
    p[pA] = pB;
    sz[pB] += sz[pA];
}

vector< pair< pair<ll, int>, pair<int, int> > > edges;

ll find(int n, ll k) {
    ll ans = 20000000000000LL;
    ll sum = 0;
    ll max_val = 0;
    int connected = 0;

    for(auto &edge: edges) {
        ll c = edge.first.first;
        int &v = edge.first.second;
        int x = edge.second.first;
        int y = edge.second.second;
        if(parent(x) != parent(y)) {
            v = true;
            max_val = max(max_val, c);
            merge(x, y);
            if(c >= k) {
                sum += (c - k);
            }
            connected++;
        }
        if (connected == n-1) break;
    }

    if(max_val >= k) {
        return sum;
    }
    ans = min(ans, k - max_val);

    connected = 0;
    for(auto edge: edges) {
        ll c = edge.first.first;
        int v = edge.first.second;
        int x = edge.second.first;
        int y = edge.second.second;
        if(v) connected++;
        if(connected == n-1) {
            if(c >= k) {
                ans = min(ans, c-k);
            }
            else {
                ans = min(ans, k-c);
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, m; ll k; cin >> n >> m >> k;
        for(int i=1; i<=n; i++) {
            p[i] = i; sz[i] = 1;
        }
        edges.clear();
        for(int i=1; i<=m; i++) {
            int a, b; ll c; cin >> a >> b >> c;
            edges.push_back({ {c, false}, {a, b}});
        }
        sort(edges.begin(), edges.end());
        cout << find(n, k) << "\n";
    }
}