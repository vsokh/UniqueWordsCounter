#include "TypeDefs.h"
#include "UniqueWordsCounter.h"

#include <unordered_set>

WordsNum UniqueWordsCounter::count(Words&& words)
{
    WordsNum num{};

    std::unordered_set<std::string> set;
    std::for_each(words.begin(), words.end(),
                  [&set, &num](const std::string& word)
    {
        if (auto [_, inserted] = set.insert(word); inserted)
        {
            ++num;
        }
    });

    return num;
}

