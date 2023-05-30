// Declare constants for LED pins and button pin
const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON = 2;

// Declare variables for button state tracking and LED mode
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

// Setup function to initialize pin modes
void setup() {
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// Debounce function to prevent false button press detections
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

// Set the LED mode based on the passed mode value
void setMode(int mode)
{
  //RED
  if(mode == 1)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  //GREEN
  else if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  
  //Your Code goes here
  
  //OFF (mode == 0)
  else  
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

// Main loop function
void loop() 
{
  // Read the current button state and debounce
  currentButton = debounce(lastButton);
  
  // Check for button press and increment LED mode
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledMode=ledMode+1;
  }
  
  // Update lastButton state
  lastButton = currentButton;
  
  // Reset ledMode if it exceeds maximum mode value
  if (ledMode == 7) ledMode = 0;
  
  // Set LED mode based on ledMode value
  setMode(ledMode); 
}
