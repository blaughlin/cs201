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
#include <sstream>
using std::stringstream;
#include <map>
using std::map;

class Pixel {
public:
    Pixel(int red, int green, int blue) :
        _red{red}, _green{green}, _blue{blue} {}
private:
    int _red;
    int _green;
    int _blue;
};

class RGBImage {
public:
    RGBImage(string filename) :
    _file{filename} {}

    void ReadFile() {
        int red, green, blue;
        int counter = 0;
        int colorCount = 0;
        ifstream fin(_file);
        if (!fin) {
            cout << "Can not open file" << endl;
        } else {
            while (true) {
                string line;
                getline(fin, line);
                counter++;
                if (counter == 3) {
                    stringstream(line) >> _width;
                    stringstream(line) >> _height;
                }
                if (counter >= 4) {
                    if (colorCount == 0) {
                        stringstream(line) >> red;
                        colorCount += 1;
                    } else if (colorCount == 1) {
                        stringstream(line) >> green;
                        colorCount += 1;
                    } else if (colorCount == 2) {
                        stringstream(line) >> blue;
                        colorCount = 0;
                        Pixel color(red, green, blue);
                        _image.push_back(color);
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

    void toASCII(){
        ReadFile();

    }

private:
    string _file;
    int _width;
    int _height;
    vector<Pixel> _image;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
