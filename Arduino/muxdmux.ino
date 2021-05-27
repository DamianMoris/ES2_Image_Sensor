  int Row[] = {9,10,11,12};
  int Kol[] = {5,6,7,8};
  float output =0;
  //float muxout =0;  
void setup() {

// place the digital pins in a array

pinMode (Row[0], OUTPUT);
digitalWrite(Row[0],LOW);
pinMode (Row[1], OUTPUT);
digitalWrite(Row[1],LOW);
pinMode (Row[2], OUTPUT);
digitalWrite(Row[2],LOW);
pinMode (Row[3], OUTPUT);
digitalWrite(Row[3],LOW);

pinMode (Kol[0], OUTPUT);
digitalWrite(Kol[0],LOW);
pinMode (Kol[1], OUTPUT);
digitalWrite(Kol[1],LOW);
pinMode (Kol[2], OUTPUT);
digitalWrite(Kol[2],LOW);
pinMode (Kol[3], OUTPUT);
digitalWrite(Kol[3],LOW);
pinMode (A0, INPUT_PULLUP);
pinMode(A1,INPUT_PULLUP);
//pinMode  (A0, INPUT);

//pinMode (output, INPUT); // when output is connected delete comments
    // put your setup code here, to run once:
Serial.begin(9600);
}

void BinaryOut(byte number, int pins[])
{
  for (int i =0;i<4;i++)
  { 
    // convert a number in binary code. if the bit [1] is a 1 write that pin high otherwise low
    if (bitRead(number, i)==1)
      {
        digitalWrite(pins[i], HIGH);
      }
      else
      { 
        digitalWrite(pins[i], LOW);
      } 
  } 
}

void loop() 
{
  Serial.print("---------------------------------start-------------------------------\n");
  for (byte binrow =0;binrow<=15; binrow++)
    { 
      BinaryOut(binrow,Row);
      for( byte binkol=0;binkol<=15;binkol++)
      {
        BinaryOut(binkol,Kol);
        //A0 for output read on jkol
        output = analogRead(A0);
        muxout = analogRead(A1);
        float number = (output*5.0)/1024;
        //float muxnum = (muxout*5.0)/1024;
        Serial.print(number);
        //Serial.print(" ");
        //Serial.print(muxnum);
        Serial.print("\t");
        delay(10); // time 100 for eye of switch betwin photothransistors
      }
    Serial.print("\n"); 
    }  
  Serial.print("---------------------------------end-------------------------------\n");
}
