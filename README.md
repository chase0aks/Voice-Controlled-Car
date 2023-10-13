# Voice Controlled Car

## Overview

The Voice-Controlled RC Car project enables you to control a radio-controlled car using voice commands. This project is ideal for those who want to add an exciting layer of interactivity to their RC car experience by issuing voice commands for control.

## Features

### 1. Voice Control

- Effortlessly control your RC car using voice commands.
- Supported commands include "forward," "back," "left," "right," "donuts," and "stop."

### 2. Motor Control

- Seamlessly adjust the motor's speed and direction in response to voice commands.
- The RC car can move forward, backward, turn left, turn right, or perform donuts as directed.

### 3. Audio Recording

- Record voice commands through a connected microphone for interpretation.
- Save the recorded audio to an audio file for later analysis if needed.

### 4. User Interaction

- A user-friendly interface for starting and stopping the RC car's voice-controlled system.
- Commands can be issued and monitored through the console.

## Prerequisites

Before using this code, ensure that you have the following prerequisites:

- A Raspberry Pi with the WiringPi library installed.
- A microphone connected to the Raspberry Pi.
- The PocketSphinx library installed on the Raspberry Pi.
- Four GPIO pins on the Raspberry Pi connected to the RC car's motor controller.

## Dependencies

This project relies on the following Python modules:

- `wiringPi`: For controlling the GPIO pins on the Raspberry Pi.
- `pocketsphinx`: For speech recognition.
- `wiringPi`: For GPIO control.
- `thread`: For multithreading.
- `chrono`: For time-related functions.

## Usage

1. Ensure that the prerequisites are met, including microphone and motor controller connections.

2. Compile and run the code on your Raspberry Pi.

3. The RC car will start listening for voice commands. Speak one of the supported commands, and the car will respond accordingly.

4. To stop the RC car, say "stop," and it will halt and initiate a shutdown of the Raspberry Pi.

## Cleanup

- After using the code, ensure to release any resources and stop the code gracefully.
- Cleanup includes freeing the PocketSphinx resources and closing the motor controls.

## Troubleshooting

- If you encounter issues with voice recognition, check the microphone's functionality and ensure that PocketSphinx and language models are correctly installed.

- Make sure the GPIO pins are connected appropriately to control the motors.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for detailed information.

## Enjoy Your Voice-Controlled RC Car

Have an exciting and interactive experience with your voice-controlled RC car! This project offers an innovative way to explore the possibilities of voice-activated robotics. Feel free to experiment, enhance, and share your advancements with the community.
