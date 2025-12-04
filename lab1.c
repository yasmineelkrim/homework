#include <stdio.h>
#include <math.h>

int main() {

float distance, consumption, price, speed;
int passengers;

printf("Enter distance (km): "); 
scanf("%f", &distance); 

printf("Enter fuel consumption (L/100km): ");
scanf("%f", &consumption);

printf("Enter fuel price (DA/L): ");
scanf("%f", &price);
 
printf("Enter average speed (km/h): ");
scanf("%f", &speed);

printf("Enter number of passengers: ");
scanf("%d", &passengers);

float total_fuel = (consumption * distance) / 100.0;

float total_cost = total_fuel * price;

float cost_per_passenger = total_cost / passengers;

float hours = distance / speed;
int hours_int = (int)hours;
int minutes = (int)((hours - hours_int) * 60);

float cost_per_km = total_cost / distance;
 
int fuel_stops = (int)(total_fuel / 50.0);

 float co2_emissions = total_fuel * 2.31;

printf("\n=== Trip Calculation ===\n");
printf("Distance: %.0f km\n", distance);
printf("Estimated Duration: %dh %dmin\n\n", hours_int, minutes);
printf("Fuel Consumption:\n"); 
printf("Total Fuel Needed: %.2f L\n", total_fuel);
printf("Total Cost: %.2f DA\n", total_cost);
printf("Cost per km: %.2f DA\n", cost_per_km);
printf("Cost per passenger: %.2f DA\n\n", cost_per_passenger);
printf("Fuel Stops Required: %d stop\n", fuel_stops);
printf("(Tank capacity: 50L)\n\n");
printf("Environmental Impact:\n");
printf("CO2 Emissions: %.2f kg\n", co2_emissions);

return 0;

}