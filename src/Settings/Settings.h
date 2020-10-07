#ifndef com_Settings_H_
#define com_Settings_H_

#include <string>

namespace com {

template <class TValue>
class Settings {
private:
public:
    Settings() = default;
    virtual ~Settings() = default;

public:
    bool getSetting(const std::string& name, TValue& value)
    {
        auto res = false;

        return res;
    }
};

}  // namespace com

#endif  // com_Settings_H_
