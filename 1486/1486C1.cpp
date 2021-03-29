//# Author : godgiyeon =========================#
//# Problem Title : Guessing the Greatest (easy version) #
//# Time Stamp : 2021-03-10T10:18:26 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>

using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int k; cin >> k;
    return k;
}

int main() {
    int n; cin >> n;
    int k = query(1, n);
    int left, right;
    bool flag = true;
    if(k == 1 || query(1, k) != k) {
        left = k; right = n;
        flag = false;
    }
    else {
        left = 1; right = k;
    }
    if (flag) {
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            int x = query(mid, k);
            if(x != k) right = mid;
            else left = mid;
        }
        cout << "! " << left;
    }
    else {
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            int x = query(k, mid);
            if(x != k) left = mid;
            else right = mid;
        }
        cout << "! " << right;
    }

}