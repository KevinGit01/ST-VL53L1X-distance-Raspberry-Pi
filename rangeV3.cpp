#include <iostream>
#include "SparkFun_VL53L1X_Arduino_Library.h"
#include <unistd.h>
#include <ctime>

using namespace std;

VL53L1X distanceSensor;


int main()
{


   bool status;  
   status = distanceSensor.begin();
  // cout << status << endl;
  int counter = 0;
  int rate = 0;
  double time = 0;
  clock_t begin = clock();

while(counter < 50){

   
   distanceSensor.startMeasurement(); //Write configuration bytes to initiate measurement

  //Poll for completion of measurement. Takes 40-50ms.
  while(distanceSensor.newDataReady() == false){
    usleep(5);
 }   


  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  cout << "distance is "<< distance << endl;
  counter++;

}

  clock_t end = clock();
  time = begin - end;
  rate = 50/time;
  cout << time;
 return 0;
}

