#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
        string v;
        Node* r = nullptr;
        Node* l = nullptr;

    Node(string v) {
        this -> v = v;
    }

};

string search(string v, Node* root) {
    queue<Node*> q;
    q.push(root);
       
    while (q.size() > 0) {
        if (q.front() != nullptr) {
                if (q.front()->v == v) {
                    return v + " existe";
                }
            q.push(q.front()->r);
            q.push(q.front()->l);
        }
        q.pop();
    }

    return v + " nao existe";
}

vector<string> infixa_vector(Node* root) {
    vector<string> resultado;

    if (root->l != nullptr) { 
        for (string elemento: infixa_vector(root->l)) {
            resultado.push_back(elemento);
        }
    }
    resultado.push_back(root->v);
    
    if (root->r != nullptr) {
        for (string elemento: infixa_vector(root->r)) {
            resultado.push_back(elemento);
        }
    }

    return resultado;
}


vector<string> prefixa_vector(Node* root) {
    vector<string> resultado;

    resultado.push_back(root->v);
    if (root->l != nullptr) { 
        for (string elemento: prefixa_vector(root->l)) {
            resultado.push_back(elemento);
        }
    }
    
    if (root->r != nullptr) { 
        for (string elemento: prefixa_vector(root->r)) {
            resultado.push_back(elemento);
        }
    }

    return resultado;
}

vector<string> posfixa_vector(Node* root) {
    vector<string> resultado;

    if (root->l != nullptr) { 
        for (string elemento: posfixa_vector(root->l)) {
            resultado.push_back(elemento);
        }
    }
    
    if (root->r != nullptr) { 
        for (string elemento: posfixa_vector(root->r)) {
            resultado.push_back(elemento);
        }
    }

    resultado.push_back(root->v);
    
    return resultado;
}

int main() {
    Node* root = nullptr;
    string a; 
    string v;
    while (cin >> a) {
        if (a.size() == 1) {
            if (!(cin >> v)) {
                break;
            }
        }

        if (a == "I") {
            if (root == nullptr) { root = new Node(v); }
            else { 
                Node* current = root;
                bool added = false;
                while (!added) {
                    if (current->v >= v && current->l != nullptr) {
                        current = current->l;
                    } else if (current->v >= v) {
                        current->l = new Node(v);
                        added = true;
                    } else if (current->r != nullptr) {
                        current = current->r;
                    } else {
                        current->r = new Node(v);
                        added = true;
                    }
                    
                }
            }
        }

        else if (a == "P") {
            cout << search(v, root) << endl;
        }
        
        else if (a == "INFIXA") {
            vector<string> resultado = infixa_vector(root);

            for (int i = 0; i < resultado.size(); i++) {
                if (i != 0) {
                    cout << " ";
                }
                cout << resultado[i];
            }

            cout << endl;
        }

        else if (a == "PREFIXA") {
            vector<string> resultado = prefixa_vector(root);

            for (int i = 0; i < resultado.size(); i++) {
                if (i != 0) {
                    cout << " ";
                }
                cout << resultado[i];
            }

            cout << endl;
        }

        else if (a == "POSFIXA") {
            vector<string> resultado = posfixa_vector(root);

            for (int i = 0; i < resultado.size(); i++) {
                if (i != 0) {
                    cout << " ";
                }
                cout << resultado[i];
            }

            cout << endl;        
        }
    }

    return 0;
}




