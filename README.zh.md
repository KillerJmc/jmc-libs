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



## 注意

由于GCC和Clang尚未实现C++20的formatting, concept等特性，本工具目前只能在MSVC编译器上运行。



