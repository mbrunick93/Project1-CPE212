#include "project01.hpp"

 int manip[MAX_ROWS][MAX_COLS];

bool LoadImage(const std::string & imageFile, Image image)
{
	//reads file name and opens it
	std::ifstream inFile;
	inFile.open(imageFile.c_str());

	if (inFile.is_open())
	{
		inFile.ignore(256,'\n'); //skips over the first line in the input file
		for (int i = 0; i < MAX_ROWS; i++){
		for (int j = 0; j < MAX_COLS; j++){
			inFile >> image[i][j]; }}//read/store txt file
	 return true; }

	else {return false;}	
}

bool Flip(Image image, Direction d)
{
switch(d)    

{case 1: //VERT

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		manip[i][j] = image[MAX_ROWS-1-i][j];}}

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		image[i][j] = manip[i][j];}}
	
	return true;
	break;

case -1: //HORZ

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		manip[i][j] = image[i][MAX_COLS-1-j];}}

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		image[i][j] = manip[i][j];}}

	return true;
	break;

default:
	return false;
	break;}
}

bool Rotate(Image image, Rotation r)
{
    
switch(r)
{case 1: //ccw

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		manip[i][j] = image[j][MAX_COLS-1-i];}}

	for (int i = 0; i < MAX_ROWS ; i++){
	for (int j = 0; j < MAX_COLS ; j++){
		image[i][j] = manip[i][j];}}

	return true;
	break;

case -1: //cw

	for (int i = 0 ; i < MAX_ROWS; i ++){
	for (int j = 0 ; j < MAX_COLS; j ++){
		manip[i][j] = image[MAX_ROWS-1-j][i];}}

	for (int i = 0; i < MAX_ROWS ; i++){
	for (int j = 0; j < MAX_COLS ; j++){
	image[i][j] = manip[i][j];}}
	return true;
	break;

default:
	return false;
	break;}
}

void Transpose(Image image)
{
    // Implement this function


for (int i = 0 ; i < MAX_ROWS; i ++){
for (int j = 0 ; j < MAX_COLS; j ++){
manip[i][j] = image[j][i];
}}

for (int i = 0 ; i < MAX_ROWS; i ++){
for (int j = 0 ; j < MAX_COLS; j ++){
image[i][j] = manip[i][j];
}}
  
}
