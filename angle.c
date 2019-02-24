#include <stdio.h>
#include <math.h>

#define offset_knee 0
#define offset_hip 0

global float femur_length ;
global float tibia_length;
global float height;

float find_ohm(float x, float y){
	float magsquare= (pow((h-y),2)+pow(x,2));
	float a= (pow((h-y),2)+pow(x,2)+pow(femur_length,2)-pow(tibia_length,2))/(2*femur_length*(pow(magsquare,0.5));
	float b= (h-y)/pow(magsquare, 0.5);
	float angle = asin(a)-asin(b);
	return angle;
}


float find_theta(float x, float ohm){
	float sinval = ((femur_length*sin(ohm)-x)/tibia_length);
	float angle= asin(sinval)-ohm;
	return angle;
}

int main(){
	printf("Please enter x \n");
	scanf(&x,"%f");
	printf("Please enter y \n");
	scanf(&y,"%f");
	printf("Please enter the length of femur \n");
	scanf(&femur_length,"%f");
	printf("Please enter the length of tibia \n");
	scanf(&tibia_length,"%f");
	printf("Please enter the height of hip \n");
	scanf(&height,"%f");
	
	
	ohm= find_ohm(x,y);
	theta= find_theta(x, ohm);
	printf("(ohm, theta)= (%f, %f)\n", ohm, theta);
	
	return 0;
}
	
	
