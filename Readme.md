# Semaforos
[![Trafic-Lights-bb.png](https://i.postimg.cc/KjTWpSXV/Trafic-Lights-bb.png)](https://postimg.cc/m1bVhngN)
Simulacion de seamaforos

## Variables

| Variable | [Tipo](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-170) | Descripción |
| -------- | ---- | ----------- |
| State | boolean | Matriz o vector que representa el estado de las luces de trafico |
| Lights | byte | Vector que indica los pines de salida de las luces de trafico |
| Semaphere | byte | Vector que indica los pines para el funcionamiento de cada semaforo |
| Red | byte | Pin de salida para la luz roja |
| Seconds | byte | Vector que indica los segundos para cada fase del semaforo |
| c | byte | Contador de las fases de todos los semaforos |
| f | byte | Contador de bucles **for** |
| i | byte | Contador de bucles **for** |
| g | byte | Contador de las fases de cada semaforo |
| k y u | byte | definen el valor logico de las luces de trafico |

## Fases del semaforo

- Prende la luz verde
- Prende la luz amarilla
- Parpadea la luz amarilla
- Prende la luz roja

## Un semaforo
- En un bucle for, se definen todos los estados (```State```) en ```0```
- Dependiendo de la fase del semaforo, se cambia un estado a ```1``` (```State[c] = true```)
- En un bucle for, se prenden las luces de trafico (```digitalWrite(Lights[i], State[i])```)
- Si ha pasado el tiempo de espera (```millis() - Millis > Seconds[i] * 1000```), se cambia de fase (```c++```)
[![Trafic-Lights-S-esquem-tico.png](https://i.postimg.cc/KzDFqMnB/Trafic-Lights-S-esquem-tico.png)](https://postimg.cc/vgTpDD2Z)

## Multiples semaforos
- En un bucle for, se definen todos los estados (```State```) en ```0``` para todos los semaforos, en ```1``` para todas las luces rojas y en ```0``` para el resto de luces de trafico.
- Se pone en ```0``` el estado de la luz roja del semaforo actual y en ```1``` el semaforo actual.
- Si aun no se ha llegado a la ultima fase del semaforo, se pone en 1 el estado de la luz azul.
- Dependiendo de la fase del semaforo, se cambia un estado a ```1``` para las luces de trafico.
- En un bucle for, se prenden las luces de trafico (```digitalWrite(Lights[i], State[x][i])```)
- Si ha pasado el tiempo de espera (```millis() - Millis > Seconds[i] * 1000```), se cambia de fase (```c++```) y si se ha llegado a la ultima fase, se cambia de semaforo (```k *= 4 ; u *= 4```).
[![Trafic-Lights-esquem-tico.png](https://i.postimg.cc/rwjPPNb8/Trafic-Lights-esquem-tico.png)](https://postimg.cc/WdD8DgTK)




