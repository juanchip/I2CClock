/*****************************/
/*    KUBIK Software         */ 
/*                           */
/* Programado por Juan Blanc */
/*                           */
/*       Mayo 2016           */
/*****************************/

#include <Wire.h> 
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>   

/* Creacion de objetos */

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//Direccion de LCD

RTC_DS1307 RTC;

  
void setup () {
  Wire.begin(); // Inicia el puerto I2C
    RTC.begin(); // Inicia la comunicación con el RTC
  lcd.begin(20,4); // Inicia el display lcd
  //RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
 
}
void loop(){
  
  int valorSensor = analogRead(A0);
  DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
  lcd.setCursor(0,0);
  lcd.print(now.year(), DEC); // Año
  lcd.print('/');
  lcd.print(now.month(), DEC); // Mes
  lcd.print('/');
  lcd.print(now.day(), DEC); // Dia
  lcd.print(' ');
  lcd.setCursor(0,1);
  lcd.print(now.hour(), DEC); // Horas
  lcd.print(':');
  lcd.print(now.minute(), DEC); // Minutos
  lcd.print(':');
  lcd.print(now.second(), DEC); // Segundos
  lcd.setCursor(0,3);
  lcd.print("Tension de pila RTC:");
  float volt = valorSensor * (5.0 / 1023.0);
  lcd.print(volt);
  lcd.print("  [V]");
  delay(10); // La información se actualiza cada 10 milisegundos


}
