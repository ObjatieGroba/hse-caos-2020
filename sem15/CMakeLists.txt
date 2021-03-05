add_executable(sem15-1 example1.c)

add_library(myfunc SHARED lib1.c)

target_link_libraries(sem15-1 myfunc)

