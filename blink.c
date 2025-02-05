#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos dos LEDs
#define LED_RED 11      // LED vermelho no pino 11
#define LED_YELLOW 12   // LED amarelo no pino 12
#define LED_GREEN 13    // LED verde no pino 13

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} LuzSemaforo;

// Variável global para armazenar o estado atual do semáforo
LuzSemaforo current_state = RED;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Muda o estado do semáforo
    switch (current_state) {
        case RED:
            current_state = YELLOW;
            gpio_put(LED_YELLOW, 1); // Liga o LED amarelo
            break;
        case YELLOW:
            current_state = GREEN;
            gpio_put(LED_GREEN, 1);  // Liga o LED verde
            break;
        case GREEN:
            current_state = RED;
            gpio_put(LED_RED, 1);    // Liga o LED vermelho
            break;
    }

    return true; // Continua o temporizador
}

int main() {
    // Inicializa a comunicação serial (para debug)
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o semáforo com o LED vermelho ligado
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Configura o temporizador periódico (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Imprime uma mensagem a cada segundo
        printf("Semáforo em funcionamento...\n");
        sleep_ms(1000);
    }

    return 0;
}