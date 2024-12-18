#include <stdio.h>
#include <stdbool.h>  // Include to use bool data type

// Define a structure to store the status of traffic light bulbs
typedef struct {
    bool red;      // Red light status (true for ON, false for OFF)
    bool green;    // Green light status (true for ON, false for OFF)
    bool orange;   // Orange light status (true for ON, false for OFF)
} TrafficLightStatus;

// Function to display the status of the traffic light
void displayTrafficLightStatus(TrafficLightStatus lightStatus) {
    printf("Traffic Light Status:\n");
    printf("Red: %s\n", lightStatus.red ? "ON" : "OFF");
    printf("Green: %s\n", lightStatus.green ? "ON" : "OFF");
    printf("Orange: %s\n", lightStatus.orange ? "ON" : "OFF");
}

int main() {
    // Example of initializing the traffic light status
    TrafficLightStatus myLightStatus = {true, false, true};  // Red ON, Green OFF, Orange ON

    // Display the current status of the traffic light
    displayTrafficLightStatus(myLightStatus);

    return 0;
}

