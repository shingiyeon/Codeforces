//# Author : godgiyeon =========================#
//# Problem Title : Hills And Valleys ======#
//# Time Stamp : 2021-01-19T23:22:10 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int d[300005];
int arr[300005];
int t; int n;

bool check(int idx) {
    if(arr[idx] > arr[idx + 1] && arr[idx] > arr[idx-1]) return 1;
    if(arr[idx] < arr[idx - 1] && arr[idx] < arr[idx+1]) return 1;
    return 0;
}

int chk(int idx) {
    int tmp_value = 0, tmp_ans = 0;
    int tmp = arr[idx];

    arr[idx] = arr[idx+1];
    tmp_ans += check(idx);
    if(idx - 1 > 0) tmp_ans += check(idx - 1);
    if(idx + 1 < n-1) tmp_ans += check(idx + 1);

    arr[idx] = arr[idx-1];
    tmp_value += check(idx);
    if(idx - 1 > 0) tmp_value += check(idx - 1);
    if(idx + 1 < n-1) tmp_value += check(idx + 1);
    arr[idx] = tmp;
    return min(tmp_ans, tmp_value);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            d[i] = 0;
        }
        for(int i=1; i<n-1; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                d[i] = 1; ans++;
            }
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                d[i] = 1; ans++;
            }
        }
        int minus = 0;
        for(int i=1; i<n-1; i++) {
            minus = max(minus, d[i-1] + d[i] + d[i+1] - chk(i));
        }
        printf("%d\n", ans - minus);
    }
}