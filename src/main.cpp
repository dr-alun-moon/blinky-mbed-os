#include <mbed.h>
#include <C12832.h>
#include <LM75B.h>

DigitalOut led1(LED1, 1);
DigitalOut led2(LED2, 1);
DigitalOut led3(LED3, 1);

//AnalogIn pot1 (A0);
//AnalogIn pot2 (A1);


C12832 lcd(D11, D13, D12, D7, D10);

//LM75B sensor(D14,D15);

void led2_thread()
{
	while (true) {
		led2 = !led2;
		wait(1);
	}
}

void led3_thread()
{
	while (true) {
		led3 = !led3;
		wait(0.5);
	}
}

float T;
float val;
void prt(void)
{
	while (true) {
		lcd.locate(0, 0);
		lcd.printf("T %.3f°C", val);
		wait(1);
	}
}

/*
void pots(void) {
	while(true){
		val = (float)sensor.read();
	}
}
*/


void rgb(void)
{
	//DigitalOut r(D5,1);
	DigitalOut g(D9,1);
	DigitalOut b(D8,1);

	PwmOut r(D5);
	float n=0.1;
	while (1) {
		r=0.9;
		wait(0.2);
	}
}


//EventQueue q;

Thread thread2;
//Thread thread3;
//Thread thread4;
//Thread thread5;
Thread thread6;

int main()
{
	int n;
	thread6.start(rgb);
	//thread5.start(pots);
	//thread4.start(prt);
	thread2.start(led2_thread);
	//thread3.start(led3_thread);
	while (true) {
	}
}
