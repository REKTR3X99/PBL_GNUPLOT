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

char * commandsForGnuplot[] = {"plot 'PlotPoints.dat' using 1:2"};

#ifndef PBL_GNU_TYPES_H
#define PBL_GNU_TYPES_H

#endif //PBL_GNU_TYPES_H


#define E_MASS 9.109E-31
#define E_ENERGY 1.6E-19


double InitialVelocity;
double StepSize;
double TimeToSimulate;
double PlateDistance;
double PotentialDifference;
double KeepTrackOfTime = 0;
double Energy;
double Acceleration;
double Force;
unsigned long long ElemCount = 0;
unsigned long long count =  0;
ssize_t buffer;
FILE *fd;



void GetValues()
{
    printf("\nEnter the Initial velocity");
    scanf("%lf",&InitialVelocity);

    printf("\nEnter the potential");
    scanf("%lf",&PotentialDifference);

    printf("\nEnter the plate distance");
    scanf("%lf",&PlateDistance);

    printf("\nEnter the time to simulate for");
    scanf("%lf",&TimeToSimulate);

    printf("\nEnter the step size");
    scanf("%lf",&StepSize);
}

void BasicCompute()
{
    Energy = PotentialDifference/PlateDistance;
    Force = E_ENERGY * Energy;
    Acceleration = Force / E_MASS;
    ElemCount = TimeToSimulate / StepSize;
}

void Parallel_ElectricField()
{


}

int Perpendicular_ElectricField()
{
    double HorizontalDisplacement;
    double VerticalDispalcemment;

    double x0,y0;

    double *XCord;
    double *YCord;
    unsigned long long count = 0;


    FILE *PlotPipe = popen("gnuplot -persistent", "w");

    XCord = (double *)calloc(ElemCount,sizeof(double));
    YCord = (double *)calloc(ElemCount,sizeof(double));


    while(KeepTrackOfTime <=TimeToSimulate)
    {
    HorizontalDisplacement = InitialVelocity * KeepTrackOfTime;
    VerticalDispalcemment  = (((E_ENERGY * Energy)/ (2 *E_MASS)) * (KeepTrackOfTime * KeepTrackOfTime));
    printf("\n%g%g",HorizontalDisplacement,VerticalDispalcemment);
    XCord[count] = HorizontalDisplacement;
    YCord[count] = VerticalDispalcemment;
    count++;
    KeepTrackOfTime+=StepSize;
    }

    fd = fopen("PlotPoints.dat", "w");

    buffer= sizeof(XCord) * 2;

    for(int i =0; i<ElemCount-1;i++)
    {
        fprintf(fd, "%lf %lf",XCord[i], YCord[i]);
        fprintf(fd, "\n");

    }

    for (int i=0; i < 1; i++)
    {
        fprintf(PlotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }



    fclose(fd);
}

void Projectile_Electric()
{
    float ProjectionAngle;
    double Vx0, Vy0;
    double HorizontalDisplacement;
    double VerticalDisplacement;
    double *XCord;
    double *YCord;

    XCord = (double *)calloc(ElemCount,sizeof(double));
    YCord = (double *)calloc(ElemCount,sizeof(double));

    FILE *PlotPipe = popen("gnuplot -persistent", "w");

    printf("\nEnter the projection Angle");
    scanf("%f",&ProjectionAngle);

    Vx0 = InitialVelocity * sin(ProjectionAngle);
    Vy0 = InitialVelocity * cos(ProjectionAngle);

    count = 0;
    KeepTrackOfTime = 0;

    while(KeepTrackOfTime <=TimeToSimulate)
    {
        HorizontalDisplacement = Vx0 * KeepTrackOfTime;
        VerticalDisplacement = Vy0  * (0.5 * Acceleration * pow(KeepTrackOfTime, 2));
        printf("\n%g%g",HorizontalDisplacement,VerticalDisplacement);
        XCord[count] = HorizontalDisplacement;
        YCord[count] = VerticalDisplacement;

        KeepTrackOfTime+= StepSize;
        count++;
    }

    fd = fopen("PlotPoints.dat", "w");

    buffer= sizeof(XCord) * 2;

    for(int i =0; i<ElemCount-1;i++)
    {
        fprintf(fd, "%lf %lf",XCord[i], YCord[i]);
        fprintf(fd, "\n");

    }

    for (int i=0; i < 1; i++)
    {
        fprintf(PlotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }

    fclose(fd);

}

void Trasnverse_Magnetic()
{

}