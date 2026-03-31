#include <iostream>
#include <vector>
#include <aes.hpp>
#include <cstring>
#include <filesystem>
#include <steg.hpp>
#include "utils.hpp"

int main(int argc, char* argv[])
{
    //argv[0] = . | argv[1] = data | argv[2] = original photo path | argv[3] = 'evil' photo path
    std::cout << "GhostRun Builder" << std::endl;
    if (argc != 4)
    {
        std::cout << "Wrong Usage! Try: " << argv[0] << " <Data> <OriginalPhotoPath> <NewPhotoPath>" << std::endl;
        return 1;
    }
    if (!std::filesystem::exists(argv[2]))
    {
        std::cout << "File does not exist: " << argv[2] << std::endl;
        return 1;
    }
    std::vector<uint8_t> data(argv[1], argv[1] + strlen(argv[1])); //Data is being recieved as a c string, cant use argv[1].end()
    const char *originalImagePath = argv[2];
    const char *newImagePath = argv[3];

    try
    {
        encryptedDataStruct encryptedData = encryptDataAes(data, AES_KEY);
        //When embedding the struct into the image, We firstly have to serialize it and turn it into raw bytes (Need a way to represent it as such).
        std::vector<uint8_t> encryptedDataRawBytes = serialize(encryptedData);

        embedData(encryptedDataRawBytes, originalImagePath, newImagePath);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }
    std::cout << "Success!" << std::endl;
    std::cout << "New image now at: " << newImagePath << std::endl;
    return 0;
}
