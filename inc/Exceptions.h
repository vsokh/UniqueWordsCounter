#pragma once

#include <string>
#include <exception>

class CantOpenFileException : public std::exception
{
public:
    virtual ~CantOpenFileException() = default;
    virtual const char* what() const noexcept;
};
