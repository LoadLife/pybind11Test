#include "miscellaneous.h"
#include "pybind11/stl.h"
namespace py = pybind11;

void RegisterMiscellaneous(py::module m) {
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
}
