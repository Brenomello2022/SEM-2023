void main() {
     TRISB.f0 = 0;
     TRISB.f1 = 1;
     PORTB.f0 = 0;
     while (1) {
           unsigned char buttonState = PORTB.f1;
           if (buttonState == 1) {
               PORTB.f0 = 1;
           } else {
               PORTB.f0 = 0;
           }
     }
}