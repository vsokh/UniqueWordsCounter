#include "FileChunksReader.h"

FileChunksReader::FileChunksReader(std::filesystem::path&& path, std::size_t chunkSize)
    : _file{std::move(path), std::ios::in | std::ios::binary}
    , _chunkSize{chunkSize}
{
}

TextChunkOpt FileChunksReader::read()
{
    if (!_file) {
        // throw an exception
        return std::nullopt;
    }

    if (_file.eof()) {
        return std::nullopt;
    }

    TextChunk chunk(_chunkSize, '\0');
    _file.read(chunk.data(), _chunkSize);

    chunk.resize(_file.gcount());
    chunk.shrink_to_fit();

    return chunk;
}
