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

        int getGrayscale() const {
            return _red * 0.2126 + 0.7152 * _green + 0.0722 * _blue;
    }
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
        for (auto i = 0; i < _image.size(); i++) {
            if (i % _width == 0) cout << endl;
            int reducedGrayscale = _image[i].getGrayscale()/16;
            cout << _key[reducedGrayscale];
        }
    }

private:
    string _file;
    int _width;
    int _height;
    vector<Pixel> _image;
    map<int, string> _key =  {
            {0, " "}, {1, "."}, {2, "`"}, {3,"~"}, {4,"-"},
            {5, "_"}, {6, "+"}, {7, "="}, {8,"!"}, {9,"*"},
            {10, "&"}, {11, "%"}, {12, "$"}, {13,"#"}, {14,"@"},
            {15, "0"} };
};

int main() {
    RGBImage ppm("parrot.ppm");
    ppm.toASCII();
    return 0;
}
