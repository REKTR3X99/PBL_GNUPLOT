#include <stdio.h>
#include <stdlib.h>
#include "Types.h"


int ElectricField()
{
    char Type = 'p';
    printf("\nEnter the type of electric field you want to simulate");
    printf("\nP: Parallel Electric Field\nA : Projectile Electric Field\nR: Perpendicular Electric Field");
    scanf("%s", &Type);

    switch(Type)
    {
        case 'p':
        case 'P':
            Parallel_ElectricField();
            break;

        case 'a':
        case 'A':
            Projectile_Electric();
            break;

        case 'r':
        case 'R':
            Perpendicular_ElectricField();
            break;

    }

}

int MagneticField()
{
    char Type;

    printf("\nEnter the type of field you want to try");
    scanf(" %c",&Type);

    switch(Type)
    {
        case 'T':
        case 't':
            Trasnverse_Magnetic();
            break;

        case 'L':
        case 'l':
            Longitudinal_Magnetic();
            break;
    }
}



int main()
{
    char FieldType = 0;

    GetValues();
    BasicCompute();


    printf("Enter the type of field your want");
    printf("\nM : Magnetic Field\nE:Electric Field");

    scanf(" %c", &FieldType);

    switch (FieldType)
    {
        case 'M':
        case 'm':
            MagneticField();
            break;

        case 'E':
        case 'e':
            ElectricField();
            break;
    }
    return 0;

}