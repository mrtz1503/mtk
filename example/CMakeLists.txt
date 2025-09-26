cmake_minimum_required(VERSION 3.14)

project(mtkExample)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE mtk::mtk)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)