#include "Exceptions.h"

const char* CantOpenFileException::what() const noexcept
{
    return "Can't open a file";
}
