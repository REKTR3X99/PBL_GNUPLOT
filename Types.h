//
// Created by ajay on 12/4/18.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

char * commandsForGnuplot[] = {"set title \"Plot\"", "plot 'PlotPoints.dat' using 1:2"};

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
    double Energy;
    unsigned long long ElemCount = 0;

    double *XCord;
    double *YCord;
    unsigned long long count = 0;
    FILE *fd;

    printf("\nEnter the Initial velocity");
    scanf("%lf",&InitialVelocity);

    printf("\nEnter the time to simulate for");
    scanf("%lf",&TimeToSimulate);

    printf("\nEnter the step size");
    scanf("%lf",&StepSize);

    printf("\nEnter the potential");
    scanf("%lf",&Potential);

    printf("\nEnter the plate distance");
    scanf("%lf",&PlateDistance);

    Energy = Potential/PlateDistance;
    ElemCount = TimeToSimulate / StepSize;

    XCord = (double *)calloc(ElemCount,sizeof(double));
    YCord = (double *)calloc(ElemCount,sizeof(double));


    while(KeepTrackOfTime <=TimeToSimulate)
    {
    HorizontalDisplacement = InitialVelocity * KeepTrackOfTime;
    VerticalDispalcemment  = (((E_ENERGY * Energy)/ (2 *E_MASS)) * (KeepTrackOfTime * KeepTrackOfTime));
    XCord[count] = HorizontalDisplacement;
    YCord[count] = VerticalDispalcemment;
    count++;
    KeepTrackOfTime+=StepSize;
    }

    fd = fopen("PlotPoints.dat", "w");

    ssize_t buffer = sizeof(XCord) * 2;

    for(int i =0; i<ElemCount-1;i++)
    {
        fprintf(fd, "%lf %lf",XCord[i], YCord[i]);
        fprintf(fd, "\n");

    }
    FILE *PlotPipe = popen("gnuplot", "w");

    for(int i =0; i<5;i++)
    {
        fprintf(PlotPipe,"%s \n",commandsForGnuplot[i]);
    }

    //system("p 'PlotPoints.dat' using 1:2");

}

void Projectile_Electric()
{
    
}