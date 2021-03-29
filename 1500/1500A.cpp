//# Author : godgiyeon =========================#
//# Problem Title : Going Home =============#
//# Time Stamp : 2021-03-14T00:08:09 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> cnt[5000001];
int arr[200001];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=5000000; i++) {
        cnt[i].first = cnt[i].second = -1;
    }
    int idx = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            int x = i; int y = j; if(x>y) swap(x, y);
            if(cnt[arr[i] + arr[j]].first == -1) {
                cnt[arr[i]+arr[j]].first = x;
                cnt[arr[i]+arr[j]].second = y;
            }
            else {
                if(cnt[arr[i] + arr[j]].first != x && cnt[arr[i] + arr[j]].first != y && \
                    cnt[arr[i] + arr[j]].second != x && cnt[arr[i] + arr[j]].second != y) {
                        cout << "YES" << "\n";
                        cout << cnt[arr[i] + arr[j]].first << " " << cnt[arr[i] + arr[j]].second << " " << x << " " << y;
                        return 0;
                    }
            }
            idx++;
            if(idx >= 20000000) break;
        }
    }

    cout << "NO";
}