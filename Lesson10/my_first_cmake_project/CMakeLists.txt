# CMakeList.txt: проект CMake для my_first_cmake_project; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("my_first_cmake_project")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (my_first_cmake_project "my_first_cmake_program.cpp" )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
