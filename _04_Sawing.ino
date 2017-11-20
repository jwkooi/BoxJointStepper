// Sawing: first finger then gap. Opposite of Procedure reverse Sawing
void Sawing() {

  int LoopCount = 0;
  int EffectiveSawWidth = 0;
  int LastCut = 0;

  EffectiveSawWidth = SawBlade - OverLap;
  LoopCount =  ((GapWidth - SawBlade) / (SawBlade - OverLap)) + 1;

  Serial.println("Sawing  ");
  Serial.print("SawBlade :            "); Serial.println (SawBlade);
  Serial.print("Accuracy :            "); Serial.println (StepCorrectionTreshold);
  Serial.print("GapWidth :            "); Serial.println ( GapWidth);
  Serial.print("FingerWidth :         "); Serial.println ( FingerWidth);
  Serial.print("Overlap :             "); Serial.println (OverLap);

  Serial.print("Effective saw width : "); Serial.println ( EffectiveSawWidth);
  Serial.print("LoopCount :           "); Serial.println ( LoopCount);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moving to       ");
  lcd.setCursor(0, 1);
  lcd.print("start of gap    ");

  // Move fingerwidth
  Moving(FingerWidth); //Create finger

  //*** Start sawing gap

  // sawing all full effective saw width
  for (int T = 1; T < LoopCount; T++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ready sawing");
    lcd.setCursor(13, 0);
    lcd.print(T);
    lcd.setCursor(15, 0);
    lcd.print("?");
    lcd.setCursor(0, 1);
    lcd.print("Press button ");

    Serial.println("Ready sawing");

    digitalWrite(GreenLed, HIGH); // sawing
    while (digitalRead(RedButton) == HIGH) {
      }
    delay(Debounce);

    digitalWrite(GreenLed, LOW); // Sawing ready
    Moving(EffectiveSawWidth); //Box joint will move
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready sawing");
  lcd.setCursor(13, 0);
  lcd.print(LoopCount);
  lcd.setCursor(15, 0);
  lcd.print("?");
  lcd.setCursor(0, 1);
  lcd.print("Press button ");

  Serial.print("Ready sawing ");
  Serial.println(LoopCount);

  digitalWrite(GreenLed, HIGH); // sawing
  while (digitalRead(RedButton) == HIGH) {} //wait until ready sawing and red button is pushed
  delay(Debounce);

  digitalWrite(GreenLed, LOW); // Sawing ready

  // Last saw if applicable
  LastCut = (GapWidth - SawBlade) - ((LoopCount - 1) * EffectiveSawWidth);
  if (LastCut > 0) {
    Serial.println("Last cut");
    Serial.println(LastCut);

    Moving(LastCut); //last cut for gap

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ready sawing");
    lcd.setCursor(13, 0);
    lcd.print(LoopCount + 1);
    lcd.setCursor(15, 0);
    lcd.print("?");
    lcd.setCursor(0, 1);
    lcd.print("Press button ");

    digitalWrite(GreenLed, HIGH); // sawing
    while (digitalRead(RedButton) == HIGH) {} //wait until ready sawing and red button is pushed
    delay(Debounce);
    digitalWrite(GreenLed, LOW); // Sawing ready

  }


}

