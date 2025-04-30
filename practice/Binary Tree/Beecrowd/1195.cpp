#include <iostream>
using namespace std;

class Node{

    public: 
        Node* right = nullptr;
        Node* left = nullptr;
        int value;

    Node(int value) {
        this->value = value;
    }

    void insert(int value) {
        if (value > this->value) {
            if (this->right == nullptr) { this->right = new Node(value); }
            else { this->right->insert(value); }
        } else {
            if (this->left == nullptr) { this->left = new Node(value); }
            else { this->left->insert(value); }
        }
    }
};


int main() {
    int C, N;

    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> N;
        int seq[N];

    }
    
    return 0;
}

