#define led 6
void setup(){
DDRD|=(1<<led);//setting output pin
TCCR0A|=(1<<WGM00)|(1<<WGM01);//Fast PWM
TCCR0A|=(1<<COM0A1); //non-inverting mode
//TCCR0A|=(1<<COM0A1)|(1<<COM0A0);//inverting mode
TCCR0B|=(1<<CS01)|(1<<CS00);//prescaler 16MHz/64 (More lower PWM frequency if we want some more delays)
TCCR0B|=(1<<CS01);//prescaler 16MHz/8
}
void loop(){
unsigned int brightness=0;
for(brightness=0;brightness<=255;brightness++){
OCR0A=brightness;
delay(10);
}
for(brightness=255;brightness>=0;brightness--){
OCR0A=brightness;
delay(10);
}
}