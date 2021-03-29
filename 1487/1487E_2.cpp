//# Author : godgiyeon =========================#
//# Problem Title : Cheap Dinner ===========#
//# Time Stamp : 2021-03-05T11:04:47 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define INF 0x7FFFFFFF
using namespace std;

int n[4];
vector< pair<int, int> > p[4];
int dy[4][150001];

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);

    for(int i=0; i<4; i++) {
        for(int j=0; j<=150000; j++) dy[i][j] = INF;
    }

    for(int i=0; i<4; i++) cin >> n[i];
    for(int i=0; i<4; i++) {
        for(int j=1; j<=n[i]; j++) {
            int tmp; cin >> tmp;
            p[i].push_back( {tmp , j});
        }
    }
    for(auto val: p[0]) {
        dy[0][val.second] = val.first;
    }

    for(int i=1; i<=3; i++) {
        vector<int> adj[150001];
        multiset<int> a;
        for(int j=1; j<=n[i-1]; j++) {
            a.insert(dy[i-1][j]);
        }

        int limit; cin >> limit;
        for(int j=0; j<limit; j++) {
            int x, y; cin >> x >> y; adj[y].push_back(x);
        }
        
        for(auto [cur_val, cur_index]: p[i]) {
            for(auto before_index: adj[cur_index]) {
                a.erase( a.find(dy[i-1][before_index]) );
            }
            auto min_val = *a.begin();
            if (!a.empty() && min_val != INF) dy[i][cur_index] = min(dy[i][cur_index], cur_val + min_val);

            for(auto before_index: adj[cur_index]) {
                a.insert(dy[i-1][before_index]);
            }
        }
    }
    int ans = INF;
    for(int i=1; i<=n[3]; i++) {
        ans = min(ans, dy[3][i]);
    }
    if(ans == INF) cout << "-1";
    else cout << ans;



}