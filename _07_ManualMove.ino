void ManualMove() {
  int ManualStep = 30;

  if (Encoder0Pos > 0) {
    Moving(ManualStep);
    
  }
  else {
    while (digitalRead(LimitSwitch) == HIGH){
      
    Serial.println("Move back to start position");
    Moving(-ManualStep);
    }
    Moving(ManualStep); //Moving forward to limit slack 
    
  }

}
