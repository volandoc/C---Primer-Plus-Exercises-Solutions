#include "workermi.h"

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename Type>
class QueueTP {
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    struct Node {
        Type item;
        struct Node * next;
    };
    enum {Q_SIZE = 10};
    // private class members
    Node * front; // pointer to front of Queue
    Node * rear; // pointer to rear of Queue
    int items; // current number of items in Queue
    const int qsize; // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    QueueTP(const QueueTP & q);
    QueueTP & operator=(const QueueTP & q) {
        return *this;
    }
public:
    explicit QueueTP(int qs = Q_SIZE) : qsize(qs), front(NULL), rear(NULL), items(0) {} // create queue with a qs limit
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type & item); // add item to end
    bool dequeue(Type & item); // remove item from front
};
#endif

template <typename Type>
QueueTP<typename Type>::~QueueTP() {
    Node * temp;
    while (front != NULL) { // while queue is not yet empty
        temp = front; // save address of front item
        front = front->next;// reset pointer to next item
        delete temp; // delete former front
    }
}

template <typename Type>
bool QueueTP<typename Type>::isempty() const {
    return items == 0;
}

template <typename Type>
bool QueueTP<typename Type>::isfull() const {
    return items == qsize;
}

template <typename Type>
int QueueTP<typename Type>::queuecount() const {
    return items;
}

// Add item to queue
template <typename Type>
bool QueueTP<typename Type>::enqueue(const Type & item) {
    if (isfull())
        return false;
    Node * add = new Node; // create node
    if (add == NULL)
        return false; // quit if none available
    add->item = item; // set node pointers
    add->next = NULL;
    items++;
    if (front == NULL) // if queue is empty,
        front = add; // place item at front
    else
        rear->next = add; // else place at rear
    rear = add; // have rear point to new node
    return true;
}
// Place front item into item variable and remove from queue
template <typename Type>
bool QueueTP<typename Type>::dequeue(Type & item) {
    if (front == NULL)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}