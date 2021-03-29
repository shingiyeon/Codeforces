//# Author : godgiyeon =========================#
//# Problem Title : Card Deck ==============#
//# Time Stamp : 2021-02-23T18:32:39 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; 
        vector<int> v;
        vector<int> pos(100001, 0);
        vector<int> ans;

        cin >> n;
        int tmp; int MAX = n;
        for(int i=1; i<=n; i++) {
            cin >> tmp ; v.push_back(tmp);
        }
        list<int> temp;
        for(int i=n-1; i>=0; i--) {
            temp.push_front(v[i]);
            pos[v[i]] = true;
            if(v[i] == MAX) {
                for(int j=MAX; pos[j]==true; j--) {
                    MAX = j-1;
                }
                for(auto val: temp) {
                    ans.push_back(val);
                }
                temp.clear();
            }
        }
        for(auto val: ans) cout << val << " ";
        cout << "\n";
    }
}