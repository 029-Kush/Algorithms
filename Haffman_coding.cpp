#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    char letter;
    int freq;
    Node *left, *right;

    Node(char d, int f){
        left = right = NULL;
        letter = d;
        freq = f;
    }
};

struct Compare{
    bool operator()(Node* l, Node* r){
        return (l->freq > r->freq);
    }
};

void print(Node* root, string str){
    if(root != NULL){
        if(root->letter != '*'){
            cout << root->letter << " : " << str << endl;
        }

        print(root->left, str + "0");
        print(root->right, str + "1");
    }
}

void huff(char data[], int freq[], int n){
    Node *lchild, *rchild;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(int i = 0; i < n; i++){
        pq.push(new Node(data[i], freq[i]));
    }

    while(pq.size() != 1){
        lchild = pq.top();
        pq.pop();

        rchild = pq.top();
        pq.pop();

        Node* temp = new Node('*', lchild->freq + rchild->freq);
        temp->left = lchild;
        temp->right = rchild;

        pq.push(temp);
    }

    print(pq.top(), "");
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {10, 5, 2, 14, 15};
    int n = 5;

    huff(arr, freq, n);
    return 0;
}