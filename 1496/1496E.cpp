//# Author : godgiyeon =========================#
//# Problem Title : Garden of the Sun ======#
//# Time Stamp : 2021-03-13T22:19:53 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t; cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        string map[601];
        for(int i=0; i<n; i++) {
            cin >> map[i];
        }

        if(n % 3 == 0) {
            for(int i=0; i<n; i++) {
                if(i % 3 == 1) {
                    for(int j=0; j<m; j++) {
                        map[i][j] = 'X';
                    }
                }
            }
            for(int i=0; i<n/3; i++) {
                int first_idx = 999;  
                for(int j=0; j<m; j++) {
                    if( (i*3+2 < n && map[i*3+2][j] == 'X') || (i*3+3 < n && map[i*3+3][j] == 'X') ) {
                        first_idx = min(first_idx, j);
                        break;
                    }
                } 
                if(first_idx == 999) {
                    if(3*i+2 < n) map[3*i+2][0] = 'X';
                    if(3*i+3 < n) map[3*i+3][0] = 'X';
                }
                else {
                    if(3*i+2 < n) map[3*i+2][first_idx] = 'X';
                    if(3*i+3 < n) map[3*i+3][first_idx] = 'X';
                }
            }
        }

        else {
            for(int i=0; i<n; i++) {
                if(i % 3 == 0) {
                    for(int j=0; j<m; j++) {
                        map[i][j] = 'X';
                    }
                }
            }
            for(int i=0; i<n/3; i++) {
                int first_idx = 999;
                for(int j=0; j<m; j++) {
                    if( (i*3+1 < n && map[i*3+1][j] == 'X') || (i*3+2 < n && map[i*3+2][j] == 'X')  ) {
                        first_idx = min(first_idx, j);
                        break;
                    }
                }
    
                if(first_idx == 999) {
                    if(3*i+1 < n) map[3*i+1][0] = 'X';
                    if(3*i+2 < n) map[3*i+2][0] = 'X';
                }
                else {
                    if(3*i+1 < n) map[3*i+1][first_idx] = 'X';
                    if(3*i+2 < n) map[3*i+2][first_idx] = 'X';
                }
            }
        }

        for(int i=0; i<n; i++) {
            cout << map[i] << "\n";
        }
    }
}