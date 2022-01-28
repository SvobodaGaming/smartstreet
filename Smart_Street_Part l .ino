#include <Servo.h>  // подключение библиотеки для работы с серво
Servo garage; // создание объекта серво (гаражные ворота)
Servo lid;  // создание объекта серво (крышка мусорного бака)

int lights = 12;  // фонари

int ledR = 3; // красный для гаражных ворот

int photorez = 0;  // датчик - фоторезистор (А0)
int data_photorez = 0;  // данные с порта фоторезистора
const int NUM_READ = 64; 

unsigned long last_time; // таймер для анимации

int greenPIN1 = 11;
int redPIN1 = 10;
int greenPIN2 = 8;
int greenPIN3 = 6;
int greenPIN4 = 4;

int IR_button_Lid = 2;  // ИК-кнопка (для крышки бака)
int data_IR_button_Lid = 0;  // данные с ИК-кнопки (для крышки бака)
int IR_button_Garage = 10;  // ИК-кнопка (для крышки бака)
int data_IR_button_Garage = 0;  // данные с ИК-кнопки (для крышки бака)

void setup() 
{
  pinMode(redPIN1, 0);
  pinMode(greenPIN1, 0);
  pinMode(greenPIN2, 0);
  pinMode(greenPIN3, 0);
  pinMode(greenPIN4, 0);

  pinMode(photorez, 0);

  pinMode(lights, 1);

  // настройка канала передачи данных (по умочанию 9600 бит/сек.)
  Serial.begin(9600);

  garage.attach(9);
  garage.write(0);

  lid.attach(5);
  lid.write(0);
  
  // настройка канала передачи данных (по умочанию 9600 бит/сек.)
  Serial.begin(9600);
}

void Osveshenie() {
    // если показания с фоторезистора > 900  
  if (data_photorez > 900) {
  // устанавливаем яркость фонарей в состояние 0 - выкл (минимум)
    analogWrite(lights, 0);
  }

  // если показания с фоторезистора > 600 и < 900
  if (data_photorez > 520 && data_photorez < 900) {
  // устанавливаем яркость фонарей в состояние 10 - еле включены (можно ставить до 100)
    analogWrite(lights, 10);
  }

  // если показания с фоторезистора < 600
  if (data_photorez < 600) {
  // устанавливаем яркость фонарей в состояние 255 - ярко (максимум)
    analogWrite(lights, 255);
 }
}

