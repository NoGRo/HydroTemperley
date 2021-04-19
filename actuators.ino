byte pinRelay1 = 16; 
byte pinRelay2 = 5; 
byte pinRelay3 = 4; 
byte pinRelay4 = 0; 
byte pin12vRelay1 = 2;
byte pin12vRelay2 = 14;
byte pin12vRelay3 = 12;
byte pin12vRelay4 = 13;

void setupActuators () 
{
    pinMode(pinRelay1, OUTPUT);
    pinMode(pinRelay2, OUTPUT);
    pinMode(pinRelay3, OUTPUT);
    pinMode(pinRelay4, OUTPUT);
    pinMode(pin12vRelay1, OUTPUT);
    pinMode(pin12vRelay2, OUTPUT);
    pinMode(pin12vRelay3, OUTPUT);
    pinMode(pin12vRelay4, OUTPUT);
}

void setPinTime(int pin ,int seconds)
{
    digitalWrite(pin, HIGH);
    delay(seconds * 1000);
    digitalWrite(pin, LOW);
}

void setCirculation(int state) 
{
    digitalWrite(pinRelay1, state);
}
void setDrain(int state) 
{
    digitalWrite(pinRelay2, state);
}
void setFill(int state) 
{
    digitalWrite(pinRelay3, state);
}
void setNutrient(int state) 
{
    digitalWrite(pin12vRelay1, state);
}
void setPhDown(int state) 
{
    digitalWrite(pin12vRelay2, state);
}
void setMixer(int state) 
{
    digitalWrite(pin12vRelay3, state);
}
void pushNutrientsFromPipe() {
    setFillTime(10);
}

// OverRide
void setCirculationTime(int seconds) 
{
    setPinTime(pinRelay1, seconds);
}
void setDrainTime(int seconds) 
{
    setPinTime(pinRelay2, seconds);
}
void setFillTime(int seconds) 
{
    setPinTime(pinRelay3, seconds);
}
void setNutrientTime(int seconds) 
{
    setPinTime(pin12vRelay1, seconds);
}
void setPhDownTime(int seconds) 
{
    setPinTime(pin12vRelay2, seconds);
}
void setMixerTime(int seconds) 
{
    setPinTime(pin12vRelay3, seconds);
}

