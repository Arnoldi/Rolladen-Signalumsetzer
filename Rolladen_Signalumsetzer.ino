#define PULSE_DURATION 500


typedef int Clock_t;
typedef unsigned int Timer_t;
typedef unsigned char Pin_t;
typedef bool PinState_t;

#define OLD_INPUT_LOW  0x00
#define OLD_INPUT_HIGH 0x01
#define NEW_INPUT_LOW  0x00
#define NEW_INPUT_HIGH 0x02

enum FlipFlopState_t {
  INPUT_LOW = OLD_INPUT_LOW | NEW_INPUT_LOW,
  INPUT_RISING = OLD_INPUT_LOW | NEW_INPUT_HIGH,
  INPUT_HIGH = OLD_INPUT_HIGH | NEW_INPUT_HIGH,
  INPUT_FALLING = OLD_INPUT_HIGH | NEW_INPUT_LOW
};

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

FlipFlopState_t getNewFlipFlopState(PinState_t OldState, PinState_t NewState) {
  if (OldState == HIGH) {
    if (NewState == HIGH) {
      return INPUT_HIGH;
    } else {
      return INPUT_FALLING;
    }
  } else {
    if (NewState == HIGH) {
      return INPUT_RISING;
    } else {
      return INPUT_LOW; 
    }
  }
}

FlipFlopState_t getNewFlipFlopState2(PinState_t OldState, PinState_t NewState) {
  return (FlipFlopState_t)(((OldState == HIGH) ? OLD_INPUT_HIGH : OLD_INPUT_LOW) |
                           ((NewState == HIGH) ? NEW_INPUT_HIGH : NEW_INPUT_LOW));
}

void processPinPair(PinTimedFlipFlop_t PinPair) {
  PinState_t InputPinNewState = digitalRead(PinPair.InputPin);
  FlipFlopState_t State = getNewFlipFlopState(PinPair.InputPinPreviousState, InputPinNewState);

  switch (State) {
    case INPUT_LOW:
    case INPUT_HIGH:
      if (PinPair.Timer > 0) {
        // count timer down
        PinPair.Timer--;
      } else {
        // timer has run out, set output to LOW
        digitalWrite(PinPair.OutputPin, LOW);
      }
    case INPUT_RISING:
    case INPUT_FALLING:
      // start pulse by setting the timer to the pulse duration and setting ouput to HIGH
      PinPair.Timer = PULSE_DURATION;
      PinPair.InputPinPreviousState = InputPinNewState;
      digitalWrite(PinPair.OutputPin, HIGH);
  }
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
