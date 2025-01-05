//Andrea Marquez Tavera
//Dr. Steinberg
//COP3223C Section 1
//Small Program 1

#include <stdio.h> //preprocessor directive

int main() //main fuction
{
    //problem 1

    printf("VV          VV\n");
    printf(" VV        VV\n");
    printf("  VV      VV\n");
    printf("   VV    VV\n");
    printf("    VV  VV\n");
    printf("     VVVV\n");
    printf("      VV\n");

    //-------------------------------------------------------------------------------------------
    //problem 2

    double bor;
    double eor;

    //inputs for problem 2
    printf("Mileage Reimbursement Calculator\n");
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &bor);
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &eor);

    //calculations for problem 2 (mileage reimbursement for an employee at a rate of $2.61/mile)
    double miles = (eor) - (bor);
    printf("You traveled %0.1f miles.\n", miles);
    double reimbursement = (2.61) * miles;
    printf("At $2.61 per mile, your reimbursement is $%0.2f\n", reimbursement);

    //-------------------------------------------------------------------------------------------
    //problem 3

    float weightInPounds;
    float heightInInches;
    
    //inputs for problem 3
    printf("Enter the weight in pounds: ");
    scanf("%f", &weightInPounds);
    printf("Enter the total height in inches: ");
    scanf("%f", &heightInInches);

    //calculations for problem 3 (bmi calculator)
    float BMI = (weightInPounds * 703) / (heightInInches * heightInInches);
    printf("BMI = %0.3f\n", BMI);
    
    //-------------------------------------------------------------------------------------------
    //problem 4 

    const double pi = 3.14159;
    double rad;
    double height;

    //inputs for problem 4
    printf("Enter the radius: ");
    scanf("%lf", &rad);
    printf("Enter the height: ");
    scanf("%lf", &height);

    //calculations for problem 4 (volume of a cone)
    double volume = (1.0 / 3.0) * (pi) * (rad * rad) * (height);
    printf("The volume of the cone is %0.4f\n", volume);

    return 0; //function terminator
}
