#pragma once

#include <exception>
#include <variant>

namespace con {

template <typename T>
struct result : private std::variant<T, std::exception_ptr> {
private:
    using base = std::variant<T, std::exception_ptr>;

public:
    explicit result(const T& value)
        : base(value)
    {
    }

    explicit result(const std::exception_ptr& exception)
        : base(exception)
    {
    }

    result()
        : base(T())
    {
    }

    result<T>& operator=(const std::exception_ptr& exception)
    {
        base::operator=(exception);
        return *this;
    }

    result<T>& operator=(const T& value)
    {
        base::operator=(value);
        return *this;
    }

    bool has_value() const noexcept
    {
        return std::holds_alternative<T>(*this);
    }

    bool has_exception() const noexcept
    {
        return std::holds_alternative<std::exception_ptr>(*this);
    }

    T& value()
    {
        if (!has_value()) {
            std::rethrow_exception(std::get<std::exception_ptr>(*this));
        }
        return std::get<T>(*this);
    }
};

} // namespace con
