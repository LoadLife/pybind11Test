from bindtest import *


def test_dynamic_load():
    ps = PetStore()
    cat = ps.GetCat()
    cat.Eat()


def test_def_property():
    c_arr = CArray()
    print(c_arr.arr)
    c_arr.arr = [[3, 4], [5, 6], [7, 8]]
    print(c_arr.arr)
