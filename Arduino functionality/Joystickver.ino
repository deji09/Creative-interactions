void joystickUpOrDown()
{
  //LED ring lights up

  //Time limit

  lcd.begin(16, 2);
  lcd.print(" y joystick 1 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" y joystick 2 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" y joystick 3 ");
  delay(500);
  yjoyvalue = analogRead(yjoy);
  yjoyvalue = analogRead(yjoy);
  yjoyvalue = analogRead(yjoy);
  Serial.println(yjoyvalue);

  //If the player moves the joystick left or right within the time limit

  if (yjoyvalue > 550 || yjoyvalue < 500)
  {
    score = score+1;
    newScore = newScore + (score * 3);
    delay(3000);
    lcd.begin(16, 2);
    lcd.print(" Correct ");
    delay(3000);
  }
  else
  {
    delay(3000);
    gameOver = true;
    gameover();
    lcd.begin(16, 2);
    lcd.print(" Wrong ");
    delay(3000);

  }

}
