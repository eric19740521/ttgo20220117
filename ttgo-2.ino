#include <TFT_eSPI.h>        //LCD函式庫
#include <Button2.h>

#include "img1.h"   //載入兩個圖檔，已轉C Array
#include "font_12.h"
#include "xbm.h"             // Sketch tab header for xbm images

static const unsigned char PROGMEM str_1[] = {    //東
  0x01, 0x00, 0x01, 0x00, 0x01, 0x04, 0x7F, 0xFE, 0x01, 0x00, 0x3F, 0xF8, 0x21, 0x08, 0x3F, 0xF8,
  0x21, 0x08, 0x3F, 0xF8, 0x05, 0x40, 0x09, 0x20, 0x11, 0x10, 0x21, 0x0E, 0x41, 0x04, 0x01, 0x00
};

static const unsigned char PROGMEM str_2[] = {    //洲
  0x01, 0x04, 0x41, 0x04, 0x31, 0x24, 0x11, 0x24, 0x81, 0x24, 0x65, 0xB4, 0x2B, 0x6C, 0x0B, 0x6C,
  0x11, 0x24, 0x11, 0x24, 0x61, 0x24, 0x21, 0x24, 0x22, 0x24, 0x22, 0x24, 0x24, 0x04, 0x20, 0x04
};

static const unsigned char PROGMEM str_3[] = {     //奶
  0x10, 0x08, 0x17, 0xFC, 0x10, 0x88, 0x10, 0x88, 0xFC, 0x88, 0x24, 0x90, 0x24, 0x90, 0x24, 0xBC,
  0x24, 0x84, 0x49, 0x04, 0x29, 0x04, 0x11, 0x04, 0x2A, 0x04, 0x4A, 0x04, 0x84, 0x28, 0x08, 0x10
};

static const unsigned char PROGMEM str_4[] = {     //茶
  0x04, 0x40, 0x04, 0x44, 0xFF, 0xFE, 0x04, 0x40, 0x01, 0x00, 0x02, 0x80, 0x04, 0x40, 0x19, 0x30,
  0x21, 0x0E, 0xDF, 0xF4, 0x01, 0x00, 0x09, 0x20, 0x19, 0x18, 0x21, 0x08, 0x05, 0x00, 0x02, 0x00
};



TFT_eSPI tft = TFT_eSPI();

#define BUTTON_A_PIN  0  //按鍵A，PIN 0
#define BUTTON_B_PIN  35 //按鍵B，PIN 35
Button2 buttonA = Button2(BUTTON_A_PIN);
Button2 buttonB = Button2(BUTTON_B_PIN);

void setup()
{
  tft.begin();               // 初始化LCD
  tft.setRotation(1);  // landscape
  tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕
  tft.setSwapBytes(true);

  tft.drawRect(0, 0, 240, 130, TFT_RED);//方形空心
  tft.drawLine(0, 40, 240, 40, TFT_YELLOW);//畫線

  //文字 ESP32
  tft.setFreeFont(&FreeSerifBold12pt7b);
  // 设置起始坐标(20, 10)，4 号字体
  tft.setCursor(20, 10);
  // 设置文本颜色为白色，黑色文本背景
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(4);
  // 设置显示的文字，注意这里有个换行符 \n 产生的效果
  tft.println("ESP32");

  //文字 TTGO
  tft.setFreeFont(&FreeSerifBold12pt7b);
  // 设置起始坐标(20, 10)，4 号字体
  tft.setCursor(160, 10, 4);
  // 设置文本颜色为白色，黑色文本背景
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.setTextFont(2);
  // 设置显示的文字，注意这里有个换行符 \n 产生的效果
  tft.println("TTGO");

  //文字 T-Display
  tft.setFreeFont(&FreeSerifBold12pt7b);
  tft.setCursor(30, 95, 4);
  tft.setTextColor(TFT_BLUE);
  tft.setTextSize(2);
  tft.printf("T-Display");


  buttonA.setPressedHandler(press);   //建立A按鍵按下Pressed的事件
  buttonA.setReleasedHandler(release);//建立A按鍵放開Released的事件
  buttonB.setPressedHandler(press);   //建立B按鍵按下Pressed的事件
  buttonB.setReleasedHandler(release);//建立B按鍵放開Released的事件
}

void loop()
{
  buttonA.loop();  //重複按鍵的觸發設定
  buttonB.loop();
}

void press(Button2& btn) {
  if (btn == buttonA) {   //按下A按鍵，更換圖片

    tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕

    tft.setTextColor(TFT_RED);
    tft.setTextSize(1);                   //sets the size of text
    tft.loadFont(font_12); //指定tft屏幕对象载入font_12字库
    tft.drawString("藍芽 測試2", 0, 0);
    tft.unloadFont(); //释放字库文件,节省资源


  } else if (btn == buttonB) {  //按下B按鍵，顯示文字

    tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕

    //delay(1000);

    //tft.invertDisplay(1);//反轉---沒搞定.暫時算了
    //tft.color565(TFT_RED,TFT_WHITE,TFT_BLUE);

    tft.drawBitmap(32, 0, str_1, 16, 16, TFT_RED);  //顯示文字
    tft.drawBitmap(50, 0, str_2, 16, 16, TFT_BLUE);  //顯示文字
    tft.drawBitmap(66, 0, str_3, 16, 16, TFT_WHITE);  //顯示文字
    tft.drawBitmap(82, 0, str_4, 16, 16, TFT_WHITE);  //顯示文字

    tft.drawLine(0, 50, 240, 55, TFT_YELLOW);//畫線

  }


}

void release(Button2& btn) {
  if (btn == buttonA) {          //放開按鍵A，恢復顯示圖片
    //tft.pushImage(0, 0, 124, 52, img1);

    int x = random(tft.width()  - logoWidth);
    int y = random(tft.height() - logoHeight);

    // Draw bitmap with top left corner at x,y with foreground only color
    // Bits set to 1 plot as the defined color, bits set to 0 are not plotted
    //              x  y  xbm   xbm width  xbm height  color
    tft.drawXBitmap(x, y, logo, logoWidth, logoHeight, TFT_WHITE);


  } else if (btn == buttonB) {   //放開按鍵A，恢復顯示圖片

    //showImage(0, 0,  124, 52, img1);
    tft.pushImage(0, 0, 240, 135, matrix);  //內建一塊1.14吋240x135的TFT LCD
  }
}
