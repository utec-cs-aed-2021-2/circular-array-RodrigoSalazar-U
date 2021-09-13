#include <iostream>
using namespace std;

// Utility function
template <class T>
void  swap (T *p1,T *p2){
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Base code
template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int pos);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);

    void mergesort(const int begin, const int end);

    void merge(const int left, int mid, const int right);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}




// Completing methods
template<class T>
bool CircularArray<T>::is_empty() {
    return (this->front == -1 && this->back == -1);
}

//
template<class T>
bool CircularArray<T>::is_full() {
    return ( next(back) == front);
}

template<class T>
int CircularArray<T>::size() {
    if (front == -1 && back == -1) {
        return 0;
    }
    return (back >= front) ? back-front+1 : capacity - (front-back) + 1;
}


template<class T>
void CircularArray<T>::push_front(T data) {
    if (this->is_empty()){
        front=0;
        back=0;
        array[0] = data;
    }
    else{
        array[prev(front)] = data;
        front = prev(front);
    }
}

template<class T>
void CircularArray<T>::push_back(T data) {
    if (this->is_empty()){
        front=0;
        back=0;
        array[0] = data;
    }
    else{
        array[next(back)] = data;
        back = next(back);
    }
}

template<class T>
T CircularArray<T>::pop_front() {
    T data = array[front];
    front = next(front);
    if ( is_full() ){
        front = -1;
        back = -1;
    }
    return data;
}

template<class T>
T CircularArray<T>::pop_back() {
    T data = array[back];
    back = prev(back);
    if ( is_full() ){
        front = -1;
        back = -1;
    }
    return data;
}

template<class T>
void CircularArray<T>::clear() {
    front = -1;
    back = -1;
}

template<class T>
T &CircularArray<T>::operator[](int pos) {
    return array[(pos+front)%capacity];
}

template<class T>
void CircularArray<T>::mergesort(int const begin, int const end) {
    // Caso base
    if (begin >= end) return;
    // Llamadas recursivas
    auto mid = begin + (end-begin)/2;
    mergesort(begin, mid);
    mergesort(mid+1, end);
    // Merge de particiones ordenadas
    merge(begin, mid, end);
}

template<class T>
void CircularArray<T>::merge(const int left, int mid, const int right) {
    auto const sub_arr_1 = mid-left+1;
    auto const sub_arr_2 = right-mid;

    // Copia de arreglos
    auto *left_arr = new T[sub_arr_1];
    auto *right_arr = new T[sub_arr_2];
    for (int i = 0; i < sub_arr_1; ++i) {
        left_arr[i] = (*this)[left+i];
    }
    for (int j = 0; j < sub_arr_2; ++j) {
        right_arr[j] = (*this)[mid+1+j];
    }

    // Merge
    auto index_left = 0, index_right = 0, index_merge = left;
    while (index_left < sub_arr_1 && index_right < sub_arr_2){
        if (left_arr[index_left] <= right_arr[index_right]){
            (*this)[index_merge++] = left_arr[index_left++];
        }
        else {
            (*this)[index_merge++] = right_arr[index_right++];
        }
    }

    // Copia de elementos restantes
    while (index_left < sub_arr_1) {
        (*this)[index_merge++] = left_arr[index_left++];
    }
    while (index_right < sub_arr_2) {
        (*this)[index_merge++] = right_arr[index_right++];
    }
}




template<class T>
void CircularArray<T>::sort() {
    // Merge sort
    if (! is_empty()){
        mergesort(0, size()-1);
    }
    /*
    // Bubble sort
    for (int i = 0; i < size()-1; ++i) {
        for (int j = 0; j < size()-i-1; ++j) {
            if ((*this)[j] > (*this)[j+1]) {
                swap(&(*this)[j], &(*this)[j+1]);
            }
        }
    }
    */
}


template<class T>
bool CircularArray<T>::is_sorted() {
    for (int i = 0; i < size()-2; ++i) {
        if ((*this)[i] > (*this)[i+1]) {
            return false;
        }
    }
    return true;
}

template<class T>
void CircularArray<T>::reverse() {
    for (int i = 0; i < size()/2; ++i) {
        swap(&(*this)[i], &(*this)[size()-1-i]);
    }
}

template<class T>
void CircularArray<T>::insert(T data, int pos) {
    if (pos == 0) {
        push_front(data);
    }
    else if (pos == size()) {
        push_back(data);
    }
    else {
        for (int i = size(); i > pos ; ++i) {
            (*this)[i] = (*this)[i-1];
        }
        (*this)[pos] = data;
    }
}





