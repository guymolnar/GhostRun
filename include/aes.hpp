#pragma once
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <vector>

struct encryptedData {
	std::vector<uint8_t> iv;
	std::vector<uint8_t> tag;
	std::vector<uint8_t> data;
};

encryptedData encryptDataAes(const std::vector<uint8_t>& plaintext, const std::vector<uint8_t>& key);
std::vector<uint8_t> aesDecrypt(const std::vector<uint8_t>& key, const encryptedData& encrypted);