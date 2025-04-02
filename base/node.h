// binary_tree.h
#pragma once

class node {
public:
    node(node* left = nullptr, node* right = nullptr, int value = 0);
    ~node();

    node* getLeft() const;
    node* getRight() const;
    int getValue() const;

    // void setLeft(node* left);
    // void setRight(node* right);
    // void setValue(int value);

private:
    node* _lc;
    node* _rc;
    int _val;
};
