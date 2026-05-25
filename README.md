# OJ Judge Core

命令行版 C++ 在线判题核心模块。

本项目目标是从最小闭环开始，实现一个本地 Judge Core，逐步支持：

1. 编译用户代码
2. 运行用户程序
3. 输入输出重定向
4. 输出比对
5. 返回 AC / WA / CE / RE / TLE
6. 后续扩展 Docker 沙箱、多测试点、数据库、后端服务等能力

---

## 当前进度

### Day 1：项目骨架与入口参数校验

已完成：

- 使用 CMake 管理项目
- 建立 `include / src / sandbox / tests` 目录
- 能够生成 `judge.exe`
- 能够接收命令行参数
- 能够检查 `source.cpp / input.txt / answer.txt` 是否存在

### Day 2：Compiler 编译模块

已完成：

- 新增 `Compiler` 类
- 通过 `Compiler::compile()` 调用 MSVC `cl` 编译器
- 支持将用户代码 `sandbox/main.cpp` 编译为 `sandbox/main.exe`
- 支持将编译日志写入 `sandbox/compile.log`
- 能够根据编译器返回值判断编译成功或 CE

当前已支持的判题结果：

- CE：Compile Error，编译错误

### Day 3：Runner 运行模块

已完成：

- 新增 `Runner` 类
- 支持运行编译后的用户程序 `sandbox/main.exe`
- 支持将 `sandbox/input.txt` 重定向为标准输入
- 支持将用户程序输出写入 `sandbox/output.txt`
- 支持将运行错误信息写入 `sandbox/runtime.log`
- 能够根据用户程序退出状态判断运行成功或 RE

当前已支持的判题结果：

- CE：编译错误
- RE：运行时错误

---

## 当前限制

- 当前仅支持 Windows + Visual Studio Developer PowerShell 环境
- 当前支持编译和运行用户程序
- 暂未进行输出比对
- 暂不支持 AC / WA
- 暂不支持 TLE
- 暂不支持 Docker 沙箱
- 暂不支持多测试点

## 项目结构

```text
oj-judge-core/
├── include/
│   ├── compiler.h
│   ├── runner.h
│   ├── comparator.h
│   ├── judge.h
│   └── judge_result.h
├── src/
│   ├── main.cpp
│   ├── compiler.cpp
│   ├── runner.cpp
│   ├── comparator.cpp
│   └── judge.cpp
├── sandbox/
│   ├── main.cpp
│   ├── input.txt
│   └── answer.txt
├── tests/
├── CMakeLists.txt
├── README.md
└── .gitignore