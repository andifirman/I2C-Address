// Author : Andi Firmansyah
// GitHub : andifirman
// E-Mail : andi13firman@gmail.com

#include <Wire.h> 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}
  
void loop()
{
  byte error, address;
  int nDevices; 
  Serial.println("Melakukan pemindaian...");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
  
    if (error == 0)
    {
      Serial.print("Alamat I2C ditemukan pada alamat 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println();
      
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Ada masalah pada alamat 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("Tidak dapat menemukan alamat I2C\n");
  else
    Serial.println("selesai\n");
  
  delay(5000);
}
