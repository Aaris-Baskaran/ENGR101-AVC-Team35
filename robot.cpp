
#include "robot.hpp"

//check for white pixels
int isWhite (int pixelValue){
	
}

//find dicstance from white line to center of image
findError(int arrayCenter, int lineCenter){
	
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	//Declare/Initialise variables
    double vLeft = 20.0;	//left motor speed
    double vRight = 20.0;	//right motor speed
    
    int vForward:		//Constant speed of robot to go forward
	int vDifference:	//Difference between motor speeds
    
    int row = 50; 	//row number
    int error;		//distance of line from center
    
    int* pixArray = new int[150];	//Create array for pixel values
    
    
    //main loop
    while(1){
		
		takePicture();						//get picture
		SavePPMFile("i0.ppm",cameraView);	//save picture
		
		//scan a row of pixels
		for( int column = 0; column < 150; column++){
			int pix = get_pixel(cameraView,row,column,3);
			int pixValue = isWhite(pix);					//call isWhite function
			
			std::cout<<pixValue<<" ";
			
			//insert the pixValue into the array
			
		} // close for
		
		// To do:
		//find error - distance from center
		//find difference in speed according to error
		//set speed of motors accordingly
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
  } // close while

} // close main


