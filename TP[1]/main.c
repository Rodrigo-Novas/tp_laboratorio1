#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Calculadora.h"


int main()
{
 float a, b, resultado;
 int calculadora = 0;
 char numero1 = 't', numero2 = 't';



 do
 {
  printf("\n\n------*-------- MENU ------*-------- \n\n");
  if (numero1 == 't' && numero2 == 't') {
   printf("Primer operando A: \n");
   printf("Segundo operando B: \n\n");
   printf("1- Primer operando(A)\n");
   printf("2- Segundo operando(B)\n");
   printf("3- Suma (A+B)\n");
   printf("4- Resta (A-B)\n");
   printf("5- Division (A/B)\n");
   printf("6- Multiplicacion (AxB)\n");
   printf("7- Factorial (A!)\n");


  }
  else {
   if (numero1 == 'n' && numero2 == 't') {
    printf("Primer operando A: %.2f\n", a);
    printf("Segundo operando B: \n\n");
    printf("1- Primer operando (%.2f)\n", a);
    printf("2- Segundo operando\n");
    printf("3- Suma (%.2f + B)\n", a);
    printf("4- Resta (%.2f - B)\n", a);
    printf("5- Division (%.2f / B)\n", a);
    printf("6- Multiplicacion (%.2f x B)\n", a);
    printf("7- Factorial (%.2f!)\n", a);
    printf("8- Factorial (B)\n");
   }
   else {
    if (numero1 == 't' && numero2 == 'n') {
     printf("Primer operando A: A\n");
     printf("Segundo operando B: %.2f\n\n", b);
     printf("1- Primero operando(A)\n");
     printf("2- Segundo operando(B) (%.2f)\n", b);
     printf("3- Suma (A + %.2f)\n", b);
     printf("4- Resta (A - %.2f)\n", b);
     printf("5- Division (A / %.2f)\n", b);
     printf("6- Multiplicacion (A x %.2f)\n", b);
     printf("7- Factorial (A)\n");
     printf("8- Factorial (B)\n", b);
    }
    else {
     if (numero1 == 'n' && numero2 == 'n') {
      printf("Primer operando A: %.2f\n",a);
      printf("Segundo operando B: %.2f\n\n", b);
      printf("1- Primer operando(A) (%.2f)\n", a);
      printf("2- Segundo operando(B) (%.2f)\n", b);
      printf("3- Suma (%.2f + %.2f)\n", a, b);
      printf("4- Resta (%.2f - %.2f)\n", a, b);
      printf("5- Division (%.2f / %.2f)\n", a, b);
      printf("6- Multiplicacion (%.2f x %.2f)\n", a, b);
      printf("7- Factorial de A (%.2f)\n", a);
      printf("8- El factorial de B (%.2f)\n", b);
     }
    }
   }
  }
  printf("9- Calcular todas las operaciones\n");
  printf("10- Salir\n\n");
  printf("\n\n-----------fin calculadora-----------\n\n");
  printf("OPCION: ");
  scanf("%d", &calculadora);



  switch (calculadora)
  {
   case 1: /* INGRESO DE NUMERO*/

        system("cls");
        a=usuarioNumero();
        system("cls");
        numero1 = 'n';

        if(a==0){


            printf("El numero ingresado no puede ser cero\n\n");

        }

        break;

       case 2: /* INGRESO DE NUMERO */
        system("cls");
        b=usuarioNumero();
        system("cls");
        numero2 = 'n';

        if (b==0) {

            printf("El numero ingresado no puede ser cero\n\n");

        }
        break;

   case 3:	/* SUMA */
        if (numero1 == 'n' && numero2 == 'n') {
         system("cls");
         resultado = sumaParametros(a,b);
         printf("--------> suma: %.2f", resultado);
        }
        else {
         system("cls");
         printf("primero ingrese operandos");
        }
        break;

   case 4:	/* RESTA*/
        if (numero1 == 'n' && numero2 == 'n') {
         system("cls");
         resultado = restaParametros(a,b);
         printf("--------> resta: %.2f", resultado);
        }
        else {
         system("cls");
         printf("primero ingrese operandos");
        }
        break;

   case 5:	/* DIVISION */
        if (numero1 == 'n' && numero2 == 'n') {
            if(b!=0){
                system("cls");
                resultado = dividirParametros(a,b);
                 printf("--------> division: %.2f", resultado);
                    }else{
                        system("cls");
                        printf("NO SE PUEDE MOSTRAR ESTE RESULTADO PORQUE EL DIVIDENDO NO PUEDE SER CERO\n\n");
                         }
                }
           else {
         system("cls");
         printf("primero ingrese operandos");
        }
        break;

   case 6:	/* MULTIPLICACION */
        if (numero1 == 'n' && numero2 == 'n') {
         system("cls");
         resultado = multiplicarParametros(a,b);
          printf("--------> multiplicacion: %.2f", resultado);
        }
        else {
         system("cls");
         printf("primero ingrese operandos");
        }
        break;

   case 7:	/* FACTORIAL */
        if (numero1 == 'n') {
         system("cls");
         resultado= factorialNumero(a);
          printf("--------> factorial de %.0f: %.0f ",a,resultado);
        }
        else {
         system("cls");
         printf("primero ingrese operando A");
        }
        break;
   case 8:
    if (numero2 == 'n') {
         system("cls");
         resultado= factorialNumero2(b);
          printf("--------> factorial de %.0f: %.0f ",b,resultado);
        }
        else {
         system("cls");
         printf("primero ingrese operando b");
        }
        break;
   case 9:	/*TODAS LAS OPERACIONES */
    if (numero1 == 'n' && numero1 == 'n') {
         system("cls");

         printf("suma(%.2f + %.2f): ",a,b);
         resultado = sumaParametros(a,b);
         printf("%.2f\n\n", resultado);

         printf("resta(%.2f - %.2f): ", a, b);
         resultado = restaParametros(a,b);
         printf("%.2f\n\n", resultado);

         printf("division(%.2f / %.2f): ", a, b);
         if(b!=0){
         resultado = dividirParametros(a,b);
         printf("%.2f\n\n", resultado);
         }
         else{
         resultado = printf("NO SE PUEDE MOSTRAR ESTE RESULTADO PORQUE EL DIVIDENDO NO PUEDE SER CERO \n\n");
         }

         printf("multiplicacion(%.2f x %.2f): ", a, b);
         resultado = multiplicarParametros(a,b);
         printf("%.2f\n\n", resultado);

         printf("factorial(%.0f): ",a);
         if (a>0){
             resultado = factorialNumero(a);
             printf("%.0f\n\n", resultado);
         }
         else{
            printf("No se puede mostrar el resultado porque A es un numero menor a cero y no se pueden calcular factorial de un numero negativo A: %.0f\n\n", a);
         }
        printf("factorial(%.0f): ",b);
        if (b>0){
         resultado = factorialNumero2(b);
         printf("%.0f\n\n", resultado);
        }
         else{
            printf("No se puede mostrar el resultado porque A es un numero menor a cero y no se pueden calcular factorial de un numero negativo B: %.0f\n\n", b);
        }

    }

    else {
     system("cls");
     printf("primero ingrese numeros\n\n");
    }
    break;


   case 10:	/*  SALIR */
    system("cls");
    printf("\n\n----> Pulse enter para salir\n\n");

    break;
   default:
    system("cls");
    printf("\n\nEsa opcion no esta disponible, vuelva a ingresar una opcion pulsa enter para seguir\n\n");

  }
  }while(calculadora!=10);

return 0; // *RETORNA CERO, FIN DEL CODIGO*

}

