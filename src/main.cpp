#include <iostream>

#include "FileChunksReader.h"
#include "TextSplitter.h"
#include "UniqueWordsCounter.h"

// TODO: add threading(threadpool?)
// TODO: add error-handling(exceptions)
// TODO: add tests(unit, performance?)
// TODO: add observer?
// TODO: add cli-presenter

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2) {
        return EXIT_FAILURE;
    }

    FileChunksReader reader(argv[1]);
    if (auto&& chunk = reader.read(); chunk) {
        TextSplitter splitter;
        auto words = splitter.split(std::move(*chunk));

        UniqueWordsCounter counter;

        auto wordsNum = counter.count(std::move(words));
        std::cout << wordsNum << std::endl;

    }
    return EXIT_SUCCESS;
}

