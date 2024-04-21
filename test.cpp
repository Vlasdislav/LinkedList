#include <iostream>
#include <cassert>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> a;
    std::vector<int> b = { 1, 2, 1000 };
    a.insert(1);
    a.insert(2);
    a.insert(1000);
    assert(a.to_vector() == b);

    a.remove(2);
    b = { 1, 1000 };
    assert(a.to_vector() == b);

    assert(a.find(1) == true);
    assert(a.find(2) == false);

    std::cout << "ALL TEST SUCCESS" << std::endl;
}
