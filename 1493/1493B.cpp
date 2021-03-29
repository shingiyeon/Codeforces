//# Author : godgiyeon =========================#
//# Problem Title : Planet Lapituletti =====#
//# Time Stamp : 2021-03-06T23:42:57 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int pos[5] = {0, 1, 2, 5, 8};
int change[5] = {0, 1, 5, 2, 8};

bool check(int t, int limit) {
    int h = t / 10;
    int m = t % 10;
    bool flag1 = false;
    bool flag2 = false;
    for(int i=0; i<5; i++) {
        if(h == pos[i]) {
            for(int j=0; j<5; j++) {
                if(m == pos[j]) {
                    if( change[j] * 10 + change[i] < limit ) {
                        return true;
                    }
                }
            }
        } 
    }
    return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int h, m; cin >> h >> m;
        string s; cin >> s;
        
        int th = 10 * (s[0] - '0') + (s[1] - '0');
        int tm = 10 * (s[3] - '0') + (s[4] - '0');
        int ansh, ansm;
        for(int i=0; i<h*m ; i++) {
            int j = (tm+i) / m;
            if(check( (th + j) % h, m) && check( (tm + i) % m, h)  ) {
                ansh = (th + j) % h;
                ansm = (tm + i) % m;
                break;
            }
        }
        cout << (int)ansh/10 << (ansh%10) << ":" << (int)ansm/10 << (ansm%10) << "\n";
    }
}