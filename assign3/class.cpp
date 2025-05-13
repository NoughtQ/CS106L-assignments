#include <algorithm>
#include "class.h"
#include <string>

template <typename T>
void Container<T>::sort() {
    std::sort(element, element + size);
}

template <typename T>
Container<T>::Container(): element(nullptr), size() {}

template <typename T>
Container<T>::Container(size_t s, std::string t): size(s), type(t) {
    if (s > 0) 
        element = new T[s]();
    else
        element = nullptr;
}

template <typename T>
Container<T>::~Container() {
    delete element;
}

// template <typename T>
// T Container<T>::get_element(size_t i) const {
//     if (i < size && element != nullptr)
//         return element[i];
//     else {
//         std::cout << "Index out of range!" << std::endl;
//         return T();
//     }
        
// }

// template <typename T>
// void Container<T>::set_element(size_t i, const T val) {
//     if (i < size && element != nullptr) {
//         element[i] = val;
//         sort();
//     } else {
//         std::cout << "Index out of range!" << std::endl;
//     }
// }

template <typename T>
size_t Container<T>::get_size() const {
    return size;
}

template <typename T>
std::string Container<T>::get_type() const {
    return type;
}

template <typename T>
void Container<T>::set_type(std::string t) {
    type = t;
}

template class Container<int>;
template class Container<double>;