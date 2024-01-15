#define ENA   2
#define STP   3
#define DIR   4
#define SW1   5
#define SW2   6

#define ZOOM_IN   1
#define ZOOM_OUT  0

//const int stepsPerRev = 3200; // 2mm per 1rev
const int mmPerRev = 1600;
const int stepDelay = 200;

void setup() {
  pin_init();
  Serial.begin(9600);
  Serial.println("START");
}

void loop() 
{
  bool valSW1 = digitalRead(SW1);
  bool valSW2 = digitalRead(SW2);

  /*Serial.print(valSW1);
  Serial.println(valSW2);
  delay(100);*/
  if(!valSW1 && valSW2)
  {
    digitalWrite(ENA, LOW);
    digitalWrite(DIR, ZOOM_IN);
        
    digitalWrite(STP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STP, LOW);
    delayMicroseconds(stepDelay);
  }
  else if(valSW1 && !valSW2)
  {
    digitalWrite(ENA, LOW);
    digitalWrite(DIR, ZOOM_OUT);
        
    digitalWrite(STP, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STP, LOW);
    delayMicroseconds(stepDelay);
  }
  else if (!valSW1 && !valSW2)
  {
      digitalWrite(ENA, HIGH);
      delay(1000);
  }
}

void pin_init(void)
{
  pinMode(ENA, OUTPUT);
  pinMode(STP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  delay(500);

}
