cmake_minimum_required(VERSION 3.8)
project(Basketball-Free-Throw)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib/x64")
endif (WIN32)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main ${SOURCE_FILES} gameObjects/primitives/rect.h gameObjects/primitives/rect.cpp
        gameObjects/primitives/shape.h gameObjects/primitives/shape.cpp gameObjects/primitives/circle.h
        gameObjects/primitives/circle.cpp gameObjects/primitives/triangle.h gameObjects/primitives/triangle.cpp
        gameObjects/prefabsSimple/prefabsSimple.h gameObjects/prefabsSimple/prefabsSimple.cpp gameObjects/prefabsComplex/prefabsComplex.h
        gameObjects/prefabsComplex/prefabsComplex.cpp gameObjects/menu/menu.h gameObjects/menu/menu.cpp)

if (WIN32)
    target_link_libraries (main ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (main ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()