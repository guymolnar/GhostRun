#include "aes.hpp"

std::vector<uint8_t> serialize(const encryptedDataStruct& encryptedData) {
	std::vector<uint8_t> out;
	//We firstly write the size of the data into the buffer, to know how much bytes to extract later. IV and Tag sizes are already fixed.
	auto len = static_cast<uint32_t>(encryptedData.data.size());
	out.insert(out.end(), reinterpret_cast<uint8_t*>(&len), reinterpret_cast<uint8_t*>(&len) + 4);
	out.insert(out.end(), encryptedData.iv.begin(), encryptedData.iv.end());
	out.insert(out.end(), encryptedData.tag.begin(), encryptedData.tag.end());
	out.insert(out.end(), encryptedData.data.begin(), encryptedData.data.end());
	return out;
}
