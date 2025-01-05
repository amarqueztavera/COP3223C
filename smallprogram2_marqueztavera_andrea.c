// Andrea Marquez Tavera
// Dr. Steinberg
// COP3223C Section 1
// Small Program 2

#include <stdio.h> // preprocessor directive
#include <math.h> // math library

double coneSurfaceArea(double radius, double height, double pi); // problem 1 function prototype
void parkingCharge();// problem 2 function prototype
void wakandaPopulation(int year);// problem 3 function prototype
double factorialApprox(int num);// problem 4 function prototype

int main() // main fuction
{
    // problem 1

    double radius;
    double height;
    double pi = 3.14;

    // inputs for problem 1
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    printf("Enter the height: ");
    scanf("%lf", &height);

    // call user defined function for problem 1
    double SurfaceArea = coneSurfaceArea(radius, height, pi);
    printf("The total surface area of the cone is %0.2f\n", SurfaceArea);

    //-------------------------------------------------------------------------------------------
    // problem 2
    parkingCharge(); // call user defined function for problem 2

    //-------------------------------------------------------------------------------------------
    // problem 3
    int year;

    // inputs for problem 3
    printf("Enter a year after 2016: ");
    scanf("%d", &year);

    wakandaPopulation(year); // call user defined function for problem 3
    
    //-------------------------------------------------------------------------------------------
    // problem 4
    int num;
    
    // inputs for problem 4
    printf("Enter the value for n: ");
    scanf("%d", &num);

    // call user defined function for problem 4
    double faqApp = factorialApprox(num);
    printf("%d! is approximately %0.4f\n", num, faqApp);
    
    return 0; // function terminator
}

//-------------------------------------------------------------------------------------------
// problem 1 user defined function
double coneSurfaceArea(double radius, double height, double pi)
{
    double formula1 = pow(height, 2) + pow(radius, 2);
    double formula2 = radius + sqrt(formula1);
    double formulafull = pi * radius * formula2;

    return formulafull;
}

//-------------------------------------------------------------------------------------------
// problem 2 user defined function
void parkingCharge()
{
    int hours;

    // inputs for problem 2
    printf("Welcome to the Parking Garage!\n");
    printf("How many hours will you keep your car parked here> ");
    scanf("%d", &hours);

    //calculations for problem 2
    double charge = hours * 4.21;
    printf("Car will be parked for %d hours and will be charged $%.2lf.\n", hours, charge);
}

//-------------------------------------------------------------------------------------------
// problem 3 user defined function
void wakandaPopulation(int year)
{
    //calculations for problem 3
    int t = year - 2016;
    double population = 51.451 + (4.239 * t);

    printf("Predicted Wakanda's population for %d (in thousands): %0.3f\n", year, population);
}

//-------------------------------------------------------------------------------------------
// problem 4 user defined function
double factorialApprox(int num)
{    
    double pi = 3.14;
    double part1 = pow(num, num) * exp(-1 * num);
    double part2 = sqrt(((2 * num) + (1.0 / 3.0)) * pi);
    double facEq = part1 * part2;

    return facEq;
}