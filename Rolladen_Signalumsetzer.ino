typed unsigned int Timer_t;

struct PinTimedFlipFlop_t {
  Timer_t TimerStart;
};

void setup() {
  // put your setup code here, to run once:

  //Input Pins:

  //Use Pullup resistor. To get an input signal, actively pull the line to ground.
  pinMode(1, INPUT_PULLUP);

  //Output Pins:
  pinMode(9, OUTPUT);
  //Set the initial output to low.
  digitalWrite(9, LOW);
}

Timer_t Timer;
void loop() {
  // put your main code here, to run repeatedly:

  //Check input here

  //Wait for 100ms
  delay(100);
}
