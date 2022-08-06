# CMakeList.txt: проект CMake для task3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("task3")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (task3  "bye.cpp")
add_library(LeaverLib SHARED Leaver.cpp Leaver.h)
target_link_libraries(task3 LeaverLib)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
