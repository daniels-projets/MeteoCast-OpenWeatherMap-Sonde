//____________________________________________________________________________ 

void sondeDatas() {

     Serial.println(temp); delay(50);
     graph = map(temp, -25, 45, 180, 0);
     Serial.println(graph); delay(50);
     drawBmp("/thermograph.bmp", 250, 0);
     tft.fillRect(290, 35, 12, graph, TFT_LIGHTGREY);
     tft.fillRect(350, 45, 85, 55, TFT_BLACK);
     tft.drawRightString(String(temp), 435, 50, 7);
     drawBmp("/celsius.bmp", 435, 45);
     drawBmp("/humid.bmp", 400, 130);
     tft.fillRect(375, 190, 85, 50, TFT_BLACK);
     tft.drawRightString(String(humid) + " %", 455, 200, 4);     
  
}
