add_library(cat SHARED cat.cc)
target_include_directories(cat PUBLIC ./)
set_target_properties(cat PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src)

add_library(pet_store SHARED pet_store.cc)
target_include_directories(pet_store PUBLIC ./)
target_link_libraries(pet_store PRIVATE dl)
set_target_properties(pet_store PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src)
