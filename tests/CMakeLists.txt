if(WITH_GOOGLE_TEST)
    find_package(GTest REQUIRED)
    add_executable(test_integral test_integral.cpp)
    target_include_directories(test_integral
            PRIVATE
            "${CMAKE_BINARY_DIR}" 
            "${CMAKE_HOME_DIRECTORY}"
    )
    
    target_link_libraries(test_integral
        pthread
        CONAN_PKG::gtest
    )
    
    set_target_properties(test_integral PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
    )

    add_executable(test_string test_string.cpp)
    target_include_directories(test_string
        PRIVATE
        "${CMAKE_BINARY_DIR}" 
        "${CMAKE_HOME_DIRECTORY}"
    )
    target_link_libraries(test_string
        pthread
        CONAN_PKG::gtest
    )

    set_target_properties(test_string PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
    )

    add_executable(test_containers test_containers.cpp)
    target_include_directories(test_containers
        PRIVATE
        "${CMAKE_BINARY_DIR}" 
        "${CMAKE_HOME_DIRECTORY}"
    )
    target_link_libraries(test_containers
        pthread
        CONAN_PKG::gtest
    )

    set_target_properties(test_containers PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
    )

    add_executable(test_tuple test_tuple.cpp)
    target_include_directories(test_tuple
        PRIVATE
        "${CMAKE_BINARY_DIR}" 
        "${CMAKE_HOME_DIRECTORY}"
    )
    target_link_libraries(test_tuple
        pthread
        CONAN_PKG::gtest
    )

    set_target_properties(test_tuple PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/tests
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
    )
endif()

if (MSVC)
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

include_directories(${CMAKE_SOURCE_DIR}/include)

if(WITH_GOOGLE_TEST)
    add_test(test_integral test_integral)
    add_test(test_string test_string)
    add_test(test_containers test_containers)
    add_test(test_tuple test_tuple)
endif()