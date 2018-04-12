//
// Created by ajay on 12/4/18.
//
#include <stdio.h>

#ifndef PBL_GNU_TYPES_H
#define PBL_GNU_TYPES_H

#endif //PBL_GNU_TYPES_H


#define E_MASS 9.109E-31
#define E_ENERGY 1.6E-19


int Parallel_ElectricField()
{
    double velocity;
    double Force;
    double Potential;
    double acceleration;

}

int Perpendicular_ElectricField()
{
    double HorizontalDisplacement;
    double VerticalDispalcemment;
    double InitialVelocity;
    double StepSize;
    double TimeToSimulate;
    double x0,y0;
    double KeepTrackOfTime = 0;
    double Potential;
    double PlateDistance;

    printf("\nEnter the Initial velocity");
    scanf("%lf",&InitialVelocity);

    printf("\nEnter the time to simulate for");
    scanf("%lf",&TimeToSimulate);

    printf("\nEnter the step size");
    scanf("%f",&StepSize);

    printf("\nEnter the potential");
    scanf("%lf",&Potential);

    printf("\nEnter the plate distance");
    scanf("%lf",&PlateDistance);
    while(KeepTrackOfTime <=TimeToSimulate)
    {
    HorizontalDisplacement = InitialVelocity * KeepTrackOfTime;
    VerticalDispalcemment  = -1*( E_ENERGY * Potential);

    }

}