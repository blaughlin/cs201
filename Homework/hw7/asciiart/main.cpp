// asciiart.cpp
// Bernard Laughlin 11/12/2021
// Reads in a PPM file and converts it into ASCII picture

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
#include <sstream>
using std::stringstream;

struct Pixel {
    int red;
    int green;
    int blue;
    double grayscale;
    int reducedGrayscale;
};


// Reads in PPM file and stores file in a vector of type Pixel and stores height and width
void ReadPPMFile(const string & file, vector<Pixel> & image, int & height, int & width) {
    int counter = 0;
    int colorCount = 0;
    Pixel color;
    ifstream fin(file);
    if (!fin) {
        cout << "Can not open file." << endl;
    } else {
        while (true) {
            string line;
            getline(fin, line);
            counter++;
            if (counter == 3) {
                stringstream(line) >> height;
                stringstream(line) >> width;
            }
            if (counter >= 4){
                if (colorCount == 0) {
                    stringstream (line) >> color.red;
                    colorCount +=1;
                } else if (colorCount == 1) {
                    stringstream (line) >> color.green;
                    colorCount +=1;
                } else if  (colorCount == 2){
                    std::stringstream (line) >> color.blue;
                    colorCount = 0;
                    color.grayscale = color.red * 0.212 + 0.715 * color.green + 0.0722 * color.blue;
                    color.reducedGrayscale = color.grayscale/16;
                    image.push_back(color);
                }
            }
            if (!fin) {
                if (fin.eof()) {
                    cout << "Finished reading file." << endl;
                } else {
                    cout << "Error during transmit" << endl;
                }
                break;
            }
        }
    }
}



int main() {
    vector<Pixel> image;
    int height, width;
    ReadPPMFile("parrot.PPM", image, height, width);
    cout << image.size();
    for (auto i : image){
        cout << i.red <<"/"<<i.green<<"/"<<i.blue <<endl;
        cout << i.grayscale << endl;
        cout << i.reducedGrayscale <<endl;
    }
    return 0;
}
