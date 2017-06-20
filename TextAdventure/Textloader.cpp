#include "Textloader.h"
#include "Game.h"

Textloader::Textloader()
{

}

Textloader::~Textloader()
{

}

 void Textloader::LoadText(std::string textlocation)
{
  const char *filename = textlocation.c_str();
     FILE *fptr = NULL;

     if((fptr = fopen(filename,"r")) == NULL)
     {
        fprintf(stderr,"error opening %s\n",filename);
    }

    char read_string[128];

    int removeLines;

    while(fgets(read_string,sizeof(read_string),fptr) != NULL) {
      if ((read_string)[0] == 's' && (read_string)[1] == 'l' && (read_string)[2] == 'p') {
        for (int i = 0; i < removeLines; i++) {
        //  std::cout << "\e[A";
          removeLines = 0;
        }
        Game::Sleep((read_string[3] - '0') * (read_string[4] - '0') * (10 * (read_string[5] - '0')));
      } else if ((read_string)[0] == 'c' && (read_string)[1] == 'l' && (read_string)[2] == 'r') {
        Game::SetTextColor(read_string[3] - '0' + read_string[4] - '0');
      } else {
        removeLines++;
        std::cout << read_string ;
      }
    }
    std::cout << "\n" << std::endl;
    fclose(fptr);
}
