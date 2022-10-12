cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(print_ip VERSION ${PROJECT_VESRION})

option(WITH_GOOGLE_TEST "Whether to build Google test" ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(print_ip main.cpp)

target_include_directories(print_ip
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

if(WITH_GOOGLE_TEST)
    find_package(GTest REQUIRED)
    add_executable(test_integral tests/test_integral.cpp)
    target_include_directories(test_integral
            PRIVATE
            "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
            "${GTEST_INCLUDE_DIR}")
    target_link_libraries(test_integral
            ${GTEST_LIBRARIES}
            ${GTEST_MAIN_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            )
    add_executable(test_string tests/test_string.cpp)
    target_include_directories(test_string
            PRIVATE
            "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
            "${GTEST_INCLUDE_DIR}"
            )
    target_link_libraries(test_string
            ${GTEST_LIBRARIES}
            ${GTEST_MAIN_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            )

    add_executable(test_containers tests/test_containers.cpp)
    target_include_directories(test_containers
            PRIVATE
            "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
            "${GTEST_INCLUDE_DIR}"
            )
    target_link_libraries(test_containers
            ${GTEST_LIBRARIES}
            ${GTEST_MAIN_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            )
    add_executable(test_tuple tests/test_tuple.cpp)
    target_include_directories(test_tuple
            PRIVATE
            "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
            "${GTEST_INCLUDE_DIR}"
           )
    target_link_libraries(test_tuple
            ${GTEST_LIBRARIES}
            ${GTEST_MAIN_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
            )
endif()

if (MSVC)
    target_compile_options(print_ip PRIVATE
            /W4
            )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_integral PRIVATE
                /W4
                )

        target_compile_options(test_string PRIVATE
                /W4
                )

        target_compile_options(test_containers PRIVATE
                /W4
                )
        target_compile_options(test_tuple PRIVATE
                /W4
                )
    endif()
else ()
    target_compile_options(print_ip PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    if(WITH_GOOGLE_TEST)
        target_compile_options(test_integral PRIVATE
                -Wall -Wextra -pedantic -Werror
                )

        target_compile_options(test_string PRIVATE
                -Wall -Wextra -pedantic -Werror
                )

        target_compile_options(test_containers PRIVATE
                -Wall -Wextra -pedantic -Werror
                )

        target_compile_options(test_tuple PRIVATE
                -Wall -Wextra -pedantic -Werror
                )
    endif()
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
    add_test(test_integral test_integral)
    add_test(test_string test_string)
    add_test(test_containers test_containers)
    add_test(test_tuple test_tuple)
endif()