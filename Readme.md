# Semaforos
[![Trafic-Lights-bb.png](https://i.postimg.cc/KjTWpSXV/Trafic-Lights-bb.png)](https://postimg.cc/m1bVhngN)
Simulacion de seamaforos

## Hardware y software necesarios
- Placa de desarrollo Arduino 
- 4 LEDs:
  - Verdes
  - Amarillos
  - Azules
  - Rojos x 2
- 8 Resistencias $\displaystyle 200\Omega$ a 1 $\displaystyle K\Omega$
- [Arduino IDE](https://www.arduino.cc/en/software) o [Arduino CLI](https://arduino.github.io/arduino-cli/0.23/installation/)

## Funcionamiento
### Variables

- ```State```: Matriz o vector que representa el estado de las luces de trafico.
- ```Lights```: Vector que indica los pines de salida de las luces de trafico.
- ```Semaphere```: Vector que indica los pines para el funcionamiento de cada semaforo.
- ```Red```: Pin de salida para la luz roja.
- ```Seconds```: Vector que indica los segundos para cada fase del semaforo.
- ```c```: Contador de las fases de todos los semaforos.
- ```f``` e ```i```: Contador de bucles **for**.
- ```g```: Contador de las fases de cada semaforo.
- ```k``` y ```u```: Definen el valor logico de las luces de trafico.

### Funcionamiento
#### Fases del semaforo

- Prende la luz verde
- Prende la luz amarilla
- Parpadea la luz amarilla
- Prende la luz roja

#### Un semaforo
- En un bucle for, se definen todos los estados (```State```) en ```0```
- Dependiendo de la fase del semaforo, se cambia un estado a ```1``` (```State[c] = true```)
- En un bucle for, se prenden las luces de trafico (```digitalWrite(Lights[i], State[i])```)
- Si ha pasado el tiempo de espera (```millis() - Millis > Seconds[i] * 1000```), se cambia de fase (```c++```)
[![Trafic-Lights-S-esquem-tico.png](https://i.postimg.cc/KzDFqMnB/Trafic-Lights-S-esquem-tico.png)](https://postimg.cc/vgTpDD2Z)

#### Multiples semaforos
- En un bucle for, se definen todos los estados (```State```) en ```0``` para todos los semaforos, en ```1``` para todas las luces rojas y en ```0``` para el resto de luces de trafico.
- Se pone en ```0``` el estado de la luz roja del semaforo actual y en ```1``` el semaforo actual.
- Si aun no se ha llegado a la ultima fase del semaforo, se pone en 1 el estado de la luz azul.
- Dependiendo de la fase del semaforo, se cambia un estado a ```1``` para las luces de trafico.
- En un bucle for, se prenden las luces de trafico (```digitalWrite(Lights[i], State[x][i])```)
- Si ha pasado el tiempo de espera (```millis() - Millis > Seconds[i] * 1000```), se cambia de fase (```c++```) y si se ha llegado a la ultima fase, se cambia de semaforo (```k *= 4 ; u *= 4```).
[![Trafic-Lights-esquem-tico.png](https://i.postimg.cc/rwjPPNb8/Trafic-Lights-esquem-tico.png)](https://postimg.cc/WdD8DgTK)




