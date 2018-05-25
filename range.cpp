#include <iostream>
#include <wiringPiI2C.h>
//#include "SparkFun_VL53L1X_Arduino_Library.h"
#include <unistd.h>

using namespace std;


int main()
{
   int fd, result;
   // Initialize the interface by giving it an external device ID.
   // The MCP4725 defaults to address 0x60.   
   //
   // It returns a standard file descriptor.
   // 
   fd = wiringPiI2CSetup(0x29);
   cout << "Init result: "<< fd << endl;
   usleep(500);
   //result = wiringPiI2CWriteReg16(fd, 0x40, (i & 0xfff) );
while(1){
   fd = 3;
   unsigned char MSB,LSB;
   wiringPiI2CWriteReg8(fd,0x01,0x0F);
   //wiringPiI2CWrite (fd, 0x01);
   //wiringPiI2CWrite (fd, 0x0F);
   MSB = wiringPiI2CRead(fd);
   LSB = wiringPiI2CRead(fd);
   result = MSB<<8|LSB;
   cout << "ID is: " << result << endl;
   usleep(500);   
   }
}

