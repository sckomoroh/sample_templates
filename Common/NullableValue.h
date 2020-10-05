#ifndef _NullableValue_H_
#define _NullableValue_H_

#include <memory>

namespace com {
namespace common {

template <class TValue>
class NullableValue {
private:
    std::shared_ptr<TValue> _value;

public:
    NullableValue()
        : _value{nullptr}
    {
    }

    template <class TVal>
    NullableValue(TVal&& value)
        : _value{std::make_shared<TValue>(std::forward<TValue>(value))}
    {
    }

    virtual ~NullableValue() = default;

    template <class TVal>
    void setValue(TVal&& value)
    {
        _value = std::make_shared<TValue>(std::forward<TValue>(value));
    }

    bool getValue(TValue& value) const
    {
        return _value == nullptr ? false : (value = *_value, true);
    }
};

}  // namespace common
}  // namespace com

#endif  // _NullableValue_H_
