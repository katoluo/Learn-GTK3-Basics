# 1. 编译GLib C程序

​	[GLib](https://wiki.gnome.org/Projects/GLib)是GTK +所需的实用程序库，但也可以在非GUI应用程序中独立使用。本文介绍了如何在Linux中编译使用GLib的C程序。它还显示了如何为系统上安装的GLib版本安装正确的文档，以及如何查找当前安装的GLib库的版本号。

​	本文中使用的命令和库已在Manjaro Linux x86_64上进行了测试，在编译程序之前，请确保已在系统上安装了GLib开发库。

​	[Youtube视频教程](https://www.youtube.com/watch?v=giKcvEMN5pg&list=PLaybP4QvyRH1obigtMQwhB2DWhPKg32_T&index=7)

​	[GLib Reference Manual](https://developer.gnome.org/glib/2.66/)

## 1.1 编译一个简单的GLib C程序

​	下面的示例程序是一个使用GLib函数编写的简单的“ Hello World” C程序。代码清单下方显示了在Linux上编译程序的说明。

```c
#include <glib.h>

int main(void)
{
	g_print("Hello, world!\n");
	return 0;
}
```

​	在命令行中使用以下命令来编译上述程序：

```bash
gcc example1.c `pkg-config --cflags --libs glib-2.0` -o example1
```

​	在上面的行中，使用反引号（`）而不是单引号（'）将pkg-config及其选项括起来。或使用：

```bash
gcc example1.c $(pkg-config --cflags --libs glib-2.0) -o example1
```

​	可以从命令行如下运行名为**example1**的已编译程序：

```bash
./example1
```

## 1.2 安装GLib帮助

​	安装系统上安装的GLib版本的GLib帮助文档。

```bash
sudo apt-get install libglib2.0-doc
```

​	可以在Devhelp中查看帮助文件。使用以下命令安装Devhelp：

```bash
sudo apt-get install devhelp
```

​	下图显示了在Devhelp中打开的GLib参考手册。



## 1.3 查找GLib的版本号



### 1.3.1 使用pkg-config

​	在终端窗口中输入以下命令将显示当前安装的GLib版本。

```bash
pkg-config --modversion glib-2.0
```

### 1.3.2 以编程方式

​	编译并运行以下程序时，它将显示GLib的当前版本。

```c
#include <glib.h>

int main(void)
{
	g_print("glib version number is %d.%d.%d\n", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
	g_print("GLIB_MAJOR_VERSION = %d\n", GLIB_MAJOR_VERSION);
	g_print("GLIB_MINOR_VERSION = %d\n", GLIB_MINOR_VERSION);
	g_print("GLIB_MICRO_VERSION = %d\n", GLIB_MICRO_VERSION);
	return 0;
}
```

​	编译使用：

```bash
gcc example2.c `pkg-config --cflags --libs glib-2.0` -o example2
```

​	或者：

```bash
gcc example2.c $(pkg-config --cflags --libs glib-2.0) -o example2
```

​	运行：

```bash
./example2
```

## 1.4 GLib C投币示例程序

​	另一个GLib C程序，用于模拟抛硬币。运行该程序时，它将“ **Heads”**或“ **Tails”**打印到终端窗口。抛硬币的正面或反面由**g_random_boolean（）**函数确定。

```c
#include <glib.h>

int main(void)
{
	gboolean result;
	
	result = g_random_boolean();
	if (result == TRUE) {
		g_print("Heads\n");
	}
	else {
		g_print("Tails\n");
	}
	return 0;
}
```

​	编译使用：

```bash
gcc example3.c`pkg-config --cflags --libs glib-2.0` -o example3
```

​	要么：

```bash
gcc example3.c $（pkg-config --cflags --libs glib-2.0）-o example3
```

​	运行：

```bash
./example3
```

# 2. Glade Gtk C投币示例程序

​	