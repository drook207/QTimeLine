include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
	ON
	CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

find_package(Qt6 REQUIRED Core)

set(QT_LIBS Qt6::Core)

qt_add_executable(unit_tests main.cpp unit_tests/tst_sqlstorage.cpp)

target_link_libraries(unit_tests PRIVATE ${QT_LIBS} gtest_main qtimeline)
add_test(NAME tst_sqlStorage COMMAND sqlStorage)
