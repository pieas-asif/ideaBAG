#include<stdio.h>
#include <math.h>

#define PI80 M_PI/180

double distanceInKM();
double distanceInFEET();
double distanceInMiles();

int main() {
    int choice;
    double lat1, lon1, lat2, lon2, result;
    printf("Welcome to Distance Between Two Cities\n");
    printf("\t\t\t-Pieas ASIF\n");
    printf("\n");
    printf("\n");
    printf("Enter Latitude For CITY 1 : ");
    scanf("%lf", &lat1);
    printf("Enter Longitude For CITY 1 : ");
    scanf("%lf", &lon1);
    printf("Enter Latitude For CITY 2 : ");
    scanf("%lf", &lat2);
    printf("Enter Longitude For CITY 2 : ");
    scanf("%lf", &lon2);

    printf("\n");
    printf("Enter 1 for Distance in KM\n");
    printf("Enter 2 for Distance in KM\n");
    printf("Enter 3 for Distance in KM\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = distanceInKM(lat1, lon1, lat2, lon2);
            printf("The Distance Between Those Two CITY is %lf KM\n", result);
            break;
        case 2:
            result = distanceInFEET(lat1, lon1, lat2, lon2);
            printf("The Distance Between Those Two CITY is %lf FEET\n", result);
            break;
        case 3:
            result = distanceInMiles(lat1, lon1, lat2, lon2);
            printf("The Distance Between Those Two CITY is %lf Miles\n", result);
            break;
        default:
            printf("OOPS. Invalid Input\n");
            break;
    }

    return 0;
}

double distanceInKM(double lat1, double lon1, double lat2, double lon2) {
    double diffBetweenLat;
    double diffBetweenLon;
    double a, c;
    double km;
    double RADIUS_OF_EARTH = 6371;

    lat1 *= PI80;
    lon1 *= PI80;
    lat2 *= PI80;
    lon2 *= PI80;

    diffBetweenLat = lat2 - lat1;
    diffBetweenLon = lon2 - lon1;
    
    a = sin(diffBetweenLat / 2) * sin(diffBetweenLat / 2) + cos(lat1) * cos(lat2) * sin(diffBetweenLon / 2) * sin(diffBetweenLon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    km = RADIUS_OF_EARTH * c;

    return km;
}

double distanceInFEET(double lat1, double lon1, double lat2, double lon2) {
    double feet;
    double inKM;
    inKM = distanceInKM(lat1, lon1, lat2, lon2);
    feet = inKM * 3280.84;

    return feet;
}

double distanceInMiles(double lat1, double lon1, double lat2, double lon2) {
    double miles;
    double inKM;
    inKM = distanceInKM(lat1, lon1, lat2, lon2);
    miles = inKM * 0.6213712;

    return miles;
}
