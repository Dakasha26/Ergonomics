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
    int number = Serial.parseInt();
    if(number % 2 == 0)
      Serial.println(1); // Чётное
    else
      Serial.println(0); // Нечётное    
    Serial.flush();
  }
}
