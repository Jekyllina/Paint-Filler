#pragma once
#include <stdint.h>

enum Error_List{
    Pixel_Out_Of_X_Boundaries, 
    Pixel_Out_Of_Y_Boundaries, 
    File_Not_found    
};

typedef struct 
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}filler_color_t;

/*
* This function will apply filler algorithm, creating a new image filled with the new color
*
* @param dest_path New image path
* @param source_path Source image path
* @param pixel_x X position of the pixel to replace with new color
* @param pixel_y Y position of the pixel to replace with new color
* @param new_color The new color to be used for filling
*/
void filler_execute(const char* dest_path, const char* source_path, int pixel_x, int pixel_y, filler_color_t new_color);

void filler_algo_execute(uint8_t* source_data, int width, int height, int channels, int pixel_x, int pixel_y, filler_color_t new_color);