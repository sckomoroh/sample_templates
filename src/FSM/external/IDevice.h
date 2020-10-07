#ifndef _IDevice_H_
#define _IDevice_H_

class IDevice {
public:
    virtual ~IDevice() = default;

    virtual bool initialize() = 0;
    virtual bool open() = 0;
    virtual bool close() = 0;
    virtual bool shutdown() = 0;
};

#endif  // _IDevice_H_
