#include "TextSplitter.h"
#include "TypeDefs.h"

Words TextSplitter::split(TextChunk&& text)
{
    Words words;

    auto it = text.find(' ');
    while (it != std::string::npos)
    {
        words.push_back(text.substr(0, it));
        text.erase(0, it + 1);
        it = text.find(' ');
    }

    if (!text.empty())
    {
        words.push_back(text.substr(0, it));
    }

    return words;
}

