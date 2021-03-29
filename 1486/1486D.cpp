//# Author : godgiyeon =========================#
//# Problem Title : Max Median =============#
//# Time Stamp : 2021-03-17T22:54:41 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int ans = 0;
int n, k; 
int arr[200005];
 
void binary_search(int l, int r) {
    if(l > r) {
        return ;
    }
    int mid = (l+r) / 2;
    vector<int> dy(n+1, 0);
 
    for(int i=1; i<=n; i++) {
        if(arr[i] >= mid) dy[i] = 1;
        else dy[i] = -1;
    }
    bool flag = false;
    int tmp_calc = 0;
    int min_val = 0;
    int temp_val = 0;
    for(int i=1; i<=k-1; i++) tmp_calc += dy[i];
 
    for(int i=k; i<=n; i++) {
        tmp_calc += dy[i];
        temp_val += dy[i-k];
        min_val = min(min_val, temp_val);
        if(tmp_calc - min_val > 0) {
            flag = true;
            ans = max(ans, mid);
        }
    }
 
    if(flag) {
        binary_search(mid + 1, r);
    } 
    else {
        binary_search(l, mid - 1);
    }
 
 
}
 
 
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        
    }
    binary_search(1, n);
    cout << ans;
}