#include <Wire.h>
#define i2c_address 0x40
byte t_l = 0;
byte t_h = 0;
int t = 0;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(i2c_address);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.requestFrom(i2c_address, 2); //16 bit register
  t_h = Wire.read();
  t_l = Wire.read();
  t = (int)((t_h << 8) | (t_l));
  Serial.println(convertToC(t));
  delay(500);
}

int convertToC(int ditigalOutputDie) {
  ditigalOutputDie >>= 2;
  ditigalOutputDie /= 32;
  return ditigalOutputDie;
}
