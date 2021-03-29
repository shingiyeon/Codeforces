//# Author : godgiyeon =========================#
//# Problem Title : The Robot ==============#
//# Time Stamp : 2020-12-25T23:17:54 ===========#
//# Language : GNU C++17 =======================#

#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int t; char s[5001];
vector<pair<int, int> > v;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        v.clear();
        int x = 0, y = 0;
        for(int i=0; s[i]!='\0'; i++) {
            if(s[i] == 'L') x--;
            else if(s[i] == 'R') x++;
            else if(s[i] == 'U') y++;
            else if(s[i] == 'D') y--;
            v.push_back({x, y});
        }
        if(v[v.size()-1].first == 0 && v[v.size()-1].second == 0) {
            printf("0 0\n");
            continue;
        }
        bool pos = false;
        for(auto obs: v) {
            int obsx = obs.first; int obsy = obs.second;
            x = y = 0;
            int dx = 0, dy = 0;
            for(int i=0; s[i]!='\0'; i++) {
                dx = 0; dy = 0;
                if(s[i] == 'L') dx = -1;
                else if(s[i] == 'R') dx = 1;
                else if(s[i] == 'U') dy = 1;
                else if(s[i] == 'D') dy = -1;

                if (!(x+dx == obsx && y+dy == obsy)) {
                    x = x + dx; y = y + dy;
                }
            }
            if(x == 0 && y == 0) {
                printf("%d %d\n", obsx, obsy);
                pos = true;
                break;
            }
        }
        if(!pos) printf("0 0\n");
    }
}