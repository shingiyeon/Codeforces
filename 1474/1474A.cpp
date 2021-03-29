//# Author : godgiyeon =========================#
//# Problem Title : Puzzle From the Future =#
//# Time Stamp : 2021-01-19T23:48:56 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>

using namespace std;
int t;
int n;

string str;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> str;
        string tmp = "";
        int idx = -1;
        for(int i=0; i<str.size(); i++) {
            if(i==0) {
                tmp += "1";
                idx = str[i] - '0' + 1;
                continue;
            }
            if(idx == 0) {
                tmp += "1";
                if(str[i] == '1') {
                    idx = 2;
                }
                else {
                    idx = 1;
                }

            }
            else if(idx == 1) {
                if(str[i] == '1') {
                    tmp += '1';
                    idx = 2;
                }
                else if(str[i] == '0') {
                    tmp += '0';
                    idx = 0;
                }
            }
            else {
                if(str[i] == '1') {
                    tmp += '0';
                    idx = 1;
                }
                else if(str[i] == '0') {
                    tmp += '1';
                    idx = 1;
                }
            }
        }
        cout << tmp << "\n";
    }
}