void firstAnimation() {
   // раз в  33 секунды (общее время круга работы светофоров)
  if (millis()-last_time > 33000) {
    // сбрасываем таймер
    last_time = millis();
  }

    // на 10 сек
    if (millis()-last_time < 10000) {
      //вкл зеленый для авто и красный для пешеходов
      digitalWrite(redPIN1, 1);
    }

    //  на 0.5 сек
    if (millis()-last_time > 10000 && millis()-last_time < 10500)  {
      // выкл зеленый для авто
      digitalWrite (redPIN1, 0);
    }

    // на 0.5 сек  
    if (millis()-last_time > 10500 && millis()-last_time < 11000) {
     // вкл зеленый для авто
      digitalWrite (redPIN1, 1);
    }

    // на 0.5 сек
    if (millis()-last_time > 11000 && millis()-last_time < 11500) {
     // выкл зеленый для авто
      digitalWrite (redPIN1, 0);
    }

    // на 0.5 сек   
    if (millis()-last_time > 11500 && millis()-last_time < 12000) {
     // вкл зеленый для авто
      digitalWrite (redPIN1, 1);
    }

    // на 0.5 сек 
    if (millis()-last_time > 12000 && millis()-last_time < 12500) {
     // выкл зеленый для авто
      digitalWrite (redPIN1, 0);
    }

    // на 0.5 сек
    if (millis()-last_time > 12500 && millis()-last_time < 13000) {
     // вкл зеленый для авто
      digitalWrite (redPIN1, 1);
    }

    // на 3 сек  
    if (millis()-last_time > 13000 && millis()-last_time < 16000) {
      // выкл зеленый для авто и включаем оранжевый
      digitalWrite (redPIN1, 0);
    }

    // на 10 сек  
    if (millis()-last_time > 16000 && millis()-last_time < 26000) {
      // включаем красный для авто и зеленый для пешеходов
      digitalWrite (greenPIN1, 1);
      if (millis()-last_time > 16500 && millis()-last_time < 17000) {
        digitalWrite(greenPIN2, 1);
      } if (millis()-last_time > 17000 && millis()-last_time < 17500) {
        digitalWrite(greenPIN2, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 17500 && millis()-last_time < 18000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN4, 1);
      } if (millis()-last_time > 18000 && millis()-last_time < 18500) {
        digitalWrite(greenPIN4, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 18500 && millis()-last_time < 19000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN2, 1);
      } if (millis()-last_time > 19000 && millis()-last_time < 19500) {
        digitalWrite(greenPIN2, 1);
      } if (millis()-last_time > 20000 && millis()-last_time < 20500) {
        digitalWrite(greenPIN2, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 20500 && millis()-last_time < 21000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN4, 1);
      } if (millis()-last_time > 21000 && millis()-last_time < 21500) {
        digitalWrite(greenPIN4, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 21500 && millis()-last_time < 22000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN2, 1);
      } if (millis()-last_time > 22000 && millis()-last_time < 22500) {
        digitalWrite(greenPIN2, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 22500 && millis()-last_time < 23000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN4, 1);
      } if (millis()-last_time > 23000 && millis()-last_time < 23500) {
        digitalWrite(greenPIN4, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 23500 && millis()-last_time < 24000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN2, 1);
      } if (millis()-last_time > 24000 && millis()-last_time < 24500) {
        digitalWrite(greenPIN2, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 24500 && millis()-last_time < 25000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN4, 1);
      } if (millis()-last_time > 25000 && millis()-last_time < 25500) {
        digitalWrite(greenPIN4, 0);
        digitalWrite(greenPIN3, 1);
      } if (millis()-last_time > 25500 && millis()-last_time < 26000) {
        digitalWrite(greenPIN3, 0);
        digitalWrite(greenPIN2, 1);
      }
      digitalWrite(greenPIN1, 0);
    }

    // на 0.5 сек  
    if (millis()-last_time > 26000 && millis()-last_time < 26500) {
      // выкл зеленый для пешеходов
      digitalWrite (greenPIN1, 0);
    }
    
    // на 0.5 сек  
    if (millis()-last_time > 26500 && millis()-last_time < 27000) {
      // вкл зеленый для пешеходов
      digitalWrite (greenPIN1, 1);
}
  
    // на 0.5 сек
    if (millis()-last_time > 27000 && millis()-last_time < 27500) {
      // выкл зеленый для пешеходов
      digitalWrite (greenPIN1, 0);
}
    
    // на 0.5 сек
    if (millis()-last_time > 27500 && millis()-last_time < 28000) {
      // вкл зеленый для пешеходов
      digitalWrite (greenPIN1, 1);
    }
  
    // на 0.5 сек
    if (millis()-last_time > 28000 && millis()-last_time < 28500) {
      // выкл зеленый для пешеходов
      digitalWrite (greenPIN1, 0);
    }
  
    // на 0.5 сек
    if (millis()-last_time > 28500 && millis()-last_time < 29000) {
      // вкл зеленый для пешеходов
      digitalWrite (greenPIN1, 1);}
  
    // на 3 сек
    if (millis()-last_time > 29000 && millis()-last_time < 32000) {
      // выкл зеленый для пешеходов и вкл оранжевый и красный для авто
      digitalWrite (greenPIN1, 0);
      digitalWrite (redPIN1, 1);
    }
}
void Garage() {
  if (data_IR_button_Garage == 1) {
    digitalWrite(ledR, 0);

    delay(2000);

    garage.write(180);
  }

  garage.write(0);
}

void Lid() {
  // если ИК-датчик принял данные (увидел отражение своего сигнала)
  if (data_IR_button_Lid == 1) {
        delay(2000);
        // установить серво в положение 180 градусов
        lid.write(180);
  }
    // установить серво в положение 0 градусов
    lid.write(0);
}

int Filter(int data_photorez) {
  long sum = 0;
  for (int i = 0; i < NUM_READ; i++)
  sum += data_photorez;  
  return ((float)sum / NUM_READ);
}

void loop() 
{
  // считываем сигнал с аналогового входа (фоторезистора)
  data_photorez = analogRead(photorez);
  Filter(data_photorez);

  data_IR_button_Lid = digitalRead(IR_button_Lid);
  data_IR_button_Garage = digitalRead(IR_button_Garage);

  // считываем сигнал с аналогового входа (фоторезистора)

  // выводим данные ИК на монитор ПК
  Serial.print("kasanie Garage: ");
  Serial.println(data_IR_button_Garage);
  Serial.print("kasanie Lid: ");
  Serial.println(data_IR_button_Lid);
  Serial.print("osveshenie : ");
  Serial.println(data_photorez);

  // вызываем функции (действия) отдельных систем
  firstAnimation();
  Osveshenie();
  Garage();
  Lid();
}