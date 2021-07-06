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
    int n, q; cin >> n >> q;
    vector<int> arr(51, 9999999);

    for(int i=0; i<n; i++) {
        int tmp; cin >> tmp;
        arr[tmp] = min(arr[tmp], i+1);
    }
    
    for(int i=0; i<q; i++) {
        int tmp; cin >> tmp;
        cout << arr[tmp] << " ";
        for(int i=1; i<=50; i++) {
            if(arr[i] < arr[tmp]) {
                arr[i]++;
            }
        }
        arr[tmp] = 1;
    }
}