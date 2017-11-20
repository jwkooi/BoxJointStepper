void doSwitch() {
  /*
   * Set motorspeed to 0 when switch is used (input goes low when pressed)
   *
  */
  RotarySwitchOn = true;

  Serial.print ("Interrupt 1: MenuOn is: ");
  Serial.println (RotarySwitchOn);
}
