#include "pet.h"

class Cat : public Pet {
public:
  ~Cat() = default;
  Cat() = default;
  void Eat() override;
};