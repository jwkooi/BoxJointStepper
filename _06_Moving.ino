void Moving(int MM) {

  boolean GoForward;
  digitalWrite(RedLed, HIGH); //Warning light. Jig is not ready to saw
  digitalWrite(Step, LOW);

  Serial.print ("*** Stepper will move :");
  Serial.print (MM);
  Serial.println ("   1/10 mm");

  //set direction of stepper motor
  if (MM > 0) {
    GoForward = true; 
    digitalWrite(Direction, LOW);
  }
  if (MM < 0) {
    GoForward = false;
    digitalWrite (Direction, HIGH);
    MM = -MM;
  }

  if (digitalRead(LimitSwitch) == HIGH || GoForward) {  // Check if Limit Switch is reached (High = save, Low = stop moving) and not going back
    for (int R = 0; R < MM; R++) {
      // move 1/10 mm
      if (digitalRead(LimitSwitch) == HIGH || GoForward) {  // Check if Limit Switch is reached (High = save, Low = stop moving) and not going back
        for (int S = 0; S < TenthMM; S++) {

          if (digitalRead(LimitSwitch) == HIGH || GoForward) {  // Check if Limit Switch is reached (High = save, Low = stop moving) and not going back

            digitalWrite (Step, HIGH);
            delayMicroseconds(1);
            digitalWrite (Step, LOW);
            StepCorrection++;
            delayMicroseconds(StepperSpeed);

            // additional corrections after StepCorrectionTreshold steps
            if (digitalRead(LimitSwitch) == HIGH) {  // Check if Limit Switch is reached (High = save, Low = stop moving)
              if (StepCorrection >= StepCorrectionTreshold) {
                digitalWrite (Step, HIGH);
                delayMicroseconds(1);
                digitalWrite (Step, LOW);
                delayMicroseconds(StepperSpeed);
                StepCorrection = 0;
              }
            }

          }

        }
      }
    }
  }

  Serial.println ("Stepper move ready :");
  digitalWrite(RedLed, LOW);
}

