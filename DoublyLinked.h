#pragma once

/**
 * DoublyLinked Template class ( + insertionSort method included)
 * @author : Hawon Oh
 * @version: 1.2
 */
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

template<typename T>
class DoublyLinked
{
private:
    // main pointers
    Node<T>* headPtr, * tailPtr;
    int count;
public:
    // constructor
    DoublyLinked<T>();
    // copy constructor
    DoublyLinked<T>(const DoublyLinked<T>* list);
    // destructor to release allocated memory
    ~DoublyLinked();
    // add one element at the front of the list
    void push_front(T data);
    // add one element at the back of the list
    void push_back(T data);
    // get the element at position index
    bool at(int index, T& val);
    // locates the item at the index and removes it from the list
    bool deleteNode(int index);
    // displaying all the elements of the list
    void display();
    // determines whether the list is empty
    bool isEmpty();
    // returns the length of the list
    int size();
    // deletes all instances of given value from the linked list
    void deleteItem(T val);
    // removes the first element and returns the value
    bool pop_front(T& val);
    // removes the last element and returns the value
    bool pop_back(T& val);
    // reverse all the nodes of the doubly linked list
    bool reverse();
    // search value and return vector variable containing all found indices
    vector<int> search(T val);


};





// constructor
template<typename T>
DoublyLinked<T>::DoublyLinked()
{
    headPtr = nullptr;
    tailPtr = nullptr;
    count = 0;
}

// (deep) copy constructor
template<typename T>
DoublyLinked<T>::DoublyLinked(const DoublyLinked<T>* list)
{
    // if empty, return
    if (list->headPtr == nullptr)
    {
        this->headPtr = nullptr;
        this->tailPtr = nullptr;
        this->count = 0;

        return;
    }

    // pointer to the head of the list that will be copied
    Node<T>* current = list->headPtr;

    // copy the list's nodes
    while (current != nullptr)
    {
        this.push_back(current->data);
        current = current->next;

        count++;
    }
}

// destructor to release allocated memory
template<typename T>
DoublyLinked<T>::~DoublyLinked()
{
    Node<T>* currentPtr = headPtr;
    Node<T>* tempPtr = nullptr;

    while (currentPtr != nullptr)
    {
        tempPtr = currentPtr->next;
        delete currentPtr;
        currentPtr = tempPtr;
        count--;
    }
    headPtr = nullptr;
    tailPtr = nullptr;
    count = 0;
}

// add one element at the front of the list
template<typename T>
void DoublyLinked<T>::push_front(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->prev = nullptr;

    // is the list empty, then headPtr should point to the newNode
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
        newNode->next = nullptr;
        count = 1;
    }
    else // otherwise, navigate to the first node of the list
    {
        newNode->next = headPtr;
        headPtr->prev = newNode;
        headPtr = newNode;
        count++;
    }
}

// add one element at the back of the list
template<typename T>
void DoublyLinked<T>::push_back(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;

    // is the list empty, then headPtr should point to the newNode
    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
        count = 1;
    }
    else // otherwise, add the new node at the tail
    {
        tailPtr->next = newNode;
        newNode->prev = tailPtr;
        tailPtr = newNode;
        count++;
    }
}

// get the element at position index
template<typename T>
bool DoublyLinked<T>::at(int index, T& val)
{
    Node<T>* current = headPtr;

    if (index >= count || index < 0)
        return false;

    if (index == 0)
    {
        val = headPtr;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        val = current;
    }
    return true;
}

