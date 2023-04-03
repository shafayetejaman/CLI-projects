#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    int count;
    node *next;
    node(int data)
    {
        this->count = 1;
        this->data = data;
        this->next = nullptr;
    }

    node &push_back(int num)
    {
        node *temp = new node(num);
        node *ptr = this;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        this->count++;
        ptr->next = temp;
        return *this;
    }

    node &push_front(int num)
    {
        node *temp = new node(num);
        temp->next = this;
        return *temp;
    }
    int size()
    {
        return this->count;
    }


    node &print()
    {
        node *ptr = this;

        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
        return *this;
    }

    bool search(int key)
    {
        node *ptr = this;

        while (ptr->next != nullptr)
        {
            if (ptr->data == key)
                return true;
            ptr = ptr->next;
        }
        if (ptr->data == key)
            return true;

        return false;
    }

    node &delete_node(int key)
    {
        if (this->next == nullptr)
        {
            cout << "unable to delete" << endl;
            return *this;
        }
        node *ptr = this;
        node *pre = nullptr;

        while (ptr != nullptr)
        {
            if (ptr->data == key)
            {
                if (pre == nullptr)
                {
                    node *new_head = this;
                    *this = *(this->next);
                    delete new_head;
                    break;
                }
                else
                {
                    pre->next = ptr->next;
                    delete ptr;
                    break;
                }
            }
            pre = ptr;
            ptr = ptr->next;
        }
        this->count--;
        return *this;
    }

    node &reverse()
    {
        node *pre = nullptr;
        node *curr = this;
        node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return *pre;
    }
};

node *reverse_k(node *head, int k)
{
    node *pre = nullptr;
    node *curr = head;
    node *next = nullptr;

    int count = 0;
    while (count < k && curr != nullptr)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        count++;
    }
    if (next != nullptr)
    {
        head->next = reverse_k(next, k);
    }
    return pre;
}

void print(node *ptr)
{
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    node list(1);
    node *str0 = new node(1);
    node *str1 = new node(2);
    node *str2 = new node(3);
    node *str3 = new node(4);
    node *str4 = new node(5);

    str0->next = str1;
    str1->next = str2;
    str2->next = str3;
    str3->next = str4;
    str4->next = nullptr;
    list.push_back(2).push_back(3).push_back(4).push_back(5).print();

    // list.push_back(5).push_front(0).push_front(-1).print();
    // list.delete_node(-1).delete_node(5).delete_node(1).print();
    // list.reverse().print();
    node *ans = reverse_k(str0, 2);
    print(ans);
    cout << list.size();
    list.delete_node(3);
    cout << list.size();
    

    // cout << list.search(10) << endl;

    return 0;
}
