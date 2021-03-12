project(seminars C)

cmake_minimum_required(VERSION 3.13.4)

#add_compile_options(-Wall -Werror=all)
#add_compile_options(-fpic)

add_subdirectory(sem1)
add_subdirectory(sem2)
add_subdirectory(sem3)
add_subdirectory(sem4)
add_subdirectory(sem5)
add_subdirectory(sem6)
add_subdirectory(sem7)
add_subdirectory(sem12)
add_subdirectory(sem14)
add_subdirectory(sem15)
add_subdirectory(sem16)

add_executable(sem13.main sem13/main.c)
