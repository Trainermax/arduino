#include <LiquidCrystal.h> // includes the LiquidCrystal Library 


LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

int BUZZER = 9;
int RED = 10;
int GREEN = 11;
int BLUE = 12;
int buttonINPUT = 13;

int buttonState = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT); 
  pinMode(buttonINPUT, INPUT_PULLUP);
  lcd.print("Hello");
}

void loop()
{
 buttonState = digitalRead(buttonINPUT);
  if (buttonState == LOW) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);

      setColor(0, 255, 0);  // green    
     tone(BUZZER, 100, 1000);
       
      lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("It's alright");
      lcd.setCursor(0,1);
      lcd.print("stay calm");
     
      
  delay(1000);
  
   setColor(51,51,0);  // yellow
  tone(BUZZER, 200, 3000);
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("now slow");
    lcd.setCursor(0,1);
    lcd.print("down");
 
  
  delay(3000);  

  setColor(255, 0, 0);  // red
  tone(BUZZER, 300, 6000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("NOW MAKE A");
  lcd.setCursor(0,1);
  lcd.print("COMPLETE STOP");
    
    
  delay(6000);
  
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }



}

void buzzernoise(){

  tone(BUZZER, 3000, 500);
  delay(1000);
  
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);  
}

void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(RED, 255-brightness);
  analogWrite(GREEN, 255-brightness);
  analogWrite(BLUE, 255-brightness);
}
