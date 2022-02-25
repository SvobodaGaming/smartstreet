#include <Servo.h>  // подключение библиотеки для работы с серво
Servo garage; // создание объекта серво (гаражные ворота)
Servo lid;  // создание объекта серво (крышка мусорного бака)

int lights = 11;  // фонари

int ledR = 2; // красный для гаражных ворот

bool debug = false // режим отладки (по умолчанию "false")

int photorez = 0;  // датчик - фоторезистор (А0)
int data_photorez = 0;  // данные с порта фоторезистора
unsigned int lights_brightness = 0; // яркость фонарей 
const int NUM_READ = 32; // интенсивность фильтра значений

unsigned long last_time; // таймер для анимации
unsigned long last_time_lid; // таймер для крышки бака
unsigned long last_time_garage; // таймер для гаражных ворот

int IR_button_Lid = 3;  // ИК-кнопка (для крышки бака)
int data_IR_button_Lid = 0;  // данные с ИК-кнопки (для крышки бака)
int IR_button_Garage = 7;  // ИК-кнопка (для крышки бака)
int data_IR_button_Garage = 0;  // данные с ИК-кнопки (для крышки бака)

void setup() {
  pinMode(IR_button_Lid, 0);
  pinMode(IR_button_Garage, 0);

  pinMode(photorez, 0);

  pinMode(lights, 1);

  garage.attach(10);
  garage.write(0);

  lid.attach(5);
  lid.write(0);
  
  Serial.begin(9600); // настройка канала передачи данных (по умочанию 9600 бит/сек.)
}

void Osveshenie() { // управление освещением
  lights_brightness = (map(Filter(data_photorez), 8, 1024, 255, 0)); // преобразование значений с фоторезистора
  analogWrite(lights, lights_brightness);
}

void Garage() { // управление гаражными воротами
  if (data_IR_button_Garage == 1) { // если ИК-датчик принял данные (увидел отражение своего сигнала)
    last_time_garage = millis(); // обнулить таймер для гаража

    if (millis()-last_time_garage < 5000) { // если таймер для гаража < 5000 мл.сек.
      digitalWrite(ledR, 1); // включить предупредительный светодиод
      garage.write(180); // установить серво в положение 180 градусов
    }
  }
    if (millis()-last_time_garage > 5000) { // если таймер для гаража > 5000 мл.сек. 
      garage.write(0); // установить серво в положение 0 градусов
    }
}

void Lid() { // управление крышкой мусорного бака
  if (data_IR_button_Lid == 1) { // если ИК-датчик принял данные (увидел отражение своего сигнала)
    last_time_lid = millis(); // обнулить таймер для крышки

    if (millis()-last_time_lid < 5000) { // если таймер для крышки < 5000 мл.сек.

      lid.write(0); // установить серво в положение 0 градусов
    }
  }
    if (millis()-last_time_lid > 5000) { // если таймер для крышки > 5000 мл.сек. 
      lid.write(180); // установить серво в положение 180 градусов
    }
}

int Filter(int data_photorez) { // фильтр значений фоторезистора (управляется через NUM_READ)
  long sum = 0;
  for (int i = 0; i < NUM_READ; i++)
  sum += data_photorez;  
  return ((float)sum / NUM_READ);
}

void loop()  {
  data_photorez = analogRead(photorez); // считываем сигнал с аналогового входа (фоторезистора)
 
  data_IR_button_Lid = digitalRead(IR_button_Lid); // считываем сигнал с цифрового выхода (ИК-датчик крышки бака)
  data_IR_button_Garage = digitalRead(IR_button_Garage); // считываем сигнал с цифрового выхода (ИК-датчик гаража)

  if (debug == true) { // выводим данные ИК на монитор ПК (если включен режим отладки)
    Serial.print("kasanie Garage: ");
    Serial.println(data_IR_button_Garage);
    Serial.print("kasanie Lid: ");
    Serial.println(data_IR_button_Lid);
    Serial.print("osveshenie : ");
    Serial.println(Filter(data_photorez));
  }

  // вызываем функции (действия) отдельных систем
  Osveshenie();
  Garage();
  Lid();
}