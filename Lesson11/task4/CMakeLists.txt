# CMakeList.txt: проект CMake для task3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("task3")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (task3  "Task3.cpp")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(FiguraLib SHARED Figura.cpp Figura.h Four.cpp Four.h Paralelogram.cpp Paralelogram.h Pramoug.cpp Pramoug.h quad.cpp quad.h Romb.cpp Romb.h Triple.cpp Triple.h Triple_pramoug.cpp Triple_pramoug.h Triple_ravnobed.cpp Triple_ravnobed.h Triple_ravnostor.cpp Triple_ravnostor.h)
target_link_libraries(task3 FiguraLib)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
