# jsos ( JavaScript Operating System )
可在硬件上运行的 quickjs。

## 动机
本人想在没有操作系统的情况下运行 Javascript 代码，就这么简单

## 思路
在没有操作系统的情况下，文件系统等都不可用，所以要去修改 quickjs
的源代码，去掉文件系统的相关的 API。

## TODO
 - [✔] 去掉 quickjs 的 `os` 和 `std` 模块的大部分 API
 - [ ] 重定向 quickjs 的标准输入输出使其不依赖标准库
 - [ ] 重构内存分配部分，不依赖标准库
 - [ ] 通过 gcc -nostdlib 编译

> 未来: (基本不可能实现)
- ~~移植文件系统和网络协议栈~~
- ~~移植 Gecko (FireFox 的渲染引擎)~~

## 贡献
您可以从这些方面帮助这个项目
- 写文档
- 找 bug
- 提供思路
- 贡献代码