#include "Waveforms.h"
#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds

int freq;
int pot = A0; //connect pot on analog 0
int sample ; //frequency 
int i = 0 ;
int potvalue = 0;
int mapValue = 0;
int flag = 0;
int pwmOutput = 3; //output is on D3
void setup() {
  Serial.begin(9600);
}

void loop() {   
  sine_wave();
}

void sine_wave(){
  if(flag = 0){
    sample = map(analogRead(pot), 0, 1024, 0, oneHzSample);
    sample = constrain(sample, 0, oneHzSample);
  }
  analogWrite(pwmOutput, waveformsTable[0][i]);  // write the selected waveform on DAC0

  i++;
  if(i == maxSamplesNum)  // Reset the counter to repeat the wave
    i = 0;

  delayMicroseconds(sample);  // Hold the sample value for the sample time
} 

void serialEvent(){
  freq = Serial.parseInt();  //data format :FREQUENCY[20] 
  Serial.print("frequency set into  ");
  Serial.print(freq);
  Serial.println();
  sample = freq ;
  flag = 1; 
}

 
