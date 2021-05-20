#include<SoftwareSerial.h>
SoftwareSerial BTserial(0,1);
int ledPins[] = {2,3,4,5,6}; 
int input[5];
int pinCount=5;
char path[100]; 
int pathlength=-1;
void Goright();
void Goleft();
void Go();
void Goback();
void Goright1();
void Goleft1(); 
void Stop();
void check();
#define M1 9
#define M2 10
#define M3 11
#define M4 12
void setup(){
  BTserial.begin(9600);
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin],INPUT);
  }
  Serial.begin(9600);
  pinMode(8,INPUT);//Switch for finding shortest path
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  pinMode(13,OUTPUT);
    pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  while(Serial.available())    //Check if there are available bytes to read              //Delay to make it stable
    BTserial.print("hi"); 
      analogWrite(A4,150);
  analogWrite(A5,150);
}
void loop()
{  
      BTserial.print("hi"); 
  int n;
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    input[thisPin]=digitalRead(ledPins[thisPin]);

    }
    //delay(30);
    if (input[0]==1 &&  input[4]==1 &&  input[2]==1 ){ 
    check();
    }
    else if (input[0]==1 && input[2]==1  && input[4]==0){
     inchleft();}
    /*else if(input[0]==1 )
    {
    Goleft();
    }*/
    else if (input[0]==0 &&input[1]== 0 &&input[2]==1&&input[3]== 0&&input[4]==0)
    Go();
    else if(input[2]==1 && input[4]==1 && input[0]== 0)
    inch();
    //else if( input[4]==1)
     //{
    //Goright();
    //}
    //else if (input[0]==0 &&input[1]== 0&&input[2]== 0&&input[3]==1&&input[4]==1)
    //Goright();
    else if( input[1]==1 )
     {
    Goleft1();
    }
     else if( input[3]==1)
     {
    Goright1();
    }
   
    else if (input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0&&input[4]==0){
      delay(70);
      if (input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0&&input[4]==0){
           Goback();}
 }
  
    
    if(pathlength>=3){
      simplify(pathlength);
    }
}
void simplify1(int Length)
{int i;
  int j=Length-1;
  if(path[j]=='B')
  {if(path[j-1]=='L' && path[j+1]=='R')
   {
    path[j-1]='B';
        path[j]='0';
            path[j+1]='0';
    Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='L' && path[j+1]=='S')
   {
    path[j-1]='R';
        path[j]='0';
            path[j+1]='0';
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='R' && path[j+1]=='L')
   {
    path[j-1]='B';
        path[j]='0';
            path[j+1]='0';
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='S' && path[j+1]=='L')
   {
    path[j-1]='R';
        path[j]='0';
            path[j+1]='0';
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='S' && path[j+1]=='S')
   {
    path[j-1]='B';
        path[j]='0';
            path[j+1]='0';
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='L' && path[j+1]=='L')
   {
    path[j-1]='S';
        path[j]='0';
            path[j+1]='0';
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
  }
}
void simplify(int Length)
{int i;
  int j=Length-1;
  if(path[j]=='B')
  {if(path[j-1]=='L' && path[j+1]=='R')
   {
    path[j-1]='B';
    pathlength=j-1;
    Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='L' && path[j+1]=='S')
   {
    path[j-1]='R';
    pathlength=j-1;
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='R' && path[j+1]=='L')
   {
    path[j-1]='B';
    pathlength=j-1;
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='S' && path[j+1]=='L')
   {
    path[j-1]='R';
    pathlength=j-1;
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='S' && path[j+1]=='S')
   {
    path[j-1]='B';
    pathlength=j-1;
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
   else if(path[j-1]=='L' && path[j+1]=='L')
   {
    path[j-1]='S';
    pathlength=j-1;
        Serial.println();
    for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
   }
  }
}
void Goright()
{
  analogWrite(A4,150);
  analogWrite(A5,150);

  Go1();
 delay(300);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW);  
 //digitalWrite(13,HIGH);
 delay(300);
 while(digitalRead(4)!=1)
 {
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW); 
 }



}
void Goright1()
{
  analogWrite(A4,150);
  analogWrite(A5,150);

 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW); 
 }
