
//____________________________________________________________________________ 

void horlogeCadran() {

     tft.fillRect(0, 0, 480, 255, TFT_BLACK);  
     
      // Cadran horloge
     tft.fillCircle(120, 120, 118, TFT_LIGHTGREY);
     tft.fillCircle(120, 120, 110, TFT_BLACK);

       // Trace 12 ligne des heures
     for (int i = 0; i<360; i+= 30) {
          sx = cos((i-90)*0.0174532925);
          sy = sin((i-90)*0.0174532925);
          x0 = sx*114+120;
          yy0 = sy*114+120;
          x1 = sx*100+120;
          yy1 = sy*100+120;
          tft.drawLine(x0, yy0, x1, yy1, TFT_WHITE);
         }
       // Trace 60 point des minutes
     for (int i = 0; i<360; i+= 6) {
          sx = cos((i-90)*0.0174532925);
          sy = sin((i-90)*0.0174532925);
          x0 = sx*102+120;
          yy0 = sy*102+120;
       // Draw minute markers
          tft.drawPixel(x0, yy0, TFT_WHITE);    
       // Trace les quarts
          if (i==0 || i==180) tft.fillCircle(x0, yy0, 2, TFT_WHITE);
          if (i==90 || i==270) tft.fillCircle(x0, yy0, 2, TFT_WHITE);
         }
      tft.fillCircle(120, 121, 3, TFT_WHITE);
       
} 

//____________________________________________________________________________ 

void horlogeAfficheTemps() {
/*
     if (!OWOC.alert) { tft.fillRect(95, 95, 51, 51, TFT_BLACK); }
   
     tft.fillRect(50, 60, 135, 40, TFT_BLACK);
     tft.drawCentreString(jourTab[timeDay], 120, 65, 4);
     tft.fillRect(60, 140, 50, 40, TFT_BLACK);
     tft.drawCentreString(String(timeJour), 90, 145, 4);
     tft.fillRect(130, 140, 65, 40, TFT_BLACK);
     tft.drawCentreString(moisTab[timeMois], 155, 145, 4);
     
     tft.fillRect(30, 245, 170, 60, TFT_BLACK);
     if (hh<10) { hhTxt = "  " + String(hh); } else { hhTxt = String(hh); }
     if (mm<10) { mmTxt = "0" + String(mm); } else { mmTxt = String(mm); }
     tft.drawCentreString(hhTxt + " :" + mmTxt, 115, 250, 7);  
  
     if (mm > 59) { mm=0; }
     if (hh > 23) { hh=0; }
     if (mm < 10) { mmTxt = "0" + String(mm); } else { mmTxt = String(mm); }
*/
     // Pre-compute hand degrees, x & y coords for a fast screen update
     mdeg = mm*6+sdeg*0.01666667;  // 0-59 -> 0-360 - includes seconds
     hdeg = hh*30+mdeg*0.0833333;  // 0-11 -> 0-360 - includes minutes and seconds
     hx = cos((hdeg-90)*0.0174532925);    
     hy = sin((hdeg-90)*0.0174532925);
     mx = cos((mdeg-90)*0.0174532925);    
     my = sin((mdeg-90)*0.0174532925);

     // Erase hour and minute hand positions every minute
     tft.drawLine(ohx, ohy, 120, 121, TFT_BLACK);
     ohx = hx*62+121;    
     ohy = hy*62+121;
     tft.drawLine(omx, omy, 120, 121, TFT_BLACK);
     omx = mx*84+120;    
     omy = my*84+121;

     // Redraw new hand positions, hour and minute hands not erased here to avoid flicker
     tft.drawLine(osx, osy, 120, 121, TFT_BLACK);
     tft.drawLine(ohx, ohy, 120, 121, TFT_WHITE);
     tft.drawLine(omx, omy, 120, 121, TFT_WHITE);
     tft.fillCircle(120, 121, 3, TFT_RED);
     
}
  
