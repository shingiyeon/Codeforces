//# Author : godgiyeon =========================#
//# Problem Title : Replace and Keep Sorted #
//# Time Stamp : 2021-02-13T00:29:33 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int arr[100005];
ll sum[100005];
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, q, k;
    cin >> n >> q >> k;
    arr[0] = 1; arr[n+1] = k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        if(i==1) {
            sum[i] += sum[i-1] + arr[i+1] - 2;
        }
        else if(i==n) {
            sum[i] += sum[i-1] + k - arr[i-1] - 1;
        }
        else  sum[i] += (sum[i-1] + arr[i+1] - arr[i-1] - 2);
    }
    for(int i=1; i<=q; i++) {
        int l, r; cin >> l >> r;
        if(r-l >= 1) {
            cout << (arr[l+1] - 2) + sum[r-1] - sum[l] + (k-arr[r-1]-1) << "\n";
        }
        else{
            cout << (arr[l] - 1) + (k - arr[r]) << "\n"; 
        }
    }

}