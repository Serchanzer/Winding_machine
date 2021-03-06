#include <LiquidCrystal_PCF8574.h>
#include <Wire.h> 
#include <Keypad.h>    
//-------------------------------------------------------------------------------------------------------
// 1 двигатель
const int STEP1=2;
const int DIR1=13;
// 2 двигатель
const int STEP2=3;
const int DIR2=4;
//-------------------------------------------------------------------------------------------------------
const byte ROWS = 4;   // Количество рядов в панели
const byte COLS = 4;   // Количество строк 
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {12, 11, 10, 9}; // Выводы, подключение к строкам
byte colPins[COLS] = {8, 7, 6, 5}; // Выводы, подключение к столбцам  
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);  
LiquidCrystal_PCF8574 lcd(0x27);
char key = ' ';
//-------------------------------------------------------------------------------------------------------
void setup() {
  // режим для STEP и DIR как OUTPUT
  pinMode(STEP1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(STEP2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  // начальные значения
  digitalWrite(STEP1, 1);
  digitalWrite(DIR1, 0);
  digitalWrite(STEP2, 1);
  digitalWrite(DIR2, 0);

  lcd.begin(16, 2);                     // Инициализация дисплея  
  lcd.setBacklight(255);                 // Подключение подсветки
  lcd.clear();              // Установка курсора в начало первой строки
  lcd.print("Made by");       // Набор текста на первой строке
  delay(200); 
  lcd.setCursor(0,1);              // Установка курсора в начало второй строки
  lcd.print("Silkwarms");       // Набор текста на второй строке
  delay(1000); 
}
//-------------------------------------------------------------------------------------------------------
void loop() { 
  lcd.clear();
  lcd.print("Apply template?");
  lcd.setCursor(0,1);
  lcd.print("Yes(*) / NO(#)");
  while (key == ' ')  key = keypad.getKey();
  if (key == '*'){
    Winding (10,20); 
  }
  else if (key == '#'){
    lcd.clear();
    lcd.print("Enter turns:");
    lcd.setCursor(0,1);
  }
  else {
    MC ();
  }
}
//-------------------------------------------------------------------------------------------------------
void Winding (int diam, int turns) {
  lcd.clear();              
  lcd.print("Please, wait..."); 
  delay(1000);      
  int DELAY_STEPS1=5;
  int DELAY_STEPS2=10; 
  int STEP_ROUND=200;

  lcd.clear();              
  lcd.print("Turns: "); 
  lcd.setCursor(11,0);              
  lcd.print("/");
  lcd.setCursor(13,0);              
  lcd.print(turns);

  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  
  for(int turn_now = 1; turn_now < turns + 1; turn_now++) {    
    lcd.setCursor(8,0);              
    lcd.print(turn_now);
    
    for(int i = 0; i < STEP_ROUND; i++) {
      digitalWrite(STEP1, HIGH);
      delay(DELAY_STEPS1);
      digitalWrite(STEP1, LOW);
      delay(DELAY_STEPS1);
    
      digitalWrite(STEP2, HIGH);
      delay(DELAY_STEPS2);
      digitalWrite(STEP2, LOW);
      delay(DELAY_STEPS2);     
    }
    
  }

}
//-------------------------------------------------------------------------------------------------------
void MC () {
  int DELAY_STEPS1=5;
  int DELAY_STEPS2=10; 
  int STEP_ROUND=200;
 
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  if (key == 'A') {
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, LOW);
    while (key == 'A') {
      digitalWrite(STEP1, HIGH);
      delay(DELAY_STEPS1);
      digitalWrite(STEP1, LOW);
      delay(DELAY_STEPS1);
    
      digitalWrite(STEP2, HIGH);
      delay(DELAY_STEPS2);
      digitalWrite(STEP2, LOW);
      delay(DELAY_STEPS2); 
      key=keypad.getKey();   
    }   
  }

  else if (key == 'B') {
    digitalWrite(DIR1,LOW);
    digitalWrite(DIR2, HIGH);
    while (key == 'A') {
      digitalWrite(STEP1, HIGH);
      delay(DELAY_STEPS1);
      digitalWrite(STEP1, LOW);
      delay(DELAY_STEPS1);
    
      digitalWrite(STEP2, HIGH);
      delay(DELAY_STEPS2);
      digitalWrite(STEP2, LOW);
      delay(DELAY_STEPS2);
      key=keypad.getKey();      
    }
  }
  else if (key == 'C') {
    digitalWrite(DIR1, LOW);
    while (key == 'C') {
      digitalWrite(STEP1, HIGH);
      delay(DELAY_STEPS1);
      digitalWrite(STEP1, LOW);
      delay(DELAY_STEPS1);
    }
  }

}
