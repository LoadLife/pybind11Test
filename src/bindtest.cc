#include "miscellaneous/miscellaneous.h"
#include "pet.h"
#include "pet_store.h"
#include "pybind11/pybind11.h"

namespace py = pybind11;
PYBIND11_MODULE(bindtest, m) {
  // test dynamic load
  py::class_<Pet>(m, "Pet").def("Eat", &Pet::Eat);

  py::class_<PetStore>(m, "PetStore")
      .def(py::init<>())
      .def("GetCat", &PetStore::GetCat, py::return_value_policy::reference)
      .def("DelCat", &PetStore::DelCat);

  // test def_property
  RegisterMiscellaneous(m);
}