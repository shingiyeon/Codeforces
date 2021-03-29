//# Author : godgiyeon =========================#
//# Problem Title : Painting the Array I ===#
//# Time Stamp : 2021-03-14T22:51:15 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
using namespace std;

int arr[100005];
int nxt[100005];
int pos[100005];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        nxt[i] = n+1;
    }
    nxt[0] = n+1;
    for(int i=n; i>=0; i--) {
        pos[i] = nxt[arr[i]];
        nxt[arr[i]] = i;
    }

    vector<int> A, B;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int vA, vB;
        if(A.empty()) vA = 0;
        else vA = A.back();
        if(B.empty()) vB = 0;
        else vB = B.back();
        if(arr[vA] == arr[i] && arr[vB] == arr[i]) {
            B.push_back(i);
            ans += (arr[vB] != arr[i]);
        }
        if(arr[vA] == arr[i]) {
            B.push_back(i);
            ans += (arr[vB] != arr[i]);
        }
        else if(arr[vB] == arr[i]) {
            A.push_back(i);
            ans += (arr[vA] != arr[i]);
        }
        else if(pos[vA] < pos[vB]) {
            A.push_back(i);
            ans += (arr[vA] != arr[i]);
        }
        else {
            B.push_back(i);
            ans += (arr[vB] != arr[i]);
        }
    }

    cout << ans;

}