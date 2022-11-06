#include "UniqueWordsCounter.h"

#include <unordered_set>

WordsNum UniqueWordsCounter::count(const Words& words)
{
    WordsNum num{};

    std::unordered_set<Word> set;
    std::for_each(words.begin(), words.end(),
                  [&set, &num](const Word& word)
    {
        if (auto [_, inserted] = set.insert(word); inserted)
        {
            ++num;
        }
    });

    return num;
}

