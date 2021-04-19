byte pinFull = 0;
byte pinEmpty = 0;
byte pinToLow = 0;

void setupSensors () {
    pinMode(pinFull, INPUT);
    pinMode(pinEmpty, INPUT);
    pinMode(pinToLow, INPUT);
}

bool TankIsEmpty () 
{
    return (digitalRead(pinEmpty) == 0);
}

bool TankIsFull () 
{
    return (digitalRead(pinToLow) == 1);
}


double getPh() {

}
