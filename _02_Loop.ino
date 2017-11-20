void loop() {

  if (RotarySwitchOn) {
    delay(Debounce);
    Serial.println("Menu");
    Menu();
  }

  lcd.setCursor(0, 0);
  lcd.print("Menu........knob");
  lcd.setCursor (0, 1);
  lcd.print("Sawing....button");

  if (Encoder0Pos != 0) { 
    ManualMove();
  }
  
  Encoder0Pos = 0;
  if (digitalRead(RedButton) == LOW) {
    delay(Debounce);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Clamp lumber");
    lcd.setCursor(0, 1);
    lcd.print("Ready?....button");

    Serial.println("Clamp Lumper");

    while (digitalRead(RedButton) == HIGH) {} //wait until ready sawing and red button is pushed
    delay(Debounce);

    if (Reverse == true) {
      Moving(SawBlade);
    }

    RotarySwitchOn = false;
    do
    {
      if (Reverse == false) {
        Moving(SawBlade);
        Sawing();
      }
      if (Reverse == true) {

        // reverse Gap and Finger;
        Dummy1 = GapWidth;
        GapWidth = FingerWidth;
        FingerWidth = Dummy1;

        Reverse_Sawing();
        Moving(SawBlade);

        // reset Gap and Finger;
        Dummy1 = GapWidth;
        GapWidth = FingerWidth;
        FingerWidth = Dummy1;

      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Next......button");
      lcd.setCursor(0, 1);
      lcd.print("Stop........knob");

      Serial.println("Voorbij wacht lus hoofd loop");
    }
    while (RotarySwitchOn == false);
    RotarySwitchOn = false;
  }

}
