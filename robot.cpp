
#include "robot.hpp"

//check for white pixels
int isWhite (int pixelValue){
	
	if (pixelValue > 250){
		return 1;
	}
	else{
		return 0;
	}
	
}

//find dicstance from white line to center of image
int findError(int arrayCenter, int lineCenter){
	return (arrayCenter - lineCenter);
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	//Declare/Initialise variables
    double vLeft = 10.0;	//left motor speed
    double vRight = 10.0;	//right motor speed
    
    int vForward;		//Constant speed of robot to go forward
	int vDifference;	//Difference between motor speeds
    
    int row = 50; 	//row number
    int error;		//distance of line from center
    
    int arraySize = 150;				//Size of array
    int* pixArray = new int[arraySize];	//Create array for pixel values
    int sumIndexes = 0;
    int count = 0;
    
    //main loop
    while(1){
		
		takePicture();						//get picture
		SavePPMFile("i0.ppm",cameraView);	//save picture
		
		//scan a row of pixels
		for( int column = 0; column < 150; column++){
			int pix = get_pixel(cameraView,row,column,3);
			int pixValue = isWhite(pix);					//call isWhite function
			
			std::cout<<pixValue<<" ";
			
			pixArray[column] = pixValue;
			
		} // close for
		
		//Find sum and number of indexes of white pixels in array
		sumIndexes = 0;
		count = 0;
		for (int i = 0; i < arraySize; i++){
			if (pixArray[i] == 1){
				sumIndexes = sumIndexes + i;
				count++;
			}
		}
		
		//Find error(findError function still isn't done)
		error = findError(arraySize/2, sumIndexes/count);
		std::cout<<"error = "<<error<<std::endl; 
		
		// To do:
		//find difference in speed according to error
		//calculate and set speed of motors accordingly
		
		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		
  } // close while

} // close main


