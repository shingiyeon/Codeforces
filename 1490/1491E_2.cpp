//# Author : godgiyeon =========================#
//# Problem Title : Fib-tree ===============#
//# Time Stamp : 2021-03-09T13:45:43 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <tuple>
using namespace std;
 
int n;
vector<int> fibo;
vector<pair<int, int> > adj[200005];
int sz[200005];
int make_fibo() {
    int a = 1, b = 1;
    fibo.push_back(1);
    while(b <= n) {
        fibo.push_back(b);
        int tmp = a + b;
        a = b; b = tmp;
    }
    return fibo.back();
}
 
void get_size(int cur, int parent) {
    sz[cur] = 1;
    for(auto next: adj[cur]) {
        if( next.second == true) continue;
        if( parent == next.first) continue;
        get_size(next.first, cur);
        sz[cur] += sz[next.first];
    }
    return;
}

tuple<int, int, int> cut_edge(int cur, int fibo_index) {
    queue< pair<int, int > > q;
    q.push({cur, 0});
    while(!q.empty()) {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto next: adj[u]) {
            int v = next.first;
            if(next.second) continue;
            if(v == parent) continue;
            q.push({v, u});
            if(sz[v] == fibo[fibo_index - 1]) {
                return make_tuple(u, v, fibo_index-1);
            }        
            if(sz[v] == fibo[fibo_index - 2]) {
                return make_tuple(u, v, fibo_index-2);
            }
        }
    }
    return make_tuple(-1, -1, -1);
}
 
void dfs(int cur, int fibo_index) {
    if(fibo_index <= 1) return;
    get_size(cur, 0);
    int cur_size = sz[cur];
    auto [u, v, next_fibo_index] = cut_edge(cur, fibo_index);
    if(u == -1) {
        cout << "NO";
        exit(0);
    }
    for(auto &next: adj[u]) {
        if(next.first == v) next.second = true;
    }
    for(auto &next: adj[v]) {
        if(next.first == u) next.second = true;
    }

    dfs(v, next_fibo_index);
    dfs(u, next_fibo_index == fibo_index - 1 ? fibo_index - 2 : fibo_index - 1);

}
 
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back({b, false});
        adj[b].push_back({a, false});
    }
    if( n != make_fibo() ) {
        cout << "NO";
        exit(0);
    }
    dfs(1, fibo.size() - 1);
    cout << "YES";
}