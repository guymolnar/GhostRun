#pragma once
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void embedData(const std::vector<uint8_t>& data, const char* imagePath, const char* outputPath);
std::vector<uint8_t> extractData(const char* imagePath);