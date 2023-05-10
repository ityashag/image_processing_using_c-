#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<vector>

using namespace std;

class pix
{
    public:
    char red , green, blue;
};

int main()
{
   

    ifstream input_file("img.ppm", ios::binary);
    

    ofstream output_file("l.ppm", ios::binary);
   

    string magic_number;
    int width, height, max_value;
    input_file >> magic_number >> width >> height >> max_value;

    output_file << "P5\n" << width << " " << height << "\n255\n";

    char red, green, blue, gray;
    for (int i = 0; i < width * height; i++) {
        input_file.get(red);
        input_file.get(green);
        input_file.get(blue);

        gray = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
        output_file.put(gray);
         output_file.put(gray);
          output_file.put(gray);
    }

    input_file.close();
    output_file.close(); 

    ifstream input_fil("l.ppm", ios::binary);
    ofstream output_fil("k.ppm", ios::binary);
    input_fil >> magic_number >> width >> height >> max_value;

    output_fil << magic_number << "\n" << width << " " << height << "\n" << max_value << "\n";

    vector<char> store;
    for (int y = height - 1; y >= 0; y--) {
        for (int x = width - 1; x >= 0; x--) {
            input_fil.get(red);
            input_fil.get(green);
            input_fil.get(blue);

           //pix temp ;
        //    temp.red=red;
        //    temp.green=green;
        //    temp.blue=blue;
           store.push_back(red);
           store.push_back(green);
           store.push_back(blue);

        }

        for(int i = store.size()-1;i>=0;i--)
        {
            // pix temp = store[i];
            output_fil.put(store[i]);
            // output_fil.put(temp.green);
            // output_fil.put(temp.blue);
        }
        store.clear();
    }

    input_fil.close();
    output_fil.close();

    cout << "Image reversed." << endl;

    return 0;
}