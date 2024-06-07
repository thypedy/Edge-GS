# Projeto Sensor de Praia

Este é um projeto de um sensor que detecta o estado da praia, informando os turistas sobre as condições de temperatura e umidade. O projeto utiliza um Arduino UNO, um sensor de temperatura e umidade DHT22, um display LCD e LEDs para indicar as condições. Além disso, há um potenciômetro que permite ajustar manualmente a temperatura.

## Link da simulação
- [Simulação Wokwi](https://wokwi.com/projects/399611971091731457)

## Funcionalidades

- Monitoramento da temperatura e umidade da praia.
- Indicação visual através de LEDs e sonoro por um buzzer.
- Ajuste manual da temperatura através de um potenciômetro.

## Requisitos

- Arduino UNO ou compatível.
- Sensor de temperatura e umidade DHT22.
- Display LCD com interface I2C.
- LEDs e buzzer.
- Potenciômetro.

## Dependências

- [DHT Library](https://github.com/adafruit/DHT-sensor-library): para comunicação com o sensor DHT22.
- [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C): para controle do display LCD.

## Instruções de Uso

1. Conecte todos os componentes conforme o esquema elétrico.
2. Carregue o código para o Arduino.
3. O display mostrará a temperatura e umidade da praia.
4. Os LEDs indicarão o estado da temperatura:
   - Verde: temperatura normal.
   - Vermelho: temperatura elevada ou baixa.
5. O buzzer emitirá um som se a temperatura estiver fora do intervalo normal.
6. Você pode ajustar manualmente a temperatura usando o potenciômetro.

## Esquema Elétrico

![Esquema Elétrico](esquema_eletrico.png)

## Observações

Certifique-se de instalar as bibliotecas necessárias antes de carregar o código para o Arduino.

Este projeto é uma demonstração simples e pode ser expandido com mais funcionalidades, como envio de dados para um aplicativo móvel ou um sistema de alerta mais sofisticado.
