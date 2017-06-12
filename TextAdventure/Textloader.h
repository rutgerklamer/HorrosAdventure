#ifndef TEXTLOADER_H
#define TEXTLOADER_H

#include <iostream>
#include <fstream>

class Textloader
{
public:
    Textloader();
    ~Textloader();
    static void loadText(std::string textlocation);
private:
};

#endif
