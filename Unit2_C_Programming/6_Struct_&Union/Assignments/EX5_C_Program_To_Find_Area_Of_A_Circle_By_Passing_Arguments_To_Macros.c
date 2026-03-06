/*
 ============================================================================
 Name        : EX5_C_Program_To_Find_Area_Of_A_Circle_By_Passing_Arguments_To_Macros.c
 Author      : Adel Shata
 Version     :
 Copyright   : Your copyright notice
 Description : EX5 C Program To Find Area Of A Circle By Passing Arguments To Macros, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Define Constants and Macros */
#define PI 3.14159
#define AREA(r) (PI * (r) * (r)) // Macro to calculate area: π * r^2

int main(void) {
    float radius, result;

    /* Get input from user */
    printf("Enter the radius: ");
    fflush(stdout);
    if (scanf("%f", &radius) != 1) {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    /* Calculate area using the macro */
    result = AREA(radius);

    /* Print result formatted to 2 decimal places */
    printf("Area=%.2f\n", result);

    return 0;
}
