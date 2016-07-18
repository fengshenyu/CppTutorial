## 环境
OS:win7 专业版SP1 64位
编译器: VS 2013 express 的cl
## 软件
windows上运行OpenGL ES要用到第三方的头文件,库文件和dll.下载地址 http://pan.baidu.com/s/1cupJoq
## 配制
%VS_HOME%代表VS的安装目录. %OpenGLES%代表上步中软件文件夹的根目录.
把%OpenGLES%\include\*.h复制到%VS_HOME%\VC\include\中
把%OpenGLES%\lib\*.lib复制到%VS_HOME%\VC\lib
把%OpenGLES%\dll\*.dll复制到C:\Windows\System32
## 编译链接运行
1. 下载源代码.以ch01_HelloWorld为例说明.
2. 单击"开始"--"Visual Studio 2013"--"Visual Studio Tools"--"VS2013 x86 Native Tools Command Prompt",打开命令行.切换到ch01_HelloWorld目录.
3. 执行
```
cl /c /EHsc main.cpp
```
只编译.不链接.
4. 执行
```
link /subsystem:windows  user32.lib gdi32.lib  libEGL.lib libGLESv2.lib main.obj
```
生成可执行文件.
4. 运行可执行文件.
```
main.exe
```