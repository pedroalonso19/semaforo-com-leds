# Semáforo com Leds
Residência em Sistemas Embarcados - Embarcatech 
Atividade Individual



## Objetivo da atividade:
Com o emprego da função add_repeating_timer_ms(), presente
na ferramenta Pico SDK, projete um semáforo com
temporização de 3 segundos para cada alteração de sinal. 

## Nesta prática, foram simulados os seguintes componentes:
03 Resistores de 330 Ω.
03 LEDs (vermelho, amarelo e verde).
Microcontrolador Raspberry Pi Pico W.

## Requisitos:

1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na
cor vermelha, alterando para amarela e, em seguida, verde.

2) O temporizador deve ser ajustado para um atraso de 3 segundos
(3.000ms).

3) A mudança de estado dos LEDs deve ser implementada na função
de call-back do temporizador, a exemplo da rotina trabalhada na
aula síncrona - repeating_timer_callback().

4) A rotina principal, presente no interior da estrutura de
repetição while, deve imprimir algum tipo de informação a cada
segundo (1.000 ms).

5) Com o emprego da Ferramenta Educacional BitDogLab, faça
um experimento com o código deste exercício utilizando o LED
RGB – GPIOs 11, 12 e 13.

## Tecnologias Utilizadas:

Visual Studio Code;
Git e GitHub;
Linguagem C;
Wokwi.

### Simulação Web: https://wokwi.com/projects/422009246276943873
