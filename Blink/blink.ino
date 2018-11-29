int inPin = 2;    // NOT output connected to digital pin 2


void setup()
{
  pinMode(inPin, OUTPUT);  // sets the digital pin 2 as input
  }

void loop()
{
  digitalWrite(inPin, HIGH); 
  delay(1000);//in milleseconds.
  digitalWrite(inPin, LOW);
  delay(1000);
  
}
