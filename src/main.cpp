#include <iostream>

#include "FileChunksReader.h"
#include "TextSplitter.h"
#include "UniqueWordsCounter.h"
#include "Exceptions.h"

// TODO: add threading(threadpool?)
// TODO: add cli-presenter
// TODO: add tests(unit, performance?)
// TODO: add observer?

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2)
    {
        return EXIT_FAILURE;
    }

    try
    {
        FileChunksReader reader(argv[1]);
        if (auto chunk = reader.read(); chunk)
        {
            TextSplitter splitter;
            auto words = splitter.split(std::move(*chunk));

            UniqueWordsCounter counter;
            auto wordsNum = counter.count(words);

            std::cout << wordsNum << std::endl;

        }
    }
    catch (const CantOpenFileException& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

