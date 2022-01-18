#include "clove.h"
#include "test_filler_algo.h"
#include "test_filler.h"

CLOVE_RUNNER(FillerAlgo_OnePixelWithSuccess, FillerAlgo_OnePixelOutOfRange, FillerAlgo_1x3First2PixelsUpdated, FillerAlgo_1x3First2PixelsUpdatedMovingLeft,
            FillerAlgo_3x1First2PixelsUpdated, FillerAlgo_3x1First2PixelsUpdatedMovingUp,            
            FillerAlgo_ImageWith4ChannelsNotExecuted, FillerAlgo_ImageWith2ChannelsNotExecuted, FillerAlgo_ImageWith1ChannelsNotExecuted, 
            Filler_16x16, Half_Filler_16x16, ZigZag_Filler_16x16, Filler_RedSquare1024x768Performance);