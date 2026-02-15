// пины
#define HC_TRIG 3
#define HC_ECHO 2

// сделаем функцию для удобства
float getDist(uint8_t trig, uint8_t echo) {
  // импульс 10 мкс
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // измеряем время ответного импульса
  uint32_t us = pulseIn(echo, HIGH);

  // считаем расстояние и возвращаем
  return us / 58.2;
}

void setup() {
  Serial.begin(115200);     // для связи
  pinMode(HC_TRIG, OUTPUT); // trig выход
  pinMode(HC_ECHO, INPUT);  // echo вход
}

void loop() {
  float dist = getDist(HC_TRIG, HC_ECHO);   // получаем расстояние
  Serial.println(dist);                     // выводим
  delay(50);
}
