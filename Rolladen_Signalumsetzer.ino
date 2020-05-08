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
  //  Read Pin_1
  //  If flag_Pin_1 == Pin_1  * check if Pin 1 was set before (flag_Pin_1 contains the previous value of Pin_1)
  //    Count++               * nothing happened, count time up
  //  Else
  //    flag_Pin_1 = Pin_1    * set flag_Pin_1 to current value of Pin_1
  //    Count = 0             * reset timer
  //    Pin_9 = High          * set output to High
  //  EndIf
  //
  //  If Count >= 500 msec
  //    Pin_9 = Low
  //  EndIf
  //
  //  delay 100 ms
  //

  //Wait for 100ms
  delay(100);
}
