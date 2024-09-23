#include "List.h"
#include "Queue.h"

template <typename T, typename Y>
class Map
{
private:
    int lambda;                // Load factor for resizing the map
    int arraySize;             // Current size of the array
    int elements;              // Number of elements in the map
    List<T, Y> *array;         // Array of linked lists to store key-value pairs
    Queue<Node<T, Y> *> queue; // Queue used for iterating over elements in the map
    bool queFlag;              // Flag to indicate if the queue needs to be updated

    // Hash function to calculate the index for a given key in the array
    int hash_val(const T &key, const int Size)
    {
        hash<T> stringHash;
        return abs(int(stringHash(key))) % Size;
    }

public:
    // Constructor
    Map(const int lambda = 10, const int arraySize = 10)
    {
        this->lambda = lambda;
        this->arraySize = arraySize;
        this->elements = 0;
        queFlag = true;

        try
        {
            array = new List<T, Y>[this->arraySize]; // Initialize an array of linked lists
        }
        catch (const bad_alloc &e)
        {
            cout << "ERROR : " << e.what() << "!" << endl;
            exit(-1);
        }
    }

    // Find a key in the map and return the corresponding node
    Node<T, Y> *find(const T &key)
    {
        int index = hash_val(key, this->arraySize);
        return array[index].find(key);
    }

    // Overloaded subscript operator to access and modify elements in the map
    Y &operator[](const T &key)
    {
        this->queFlag = true;
        Node<T, Y> *node = find(key);
        if (node)
        {
            return node->val; // If key exists, return its value
        }
        else
        {
            // If key doesn't exist, add a new node with the given key and return its value
            Node<T, Y> *newNode = array[hash_val(key, this->arraySize)].append(key);
            this->elements++;

            // Check if the map needs to be resized based on the load factor (lambda)
            if (this->elements / this->arraySize > this->lambda)
            {
                resize();
            }
            return newNode->val;
        }
    }

    // Return the number of elements in the map
    int size()
    {
        return this->elements;
    }

    // Erase a key from the map and update the number of elements
    bool erase(const T &key)
    {
        if (this->array[hash_val(key, this->arraySize)].erase(key))
        {
            this->elements--;
            this->queFlag = true;
            return true; // Key was successfully erased
        }

        return false; // Key was not found
    }

    // Resize the map to a new size (default size is current size * 2)
    void resize(const int size = 0)
    {
        int newLambda = this->lambda * 2;
        int newSize;

        if (size == 0)
            newSize = this->arraySize * 2; // Double the size if not specified
        else
            newSize = size;

        List<T, Y> *newArray;
        try
        {
            newArray = new List<T, Y>[newSize]; // Create a new array with the new size
        }
        catch (const bad_alloc &e)
        {
            cout << "ERROR : " << e.what() << "!" << endl;
            exit(-1);
        }

        // Rehash all elements to the new array
        for (auto i = 0; i < this->arraySize; i++)
        {
            List<T, Y> &list = this->array[i];
            Node<T, Y> *head = list.head;

            while (head)
            {
                int index = hash_val(head->key, newSize);
                Node<T, Y> *newNode = newArray[index].append(head->key);
                newNode->val = head->val;
                head = head->next;
            }
        }

        // Clean up the old array and update class members with the new values
        for (auto i = 0; i < this->arraySize; i++)
        {
            List<T, Y> &list = this->array[i];

            while (list.head)
            {
                list.erase(list.tail->key);
            }
        }

        delete[] this->array;
        this->array = newArray;
        this->arraySize = newSize;
        this->lambda = newLambda;
    }
    // for deleting the hole map
    void clear()
    {
        for (auto i = 0; i < this->arraySize; i++)
        {
            List<T, Y> &list = this->array[i];

            while (list.head)
            {
                list.erase(list.tail->key);
            }
        }
        delete[] this->array;
    }

    // Check if the map is empty
    bool empty()
    {
        return (this->size() == 0);
    }

    // Get the next element in the map using a queue-based iteration
    Node<T, Y> *next()
    {
        if (this->queFlag)
        {
            // If queFlag is true, update the queue with all elements in the map
            for (auto i = 0; i < this->arraySize; i++)
            {
                const List<T, Y> &list = array[i];
                Node<T, Y> *head = list.head;

                while (head)
                {
                    queue.push(head);
                    head = head->next;
                }
            }
            this->queFlag = false;
        }

        // Return the next node in the queue (if available)
        if (!queue.empty())
        {
            return queue.pop();
        }
        this->queFlag = true;
        return nullptr; // Return nullptr if the queue is empty
    }
};
