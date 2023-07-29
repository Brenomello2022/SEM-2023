// Código feito em sala.

#include <Arduino.h>
#include <arduino_FreeRTOS.h>

#define LED_PIN_1 11
#define LED_PIN_2 12

//Protótipos de Tarefas.

void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);

void setup () {

//Inicializar os pinos dos LEDs como saídas.

pinMode(LED_PIN_1, OUTPUT);
pinMode(LED_PIN_2, OUTPUT);

//Cria as tarefas

xTaskCreate(
  TaskBlink1, //Função da Tarefa - Ponteiro.
  "Blink1",
  128, //Tamanho de pilha.
  NULL, //Parâmetro da Tarefa.
  2, //Prioridade - números mais altos - proporcional ao Número.
  NULL ); //Agendar tarefa.

xTaskCreate(
  TaskBlink2, //Função da Tarefa - Ponteiro.
  "Blink2",
  128, //Tamanho de pilha.
  NULL, //Parâmetro da Tarefa.
  1, //Prioridade - números mais altos - proporcional ao Número.
  NULL ); //Agendar tarefa.

}

void loop () {

//Nada Aqui

}

void TaskBlink1(void *pvParameters) {
  (void) pvParameters;
  for (;;) { //Loop Infinito
    digitalWrite(LED_PIN_1, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Função millis RTOS
    digitalWrite(LED_PIN_1, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }

}
void TaskBlink2(void *pvParameters) {
  (void) pvParameters;
  for (;;) { //Loop Infinito
    digitalWrite(LED_PIN_2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS); // Função millis RTOS
    digitalWrite(LED_PIN_2, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }

}

// Código do Desafio.

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>

#define LED_1 6 // Led Vermelho
#define LED_2 5 // Led Verde

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// //Protótipos de Tarefas.

void TaskReadTemp(void *pvParameters);
void TaskLed1(void *pvParameters);
void TaskLedTemp(void *pvParameters);

// Variável para o valor da temperatura.

volatile float temp = 0.0;

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);

    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);

    // Cria as Tarefas.

    xTaskCreate(
      TaskReadTemp, //Função da Tarefa - Ponteiro.
      "ReadTemp",
      128, //Tamanho de pilha.
      NULL, //Parâmetro da Tarefa.
      3, //Prioridade - números mais altos - proporcional ao Número.
      NULL); //Agendar tarefa.
 
    xTaskCreate(
      TaskLed1, //Função da Tarefa - Ponteiro.
      "Led1",
      128, //Tamanho de pilha.
      NULL, //Parâmetro da Tarefa.
      3, //Prioridade - números mais altos - proporcional ao Número.
      NULL); //Agendar tarefa.

    xTaskCreate(
      TaskLedTemp, //Função da Tarefa - Ponteiro.
      "LedTemp",
      128, //Tamanho de pilha.
      NULL, //Parâmetro da Tarefa.
      3, //Prioridade - números mais altos - proporcional ao Número.
      NULL); //Agendar tarefa.
}

void loop()
{
    // Nada aqui
}

void TaskReadTemp(void *pvParameters)
{

    (void)pvParameters;
    float sensorValue = 0.0;
    for (;;)
    {
        
        sensorValue = -10.0 + (rand() % 51); // Gera um número aleatório entre -10 e 40.
        temp = sensorValue;
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Aguarda por 2 segundos.
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temp);
        lcd.print(" C");
    }
}

void TaskLed1(void *pvParameters)
{

    (void)pvParameters;
    for (;;)
    {
        digitalWrite(LED_1, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        digitalWrite(LED_1, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void TaskLedTemp(void *pvParameters)
{
    (void)pvParameters;
    for (;;)
    {
        if (temp == 26.00)
        {
            vTaskDelay(2000 / portTICK_PERIOD_MS);
            digitalWrite(LED_2, HIGH);
        }
    }
}

