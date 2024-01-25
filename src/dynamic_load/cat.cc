#include "cat.h"
#include <iostream>

void Cat::Eat() { std::cout << "Eat fish biscuit" << std::endl; }

extern "C" Pet *GetCat() {
  Cat *cat = new Cat();
  return cat;
}

extern "C" void DelCat(Pet *cat) { delete cat; }