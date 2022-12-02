# Cognitive Load Detection
## Introduction
This is the final project for Erin Seliger, Jay Amlani, Leigh Levinson, and Zachary Kaufman for ENGR-E 545 Wearable Sensors at Indiana University Bloomington. 

For this project we created a cognitive load detection device to determine how fidgeting affects the stress of children working on complex tasks (such as math problems). We utilize a Grove Galvanic Skin Response (GSR) sensor to detect stress levels in the participant and an Inertial Measurement Unit (IMU) to detect fidgeting with the writing utensil provided to the participant. 

Below are the instructions for setting up the device, running the code, collecting the data, and what applications are required. 

## Applications
- You will need some application to send our code (only main.ino is required) to the Arduino Uno, we used the Arduino IDE
- You will need CoolTerm to collect the data

## Hardware
- 1 Arduino Uno
- 1 Grove GSR Sensor
- 1 Adafruit 9 Axis IMU

## Physical Set up
1. The IMU sensor requires that the following solder points have wires attached to them: 
2. Connect those wires to the Arduino Uno in these spots:
  - 
3. The GSR sensor only requires use of its yellow, red, and black wire which is already attached. Connect those wires to the Arduino Uno in these spots: 
  -
4. Now connect the Arduino Uno to the computer you are doing data collection on

Your physical setup is complete

## Running the Code
1. Copy our GitHub repository to your computer by clicking the blue "<> Code" button in the upper right corner of our repository and copying the link that it provides you for an HTTPS connection
2. On your computer open terminal and change your directory to where you want to save the code
3. Type in "git clone [link from Code button]" and hit enter, there should now be a new folder called "Cognitive_Load_Detection"
4. Open the "main.ino" file from our repository on your computer with the Arduino IDE
5. Go to Tools in the Arduino IDE and change the board to "Arduino Uno" and the port to whatever port the Arduino is connected to
6. Hit the Upload button (upper left side of the IDE, it's a circle with an arrow pointing right)
7. Data collection will begin after the code is finished uploading. You can view the output by opening the Serial Monitor under Tools, but Arduino can't save files to your computer, so we will use CoolTerm for that in the "Collecting the Data" section

## Collecting the Data
### Digital collection
1. Open CoolTerm
2. Ensure that the Arduino IDE is closed OR change the port that the Arduino IDE is attached to in Tools > Port, both applications can't share the same port and we need CoolTerm to have the port for data collection
3. Now click the downwards facing arrow in the lower left side of the CoolTerm window
4. Under "Port" click the same port as you did in the Arduino IDE
5. Now hit "Connect" on the top of the CoolTerm window, you should see the same data as you saw in the Arduino Serial Monitor written to the CoolTerm screen

Note: You can reset the output from the Arduino by hitting the red button on the Arduino next to the charger port

6. You can begin recording data by going to Connection > Capture to Text/Binary file > Start
7. When you are finished collection data, click Connection > Capture to Text/Binary file > Stop

### Attaching the sensors
1.
