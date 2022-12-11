byte inceput = 254, inainte = 240, inapoi = 186;
int senzorStanga, senzorDreapta;

// Variabile pentru PID //
int maxSpeed = 100;//100
int SpeedL, SpeedR;
float KP = 0.085;//0.08
float KD = 0.9;//0.8
int error, lastError;
float adjustment;
int zone = 1000;
int GOAL = 1000;
bool schimbareZona;
// Variabile pentru PID //

void setup() {
  pinMode(3, INPUT);
  pinMode(9, INPUT);

  Serial.begin(9600);
}

void loop() {
  schimbareZona = false;
  senzorStanga = digitalRead(3);
  senzorDreapta = digitalRead(9);

  if (senzorStanga == 1 && zone > 0 && schimbareZona == false) {
    zone = 0;
    schimbareZona = true;
  }

  if (senzorDreapta == 1 && zone < 2000 && schimbareZona == false) {
    zone = 2000;
    schimbareZona = true;
  }

  error = GOAL - zone;                                //Calculare eroare
  adjustment = KP * error + KD * (error - lastError); //Algoritm PID
  lastError = error;                                  //Calculare ultima eroare

  SpinMotors(adjustment);                             //Rotire motoare corespunzator ajustarii
}

void SpinMotors(float adj) {                          //Functie pentru rotirea motoarelor

  SpeedL = constrain(maxSpeed - adj, 0, maxSpeed);
  SpeedR = constrain(maxSpeed + adj, 0, maxSpeed);
  
  Serial.write(inceput);
  Serial.write(1);
  Serial.write(inainte);
  Serial.write(SpeedL);
  Serial.write(inceput);
  Serial.write(2);
  Serial.write(inainte);
  Serial.write(SpeedR);
}
