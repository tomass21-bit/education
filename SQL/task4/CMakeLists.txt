# CMakeList.txt: проект CMake для task1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("task4")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (task4 "task4.cpp")
add_subdirectory(D:/GIT/education/SQL/libpqxx libpqxx-build)
target_compile_features ( task4 PRIVATE cxx_std_17)
target_link_libraries(task4  pqxx)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
