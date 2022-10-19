#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define lpg_sensor 7
#define buzzer 13

void setup()
{
	pinMode(lpg_sensor, INPUT);
	pinMode(buzzer, OUTPUT);
	lcd.begin(16, 2);
	lcd.print(‘LPG Gas Detector’);
	delay(2000);
}

void loop()
{
	if (digitalRead (lpg_sensor)) {
		digitalWrite(buzzer, LOW);
		lcd.clear();
		lcd.print(‘NO LPG GAS’);
		lcd.setCursor(0, 1);
		lcd.print(‘LEAKAGE’);
		delay(400);
		digitalWrite(buzzer, LOW);
		delay(500);
	} else {
		digitalWrite(buzzer, HIGH);
		lcd.clear();
		lcd.print(‘LPG Gas Leakage’);
		lcd.setCursor(0,1);
		lcd.print(‘Alert’);
		delay(1000);
	}
}
