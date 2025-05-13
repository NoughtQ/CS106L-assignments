#ifndef CLASS_H
#define CLASS_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Container {
private:
    T *element;
    size_t size;
    std::string type;
    void sort();
public:
    Container();
    Container(size_t s, std::string t);
    ~Container();
    // T get_element(size_t i) const;
    // void set_element(size_t i, const T val);
    size_t get_size() const;
    std::string get_type() const;
    void set_type(std::string t);
};

#endif