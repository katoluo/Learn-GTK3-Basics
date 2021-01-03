## Part3：使用Glade的GTK3 C代码的Hello World教程

​	在这个面向初学者的简单教程中，使用GTK + 3创建了一个简单的“ Hello World”程序，并使用C编程语言进行了编程。Glade 3在此GTK 3 C代码hello world教程中用于创建GUI窗口，按钮和文本标签。

​	下图显示了本教程中制作的带窗口的Hello World应用程序。第一次单击窗口中的按钮时，文本“ Hello，world！” 在窗口中显示。每次单击按钮时，按钮的点击总数都会更新并显示在窗口中。

​                                          <img src="https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic01.png" alt="pic01.png" style="zoom:60%;" /> <img src="https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic02.png" alt="pic02.png" style="zoom:60%;" />

​	本教程（[Youtube视频教程](https://www.youtube.com/watch?v=oWeYD3vg2xA&list=PLaybP4QvyRH1obigtMQwhB2DWhPKg32_T&index=5)）演示了按钮和文本标签的用法，以及如何获取指向文本标签的句柄或指针以更改其文本。

### 1. 开始一个新的GTK+3 Glade C项目

​	最简单的方法是从一组GTK + 3 Glade C编程模板文件开始，该文件通过将C源代码文件和Glade文件分离到各自的文件夹中，从而为程序添加了一个不错的结构。模板文件包括：

- 包含**src**文件夹的main()函数的main.c文件
- 在**glade**文件夹中的主glade窗口，名为window_main.glade，已连接了目标信号回调处理程序功能
- 在项目的主文件夹中用于生成项目的名为makefile的生成文件
- main.c文件中的某些框架源代码，使用Glade文件创建项目的主窗口

#### 1.1 创建一组模板文件

![pic03.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic03.png)

[Makefile文件](https://github.com/katoluo/Learn-GTK3-Basics/blob/master/003_hello_button/Makefile)

### 2. 编辑Glade文件

​	打开Glade，创建一个新项目，单击“**顶层**”下的GtkWindow，按照图片更改信息。

图1：按照红框编辑。

![pic04.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic04.png)

图2：点击”**信号**“，找到”GtkWidget“下的”destory“，在”处理函数“列双击，输入on之后会列出函数，选中之后在回车确定。

![pic05.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic05.png)

#### 2.1 添加固定网格

​	尽管GTK有在窗口中打包小部件的方法，但在本教程中我们将使用固定的网格。

​	单击”**容器**“下的”GtkFixed“，然后单击主窗口以放置网格。

​	如果没有固定的网格，则无法放置按钮和文本标签。

#### 2.2 放置文字标签

​	该项目使用两个文本标签 —— 一个用于显示hello world文本，另一个用于显示单击按钮的次数。

​	**2.2.1 放置标签**

​	单击”显示“下的”GtkLabel“。单击网格上的主窗口以放置标签，使用拖动/调整大小工具将标签体懂到所需位置。如下图：

![pic06.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic06.png)

​	**2.2.2 调整标签大小**

​	如下图所示调整标签的大小。

![pic07.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic07.png)

​	**2.2.3 更改标签ID和文本**

​	在左侧窗格中，选择标签，然后单击”**常规**“，在”**ID**“框中将标签的ID更改为**label_hello**，在”**标签**“框中将标签的文本更改为...。如下图所示：

![pic08.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic08.png)

​	**2.2.4 添加第二个标签**

​	创建具有与第一个标签相同的高度和文本的第二个标签，但是给它一个ID为**label_count**并将其放在第一个标签下。在右侧窗格中”**包装**“也能调整标签的位置。按照之前的就可以完成这个操作。

#### 2.3 放置和编辑按钮

​	在Glade的中间窗格中，单击”**控制**“下的”GtkButton“。单击主窗口网格以放置按钮。在更改文本高度的位置，将按钮的高度更改为30（右窗格，”公共“选项，”高度请求“字段）。

​	在“**常规”**选项卡下，将按钮ID更改为**btn_hello**，并将该按钮的文本更改为**hello**。将按钮放在第二个标签下。如下图所示：

![pic09.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic09.png)

#### 2.4 更改窗口大小和标题

​	单击Glade左侧窗格中的**window_main**以选择主窗口。在右窗格的”**常规**“选项下，将”默认高度“和”默认宽度“字段中的窗口宽度和高度都更改为200。将”标题“字段中的窗口标题更改为”Hello World“。

​	单击预览快照齿轮图标以查看窗口的预览，以确保小部件正确地适合窗口。

​	如下图所示：

![pic10.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic10.png)

#### 2.5 按钮回调功能信号

​	单击该按钮时，将发出信号。我们需要在信号上附加一个函数，以便在单击按钮时调用该函数。

​	单击Glade中的按钮将其选中，然后单击Glade编辑器右窗格中的**信号**选项卡。单击“**处理函数”**标题下的文本，然后**单击**以将其选中，然后再次**单击**以开始对其进行编辑。键入**on**，然后将弹出Glade建议的名称（on_btn_hello_clicked）。按向下箭头键将其选中，然后按两次Enter键进行更改。如下图所示：

![pic11.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/003_hello_button/images/pic11.png)

​	保存Glade文件到glade目录，我们现在将编辑C源代码。

### 3. 编写C代码

​	构建应用程序之前的最后一步是为此GTK 3 C代码Hello World教程编写C代码。

​	打开在项目的**src**文件夹中找到的**main.c** C模板文件以进行编辑。

​	我们需要一个指向项目中每个标签的指针，以便可以握住标签来更改其文本。在这个简单的项目中，在C文件的顶部定义了两个全局指针。

```c
#include <gtk / gtk.h> 

GtkWidget * g_lbl_hello; 
GtkWidget * g_lbl_count;
```

​	连接代码中的信号后，获得指向两个标签的指针：

```c
gtk_builder_connect_signals（builder，NULL）; 
    
g_lbl_hello = GTK_WIDGET（gtk_builder_get_object（builder，“ label_hello”））; 
g_lbl_count = GTK_WIDGET（gtk_builder_get_object（builder，“ label_count”））;
```

​	最后，我们必须添加一个将文本写入第一个标签并在单击按钮时增加第二个标签计数的函数。此功能必须与Glade中为按钮设置的信号处理函数功能名称相同。

```c
void on_btn_hello_clicked()
{
    static unsigned int count = 0;
    char str_count[30] = {0};
    
    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);
}
```

​	最终代码：[main.c](https://github.com/katoluo/Learn-GTK3-Basics/blob/master/003_hello_button/src/main.c)

### 4. 构建并运行项目

​	在终端窗口中打开模板目录，并通过输入make命令使用make文件来构建项目。

```bash
make
```

​	可以通过使用文件管理器导航到项目文件夹后双击hello图标来运行该项目，也可以在终端窗口中输入以下命令来运行该项目：

```bash
./hello
```

​	Hello World窗口应打开。单击“ Hello”按钮应显示“ Hello，world！” 在第一个标签中输入文本，并在第二个标签中增加计数。