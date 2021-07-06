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
        int n,  k; cin >> n >> k;
        int sum = 0;
        vector<int> arr;
        for(int i=0; i<n; i++ ) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        int idx = 0;
        while(k) {
            bool flag = false;
            while(arr[idx] == 0) {
                idx++;
                if(idx == arr.size() - 1) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            k--;
            arr[idx]--;
            arr[arr.size()-1]++;
        }
        for(auto val: arr) {
            cout << val << " ";
        }
        cout << "\n";
    }
}