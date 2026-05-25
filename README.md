# OJ Judge Core

命令行版 C++ 在线判题核心模块。

当前项目目标是从最小闭环开始，实现本地判题流程：

1. 接收用户代码路径
2. 接收输入文件路径
3. 接收标准答案路径
4. 编译用户代码
5. 运行用户程序
6. 比对输出结果
7. 返回 AC / WA / CE / RE / TLE

## 当前进度

Day 1：项目骨架搭建与命令行参数校验。

当前已完成：

- 使用 CMake 管理项目
- 建立 include / src / sandbox / tests 目录
- 能够生成 judge 可执行程序
- 能够接收命令行参数
- 能够检查 source / input / answer 文件是否存在

## 项目结构

```text
oj-judge-core/
├── include/
├── src/
├── sandbox/
├── tests/
├── CMakeLists.txt
├── README.md
└── .gitignore