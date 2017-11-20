void setup() {

  Serial.begin(9600);
  Serial.println("Setup");

  // Rotary switch 
  pinMode(Encoder0PinA, INPUT);
  pinMode(Encoder0PinB, INPUT);
  pinMode(Switch1Pin, INPUT);
 
  // Interrupt setup
  attachInterrupt(0, doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2
  attachInterrupt(1, doSwitch, LOW);   // switch pin on interrupt 1 - pin 3

  // Red Button
  pinMode (RedButton, INPUT); // normal HIGH, pressed LOW

  // Limit switch
  pinMode (LimitSwitch, INPUT); // normal HIGH, pressed LOW

  //Leds
  pinMode (RedLed, OUTPUT);
  pinMode (GreenLed, OUTPUT);

  // Easy stepper
  pinMode(Step, OUTPUT);
  pinMode(Direction, OUTPUT);
  digitalWrite(Step, LOW);
  digitalWrite(Direction, LOW);

  lcd.begin(16, 2);

  // -------  blinks of backlight LCD -------------
  lcd.clear();
  lcd.backlight();
  delay(150);
  lcd.noBacklight();
  delay(150);
  lcd.backlight(); // finish with backlight on

  // Start message
  lcd.clear();
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("Box Joint Jig");
  lcd.setCursor(0, 1);
  lcd.print("by JW Kooi");
  delay(3000);
  lcd.clear();

}

