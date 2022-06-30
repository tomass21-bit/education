# CMakeList.txt: проект CMake для Task2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Task2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Task2 "Task3.cpp" "Four.cpp" "Four.h" "Triple.cpp" "Triple.h" "Figura.cpp" "Figura.h" "Paralelogram.cpp" "Paralelogram.h" "Pramoug.cpp" "Pramoug.h" 
"Quad.cpp" "Quad.h" "Romb.cpp" "Romb.h" "Triple_pramoug.cpp" "Triple_pramoug.h" "Triple_ravnobed.cpp" "Triple_ravnobed.h" "Triple_ravnostor.cpp" "Triple_ravnostor.h" )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
