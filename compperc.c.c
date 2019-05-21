#include <stdio.h>
#include <math.h>
int cycle(int init, double perc, int payment, int yrs)
{
   int mths=yrs*12;
   double mfact=(1+perc/1200);
   int i;
   double sum, sumo;
   FILE *F;
   F=fopen("a.txt", "w");
   for(sum=(double)(init-payment), i=1;i<=mths;i++)
   {
       sum+=payment;
       sumo=sum;
       sum*=mfact;
       fprintf(F, "month:%i  percentage is %lf\n",i, sum-sumo) ;
   }
    fclose(F);
    return (int)sum;
}

/*int nocycle(int init, double perc, int payment, int yrs)
{
   int mths=yrs*12;
   double mfact=(1+perc/1200);
   int i;
   double sum;
   sum=init+payment*(pow(mfact,mths)-1)/(mfact-1);
    return (int)sum;
}*/
void main() 
{
    int deposit, payment, years, sum1, sum2;
    double interest;
    printf("Initial deposit:\n");
    scanf("%i", &deposit);
    printf("Annual interest rate:\n");
    scanf("%lf", &interest);
    printf("Monthly payment:\n");
    scanf("%i", &payment);
    printf("Time in years:\n");
    scanf("%i", &years);
    sum1=cycle(deposit, interest, payment, years);
    //sum2=nocycle(deposit, interest, payment, years);
    printf("You will have %i", sum1);
}
