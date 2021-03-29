//# Author : godgiyeon =========================#
//# Problem Title : K-th Largest Value =====#
//# Time Stamp : 2021-02-28T22:39:21 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;
int n, q;
int cnt[2];
int arr[100001];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> q; int tmp;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int x, y;
    for(int i=0; i<q; i++) {
        cin >> x >> y;
        if(x == 1) {
            if(arr[y]) {
                arr[y] = 0;
                cnt[1]--; cnt[0]++;
            }
            else {
                arr[y] = 1;
                cnt[0]--; cnt[1]++;
            }
        }
        else {
            if(cnt[1] >= y) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
    }

}