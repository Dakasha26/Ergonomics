/*
    Автор: Скворцов Даниил
    Дата: 07.03.22
    Назначение: Программа для Ардуино - получает через Serial число, проверяет его на чётность и возвращает результат.
*/

// Настройка параметров
void setup() {
  Serial.begin(9600); // Стандартное значение
  //Serial.print((char)255);
  Serial.flush();
}

// Работа программы в бесконечном цикле
void loop() {
  if(Serial.available() > 0) {
    int number = Serial.read();
    if(number % 2 == 0)
      Serial.print('Чётное');
    else
      Serial.print('Нечётное');     
    Serial.flush();
  }
}