中文 &nbsp; | &nbsp; [English](README.md)

# jmc-libs



## 介绍

提供大量的工具类，简化 **C++** 日常开发



## 用法

在您的CMake项目的顶层**CmakeLists.txt** 中加入以下命令:

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

之后，您需要添加 [Visual Studio 在 CMake 中使用 C++ 20 Modules 特性](https://devblogs.microsoft.com/cppblog/cpp20-modules-in-cmake-with-vs/)的支持。



## 注意

由于GCC和Clang尚未实现C++20的formatting, concept, modules等特性，本工具目前只能在MSVC编译器上运行。



