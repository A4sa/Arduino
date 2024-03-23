// Motor pin definitions
#define M1_PIN 40        // Motor 1
#define M2_PIN 38        // Motor 2
#define M3_PIN 36       // Motor 3
#define M4_PIN 34        // Motor 4

// Sensor pin definitions
#define SENSOR_LEFT_PIN 26   // Sensor
#define SENSOR_RIGHT_PIN 27  // Sensor

// RPM values for motors at different voltages
#define M1_M2_RPM_29V 60
#define M1_M2_RPM_22V 40
#define M3_M4_RPM_29V 240
#define M3_M4_RPM_22V 180

// Motor speed variables
int m1_m2_speed;
int m3_m4_speed;

void setup() {
  // Initialize motor pins as OUTPUT
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);
  pinMode(M3_PIN, OUTPUT);
  pinMode(M4_PIN, OUTPUT);

  // Initialize sensor pins as INPUT
  pinMode(SENSOR_LEFT_PIN, INPUT);
  pinMode(SENSOR_RIGHT_PIN, INPUT);

  // Set initial motor speeds
  m1_m2_speed = M1_M2_RPM_29V;
  m3_m4_speed = M3_M4_RPM_29V;
}

void loop() {
  // Read sensor values
  int leftSensorValue = digitalRead(SENSOR_LEFT_PIN);
  int rightSensorValue = digitalRead(SENSOR_RIGHT_PIN);

  // Check if barrier detected by either sensor
  if (leftSensorValue == HIGH || rightSensorValue == HIGH) {
    // Reverse motor directions
    digitalWrite(M1_PIN, LOW);
    digitalWrite(M2_PIN, LOW);
    digitalWrite(M3_PIN, HIGH);
    digitalWrite(M4_PIN, HIGH);
  } else {
    // Set motor directions
    digitalWrite(M1_PIN, HIGH);
    digitalWrite(M2_PIN, HIGH);
    digitalWrite(M3_PIN, LOW);
    digitalWrite(M4_PIN, LOW);
  }

  // Adjust motor speeds based on battery voltage
  float batteryVoltage = readBatteryVoltage(); // Function to read battery voltage
  if (batteryVoltage > 29.2) {
    m1_m2_speed = M1_M2_RPM_29V;
    m3_m4_speed = M3_M4_RPM_29V;
  } else if (batteryVoltage < 22) {
    m1_m2_speed = M1_M2_RPM_22V;
    m3_m4_speed = M3_M4_RPM_22V;
  } else {
    // Linearly interpolate motor speeds between 29.2V and 22V
    m1_m2_speed = map(batteryVoltage, 22, 29.2, M1_M2_RPM_22V, M1_M2_RPM_29V);
    m3_m4_speed = map(batteryVoltage, 22, 29.2, M3_M4_RPM_22V, M3_M4_RPM_29V);
  }

  // Set motor speeds
  analogWrite(M1_PIN, m1_m2_speed);
  analogWrite(M2_PIN, m1_m2_speed);
  analogWrite(M3_PIN, m3_m4_speed);
  analogWrite(M4_PIN, m3_m4_speed);
}

float readBatteryVoltage() {
  // Code to read the battery voltage using appropriate analog pins and calculations
  // Replace this with your actual code to read the battery voltage
  return 0.0; // Placeholder value, replace with the actual battery voltage
}