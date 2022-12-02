const int GSR=A0;
int sensorValue=0;
int gsr_average=0;


//import processing.serial.*;
//Serial mySerial;
//PrintWriter output;

void setup() {

}

void setup(){
  Serial.begin(9600);
//  mySerial = new Serial( this, Serial.list()[0], 9600 );
//output = createWriter( "data.txt" );
}

//void draw(){
//  if (mySerial.available() > 0 ) {
//      String value = mySerial.readString();
//      if ( value != null ) {
//      output.println(value);
//      }
//    }
//}



void loop(){
  long sum=0;
  long c_sum=0;
  long time = 0;
  for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
      {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      delay(5);
      }
   gsr_average = sum/10;
   c_sum += gsr_average;
   time_stamp += 1; // 1 timestep for every 10 that are averaged. 
   Serial.print("GSR Value:"); //comment this out for processing
   Serial.println(gsr_average);
   Serial.print("Cumulative sum:"); //comment this out for processing
   Serial.println(c_sum);
   gsr_overall_avg = c_sum/time_stamp;
   Serial.print("Average"); //comment this out for processing  
   Serial.print(gsr_overall_avg);
   
}

//open COM4 in coolterm 
//connection - capture to text/binary file 
//* option to save file 
//Serial.txt 
//connect data will be saved in the coolterm 



void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}
