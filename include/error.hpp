#pragma once

#include <exception>
#include <format>
#include <source_location>

namespace con {

class error : public std::exception {
public:
    error(const char* message, std::source_location location = std::source_location::current())
        : message_(std::format("{} ({}:{})", message, location.file_name(), location.line()))
    {
    }

    const char* what() const noexcept override
    {
        return message_.c_str();
    }

private:
    std::string message_;
};

}
