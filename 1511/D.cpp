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
    int n, k; cin >> n >> k;
    string str = "a";
    int idx = 1;
    bool visited[26][26];
    int cur = 0;

    for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) visited[i][j] = 0;
    }

    while(str.size() < n) {
        bool flag = false;
        for(int i=0; i<k; i++) {
            if(!visited[cur][ (cur+i) % k]) {
                str += ((cur+i) % k + 'a');
                visited[cur][(cur+i) % k] = true;
                cur = (cur+i) % k;
                flag = true;
                break;
            }
        }
        if(flag == false) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) visited[i][j] = 0;
            }
        }
    }

    cout << str;
}