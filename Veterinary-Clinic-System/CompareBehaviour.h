#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
  Class:    CompareBehaviour
  Purpose:  Base class for behaviour comparison hierarchy of class templates.
*/

template <typename T>
class CompareBehaviour {
  public:
    CompareBehaviour(bool ascending);
    virtual ~CompareBehaviour();
    virtual bool compare(T* obj1, T* obj2) = 0;

  protected:
    bool asc;
};

/*
  Class:    CompareAge
  Purpose:  Derived class in which the behaviour of comparing ages is managed.
*/

template <typename T>
class CompareAge : public CompareBehaviour<T> {
  public:
    CompareAge(bool ascending);
    virtual ~CompareAge();
    virtual bool compare(T* obj1, T* obj2);
};

/*
  Class:    CompareDate
  Purpose:  Derived class in which the behaviour of comparing dates is managed.
*/

template <typename T>
class CompareDate : public CompareBehaviour<T> {
  public:
    CompareDate(bool ascending);
    virtual ~CompareDate();
    virtual bool compare(T* obj1, T* obj2);
};



template <class T>
CompareBehaviour<T>::CompareBehaviour(bool ascending) : asc(ascending) { }

template <class T>
CompareBehaviour<T>::~CompareBehaviour() { }


template <class T>
CompareAge<T>::CompareAge(bool ascending) : CompareBehaviour<T>(ascending) { }

template <class T>
CompareAge<T>::~CompareAge() { }

template <class T>
bool CompareAge<T>::compare(T* obj1, T* obj2) {
  if (this->asc) {
    return obj1->getAge() < obj2->getAge();
  }
  else {
    return obj1->getAge() > obj2->getAge();
  }
}


template <class T>
CompareDate<T>::CompareDate(bool ascending) : CompareBehaviour<T>(ascending) { }

template <class T>
CompareDate<T>::~CompareDate() { }

template <class T>
bool CompareDate<T>::compare(T* obj1, T* obj2) {
  if (this->asc) {
    return obj1->getDate() < obj2->getDate();
  }
  else {
    return obj1->getDate() > obj2->getDate();
  }
}

#endif