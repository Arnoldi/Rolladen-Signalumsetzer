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
  //  If Pin_1 == High        * check if Pin 1 is set
  //    If flag_Pin_1 == High  * check if Pin 1 was set before
  //      Count++
  //    Else
  //      flag_Pin_1 = High
  //      Count = 0
  //      Pin_9 = High
  //    EndIf
  //  Else
  //    If flag_Pin_1 == High
  //      flag_Pin_1 = Low
  //      Count = 0
  //      Pin_9 = High
  //    Else
  //      Count++
  //    EndIf
  //  EndIf
  //
  //  If Count >= 500 msec
  //    Set Pin_9 Low
  //  EndIf
  //
  //  delay 100 ms
  //

  //Wait for 100ms
  delay(100);
}
