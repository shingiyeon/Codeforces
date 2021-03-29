//# Author : godgiyeon =========================#
//# Problem Title : Four Segments ==========#
//# Time Stamp : 2020-12-25T22:12:36 ===========#
//# Language : GNU C++17 =======================#

#include <stdio.h>
#include <algorithm>

using namespace std;
int t;
int arr[4];

int main() {
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<4; i++) scanf("%d", &arr[i]);
        int ans = 0;
        ans = max(ans, min(arr[0], arr[1]) * min(arr[2], arr[3]));
        ans = max(ans, min(arr[0], arr[2]) * min(arr[1], arr[3]));
        ans = max(ans, min(arr[0], arr[3]) * min(arr[2], arr[1]));
        ans = max(ans, min(arr[0], arr[3]) * min(arr[2], arr[1]));
        printf("%d\n", ans);
    }
}