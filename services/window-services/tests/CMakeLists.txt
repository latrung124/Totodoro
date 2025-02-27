set(SOURCES WindowMediaServiceTest.cpp)

add_executable(WindowMediaServiceTest ${SOURCES})

target_link_libraries(WindowMediaServiceTest PRIVATE WMediaService
                                                     GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(WindowMediaServiceTest)
