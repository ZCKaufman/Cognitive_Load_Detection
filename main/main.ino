#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 IMU = Adafruit_BNO055(55);
const int GSR=A0;
int gsrSensorValue=0;
int ten_sample_average=0;
long gsrOverallAvg=0;
long c_sum=0;
long time_stamp = 0;

void setup(void) {
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!IMU.begin()) {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  IMU.setExtCrystalUse(true);

  // First row in CSV
  Serial.println("10 Sample Average, Cumulative Sum, GSR Overall Average, Gyro X, Gyro Y, Gyro Z, Acc X, Acc Y, Acc Z");
}

void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  long sum = 0;

  // IMU Data Collection
  IMU.getEvent(&event);
  imu::Vector<3> acc = IMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  imu::Vector<3> gyro = IMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);

  // GSR Data
  for(int i=0;i<10;i++) {
      gsrSensorValue = analogRead(GSR);
      sum += gsrSensorValue;
      delay(5);
  }
  ten_sample_average = sum/10;
  c_sum += ten_sample_average;
  time_stamp += 1;
  gsrOverallAvg = c_sum/time_stamp;

  /* Display the floating point data */
  //Serial.print("GSR: ");
  Serial.print(ten_sample_average);
  Serial.print(", ");
  Serial.print(c_sum);
  Serial.print(", ");
  Serial.print(gsrOverallAvg);
  Serial.print(", ");
  Serial.print(event.gyro.x, 4);
  Serial.print(", ");
  Serial.print(event.gyro.y, 4);
  Serial.print(", ");
  Serial.print(event.gyro.z, 4);
  Serial.print(", ");
  Serial.print(event.acceleration.x, 4);
  Serial.print(", ");
  Serial.print(event.acceleration.y, 4);
  Serial.print(", ");
  Serial.print(event.acceleration.z, 4);
  Serial.println("");
  
  delay(100);
}