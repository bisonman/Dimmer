//********************************************************************************************
//*
//*
//*
//*
//*
//*
//*
//*
//********************************************************************************************

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin = 9;        // the pin that the LED is attached to

int fadeValue = 0;
int fadeAmount = 5;          // how many points to fade the LED by
boolean buttonState = LOW;
boolean fadeDirection = HIGH;

//********************************************************************************************
//*
//********************************************************************************************
void
setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, fadeValue);
}

//********************************************************************************************
//*
//********************************************************************************************
void
loop()
{
  delay(30);
  
  if (digitalRead(buttonPin) == LOW) {
    switch (fadeDirection) {
      case LOW:
        fadeDown();
        delay(100);
        break;
        
      case HIGH:
        fadeUp();
        delay(100);
        break;
        
      default:
        break;
    }
  }
}

//********************************************************************************************
//*
//********************************************************************************************
void
fadeDown()
{
  Serial.println("fadeDown");
  // delay(200);
  while (digitalRead(buttonPin) == LOW);
  
#if 0
  if (digitalRead(buttonPin) == HIGH) {
    fadeValue = 0;
    analogWrite(ledPin, fadeValue);
    Serial.println("Off");
    fadeDirection = HIGH;
    return;
  }
#endif
  do {
    fadeValue -= 5;
    fadeValue &= 255;
    analogWrite(ledPin, fadeValue);
    
    if (fadeValue <= 0) {
      fadeDirection = HIGH;
      break;;
    }
    delay(15);
  } while (digitalRead(buttonPin) != LOW);
  
  fadeDirection = HIGH;
  Serial.println("Done");
}

//********************************************************************************************
//*
//********************************************************************************************
void
fadeUp()
{
  Serial.println("fadeUp()");
  // delay(200);
  while (digitalRead(buttonPin) == LOW);

#if 0
  if (digitalRead(buttonPin) == HIGH) {
    fadeValue = 255;
    analogWrite(ledPin, fadeValue);
    Serial.println("On");
    fadeDirection = LOW;
    return;
  }
#endif
  do {
    fadeValue += 5;
    fadeValue &= 255;
    analogWrite(ledPin, fadeValue);
    if (fadeValue >= 253) {
      break;
    }
    delay(15);
  } while (digitalRead(buttonPin) != LOW);
  fadeDirection = LOW;
  Serial.println("Done");
}

