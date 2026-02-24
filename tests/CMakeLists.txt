add_executable(result-test result_test.cpp)

add_test(NAME result-test COMMAND ${CMAKE_CURRENT_BINARY_DIR}/result-test)

target_link_libraries(result-test unittest containers)

if(MSVC)
    target_compile_options(result-test PRIVATE /W4 /WX)
else()
    target_compile_options(result-test PRIVATE -Wall -Wextra -Werror)
endif()
