#include<iostream>
#include<string.h>

using namespace std;
unsigned char* readPPM(const char* fileName, char* pSix, int* width, int* height, int* maximum) {

	// open the file to read just the header reading
	FILE* fr = fopen(fileName, "r");

	// formatted read of header
	fscanf(fr, "%s", pSix);

	// check to see if it's a PPM image file
	if (strncmp(pSix, "P6" , 10) != 0) {
		printf("They are not the same\n");
	} else {
		printf("They are the same\n");
	}

	// read the rest of header
	fscanf(fr, "%d\n %d\n", width, height);

    fscanf(fr, "%d\n", maximum);

    // check to see if they were stored properly
    printf("PSix: %s\n", pSix);
    printf("Width: %d\n", *width);
    printf("Height: %d\n", *height);
    printf("maximum: %d\n", *maximum);

    //int size = width * height;
    int size = 423800;

    // allocate array for pixels
    unsigned char* pixels = new unsigned char[size];

	// unformatted read of binary pixel data
	while (fread(pixels, sizeof(int), 128, fr)) {
		printf("%s", pixels);
	} // end of for loop

	// close file
	fclose(fr);

	// return the array
	return pixels;
	
}
int main() {

	//char fileName[50] = "binary_pixels.txt";
	char fileName[50] = "img.ppm";
	char pSix[10];		// indicates this is a PPM image
	int width = 0;		// width of the image
	int height = 0;		// heigt of the image
	int maximum = 0;	// maximum pixel value
	int size = 128;		// size of the array

	// read the PPM file and store its contents inside an array and return the pointer to that array to pixelArray
	unsigned char* pixelArray = readPPM(fileName, pSix, &width, &height, &maximum);
}