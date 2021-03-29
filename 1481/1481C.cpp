//# Author : godgiyeon =========================#
//# Problem Title : Fence Painting =========#
//# Time Stamp : 2021-02-12T23:47:17 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int N, M;

vector<int> v[100001];
int p[100001];
int a[100001];
int b[100001];
int c[100001];

struct Query {
    int toVal, idx;
    bool pos;

    Query(int _toVal, int _idx) {
        toVal = _toVal;
        idx = _idx;
        pos = false;
    }
};


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        vector<int> ans_v(M+1);
        for(int i=1; i<=N; i++) v[i].clear();
        for(int i=1; i<=N; i++) p[i] = false;
        for(int i=1; i<=N; i++) cin >> a[i];
        for(int i=1; i<=N; i++) {
            cin >> b[i];
            p[b[i]] = i;
        }

        vector<Query> q;
        for(int i=1; i<=N; i++) {
            if(a[i] != b[i]) {
                q.push_back(Query(b[i], i));
            }
        }

        for(int i=1; i<=M; i++) {
            cin >> c[i];
            v[c[i]].push_back(i);
        }

        bool ans = true;
        for(int i=q.size()-1; i>=0; i--) {
            if(v[q[i].toVal].size() == 0) continue;
            q[i].pos = true;
            ans_v[v[q[i].toVal].back()] = q[i].idx;
            v[q[i].toVal].pop_back();
        }
        for(int i=0; i<=(int)q.size()-1; i++) {
            if(q[i].pos == false) ans = false;
        }

        for(int i=1; i<=N; i++) {
            for(auto val: v[i]) {
                if(p[i]) {
                    ans_v[val] = p[i];
                }
            }
        }

        int tmp_Val = -1;
        int tmp_idx = -1;
        for(int i=M; i>=1; i--) {
            if(ans_v[i] != 0) {
                tmp_Val = ans_v[i];
                tmp_idx = i;
                break;
            }
        }
        for(int i=1; i<=M; i++) {
            if(ans_v[i] == 0 && tmp_idx >= i) {
                ans_v[i] = tmp_Val;
            }
        }
        for(int i=1; i<=M; i++) {
            if(ans_v[i] == 0) ans = false;
        }
        
        if(ans) {
            cout << "YES" << "\n";
            for(int i=1; i<=M; i++) {
                cout << ans_v[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        

    }
}