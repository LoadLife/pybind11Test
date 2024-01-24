#include "pet.h"
#include "pet_store.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;
PYBIND11_MODULE(bindtest, m) {
  py::class_<Pet>(m, "Pet").def("Eat", &Pet::Eat);

  py::class_<PetStore>(m, "PetStore")
      .def(py::init<>())
      .def("GetCat", &PetStore::GetCat);
}