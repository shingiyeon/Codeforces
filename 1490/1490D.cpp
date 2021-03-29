//# Author : godgiyeon =========================#
//# Problem Title : Permutation Transformation #
//# Time Stamp : 2021-03-02T15:32:30 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int depth[100];
int arr[100];

int max_val(int left, int right) {
    if(left > right) return -1;
    if(left == right) {
        return left;
    }
    int val = 0;
    int idx = left;
    for(int i=left; i<=right; i++) {
        if(arr[i] > val) {
            val = arr[i];
            idx = i;
        }
    }
    return idx;
}

void binary_search(int left, int right, int d) {
    int idx = max_val(left, right);
    if(idx == -1) return;
    depth[idx] = d;
    binary_search(left, idx-1, d+1);
    binary_search(idx+1 ,right, d+1);
    return;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            depth[i] = 0;
        }
        binary_search(0, n-1, 0);
        for(int i=0; i<n; i++) {
            cout << depth[i] << " ";
        }
        cout << "\n";
    }
}