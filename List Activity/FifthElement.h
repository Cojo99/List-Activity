//
// Created by Connor Jones on 2/21/23.
//

#ifndef CS2420_INCLASS_FIFTHELEMENT_H
#define CS2420_INCLASS_FIFTHELEMENT_H

#include "LinkedList.h"

template <class T>
class FifthElement : public LinkedList<T> {

public:
    T getFifthElement();
    void insertNewFifthElement(const T&value);
    void deleteFifthElement();
    void swapFourthAndFifthElement(); //switch/rearrange pointers, not the data that is being pointed to

private:

};

template <class T>
T FifthElement<T>::getFifthElement() //returns data at 5th element
{
    auto temp = LinkedList<T>::front;

    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            return temp->value;
        }
        temp = temp->next;
        if (temp == nullptr) {
            throw runtime_error("Out of list bounds.");
        }
    }
    return temp->value;
}

template <class T>
void FifthElement<T>::insertNewFifthElement(const T &value) //inserts a node between existing nodes 4 and 5(5->6
{

    auto newFifth = new Node<T>(value);
    auto temp = LinkedList<T>::front;
    bool flag = true;

    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            flag = false;
            break;
        }
        temp = temp->next;
    }
    if (!flag) {
        auto aux = temp->next;
        temp->next = newFifth;
        newFifth->next = aux;
    }
}

template <class T>
void FifthElement<T>::deleteFifthElement() //deletes 5th node, if there are 6 nodes, 4 will point to 6. if 5th is last, 4 ->new back node
{
    auto temp = LinkedList<T>::front;
    bool flag = true;

    for (int i = 0; i < 4; i++) {
        if (i == 3) {

            flag = false;
            break;
        }
        temp = temp->next;
    }
    if (!flag) {

        auto aux = temp->next;
        temp->next = aux->next;
    }
}

template <class T>
void FifthElement<T>::swapFourthAndFifthElement() //rearranges 4 and 5 nodes. swap pointers, not data
{
    auto temp = LinkedList<T>::front;
    bool flag = true;

    for (int i = 0; i < 3; i++) {
        if (i == 2) {

            flag = false;
            break;
        }
        temp = temp->next;
    }
    if (!flag) {

        auto third = temp->next;
        auto fourth = third->next;
        auto fifth = fourth->next;
        temp->next = fourth;
        fourth->next = third;
        third->next = fifth;
    }
}





#endif //CS2420_INCLASS_FIFTHELEMENT_H
