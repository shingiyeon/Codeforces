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

    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> vec(n);
        for(int i=0; i<n; i++) cin >> vec[i];
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(vec[i] != 2) ans++;
        }
        cout << ans << "\n";
    }
}