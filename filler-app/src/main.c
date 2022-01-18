#include "stb_image.h"
#include "stb_image_write.h"
#include "filler.h"

int main(int argc, char* argv[])
{   
    //app's input:
    /*
    -filename_input
    -pixel coordinates
    -new color
    -filename_output    
    */

    char* file_name = "Immagine.png";
    int width, height, channels;
    unsigned char* data = stbi_load(file_name, &width, &height, &channels, 0);

    // printf("width: %d, height: %d", width, height);
    // int size = width * height * channels;  //quanti byte pesa l'immagine
    // printf("size: %d", size);

    // printf("pixel0: %d, %d, %d", (int)data[0], (int)data[1], (int)data[2]); 

    stbi_image_free(data);

    filler_color_t green = {0, 255, 0, 0};

    filler_execute("destination.png", "Immagine.png", 0, 0, green);
    
    return 0;
}