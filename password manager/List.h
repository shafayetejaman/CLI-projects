#include <iostream>

using namespace std;

// Node class to represent individual elements in the list
template <typename T, typename Y>
class Node
{
public:
    T key;      // The key of the node
    Y val;      // The value associated with the key
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a new node with given key and value
    Node(const T &key, const Y &val)
    {
        this->key = key;
        this->val = val;
        this->next = nullptr;
    }
};

// List class to implement a singly linked list
template <typename T, typename Y>
class List
{
public:
    Node<T, Y> *head; // Pointer to the head (first element) of the list
    Node<T, Y> *tail; // Pointer to the tail (last element) of the list

    // Constructor to initialize an empty list
    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Method to append a new node with the given key and value to the end of the list
    Node<T, Y> *append(const T &key, const Y &val = Y())
    {
        Node<T, Y> *newNode;
        try
        {
            newNode = new Node<T, Y>(key, val);
        }
        catch (const bad_alloc &e)
        {
            cout << "ERROR : " << e.what() << "!" << endl;
            exit(-1);
        }

        if (this->head == nullptr) // If the list is empty
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;    // Attach the new node to the current tail
            this->tail = this->tail->next; // Update the tail to be the new node
        }

        return newNode;
    }

    // Method to find and return the first node with the given key, if it exists in the list
    Node<T, Y> *find(const T &key)
    {
        Node<T, Y> *temp = this->head;
        while (temp)
        {
            if (temp->key == key)
            {
                return temp; // Return the node if the key is found
            }
            temp = temp->next;
        }
        return nullptr; // Return nullptr if the key is not found in the list
    }

    // Method to erase the first occurrence of the node with the given key in the list
    bool erase(const T &key)
    {
        Node<T, Y> *temp = this->head;
        if (!head)
            return false;

        if (temp && temp->key == key) // If the key is found in the head node
        {
            this->head = temp->next; // Update the head to the next node
            if (this->tail == temp)  // If the head was also the tail (only one node in the list)
            {
                this->tail = nullptr;
            }
            delete temp; // Delete the old head node
            return true;
        }
        else // If the key is not in the head node
        {
            while (temp->next && temp->next->key != key)
            {
                temp = temp->next; // Traverse the list to find the node with the given key
            }
            if (temp->next && temp->next->key == key && temp->next == this->tail) // If the key is in the tail node
            {
                Node<T, Y> *deleteNode = this->tail;
                this->tail = temp;    // Update the tail to the previous node
                this->tail->next = nullptr; // Set the next pointer of the new tail to nullptr
                delete deleteNode;    // Delete the old tail node
                return true;
            }
            else if (temp->next && temp->next->key == key) // If the key is in a node in between
            {
                Node<T, Y> *deleteNode = temp->next;
                temp->next = temp->next->next; // Update the next pointer to skip the node with the given key
                delete deleteNode;             // Delete the node with the given key
                return true;
            }
        }
        return false; // Return false if the key is not found in the list
    }
};
