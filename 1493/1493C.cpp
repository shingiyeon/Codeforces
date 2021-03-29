//# Author : godgiyeon =========================#
//# Problem Title : K-beautiful Strings ====#
//# Time Stamp : 2021-03-07T22:49:56 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int need(int n, int k) {
    return (k - (n % k)) % k;
}

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        if(n % k) {
            cout << "-1" << "\n";
            continue;
        }
        int sum = 0;
        vector<int> cnt(26, 0);
        for(int i=0; i<str.size(); i++) cnt[str[i] - 'a']++;
        for(int i=0; i<26; i++) sum += need(cnt[i], k);
        if(sum == 0) {
            cout << str << "\n";
            continue;
        }
        bool flag = false;

        for(int i=str.size()-1; i>=0; i--) {
            sum -= need(cnt[str[i] - 'a'], k); 
            cnt[str[i] - 'a']--;
            sum += need(cnt[str[i] - 'a'], k);
            for(int j=str[i] + 1; j<='z'; j++) {
                sum -= need(cnt[j - 'a'], k);
                cnt[j - 'a']++;
                sum += need(cnt[j - 'a'], k);
                if(sum <= n - i - 1) {
                    string ans = "";
                    for(int k=0; k<i; k++) {
                        cout << str[k];
                    }
                    cout << (char)j;
                    
                    for(int x=0; x<26; x++) {
                        for(int y=0; y<need(cnt[x], k); y++) {
                            ans += char(x + 'a');
                        }
                    }
                    int k = ans.size();
                    for(int x=0; x<n-k-i-1; x++) {
                        ans += char('a');
                    }
                    sort(ans.begin(), ans.end());
                    flag = true;
                    cout << ans << "\n";
                    break;
                }
                sum -= need(cnt[j - 'a'], k);
                cnt[j - 'a']--;
                sum += need(cnt[j - 'a'], k);
            }
            if(flag) break;
        }
         
    }
}