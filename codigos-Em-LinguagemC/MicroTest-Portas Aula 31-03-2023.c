void main() {
     TRISB = 0b00000000; //habilitar portas B como saída
     PORTB = 0b00000000; //Todas as portas B em estado LOW (Nivel Baixo)
     
     while(1){
     PORTB = 0b00000001;
     Delay_ms(100);
     PORTB = 0b00000010;
     Delay_ms(100);
     PORTB = 0b00000100;
     Delay_ms(100);
     PORTB = 0b00001000;
     Delay_ms(100);
     PORTB = 0b00010000;
     Delay_ms(100);
     PORTB = 0b00100000;
     Delay_ms(100);
     PORTB = 0b01000000;
     Delay_ms(100);
     PORTB = 0b10000000;
     Delay_ms(100);
     }
}