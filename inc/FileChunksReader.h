#pragma once

#include "TypeDefs.h"

#include <fstream>
#include <filesystem>
#include <optional>

class FileChunksReader
{
    static constexpr std::size_t MAX_TEXT_CHUNK_SIZE = 1024;

public:
    explicit FileChunksReader(std::filesystem::path&& path, std::size_t chunkSize = MAX_TEXT_CHUNK_SIZE);
    TextChunkOpt read();

private:
    std::ifstream _file{};
    std::size_t _chunkSize{MAX_TEXT_CHUNK_SIZE};
};
