#include <iostream>

using namespace std;

// QueueNode class to represent individual nodes in the Queue
template <typename T>
class QueueNode
{
public:
    T data;          // Data stored in the node
    QueueNode *next; // Pointer to the next node in the Queue
    QueueNode *prev; // Pointer to the previous node in the Queue

    // Constructor to initialize the QueueNode with given data
    QueueNode(const T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Queue class to implement a doubly linked list based Queue
template <typename T>
class Queue
{
private:
    QueueNode<T> *frontNode; // Pointer to the front (head) node of the Queue
    QueueNode<T> *backNode;  // Pointer to the back (tail) node of the Queue
    int elementSize;         // Size of the Queue

public:
    // Constructor to create a Queue with one element
    Queue(T data)
    {
        QueueNode<T> *newNode;
        try
        {
            newNode = new QueueNode<T>(data);
        }
        catch (const bad_alloc &e)
        {
            cout << "ERROR : " << e.what() << "!" << endl;
            exit(-1);
        }

        this->frontNode = newNode;
        this->backNode = newNode;
        this->elementSize++;
    }

    // Default constructor to create an empty Queue
    Queue()
    {
        this->frontNode = nullptr;
        this->backNode = nullptr;
        this->elementSize = 0;
    }

    // Pushes an element to the back of the Queue
    void push(T data)
    {
        QueueNode<T> *newNode;
        try
        {
            newNode = new QueueNode<T>(data);
        }
        catch (const bad_alloc &e)
        {
            cout << "ERROR : " << e.what() << "!" << endl;
            exit(-1);
        }

        if (this->frontNode == nullptr) // If the Queue is empty
        {
            this->frontNode = newNode;
            this->backNode = newNode;
            this->elementSize++;
        }
        else
        {
            // Adding the new node at the back of the Queue
            this->backNode->next = newNode;
            newNode->prev = this->backNode;
            this->backNode = newNode;
            this->elementSize++;
        }
    }

    // Removes and returns the front element of the Queue
    T pop()
    {
        if (this->frontNode == nullptr) // If the Queue is empty
        {
            return nullptr;
        }
        QueueNode<T> *temp = this->frontNode;
        if (this->frontNode == this->backNode) // If there is only one element in the Queue
        {
            this->frontNode = nullptr;
            this->backNode = nullptr;
        }
        else
        {
            // Removing the front node and updating the frontNode pointer
            this->frontNode = this->frontNode->next;
            this->frontNode->prev = nullptr;
        }
        T data = temp->data;
        delete temp; // Deallocate the memory of the removed node
        this->elementSize--;
        return data;
    }

    // Returns the front element of the Queue without removing it
    T front()
    {
        return this->frontNode->data;
    }

    // Returns the back element of the Queue without removing it
    T back()
    {
        return this->backNode->data;
    }

    // Checks if the Queue is empty
    bool empty()
    {
        if (this->frontNode == nullptr)
        {
            return true;
        }
        return false;
    }

    // Returns the current size of the Queue
    int size()
    {
        return elementSize;
    }
};
