#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <iostream>


using namespace std;
int i2c_port = 3;


int i2cInit(void){

	//----- OPEN THE I2C BUS -----
    int i2c_port;
	char *filename = (char*)"/dev/i2c-1";
	if ((i2c_port = open(filename, O_RDWR)) < 0){
      return 0;
	}
	
	int addr = 0x29;          //<<<<<The I2C address of the slave
	if (ioctl(i2c_port, I2C_SLAVE, addr) < 0)
	{
      return 0;
	}
	
    return (i2c_port);
}


void write(unsigned char addr){
    char buffer[1] = {0};
	int length = 1;			//<<< Number of bytes to write
	write(i2c_port, buffer, length);		
}



int read(int i2c_port){

   char buffer[2] = {0};
   buffer[0] = 0x01;
   buffer[1] = 0x0F;
   int length = 2;			//<<< Number of bytes to write
   write(i2c_port, buffer, length);
   unsigned int result;
   char buffer2[2] = {0};
   int length2 = 2;			//<<< Number of bytes to read
	if (read(i2c_port, buffer2, length2) != length2){
		//ERROR HANDLING: i2c transaction failed
	  return (0);
	}
	else
	{
       result = buffer2[0] << 8 | buffer2[1];
	}
   return (result);
}



	int main(){

    int i2c_port;
	int length;
	unsigned char buffer[60] = {0};
    i2c_port = i2cInit();
    unsigned int result;
	
    while(1){
//		writeRegister(i2c_port);
        result = read(i2c_port);
        cout << result << endl;

   }

}
