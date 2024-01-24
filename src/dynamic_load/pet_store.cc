#include "pet_store.h"
#include <dlfcn.h>
#include <iostream>

PetStore::PetStore() {
  pet_lib_ = dlopen("./libcat.so", RTLD_LAZY | RTLD_DEEPBIND);
  if(!pet_lib_) {
    std::cerr << "Failed to open libcat" << std::endl;
    abort(); 
  }
  GetCat_ptr_ = reinterpret_cast<GetCat_handle>(dlsym(pet_lib_, "GetCat"));
}

Pet *PetStore::GetCat() { return GetCat_ptr_(); }

PetStore::~PetStore() { dlclose(pet_lib_); }