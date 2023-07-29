void main() {
     // Configura o pino RB0 (LED) como saida
     TRISB.F0 = 0;
     // Configura o pino RB1 (Botão) como entrada
     TRISB.F1 = 1;
     // Inicializa o LED desligado (LOW)
     PORTB.F0 = 0;
     while (1) {
           // Lê o estado do botão e armazena na variável 'buttonState'
           unsigned char buttonState = PORTB.F1;
           
           // Verifica se o botão está precionado
           // (assumindo que o botão é ativo em nível baixo)
           if (buttonState == 0) {
               // Liga o LED (HIGH)
               PORTB.F0 = 1;
           } else {
               // Desliga o LED (LOW)
               PORTB.F0 = 0;
           }
     }
}