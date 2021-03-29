//# Author : godgiyeon =========================#
//# Problem Title : Accidental Victory =====#
//# Time Stamp : 2021-03-02T16:24:02 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long sum[200005];
int arr[200005];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v, ans; 
        for(int i=1; i<=n; i++) {
            cin >> arr[i]; v.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            if(i==0) sum[i] = v[i];
            else sum[i] = sum[i-1] + v[i];
        }
        int max_val = -1;
        for(int i=0; i<v.size()-1; i++) {
            if(sum[i] < v[i+1]) {
                max_val = i;
            }
        }
        for(int i=1; i<=n; i++) {
            if( lower_bound(v.begin(), v.end(), arr[i]) - v.begin() > max_val ) {
                ans.push_back(i);
            }
        }
        cout << ans.size() << "\n";
        for(auto val: ans) {
            cout << val << " ";
        }
        cout << "\n";
    }
}