# Rfid_D_Think_M50 类的 API 描述

所有方法根据模块datasheet编写

## 构造方法

### 使用硬件串口，不知道模块ID，使用广播ID

Rfid_D_Think_M50(HardwareSerial &ser_in);

### 使用硬件串口，并设置已知的模块地址

Rfid_D_Think_M50(HardwareSerial &ser_in, uint16_t id);

注：通常用于一个串口上挂载多个不同ID的模块，节省串口数量

### 使用软件串口，不知道模块ID，使用广播ID

Rfid_D_Think_M50(SoftwareSerial &ser_in);

### 使用软件串口，并设置已知的模块地址

Rfid_D_Think_M50(SoftwareSerial &ser_in, uint16_t id);

注：通常用于一个串口上挂载多个不同ID的模块，节省串口数量



## 系统操作

以下操作返回值都为 bool，true代表成功，false代表失败

### 使能天线并设置射频模式

bool enableAntenna(uint8_t rfidMode);

### 使能天线

bool enableAntenna();

### 关闭天线，减小芯片发热

bool disableAntenna();

### 获取模块信息字符串

bool getModelInfo(char *infoBuffer);

### 设置模块ID

bool setId(uint16_t id);

注：出厂ID为0x1112，设置多个不同的ID，就可以实现一个串口上挂载多个模块，节省串口数量

##  ISO_15693 操作

### 获取标签UID

bool singleInventory(uint8_t &dsfid, uint8_t uid[]);

注：若发现标签则把读到的dsfid和8字节uid放入参数，并返回true。若未发现标签则返回false。

### 已知标签UID，读取多个块

bool read(uint8_t model, uint8_t uid[], uint8_t blockNo, uint8_t blockCnt, uint8_t data[]);

注：model 意义不明，给0即可，uid是要读的卡的uid，blockNo，是要读的起始块号(每块4字节)，blockCnt是要读的块数，data是读到的数据的存放首地址

### 已知标签UID，读取一个块

bool read(uint8_t model, uint8_t uid[], uint8_t blockNo, uint8_t data[]);

### 自动发现标签，读取多个块

bool read(uint8_t blockNo, uint8_t blockCnt, uint8_t data[]);

### 自动发现标签，读取一个块

bool read(uint8_t blockNo, uint8_t data[]);

### 关于写块、锁块、读取锁状态等更多API，请阅读 Rfid_D_Think_M50.h
