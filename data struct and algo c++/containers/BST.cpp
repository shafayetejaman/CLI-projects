#include <iostream>

using namespace std;

struct Tree
{
    int data;
    int index;
    Tree *right;
    Tree *left;
};

Tree *set(Tree *root, int data)
{
    static int index = 1;
    Tree *temp;
    try
    {
        temp = new Tree;
    }
    catch (const exception &e)
    {
        cout << "Error : " << e.what() << endl;
        delete root;
        exit(1);
    }

    temp->data = data;
    temp->index = index;
    temp->right = nullptr;
    temp->left = nullptr;
    index++;

    return temp;
}

void free_t(Tree *root)
{
    if (root != nullptr)
    {
        free_t(root->left);
        free_t(root->right);
        delete root;
    }
}

void print(Tree *root)
{
    if (root != nullptr)
    {
        print(root->left);
        // cout << "index[" << root->index << "]: " << root->data << endl;
        cout << " " << root->data;
        print(root->right);
    }
}
Tree *insert(Tree *root, int data)
{
    if (root == NULL)
        return set(root, data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

bool isBST(Tree *root)
{
    if (root != nullptr)
    {
        if (root->left != nullptr && root->left->data >= root->data)
            return false;
        if (root->right != nullptr && root->right->data <= root->data)
            return false;
        return isBST(root->left) && isBST(root->right);
    }
    return true;
}

bool search(Tree *root, int val)
{
    if (!isBST(root))
    {
        cout << "Not a BST tree" << endl;
        return false;
    }

    Tree *ptr = root;
    if (ptr != nullptr)
    {
        if (ptr->data == val)
        {

            cout << "the value is in index[" << ptr->index << "]" << endl;
            return true;
        }
        else if (ptr->data > val)
        {
            return search(ptr->left, val);
        }
        else
        {
            return search(ptr->right, val);
        }
    }
    return false;
}

Tree *in_order_pre(Tree *root)
{
    root = root->left;

    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

Tree *delete_t(Tree *root, int val)
{
    Tree *ip;
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    if (root->data > val)
    {
        root->left = delete_t(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = delete_t(root->right, val);
    }
    else
    {
        ip = in_order_pre(root);
        root->data = ip->data;
        root->left = delete_t(root->left, ip->data);
    }
    return root;
}

int main(void)
{
    Tree *root = new Tree;
    if (root == nullptr)
    {
        cout << "Error : cannot allocate" << endl;
        exit(1);
    }

    root->data = 5;
    root->index = 0;
    root->right = nullptr;
    root->left = nullptr;

    insert(root, 3);
    insert(root, 6);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 8);
    insert(root, 11);
    insert(root, 12);

    print(root);

    delete_t(root, 5);
    delete_t(root, 4);
    delete_t(root, 12);

    cout << endl;

    print(root);

    // search(root, 6);

    free_t(root);

    return 0;
}