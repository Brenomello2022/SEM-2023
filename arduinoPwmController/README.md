Nesse projeto, foi elaborado um circuito em um programa de simulação, um modulador por largura de pulso.

PWM, em inglês "Pulse Width Modulation", ou em portugues MLP, que significa Modulação por Largura de Pulso, é uma tecnica que controla a quantidade média de energia, que for aplicada a um dispositivo eletronico.

------------------------------------------------------

<h1>Componentes do Esquemático.<h1>

<p>Arduino Nano.<p>
<p>Resistor.<p>
<p>Motor.<p>
<p>Cell.<p>
<p>L293D.<p>
<p>Button.<p>
<p>2 Grounds.<p>
<p>Oscilloscope.<p>
<p>DC Voltometer.<p>

------------------------------------------------------



------------------------------------------------------

<h1>Schematic Capture.<h1>

<p>Esquemático do circuito de modulação de largura de pulsos, feito no proteus.<p>

<div align=center>

<img height="200em" src="./img/pwm.png">

</div>

------------------------------------------------------



------------------------------------------------------

<h1>Schematic Capture PDF.<h1>

<div align=center>

<img height="200em" src="./schematics/pwm-controller-schematic.png">

</div>

------------------------------------------------------



------------------------------------------------------

<h1>Código Fonte.<h1>

```javascript
void setup() {
  pinMode(PWM, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

  int leitura = digitalRead(BUTTON_PIN);

  if (leitura != ultimo_estado_botao) {
    ultimo_estado_botao = leitura;
    if (leitura == HIGH) {  
      tempo_acionado = millis();
    }
  }

  if (leitura == HIGH && ((millis() - tempo_acionado) > tempo_delay)) {
    pwm = pwm + 64;

    if(pwm > 256 ) {
        pwm = 0;
    }
  }

  analogWrite(PWM, pwm);
}
```
------------------------------------------------------



------------------------------------------------------

<p>Para este projeto foi utiilizado o programa Proteus 8 Professional, bastante utilizado para montar circuitos, onde temos a visão do Esquemático, do Pcb Layout e a Visão 3D.<p>

------------------------------------------------------



------------------------------------------------------

<h1>Proteus 8 Professional.<h1>

<div align=center>

<img height="200em" src="./img/proteus.png">

</div>

------------------------------------------------------



------------------------------------------------------

<h1>Instruções de Montagem do Circuito.<h1>

<p>Primeiro precisa conectar a porta 2 do Arduino Nano em uma das entradas do Botão, e a outra entrada conectar à célula de energia, também conectar as portas 9 e 10 do Arduino Nano, às portas 7 e 2 do L293D<p>

<p>Segundo, logo abaixo do botão, conectar as entradas do resistor com a ligação do botão, e aterrar a outra entrada<p>

<p>Terceiro, conectar uma entrada do Motor, e aterrar a outra entrada<p>

<p>Quarto, conectar as portas 1, 8, 9, e 16 do L293D nas ligações do Botão e Cell, aterrar o gnd do L293D<p>

<p>Quinto, conectar uma das entradas do DC Voltometer a porta 3 do L293D, e a outra na ligação do Ground do Resistor, e ligar as duas entradas do Motor às duas ligações do DC Voltometer<p>

<p>Sexto, conectar a porta A do Oscilloscope à ligação do DC Voltometer<p>

------------------------------------------------------



------------------------------------------------------

<h1>Funcionamento de um PWM.<h1>

<p>O PWM funciona modulando o ciclo ativo (duty cicle) de uma onda quadrada. O conceito de funcionamento é simples. O controlador (fonte de tensão com PWM) entrega uma série de pulsos, gerados em intervalos de igual duração, que pode ser variada. Quanto mais largo o pulso, maior a quantidade de corrente fornecida à carga.<p>

------------------------------------------------------



------------------------------------------------------

<h1>Funcionamento do Projeto.<h1>

<p>No momento em que for pressionado o botão, a velocidade do motor chega em 64. Se clicado mais uma vez, aumentará a velocidade para 127. Se for clicado mais duas vezes, sua velocidade chegará à 191 e 255, respectivamente, assim mantendo sua velocidade constante, ate que o botão seja novamente pressionado, reiniciando sua velocidade.<p>

------------------------------------------------------



------------------------------------------------------

Thank you so much for reading, have a nice day! :D

------------------------------------------------------