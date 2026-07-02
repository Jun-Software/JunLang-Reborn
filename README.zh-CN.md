# JunLang Reborn

JunLang Reborn 是一个使用 C++17 编写的轻量级语言/解释器项目。
当前仓库提供一个命令行程序，用于读取并执行 `JunLang` 源文件。

## 特性

- C++17
- 支持从文件读取源码
- 无参数时输出版本信息和用法
- 支持注释与基础表达式解析

## 构建

项目使用 CMake 构建：

```bash
cmake -S . -B build
cmake --build build
```

## 运行

程序需要传入一个源码文件路径：

```bash
JunLang <filename>
```

如果不传参数，程序会输出版本信息和用法提示。

## 语法约定

- 关键字和标识符在读取时会被转成小写
- 空白会被折叠处理
- `#` 后面的内容会被当作注释忽略

## 项目结构

- `src/main.cpp`：程序入口
- `src/read.hpp`：文件读取逻辑
- `src/interpreter.hpp`：解释执行入口
- `src/init.hpp`：基础类型、全局状态和工具函数

## 版本

当前版本：`v1.0.0`

## 许可证

本项目使用 `LICENSE` 中列出的许可证。
