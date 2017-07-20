// D-Think_M50 Rfid 模块 读取一块数据示例（软串口）
// 2016/08/19
//
// 功能： 尝试寻找 Rfid 标签并读取其第0块数据（前4字节）
//        每 0.3 秒检测一次
//        若Rfid标签在读取范围，则读取结果打印到串口0
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
    // 以 ISO15693 为例
    if( rfid.enableAntenna( rfid.ISO15693 ) ){
        Serial.println("init ok");
    }else{
        Serial.println("init failed");
        for(;;);
    }
}

void loop() {

    // 若读取不频繁，为节省功耗，减小发热，则在读操作之前使能天线，读操作之后关闭天线
    // rfid.enableAntenna( rfid.ISO15693 );  // 能达到相同的效果
    rfid.enableAntenna();

    // 用于存放读取结果，一块=4字节
    uint8_t data[4];

    // 尝试读取第 BLOCK_NO 块数据
    if( rfid.read(BLOCK_NO, data) ){
        // 若读取成功，在串口0打印读取结果
        for(int j=0; j<4; j++){
            Serial.print(data[j], HEX);
            Serial.print(' ');
        }
        Serial.println();
    }else{
        // 若读取失败
        Serial.println("no card!");
    }

    // 读操作之后关闭天线，否则芯片发热
    rfid.disableAntenna();

    // 延时 0.3 秒后循环读取。
    // 若想读的更频繁，可以注释掉 rfid.enableAntenna(); rfid.disableAntenna(); delay(300); 这三句。
    // 但不能避免芯片发热
    delay(300);
}
