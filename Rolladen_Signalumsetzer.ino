typedef int Clock_t;
typedef unsigned int Timer_t;
typedef unsigned char Pin_t;
typedef bool PinState_t;

enum class {
  INPUT_LOW,
  INPUT_RISING,
  INPUT_HIGH,
  INPUT_FALLING
}

struct PinTimedFlipFlop_t {
  Timer_t Timer;
  PinState_t InputPinPreviousState;
  Pin_t InputPin;
  Pin_t OutputPin;
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

void ProcessPinPair(PinTimedFlipFlop_t PinPair) {

}

void loop() {
  // put your main code here, to run repeatedly:

  //Check input here
  //  Read Pin_1
  //  If flag_Pin_1 == Pin_1  * check if Pin 1 was set before (flag_Pin_1 contains the previous value of Pin_1)
  //    If Count > 0          * nothing happened
  //      Count--             * count timer down
  //    Else
  //      Pin_9 = Low
  //    EndIf
  //  Else
  //    flag_Pin_1 = Pin_1    * set flag_Pin_1 to current value of Pin_1
  //    Count = 5             * reset timer to 500ms
  //    Pin_9 = High          * set output to High
  //  EndIf
  //
  //
  //  delay 100 ms
  //

  //Wait for 100ms
  delay(100);
}
