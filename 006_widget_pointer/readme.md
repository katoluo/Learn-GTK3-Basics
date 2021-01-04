# 在回调函数GTK Glade中获取小部件指针

​	如何在Glade GTK C程序的回调函数中获取小部件指针。通过回调函数的*gpointer user_data*参数将指向单个小部件的指针传递给回调函数。

![pic01.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic01.png)

<center>在回调函数中获取小部件指针</center>

​	[Youtube视频教程](https://www.youtube.com/watch?v=5eR_2wSq3Ik&list=PLaybP4QvyRH1obigtMQwhB2DWhPKg32_T&index=10)

## 1. 如何在回调函数中获取小部件指针

​	在先前的文章中，使用全局变量获取指向文本标签小部件的指针，以便在单击应用程序中的按钮时可以更新标签中的文本。为了避免使用全局变量，可以将指向标签的指针传递给按钮的回调函数。

​	单击应用程序中的按钮时，它将发出一个信号，该信号导致调用按钮单击的处理程序。处理函数的第二个参数，即用户数据参数，可用于将指针传递给文本标签小部件。然后可以在回调函数中更新标签小部件中的文本，而无需指向标签小部件的全局指针。如下面的教程所示，这是在Glade内部设置的。



## 2. Glade C程序的回调函数中的小部件指针

​	以下教程步骤显示了如何使用Glade 3构建GTK + 3 C程序，该程序通过按钮的单击信号的回调函数将指针传递到单个小部件。

### 2.1 创建一个新的GTK Glade C程序

​	通过复制[GTK + 3 Glade 3 C程序模板文件](https://github.com/katoluo/Learn-GTK3-Basics/tree/master/template_dir)开始一个新项目。将项目文件夹重命名为**006_widget_pointer**。将makefile中的应用程序名称重命名为**widget_pointer**。现在，makefile应如下所示。

```makefile
# change application name here (executable output name)
TARGET=glade_widget_pointer

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=    main.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) -o main.o
    
clean:
	rm -f *.o $(TARGET)
```

### 2.2 在Glade中布置应用程序窗口

​	从项目glade目录中使用glade编辑器打开**window_main.glade**文件

​	大概的详细设置如下图所示：

![pic03.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic03.png)

​	将标签的**ID**更改为**lbl_text**，在**Label**字段中将标签文本更改为**…**。

​	将按钮的**ID**更改为**btn_print_txt**，并将按钮的文本更改为**Print Text**。

![pic02.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic02.png)

​	在Glade中，选择Glade中的按钮小部件，然后单击Glade右窗格中的**Signals**选项卡。在**Handler**下的**clicked**信号旁边，创建回调函数的名称 **on_btn_print_txt_clicked**。

​	回调函数中的窗口小部件指针：这是指向标签窗口小部件的指针传递到按钮回调函数的位置。现在，单击回调函数名称旁边“**用户数据”**下的铅笔图标。在弹出的对话框中，选择**lbl_text**，然后单击“**确定”**按钮。

### 2.3 修改C程序

​	从项目的**src**文件夹中打开**main.c**文件进行编辑。现在必须将按钮单击信号的回调函数添加到C代码中。

#### 2.3.1 查找正确的回调函数格式

​	如果系统上[安装](https://prognotes.net/2016/03/gtk-3-reference-manual-devhelp-viewer/)了[Devhelp应用程序，并且安装](https://prognotes.net/2016/03/gtk-3-reference-manual-devhelp-viewer/)[了GTK](https://prognotes.net/2016/03/gtk-3-help-finding-gtk3-documentation/)的[帮助文件，则](https://prognotes.net/2016/03/gtk-3-help-finding-gtk3-documentation/)Glade中按钮的clicked事件旁边将出现一个小的Devhelp图标。单击该图标可为单击按钮的信号找到正确的回调函数格式。

​	单击图标后，Devhelp将打开，其中包含有关单击按钮信号的以下信息。

![pic04.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic04.png)

<center>按钮单击信号上的Devhelp信息</center>

```c
void user_function (GtkButton *button, gpointer user_data)
```

​	如上所示，按钮单击信号的回调函数有两个参数-第一个参数是指向按钮本身的指针，第二个参数是指向用户数据的指针。用户数据在Glade应用程序中被设置为指向标签的指针。由于gpointer被定义为指向void的指针，因此GtkLabel可以作为用户数据传递，而无需在回调函数中进行强制转换。因此，该功能可以定义如下。

```c
void on_btn_print_txt_clicked(GtkButton *button, GtkLabel *text_label)
```

#### 2.3.2 在C代码中添加回调函数

​	将回调函数添加到更改标签中文本的代码中。该程序的完整最终清单如下。

```c
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_btn_print_txt_clicked(GtkButton *button, GtkLabel *text_label)
{
    gtk_label_set_text(text_label, "You clicked the button!");
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
```

​	从代码中可以看出，指向文本标签的指针传递给了单击按钮的回调函数。指向标签的指针作为用户数据传递，并在Glade中设置。这是我们在回调函数*on_btn_print_txt_clicked（）中*获得标签窗口小部件指针的位置。然后可以调用**gtk_label_set_text（）**，并将指向文本标签的指针传递给它，而不需要任何强制转换。

### 2.4 Build the Project

​	打开一个终端窗口，然后转到项目目录。通过在终端窗口中输入**make**来构建项目。通过在终端窗口中输入**./widget_pointer**来运行程序。

​	启动应用程序后，单击按钮，标签中的文本应如下所示更改。

​      <img src="https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic05.png" alt="pic05.png" style="zoom:80%;" />      <img src="https://github.com/katoluo/Learn-GTK3-Basics/raw/master/006_widget_pointer/images/pic06.png" alt="pic06.png" style="zoom:80%;" />



