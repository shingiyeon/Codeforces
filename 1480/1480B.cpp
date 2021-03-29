//# Author : godgiyeon =========================#
//# Problem Title : The Great Hero =========#
//# Time Stamp : 2021-03-11T22:48:58 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;

int upper(int a, int b) {
    if(a % b) {
        return (a/b) + 1;
    }
    else return (a/b);
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int A, B, n; cin >> A >> B >> n;
        vector< pair<int, int> > a(n, {0, 0});
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp; a[i].first = tmp;
        }
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp; a[i].second = tmp;
        }
        sort(a.begin(), a.end());
        ll sum = 0;

        for(int i=0; i<a.size()-1; i++) {
            int attack = a[i].first; int health = a[i].second;
            int t = upper(health, A);
            sum += (ll)attack * t;
        }
        int attack = a.back().first; int health = a.back().second;
        int t = upper(health, A);
        sum += (ll)attack * (t - 1);
        if((ll)B > sum) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }


    }    
}