
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

char digCode(int val){
    switch(val){
        case 0:
            return 0xFE;
            break;
        case 1:
            return 0xC0;
            break;
    }

}

void setDisplay(char code){
    for(int i = 0; i < 9; i++ ){
        if( ( (code >> i) & 0x01 ) == 1)
            PORTB |= (1 << PB0);
        }else{
            PORTB &= ~(1 << PB0); 
        _delay_us(1);
        PORTB |= (1 << PB1);
        _delay_us(1);
        PORTB &= ~(1 << PB0);
        _delay_us(1);
        PORTB &= ~(1 << PB1);
        _delay_us(1);
    }
}


int main(){
    DDRB = 0x03;

    while(1){

    }

}