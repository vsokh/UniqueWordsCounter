#include "FileChunksReader.h"
#include "Exceptions.h"

FileChunksReader::FileChunksReader(const std::filesystem::path& path, std::size_t chunkSize)
    : _file{path, std::ios::in | std::ios::binary}
    , _chunkSize{chunkSize}
{
}

bool FileChunksReader::finished() const
{
    return _finished;
}

TextChunkOpt FileChunksReader::read()
{
    if (_finished)
    {
        return std::nullopt;
    }

    if (!_file)
    {
        throw CantOpenFileException{};
    }

    TextChunk chunk(_chunkSize, ZERO_VALUE);
    _file.read(chunk.data(), _chunkSize);

    if (_file.eof())
    {
        _finished = true;
    }

    chunk.resize(_file.gcount());
    chunk.shrink_to_fit();

    return chunk;
}
