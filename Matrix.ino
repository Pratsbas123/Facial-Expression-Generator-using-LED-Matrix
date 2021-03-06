#include "LedControl.h"

int DIN = 12;
int CS =  11;
int CLK = 10;


// Alphabets ::

byte A[8]=     {0x18,0x3C,0x3C,0x66,0x7E,0xFF,0xC3,0xC3};
byte a[8]=     {0xFF,0xFF,0x03,0xFF,0xFF,0xC3,0xFF,0xFF};
byte B[8]=     {0xFF,0xFF,0xC3,0xFE,0xFE,0xC3,0xFF,0xFF};
byte b[8]=     {0xC0,0xC0,0xC0,0xFF,0xFF,0xC3,0xFF,0xFF};
byte C[8]=     {0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF};
byte c[8]=     {0x00,0x00,0xFF,0xFF,0xC0,0xC0,0xFF,0xFF};
byte D[8]=     {0xFC,0xFE,0xC3,0xC3,0xC3,0xC3,0xFE,0xFC};
byte d[8]=     {0x03,0x03,0x03,0xFF,0xFF,0x83,0xFF,0xFF};
byte E[8]=     {0xFF,0xFF,0xC0,0xFF,0xFF,0xC0,0xFF,0xFF};
byte e[8]=     {0xFF,0xFF,0xC3,0xFF,0xFF,0xC0,0xFF,0xFF};
byte F[8]=     {0xFF,0xFF,0xC0,0xC0,0xFC,0xFC,0xC0,0xC0};
byte f[8]=     {0x3F,0x3F,0x30,0xFC,0xFC,0x30,0x30,0x30};
byte G[8]=     {0xFC,0xFC,0xC0,0xFF,0xFF,0xCC,0xFC,0xFC};
byte g[8]=     {0x3F,0x7F,0x63,0x7F,0x1F,0xC3,0xFF,0x7F};
byte H[8]=     {0xC3,0xC3,0xC3,0xFF,0xFF,0xC3,0xC3,0xC3};
byte h[8]=     {0xC0,0xC0,0xC0,0xFF,0xFF,0xC3,0xC3,0xC3};
byte I[8]=     {0xFF,0xFF,0x18,0x18,0x18,0x18,0xFF,0xFF};
byte i[8]=     {0x18,0x18,0x00,0x18,0x18,0x18,0xFF,0xFF};
byte J[8]=     {0xFF,0xFF,0x03,0x03,0xC3,0xC3,0xFF,0x7E};
byte j[8]=     {0x03,0x00,0x03,0x03,0x03,0xC3,0xFF,0xFF};
byte K[8]=     {0xC3,0xC6,0xD8,0xF0,0xF0,0xD8,0xC6,0xC3};
byte k[8]=     {0xC0,0xC3,0xC6,0xCC,0xD8,0xF0,0xD8,0xC6};
byte L[8]=     {0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF};
byte l[8]=     {0x30,0x30,0x30,0x30,0x30,0x30,0xFF,0xFF};
byte M[8]=     {0xC3,0xE7,0xFF,0xDB,0xDB,0xC3,0xC3,0xC3};
byte m[8]=     {0x00,0x00,0xE7,0xE7,0xDB,0xDB,0xC3,0xC3};
byte N[8]=     {0xE3,0xE3,0xF3,0xFB,0xDF,0xCF,0xC7,0xC7};
byte n[8]=     {0x00,0x00,0xDF,0xFF,0xE3,0xE3,0xE3,0xE3};
byte O[8]=     {0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E};
byte o[8]=     {0x00,0x7E,0x7E,0xC3,0xC3,0xC3,0xFF,0x7E};
byte P[8]=     {0xFE,0xFF,0xC3,0xC3,0xFE,0xFC,0xC0,0xC0};
byte p[8]=     {0xC0,0xFE,0xFF,0xC3,0xFF,0xFC,0xC0,0xC0};
byte Q[8]=     {0x3C,0xFF,0xC3,0xC3,0xC3,0x7E,0x7E,0x07};
byte q[8]=     {0x03,0x7F,0xCF,0xCF,0xCF,0x7F,0x03,0x03};
byte R[8]=     {0xFC,0xFE,0xC7,0xC6,0xFC,0xD8,0xCE,0xC3};
byte r[8]=     {0xC0,0xDE,0xFF,0xE3,0xC0,0xC0,0xC0,0xC0};
byte S[8]=     {0x7E,0x81,0x80,0xFE,0x7F,0x01,0x81,0x7E};
byte s[8]=     {0x3C,0x43,0x40,0x7C,0x3E,0x02,0xC2,0x3C};
byte T[8]=     {0xFF,0xFF,0x18,0x18,0x18,0x18,0x18,0x18};
byte t[8]=     {0x60,0x60,0xF0,0xF0,0x60,0x60,0x7F,0x3E};
byte U[8]=     {0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E};
byte u[8]=     {0x00,0x00,0xC6,0xC6,0xC6,0xC6,0xFF,0x7D};
byte V[8]=     {0x81,0x81,0x42,0x42,0x24,0x24,0x18,0x18};
byte v[8]=     {0x00,0x00,0x00,0xC3,0x42,0x64,0x24,0x18};
byte W[8]=     {0x81,0x81,0x81,0x81,0x81,0x5A,0x5A,0x24};
byte w[8]=     {0x00,0x00,0x00,0x81,0x81,0x5A,0x5A,0x24};
byte X[8]=     {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
byte x[8]=     {0x00,0x00,0xE7,0x24,0x18,0x18,0x24,0xE7};
byte Y[8]=     {0x81,0xC3,0x66,0x3C,0x18,0x18,0x18,0x18};
byte y[8]=     {0x63,0x63,0x7F,0x3F,0x03,0xC3,0xFF,0x7F};
byte Z[8]=     {0xFF,0xFF,0x07,0x0C,0x18,0x70,0xFF,0xFF};
byte z[8]=     {0x00,0xFF,0xFF,0xC6,0x08,0xD3,0xFF,0xFF};


// Expressions ::

byte deadface[8]={0xFF,0x99,0x99,0xFF,0x00,0x00,0x18,0x00};
byte eclose[8]={0x00,0xE7,0xE7,0x00,0x00,0x00,0x18,0x00};
byte eopen[8]={0xFF,0x99,0xDD,0xFF,0x00,0x00,0x18,0x00};
byte eopen1[8]={0x00,0xFF,0x99,0xFF,0x00,0x00,0x18,0x00};
byte eopen2[8]={0xFF,0x99,0x99,0xFF,0x00,0x00,0x18,0x00};
byte eup[8]={0xFF,0xBB,0x99,0xFF,0x00,0x00,0x18,0x00};
byte edown[8]={0xFF,0x99,0xBB,0xFF,0x00,0x00,0x18,0x00};

byte mclose[8]={0xFF,0xBB,0x99,0xFF,0x00,0x00,0x3C,0x00};
byte mopen[8]={0xFF,0xBB,0x99,0xFF,0x00,0x7E,0x42,0x7E};
byte mcircle[8]={0xFF,0xBB,0x99,0xFF,0x3C,0x24,0x24,0x3C};

byte smile[8]={0xFF,0xBB,0x99,0xFF,0x00,0x42,0x7E,0x00};
byte sad[8]={0xFF,0xBB,0x99,0xFF,0x00,0x7E,0x42,0x00};

byte like[8]= {0x30,0x30,0x30,0x30,0x7C,0x7E,0x7E,0x3C};            // front like 
byte dislike[8]= {0x7E,0x7E,0x7C,0x7C,0x30,0x30,0x30,0x30};


//Symbols ::

byte net0[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte net1[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18};
byte net2[8]= {0x00,0x00,0x00,0x00,0x3C,0x3C,0x18,0x18};
byte net3[8]= {0x00,0x00,0x7E,0x7E,0x3C,0x3C,0x18,0x18};
byte net4[8]= {0xFF,0xFF,0x7E,0x7E,0x3C,0x3C,0x18,0x18};

byte bat0[8]= {0x00,0x00,0xFF,0x81,0x81,0xFF,0x00,0x00};
byte bat1[8]= {0x00,0x00,0xFF,0xC1,0xC1,0xFF,0x00,0x00};
byte bat2[8]= {0x00,0x00,0xFF,0xE1,0xE1,0xFF,0x00,0x00};
byte bat3[8]= {0x00,0x00,0xFF,0xF1,0xF1,0xFF,0x00,0x00};
byte bat4[8]= {0x00,0x00,0xFF,0xF9,0xF9,0xFF,0x00,0x00};
byte bat5[8]= {0x00,0x00,0xFF,0xFD,0xFD,0xFF,0x00,0x00};
byte bat6[8]= {0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00};


LedControl lc=LedControl(DIN,CLK,CS,0);



void setup()
{
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      
  lc.clearDisplay(0);         
}




void loop()
{    

    printExp();
    lc.clearDisplay(0);
    delay(1000);
   
    printAlpha();
    lc.clearDisplay(0);
    delay(1000);

    printSymbol();
    lc.clearDisplay(0);
    delay(1000);
}


void printAlpha()
{
  // Alphabet :::
    // Lower
  
  for(int chl=97;chl<=122;chl++)
  {
    char chl1=chl;
    printByte(chl1);
    delay(1000);     
  }

    // Upper

   for(int chu=65;chu<=90;chu++)
   {
      char chu1=chu;
      printByte(chu1);
      delay(1000);
   }
}



void printExp()
{
  // Expression :::

  printByte(deadface);
  delay(1000);

  for(int i=0;i<4;i++)  //Open slowly
  {
    printByte(eclose);
    delay(1000);
    printByte(eopen);
    delay(1000);
    printByte(eopen1);
    delay(1000);
    printByte(eopen2);
    delay(1000);
  }

  for(int i=0;i<4;i++)  //Blink
  {
    printByte(eopen);
    delay(100);
    printByte(eclose);
    delay(100);
  }

  for(int i=0;i<4;i++)  //Roll
  {
    printByte(eup);
    delay(500);
    printByte(edown);
    delay(500);
  }

  for(int i=0;i<4;i++)  //Laugh
  {
    printByte(mclose);
    delay(100);
    printByte(mopen);
    delay(500);
    printByte(mopen);
    delay(500);
    printByte(mopen);
    delay(500);
  }

   for(int i=0;i<2;i++)  //Smile and Sad
  {
    printByte(smile);
    delay(1000);
    printByte(sad);
    delay(1000);
  }
  for(int i=0;i<4;i++)  //Eat
  {
    printByte(mopen);
    delay(500);
    printByte(mclose);
    delay(500);
  }

  for(int i=0;i<2;i++)  //Hello
  {
    printByte(mopen);
    delay(1000);
    printByte(mcircle);
    delay(1000);
  }

  for(int i=0;i<2;i++)  //Wow
  {
    printByte(mcircle);
    delay(1000);
    printByte(mopen);
    delay(1000);
    printByte(mcircle);
    delay(1000);
  }

  for(int i=0;i<4;i++)  //Oh
  {
    printByte(mclose);
    delay(1000);
    printByte(mcircle);
    delay(1000);
  }

  for(int i=0;i<2;i++)  //Good Morning
  {
    printByte(mclose);
    delay(1000);
    printByte(mcircle);
    delay(3000);
    printByte(mclose);
    delay(1000);
    printByte(mcircle);
    delay(2000);
    printByte(mopen);
    delay(2000);
  }

  for(int i=0;i<2;i++)  //Like and Dislike
  {
    printByte(like);
    delay(3000);
    printByte(dislike);
    delay(3000);
  }
}



void printSymbol()
{
  //Network
    printByte(net0);
    delay(500);

    printByte(net1);
    delay(1000);
    
    printByte(net2);
    delay(1000);
    
    printByte(net3);
    delay(1000);
    
    printByte(net4);
    delay(1000);

   //Battery
    
    printByte(bat0);
    delay(500);
    
    printByte(bat1);
    delay(1000);

    printByte(bat2);
    delay(1000);
    
    printByte(bat3);
    delay(1000);
    
    printByte(bat4);
    delay(1000);
    
    printByte(bat5);
    delay(1000);

    printByte(bat6);
    delay(1000);
}


void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

