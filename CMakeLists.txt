cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(print_ip VERSION ${PROJECT_VESRION})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

option(WITH_GOOGLE_TEST "Whether to build Google test" ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(print_ip src/main.cpp)

target_include_directories(print_ip
        PRIVATE 
        "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(print_ip PRIVATE
            /W4
            )
else ()
    target_compile_options(print_ip PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT shirkin39@mail.ru)
include(CPack)


if(WITH_GOOGLE_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()