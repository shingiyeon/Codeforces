//# Author : godgiyeon =========================#
//# Problem Title : Pythagorean Triples ====#
//# Time Stamp : 2021-03-05T10:01:48 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    vector<long long> v;
    long long c = 5;
    long long k = 8;
    v.push_back(c);

    while(c <= 1000000000LL) {
        c += k;
        k += 4;
        v.push_back(c);
    }

    while(t--) {
        long long n; cin >> n;
        int idx = lower_bound(v.begin(), v.end(), n+1) - v.begin();
        cout << idx << "\n";
    }
}