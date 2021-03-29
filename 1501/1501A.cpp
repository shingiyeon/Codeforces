//# Author : godgiyeon =========================#
//# Problem Title : Alexey and Train =======#
//# Time Stamp : 2021-03-13T22:39:14 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int upper(int a, int b) {
    if(a % b) {
        return (a/b) + 1;
    }
    return (a/b);
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a, b, tm;
        a.push_back(0);
        b.push_back(0);
        tm.push_back(0);
        ll arrive_time = 0;
        ll depart_time = 0;
        for(int i=1; i<=n; i++) {
            int A, B; cin >> A >> B;
            a.push_back(A); b.push_back(B);
        }
        for(int i=1; i<=n; i++) {
            int TM; cin >> TM;
            tm.push_back(TM);
        }
        for(int i=1; i<=n; i++) {
            arrive_time = depart_time + ((ll)a[i] - b[i-1] + tm[i]);
            ll hope_time = arrive_time + (ll)upper(b[i]-a[i], 2);
            if(hope_time > (ll)b[i]) {
                depart_time = hope_time;
            }
            else {
                depart_time = (ll)b[i];
            }
        }
        cout << arrive_time << "\n";
    }


}