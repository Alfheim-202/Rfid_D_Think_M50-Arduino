// D-Think_M50 Rfid 模块 获取锁状态示例
// 2016/08/19
//
// 功能： 尝试寻找 Rfid 标签并查看其第0块数据的是否被锁，
//        每 1.0 秒检测一次
//
// 注意： 因为使用软串口，该示例兼容硬件串口不够的 Arduino 型号：
//          Arduino UNO、 Arduino Nano、 Arduino Pro Mini 等
//
// 接线： Arduino   |    D-Think_M50 模块
//          5V      |        VCC
//          GND     |        GND
//     3(软串口TX)  |         RX
//     2(软串口RX)  |         TX
//
// 模块耗电量大，建议使用外部电源供电.
//


#include <SoftwareSerial.h>
#include "Rfid_D_Think_M50.h"

// 待读取的块号 = 0
#define BLOCK_NO  0

// 初始化软串口、指定 RX=2， TX=3
SoftwareSerial softSerial(2,3);

// 使用 软件串口softSerial 与 Rfid 模块通信
Rfid_D_Think_M50 rfid( softSerial );

void setup() {
    Serial.begin(9600);

    // 使能天线并设置射频工作模式
    if( rfid.enableAntenna( rfid.ISO15693 ) ){
        Serial.println("init ok");
    }else{
        Serial.println("init failed");
        for(;;);
    }
}

void loop() {
    rfid.enableAntenna();

    bool isLocked;

    // 尝试锁第 BLOCK_NO 块
    if( rfid.getLockStatus(BLOCK_NO, isLocked) ){
        if(isLocked){
            Serial.println("block already locked.");
        }else{
            Serial.println("block not locked.");
        }
    }else{
        Serial.println("no card!");
    }

    rfid.disableAntenna();
    delay(1000);
}

