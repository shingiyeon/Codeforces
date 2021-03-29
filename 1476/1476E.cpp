//# Author : godgiyeon =========================#
//# Problem Title : Pattern Matching =======#
//# Time Stamp : 2021-02-22T23:15:47 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<string, int> s_map;
vector<int> adj[100001];
int indeg[100001];

string change(string str, int num) {
    int idx = 0;
    while(num) {
        if(num & 1) {
            str[idx] = '_';
        }
        num /= 2;
        idx++;
    }
    return str;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    string tmp; int num;
    for(int i=1; i<=n; i++) {
        cin >> tmp; 
        s_map[tmp] = i;
    }
    bool flag = true;
    for(int i=1; i<=m; i++) {
        cin >> tmp >> num;
        bool tmp_flag = false;
        for(int j=0; j<pow(2,k); j++) {
            string change_str = change(tmp, j);
            int idx = s_map[change_str];
            if(idx && idx != num) {
                adj[num].push_back(idx);
                indeg[idx]++;
            }
            if(idx == num) {
                tmp_flag = true;
            }
        }
        flag = flag & tmp_flag;
    }
    vector<int> ans;
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(auto next: adj[cur]) {
            indeg[next]--;
            if(indeg[next] == 0) {
                q.push(next);
            }
        }
    }

    if(ans.size() != n || !flag) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        for(auto val: ans) {
            cout << val << " ";
        }
    }

}