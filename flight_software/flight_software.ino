#include <PID.h>

const int INITIAL_POSITION = 0;
const float SET_POINT = 0.005;

const int MAX_MAGNET_FORCE = 55;
const int MIN_MAGNET_FORCE = 0;

const int MAX_VOLTS = 24;
const int RESISTANCE = 2;

const float kP = 58024.7697722311;
const float kI = 679104.182905479;
const float kD = 1217.40122699774;
const float N = 1363.49256355405;
const float SAMPLE_TIME = 0.0001;

const int RESISTOR_PIN = A0;
const int SENSOR_PIN = A1;
const int OUTPUT_PIN = 9;

PID pid(INITIAL_POSITION, SET_POINT, MAX_MAGNET_FORCE, MIN_MAGNET_FORCE, kP, kI, kD, N, SAMPLE_TIME);

float error() {
  int sensorOutput = analogRead(SENSOR_PIN);
  // TODO: convert sensorOutput into meters
  float height = random(SET_POINT);
  return SET_POINT - height;
}

float current(float force, float error) {
  // implement inversion regression
  return 0;
}

void actuate(float current) {
  // measure voltage drop across resistor to calculate total resistance acrosss the circuit
  // calculate volts needed to drive the given current
}

void setup() {
  Serial.begin(9600);

  // pin setup
  pinMode(RESISTOR_PIN, INPUT);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
}
