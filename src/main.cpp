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

        std::promise<std::size_t> promiseCounter;

        while (!reader.finished())
        {
            if (auto chunk = reader.read(); chunk)
            {
                std::async(std::launch::deferred | std::launch::async,
                        [&reader, &splitter, &counter, chunk = std::move(*chunk), &promiseCounter]() mutable
                        {
                            auto words = splitter.split(std::move(chunk));
                            counter.count(std::move(words));

                            if (reader.finished())
                            {
                                promiseCounter.set_value(counter.get());
                            }
                        });
            }
        }

        auto fut = promiseCounter.get_future();
        auto count = fut.get();
        std::cout << count << std::endl;
    }
    catch (const CantOpenFileException& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}

