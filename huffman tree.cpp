#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For setw
using namespace std;

class node2 {
public:
    int value;
    char charr;
    string code;
    node2* left;
    node2* right;

    node2(int a, node2* left = nullptr, node2* right = nullptr, char charr = '\0') {
        value = a;
        this->charr = charr;
        this->left = left;
        this->right = right;
    }
};

class huffman {
private:
    vector<node2*> v1, v2;
    int num;

public:
    void getdata();
    void createtree();
    void huffmancode(node2* root, string str);
    void display();
};

void huffman::getdata() {
    cout << "Enter the number of entries: ";
    cin >> num;

    int value;
    char charr;
    cout << "NOTE - (Enter unique characters only)" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Character-" << (i + 1) << ": ";
        cin >> charr;
        cout << "Frequency-";
        cin >> value;

        node2* temp = new node2(value, nullptr, nullptr, charr);
        v2.push_back(temp);
        v1.push_back(temp);
    }

    sort(v1.begin(), v1.end(), [](node2* l, node2* r) { return l->value > r->value; });

    cout << "Character   Frequency" << endl;
    for (int i = 0; i < num; i++) {
        cout << v2[i]->charr << setw(14) << v2[i]->value << endl;
    }
}

void huffman::display() {
    cout << "Character   Frequency   Huffman Code" << endl;
    for (int i = 0; i < num; i++) {
        cout << v1[i]->charr << setw(12) << v1[i]->value << setw(14) << v1[i]->code << endl;
    }
}

void huffman::createtree() {
    if (v2.size() < 2) {
        cout << "Insufficient entities to create Huffman tree." << endl;
        return;
    }

    int sum;

    cout << endl << "Process" << endl;
    while (v2.size() != 1) {
        
        sort(v2.begin(), v2.end(), [](node2* l, node2* r) { return l->value > r->value; });
        for (auto x : v2) {
            cout << x->value<<setw(5);
        }
        cout<<"<-start"<<endl;

        sum = (v2.rbegin()[0]->value) + (v2.rbegin()[1]->value);
        node2* temp = new node2(sum);
        temp->left = v2.rbegin()[0];
        temp->right = v2.rbegin()[1];
        v2.pop_back();
        v2.pop_back();
        v2.push_back(temp);

        if (v2.size() == 1) {
            cout << endl;
            huffmancode(v2[0], "");
            return;
        }
    }
    cout << "No input" << endl;
}

void huffman::huffmancode(node2* root, string str) {
    if (root == nullptr) {
        cout << "Empty" << endl;
    } else if (root->left == nullptr) {
        root->code = str;
    } else {
        huffmancode(root->left, str + '0');
        huffmancode(root->right, str + '1');
    }
}

int main() {
    huffman h1;

    h1.getdata();

    h1.createtree();

    h1.display();

    return 0;
}

