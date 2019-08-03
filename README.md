![test](https://img.shields.io/badge/test-passing-green.svg)
![docs](https://img.shields.io/badge/docs-passing-green.svg)
![docs](https://img.shields.io/badge/platform-UNO|Nano|Mega2560-blue.svg)

D-Think_M50 Rfid ģ�� Arduino ��
===========================

�ÿ�ʹ�� Arduino �� **Ӳ����** �� **����** �� **D-Think_M50ģ��** ͨ�ţ���� **ISO15693���ӱ�ǩ** ��д���ÿ����� [ģ��datasheet](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/D-Think_M50D_DataSheet_CN_ISO15693.pdf) ��д��

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/RFID_UNO_Connection.jpg)

# ʹ�÷���

### ��װ Arduino IDE

�����û�а�װArduino IDE����Ҫ��װ������ǰ��[Arduino��������](https://www.arduino.cc/en/Main/Software)����װ���ҵ���·���������ڱ��ߵ����·���� **C:\\Arduino\\**

### ���ظÿⲢ��ѹ

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op1.png)

### �ƶ��ÿ⵽Arduino IDE�Ŀ��ļ���

�ƶ���ѹ�õ����ļ��У��� **[���Arduino IDE��װĿ¼]\\libraries** �������ڱ��ߵ����Ӧ���ƶ��� **C:\\Arduino\\libraries**

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op2.png)

### ����ʾ��

�ÿ��ṩ�˷ḻ��ʾ�������������� **��ȡ��** ʾ����**��** �� **����** **Arduino IDE** , ��� **file->examples->Rfid_D_Think_M50** ���ῴ���ܶ�ʾ�������У�

* �����Arduino **ֻ��һ��Ӳ������**������ **Arduino UNO** �� **Arduino Nano** ��������Ҫ������ģ��ͨ�ţ���ѡ���� **SoftSerial** Ϊ��β��ʾ�����������ѡ��ʾ��: **readBlock_SoftSerial**
* �����Arduino **�ж��Ӳ������**������ **Arduino Mega2560** �����������Ӳ������ģ��ͨ�ţ���ѡ���� **HardSerial** Ϊ��β��ʾ�����������ѡ��ʾ��: **readBlock_HardSerial**

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op3.png)

![image](https://github.com/WangXuan95/Rfid_D_Think_M50-Arduino/blob/master/doc/op4.png)

# ʾ������

* **getLockStatus_HardSerial** �� **getLockStatus_SoftSerial** : ��ȡ���Ƿ�����
* **lockBlock_HardSerial** �� **lockBlock_SoftSerial** : Ϊ�� **����** �������󲻿���д�� **����**�������� **�޷�����**
* **ReadBlock_HardSerial** �� **ReadBlock_SoftSerial** : ����
* **WriteBlock_HardSerial** �� **WriteBlock_SoftSerial** : д��
* **Read_Write_Lock_HardSerial** �� **Read_Write_Lock_SoftSerial** : �ṩ����ʽ�� **����д�������鿴��**
