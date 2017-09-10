// D-Think_M50 Rfid 模块 交互式读、写、锁卡程序
// 2016/08/19
// 操作指南：上传后打开ArduinoIDE自带的串口监视器，结束符设置为“换行符”，之后按照提示去做。
//           若波特率设置不为115200，则设置为115200，然后按下Arduino上的Reset键，并按提示去做
//           若显示Rfid module初始化失败，请插拔Arduino重新尝试
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

// 被操作的块号 = 0
#define BLOCK_NO      (0)
// 每块字节数 = 4
#define BLOCK_SIZE    (4)

// 初始化软串口、指定 RX=2， TX=3
SoftwareSerial softSerial(2,3);

// 使用 软件串口softSerial 与 Rfid 模块通信
Rfid_D_Think_M50 rfid( softSerial );

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(0xffffffff);
  while (!Serial);

  // 使能天线并设置射频工作模式
  if ( rfid.enableAntenna( rfid.ISO15693 ) ) {
    Serial.print("Rfid module ready.");
  } else {
    Serial.print("Rfid module initialized failed!nTry to REPLUG the Arduino's USB");
    for (;;);
  }
  rfid.disableAntenna();
}

void loop() {
  uint8_t data[BLOCK_SIZE] = {0x00};
  char    buffer[0x100];
  int     ch;
  bool    ret_code, isLocked;

  for (int i = 0; i < BLOCK_SIZE; i++)
    data[i] = 0;

  Serial.print("\n\nMenu:\n    1. Read\n    2. Write Byte at address 0\n    3. Write Byte at address 1\n    4. Check Lock Status\n    5. Lock\nPlease input your option:");

  for (;;) {
    ch = Serial.read();
    if ( ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ) {
      Serial.write(ch);
      Serial.print("\n\n");
      break;
    }
  }

  rfid.enableAntenna();
  if ( ch == '1' ) {
    ret_code = rfid.read(BLOCK_NO, data);
  } else if ( ch == '2' || ch == '3') {
    Serial.println("input the number you want to write:");
    int b = Serial.parseInt();
    if ( ch == '2' )
      data[0] = b;
    else if ( ch == '3' )
      data[1] = b;
    ret_code = rfid.write(BLOCK_NO, data);
  } else if ( ch == '4' ) {
    ret_code = rfid.getLockStatus(BLOCK_NO, isLocked);
  } else if ( ch == '5' ) {
    ret_code = rfid.lock(BLOCK_NO);
  }
  rfid.disableAntenna();

  if ( ret_code ) {
    if ( ch == '1' ) {
      sprintf(buffer, "read result:  0x%02x 0x%02x 0x%02x 0x%02x\n", data[0], data[1], data[2], data[3]);
      Serial.print(buffer);
    } else if ( ch == '2' || ch == '3' ) {
      sprintf(buffer, "write success!  0x%02x 0x%02x 0x%02x 0x%02x\n", data[0], data[1], data[2], data[3]);
      Serial.print(buffer);
    } else if ( ch == '4' ) {
      if (isLocked)
        Serial.print("Block already locked.\n");
      else
        Serial.print("Block NOT locked.\n");
    } else if ( ch == '5' ) {
      Serial.print("Block locked success.");
    }
  } else {
    Serial.println("Failed!");
  }

}