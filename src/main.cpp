#include <mbed.h>
#include <C12832.h>

DigitalOut led1(LED1,1);
DigitalOut led2(LED2,1);
DigitalOut led3(LED3,1);

C12832 lcd(D11, D13, D12, D7, D10);

void led2_thread() {
	while(true) {
		led2 = !led2;
		wait(0.1);
	}
}

void led3_thread() {
	while(true) {
		led3 = !led3;
		wait(0.5);
	}
}

void prt(const char *s, int n){
	lcd.locate(0,0);
	lcd.printf(s,n);
	led1 = !led1;
}

EventQueue q;

Thread thread2;
Thread thread3;
int main() {
	int n;

	lcd.cls();
	lcd.locate(0 , 0);
	q.call_every(1000, prt, "this %d", n);
	lcd.puts("hello");


	//thread2.start(led2_thread);
	thread3.start(led3_thread);
q.dispatch();
///	while(true) {
///		n++;
///		led1 = !led1;
///		wait(0.7);
///	}
}

