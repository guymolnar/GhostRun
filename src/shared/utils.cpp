#include "aes.hpp"

std::vector<uint8_t> serialize(const encryptedDataStruct& encryptedData) {
	std::vector<uint8_t> out;
	//We firstly write the size of the data into the buffer, to know how much bytes to extract later. IV and Tag sizes are already fixed.
	auto len = static_cast<uint32_t>(encryptedData.data.size());
	out.insert(out.end(), reinterpret_cast<uint8_t*>(&len), reinterpret_cast<uint8_t*>(&len) + 4);
	out.push_back(encryptedData.injectionFlag);
	out.insert(out.end(), encryptedData.iv.begin(), encryptedData.iv.end());
	out.insert(out.end(), encryptedData.tag.begin(), encryptedData.tag.end());
	out.insert(out.end(), encryptedData.data.begin(), encryptedData.data.end());
	return out;
}

encryptedDataStruct deserialize(const std::vector<uint8_t>& encryptedDataBytes)
{
	encryptedDataStruct encryptedDataStruct;
	uint32_t len = 0;
	std::memcpy(&len, encryptedDataBytes.data(), 4);
	encryptedDataStruct.injectionFlag = encryptedDataBytes.at(4);
	encryptedDataStruct.iv.assign(encryptedDataBytes.data() + 5, encryptedDataBytes.data() + 17);
	encryptedDataStruct.tag.assign(encryptedDataBytes.data() + 17, encryptedDataBytes.data() + 33);
	encryptedDataStruct.data.assign(encryptedDataBytes.data() + 33, encryptedDataBytes.data() + 33 + len);
	return encryptedDataStruct;
}