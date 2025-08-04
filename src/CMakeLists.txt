function(add_gtest test_name)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(ADD_GTEST "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_executable(${test_name})
    target_include_directories(${test_name} PRIVATE src)
    target_sources(${test_name}
        PRIVATE
            ${ADD_GTEST_SOURCES}
    )
    target_compile_definitions(${test_name} PRIVATE UNIT_TEST)

    target_link_libraries(${test_name}
        PRIVATE
            OpenSSL::SSL
            GTest::gtest_main
            GTest::gmock_main
    )

    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

add_subdirectory(block)
add_subdirectory(hash)
