#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculateVoltageGain(double output_voltage, double input_voltage) {
    return output_voltage / input_voltage;
}

// Function to calculate current gain
double calculateCurrentGain(double output_current, double input_current) {
    return output_current / input_current;
}

// Function to calculate power gain
double calculatePowerGain(double voltage_gain, double current_gain) {
    return voltage_gain * current_gain;
}

void calculateAlphaBeta(double Ie, double Ic, double Ib, double *alpha, double *beta) {
    *alpha = Ic / Ie;
    *beta = Ic / Ib;
}

double zenerRegulator(double zener_voltage,double input_voltage, double power, double rl){
    // Calculate minimum series resistance
     double min_series_resistance = ((input_voltage * zener_voltage) - pow(zener_voltage, 2)) / power;
    
    // Calculate maximum series resistance
     double max_series_resistance = rl*((input_voltage/zener_voltage)-1);
    printf("Minimum Series Resistance: %.2lf\n", min_series_resistance);
    printf("Maximum Series Resistance: %.2lf\n", max_series_resistance);
    return 0.0;

}

int main()
{
    int choice;
    printf("Welocome to the Electronics guide:\n\nEnter your choice\n1.Calculate the mimimum and maximum series resistance in Zener Voltage regulator\n2.Find common base(alpha) and common emmitter current gain(beta) in a transistor\n3.Find voltage, current and power gain of an amplifier\n4.Exit the menu\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        double zener_voltage, input_voltage_zener, power, rl;
    
    // Get user inputs
    printf("Enter the zener voltage (V): ");
    scanf("%lf", &zener_voltage);
    
    printf("Enter the input voltage (V): ");
    scanf("%lf", &input_voltage_zener);
    
    printf("Enter the power (W): ");
    scanf("%lf", &power);
    printf("Enter the load resistance (Rl): ");
    scanf("%lf", &rl);

    zenerRegulator(zener_voltage,input_voltage_zener, power, rl);
    
    break;
    case 2:
    double emitter_current, collector_current, base_current;
    double alpha, beta;
    
    // Get user input
    
    printf("Enter the collector current (Ic in mA): ");
    scanf("%lf", &collector_current);
    
    printf("Enter the base current (Ib in mA): ");
    scanf("%lf", &base_current);
    emitter_current = collector_current + base_current;
    // Convert current values to Amperes
    emitter_current /= 1000.0;
    collector_current /= 1000.0;
    base_current /= 1000.0;
    
    // Calculate alpha and beta using the function
    calculateAlphaBeta(emitter_current, collector_current, base_current, &alpha, &beta);
    
    // Print the results
    printf("Alpha : %.2lf\n", alpha);
    printf("Beta : %.2lf\n", beta);
    break;
    case 3:
    double input_voltage, input_current, output_voltage, output_current;
    
    // Get user inputs
    printf("Enter the input voltage (V): ");
    scanf("%lf", &input_voltage);
    
    printf("Enter the input current (A): ");
    scanf("%lf", &input_current);
    
    printf("Enter the output voltage (V): ");
    scanf("%lf", &output_voltage);
    
    printf("Enter the output current (A): ");
    scanf("%lf", &output_current);

    double voltage_gain = calculateVoltageGain(output_voltage, input_voltage);
    
    // Calculate current gain
    double current_gain = calculateCurrentGain(output_current, input_current);
    
    // Calculate power gain
    double power_gain = calculatePowerGain(voltage_gain, current_gain);
    printf("Voltage Gain: %.2lf\n", voltage_gain);
    printf("Current Gain: %.2lf\n", current_gain);
    printf("Power Gain: %.2lf\n", power_gain);
    break;
    case 4:
    printf("Thenks for using the electronics tool!");
    exit(0);
    default:printf("invalid input");
        break;
    }
}
