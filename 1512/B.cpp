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
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        string map[401];
        int n; cin >> n;
        for(int i=0; i<n; i++) cin >> map[i];
        vector<pair<int, int> > v;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j] == '*') v.push_back({i, j});
            }
        }
        if(v[0].first != v[1].first && v[0].second != v[1].second) {
            map[v[0].first][v[1].second] = '*';
            map[v[1].first][v[0].second] = '*';
        }
        else if(v[0].first == v[1].first) {
            int tmp = v[0].first - 1;
            if(tmp < 0 || tmp >= n) {
                tmp = v[0].first + 1;
            }
            map[tmp][v[0].second] = '*';
            map[tmp][v[1].second] = '*';
        }
        else if(v[0].second == v[1].second) {
            int tmp = v[0].second - 1;
            if(tmp < 0 || tmp >= n) {
                tmp = v[0].second + 1;
            }
            map[v[0].first][tmp] = '*';
            map[v[1].first][tmp] = '*';   
        }

        for(int i=0; i<n; i++) {
            cout << map[i] << "\n";
        }
    }
}