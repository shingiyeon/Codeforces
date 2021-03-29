//# Author : godgiyeon =========================#
//# Problem Title : Multiples and Power Differences #
//# Time Stamp : 2021-02-13T23:43:28 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int a[501][501];
int b[501][501];

int gcd(int a, int b) {
    while(a%b) {
        int m = a % b;
        a = b; b = m;
    }
    return b;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m; 
    int lcm = 1;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=16; i++) {
        lcm *= i / gcd(lcm, i);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if( (i+j) % 2 == 1 ) {
                b[i][j] = lcm;
            }
            else {
                b[i][j] = a[i][j] * a[i][j] * a[i][j] * a[i][j] + lcm;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }



}