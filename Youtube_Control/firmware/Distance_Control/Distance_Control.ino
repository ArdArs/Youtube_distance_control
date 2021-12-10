//Библиотеки
#include <Keyboard.h>
#include <IRremote.h>
#include "IK_codes.h"

#define PIN_IK 2 //Пин приёмника ИК сигнала

//Объекты
IRrecv irrecv(PIN_IK);
decode_results ir;
 
void setup() {
  irrecv.enableIRIn(); //Инийиализаци ик-приёимника
  Keyboard.begin(); //Инициализация объекта-клавиатуры
}

void loop() {
  static uint32_t actual_code;
  if (irrecv.decode(&ir)) { // Если что-то приняли:
    if (ir.value != BUTT_REPEAT) { //И это не код удержания кнопки
      actual_code = ir.value; //Запоминаем его.
    }
    switch (actual_code) { //Нажимаем сочитания клавищ взависимости от нажатой кнопки на пульте.
      case BUTT_UP: //Кнопка вверх
        Keyboard.press(KEY_UP_ARROW);
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_DOWN: //Кнопка вниз
        Keyboard.press(KEY_DOWN_ARROW);
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_RIGHT: //Кнопка вправо
        Keyboard.write(KEY_RIGHT_ARROW);
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_LEFT: //Кнопка влево
        Keyboard.write(KEY_LEFT_ARROW);
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_OK: //Кнопка ok
        Keyboard.write('k');
        Keyboard.releaseAll();
        break;
      case BUTT_HASH: //Кнопка на весь экран\свернуть
        Keyboard.write('f');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_STAR: //Кнопка Выключить звук
        Keyboard.write('m');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_0: //Переход по частям видео
        Keyboard.write('0');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_1:
        Keyboard.write('1');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_2:
        Keyboard.write('2');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_3:
        Keyboard.write('3');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_4:
        Keyboard.write('4');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_5:
        Keyboard.write('5');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_6:
        Keyboard.write('6');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_7:
        Keyboard.write('7');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_8:
        Keyboard.write('8');
        delay(10);
        Keyboard.releaseAll();
        break;
      case BUTT_9:
        Keyboard.write('9');
        delay(10);
        Keyboard.releaseAll();
        break;
    }
    irrecv.resume();
  }
}
