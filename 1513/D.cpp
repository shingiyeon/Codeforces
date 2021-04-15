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
        int n, p; cin >> n >> p;
        vector<int> v;
        set<pair<int, int> > s;
        vector<int> connected(n-1, 0);
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp; v.push_back(tmp);
        }
        for(int i=0; i<v.size(); i++) {
            s.insert({v[i], i});
        }
        for(auto it=s.begin(); it!=s.end(); it++) {
            int val = it->first;
            int index = it->second;
            if(val >= p) break;
            for(int i=index-1; i>=0; i--) {
                if(connected[i]) break;
                if(v[i] % val == 0) {
                    connected[i] = true;
                    ans += val;
                }
                else break;
            }
            for(int i=index+1; i<n; i++) {
                if(connected[i-1]) break;
                if(v[i] % val == 0) {
                    connected[i-1] = true;
                    ans += (long long)val;
                }
                else break;
            }
        }
        for(int i=0; i<n-1; i++) {
            if(!connected[i]) ans += (long long)p;
        }
        cout << ans << "\n";
    }
}

