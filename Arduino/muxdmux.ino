  int Row[] = {9,10,11,12};
  int Kol[] = {5,6,7,8};
  int output =0;  
void setup() {

// place the digital pins in a array

pinMode (Row[0], OUTPUT);
pinMode (Row[1], OUTPUT);
pinMode (Row[2], OUTPUT);
pinMode (Row[3], OUTPUT);

pinMode (Kol[0], OUTPUT);
pinMode (Kol[1], OUTPUT);
pinMode (Kol[2], OUTPUT);
pinMode (Kol[3], OUTPUT);

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
  for (byte binrow =0;binrow<=15; binrow++)
    { 
      BinaryOut(binrow,Row);
      for( byte binkol=0;binkol<=15;binkol++)
      {
        BinaryOut(binkol,Kol);
        //A0 for output read on jkol
        //output = analogRead(A0);
        //Serial.print(output);
        //Serial.print("\t");
        delay(500); // time of switch betwin photosensors
      }
    //Serial.print("\n"); 
    }  
}
