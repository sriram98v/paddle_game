#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);

int h=10, m=30, s=0, hA, mA, sA, flag =0;


void setup(){
  Serial.begin(9600);  
  u8g.setFont(u8g_font_unifont);
  
}

void get_info(void)
{
  //s=s+1;
  if(s==60){ 
    s=0; 
    m=m+1; 
  } 
  if(m==60) 
  { 
    m=0; 
    h=h+1; 
    flag=flag+1; 
  } 
  if(h==13) 
  { 
    h=1; 
  }
  //delay(1000);
  u8g.print(h);
  u8g.print(":");
  u8g.print(m);
  u8g.print(":");
  u8g.print(s);
  u8g.setPrintPos(6, 20);
  delay(125); 
   //u8g.print(q);
}
  void loop(){
    u8g.firstPage();
    do{
  
  get_info();
  
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);
  
  
  
  }while(u8g.nextPage());
  s=s+1;
  
}
