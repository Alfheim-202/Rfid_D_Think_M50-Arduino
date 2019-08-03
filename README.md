![test](https://img.shields.io/badge/test-passing-green.svg)
![docs](https://img.shields.io/badge/docs-passing-green.svg)
![docs](https://img.shields.io/badge/platform-UNO|Nano|Mega2560-blue.svg)

D-Think_M50 Rfid 模块 Arduino 库
===========================

该库用 Arduino 的 **硬串口** 或 **软串口** 与 **D-Think_M50模块** 通信，完成 **ISO15693电子标签** 读写。参考资料：[模块datasheet](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/D-Think_M50D_DataSheet_CN_ISO15693.pdf)。

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/RFID_UNO_Connection.jpg)

# 使用方法

### 步骤一：安装 Arduino IDE

如果你还没有安装 **Arduino IDE** ，请前往[Arduino官网](https://www.arduino.cc/en/Main/Software)下载。安装后找到其路径，比如在笔者电脑里，路径是 **C:\\Arduino\\**

### 步骤二：下载该库并解压

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op1.png)

### 步骤三：移动文件夹

移动解压得到的文件夹，到 **[Arduino IDE安装目录]\\libraries** 。比如在笔者电脑里，应该移动到 **C:\\Arduino\\libraries**

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op2.png)

### 步骤四：打开示例

该库提供了丰富的示例，我们先试试 **读取块** 示例，打开 **Arduino IDE** , 在 **左上角菜单栏** 中，点击 **file->examples->Rfid_D_Think_M50** ，会看到很多示例，请依据你的Arduino型号做出选择：

* 若你的Arduino **只有一个硬件串口**（比如 **Arduino UNO** 、 **Arduino Nano** ），则需要软串口与模块通信，请选择以 **SoftSerial** 为结尾的示例。这里，我们选择示例: **readBlock_SoftSerial**
* 若你的Arduino **有多个硬件串口**（比如 **Arduino Mega2560** ），则可以用硬串口与模块通信，请选择以 **HardSerial** 为结尾的示例。这里，我们选择示例: **readBlock_HardSerial**

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op3.png)

### 步骤五：运行示例

每个示例都有 **详细的注释** ，包括功能详述和如何连线等，请 **按照注释去做**，并烧录程序和进行测试。

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op4.png)

# 示例介绍

* **getLockStatus_HardSerial** 和 **getLockStatus_SoftSerial** : 获取块是否上锁
* **lockBlock_HardSerial** 和 **lockBlock_SoftSerial** : 为块 **加锁** ，加锁后不可再写。 **警告**：加锁后 **无法解锁**
* **ReadBlock_HardSerial** 和 **ReadBlock_SoftSerial** : 读块
* **WriteBlock_HardSerial** 和 **WriteBlock_SoftSerial** : 写块
* **Read_Write_Lock_HardSerial** 和 **Read_Write_Lock_SoftSerial** : 提供交互式的 **读、写、锁、查看锁**
