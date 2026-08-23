#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */
void test_compra_con_descuento() {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Leche", 350, 2};  
    Producto p2 = {"Pan", 150, 3};    
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    ASSERT_IGUAL(1150, carrito_total(&c));  
    ASSERT_IGUAL(1035, carrito_descuento(carrito_total(&c), 10));
}



/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */
void test_agregar_hasta_llenar() {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};

    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));  
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));  
}


int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();  
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
