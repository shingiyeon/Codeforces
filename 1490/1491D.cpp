//# Author : godgiyeon =========================#
//# Problem Title : Zookeeper and The Infinite Zoo #
//# Time Stamp : 2021-03-01T23:28:58 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> func(ll a) {
    vector<int> pos;
    for(int i=0; i<=30; i++) {
        if(a  & (1 << i)) pos.push_back(i);
    }
    return pos;
}

bool checked(vector<int> a, vector<int> b) {
    int bidx = b.size() - 1;
    int aidx = 0;
    for(int i = 0; i <= bidx; i++) {
        if(b[i] < a[aidx++]) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        ll a, b; cin >> a >> b;
        if(a > b)  {
            cout << "NO" << "\n";
            continue;
        }
        auto _a = func(a);
        auto _b = func(b);
        if(_a.size() < _b.size() ) {
            cout << "NO" << "\n";
            continue;
        }
        if(checked(_a, _b)) {
            cout << "YES" << "\n";
        }   
        else {
            cout << "NO" << "\n";
        }
    }
}