# Práctica 4: Calculadora básica

> **Las secciones 1 a 6 ya están resueltas por el profesor.** Léelas con atención, pero no las modifiques. Tu trabajo empieza en la sección 7.

## 1. Descripción del problema (Fase 1, resuelta)

El programa muestra un menú con cuatro operaciones (suma, resta, multiplicación y división). El usuario elige una, escribe dos números y el programa muestra el resultado de la operación. Es la base de cualquier calculadora y del tipo de menú que se usa, por ejemplo, en el panel de control de una máquina.

## 2. Entradas y salidas (Fase 1, resuelta)

**Entradas:**
1. `opcion` (`int`): la operación elegida, de 1 a 4. Se lee con `leerEntero`.
2. `a` (`double`): el primer número. Se lee con `leerDecimal`.
3. `b` (`double`): el segundo número. Se lee con `leerDecimal`.

**Salidas:**
1. `resultado` (`double`): el resultado de la operación.
2. Se muestra en la forma `a símbolo b = resultado`, por ejemplo `7 / 2 = 3.5`. El símbolo se guarda en `simbolo` (`char`).

**Operaciones:** 1) `a + b`   2) `a - b`   3) `a * b`   4) `a / b`

## 3. Restricciones e invariante (Fases 1 y 2, resuelta)

**Restricciones:**
- La opción debe estar entre 1 y 4. Si no, el programa la vuelve a pedir.
- Si la operación es división, `b` no puede ser 0. Si lo es, el programa vuelve a pedir solo `b`.
- En la resta y en la división el orden importa: siempre se calcula `a` op `b`.

**¿Quién detecta cada error?**
- `leerEntero` y `leerDecimal` detectan el **formato**: texto (`abc`) o, en el caso de `leerEntero`, decimales (`2.5`).
- El programa detecta el **rango**: una opción fuera de 1 a 4 y un divisor igual a 0.

**Invariante:** al llegar al Paso 7 (el cálculo), `opcion` está entre 1 y 4 y, si la opción es 4 (división), `b` es distinto de 0. Por eso el cálculo siempre es válido.

## 4. Casos resueltos a mano (Fase 1, resuelta)

| Caso | Opción | a | b | Resultado |
|---|---|---|---|---|
| 1 | 1 (suma) | 8 | 5 | 8 + 5 = 13 |
| 2 | 2 (resta) | 3 | 5 | 3 - 5 = -2 |
| 3 | 3 (multiplicación) | 2.5 | 4 | 2.5 * 4 = 10 |
| 4 | 4 (división) | 7 | 2 | 7 / 2 = 3.5 |
| 5 | 4 (división) | 5 | 0, luego 2 | vuelve a pedir `b`; 5 / 2 = 2.5 |

## 5. Receta en pseudocódigo (Fase 2, resuelta)

