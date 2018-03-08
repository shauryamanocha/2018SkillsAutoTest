/* Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this
  sketch!

  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed]) -- Drive [motor]
      (0 for A, 1 for B) in [direction] (0 or 1) at a [speed]
      between 0 and 255. It will spin until told to stop.
    stopArdumoto([motor]) -- Stop driving [motor] (0 or 1).

  setupArdumoto() is called in the setup().
  The loop() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define CW  0
#define CCW 1

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
// Don't change these! These pins are statically defined by shield layout
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 11; // PWM control (speed) for motor B
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B
int leftSens = 0;
int rightSens = 0;
int centerSens = 0;

void setup()
{
  setupArdumoto(); // Set all pins as outputs
}

void loop()
{

  driveArdumoto(MOTOR_A, CCW, 255);  // Motor A at max speed.
  driveArdumoto(MOTOR_B, CW, 255);  // Motor B at max speed.
}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

// setupArdumoto initialize all pins
void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

void updateLines(){
  leftSens = digitalRead(0);
  centerSens = digitalRead(1);
  rightSens = digitalRead(2);
  
}

void followLine() {

  if (leftSens == 1 && rightSens == 0) {
    driveArdumoto(MOTOR_A, CW, 255);
    driveArdumoto(MOTOR_B, CW, 255);
  }
  if (leftSens == 0 && rightSens == 1) {
    driveArdumoto(MOTOR_A, CCW, 255);
    driveArdumoto(MOTOR_B, CCW, 255);
  } else {
    if (leftSens == 0 && rightSens == 0) {
      driveArdumoto(MOTOR_A, CCW, 255);
      driveArdumoto(MOTOR_B, CW, 255);
    }

  }
}