void Go()
{

  analogWrite(A0,100);
  analogWrite(A2,150);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW); 
}
void Go1()
{
  
  analogWrite(A4,150);
  analogWrite(A5,150);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW); 
}
void Stop()
{
  int i;
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW); 
 for(i=0;i<=pathlength;i++)
  {if(path[i]=='B')
   simplify1(i+1);
  } 

for(i=0;i<=pathlength;i++)
    Serial.print(path[i]);
//while(digitalRead(8)!=HIGH)
//{
 
//}
Goback();


 
}
void Goleft()
{

 int n;
  Go1();
  delay(300);

 Go1();
 delay(300);
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW);
//digitalWrite(13,HIGH);
 delay(450);
 while(digitalRead(4)!=1)
 {
   digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW);
 //digitalWrite(13,HIGH);
  }
}
void Goleft1()
{  analogWrite(A4,150);
  analogWrite(A5,150);
  digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW);
 digitalWrite(13,HIGH);
  }
void Goback()
{
 
  if(input[0]==0 &&input[1]==0 &&input[2]==0&&input[3]== 0 &&input[4]==0){
  pathlength=pathlength+1;
  path[pathlength]='B';
    Serial.print('B');}
 Go1();
 delay(500);
 while(digitalRead(4)!=1)
 {
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,HIGH);
 //digitalWrite(13,HIGH);
 }
}
void check()
{
 digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
 digitalWrite(M4,LOW); 
delay(400);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW); 
 delay(2000);
  if(digitalRead(4)==1 && digitalRead(6)==1 && digitalRead(2)==1)
  {
  Stop();
  }
 else if (digitalRead(2)==0)
   {
       Goleft();
         pathlength=pathlength+1;
  path[pathlength]='L';
    Serial.println('L');
  }
}

void inch()
{
   digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW); 
  delay(200);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
  digitalWrite(M4,LOW); 
  delay(1000);
  if(digitalRead(4)==1 && digitalRead(6)==0)
    {
      Go();
       { pathlength=pathlength+1;
  path[pathlength]='S';
    Serial.println('S');}
      }
      else if(digitalRead(4)==0 && digitalRead(6)==0)
      {
        Goright();
        }

}
void inchleft()
{
   digitalWrite(M1,HIGH);
 digitalWrite(M2,LOW);
 digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW); 
  delay(200);
 digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
  digitalWrite(M4,LOW); 
  delay(1000);
    if(digitalRead(4)==0 && digitalRead(2)==0)
    {
      Goleft();
  //pathlength=pathlength+1;
  //path[pathlength]='L';
  //Serial.print('L');
      }
     else if(digitalRead(4)==1 && digitalRead(2)==0)
     {
            Goleft();
  pathlength=pathlength+1;
  path[pathlength]='L';
    Serial.println('L');
      }
}
void return_path()
{
  char path_return[50];
  int j=0;
  for (int i;i<=pathlength;i++){
    if(i!='0'){
      path_return[j]==i; 
      j++;
      }
    }
    while(j!=-1){
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    input[thisPin]=digitalRead(ledPins[thisPin]);
   }
   if(input[0]==0 && input[2]==1 && input[4]==0)
   {
    Go1();
    } 
   else if(input[0]==1 || input[4]==1)
   {
    switch (path_return[j--]) {
    case 'S':
      Go();   
      break;
    case 'L':
      Goleft();   
      break;
    case 'R':  
      Goright();  
      break;
      
      }
    }
    else if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0&&input[4]==0)
    stop1();
    }
   
}

void stop1()
{
  digitalWrite(M1,LOW);
 digitalWrite(M2,LOW);
 digitalWrite(M3,LOW);
 digitalWrite(M4,LOW); 
while(1)
{
  
   }
  
  }
