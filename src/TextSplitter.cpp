#include "TextSplitter.h"
#include "TypeDefs.h"

TextSplitter::TextSplitter(const char separator)
    : _separator{separator}
{
}

Words TextSplitter::split(TextChunk&& text)
{
    Words words;

    auto it = text.find(_separator);
    while (it != std::string::npos)
    {
        words.push_back(text.substr(0, it));
        text.erase(0, it + 1);
        it = text.find(_separator);
    }

    if (!text.empty())
    {
        words.push_back(text.substr(0, it));
    }

    return words;
}

