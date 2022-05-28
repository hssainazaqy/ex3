
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

//--------------------------------------------------------------
//                     is this okay????????????????????
//--------------------------------------------------------------

template < T class >
class List
{
    public:
        List<T>();
        ~List<T>();
    private:
        T data;
        List<T>* next;
}
//----------------------------------------------
template < T class >
List<T>::~List<T>()
{
    List<T> list = this;
    while(list){
        List<T> toDelete = list;
        delete toDelete;
        list = list->next;
    }
}
//----------------------------------------------
template < T class >
List<T>::List<T>():data(new T),next(nullptr)
{
}
//----------------------------------------------
template < T class >
class Queue
{
    private:
        class List<T> list;
        bool isEmpty;
        int size;
        
        //-----------------------------
    public:
        Queue();
        Queue(const Queue& other);
        Queue& operator=(const Queue& other);
        ~Queue();
        //-----------------------------
        void pushBack (const T object);
        &int front();
        void popFront();
        int size();
}













#endif