#pragma once

#include "clove.h"
#include "filler.h"
#include <string.h>
#include "test_utils.h"
#include "stb_image.h"

CLOVE_TEST(Filler_16x16)
{    
    char* dest_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\updatedImg.png");
    char* source_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\Immagine.png");
    char* expected_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\ImmagineFinale.png");

    filler_color_t new_color = {0, 255, 0};
    filler_execute(dest_path, source_path, 0, 0, new_color);

    int dest_width, dest_height, dest_channels;
    uint8_t *dest_data = stbi_load(dest_path, &dest_width, &dest_height, &dest_channels, 0);

    int expected_width, expected_height, expected_channels;
    uint8_t *expected_data = stbi_load(expected_path, &expected_width, &expected_height, &expected_channels, 0);
    int expected_size = expected_width * expected_height * expected_channels;

    CLOVE_INT_EQ(expected_width, dest_width);
    CLOVE_INT_EQ(expected_height, dest_height);
    CLOVE_INT_EQ(expected_channels, dest_channels);
    CLOVE_INT_EQ(0, memcmp(expected_data, dest_data, expected_size));

    free(dest_path);
    free(source_path);
    free(expected_path);

    stbi_image_free(dest_data);
    stbi_image_free(expected_data);
}

CLOVE_TEST(Half_Filler_16x16)
{    
    char* dest_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\updatedImgProva.png");
    char* source_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\ImmagineProva.png");
    char* expected_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\ImmagineProvaFinale.png");

    filler_color_t new_color = {0, 255, 0};
    filler_execute(dest_path, source_path, 0, 0, new_color);

    int dest_width, dest_height, dest_channels;
    uint8_t *dest_data = stbi_load(dest_path, &dest_width, &dest_height, &dest_channels, 0);

    int expected_width, expected_height, expected_channels;
    uint8_t *expected_data = stbi_load(expected_path, &expected_width, &expected_height, &expected_channels, 0);
    int expected_size = expected_width * expected_height * expected_channels;

    CLOVE_INT_EQ(expected_width, dest_width);
    CLOVE_INT_EQ(expected_height, dest_height);
    CLOVE_INT_EQ(expected_channels, dest_channels);
    CLOVE_INT_EQ(0, memcmp(expected_data, dest_data, expected_size));

    free(dest_path);
    free(source_path);
    free(expected_path);

    stbi_image_free(dest_data);
    stbi_image_free(expected_data);
}

CLOVE_TEST(ZigZag_Filler_16x16)
{    
    char* dest_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\updatedImgZigZag.png");
    char* source_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\ImmagineZigZag.png");
    char* expected_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\ImmagineZigZagFinale.png");

    filler_color_t new_color = {0, 255, 0};
    filler_execute(dest_path, source_path, 8, 4, new_color);  // pixel inside the red line

    int dest_width, dest_height, dest_channels;
    uint8_t *dest_data = stbi_load(dest_path, &dest_width, &dest_height, &dest_channels, 0);

    int expected_width, expected_height, expected_channels;
    uint8_t *expected_data = stbi_load(expected_path, &expected_width, &expected_height, &expected_channels, 0);
    int expected_size = expected_width * expected_height * expected_channels;

    CLOVE_INT_EQ(expected_width, dest_width);
    CLOVE_INT_EQ(expected_height, dest_height);
    CLOVE_INT_EQ(expected_channels, dest_channels);
    CLOVE_INT_EQ(0, memcmp(expected_data, dest_data, expected_size));

    free(dest_path);
    free(source_path);
    free(expected_path);

    stbi_image_free(dest_data);
    stbi_image_free(expected_data);
}

CLOVE_TEST(Filler_RedSquare1024x768Performance)
{
    char* dest_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\updatedImg1024x768.png");
    char* source_path = concat_path(CLOVE_EXEC_BASE_PATH, "\\resources\\Immagine1024x768.png");
    
    filler_color_t new_color = {0, 255, 0};
    filler_execute(dest_path, source_path, 0, 0, new_color);

    CLOVE_IS_TRUE(1);
    
    free(dest_path);
    free(source_path);   
}