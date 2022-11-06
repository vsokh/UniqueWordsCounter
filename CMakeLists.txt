cmake_minimum_required(VERSION 3.20)

project(UniqueWordsCounter)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc src)

add_executable(UniqueWordsCounter

               inc/TypeDefs.h

               inc/FileChunksReader.h
               src/FileChunksReader.cpp

               inc/TextSplitter.h
               src/TextSplitter.cpp

               inc/UniqueWordsCounter.h
               src/UniqueWordsCounter.cpp

               inc/Exceptions.h
               src/Exceptions.cpp

               src/main.cpp)
