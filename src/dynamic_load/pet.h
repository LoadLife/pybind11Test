#ifndef _PET_H_
#define _PET_H_

class Pet {
public:
  virtual ~Pet() = default; 
  virtual void Eat() = 0;
};

#endif