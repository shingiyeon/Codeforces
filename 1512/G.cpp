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

vector<int> spf(1e7 + 1, 0);
vector<int> p;
vector<int> dy(1e7 + 1, 1);
vector<int> ans(1e7 + 1, 1e7 + 5);
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i=2; i<= 1e7; i++) {
        if(!spf[i]) {
            p.push_back(i);
            spf[i] = i;
        }
        for(int j=0; i*p[j] <= 1e7; j++) {
            spf[i*p[j]] = p[j];
            if(i % p[j] == 0) break;
        }
    }
    dy[1] = 1;
    for(int i=2; i<=1e7; i++) {
        if(i == spf[i]) {
            dy[i] = dy[i/spf[i]] + i;
        }
        else if( i/spf[i] == spf[i]) {
            dy[i] = dy[i/spf[i]] + i;
        }
        else dy[i] = dy[i/spf[
    }
    for(int i=1; i<=1e7; i++) {
        if(dy[i] <= 1e7) {
            ans[dy[i]] = min(i, ans[dy[i]]);
        }
    }
    while(t--) {
        int n; cin >> n;
        if(ans[n] == 1e7 + 5) {
            cout << "-1\n";
        }
        else cout << ans[n] << "\n";
    }
}