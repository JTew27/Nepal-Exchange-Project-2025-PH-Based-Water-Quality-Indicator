# Nepal-Project-2025-PH-Based-Water-Quality-Indicator

As part of my studies in my second year of university me and 7 other students were selected to go on the Computer Science Exchange Project out in Nepal in April 2025 for a week. This Exchange aimed to be a collaborative project between students from Leeds Beckett University and the British College of Kathmandu in order to build a sustainable project that could solve a local real world problem. With many people throughout Nepal not having access to clean drinking water alongside my teamates in just two days we aimed to produce a system that could detect safe drinking water and its quality based of the PH level. Utilising an analog sensor, LED lights and other hardware we created a system that could test various samples and indicate if the water was safe to drink in order to ensure safety.

## Hardware & Technologies
- Arduino: Microcontroller used to process analogue sensor readings and control the connected components.
- Analogue pH Sensor: Measures the pH level of water samples through analogue voltage readings.
- 16x2 LCD Display: Displays the calculated pH value in real time.
- LED Indicators: Green and red LEDs provide visual feedback depending on the measured pH range.
- Arduino IDE: Used to develop and upload the microcontroller code.
- C/C++: Used to implement sensor readings, calibration calculations, conditional logic and hardware control.

## System Functionality
- Collects multiple analogue readings from the pH sensor through the Arduino's A0 input.
- Sorts sensor readings and averages the middle six measurements to reduce noise.
- Converts the averaged analogue voltage into an estimated pH value using experimentally determined calibration parameters.
- Displays the calculated pH value on a 16x2 LCD screen.
- Compares the measured pH against a predefined range of 6.5–7.8.
- Activates a green LED when the measurement falls within the defined range and a red LED when it falls outside it.
- Outputs sensor readings, voltage measurements and calculated pH values through the serial monitor for debugging and testing.

## Development & Implementation
- Hardware integration and component connectivity.
- Python script development for processing sensor readings.
- Implementation of conditional logic to interpret pH measurements.
- Integration of LCD and LED output components.
- Testing the prototype against different water samples.
- Collaborative development within a two-day timeframe.

## Project Objectives
- Explore how accessible technology can address local environmental challenges.
- Develop an affordable and accessible water-testing prototype.
- Provide an understandable visual indication of water pH levels.
- Demonstrate the practical application of computer science and hardware integration.
  
## Challenges & Learning Outcomes
-

## Future Improvements
- Improve sensor calibration and measurement accuracy.
- Introduce additional sensors to measure turbidity and total dissolved solids (TDS).
- Store historical measurements for comparison.
- Develop a more comprehensive water quality assessment system.
- Improve the interface and usability of the prototype.

## Project Gallery
