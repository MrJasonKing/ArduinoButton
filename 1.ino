const int LED=9;
const int BUTTON=2;
bool lastButton=LOW;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(BUTTON, INPUT);
}
bool debounce(bool last)
{
  bool current = digitalRead(BUTTON);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(BUTTON);
  }
  return current;
}


void loop()
{
  currentButton=debounce(lastButton);
  /*
  Check if the previous button state was LOW and the current button state is HIGH.
  THE && is a logical operator that means AND
  */
  if (lastButton==LOW && currentButton==HIGH)
  {
    ledOn = !ledOn;
    /*
    if button has been presed, the value of the ledOn variable reassing.
    ! in fron of the LedOn variable resests the variable to the opposite value
    */
  }
  lastButton = currentButton;// update the previous button state to the current
  digitalWrite(LED, ledOn);
}
