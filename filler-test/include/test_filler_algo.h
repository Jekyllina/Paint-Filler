#include "clove.h"
#include "filler.h"

CLOVE_TEST(FillerAlgo_OnePixelWithSuccess)
{
    uint8_t source[3] = {255, 0, 0};
    int width = 1;
    int height = 1;
    int channels = 3;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(0, source[0]);
    CLOVE_INT_EQ(255, source[1]);
    CLOVE_INT_EQ(0, source[2]);
}

CLOVE_TEST(FillerAlgo_OnePixelOutOfRange)
{
    uint8_t source[3] = {255, 0, 0};
    int width = 1;
    int height = 1;
    int channels = 3;
    int pixel_x = 10;
    int pixel_y = 10;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(255, source[0]);
    CLOVE_INT_EQ(0, source[1]);
    CLOVE_INT_EQ(0, source[2]);
}

CLOVE_TEST(FillerAlgo_1x3First2PixelsUpdated)
{
    uint8_t source[9] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    int width = 3;
    int height = 1;
    int channels = 3;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(0, source[0]);
    CLOVE_INT_EQ(255, source[1]);
    CLOVE_INT_EQ(0, source[2]);

    CLOVE_INT_EQ(0, source[3]);
    CLOVE_INT_EQ(255, source[4]);
    CLOVE_INT_EQ(0, source[5]);

    CLOVE_INT_EQ(0, source[6]);
    CLOVE_INT_EQ(0, source[7]);
    CLOVE_INT_EQ(255, source[8]);
}

CLOVE_TEST(FillerAlgo_1x3First2PixelsUpdatedMovingLeft)
{
    uint8_t source[9] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    int width = 3;
    int height = 1;
    int channels = 3;
    int pixel_x = 1;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(0, source[0]);
    CLOVE_INT_EQ(255, source[1]);
    CLOVE_INT_EQ(0, source[2]);

    CLOVE_INT_EQ(0, source[3]);
    CLOVE_INT_EQ(255, source[4]);
    CLOVE_INT_EQ(0, source[5]);

    CLOVE_INT_EQ(0, source[6]);
    CLOVE_INT_EQ(0, source[7]);
    CLOVE_INT_EQ(255, source[8]);
}

CLOVE_TEST(FillerAlgo_3x1First2PixelsUpdatedMovingUp)
{
    uint8_t source[9] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    int width = 1;
    int height = 3;
    int channels = 3;
    int pixel_x = 0;
    int pixel_y = 1;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(0, source[0]);
    CLOVE_INT_EQ(255, source[1]);
    CLOVE_INT_EQ(0, source[2]);

    CLOVE_INT_EQ(0, source[3]);
    CLOVE_INT_EQ(255, source[4]);
    CLOVE_INT_EQ(0, source[5]);

    CLOVE_INT_EQ(0, source[6]);
    CLOVE_INT_EQ(0, source[7]);
    CLOVE_INT_EQ(255, source[8]);
}

CLOVE_TEST(FillerAlgo_3x1First2PixelsUpdated)
{
    uint8_t source[9] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    int width = 1;
    int height = 3;
    int channels = 3;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(0, source[0]);
    CLOVE_INT_EQ(255, source[1]);
    CLOVE_INT_EQ(0, source[2]);

    CLOVE_INT_EQ(0, source[3]);
    CLOVE_INT_EQ(255, source[4]);
    CLOVE_INT_EQ(0, source[5]);

    CLOVE_INT_EQ(0, source[6]);
    CLOVE_INT_EQ(0, source[7]);
    CLOVE_INT_EQ(255, source[8]);
}

CLOVE_TEST(FillerAlgo_ImageWith4ChannelsNotExecuted)
{
    uint8_t source[4] = {255, 0, 0, 255};
    int width = 1;
    int height = 1;
    int channels = 4;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(255, source[0]);
    CLOVE_INT_EQ(0, source[1]);
    CLOVE_INT_EQ(0, source[2]);
    CLOVE_INT_EQ(255, source[3]);
}

CLOVE_TEST(FillerAlgo_ImageWith2ChannelsNotExecuted)
{
    uint8_t source[2] = {255, 0};
    int width = 1;
    int height = 1;
    int channels = 2;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(255, source[0]);
    CLOVE_INT_EQ(0, source[1]);    
}

CLOVE_TEST(FillerAlgo_ImageWith1ChannelsNotExecuted)
{
    uint8_t source[1] = {255};
    int width = 1;
    int height = 1;
    int channels = 1;
    int pixel_x = 0;
    int pixel_y = 0;

    filler_color_t green = {0, 255, 0};
    filler_algo_execute(source, width, height, channels, pixel_x, pixel_y, green);

    CLOVE_INT_EQ(255, source[0]);    
}