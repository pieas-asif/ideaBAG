#include<stdio.h>
#include<math.h>

int main() {
    double cost, tax, total_cost;
    printf("Enter a Cost: ");
    scanf("%lf", &cost);
    printf("Enter Your Country/State Tax: ");
    scanf("%lf", &tax);

    total_cost = cost + (cost * tax / 100);

    printf("Total Price with Cost is: %.2lf\n", total_cost);
}