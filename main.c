#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>

#define LED 5
#define BUTTON 6

volatile int running = 1;

void handle_signal(int signal) {
    running = 0;
}

int main(void) {
    if(wiringPiSetup() == -1) {
        printf("wiringpi setup failed\n");
        return 1;
    }

    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    digitalWrite(LED, HIGH);

    while (running){
        if(digitalRead(BUTTON) == 0) {
            digitalWrite(LED, LOW);
        } else {
            digitalWrite(LED, HIGH);
        }
    }

    return 0;
}