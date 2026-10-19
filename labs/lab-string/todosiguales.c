#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    (void)argc;

    if (argv[1] == NULL) {
        printf("0\n");
        return 0;
    }

    char *referencia = argv[1];
    int todos_iguales = 1;

    for (char **arg = argv + 2; *arg != NULL; arg++) {
        if (!AreEqual(*arg, referencia)) {
            todos_iguales = 0;
            break;
        }
    }

    printf("%d\n", todos_iguales);
    return 0;
}
