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
int zegop(int a, int x) {
    int ans = 1;
    while(x) {
        if(x%2) ans *= a;
        a *= a;
        x /= 2;
    }
    return ans;
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;
    int idx = 1;
    int p = 1;
    while(p <= 1e9) {
        if(idx >= p) {
            v.push_back(idx);
            p *= 10;
        }
        idx *= 2;
    }
    int tc; cin >> tc;
    while(tc--) {
        int a, b, c; cin >> a >> b >> c;
        int x, y;
        int tb = zegop(10, b-1);
        x = v[a-1];
        y = v[c-1];
        while(y < tb) y *= 3;
        cout << x << " " << y << "\n"; 
    }
}