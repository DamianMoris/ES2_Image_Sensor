void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  String kom=";";
  int row = 16;
  int kol = 16;
  int sens[row][kol];
  int valt =0;
  int val =0;
  int sensorrow=0;
  int sensorkol=0;
  int input=0;
   int fil = 0;
  unsigned int value =0;

  while(1)
  {     
    Serial.print("choose a letter and press enter?\n 1. read a specific sensorvalue(0->256).\n 2. show all the sensor values\n 3. to fill the arrays:\n number:\n");
    while(Serial.available() == 0) {} 
    input = Serial.parseInt();
  
    if(input == 1)
    {
      Serial.print("sensor(0->256)\n row:");
      while(Serial.available()){Serial.read();};
      while(Serial.available() == 0) {} 
      sensorrow = Serial.parseInt();
      Serial.print(sensorrow);

      Serial.read();
      
      Serial.print("\n kol:");
      while(Serial.available() ==0 ){};
      sensorkol = Serial.parseInt();
      Serial.print(sensorkol);
      Serial.read();
      Serial.print("\n");
      Serial.print(sens[sensorrow][sensorkol]);
      
      delay(1000);
     
    }
      
    else if(input == 2)
    {
      Serial.print("Read the array\n");
      for(val = 1;val<=row;val++)
      {
        for(valt=1;valt<=kol;valt++)
        {
          Serial.print(sens[val][valt]);
          Serial.print("\t");
        }
        Serial.print("\n");
      }
      Serial.print("FIN\n");
      Serial.read();

    }
      
    else if(input == 3)
    {
      
      Serial.print(input);
      Serial.print("filling the array.....\n");
      for(val =1;val<=row;val++)
      {
        for(valt=1;valt<=kol;valt++)
        {
        value = analogRead(A0);
         
        sens[val][valt]=value;
        Serial.print(sens[val][valt]);
        Serial.print("\t");
        }
        Serial.print("\n");
      } 
       Serial.read();
       Serial.print("array filled");
    }
  }
    
  

}
