// D-Think_M50 Rfid 模块 写入一块数据示例
// 2016/08/19
//
// 功能： 尝试寻找 Rfid 标签并写其第0块数据（前4字节）为 0x12345678
//        每 1.0 秒检测一次
//        若Rfid标签在读取范围，则写入内容，然后立即读取，验证读取内容是否为0x12345678
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

    uint8_t writedata[] = {0x12, 0x34, 0x56, 0x78};
    uint8_t readdata[4] = {0x00};

    // 尝试写第 BLOCK_NO 块数据
    if( rfid.write(BLOCK_NO, writedata) ){
        // 尝试读第 BLOCK_NO 块数据
        if( rfid.read(BLOCK_NO, readdata) ){
            Serial.print("write data: ");
            for(int j=0; j<4; j++){
                Serial.print(writedata[j], HEX);
                Serial.print(' ');
            }
            Serial.print("    read result: ");
            for(int j=0; j<4; j++){
                Serial.print(readdata[j], HEX);
                Serial.print(' ');
            }
            if( memcmp(readdata, writedata, 4) == 0 ){
                Serial.print("    verify ok!");
            }else{
                Serial.print("    verify error! the block might be locked.");
            }
            Serial.println();
        }else{
            Serial.println("no card!");
        }
    }else{
        Serial.println("no card!");
    }

    rfid.disableAntenna();
    delay(1000);
}
