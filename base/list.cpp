#include "list.h"
//列表节点操作
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi(T) cur = new ListNode<T>(e,_pred , this); //先把cur的_pred _succ维护好
    if(_pred){ //如果有哨兵则不必判定
        _pred->_succ = cur; //维护_pred的后继
    }
    _pred = cur; //维护this的前驱
    return cur;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e)
{
    ListNodePosi(T) cur = new ListNode<T>(e , this, _succ);
    if(_succ){//如果有哨兵则不必判定
        _succ->_pred = cur; //维护_succ的前驱
    }
    _succ = cur;//维护this的后继
    return cur;
}

template <typename T>
void List<T>::init(){
    _header = new ListNode<T>;
    _trailer = new ListNode<T>;
    _header->_succ = _trailer;_header->_pred = NULL;
    _trailer->_pred = _header; _trailer->_succ = NULL;
    _size = 0;
}

// 列表操作
template <typename T>
void List<T>::insertAsLast(T const & s){
    _trailer->insertAsSucc(s);
}

template <typename T>
void List<T>::insertAsFirst(T const & s){
    _header->insertAsPred(s);
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p){
    T data = p->_data;
    p->_pred->_succ = p->_succ;
    p->_succ->_pred = p->_pred;
    delete p; _size --;
    return data;
}
