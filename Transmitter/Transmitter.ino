#include <RH_ASK.h>
#include <LiquidCrystal.h>
#include <SPI.h> // Not actually used but needed to compile
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RH_ASK driver;
int row[]={2,3,4,5};//c4,c3,c2,c1
int col[]={6,7,8,9};//r4,r3,r2,r1
int x=0;
int y=0;
int stat =1;
char keys;

void setup()
lcd.begin(16, 2);
{
for (int x=0; x<=3;x++)
{pinMode(row[x],OUTPUT);
pinMode(col[x],INPUT_PULLUP);
}
Serial.begin(9600); // Debugging only
if (!driver.init())
Serial.println("init failed");
}
void loop()
{ for(x=0; x<=3; x++)
{digitalWrite(row[0],1);
digitalWrite(row[1],1);
digitalWrite(row[2],1);
digitalWrite(row[3],1);
digitalWrite(row[x],0);
for(y=0; y<=3; y++)
{ stat= digitalRead(col[y]);
if(stat==LOW)
{ pressedkeys(x,y);
lcd.setCursor(0, 1);
lcd.print(keys);
delay(100)
//Serial.print(keys );
//delay(100);
}}
if(y==3)
{y=0;
}
delay(5);
}
if(x==3)
{x=0;
}
}
void pressedkeys (int x, int y)
{
if(x==0&&y==0)
{ keys='A';
char *msg = "a";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==0&&y==1)
{ keys='B';
char *msg = "b";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==0&&y==2)
{ keys='C';
char *msg = "c";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==0&&y==3)
{ keys='D';
char *msg = "d";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==1&&y==0)
{ keys='E';
char *msg = "e";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==1&&y==1)
{ keys='F';
char *msg = "f";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==1&&y==2)
{ keys='G';
char *msg = "g";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==1&&y==3)
{ keys='H';
char *msg = "h";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==2&&y==0)
{ keys='I';
char *msg = "i";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==2&&y==1)
{ keys='J';
char *msg = "j";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==2&&y==2)
{ keys='K';
char *msg = "k";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);
}
if(x==2&&y==3)
{ keys='L';
char *msg = "l";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);}
if(x==3&&y==0)
{ keys='L';
char *msg = "m";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);}
if(x==3&&y==1)
{ keys='M';
char *msg = "n";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);}
if(x==3&&y==2)
{ keys='N';
char *msg = "o";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);}
if(x==3&&y==3)
{ keys='O';
char *msg = "p";
//msg=keys;
driver.send((uint8_t *)msg, strlen(msg));
driver.waitPacketSent();
delay(5);}
}
