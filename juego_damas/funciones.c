#include <stdio.h>
#include <stdlib.h>
#define T 8

//Declaración de una estructura//
struct jugadores{
    char nombre[50],segundo_nombre[50];
    char apellido[50],segundo_apellido[50];
    char nombre2[50],segundo_nombre2[50];
    char apellido2[50],segundo_apellido2[50];
    char matricula[50];
    char matricula2[50];
} JUGADORES;

 struct partida{
 char seguir;
 char rendirse;
 }PARTIDA;
 //Manuel Ortiz///

 struct reglamento{
 char regla1[500];
 char regla2[500];
 char regla3[500];
 char regla4[500];
 char regla5[500];
 char regla6[500];
  }REGLAMENTO;

FILE *fFile;
FILE *fReglas;
int turno=0;
char tablero[T][T];

int llenarTablero()
{
    system("color f5");

    for(int i=0; i<T; i++)
    {
        fprintf(fFile,"%d",i);
        for(int j=0; j<T; j++)
        {

            if(i<3&&(i+j)%2==0)
            {
                tablero[i][j]='O';

            }
            else if((i==3||i==4)&&(i+j)%2==0)
            {
                tablero[i][j]=' ';
            }
            else if(i>4&&(i+j)%2==0)
            {
                tablero[i][j]='X';
            }
            else
            {
                tablero[i][j]='-';
            }
        }
    }
}
///////////////////////////////////////Pausa para continuar///////////////////////////////////////////////////////////

void pausar()
{
    printf("\nPresione 'C' para continuar...");
    while(getchar()!='C');
}
////////////////////////////////imprimir el  tablero///////////////////////////////////////////////////////////////////////////

int imprimirTablero()
{
    for(int i=0; i<T; i++)
    {

        if(i==0)
        {
            printf(" ");

            for(int k=0; k<=7; k++)
            {

                printf(" %d ",k);
            }
            printf("\n");
        }
        printf("%d ",i);
        for(int j=0; j<T; j++)
        {

            printf(" %c ",tablero[i][j]);
        }
        printf("\n");
    }
}
/////////////////////////////validacion movimiento de pieza/////////////////////////////////////////////////////////////////
int moverPieza(int x, int y, int direccion)
{
    if(turno==1)
    {
        if(tablero[x][y]!='O')
        {
            printf("No existe pieza Negra (O) en la posicion digitada %d %d \n", x, y);
        }
        else
        {
            printf("Direccion %d \n", direccion);
            if(direccion==1&&(y-1)>=1&&(x+1)<8)
            {
                if(tablero[x+1][y-1]==' ')
                {
                    tablero[x][y] =' ';
                    tablero[x+1][y-1]= 'O';
                }
                else if(tablero[x+1][y-1]=='X'&&tablero[x+2][y-2]==' ')
                {
                    tablero[x][y] = ' ';
                    tablero[x+1][y-1]= ' ';
                    tablero[x+2][y-2]= 'O';
                    printf("La pieza Negra se acaba de comer la pieza Blanca en %d %d \n", x + 1, y - 1);
                }
                else
                {
                    printf("La pieza no puede moverse la casilla esta ocupada");
                }
            }
            else
            {
                if(direccion==1)
                {
                    printf("La pieza no puede moverse por que  sale del tablero");
                }
                if(direccion==2&&(y+1)<8&&(x+1)<8)
                {
                    if(tablero[x+1][y+1]==' ')
                    {
                        tablero[x][y]=' ';
                        tablero[x+1][y+1]= 'O';
                    }
                    else if(tablero[x+1][y+1]=='X'&&tablero[x+2][y+2]==' ')
                    {
                        tablero[x][y]=' ';
                        tablero[x+1][y+1]=' ';
                        tablero[x+2][y+2]='O';
                        printf("La pieza Negra se acaba de comer la pieza Blanca en %d %d \n", x + 1, y + 1);
                    }
                    else
                    {
                        printf("La pieza no puede moverse por que la casilla esta ocupada");
                    }
                }
                else
                {
                    if(direccion==2)
                    {
                        printf("La pieza no puede moverse por que sale del tablero");
                    }
                }
            }
        }
        turno=0;
        pausar();
    }
    else
    {
        if(turno==0)
        {
            if(tablero[x][y]!='X')
            {
                printf("No existe pieza Blanca en la posicion digitada %d %d \n", x, y);
            }
            else
            {
                if(direccion==1&&(y-1)>=0&&(x-1)>=0)
                {
                    if(tablero[x-1][y-1]==' ')
                    {
                        tablero[x][y]=' ';
                        tablero[x-1][y-1]='X';
                    }
                    else if(tablero[x-1][y-1]=='O'&&tablero[x-2][y-2]==' ')
                    {
                        tablero[x][y]=' ';
                        tablero[x-1][y-1]=' ';
                        tablero[x-2][y-2]='X';
                        printf("La pieza Blanca se acaba de comer la pieza negra en %d %d \n", x - 1, y - 1);
                    }
                    else
                    {
                        printf("La pieza no puede moverse por que  casilla la ocupada");
                    }
                }
                else
                {
                    if(direccion==1)
                    {
                        printf("La pieza no puede moverse pues sale del tablero");
                    }
                }
                if(direccion==2&&(y+1)<8&&(x-1)>=0)
                {
                    if(tablero[x-1][y+1]==' ')
                    {
                        tablero[x][y] = ' ';
                        tablero[x-1][y+1]='X';
                    }
                    else if(tablero[x-1][y+1]=='O'&&tablero[x-2][y+2]==' ')
                    {
                        tablero[x][y] = ' ';
                        tablero[x-1][y+1]=' ';
                        tablero[x-2][y+2]='X';
                        printf("La pieza Blanca se acaba de comer la pieza negra en %d %d \n", x + 1, y + 1);
                    }
                    else
                    {
                        printf("la pieza no puede moverse por que la casilla esta ocupada");
                    }
                }
                else
                {
                    if(direccion==2)
                        printf("La pieza no puede moverse por que sale del tablero");
                }
            }
            turno=1;
        }
        pausar();
    }
}
int jugar()
{
    system ("cls");
    int x;
    int y;
    int direccion;
    imprimirTablero();

    if(turno==1)
    {
        printf("\t\nSeleccione la ubicacion de la ficha de color Negra (O) que desea jugar...\n");
    }
    else if(turno==0)
    {
        printf("\t\nSeleccione la ubicacion de la  ficha de color Blanca (X) que desea jugar...\n\n");
    }
    printf("\t\nIntroduzca la posicion de la fila y la columna que desea jugar: \n\n");
    scanf("%d %d",&x,&y);

    printf("\t\nElija la direccion de la ficha que desea jugar,\n\tIzquierda [1]\n\tDerecha [2]\n");
    scanf("%d",&direccion);

    moverPieza(x, y, direccion);

    return 1;

}
//Manuel Ortiz//

