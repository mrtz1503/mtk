cmake_minimum_required(VERSION 3.14)
project(mtk VERSION 1.0.0 LANGUAGES CXX)


# options
option(MTK_BUILD_EXAMPLES "Build example" ON)
option(GDIPLUS "Use of GDI+" ON)



###########  ###########

# SOURCE_FILES
set(SOURCE_FILES
    app.cpp
    group.cpp
    rect.cpp
    util.cpp
    widget.cpp
    window.cpp
    canvas.cpp
)


if (WIN32)
    set(PLATFORM_SOURCES windows_system_driver.cpp windows_window_driver.cpp win32.cpp)
    list(TRANSFORM PLATFORM_SOURCES PREPEND "src/driver/windows/")
endif()

if (GDIPLUS) 
    set(GRAPHICS_SOURCES gdiplus_graphics_driver.cpp)
    list(TRANSFORM GRAPHICS_SOURCES PREPEND "src/driver/gdiplus/")
endif()


list(TRANSFORM SOURCE_FILES PREPEND "src/")


add_library(${PROJECT_NAME} ${SOURCE_FILES} ${PLATFORM_SOURCES} ${GRAPHICS_SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(mtk
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PUBLIC Comctl32.lib Shcore.lib Gdiplus.lib)





if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    DEBUG_POSTFIX "d"
    CMAKE_CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED ON
    CMAKE_CXX_EXTENSIONS OFF
)


#################### Installation instructions ####################


include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# Export the targets to a script
install(EXPORT ${PROJECT_NAME}-targets
    FILE 
        ${PROJECT_NAME}Targets.cmake
    NAMESPACE 
        ${PROJECT_NAME}::
    DESTINATION 
        ${INSTALL_CONFIGDIR}
)


include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CMake/Config.cmake.in
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)


#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)




export(EXPORT ${PROJECT_NAME}-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::)

#Register package in the User Package Registry
export(PACKAGE ${PROJECT_NAME})



if(MTK_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()




