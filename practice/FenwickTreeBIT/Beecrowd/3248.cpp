#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n = 0) : n(_n), bit(n + 1) {}

    void update(int i, ll x) { 
        for (i ++; i <= n; i = i & -i) bit[i] += x; 
    }
   
    ll pref(int i) {
        ll ret = 0;
        for (i ++; i; i -= i & -i) ret += bit[i];
        return ret;
    }

};

int main() {
    int s; 

    cin >> s;
    int numbers[s];
    for (int t = 0; t < s; t++) {
         cin >> numbers[t];

    }

}
