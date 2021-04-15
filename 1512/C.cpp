#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int q_mark = 0;
        bool isOdd= false;
        string str; cin >> str;
        bool flag = true;
        if( (a+b) % 2 ) {
            isOdd = true;
            if(str[str.size()/2] == '0') a--;
            else if(str[str.size()/2] == '1') b--;
            else q_mark++;
        }
        for(int i=0; i<str.size()/2; i++) {
            if((str[i] == '0' && str[str.size()-i-1] == '1') || (str[i] == '1' && str[str.size()-i-1] == '0')) {
                flag = false;
            }
            else if(str[i] != '?' && str[str.size()-i-1] == '?') {
                if(str[i] == '0') {
                    a -= 2; 
                }
                else if(str[i] == '1') {
                    b-= 2;
                }
                str[str.size()-i-1] = str[i];
            }
            else if(str[i] == '?' && str[str.size()-i-1] != '?'){
                if(str[str.size()-i-1] == '0') {
                    a -= 2; 
                }
                else if(str[str.size()-i-1] == '1') {
                    b-= 2;
                }
                str[i] = str[str.size()-i-1];
            }
            else if(str[i] == '?' && str[str.size()-i-1] == '?'){
                q_mark += 2;
            }
            else {
                if(str[i] == '0') a-=2;
                else b-=2;
            }
        }
        if(a<0 || b<0 || a+b != q_mark || (a%2 && b%2)) {
            flag = false;
        }
        for(int i=0; i<str.size()/2; i++) {
            if(str[i] == '?') {
                if(a >= 2) {
                    str[i] = str[str.size() - i - 1] = '0';
                    a -= 2;
                }
                else {
                    str[i] = str[str.size() - i - 1] = '1';
                    b -= 2;
                }
            }
        }
        if(isOdd) {
            if(str[str.size()/2] == '?') {
                str[str.size()/2] = ( (a > 0) ? '0' : '1' );
            } 
        }
        
        if(flag) {
            cout << str << "\n";
        }
        else {
            cout << "-1\n";
        }
        
    }
}
