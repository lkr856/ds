

typedef int Rank; //
#define ListNodePosi(T) ListNode<T>* //列表节点

template <typename T> struct ListNode {
   T _data; ListNodePosi(T) _pred; ListNodePosi(T) _succ; //双向列表 前驱 后继
   ListNode() {} 
   ListNode ( T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL )
      : _data ( e ), _pred ( p ), _succ ( s ) {} //初始化
   ListNodePosi(T) insertAsPred ( T const& e ); //在节点之前插入
   ListNodePosi(T) insertAsSucc ( T const& e ); //在结点之后插入
};


template <typename T> class List {
    private:
        int _size; ListNodePosi(T) _header; ListNodePosi(T) _trailer; //_header _trailer 都是哨兵本身第一个是_header->succ 最后一个是_trailer->pred 
    protected:
        void init();
    public:
        void insertAsLast(T const&);
        void insertAsFirst(T const&);
        ListNodePosi(T) first() const{return _header->_succ};//头的后一个(哨兵后)
        ListNodePosi(T) last() const{return _trailer->_pred};//末尾的前一个(哨兵前)
        T remove(ListNodePosi(T) p);
        bool empty() const{return _size <= 0}; //size为0时列表为空
};