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
        int n, k; cin >> n >> k;
        int arr[101];
        vector<int> d(101, 0);
        if(k == 0) {
            for(int i=0; i<n; i++) cout << i+1 << " ";
            cout << "\n";
            continue;
        }
        else {
            if( (n-1)/2 < k )  {
                cout << "-1\n";
                continue;
            }

            int idx = 1;
            for(int i=0; i<k; i++) {
                d[idx] = n - i;
                idx += 2;
            }
            idx = n - k;
            for(int i=n-1; i>=0; i--) {
                if(d[i] == 0) {
                    d[i] = n - k;
                    k++;
                }
            }
            for(int i=0; i<n; i++) cout << d[i] << " ";
            cout << "\n";
        }
    }
}
