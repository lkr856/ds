#include "list.h"

template <typename T> class Queue: public List<T> {
    public:
        void enqueue ( T const& e ) { insertAsLast ( e ); } //队列插入
        T dequeue() { return remove ( first() ); } //删除第一个节点
        T& front() { return first()->data; } //查看第一个节点
}