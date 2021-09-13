#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
    public:
        QueueArray();
        QueueArray (int _capacity);
        void enqueue(T data);
        T dequeue();
        void display();
        T& front();
        T& back();
};

template<typename T>
QueueArray<T>::QueueArray(): CircularArray<T>{0} {}

template<typename T>
QueueArray<T>::QueueArray(int _capacity): CircularArray<T>{_capacity} {}

template<typename T>
void QueueArray<T>::enqueue(T data) {
    this->push_back(data);
}

template<typename T>
T QueueArray<T>::dequeue() {
    return this->pop_front();
}

template<typename T>
void QueueArray<T>::display() {
    cout << this->to_string()<<endl;
}

template<typename T>
T &QueueArray<T>::front() {
    return (*this)[0];
}

template<typename T>
T &QueueArray<T>::back() {
    return (*this)[this->size() - 1];
}
