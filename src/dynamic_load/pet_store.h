#ifndef _PET_STORE_H_
#define _PET_STORE_H_
class Pet;

typedef Pet *(*GetCat_handle)();
typedef void *(*DelCat_handle)(Pet *);

class PetStore {
public:
  PetStore();
  Pet *GetCat();
  void DelCat(Pet *pet);
  ~PetStore();

private:
  GetCat_handle GetCat_ptr_;
  DelCat_handle Delcat_ptr_;
  void *pet_lib_{nullptr};
};

#endif