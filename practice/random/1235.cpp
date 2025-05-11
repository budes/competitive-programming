#include <iostream>

using namespace std;

int main() {
    string input;
    
    int n;
    cin >> n;
    
    cin.ignore(256, '\n');  
    for (int j = 0; j < n; j++) {
        
        getline(cin, input);
        string msg = "";

        for (int i = input.size() / 2 - 1; i >= 0; i--) {
            msg += input[i];
        }
        for (int i = input.size() - 1; i >= input.size()/2; i--) {
            msg += input[i];
        }

        cout << msg << endl;
    }
}


