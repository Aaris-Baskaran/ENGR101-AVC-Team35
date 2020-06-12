//Tested by Aidan Lim 6/6/20
//Changed by Marius Minnie 8/6/20
//Changed by Aaris Baskaran 9/6/20
//Tested by Aidan Lim 12/6/20
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

//find distance from white line to center of image
int findError(int arrayCenter, int sumWhiteIndexes, int numWhitePixels){
	if (numWhitePixels > 0){	//Check if the are white pixels to avoid division by 0
		return (arrayCenter - (sumWhiteIndexes/numWhitePixels));
	}
	else{
		return 100;
	}
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	//Declare/Initialise variables
    double vLeft = 10.0;	//left motor speed
    double vRight = 10.0;	//right motor speed
    
    int vForward = 20;		//Constant speed of robot to go forward
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
		
		//Find error
		error = findError(arraySize/2, sumIndexes, count);
		
		if(error < 100){ 
			vDifference = 0.5*error;
		}else{
			error = 0;
			vDifference = error;
		}
		
		std::cout<<"error = "<<error<<std::endl; 
		
		vLeft = vForward - vDifference;
		vRight = vForward + vDifference;
		
		setMotors(vLeft,vRight); 
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
		
		// To do:
		//Add lost mode
		//see if we can use more functions instead of long main function
		
  } // close while

} // close main
