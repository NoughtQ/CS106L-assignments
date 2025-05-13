/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
// #include <string>

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Container<int> container_1;
  Container<double> container_2(50, "double");

  // std::cout << container_2.get_element(5) << std::endl;
  // container_2.set_element(5, 100);
  // std::cout << container_2.get_element(5) << std::endl;
  // std::cout << container_2.get_element(99) << std::endl;
  std::cout << container_2.get_size() << " " << container_2.get_type() << std::endl;
}