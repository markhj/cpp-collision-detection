#include "collision-detection/traits/processes-layers-masks.hpp"

bool ProcessesLayersAndMasks::hasLayerAndMaskOverlap(std::vector<int> a_masks, std::vector<int> b_layers)
{
    for (int b_layer : b_layers) {
        for (int a_mask : a_masks) {
            if (b_layer == a_mask) {
                return true;
            }
        }
    }
    return false;
}
