#include <iostream>
#include <string>
using std::string;
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
private:
    string _file;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
