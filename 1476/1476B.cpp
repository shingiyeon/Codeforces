//# Author : godgiyeon =========================#
//# Problem Title : Inflation ==============#
//# Time Stamp : 2021-02-25T13:19:41 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
typedef long long ll;
using namespace std;
ll arr[101];
long double arrd[101];
ll upper(ll a, ll b) {
    return (a / b) + (a % b != 0);
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        long long delta = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        ll sum = arr[0];
        for(int i=1; i<n; i++) {
            arrd[i] = (long double)arr[i] / sum;
            if( arrd[i] > ((long double)k/100) ) {
                delta = max(delta, upper(100 * arr[i], k) - sum);
            }
            sum += arr[i];
        }
        cout << delta << "\n";
    }
}