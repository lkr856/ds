
#include <iostream>

#include "base\node.h"


int main(){
    node* no  = new node(nullptr,nullptr,1);
    std::cout << no->getValue() <<std::endl;

    std::cout << "hello" <<std::endl;
    return 0;

}