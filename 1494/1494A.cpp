//# Author : godgiyeon =========================#
//# Problem Title : ABC String =============#
//# Time Stamp : 2021-03-05T14:30:20 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    int cnt[3];
    int bra[2];
    while(t--) {
        string a; cin >> a;
        cnt[0] = cnt[1] = cnt[2] = 0;
        bra[0] = bra[1] = 0;
        int sum = a.size();
        for(int i=0; i<a.size(); i++) {
            cnt[a[i] - 'A']++;
        }
        bool flag[3];
        bool okay = true;
        int s = a[0] - 'A';
        int e = a[a.size()-1] - 'A';
        flag[s] = false;
        flag[e] = true;
        int m;
        if(s == e) {
            cout << "NO" << "\n";
            continue;
        }
        if(s != 0 && e != 0) m = 0;
        if(s != 1 && e != 1) m = 1;
        if(s != 2 && e != 2) m = 2;
        if(cnt[s] + cnt[m] == cnt[e]) flag[m] = false;
        else if(cnt[s] == cnt[m] + cnt[e]) flag[m] = true;
        else {
            cout << "NO" << "\n";
            continue;
        }

        for(int i=0; i<a.size(); i++) {
            bra[ flag[a[i] - 'A'] ]++;
            if(bra[1] > bra[0]) {
                cout << "NO" << "\n";
                okay = false;
                break;
            }
        }
        if (okay) cout << "YES" << "\n";
        

        


        

        
    }
}