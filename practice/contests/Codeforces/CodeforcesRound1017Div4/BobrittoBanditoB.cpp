#include <iostream>
using namespace std;


int main() {
    int t, n, m, l, r;
    cin >> t;
    for (; t > 0; t--) {
        cin >> n >> m >> l >> r;
        int lalt = 0, ralt = 0;

        for (;m > 0; m--) {
            if (lalt < l && (ralt >= r || lalt * -1 < ralt) ) lalt --;
            else ralt++;
        }

        cout << lalt << " " << ralt << endl;
    }
}