// Delete item at the given index from the list
template<typename T>
bool DoublyLinked<T>::deleteNode(int index)
{
    // check validation of the index and the list
    if (count <= index || count < 1 || index < 0 || headPtr == nullptr)
    {
        return false;
    }

    // find index of median of list
    int median_index = (int)count / 2;

    Node<T>* tempPtr;
    Node<T>* tempPrev;
    Node<T>* tempNext;

    // when it's headPtr
    if (index == 0)
    {
        tempPtr = headPtr;
        headPtr = headPtr->next;
        headPtr->prev = nullptr;
        delete tempPtr;

        count--;

        if (count == 0)
            tailPtr = nullptr;
    }
    // starting from head
    else if (index < median_index)
    {
        tempPtr = headPtr;

        // find the index
        for (int i = 0; i < index; i++)
        {
            tempPtr = tempPtr->next;
        }

        // set prev & next assuming tempPtr will be deleted
        tempPrev = tempPtr->prev;
        tempNext = tempPtr->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;

        delete tempPtr;
    }
    // when it's tailPtr
    else if (index == count - 1)
    {
        // or just use pop_back
        tempPtr = tailPtr;
        tailPtr = tailPtr->prev;
        tailPtr->next = nullptr;
        delete tempPtr;
    }
    // starting from tail
    else
    {
        tempPtr = tailPtr;
        for (int i = count - 1; i > index; i--)
        {
            tempPtr = tempPtr->prev;
        }

        tempPrev = tempPtr->prev;
        tempNext = tempPtr->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;

        delete tempPtr;
    }

}

// displaying all the elements of the list
template<typename T>
void DoublyLinked<T>::display()
{
    Node<T>* current = headPtr;

    if (headPtr == nullptr)
    {
        cout << "Empty" << endl;
    }

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// determines whether the list is empty
template<typename T>
bool DoublyLinked<T>::isEmpty()
{
    if (count == 0)
        return true;
    return false;
}
// returns the size of the list
template<typename T>
int DoublyLinked<T>::size()
{
    return count;
}

// deletes all the elements of the linked list
template<typename T>
void DoublyLinked<T>::deleteItem(T val)
{
    // check if it's empty
    if (headPtr == nullptr)
    {
        return;
    }

    Node<T>* current = headPtr;

    vector<int> all_thing_to_be_deleted = search(val);
    int deletion_count = 0;

    for (const int& i : all_thing_to_be_deleted)
    {
        deleteNode(i - deletion_count);
        deletion_count++;
    }
}

// removes the first element and returns the value
template<typename T>
bool DoublyLinked<T>::pop_front(T& val)
{
    if (headPtr == nullptr)
    {
        return false;
    }

    // stor value
    val = headPtr->data;

    Node<T>* tempPtr = headPtr;
    headPtr = headPtr->next;
    if (headPtr != nullptr)
    {
        headPtr->prev = nullptr;
    }


    delete tempPtr;
    count--;

    return true;
}

// removes the last element and returns the value
template<typename T>
bool DoublyLinked<T>::pop_back(T& val)
{
    // or "if(count == 0)"
    if (tailPtr == nullptr)
    {
        return false;
    }

    // store value
    val = tailPtr->data;

    Node<T>* tempPtr = tailPtr;

    tailPtr = tailPtr->prev;
    tailPtr->next = nullptr;

    delete tempPtr;
    count--;
}

// reverse the contents of the doubly linked list
template<typename T>
bool DoublyLinked<T>::reverse()
{
    // when the list contains nothing or one node
    if (count == 0 || count == 1)
    {
        return false;
    }

    // swap head and tail
    Node<T>* hNode = headPtr;
    Node<T>* tNode = tailPtr;

    T temp;
    int median_index = (int)count / 2;

    for (int i = 0; i < median_index; i++)
    {
        // swap
        temp = hNode->data;
        hNode->data = tNode->data;
        tNode->data = temp;

        // move pointers to next or prev nodes
        hNode = hNode->next;
        tNode = tNode->prev;
    }
}

// search value and return all indices containing the equal value
template<typename T>
vector<int> DoublyLinked<T>::search(T val)
{
    vector<int> indices;

    Node<T>* current = headPtr;
    int i = 0;

    while (current != nullptr)
    {
        if (val == current->data)
        {
            indices.push_back(i);
        }
        current = current->next;
        i++;
    }

    return indices;
}
