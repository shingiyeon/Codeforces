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
        int pre[2001];
        pre[0] = 0;
        
        bool ans = false;
        for(int i=1; i<=n; i++) {
            int tmp; cin >> tmp;
            pre[i] = pre[i-1] ^ tmp;
        }
        if(!pre[n]) ans = true;

        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                ans |= ( (pre[i] == (pre[i] ^ pre[j])) && (pre[i] == (pre[n] ^ pre[j])) );
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}