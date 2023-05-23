const int analogPin = A1;
const int ledPin = 5;
int inputValue = 0;
int outputValue = 0; 

void setup(){
} 

void loop(){
inputValue = analogRead(analogPin);
outputValue = map(inputValue,0,1023,0,255);
analogWrite(ledPin,outputValue);
}