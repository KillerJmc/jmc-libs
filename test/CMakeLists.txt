unset(enable_basic_testing CACHE)
unset(enable_gtest_testing CACHE)
option(enable_basic_testing "Build test/main.cpp." OFF)
option(enable_gtest_testing "Build test cases with Google Test." OFF)

if (enable_basic_testing)
	add_executable(JmcLibsMain main.cpp)
	target_link_libraries(JmcLibsMain JmcLibs::jmc-libs)
endif()

if (enable_gtest_testing)
	enable_testing()

	include(FetchContent)

	# Google Test
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest
		GIT_TAG        release-1.12.1
	)

	if (MSVC)
		set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	endif()

	FetchContent_MakeAvailable(googletest)

	# get cpp test files in ./cases
	file(GLOB_RECURSE TEST_CASES CONFIGURE_DEPENDS cases/*.cpp)
	add_executable(JmcLibsTest ${TEST_CASES})
	target_link_libraries(JmcLibsTest JmcLibs::jmc-libs GTest::gtest_main)

	add_test(JmcLibsTests JmcLibsTest)
endif()

