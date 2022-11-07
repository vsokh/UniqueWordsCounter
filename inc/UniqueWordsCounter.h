#pragma once

#include "TypeDefs.h"
#include <unordered_set>
#include <mutex>

class UniqueWordsCounter
{
public:
    void count(Words&& words);

private:
    std::unordered_set<Word> _uniqueWords{};
    std::mutex _mutex{};
};

