//# Author : godgiyeon =========================#
//# Problem Title : Genius's Gambit ========#
//# Time Stamp : 2021-02-24T10:39:09 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b, k; cin >> a >> b >> k;
    string sa, sb;
    string tsa, tsb;
    if(k == 0) {
        cout << "Yes\n";
        for(int i=0; i<b; i++) {
            sa += "1"; sb += "1";
        }
        for(int i=0; i<a; i++) {
            sa += "0"; sb += "0";
        }
        cout << sa << "\n" << sb;
        return 0;
    }
    if(b < 2 || a < 1) {
        cout << "No"; return 0;
    }
    if(a+b < k+2) {
        cout << "No"; return 0;
    }

    tsa = "0";
    tsb = "1";
    int temp = min(b-2, k-1);
    for(int i=0; i<temp; i++) {
        tsa = "1" + tsa;
        tsb = "1" + tsb;
    }
    b -= temp;
    temp = k - temp - 1;
    for(int i=0; i<temp; i++) {
        tsa = "0" + tsa;
        tsb = "0" + tsb;
    }
    a -= temp;
    tsa = "1" + tsa;
    tsb = "0" + tsb;
    b -= 1;
    a -= 1;
    for(int i=0; i<b; i++) {
        sa += "1";
        sb += "1";
    }
    for(int i=0; i<a; i++) {
        sa += "0";
        sb += "0";
    }
    cout << "Yes\n" << sa + tsa << "\n" << sb + tsb;
}