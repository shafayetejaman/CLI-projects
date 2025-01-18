#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* make_tree(priority_queue<int>& pq)
{
    queue<Node*> que;
    int i;
    cin >> i;
    if (i == -1) return nullptr;

    Node* root = new Node(i);
    que.push(root);
    pq.push(root->data);

    while (!que.empty())
    {
        Node* curr = que.front();
        que.pop();

        Node* left = nullptr;
        Node* right = nullptr;


        cin >> i;
        if (i != -1)
        {
            left = new Node(i);

            que.push(left);
            pq.push(left->data);


        }

        cin >> i;
        if (i != -1)
        {
            right = new Node(i);

            que.push(right);
            pq.push(right->data);

        }
        curr->left = left;
        curr->right = right;
    }
    return root;
}

int main()
{
    priority_queue<int> pq;
    make_tree(pq);

    int query;
    cin >> query;
    while (query--)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int val;
            cin >> val;
            pq.push(val);
        }
        else
        {
            cout << pq.top() << endl;
            pq.pop();
        }

    }


    return 0;
}