//Use arduino UNO or Arduino NANO.
int level1=A1;
int level2=A2;
int level3=A3;
int level4=A4;
//int level5=A5;
int motor=7;
int a;
int b;
int c;
int d;
int e;
int r; //Water Pump status flag
int m=0; //water Pump flag
int z=50; // Adjust this value from 100 to 1023 if your circuit do not show correct value. 
  

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
pinMode(level1,INPUT);
pinMode(level2,INPUT);
pinMode(level3,INPUT);
pinMode(level4,INPUT);
//pinMode(level5,INPUT);
pinMode(motor,OUTPUT);
Serial.begin(9600);

//lcd.begin(20, 4); // if you are using 16x2 line LCD, then replace these values and also adjust all LCD text for 1st and 2nd line in the loop below. 
}

void loop()
{

r=digitalRead(motor);
a=analogRead(level1);
b=analogRead(level2);
c=analogRead(level3);
d=analogRead(level4);
//e=analogRead(level5);

Serial.println("a:  ");
Serial.print(a);

Serial.println("b:  ");
Serial.print(b);

Serial.println("c:  ");
Serial.print(c);

Serial.println("d:  ");
Serial.print(d);
//
//Serial.println("e:  ");
//Serial.print(e);

//lcd.clear();
//lcd.setCursor(2,0);              
//lcd.print("Easy HM Projects");   
//lcd.setCursor(0,1);              
//lcd.print("Water Level Monitor.");

if(a>z && b>z && c>z && d>z)
{
  digitalWrite(motor, HIGH);
}
else
{
  if(a>z && b>z && c>z && d<z)
  {
     Serial.println("75 Full.");
  }
  else
  {
    if(a>z && b>z && c<z && d<z)
    {
      Serial.println("50 Full.");
    }
    else
    {
      if(a>z && b<z && c<z && d<z)
      {
          Serial.println("25 Full.");
      }
      else
      {
          if(a<z && b<z && c<z && d<z)
          {
            Serial.print("Empty");
            digitalWrite(motor, LOW);
          }
      }
    }
  }
}
Serial.println(motor);





}
