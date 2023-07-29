int i = 0;
void main() {
     TRISB = 0x00;//habilitar portas B como saída

     while(1){
     PORTB = (i++) & 7;
     Delay_ms (500);
     }
}