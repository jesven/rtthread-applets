# User Applications


#目录介绍
apps    -- 应用示例
sdk     -- 基本支持库
  | crt    -- c语言运行库
    | armcc    -- armcc c运行库支持
    | gcc      -- gcc c运行库支持(newlib)
      | arch    -- cpu相关(启动和系统调用的汇编代码)
    | rtthread -- 操作系统相关的c运行库支持(编译器无关,都需要包含)
tools   -- elf转自定义格式
  | elf_pk.py    -- 使用示例: elf_pk.py hello.axf hello.lwp /* CMD运行 */

#注意事项
如果应用要调用静态库，则库中不能访问全局变量(包括函数指针)
