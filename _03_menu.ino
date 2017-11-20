void Menu() {

  // *** Setting finger width

  StepCorrection = 0; //Accuracy correction reset

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("fingerwidth:");
  delay(Debounce);

  RotarySwitchOn = false;

  while (RotarySwitchOn == false) {     //Move on Rotary switch trigger
    Encoder0Pos = 0;
    lcd.setCursor(0, 1);
    lcd.print(FingerWidth / 10);
    lcd.print(".");
    lcd.print(FingerWidth % 10);
    lcd.print("                ");
    if (Encoder0Pos != 0) {
      FingerWidth = FingerWidth + Encoder0Pos;
    }
    if (FingerWidth > MaxDimension ) { // maximum or trying to make negative (unsigned is not possible)
      FingerWidth = 1;
    }
    if (FingerWidth == 0) {
      FingerWidth = 1; // minimum is 1/10 mm
    }
  }

  // *** Setting gap width
  lcd.clear();
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("gapwidth:");
  delay(Debounce);

  RotarySwitchOn = false;

  while (RotarySwitchOn == false) {   //Move on Rotary switch trigger
    Encoder0Pos = 0;
    lcd.setCursor(0, 1);
    lcd.print(GapWidth / 10);
    lcd.print(".");
    lcd.print(GapWidth % 10);
    lcd.print("                ");
    if (Encoder0Pos != 0) {
      GapWidth = GapWidth + Encoder0Pos;
    }
    if (GapWidth > MaxDimension) {// maximum or trying to make negative (unsigned is not possible)
      GapWidth = 1;
    }
    if (GapWidth <= SawBlade) {
      GapWidth = SawBlade; // minimum is the saw blade width
    }
  }
  delay(Debounce);

  // *** Setting overlap
  lcd.clear();
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("overlap:");
  delay(Debounce);

  RotarySwitchOn = false;

  while (RotarySwitchOn == false) {   //Move on Rotary switch trigger
    Encoder0Pos = 0;
    lcd.setCursor(0, 1);

    lcd.print(OverLap / 10);
    lcd.print(".");
    lcd.print(OverLap % 10);
    lcd.print("                ");

    if (Encoder0Pos != 0) {
      OverLap = OverLap + Encoder0Pos;
    }


    if (OverLap > MaxDimension) {  // When trying to make unsigned OverLap negative
      OverLap = 0;
    }

    if (OverLap > (SawBlade - 1)) { // Maximum OverLap is SawBlade - 1/10mm
      OverLap = SawBlade - 1;
    }

  }
  delay(Debounce);


  // *** Setting reverse sawing
  lcd.clear();
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("reverse sawing:");
  delay(Debounce);

  RotarySwitchOn = false;

  while (RotarySwitchOn == false) {   //Move on Rotary switch trigger
    Encoder0Pos = 0;
    lcd.setCursor(0, 1);
    if (Reverse == true) {
      lcd.print("true");
      lcd.print("                ");
    }

    if (Reverse == false) {
      lcd.print("false");
      lcd.print("                ");
    }

    if (Encoder0Pos > 0) {
      Reverse = true;
    }
    if (Encoder0Pos < 0) {
      Reverse = false;
    }
  }
  delay(Debounce);


  // *** Setting accuracy
  lcd.clear();
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("accuracy:");
  delay(Debounce);

  RotarySwitchOn = false;

  while (RotarySwitchOn == false) {   //Move on Rotary switch trigger
    Encoder0Pos = 0;
    lcd.setCursor(0, 1);
    lcd.print(StepCorrectionTreshold);
    lcd.print("                ");
    if (Encoder0Pos != 0) {
      StepCorrectionTreshold = StepCorrectionTreshold + Encoder0Pos;
    }

    if (StepCorrectionTreshold > MaxDimension) {
      StepCorrectionTreshold = 0;
    }

  }
  delay(Debounce);



  // *** Exit Menu
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Exit Menu");
  delay(1000);

  RotarySwitchOn = false; // prevent that menu is called again
  Serial.println("Exit Menu");
}
