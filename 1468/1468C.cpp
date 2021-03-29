//# Author : godgiyeon =========================#
//# Problem Title : Berpizza ===============#
//# Time Stamp : 2020-12-25T22:40:17 ===========#
//# Language : GNU C++17 =======================#

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool visited[500001];
priority_queue< pair<int, int> > pq; 
queue< pair<int, int> > q;
vector<int> ans;
int t;

int main() {
    scanf("%d", &t); int idx = 1;
    int qu, m;
    while(t--) {
        scanf("%d", &qu);
        if(qu==1) {
            scanf("%d", &m);
            q.push({m, -idx});
            pq.push({m, -idx});
            idx++;
        }
        else if(qu==2) {
            int cur = 0;
            while(visited[-q.front().second] && !q.empty()) q.pop();
            cur = -q.front().second;
            q.pop(); visited[cur] = true;
            if (cur != 0) ans.push_back(cur);
        }
        else {
            int cur = 0;
            while(visited[-pq.top().second] && !pq.empty()) pq.pop();
            cur = -pq.top().second;
            pq.pop(); visited[cur] = true;
            if(cur != 0) ans.push_back(cur);
        }
    }
    for(auto val: ans) {
        printf("%d ", val);
    }
}