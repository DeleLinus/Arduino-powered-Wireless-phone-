int row[]={2,3,4,5};//c4,c3,c2,c1
int col[]={6,7,8,9};//r4,r3,r2,r1
int x=0;
int y=0;
char keys;
int stat =1;
void setup() {
for (int x=0; x<=3;x++)
{pinMode(row[x],OUTPUT);
pinMode(col[x],INPUT_PULLUP);
}
Serial.begin(9600);
}
void loop() { for(x=0; x<=3; x++)
{digitalWrite(row[0],1);
digitalWrite(row[1],1);
digitalWrite(row[2],1);
digitalWrite(row[3],1);
digitalWrite(row[x],0);
for(y=0; y<=3; y++)
{ stat= digitalRead(col[y]);
if(stat==LOW)
{ pressedkeys(x,y);
Serial.print(keys );
delay(100);
}}
if(y==3)
{y=0;
}
delay(20);
}
if(x==3)
{x=0;
}
}
void pressedkeys (int x, int y)
{
if(x==0&&y==0)
{ keys='1';}
if(x==0&&y==1)
{ keys='2';}
if(x==0&&y==2)
{ keys='3';}
if(x==0&&y==3)
{ keys='+';}
if(x==1&&y==0)
{ keys='4';}
if(x==1&&y==1)
{ keys='5';}
if(x==1&&y==2)
{ keys='6';}
if(x==1&&y==3)
{ keys='-';}
if(x==2&&y==0)
{ keys='7';}
if(x==2&&y==1)
{ keys='8';}
if(x==2&&y==2)
{ keys='9';}
if(x==2&&y==3)
{ keys='^';}
if(x==3&&y==0)
{ keys='*';}
if(x==3&&y==1)
{ keys='0';}
if(x==3&&y==2)
{ keys='=';}
if(x==3&&y==3)
{ keys='/';}
}
