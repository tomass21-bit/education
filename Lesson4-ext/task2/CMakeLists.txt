# CMakeList.txt: проект CMake для task1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("task1")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (test_task1 "test.cpp" "task1.cpp" "task1.h")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_subdirectory(E:/C++/education/Catch2 Catch2-build)

target_link_libraries(test_task1 PRIVATE Catch2::Catch2 )

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
