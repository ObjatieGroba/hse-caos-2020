add_executable(sem25-1 example.cpp)
add_executable(sem25-templates temlpates.cpp)

set_property(TARGET sem25-templates PROPERTY CXX_STANDARD 17)

target_link_libraries(sem25-1 pthread)  ## g++ example.cpp -lpthread

