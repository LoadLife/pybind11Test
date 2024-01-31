#include "pybind11/embed.h"
#include "pybind11/numpy.h"
#include <iostream>

namespace py = pybind11;
int main() {
  py::scoped_interpreter guard{};
  try {
    auto builtins = py::module::import("builtins");
    auto pickle_file = builtins.attr("open")("arr_dump", "rb");
    auto pickle = py::module::import("pickle");
    auto data_list = pickle.attr("load")(pickle_file);
    pickle_file.release();

    auto ret = data_list.cast<py::list>();
    py::print(ret);


    // py::exec("import numpy as np;");
    // auto res = py::eval("np.ones([1,2,3], np.int32)");
    // py::array arr = res.cast<py::array>();
    // py::print(arr.dtype());
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}