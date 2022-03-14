void joystickLeftOrRight()
{
  //LED ring lights up

  //Time limit
lcd.begin(16, 2);
  lcd.print(" x joystick 1 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" x joystick 2 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" x joystick 3 ");
  delay(500);

  xjoyvalue = analogRead(xjoy);
  xjoyvalue = analogRead(xjoy);
  xjoyvalue = analogRead(xjoy);

  //If the player moves the joystick left or right within the time limit
  if (xjoyvalue > 510 || xjoyvalue < 500)
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
    lcd.begin(16, 2);
    lcd.print(" Wrong ");
    gameOver = true;
    gameover();
    delay(3000);

  }

}
