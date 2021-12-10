# LABERINTO

## Problema 🚀

Crear un generador de laberintos aleatorios de dos dimensiones de tamaño 'n' (n: impar > 3). El punto inicial **A** siempre se encontrará en la esquina superior izquierda. El punto final **B** deberá encontrarse al final de la ruta **más larga** dentro de tu laberinto generado (que no necesariamente será la esquina superior derecha).

Ademas para ir de A a B deberá existir solo un camino posible, no se te permite volver a caminar sobre lo ya recorrido. 

Ejemplo:

n = 11 (* = muro, A = inicio, B = fin)  

```
***********
*A  *    B*
*** * *****
* * * *   *
* * * * * *
*   *   * *
* *** *** *
*   * *   *
*** *** * *
*       * *
***********
```

Implementar la función: **createMaze2D( n )**

No generar cualquier laberinto, recuerda que se pide un laberinto de un solo camino posible entre A y B.
