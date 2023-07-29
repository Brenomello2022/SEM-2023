void main() {
     TRISB = 0x00;//habilitar portas B como saída
     PORTB = 0x00; //Todas as portas B em estado LOW (Nivel Baixo)

     while(1){
     PORTB = 0x01;
     Delay_ms(100);
     PORTB = 0x02;
     Delay_ms(100);
     PORTB = 0x04;
     Delay_ms(100);
     PORTB = 0x08;
     Delay_ms(100);
     PORTB = 0x10;
     Delay_ms(100);
     PORTB = 0x20;
     Delay_ms(100);
     PORTB = 0x40;
     Delay_ms(100);
     PORTB = 0x80;
     Delay_ms(100);
     }
}