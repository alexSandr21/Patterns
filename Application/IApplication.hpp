#ifndef IAPPLICATION_HPP
#define IAPPLICATION_HPP

#include <string>
#include "IProgressObserver.hpp"


class IApplication
{
public:
    IApplication(IProgressObserver* observer, const std::string& name)
        : m_progressObserver(observer),
          m_name(name) {}
    virtual ~IApplication() {}
    virtual void install() = 0;
    virtual void uninstall() = 0;
    virtual void exec() = 0;

protected:
    IProgressObserver* m_progressObserver;
    std::string m_name;
};

#endif // IAPPLICATION_HPP
