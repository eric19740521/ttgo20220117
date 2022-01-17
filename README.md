ESP32實驗: TTGO T-Display ,使用 TFT_eSPI 控制螢幕顯示 中文/圖檔

參考資料:
https://www.cxymm.net/article/qq_35274097/111501933
https://hackmd.io/@Shinjia/ByYd0XXo8/%2FGTu9Ew4EQHKXpcwWC2uLGQ
https://chowdera.com/2021/09/20210918113606411C.html
https://www.flaticon.com/stickers-packs/4?order_by=4

1.esp32設定
https://dl.espressif.com/dl/package_esp32_index.json

2.程式庫管理員 --> TFT-eSPI和Button2 安裝lib

3.偏好設定.草稿碼簿的位置
C:\Users\user\Documents\Arduino\libraries\TFT_eSPI
找到User_Setup_Select.h檔案並開啟。


#include <User_Setup.h> //把這行註解掉。
#include <User_Setups/Setup25_TTGO_T_Display.h>		 //把這行已註解.拿掉。


4.開發板選擇「ESP32 Dev Module」。
連接埠 ...裝置管理員查看???


5.燒錄鍵..不需要按

程式碼
https://github.com/eric19740521/ttgo20220117
