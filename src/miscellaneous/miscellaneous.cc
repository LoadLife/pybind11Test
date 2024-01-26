#include "miscellaneous.h"
#include "pybind11/numpy.h"
#include "pybind11/stl.h"
#include <iostream>
namespace py = pybind11;
template <typename T> void PrintArray(const T &arr, std::string name) {
  std::cout << "\n" << name << ":" << std::endl;
  for (auto i : arr) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}
void RegisterMiscellaneous(py::module m) {
  // 1.test c array def_property
  py::class_<TestCArray>(m, "CArray")
      .def(py::init<>())
      .def_property(
          "arr",
          [](const TestCArray &self) {
            std::array<std::array<int32_t, 2>, 3> arr;
            for (int i = 0; i != 3; i++) {
              for (int j = 0; j != 2; j++) {
                arr[i][j] = self.array[i][j];
              }
            }
            return arr;
          },
          [](TestCArray &self, std::array<std::array<int32_t, 2>, 3> arr) {
            for (int i = 0; i != 3; i++) {
              for (int j = 0; j != 2; j++) {
                self.array[i][j] = arr[i][j];
              }
            }
          });

  // 2.test numpy
  m.def("PrintNumpy", [](py::array &arr) {
    auto nbdim = arr.ndim();
    std::vector<uint32_t> shape;
    for (ssize_t i = 0; i != nbdim; i++) {
      shape.push_back(arr.shape(i));
    }
    PrintArray(shape, "shape");
  });
}
