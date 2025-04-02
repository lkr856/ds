#include "node.h"

// Node 类的实现
node::node(node* left, node* right, int value)
    : _lc(left), _rc(right), _val(value) {}

node::~node() {
    delete _lc;
    delete _rc;
}

// 获取左子节点
node* node::getLeft() const {
    return _lc;
}

// 获取右子节点
node* node::getRight() const {
    return _rc;
}

// 获取节点值
int node::getValue() const {
    return _val;
}

// 如果需要，可以取消注释并实现设置器（setter）方法
/*
void node::setLeft(node* left) {
    _lc = left;
}

void node::setRight(node* right) {
    _rc = right;
}

void node::setValue(int value) {
    _val = value;
}
*/