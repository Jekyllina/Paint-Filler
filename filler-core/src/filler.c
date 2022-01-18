#include "filler.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void Get_error(enum Error_List error)
{    
    switch(error)
    {
        case Pixel_Out_Of_X_Boundaries:
            printf("ERROR: Pixel Out Of X Boundaries --> ");
            break;
        case Pixel_Out_Of_Y_Boundaries:
            printf("ERROR: Pixel Out Of Y Boundaries --> ");
            break;
        case File_Not_found:
            printf("ERROR: File not found --> ");
            break;        
        default:
            break;
    }
}

void filler_execute(const char* dest_path, const char* source_path, int pixel_x, int pixel_y, filler_color_t new_color)
{
    //read image
    int width, height, channels;
    uint8_t* data = stbi_load(source_path, &width, &height, &channels, 0); 

    if(!data)
    {
        Get_error(2);
        return;
    }

    //apply filler algorithm(source_data, width, height, channels, pixel_x, pixel_y, new_color)
    filler_algo_execute(data, width, height, channels, pixel_x, pixel_y, new_color);

    //write new image
    stbi_write_png(dest_path, width, height, channels, data, 0);

    stbi_image_free(data);
}

void filler_algo_recursive(uint8_t* source_data, int width, int height, int channels, int pixel_x, int pixel_y, filler_color_t new_color, filler_color_t sample_color)
{
    if(pixel_x >= width || pixel_x < 0) return;
    if(pixel_y >= height || pixel_y < 0) return;
    
    int current_pixel_index = (pixel_y * width + pixel_x) * channels;
    
    filler_color_t* current_color = (filler_color_t*)(&source_data[current_pixel_index]); 
    if(current_color->r != sample_color.r) return;
    if(current_color->g != sample_color.g) return; 
    if(current_color->b != sample_color.b) return; 
    
    source_data[current_pixel_index + 0] = new_color.r;
    source_data[current_pixel_index + 1] = new_color.g;
    source_data[current_pixel_index + 2] = new_color.b;  

    filler_algo_recursive(source_data, width, height, channels, pixel_x + 1, pixel_y, new_color, sample_color);
    filler_algo_recursive(source_data, width, height, channels, pixel_x - 1, pixel_y, new_color, sample_color);
    filler_algo_recursive(source_data, width, height, channels, pixel_x, pixel_y + 1, new_color, sample_color);
    filler_algo_recursive(source_data, width, height, channels, pixel_x, pixel_y - 1, new_color, sample_color);
}

void filler_algo_execute(uint8_t* source_data, int width, int height, int channels, int pixel_x, int pixel_y, filler_color_t new_color)
{
    if(pixel_x >= width || pixel_x < 0) 
    {
        Get_error(0);
        return;
    }

    if(pixel_y >= height || pixel_y < 0) 
    {
        Get_error(1);
        return;
    }

    if(channels != 3) return;

    //find pixel data and save color  
    int current_pixel_index = (pixel_y * width + pixel_x) * channels;  
        
    filler_color_t current_color;
    current_color.r = source_data[current_pixel_index + 0];
    current_color.g = source_data[current_pixel_index + 1];
    current_color.b = source_data[current_pixel_index + 2];  
    
    filler_algo_recursive(source_data, width, height, channels, pixel_x, pixel_y, new_color, current_color);
}
