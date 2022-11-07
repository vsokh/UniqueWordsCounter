#include <iostream>
#include <future>

#include "FileChunksReader.h"
#include "TextSplitter.h"
#include "UniqueWordsCounter.h"
#include "Exceptions.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 2)
    {
        return EXIT_FAILURE;
    }

    try
    {
        FileChunksReader reader{argv[1]};
        TextSplitter splitter;
        UniqueWordsCounter counter;

        while (!reader.finished())
        {
            if (auto chunk = reader.read(); chunk)
            {
                std::async(std::launch::deferred | std::launch::async,
                        [&splitter, &counter, chunk = std::move(*chunk)]() mutable
                        {
                            auto words = splitter.split(std::move(chunk));
                            counter.count(std::move(words));
                        });
            }
        }
    }
    catch (const CantOpenFileException& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

