//
//  main.c
//  newtonmethod
//
//  Created by NUR SABRINA BINTI ZURAIMI on 2017/01/27.
//  Copyright © 2017年 NUR SABRINA BINTI ZURAIMI. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define EPS .01

int N = 10; //max number of iterations///

double x0 = 10.0; //initial value//

//define function//
double function(double x){
    double y = 1/(1+x);
    double z = (1/3)*(sin(x));
    
    return (y-z);
}

//define function that has been derivated once//
double dfunction(double x){
    double y = 1/(x+1);
    double z = (sin(x))/3;
    
    return(y-z);
}

int main(int argc, const char * argv[]) {
    
    double h,x1,z;
    int itr; //iterations
    
    for(itr = 1; itr <= N; itr++){
        
        h=(function(x0)/dfunction(x0));
        x1=(x0-h);
        z = x0-x1;
        printf("At Iteration no. %3d, x = %9.6f \n,", itr,x1);
        if ( fabs(z)<EPS)     {
            printf("After Iteration no. %3d, root = %9.6f \n,", itr,x1);
            return 0;
        }
     x0=x1;
    }

    printf("The required solution does not converge or iterations are insufficient!\n");
    return 1;
}



