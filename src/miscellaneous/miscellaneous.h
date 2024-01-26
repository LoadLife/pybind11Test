#ifndef _MISCELLANEOUS_H_
#define _MISCELLANEOUS_H_
#include "pybind11/pybind11.h"

class TestCArray {
public:
  TestCArray() = default;
  int32_t array[3][2]{{1, 2}, {3, 4}, {5, 6}};

private:
};

void RegisterMiscellaneous(pybind11::module);

#endif