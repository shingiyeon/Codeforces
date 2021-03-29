//# Author : godgiyeon =========================#
//# Problem Title : Waste Sorting ==========#
//# Time Stamp : 2020-12-25T22:26:53 ===========#
//# Language : GNU C++17 =======================#

#include <stdio.h>

using namespace std;

int t;
int c[3], arr[5];
int main() {
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<3; i++) scanf("%d", &c[i]);
        for(int i=0; i<5; i++) scanf("%d", &arr[i]);
        bool pos = true;
        for(int i=0; i<3; i++) {
            c[i] -= arr[i];
            if(c[i] < 0) pos = false;
        }
        pos = c[0] + c[2] < arr[3] ? false : pos;
        int tmp = c[0] >= arr[3] ? 0 : arr[3] - c[0];
        c[2] -= tmp;
        pos = c[1] + c[2] < arr[4] ? false : pos;
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
}