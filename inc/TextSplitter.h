#pragma once

#include "TypeDefs.h"

class TextSplitter
{
    static constexpr char SEPARATOR = ' ';

public:
    explicit TextSplitter(const char separator = SEPARATOR);
    Words split(TextChunk&& text);

private:
    char _separator{SEPARATOR};
};

