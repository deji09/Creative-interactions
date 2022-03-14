void potentiometer ()
{

  delay(3000);
  lcd.begin(16, 2);
  lcd.print(" Potentiometer 1");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" Potentiometer 2");
  delay(500);
  lcd.begin(16, 2);
  lcd.print(" Potentiometer 3");
  delay(500);
  value = analogRead(pot);
  value = analogRead(pot);
  value = analogRead(pot);
 delay(1200);
  newvalue = analogRead(pot);
  newvalue = analogRead(pot);
  newvalue = analogRead(pot);


  if (newvalue > value + 80 )
  {
    delay(3000);
    lcd.begin(16, 2);
    lcd.print(" Correct ");
    score = score+1;
    newScore = newScore + (score * 3);
    delay(3000);
  }
  else  if (newvalue < value - 80 )
  {
    delay(3000);
    lcd.begin(16, 2);
    lcd.print(" Correct ");
    score = score+1;
    newScore = newScore + (score * 3);
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


//  //If the player does not press the button
//  //within the time limit, the game will be over
//  if (newScore == score)
//  {
//    gameOver = true;
//  }
//  //Keeps the score up to date
//  else
//  {
//    //    lcd.print(score);
//  }






}
