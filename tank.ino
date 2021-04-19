#include <SoftTimer.h>
#include <BlinkTask.h>


int mlNuttrientByLiterLow = 2;
int mlNuttrientByLiterNormal = 4;
int mlNuttrientByLiterHigh = 5;

int InitPHDownCorrect = 5;
int TankLiters = 25;

int Fill1LiterSeconds = 7;
int Drain1LiterSeconds = 5;

BlinkTask TimerCirculate(pinRelay1, 4*1000, 8*1000);

void SetupTank()
{
    Continue();
}

void Pause()
{
    TimerCirculate.stop();
    setCirculation(LOW);
    setDrain(LOW);
    setFill(LOW);
    setNutrient(LOW);
    setPhDown(LOW);
    setMixer(LOW);
}
void Continue() 
{
  TimerCirculate.start();
}

void TotalTankReFill () {
    Pause();
    EmptyTank();
    FillTank();
    PutNutrients();
    Continue();
}
void EmptyTank() {
    setDrainTime(Drain1LiterSeconds * TankLiters);
}

void FillTank() {
    int EstimatedSecondsToFill = Fill1LiterSeconds * (TankLiters + 2);

    int SecondsPassed = 0;
    setFill(HIGH);
    while (!TankIsFull() || SecondsPassed > EstimatedSecondsToFill) {
        delay(1000);
        SecondsPassed++;
    }
    setFill(LOW);

    if (!TankIsFull()) {
       // Fail();
    }
}


void PutNutrients() 
{
    setPhDownTime(InitPHDownCorrect);
    pushNutrientsFromPipe();
    
    setCirculationTime(5 * 60);
    
    setNutrientTime(mlNuttrientByLiterNormal * TankLiters);
    pushNutrientsFromPipe();
    
    setCirculationTime(5 * 60);
}