#include <mbed.h>

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

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

Thread thread2;
Thread thread3;
int main() {
	thread2.start(led2_thread);
	thread3.start(led3_thread);
	while(true) {
		led1 = !led1;
		wait(0.7);
	}
}

