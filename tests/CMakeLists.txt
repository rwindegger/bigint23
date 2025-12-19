cmake_minimum_required(VERSION 3.28)

CPMAddPackage("gh:google/googletest#v1.17.0")

include(GoogleTest)

add_executable(
        bigint_tests
        arithmetic_tests.cpp
        assign_and_equals_tests.cpp
        binary_tests.cpp
        comparison_tests.cpp
        constexpr_tests.cpp
        functions_tests.cpp
        io_tests.cpp
        main.cpp
)

if(MSVC)
    target_compile_options(bigint_tests PRIVATE
            /W4             # Warning level 4 (almost all warnings)
            /WX             # Treat warnings as errors
            /permissive-    # Strict conformance mode
            /Zc:__cplusplus # Enable correct __cplusplus macro
            /utf-8          # UTF-8 source and execution character sets
    )

    # Debug-specific flags
    target_compile_options(bigint_tests PRIVATE
            $<$<CONFIG:Debug>:/Od>      # No optimization
            $<$<CONFIG:Debug>:/Zi>      # Debug info
            $<$<CONFIG:Debug>:/RTC1>    # Runtime checks
    )

    # RelWithDebInfo-specific flags
    target_compile_options(bigint_tests PRIVATE
            $<$<CONFIG:RelWithDebInfo>:/O2>         # Optimize for speed
            $<$<CONFIG:RelWithDebInfo>:/Zi>         # Debug info
            $<$<CONFIG:RelWithDebInfo>:/DNDEBUG>    # Define NDEBUG
    )
else()
    target_compile_options(bigint_tests PRIVATE
            -Wall           # Enable all warnings
            -Wextra         # Enable extra warnings
            -Werror         # Treat warnings as errors
            -pedantic       # Enforce strict compliance to the standard
            -Wconversion    # Warn on type conversions that may alter a value
    )

    # Debug-specific flags
    target_compile_options(bigint_tests PRIVATE
            $<$<CONFIG:Debug>:-O0>        # No optimization
            $<$<CONFIG:Debug>:-g>         # Debug info
    )

    # RelWithDebInfo-specific flags
    target_compile_options(bigint_tests PRIVATE
            $<$<CONFIG:RelWithDebInfo>:-O2>      # Optimize for speed
            $<$<CONFIG:RelWithDebInfo>:-g>       # Debug info
            $<$<CONFIG:RelWithDebInfo>:-DNDEBUG> # Define NDEBUG
    )
endif()

target_link_libraries(
        bigint_tests
        PRIVATE
        bigint::bigint
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(bigint_tests)

set_target_properties(bigint_tests PROPERTIES CXX_STANDARD 23)
target_compile_features(bigint_tests PUBLIC cxx_std_23)
