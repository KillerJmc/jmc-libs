# jmc-libs

## 介绍

提供大量的工具类，简化 **C++** 日常开发

## 用法

1. 复制该项目根目录下的 **modules** 文件夹到你的 **个人项目** 的根目录。
2. 在 **CmakeLists.txt** 中的 **add_executable** 命令之前加入命令 <br>
`include(${PROJECT_SOURCE_DIR}/modules/jmc-libs/install.cmake)` 
以导入本库。

## 注意

仅支持 **CMake** 项目








