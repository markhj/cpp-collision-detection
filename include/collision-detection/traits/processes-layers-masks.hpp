#ifndef COLLISION_DETECTION_PROCESSES_LAYERS_MASKS_HPP
#define COLLISION_DETECTION_PROCESSES_LAYERS_MASKS_HPP

#include <vector>

class ProcessesLayersAndMasks {
protected:
    bool hasLayerAndMaskOverlap(std::vector<int> a_masks, std::vector<int> b_layers);

};

#endif
