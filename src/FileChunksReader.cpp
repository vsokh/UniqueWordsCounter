#include "FileChunksReader.h"
#include "Exceptions.h"

FileChunksReader::FileChunksReader(const std::filesystem::path& path, std::size_t chunkSize)
    : _file{path, std::ios::in | std::ios::binary}
    , _chunkSize{chunkSize}
{
}

TextChunkOpt FileChunksReader::read()
{
    if (!_file)
    {
        throw CantOpenFileException{};
    }

    if (_file.eof())
    {
        return std::nullopt;
    }

    TextChunk chunk(_chunkSize, ZERO_VALUE);
    _file.read(chunk.data(), _chunkSize);

    chunk.resize(_file.gcount());
    chunk.shrink_to_fit();

    return chunk;
}
