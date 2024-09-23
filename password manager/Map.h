#include <iostream>

using namespace std;

class Node // elements for the hashmap
{
public:
    string first, second;

    Node(const string &first, const string &second)
    {
        this->first = first;
        this->second = second;
    }
    Node() {}

    bool empty()
    {
        return first.empty();
    }
};
class ListNode
{
public:
    Node map;
    ListNode *next;

    ListNode(const string &first, const string &second)
    {
        this->map.first = first;
        this->map.second = second;
        this->next = nullptr;
    }
    ListNode(const string &first)
    {
        this->map.first = first;
        this->next = nullptr;
    }
};

class List // for handling duplicate hash of keys
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;

    List(const string &first, const string &second)
    {
        ListNode *newNode = new ListNode(first, second);
        if (newNode == nullptr)
        {
            cout << "Failed to add password!" << endl;
            return;
        }

        this->head = newNode;
        this->tail = newNode;
    }
    List() {}

    bool empty()
    {
        if (this->size == 0)
            return true;

        return false;
    }
    // inserting in the end of the link list
    string &append(const string &first)
    {
        ListNode *newNode = new ListNode(first);
        if (newNode == nullptr)
        {
            cout << "Failed to add password!" << endl;
        }
        else
        {

            if (this->head == nullptr)
            {
                this->head = newNode;
                this->tail = newNode;
            }
            else
            {
                this->tail->next = newNode;
                this->tail = this->tail->next;
            }
            this->size++;
            return newNode->map.second;
        }
        static string s;
        return s;
    }
    // deleting the node of the link list
    void delete_node(int index)
    {
        if (this->head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        ListNode *ptr = this->head;
        ListNode *prev = nullptr;

        if (index == 0)
        {
            this->head = ptr->next;
            delete ptr;
            this->size--;
            return;
        }
        else if (index >= this->size || index < 0)
        {
            cout << "Invalid Index!\n";
            return;
        }
        else if (index == this->size - 1)
        {
            while (ptr->next != nullptr)
            {
                prev = ptr;
                ptr = ptr->next;
            }

            prev->next = nullptr;
            this->tail = prev;

            delete ptr;
            this->size--;
            return;
        }

        while (ptr->next != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = ptr->next;
        this->size--;
        delete ptr;
    }
    int find(const string &key)
    {
        ListNode *ptr = this->head;
        int index = 0;
        while (ptr != nullptr)
        {
            if (ptr->map.first == key)
                return index;

            index++;
            ptr = ptr->next;
        }
        return -1;
    }
    void print()
    {
        for (auto i = this->head; i != nullptr; i = i->next)
        {
            cout << i->map.first << " : " << i->map.second << endl;
        }
    }
};

class Map
{
public:
    Node *arr;
    List list;
    int size;

    Map() // making the map
    {
        this->size = 1000000;
        arr = new Node[this->size];

        if (arr == nullptr)
        {
            cout << "Failed to add password!" << endl;
            return;
        }
    }
    // increasing or decreasing the map size
    void resize(const int &newSize)
    {
        Node *newNode = new Node[newSize];
        if (newNode == nullptr)
        {
            cout << "Failed to resize the array!" << endl;
            return;
        }
        for (auto i = 0; i < this->size; i++)
        {
            newNode[i] = arr[i];
        }
        delete[] arr; // freeing old map
        this->arr = newNode;
        this->size = newSize;
    }
    // printing the nodes of array
    void print()
    {
        for (auto i = 0; i < this->size; i++)
        {
            if (!this->arr[i].empty())
            {
                cout << this->arr[i].first << " : " << this->arr[i].second << endl;
            }
        }
    }
    // generating hash index
    int hash(const string &key)
    {
        int index = 0;
        int hashVal = 31; // prime number for better distribution
        int power = 1;

        for (auto &i : key)
        {
            index = (index + (i - '0' + 1) * power) % this->size; // decreasing the index by using mod

            power = (power * hashVal) % this->size;
        }
        return std::abs(index) % this->size;
    }
    // implementing operator overloading of hash map
    string &operator[](const string &key)
    {
        int index = hash(key);
        if (this->arr[index].empty()) // if there are no password was saved by the key
        {
            arr[index].first = key;
        }
        else // inserting new password in the list
        {
            return this->list.append(key);
        }

        return arr[index].second;
    }
    // finding the index of the list
    bool find(const string &key)
    {
        int index = hash(key);
        int pos = this->list.find(key);
        if (pos != -1 || this->arr[index].first == key)
        {
            return true;
        }
        return false;
    }
    // finding the index of the array
    int find_index_arr(const string &key)
    {
        int index = hash(key);

        if (this->arr[index].first == key)
        {
            return index;
        }
        return -1;
    }
    // deleting node from the link list
    bool delete_node(const string &key)
    {
        int pos = this->list.find(key);

        if (pos == -1)
        {
            pos = this->find_index_arr(key);
            if (pos == -1)
            {
                return false;
            }
            else
            {
                this->arr[pos].first.clear();
                this->arr[pos].second.clear();
            }
        }
        else
        {
            this->list.delete_node(pos);
        }
        return true;
    }

    bool empty()
    {
        for (auto i = 0; i < this->size; i++)
        {
            if (!this->arr[i].empty())
            {
                return false;
            }
        }
        return true;
    }
};