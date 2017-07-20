// D-Think_M50 Rfid 模块 锁一块数据示例
// 2016/08/19
//
// 功能： 尝试寻找 Rfid 标签并锁其第0块数据（前4字节），锁之后该块只读，不可写
//        每 1.0 秒检测一次
//        警告：锁之后不能再解锁，运行此程序前请写入正确的数据。
//
// 注意： 请使用具有不止一个硬件串口的 Arduino 型号。比如：
//          Arduino 101、 Arduino Mega2560、 Arduino DUE、 Arduino Zero、 Teensy 等
//        以下 Arduino 型号只具有1个串口，在与PC通信时无法使用该例程。请参考软串口示例
//          Arduino UNO、 Arduino Nano、 Arduino Pro Mini 等
//
// 接线： Arduino   |    D-Think_M50 模块
//          5V      |        VCC
//          GND     |        GND
//          TX1     |        RX
//          RX1     |        TX
//
// 模块耗电量大，建议使用外部电源供电.
//
#include "Rfid_D_Think_M50.h"

// 待读取的块号 = 0
#define BLOCK_NO  0

// 使用 硬件串口Serial1 与 Rfid 模块通信
Rfid_D_Think_M50 rfid( Serial1 );

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

    // 尝试锁第 BLOCK_NO 块
    if( rfid.lock(BLOCK_NO) ){
        Serial.println("block locked!");
    }else{
        Serial.println("no card!");
    }

    rfid.disableAntenna();
    delay(1000);
}

