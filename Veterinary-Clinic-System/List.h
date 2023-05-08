#ifndef LIST_H
#define LIST_H

#include "CompareBehaviour.h"

template <typename T>
class List;

/*
  Class:    Node
  Purpose:  Uses templating to manage nodes for doubly-linked lists.
*/

template <typename T>
class Node {
  friend class List<T>;
  template <typename V>
  friend ostream& operator<<(ostream& output, List<V>& list);

  private:
    T* data;
    Node<T>* next;
    Node<T>* prev;
};

/*
  Class:    List
  Purpose:  Uses templating to manage doubly-linked lists of object pointers.
*/

template <typename T>
class List {
  template <typename V>
  friend ostream& operator<<(ostream& output, List<V>& list);

  public:
    List();
    ~List();
    bool add(T* obj);
    virtual bool find(int id, T** foundObj);
    void convertToArray(T** arr, int& size);
    void cleanupData();
    void setBehaviour(CompareBehaviour<T>* cmp);

  private:
    Node<T>* head;
    CompareBehaviour<T>* behaviour;

};



template <class T>
List<T>::List() : head(NULL), behaviour(NULL) { }

template <class T>
List<T>::~List() {  //deallocate nodes, but not data
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
  
  delete behaviour;
}

template <class T>
bool List<T>::add(T* obj) {
  if (behaviour == NULL) {
    return false;
  }

  Node<T>* currNode;
  Node<T>* prevNode;
  Node<T>* newNode;

  newNode = new Node<T>;
  newNode->data = obj;
  newNode->next = NULL;
  newNode->prev = NULL;
  
  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (behaviour->compare(newNode->data, currNode->data)) {
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = newNode;
  }
  else {
    newNode->prev = prevNode;
    prevNode->next = newNode;
  }

  if (currNode != NULL) {
    currNode->prev = newNode;
  }

  newNode->next = currNode;
  return true;
}

template <class T>
bool List<T>::find(int id, T** foundObj) {
  Node<T>* currNode = head;

  while (currNode != NULL) {
    if (currNode->data->getId() == id) {
      *foundObj = currNode->data;
      return true;
    }
    currNode = currNode->next;
  }

  return false;
}

template <class T>
void List<T>::convertToArray(T** arr, int& size) {
  Node<T>* currNode = head;

  while (currNode != NULL) {
    arr[size] = currNode->data;
    currNode = currNode->next;
    size++;
  }
}

template <class T>
void List<T>::cleanupData() {
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}

template <class T>
void List<T>::setBehaviour(CompareBehaviour<T>* cmp) {
  behaviour = cmp;
}

template <class V>
ostream& operator<<(ostream& output, List<V>& list) {
  Node<V>* currNode = list.head;
  output << "--- FORWARD:\n";
  while (currNode != NULL) {
    output << *(currNode->data) << "\n";
    if (currNode->next == NULL) {
      break;
    }
    else {
      currNode = currNode->next;
    }
  }

  output << "--- BACKWARD:\n";
  while (currNode != NULL) {
    output << *(currNode->data) << "\n";
    currNode = currNode->prev;
  }

  return output;
}

#endif