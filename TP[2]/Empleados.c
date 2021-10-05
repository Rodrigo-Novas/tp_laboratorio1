#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Empleados.h"
#include "Herramientas.h"




int initEmployee(employee *emp,int MAXEMP){
    /** \brief To indicate that all position in the array are empty,
     * this function put the flag (isEmpty) in TRUE in all
     * position of the array
     * \param list Employee* Pointer to array of employees
     * \param len int Array length
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */
    int i;
    int retorno=-1;
    for(i=0;i<MAXEMP;i++){
        emp[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int getFreeSpace(employee* emp, int MAXEMP){

    int i,retorno=-1;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}

int addEmployee(employee *emp,int MAXEMP,char* nombre,
                char* apellido, float salario,int sk,int id){
    /** \brief add in a existing list of employees the values received as parameters
     * in the first empty position
     * \param list employee*
     * \param len int
     * \param id int
     * \param name[] char
     * \param lastName[] char
     * \param salary float
     * \param sector int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or without
    free space] - (0) if Ok
     */
    int i,retorno=-1;
    i=getFreeSpace(emp,MAXEMP);
        if(i!=-1){ //si hay espacio libre

            emp[i].isEmpty=0;
            strcpy(emp[i].name,nombre);
            strcpy(emp[i].lastName,apellido);
            emp[i].salary=salario;
            emp[i].sector=sk;
            emp[i].id=id;
            retorno=0;

        }
    return retorno;
}

int findEmployeeById(employee* emp, int MAXEMP,int id){
    /** \brief find an Employee by Id en returns the index position in array.
     *
     * \param list Employee*
     * \param len int
     * \param id int
     * \return Return employee index position or (-1) if [Invalid length or NULL
    pointer received or employee not found]
     *
 */
    int i;
    int retorno=-1;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==0){ //si esta ocupado
            if(emp[i].id==id){
                retorno=i;
                break;
            }
        }
    retorno=-1;
    }
    return retorno;
}

int removeEmployee(employee* emp,int MAXEMP,int id){
    /** \brief Remove a Employee by Id (put isEmpty Flag in 1)
     *
     * \param list Employee*
     * \param len int
     * \param id int
     * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
    find a employee] - (0) if Ok
     *
     */
    int iAux,retorno=-1;
    char rta;
        iAux=findEmployeeById(emp,MAXEMP,id);
        if(iAux!=-1){//lo encontro
            do{
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
            }while(rta!='S'&&rta!='N');
            if(rta=='S'){
                emp[iAux].isEmpty=1;
                system("cls");
                printf("Accion: Registro eliminado correctamente\n");
                retorno=0;
                }
            if(rta=='N'){
                system("cls");
                printf("Accion: No se elimino el registro\n");
                retorno=-1;
            }
        }
        else{
            system("cls");
            printf("Accion: No se encuentra el ID\n");
        }

    return retorno;
}

int sortEmployee(employee* emp,int MAXEMP,char* name, char* lastName,int opcion){
    /** \brief Sort the elements in the array of employees, the argument order
    indicate UP or DOWN order
     *
     * \param list Employee*
     * \param len int
     * \param order int [1] indicate UP - [0] indicate DOWN
     * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
     *
     */

    employee empAux;
    int i, j;
    if(opcion==1){
        for(i=0;i<MAXEMP-1;i++){
                for(j=i;j<MAXEMP;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(emp[i].sector>emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0;i<MAXEMP-1;i++){
            for(j=i;j<MAXEMP;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(strcmp(emp[i].lastName,emp[j].lastName)>0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }

    if(opcion==0){
        for(i=0;i<MAXEMP-1;i++){
            for(j=i;j<MAXEMP;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(emp[i].sector<emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0;i<MAXEMP-1;i++){
            for(j=i;j<MAXEMP;j++){
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0){
                    if(strcmp(emp[i].lastName,emp[j].lastName)<0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector){
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }
    return 0;
}

int firstEmployee(int flag){
    int retorno=-1;
    if(flag!=1){
        system("cls");
        printf("___________________________________________________________________\n");
        printf("ERROR! Debera realizar la carga de un empleado\n");
        printf("___________________________________________________________________\n");
        retorno=0;
    }
    return retorno;
}

int printEmployee(employee* emp,int MAXEMP){
    /** \brief print the content of employees array
     *
     * \param list Employee*
     * \param length int
     * \return int
     *
     */
    int i,retorno=-1;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==0){
            printf("___________________________________________________________________\n");
            printf("\tEmpleado: %s \nApellido: %s Sector: %d ID: %d\n",
                   emp[i].name,emp[i].lastName,emp[i].sector,emp[i].id);
            printf("___________________________________________________________________\n");
            retorno=i;
        }

    }
    return retorno;
}

void modifyEmployee(employee *emp,int MAXEMP,char* nombre,
                    char* apellido, float salario,int sk,int id,int Modif){
        /** \brief modify existing employee
         * \param list employee*
         * \param len int
         * \param id int
         * \param name[] char
         * \param lastName[] char
         * \param salary float
         * \param sector int
         * \return int Return (-1) if Error [Invalid length or NULL pointer or without
        free space] - (0) if Ok
         */
         if (findEmployeeById(emp,MAXEMP,id)!=0){
            if(Modif==1)
            strcpy(emp[id].name,nombre);
            if(Modif==2)
            strcpy(emp[id].lastName,apellido);
            if(Modif==3)
            emp[id].salary=salario;
            if(Modif==4)
            emp[id].sector=sk;
         }
         else{
            printf("Error el empleado no existe \n");
         }

}

int averageSalary(employee* emp,int MAXEMP){
    int i,retorno=-1;
    float salaryAux=0,empContAux=0;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==0){
            salaryAux+=emp[i].salary;
            empContAux++;
            retorno=0;
        }
        else{
            break;
        }
    }
    if(retorno!=-1){
        retorno=salaryAux/empContAux;
    }
    return retorno;
}

float totalSalary(employee* emp,int MAXEMP){
    int i,retorno=-1;
    float totalSalary=0;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==0){
            totalSalary+=emp[i].salary;
            retorno=totalSalary;
        }
    }
    return retorno;
}

int excSalary(employee* emp,int MAXEMP){
    int i,retorno=-1,count=0;
    for(i=0;i<MAXEMP;i++){
        if(emp[i].isEmpty==0){
            if(emp[i].salary>averageSalary(emp,MAXEMP)){
                count++;
            }
            retorno=count;
        }
    }
    return retorno;
}


void Touperralizar(employee emp[], int CHAR) {
    int i;
    int j;
    for (i = 0; i < CHAR; i++) {
        for (j = 0; j < strlen(emp[i].lastName); ++j) {
            emp[i].lastName[j] = toupper(emp[i].lastName[j]);
        }
    }
    for (i = 0; i < CHAR; i++) {
        for (j = 0; j < strlen(emp[i].name); ++j) {
            emp[i].name[j] = toupper(emp[i].name[j]);
        }
    }
}


int menuoption(void){
    int opcion;

        printf("\tMenu\n");
        printf("-----------------------BIENVENIDO----------------------------- \n");
        printf("|                                                          |\n");
        printf("|1- Alta empleados\n");
        printf("|                                                          |\n");
        printf("|2- Modificar empleados (debera tener empleados cargados)\n");
        printf("|                                                          |\n");
        printf("|3- Baja empleados (debera tener empleados cargados)\n");
        printf("|                                                          |\n");
        printf("|4- Imprimir empleados (debera tener empleados cargados/ NOMBRE Y APELLIDO APARECERAN EN MAYUSCULAS)\n");
        printf("|                                                          |\n");
        printf("|5- Salir\n");
        printf("--------------------------------------------------------------- \n");
        fflush(stdin);
        scanf("%d",&opcion);

return opcion;
}



