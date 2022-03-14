void Button()
{
  
  lcd.begin(16, 2);
  lcd.print(" button 1 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" button 2 ");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" button 3 ");
  delay(500);
  gameButtonState = digitalRead(gameButtonPin);
  delay(3000);
  //Time limit


  //If the player presses the button within the time limit
  if (gameButtonState == 0)
  {

    lcd.begin(16, 2);
    lcd.print(" Correct ");
    score = score+1;
    newScore = newScore + (score * 3 );
  }
  else
  {
    lcd.begin(16, 2);
    lcd.print(" Wrong ");
    gameOver = true;
    gameover();
  }
}
