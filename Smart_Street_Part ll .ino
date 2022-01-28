int svAR = 12;  // красный для авто
int svAY = 11;  // оранжевый для авто
int svAG = 10;  // зеленый для авто

int svPR = 9;  // красный для пешеходов
int svPG = 8;  // зеленый для пешеходов

unsigned long last_time; // таймер для светофора

void setup() 
{
  pinMode(svAR, 1);
  pinMode(svAY, 1);
  pinMode(svAG, 1);

  pinMode(svPR, 1);
  pinMode(svPG, 1);
  
  // настройка канала передачи данных (по умочанию 9600 бит/сек.)
  Serial.begin(9600);
}

void loop() 
{
  // вызываем функции (действия) отдельных систем
  Svetofor();
}

void Svetofor () {
   // раз в  33 секунды (общее время круга работы светофоров)
  if (millis()-last_time > 33000) {
    // сбрасываем таймер
    last_time = millis();
  }

    // на 10 сек
    if (millis()-last_time < 10000) {
      //вкл зеленый для авто и красный для пешеходов
      digitalWrite (svAG, 1);  
      digitalWrite (svPR, 1);
      digitalWrite (svAR, 0);
      digitalWrite (svAY, 0);
    }

    //  на 0.5 сек
    if (millis()-last_time > 10000 && millis()-last_time < 10500)  {
      // выкл зеленый для авто
      digitalWrite (svAG, 0);
    }

    // на 0.5 сек  
    if (millis()-last_time > 10500 && millis()-last_time < 11000) {
     // вкл зеленый для авто
      digitalWrite (svAG, 1);
    }

    // на 0.5 сек
    if (millis()-last_time > 11000 && millis()-last_time < 11500) {
     // выкл зеленый для авто
      digitalWrite (svAG, 0);
    }

    // на 0.5 сек   
    if (millis()-last_time > 11500 && millis()-last_time < 12000) {
     // вкл зеленый для авто
      digitalWrite (svAG, 1);
    }

    // на 0.5 сек 
    if (millis()-last_time > 12000 && millis()-last_time < 12500) {
     // выкл зеленый для авто
      digitalWrite (svAG, 0);
    }

    // на 0.5 сек
    if (millis()-last_time > 12500 && millis()-last_time < 13000) {
     // вкл зеленый для авто
      digitalWrite (svAG, 1);
    }

    // на 3 сек  
    if (millis()-last_time > 13000 && millis()-last_time < 16000) {
      // выкл зеленый для авто и включаем оранжевый
      digitalWrite (svAG, 0);
      digitalWrite (svAY, 1);
    }

    // на 10 сек  
    if (millis()-last_time > 16000 && millis()-last_time < 26000) {
      // включаем красный для авто и зеленый для пешеходов
      digitalWrite (svAY, 0);
      digitalWrite (svAR, 1);
      digitalWrite (svPR, 0);
      digitalWrite (svPG, 1);
    }

    // на 0.5 сек  
    if (millis()-last_time > 26000 && millis()-last_time < 26500) {
      // выкл зеленый для пешеходов
      digitalWrite (svPG, 0);
    }
    
    // на 0.5 сек  
    if (millis()-last_time > 26500 && millis()-last_time < 27000) {
      // вкл зеленый для пешеходов
      digitalWrite (svPG, 1);
}
  
    // на 0.5 сек
    if (millis()-last_time > 27000 && millis()-last_time < 27500) {
      // выкл зеленый для пешеходов
      digitalWrite (svPG, 0);
}
    
    // на 0.5 сек
    if (millis()-last_time > 27500 && millis()-last_time < 28000) {
      // вкл зеленый для пешеходов
      digitalWrite (svPG, 1);
    }
  
    // на 0.5 сек
    if (millis()-last_time > 28000 && millis()-last_time < 28500) {
      // выкл зеленый для пешеходов
      digitalWrite (svPG, 0);
    }
  
    // на 0.5 сек
    if (millis()-last_time > 28500 && millis()-last_time < 29000) {
      // вкл зеленый для пешеходов
      digitalWrite (svPG, 1);}
  
    // на 3 сек
    if (millis()-last_time > 29000 && millis()-last_time < 32000) {
      // выкл зеленый для пешеходов и вкл оранжевый и красный для авто
      digitalWrite (svPG, 0);
      digitalWrite (svPR, 1);
      digitalWrite (svAY, 1);
    }
}