//# Author : godgiyeon =========================#
//# Problem Title : Let's Go Hiking ========#
//# Time Stamp : 2021-03-12T23:21:12 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
using namespace std;

int dy[200001];
int rdy[200001];
int arr[200001];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    dy[1] = 1;
    for(int i=2; i<=n; i++) {
        if(arr[i] > arr[i-1]) dy[i] = dy[i-1] + 1;
        else dy[i] = 1;
    }
    rdy[n] = 1;
    for(int i=n-1; i>=1; i--) {
        if(arr[i] > arr[i+1]) rdy[i] = rdy[i+1] + 1;
        else rdy[i] = 1;
    }
    
    int max_val = 0;
    for(int i=1; i<=n; i++) {
        if(dy[i] == rdy[i]) {
            max_val = max(max_val, dy[i]);
        }
    }
    int num = 0, rnum = 0;
    for(int i=1; i<=n; i++) {
        if(dy[i] == max_val) num++;
        if(rdy[i] == max_val) rnum++;
    }
    if(num == 1 && rnum == 1 && (max_val % 2)) {
        cout << "1";
    }
    else {
        cout << "0";
    }
}