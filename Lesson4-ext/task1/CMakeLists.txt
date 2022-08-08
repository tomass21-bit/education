# CMakeList.txt: проект CMake для task1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("task1")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (task1 "task1.cpp" "task1.h")
add_subdirectory(D:/GIT/education/Lesson4-ext/Catch2 Catch2-build)
add_executable (test_task1 "test.cpp" "task1.h" "task1.cpp")
target_link_libraries(test_task1 PRIVATE Catch2::Catch2)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
