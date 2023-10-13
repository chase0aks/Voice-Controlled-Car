# Voice Controlled Car

## Overview

The Voice-Controlled Robot Car project allows you to build a voice-activated robot car that can move in response to spoken commands. This project is ideal for those who want to create an innovative voice-controlled vehicle using a Raspberry Pi and servos.

## Features

### 1. Voice Control

- Effortlessly control your robot car using voice commands.
- Supported commands include "forward," "back," "left," "right," "donuts," and "stop."

### 2. Motor Control

- Seamlessly adjust the servo motors to control the robot car's movement based on voice commands.
- The car can move forward, backward, turn left, turn right, or perform donuts as directed.

### 3. Audio Recording

- Record voice commands through a connected microphone for interpretation.
- Save the recorded audio to an audio file for later analysis if needed.

### 4. User Interaction

- A user-friendly interface for starting and stopping the voice-controlled system.
- Commands can be issued and monitored through the console.

## Prerequisites

Before using this code, ensure that you have the following prerequisites:

- A Raspberry Pi with the WiringPi library installed.
- A microphone connected to the Raspberry Pi.
- The PocketSphinx library installed on the Raspberry Pi.
- Servo motors connected to the Raspberry Pi for controlling the robot car.

## Dependencies

This project relies on the following Python modules:

- `wiringPi`: For controlling the GPIO pins on the Raspberry Pi.
- `pocketsphinx`: For speech recognition.
- `wiringPi`: For GPIO control.
- `thread`: For multithreading.
- `chrono`: For time-related functions.

## Usage

1. Ensure that the prerequisites are met, including microphone, servo, and Raspberry Pi connections.

2. Compile and run the code on your Raspberry Pi.

3. The robot car will start listening for voice commands. Speak one of the supported commands, and the car will respond accordingly.

4. To stop the robot car, say "stop," and it will halt and initiate a shutdown of the Raspberry Pi.

## Cleanup

- After using the code, ensure to release any resources and stop the code gracefully.
- Cleanup includes freeing the PocketSphinx resources and releasing the servo motors.

## Troubleshooting

- If you encounter issues with voice recognition, check the microphone's functionality and ensure that PocketSphinx and language models are correctly installed.

- Verify that the servo motors are connected appropriately to control the robot car's wheels.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for detailed information.

## Enjoy Your Voice-Controlled Robot Car

Explore the possibilities of voice-activated robotics with your voice-controlled robot car! This project offers an innovative way to build and experiment with voice-controlled vehicles. Feel free to enhance and share your advancements with the community.
