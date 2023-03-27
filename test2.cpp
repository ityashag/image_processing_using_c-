#include<iostream>
using namespace std;
#include<fstream>
#include<string>

class PPMImage {  
    public:
        PPMImage(){;};
        ~PPMImage(){
            delete threeChan;
        }
        friend std::istream& operator >>(std::ifstream& inputStream, PPMImage& img);
        friend std::ostream& operator <<(std::ofstream& outputStream, const PPMImage& img);
        void grayscale();
            // feel free to add more if you want!

    private:
        string magicNumber; // A "magic number" for identifying the file type
        int width; // Width of the image
        int height; // Height of the image
        int maxColorVal; // Maximum color value
        char *threeChan; // A series of rows and columns (raster) that stores important binary image data
};

std::istream& operator >>(std::ifstream& inputStream, PPMImage& img){  
    string fileName;
    char dump;

    inputStream >> img.magicNumber;

    string myString;
    inputStream >> myString;
    img.width = atoi(myString.c_str());

    inputStream >> myString;
    img.height = atoi(myString.c_str());

    inputStream >> myString;
    img.maxColorVal = atoi(myString.c_str());

    int memoryBlockSize = img.width * img.height * 3; //This means the size is 3 bytes

    img.threeChan = new char[memoryBlockSize];

    inputStream.read(&dump, 1); // ignore newline
    inputStream.read(img.threeChan, img.width * img.height * 3); //Read data into array

    return inputStream;
}

void PPMImage::grayscale(){  
    char *init, *reset;
    unsigned char oldRed, oldGreen, oldBlue, newRed, newGreen, newBlue;

    reset = threeChan; // keep track of initial pointer position

    for(int i = 0; i < width * height; i++){
        init = threeChan;

        oldRed = *threeChan;
        threeChan++;
        oldGreen = *threeChan;
        threeChan++;
        oldBlue = *threeChan;

        newRed  = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);
        newGreen = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);
        newBlue = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);

        threeChan = init;
        *threeChan = newRed;
        threeChan++;
        *threeChan = newGreen;
        threeChan++;
        *threeChan = newBlue;
        threeChan++;
    }
    threeChan = reset; // reset pointer position
}

int main(){  
        PPMImage p;
        ifstream inStream;
        ofstream outStream;
        string srcFileName, outFileName;

        cout << "Please specify the source PPM filename: ";
        cin >> srcFileName;
        inStream.open(srcFileName, std::ifstream::binary);
        inStream >> p;
        inStream.close();
        cout << "Please specify the output PPM filename: ";
        cin >> outFileName;
        p.grayscale();
        outStream.open(outFileName, std::ifstream::binary);
        outStream << p;
        outStream.close();
        cout <<  "The " << srcFileName << " has been converted to grayscale and saved as " << outFileName << endl;
}