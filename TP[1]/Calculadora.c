/**
 * \BRIEF solicitar un numero
 * \PARAM -
 * \RETURN numero ingresado
 */

float usuarioNumero(void){
	float num;
	printf("ingrese numero: ");
	scanf("%f",&num);
	return num;
}

/**
 * \BRIEF suma de dos parametros
 * \PARAM num1
 * \PARAM num2
 * \RETURN resuktado
 */

float sumaParametros(float a, float b) {
  return a+b;
}

/**
 * \BRIEF resta de dos parametros
 * \PARAM num1
 * \PARAM num2
 * \RETURN resultado
 */

float restaParametros(float a, float b) {
  return a-b;
}


/**
 * \BRIEF multiplica dos parametros
 * \PARAM num1
 * \PARAM num2
 * \RETURN resultado
 */


float multiplicarParametros(float a, float b) {
  return a*b;
}

/**
 * \BRIEF division dos parametros
 * \PARAM num1 (a)
 * \PARAM num2 (b)
 * \RETURN resultado
 */

float dividirParametros(float a, float b) {
  return a/b;
}

/**
 * \BRIEF realiza el calculo factorial de un numero
 * \PARAM num (n)
 * \RETURN resultado factorial
 */

int factorialNumero(float n)  //FUNCION RECURSIVA

{
 int i;
 int resultado = 1;
 if (n < 1)
    return 1;
  for (i = 1; i <= n; i++)
    resultado = resultado * i;

  return resultado;
}


/**
 * \BRIEF realiza el calculo factorial de un numero
 * \PARAM num (n)
 * \RETURN resultado factorial
 */

int factorialNumero2(float n)  //FUNCION RECURSIVA

{
  int i;
 int resultado = 1;
 if (n < 1)
    return 1;
  for (i = 1; i <= n; i++)
    resultado = resultado * i;

  return resultado;
}
