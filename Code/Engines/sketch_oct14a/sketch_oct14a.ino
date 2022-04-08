int STEP_PIN=3;
int DIR_PIN=2;

// задержка между шагами двигателя
int DELAY_STEPS=10;

// количество шагов на 1 оборот
int STEP_ROUND=200;

void setup() {
  // режим для STEP и DIR как OUTPUT
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  // начальные значения
  digitalWrite(STEP_PIN, 1);
  digitalWrite(DIR_PIN, 0);
}

void loop() {
  // Крутимся в одну сторону
  digitalWrite(DIR_PIN, HIGH);
  //  1 оборот
  for(int i = 0; i < STEP_ROUND; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(DELAY_STEPS);
    digitalWrite(STEP_PIN, LOW);
    delay(DELAY_STEPS);
  }
  // Затем меняем направление и крутимся в другую сторону
  digitalWrite(DIR_PIN, LOW);
  // сделать 1 оборот
  for(int i = 0; i < STEP_ROUND; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(DELAY_STEPS);
    digitalWrite(STEP_PIN, LOW);
    delay(DELAY_STEPS);
  }
}
