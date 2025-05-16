#include <iostream>

using namespace std;
int main() {
    int t;
    cin >> t >> ws;
    
    for (int i = 0; i < t; i++) {
        string seq = "";
        string abrv = "";
        getline(cin, seq);

        for (int j = 0; j < seq.size(); j++) {
            if (j==0) abrv += seq[0];
            else if (seq[j-1] == ' ') abrv += seq[j];
        }

        cout << abrv << endl;
    }
}
