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
        int n; cin >> n;
        vector<int> cnt(101, 0);
        vector<int> idx(101, 0);
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            cnt[tmp]++;
            idx[tmp] = i+1;
        }
        for(int i=1; i<=100; i++) {
            if(cnt[i] == 1) {
                cout << idx[i] << "\n";
            }
        }
    }
}