/////////////////////////////////////Reglas usuario////////////////////////////////////////////////////////////////////
int Reglas()
{

    system ("cls");
    fReglas= fopen("Reglas.txt", "wt");

    fprintf(fReglas,"Regla #1: Las piezas solo se pueden matar en diagonal para adelante,lo cual esos son movimientos multiples. %s\n ",REGLAMENTO.regla1);
    printf("\nRegla #1: Las piezas solo se pueden matar en diagonal para adelante,lo cual esos son movimientos multiples. %s\n ",REGLAMENTO.regla1 );

    fprintf(fReglas,"\nRegla #2: Si un jugador no puede moverse ha perdido su turno de jugar. %s\n",REGLAMENTO.regla2);
    printf("\nRegla #2: Si un jugador no puede moverse ha perdido su turno de jugar. %s\n", REGLAMENTO.regla2);

    fprintf(fReglas,"\nRegla #3: La ficha no puede saltar dos piezas juntas o una pieza de su mismo color. %s\n ",REGLAMENTO.regla3);
    printf("\nRegla #3: La ficha no puede saltar dos piezas juntas o una pieza de su mismo color.%s\n ",REGLAMENTO.regla3);

    fprintf(fReglas, "\nRegla #4: Los movimientos se realizan alternadamente uno por jugador. %s\n", REGLAMENTO.regla4);
    printf("\nRegla #4: Los movimientos se realizan alternadamente uno por jugador. %s\n",REGLAMENTO.regla4);

    fprintf(fReglas,"\nReglas #5: Cada jugador tiene la obligacion de comer siempre y cuando te la oportunidad de hacerlo. %s\n",REGLAMENTO.regla5);
    printf("\nReglas #5: Cada jugador tiene la obligacion de comer siempre y cuando te la oportunidad de hacerlo. %s\n",REGLAMENTO.regla5);

    fprintf(fReglas,"\nRegla #6: Si la pieza de un jugador llega al lado del enemigo corona una Reina y puede comer de extremos a extremos y no es obligatorio comer con la reina coronada. %s\n",REGLAMENTO.regla6);
    printf("\nRegla #6: Si la pieza de un jugador llega al lado del enemigo corona una Reina y puede comer de extremos a extremos y no es obligatorio comer con la reina coronada. %s\n",REGLAMENTO.regla6);
}
///////////////////////////////////////////digitar usuario/////////////////////////////////////////////////

int digita()
{

    system ("cls");

    fFile = fopen("student.txt", "wt");

    printf("\n\tDigitando los jugadores de Damas en C...\n\n");

    printf("\n\tNombres del jugador #1: \n\n");
    scanf("%s %s",&JUGADORES.nombre, &JUGADORES.segundo_nombre);

    printf("\tApellidos completos del  jugador #1: \n\n");
    scanf("%s %s",&JUGADORES.apellido,JUGADORES.segundo_apellido);

    printf("\t Matricula del  jugador #1:\n\n");
    scanf("%s",&JUGADORES.matricula);

    printf("\n\tNombres del jugador #2: \n\n");
    scanf("%s %s",&JUGADORES.nombre2, &JUGADORES.segundo_nombre2);

    printf("\tApellido completos  del jugador #2: \n\n");
    scanf("%s %s",&JUGADORES.apellido2, JUGADORES.segundo_apellido2);

    printf("\t Matricula del jugador #2:\n\n");
    scanf("%s",&JUGADORES.matricula2);

    fprintf(fFile,"Nombre del jugador #1: %s %s\n",JUGADORES.nombre, JUGADORES.segundo_nombre);
    fprintf(fFile,"Apellido completo del jugador #1: %s %s \n",JUGADORES.apellido, JUGADORES.segundo_apellido);
    fprintf(fFile,"Matricula del jugador #1: %s\n",JUGADORES.matricula);
    fprintf(fFile,"Nombre del jugador #2: %s %s \n",JUGADORES.nombre2, JUGADORES.segundo_nombre2);
    fprintf(fFile,"Apellido completo del jugador #2: %s %s\n",JUGADORES.apellido2, JUGADORES.segundo_apellido2);
    fprintf(fFile,"Matricula del jugador #2:%s\n ",JUGADORES.matricula2);
}

