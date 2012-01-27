const int BUTTON = 2;

const int LEDPIN_MIN = 3;
const int LEDPIN_MAX = 4;

volatile int count = 0;

void setup()
{
  Serial.begin(9600);
  for (int i=LEDPIN_MIN; i<=LEDPIN_MAX; i++) {
      pinMode(i, OUTPUT);
      digitalWrite(i, HIGH);
  }
  pinMode(BUTTON, INPUT);
  // interrupt 0 == pin 2
  attachInterrupt(0, accumulate, RISING);
  delay(250);
}

void loop()
{
  if(count > LEDPIN_MAX) {
    count = LEDPIN_MIN-1;
    for (int i=LEDPIN_MIN; i<=LEDPIN_MAX; i++){
      digitalWrite(i, LOW);
    }
  }
  for(int i=LEDPIN_MIN; i<=count; i++){
    digitalWrite(i, HIGH);
  }
}

void accumulate()
{
  count++;
}


