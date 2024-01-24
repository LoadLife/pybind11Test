#ifndef _PET_STORE_H_
#define _PET_STORE_H_
class Pet;

typedef Pet *(*GetCat_handle)();

class PetStore {
public:
  PetStore();
  Pet* GetCat();  
  ~PetStore();

private:
  GetCat_handle GetCat_ptr_;
  void *pet_lib_{nullptr};
};

#endif