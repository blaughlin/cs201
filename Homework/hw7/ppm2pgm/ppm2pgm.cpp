// ppm2pgm.cpp
// Bernard Laughlin 11/12/2021
// Reads in a PPM file and converts it into ASCII picture

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;
#include <tuple>
using std::tuple;
#include <sstream>
using std::stringstream;
#include <map>
using std::map;

struct Pixel {
    int red;
    int green;
    int blue;
    int grayscale;
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
                stringstream(line) >> width;
                stringstream(line) >> height;
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
                    color.grayscale = color.red * 0.2126 + 0.7152 * color.green + 0.0722 * color.blue;
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

// Converts a PPM image into PMG and saves it to disk
void WriteOutPGM(const string & fileName, const vector<Pixel> & image, const int & width, const int & height) {
    ofstream fout(fileName);
    if (!fout) {
        cout << "Error opening file" << endl;
        return;
    }
    fout << "P2" << endl;
    fout << width << " " << height << endl;
    fout << "255" << endl;
    for (auto i = 0; i < image.size(); i++) {
        if (i % width == 0 && i != 0) fout << endl;
        fout << image[i].grayscale << " ";
    }
    cout << "Finshed writing out file." << endl;
}

int main() {
    vector<Pixel> image;
    int height, width;
    ReadPPMFile("parrot.PPM", image, height, width);
    WriteOutPGM("parrot.pgm", image, width, height);
    return 0;
}
