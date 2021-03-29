//# Author : godgiyeon =========================#
//# Problem Title : Different Divisors =====#
//# Time Stamp : 2021-01-20T00:01:34 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int t, d;


vector<int> s;
bool sosu[30000];


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    sosu[0] = 1; sosu[1] = 0;
    for(int i=2; i<30000; i++) {
        if(sosu[i] == 0) {
            for(int j=2*i; j<30000; j+=i) {
                sosu[j] = 1;
            }
        }
    }
    for(int i=0; i<30000; i++) if(!sosu[i]) s.push_back(i);
    cin >> t;
    while(t--) {
        cin >> d;
        int low_idx = lower_bound(s.begin(), s.end(), 1 + d) - s.begin();
        int high_idx = lower_bound(s.begin(), s.end(), s[low_idx] + d) - s.begin();
        cout << s[low_idx] * s[high_idx] << "\n";
    }
}