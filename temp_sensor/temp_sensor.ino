int temp_sensor = A0; // the TMP36 temperature sensor is connected to Pin A0 of the Arduino
int led_green = 2;    // the green LED is connected to Pin 2 of the Arduino
int led_yellow = 3;   // the yellow LED is connected to Pin 3 of the Arduino
int led_red = 4;      // the red LED is connected to Pin 4 of the Arduino

float cool_limit = 25.0; // below 25 C the green LED is on
float warm_limit = 30.0; // from 25 C to 30 C the yellow LED is on, above 30 C the red LED is on

void setup() {
  // start the Serial Monitor so we can see the temperature
  Serial.begin(9600);

  // set up all the LEDs as OUTPUT
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  // read the sensor (a number from 0 to 1023)
  int reading = analogRead(temp_sensor);

  // turn the reading into volts, then into degrees Celsius
  float voltage = reading * 5.0 / 1024.0;
  float temperature = (voltage - 0.5) * 100.0;

  // print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature < cool_limit) {
    // cool: turn the green LED on and the other LEDs off
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, LOW);
  } else if (temperature < warm_limit) {
    // warm: turn the yellow LED on and the other LEDs off
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_red, LOW);
  } else {
    // hot: turn the red LED on and the other LEDs off
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_red, HIGH);
  }

  delay(1000); // wait 1 second before reading again
}
