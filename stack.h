#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
    public:
        StackArray();
        StackArray (int _capacity);
        void push(T data);
        T pop();
        T& top();
        void display();
};

template<typename T>
StackArray<T>::StackArray(): CircularArray<T>{0} {}

template<typename T>
StackArray<T>::StackArray(int _capacity): CircularArray<T>{_capacity} {}

template<typename T>
void StackArray<T>::push(T data) {
    this->push_back(data);
}

template<typename T>
T StackArray<T>::pop() {
    return this->pop_back();
}

template<typename T>
void StackArray<T>::display() {
    cout << this->to_string()<<endl;
}

template<typename T>
T& StackArray<T>::top() {
    return (*this)[this->size() - 1];
}


