file(GLOB EMBED_SRC "*.cc")
add_executable(embed_test ${EMBED_SRC})
target_link_libraries(embed_test PRIVATE pybind11::embed)