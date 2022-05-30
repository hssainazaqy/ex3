
#ifndef QUEUE_TEMPLATE
#define QUEUE_TEMPLATE

/*
* This is indeed as the name suggests, a Queue Template
*   The template supports:
*       pushBack:
*           pushes an object to the back of a queue.
*       front:
*           returns the front value BY REFERENCE
*       popFront:
*           releases the front object in the queue, doesn't return the object
*       size:
*           returns the number of objects in the queue, zero if empty
*
*
*/
#define DEFAULT_SIZE 10
#define EXPAND_MULTIPLIER 2

//-------------------Queue-------------------
//-----first index is first in line
//-------------------------------------------

template < class T >
class Queue
{
public:
    //-----------------------------
    class Iterator;
    Iterator begin() const;
    Iterator end() const;
    //-----------------------------
    class EmptyQueue {};
    //-----------------------------
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();
    //-----------------------------
    void pushBack (const T& object);
    T& front();
    void popFront();
    int size();
    //-----------------------------
private:
    T* m_data;
    int m_size;
    int m_max_size;
    //-----------------------------
};
//----------------------------------------------
template <  class T >
Queue<T>::Queue():m_data(new T[DEFAULT_SIZE]),m_size(0),m_max_size(DEFAULT_SIZE)
{
}
//----------------------------------------------
template <  class T >
Queue<T>::~Queue()
{
    for (int i = 0 ; i < m_size ; i++){
        delete m_data[i];
    }
}
//----------------------------------------------
template <  class T >
Queue<T>::Queue(const Queue& other):m_data(new T[other.m_max_size]),m_size(other.m_size),m_max_size(other.m_max_size)
{
    for (int j = 0 ; j < other.m_size; j++){
        m_data[j] = other.m_data[j];
    }
}
//----------------------------------------------
template <  class T >
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if(this == &other){
        return *this;
    }

    delete[] m_data;
    m_data = new T[other.m_max_size];
    m_size  = other.m_size;
    m_max_size = other.m_max_size;
    //-----------------------------
    for (int k = 0 ; k < other.m_size; k++){
        m_data[k] = other.m_data[k];
    }

    return *this;
}
//----------------------------------------------
template <  class T >
void Queue<T>::pushBack (const T& object)
{
    T* tmp_data;
    if(m_size +1 >= m_max_size){
        tmp_data = new T[m_max_size*EXPAND_MULTIPLIER];
        m_max_size = m_max_size*EXPAND_MULTIPLIER;
    }
    else{
        tmp_data = new T[m_max_size];
    }
//-----------------------------
    for (int k = 1 ; k < m_size +1; k++){
        tmp_data[k] = m_data[k-1];
    }
//-----------------------------
    delete[] m_data;
    m_data = tmp_data;
    m_data[0] = object;
    m_size++;
}
//----------------------------------------------
template <  class T >
T& Queue<T>::front()
{
    if(m_size == 0){
        throw EmptyQueue();
    }
    return &m_data[m_size-1];
}
//----------------------------------------------
template <  class T >
void Queue<T>::popFront()
{
    if(m_size == 0){
        throw EmptyQueue();
    }
    else{
        delete m_data[m_size-1];
        m_size--;
    }
}
//----------------------------------------------
template <  class T >
int Queue<T>::size()
{
    return m_size;
}
//-----------------begin------------------------
template <  class T >
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(this, 0);
}
//-----------------end--------------------------
template <  class T >
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(this, m_size-1);
}
//----------------------------------------------
//-----------------Iterator + Iterator operators-----------------

template<class T>
class Queue<T>::Iterator {
    Queue<T>* m_queue;
    int m_index;
    class InvalidOperation{};
    Iterator(const Queue<T>* other, int index);
    friend class Queue<T>;
public:
    T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
};
//----------------------------------------------
template <  class T >
T& Queue<T>::Iterator::operator*() const
{   if(m_index >= m_queue->m_size){
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}
//----------------------------------------------
template <  class T >
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    ++m_index;
    return *this;
}
//----------------------------------------------
template <  class T >
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    Iterator result = *this;
    ++*this;
    return result;
}
//----------------------------------------------
template <  class T >
bool Queue<T>::Iterator::operator==(const Iterator& it) const {
    return m_index == it.index;
}
//----------------------------------------------
template <  class T >
bool Queue<T>::Iterator::operator!=(const Iterator& it) const {
    return !(*this == it);
}

template<class T>
Queue<T>::Iterator::Iterator(const Queue<T>* other, int index) :
        m_queue(other),m_index(index)
{
    if(index < 0 || index >= m_queue->m_size){
        throw InvalidOperation();
    }
}

//----------------------------------------------
template <  class T , class S>//----------------second look-----
Queue<T>& filter(Queue<T>&, S condition)
{
    Queue<T> queue = new Queue<T>();
    for(typename Queue<T>::Iterator it = queue.begin();it < queue.end();it++){
        if(condition(*it)){
            queue.pushBack(*it);
        }
    }
    return &queue;
}
//----------------------------------------------
template <  class T , class S>//----------------second look-----
void transform(Queue<T>& queue, S condition)
{
    for(typename Queue<T>::Iterator it = queue.begin();it < queue.end();it++){
        *it = condition(*it);
    }
}











#endif