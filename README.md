[中文](README.zh.md) &nbsp; | &nbsp; English

# jmc-libs



## Description

Providing a great number of utility classes to simplify the **C++** daily development.



## Usage

Add the following commands to the top level **CmakeLists.txt** of your CMake project:

```cmake
include(FetchContent)
FetchContent_Declare(
	JmcLibs
	GIT_REPOSITORY https://github.com/KillerJmc/jmc-libs
	GIT_TAG        ${LATEST_VERSION}
)
FetchContent_MakeAvailable(JmcLibs)
link_libraries(JmcLibs::jmc-libs)
```

Then, you need to add support for [C++ 20 Modules in CMake with Visual Studio](https://devblogs.microsoft.com/cppblog/cpp20-modules-in-cmake-with-vs/).



## Notice

Since GCC and Clang have not implemented the formatting, concept, modules and other features of C++20, this tool now can only run on MSVC compiler.



