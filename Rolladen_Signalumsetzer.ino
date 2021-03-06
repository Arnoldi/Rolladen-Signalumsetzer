#define PULSE_DURATION 500
#define NUM_PINPAIRS 8

typedef unsigned long Time_t;
typedef int Clock_t;
typedef int Timer_t;
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
  PinTimedFlipFlop_t():
    PinTimedFlipFlop_t(0, 0)
  {}
  PinTimedFlipFlop_t(Pin_t InputPin, Pin_t OutputPin):
    InputPin(InputPin),
    OutputPin(OutputPin),
    Timer(0),
    InputPinPreviousState(LOW)
  {}
  Timer_t Timer;
  PinState_t InputPinPreviousState;
  Pin_t InputPin;
  Pin_t OutputPin;
};

FlipFlopState_t getNewFlipFlopState(PinState_t OldState, PinState_t NewState) {
  return (FlipFlopState_t)(((OldState == HIGH) ? OLD_INPUT_HIGH : OLD_INPUT_LOW) |
                           ((NewState == HIGH) ? NEW_INPUT_HIGH : NEW_INPUT_LOW));
}

void processPinPair(PinTimedFlipFlop_t& PinPair, Time_t PassedTime) {
  PinState_t InputPinNewState = digitalRead(PinPair.InputPin);
  FlipFlopState_t State = getNewFlipFlopState(PinPair.InputPinPreviousState, InputPinNewState);

  switch (State) {
    case INPUT_LOW:
    case INPUT_HIGH:
      if (PinPair.Timer > 0) {
        // count timer down
        PinPair.Timer -= (Timer_t)PassedTime;
      } else {
        // timer has run out, set output to HIGH
        digitalWrite(PinPair.OutputPin, HIGH);
        PinPair.Timer = 0;
      }
      break;
    case INPUT_RISING:
    case INPUT_FALLING:
      // start pulse by setting the timer to the pulse duration and setting ouput to LOW
      PinPair.Timer = PULSE_DURATION;
      PinPair.InputPinPreviousState = InputPinNewState;
      digitalWrite(PinPair.OutputPin, LOW);
  }
}

PinTimedFlipFlop_t PinPairs[NUM_PINPAIRS];
Time_t LastTimestamp = 0;
void setup() {
  // put your setup code here, to run once:

  PinPairs[0] = PinTimedFlipFlop_t(3, 5);
  PinPairs[1] = PinTimedFlipFlop_t(4, 6);
  PinPairs[2] = PinTimedFlipFlop_t(A0, 7);
  PinPairs[3] = PinTimedFlipFlop_t(A1, 8);
  PinPairs[4] = PinTimedFlipFlop_t(A2, 9);
  PinPairs[5] = PinTimedFlipFlop_t(A3, 10);
  PinPairs[6] = PinTimedFlipFlop_t(A4, 11);
  PinPairs[7] = PinTimedFlipFlop_t(A5, 12);

  for (int i = 0; i < NUM_PINPAIRS; i++)
  {
    //Use Pullup resistor. To get an input signal, actively pull the line to ground.
    pinMode(PinPairs[i].InputPin, INPUT_PULLUP);

    pinMode(PinPairs[i].OutputPin, OUTPUT);
    //Set the initial output to low.
    digitalWrite(PinPairs[i].OutputPin, HIGH);
  }

  LastTimestamp = millis();
}


void loop() {
  // put your main code here, to run repeatedly:

  Time_t CurrentTimestamp = millis();
  Time_t PassedTime = CurrentTimestamp - LastTimestamp;

  if (PassedTime > 0)
  {
    for (int i = 0; i < NUM_PINPAIRS; i++)
    {
      processPinPair(PinPairs[i], PassedTime);
    }
    LastTimestamp = CurrentTimestamp;
  }
  //Wait for 1ms
  delay(1);
}
