cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -g")

link_directories(libft minilibx_macos) # libraries

include_directories(inc libft minilibx_macos) # headers

set(SOURCE_FILES main.c map.c read.c) # sources

add_executable(fdf ${SOURCE_FILES}) # compilation

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(fdf -lft -lmlx ${OPENGL_LIBRARIES} ${GLUT_LIBRARY}) # linkage
