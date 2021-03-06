## Part4：Glade的包装（Packing）指南

​	在此Glade包装教程中，了解如何使用Glade盒容器将小部件包装到窗口中。使用小部件打包而不是固定的网格。

​	[Youtube视频教程](https://www.youtube.com/watch?v=-bKHBqBp1TA&list=PLaybP4QvyRH1obigtMQwhB2DWhPKg32_T&index=6)

​	**Glade固定网格窗口与Glade Packing窗口：**下图显示了两个窗口之间的比较。使用固定网格创建一个窗口，使用打包创建另一个窗口。调整窗口大小时，打包的窗口会自动定位小部件，而固定的网格窗口会将小部件放在同一位置。

![pic01.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic01.png)

<center>Glade固定网格窗口（左）与Glade Packing窗口（右）放大后的窗口</center>

![pic02.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic02.png)

<center>Glade固定网格（左）与Glade Packing（右）Windows减小到最小尺寸</center>

​	在两个图像中，左边的窗口是在GTK 3 C代码“ hello world”教程中使用固定网格创建的窗口。右侧的窗口是将在本教程中创建的窗口。

​	**GTK中的包装是什么：**打包是一种将小部件放置在GTK中的方法，用于将小部件放置在窗口中。打包通常是通过创建用于放置小部件的盒子来完成的。盒子是不可见的小部件，可以包含其他小部件。它们可以是垂直或水平的。可以将框放置在其他框内，以使所需数量的区域可用于放置小部件。

​	默认情况下，新的GTK窗口只能包含一个小部件。必须将诸如固定网格或框之类的容器窗口小部件放置在窗口中，以便将其他窗口小部件放置到窗口上。

​	在Glade中，通过选择中间窗格的“**容器”**菜单下的**"GtkBox”**小部件来放置**盒子**。当将框放置在窗口中时，可以选择与要放置在框中的小部件数量相对应的项目数。然后可以在“**框特性**”的“**常规”**选项卡下选择“框的**方向”**，可以选择“**垂直”**或“**水平**” 。方向确定是将小部件放置在另一个之上还是彼此相邻。

在GTK中打包是一个需要习惯的概念。请遵循以下教程，以了解如何放置用于将小部件打包的盒子。将其与固定网格示例进行比较。运行固定网格窗口应用程序和本教程中的应用程序，然后尝试调整应用程序窗口的大小以查看区别。

​	随着更高级的应用程序和窗口小部件，打包的优势将变得更加明显。包装具有一些内置的智能功能，当放置更高级的小部件（如菜单栏，滚动窗口和状态栏）时，很容易看到。这些小部件将在以后的教程中介绍。

## Glade包装示例

​	请按照以下教程步骤创建一个Glade窗口，该窗口使用Glade框容器包装小部件而不是固定网格。

### 1. 开始一个新项目

​	通过复制 [003_hello_button](https://github.com/katoluo/Learn-GTK3-Basics/tree/master/003_hello_button) 的makefile文件和main.c文件来开始一个新的项目。

​	将模板文件夹重命名为**0004_packing**。打开Makefile，然后在文件顶部将项目重命名为**packing**，如下所示。

```makefile
# change application name here (executable output name)
TARGET=packing
```

​	您的项目文件夹现在应如下所示。

![pic03.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic03.png)

### 2. 编辑Glade文件

​	进入glade文件夹，通过glade编辑器打开window_main.glade文件。

#### 2.1 将盒子容器添加到窗口

​	单击中间的窗格中的“**容器**”下的“GtkBox”，然后点击主窗口，创建成功之后，可根据下图中的红框进行设置：

![pic04.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic04.png)

#### 2.2 添加两个文本标签

​	在中间窗格中的“**显示**”中，选择GtkLabel，放入主窗口的第一和第二个框区域。使用跟[003_hello_button](https://github.com/katoluo/Learn-GTK3-Basics/tree/master/003_hello_button) 一样的标签ID和文本。这样，我们就可以在该项目中使用相同的C代码，但要了解Glade包装的工作原理。

​	Glade编辑器中的主窗口现在应如下所示。

![pic05.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic05.png)

<center>添加标签后的Glade窗口</center>

#### 2.3 添加按钮

​	将**Button**小部件从Glade的右窗格（在**控制下**）拖放到主窗口中Box小部件的最后一个（底部）区域。

​	将按钮ID更改为**btn_hello**，并将按钮文本更改为**Hello**。

​	现在，该按钮将跨越窗口的宽度。要使按钮居中，请单击Glade右窗格中的“**公共”**选项。向下滚动以找到“**组件间距”**标题，然后将“**水平的：”**从“填充”更改为“**中心”**，如下图所示。

![pic06.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic06.png)

#### 2.4 更改主窗口的宽度和标题

​	如果在Glade编辑器中单击主窗口，则将选择我们插入的GtkBox，因为它位于主窗口的顶部。要选择主窗口，请使用左上方的窗格，然后单击**window_main **。

​	在Glade右下方窗格中选择“**常规**”选项卡。向下滚动以找到默认的宽度和高度。将默认宽度更改为**180**。取消选中默认高度框。

#### 2.5 连接按钮信号

​	照着Part3可以简单完成这一步，这里省略。

​	单击顶部Glade工具栏上的齿轮图标，保存更改并预览窗口。

### 3. 应用C代码

​	这里使用Part3的main.c文件。将其赋值到本项目的src目录下即可。

### 4. 构建并运行项目

​	打开一个终端窗口，然后切换到项目所在的目录。通过在终端窗口中输入**make**来构建项目。

​	通过在终端窗口中输入**./packing**或通过从文件管理器双击项目文件夹中的打包应用程序图标来运行项目。

​	单击“ **Hello”**按钮应显示“ Hello，world！” 在第一个文本标签中，并在第二个文本标签中增加计数。可以调整窗口的大小，并且小部件现在将水平放置在窗口的中间。

![pic07.png](https://github.com/katoluo/Learn-GTK3-Basics/raw/master/004_packing/images/pic07.png)



