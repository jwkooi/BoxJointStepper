void doEncoder() {
  /* If pinA and pinB are both high or both low, it is spinning
   * forward. If they're different, it's going backward.
   *
   * For more information on speeding up this process, see
   * [Reference/PortManipulation], specifically the PIND register.
   */

  if (digitalRead(Encoder0PinA) == digitalRead(Encoder0PinB)) {
    Encoder0Pos = -1;
  }

  else {
    Encoder0Pos = + 1;
  }


//delay(100);

//Serial.print ("Interrupt 0 ");
//Serial.println (Encoder0Pos, DEC);


}

