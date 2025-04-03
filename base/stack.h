#include "list.h"

template <typename T> class Stack: public List<T> {
    public:
        void push ( T const& e ) { insertAsLast ( e ); } //队列插入
        T pop() { return remove ( last() ); } //删除第一个节点
        T& top() { return last()->data; } //查看第一个节点
}