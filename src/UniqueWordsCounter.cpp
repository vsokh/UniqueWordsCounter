#include "UniqueWordsCounter.h"

std::size_t UniqueWordsCounter::get() const
{
    return _uniqueWords.size();
}

void UniqueWordsCounter::count(Words&& words)
{
    std::for_each(words.begin(), words.end(),
          [this](const Word& word)
          {
              std::lock_guard<std::mutex> guard{_mutex};
              _uniqueWords.insert(word);
          });
}