La receta completa está en el archivo `RECETA.md`. No la modifiques: si encuentras algo que no contempla, anótalo en la sección 11.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o calculadora
./calculadora
```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con una división donde primero escribes 0 como segundo número. -->

```
Calculadora basica
1) Suma
2) Resta
3) Multiplicacion
4) Division
Elige una opcion (1-4): 4
Primer numero: 5
Segundo numero: 0
No se puede dividir entre cero
Segundo numero (distinto de 0): 2
5 / 2 = 2.5
```

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de la receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. -->

| Paso de la receta | Instrucción de C++ que lo implementa |
|---|---|
| 1 y 2. Título y menú | std::cout << "Calculadora basica\n"; y los std::cout que muestran las cuatro opciones. |
| 3. Leer y validar la opción | do { opcion = leerEntero("Elige una opcion (1-4): "); ... } while (opcion < 1 |
| 4 y 5. Leer `a` y `b` | a = leerDecimal("Primer numero: "); y b = leerDecimal("Segundo numero: "); |
| 6. Validar el divisor | if (opcion == 4) { while (b == 0) { ... } } |
| 7. Decisión múltiple (un `case`) | switch (opcion) { case 1: resultado = a + b; simbolo = '+'; break; ... } |
| 8. Mostrar el resultado | std::cout << a << " " << simbolo << " " << b << " = " << resultado << "\n"; |

**¿Hubo algún paso de la receta que te costó traducir a C++? ¿Cuál y por qué?**
El Paso 7 fue el que más me costó porque tuve que entender cómo funciona switch, case y break para realizar una operación diferente dependiendo de la opción.

## 9. Experimentos (Fase 3)

**Experimento A: sin el `break` del `case 1`, ¿qué mostró el programa con 8 + 5? ¿Qué te dijo el compilador? ¿Por qué pasó?**
El programa siguió ejecutando el siguiente case porque al quitar break ocurre un fall-through. El compilador mostró una advertencia relacionada con la posibilidad de continuar al siguiente case. Esto pasó porque break es el que detiene la ejecución del switch.

**Experimento B: sin la validación del Paso 6, ¿qué mostró el programa con 5 / 0? ¿Tiene sentido?**
El programa mostró un valor especial que representa infinito. No es un resultado útil para una calculadora, por eso es necesario validar que el divisor no sea 0 antes de realizar la división.

**Experimento C (opcional): con `a` y `b` de tipo `int`, ¿qué resultado dio 7 / 2? ¿Te avisó el compilador?**
El resultado fue 3 porque entre dos variables int la división es entera y se descarta la parte decimal. El compilador no necesariamente avisa de este problema.

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas (opción, a, b) | Esperado | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| Suma | 1, 8, 5 | 8 + 5 = 13 | 8 + 5 = 13 | Sí |
| Resta negativa | 2, 3, 5 | 3 - 5 = -2 | 3 - 5 = -2 | Sí |
| Multiplicación con decimales | 3, 2.5, 4 | 2.5 * 4 = 10 | 2.5 * 4 = 10 | Sí |
| Multiplicación con negativo | 3, -3, 4 | -3 * 4 = -12 | -3 * 4 = -12 | Sí |
| División | 4, 7, 2 | 7 / 2 = 3.5 | 7 / 2 = 3.5 | Sí |
| Dividendo cero | 4, 0, 5 | 0 / 5 = 0 | 0 / 5 = 0 | Sí |
| Divisor cero | 4, 5, 0 (luego 2) | vuelve a pedir `b`; 5 / 2 = 2.5 | vuelve a pedir b; 5 / 2 = 2.5 | Sí |
| Suma con cero | 1, 5, 0 | 5 + 0 = 5 (**no** vuelve a pedir `b`) | 5 + 0 = 5 | Sí |
| Opción fuera de rango | 5 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | vuelve a pedir la opción; 8 + 5 = 13 | Sí |
| Opción cero | 0 (luego 1), 8, 5 | vuelve a pedir la opción; 8 + 5 = 13 | vuelve a pedir la opción; 8 + 5 = 13 | Sí |
| Opción decimal | 2.5 (luego 2), 3, 5 | `leerEntero` vuelve a pedir; 3 - 5 = -2 |  | SíleerEntero vuelve a pedir; 3 - 5 = -2 |
| Opción con texto | `suma` (luego 1), 8, 5 | `leerEntero` vuelve a pedir; 8 + 5 = 13 | leerEntero vuelve a pedir; 8 + 5 = 13 | Sí |
| Número con texto | 1, `abc` (luego 8), 5 | `leerDecimal` vuelve a pedir; 8 + 5 = 13 | leerDecimal vuelve a pedir; 8 + 5 = 13 | Sí |
| Caso propio 1 | 3, 0, -5 | 0 * -5 = 0 | 0 * -5 = 0 | Sí |
| Caso propio 2 | 2, -10, -5 | -10 - -5 = -5 | -10 - -5 = -5 | Sí |

## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | Al principio podía ocurrir una división entre cero. | Agregué la validación del divisor del Paso 6. | Sí |
| 2 | La opción podía estar fuera del rango permitido. | Agregué el ciclo para volver a pedir la opción cuando no está entre 1 y 4 | Sí |

**¿Encontré algo que la receta no contemplaba? ¿Qué?**
No encontré un problema importante que la receta no contemplara. La receta incluye las validaciones necesarias para la opción y para el divisor.

**Reto elegido (opcional):** _____

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Por qué al dividir dos variables int se pierde la parte decimal? | Probé el Experimento C y observé que 7 / 2 da 3 en lugar de 3.5. |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a utilizar switch, case y break para realizar diferentes operaciones dependiendo de una opción. También aprendí a validar datos y a utilizar double para trabajar con números decimales.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Intentaría probar cada parte del programa conforme la voy programando para encontrar los errores más rápido.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue entender cómo funcionaba switch y por qué era necesario utilizar break. Lo resolví revisando la receta y haciendo el Experimento A.

**¿Qué pregunta me quedó sin responder?**
Me quedó la duda de por qué los números double pueden producir valores especiales como infinito cuando se divide entre cero.

**¿Fue más fácil programar a partir de una receta ajena que de la mía? ¿Por qué?**
Sí, porque la receta ya tenía los pasos definidos y solo tuve que traducir cada uno a instrucciones de C++.

**Si yo hubiera diseñado la receta, ¿qué le cambiaría?**
Agregaría algún ejemplo de código pequeño junto a cada paso para entender más rápido cómo traducirlo a C++.

## 14. Lista de verificación antes de entregar (Fase 5)

- [x ] Llené las secciones 7 a 13 (no quedan `_____`)
- [x ] No modifiqué las secciones 1 a 6 ni la receta de `RECETA.md`
- [x ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`
- [ x] Mi programa compila sin advertencias
- [ x] Probé todos los casos de la tabla
- [x ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [x ] No modifiqué `utilerias.h`
- [x ] Hice al menos 4 commits con mensajes claros
- [x ] Hice `git push` y verifiqué mi fork en GitHub
- [x ] Entregué el enlace de mi fork en Classroom