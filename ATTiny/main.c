#include <avr/io.h>
#include <util/delay.h>

// DDRB = DDRB | (1 << PBx); // Set PBx to output
// DDRB = DDRB & ~(1 << PBx); // Set PBx to input
// PORTB = PORTB | (1 << PBx); // Set PBx to HIGH
// PORTB = PORTB & ~(1 << PBx); // Set PBx to LOW
// if(PINB & (1 << PBx)); // Test PBx high

const char MSG[14] = "bonjour madame";

const int PIN_LED = PB4;
const int ASK = PB3;
const int CLK = PB2;
const int DAT = PB1;
const int ms = 100;
const unsigned char test = 55;

unsigned int indice = 0;

int question(){
    if(!(PINB & (1 << ASK))){//test si bas
        DDRB |= (1 << ASK);//mode out
        PORTB &= ~(1 << ASK);//maintenir a bas
        _delay_ms(10);
        DDRB &= ~(1 << ASK);//mode in
        return 1;
    }
    return 0;
}

void answer(){
    int cmpt = 0;
    int prec = (PINB & (1 << CLK));
    while(cmpt < 8){
        int actual = (PINB & (1 << CLK));
        if(prec < actual){//test si haut
            PORTB |= (1 << PIN_LED);//led on

            if(MSG[indice] & (1 << cmpt)){
                PORTB |= (1 << DAT);
            }else{
                PORTB &= ~(1 << DAT);
            }

            _delay_ms(10);
            PORTB &= ~(1 << PIN_LED);//led off
            cmpt++;
        }
        prec = actual;
    }
    if(indice == sizeof(MSG)){
        indice = 0;
    }else{
        indice++;
    }
}

int main() {
  DDRB |= (1 << PIN_LED);//mode out
  DDRB &= ~(1 << ASK);//mode in
  DDRB &= ~(1 << CLK);//mode in
  DDRB |= (1 << DAT);// MISO mode out
  while(1){
    if(question()){
        answer();
    }
    _delay_ms(1);
  }
  return 0;
}