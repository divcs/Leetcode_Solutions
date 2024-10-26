#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//main solution function 
class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        if(root!=NULL)
        q.push({root, 0});
        while (!q.empty()) {
            Node* temp = q.front().first;
            int y = q.front().second;
            q.pop();
            if(!q.empty()){
                if(y==q.front().second)
                temp->next=q.front().first;
            }
            

            
            if (temp->left != NULL) {
                q.push({temp->left, y + 1});
            }
            if (temp->right != NULL) {
                q.push({temp->right, y + 1});
            }
            
        }
        return root;
    }
};