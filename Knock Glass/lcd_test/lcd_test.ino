 // TECHATRONIC.COM  
 //LIBRARY FOR I2C LDC  
 //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library  
 #include <Wire.h>           
 #include <LiquidCrystal_I2C.h>    
 LiquidCrystal_I2C lcd(0x27,16,2);   
 // if lcd is not print then use this 0x27..  
 void setup()  
  {  
   lcd.begin();      
   lcd.backlight();  
  }  
 void loop()   
  {  
   lcd.setCursor(0,0);  
   lcd.print("   Helo  ");  
   lcd.setCursor(0,1);  
   lcd.print("  Friend ");  
  }  