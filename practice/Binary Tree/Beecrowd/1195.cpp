#include <iostream>
#include <stack>

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

void infixo(Node* root) {
    if (root == nullptr) {
        return; 
    }

    infixo(root->left);
    
    cout << " " << root->value;

    infixo(root->right);
}

void posfixo(Node* root) {
    if (root == nullptr) {
        return; 
    }

    posfixo(root->left);
    posfixo(root->right);
    
    cout << " " << root->value;

}
int main() {
    int C, N;

    cin >> C;

    for (int i = 0; i < C; i++) {
        
        cout << "Case " << i + 1 << ":" << endl;
        cin >> N;
        
        Node* root;
        int v;

        cin >> v;
        root = new Node(v);

        for (int j = 1; j < N; j++) {
            cin >> v;
            root->insert(v);
        }
    
        Node* curr;
        stack<Node*> valores;
        
        // PREFIXO
        cout << "Pre.:";
        valores.push(root);
       
        while (valores.size() > 0) {
            curr = valores.top();
            valores.pop();
            
            if (curr->right != nullptr) {
                valores.push(curr->right);
            }
            if (curr->left != nullptr) {
                valores.push(curr->left);
            }
            cout << " " << curr->value; 
        }

        cout << endl;
        
        // INFIXO
        cout << "In..:";
        infixo(root);   
        cout << endl;
        
        // POSFIXO
        cout << "Post:";
        posfixo(root);
        cout << endl;
        cout << "\n";
    }
    return 0;
}


   
