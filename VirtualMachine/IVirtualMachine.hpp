#ifndef IVIRTUALMACHINE_HPP
#define IVIRTUALMACHINE_HPP

#include <map>
#include <string>
#include <memory>
#include "IGuestOS.hpp"

enum NIC
{
    Bridge,
    Private,
    Passthrough
};

struct HardwareParams
{
    size_t cpu;
    size_t ram;
    size_t hdd;
    NIC nic;
};

class IVirtualMachine
{
public:
    explicit IVirtualMachine(){}
    IVirtualMachine(ProgressObserver* observer, const HardwareParams& params, const std::string& name)
        : m_progressObserver(observer),
          m_hardwareParams(params),
          m_name(name) {}
    virtual ~IVirtualMachine() {}

    virtual std::unique_ptr<IVirtualMachine> clone() = 0;
    virtual void installOS(GuestOS guestOs) = 0;
    virtual void uninstallOS() = 0;
    virtual void installApp(const std::string& appName) = 0;
    virtual void uninstallApp(const std::string& appName) = 0;
    virtual void execApp(const std::string& appName) = 0;
    void setName(const std::string& newName)
    {
        m_name = newName;
    }

protected:
    void checkIsOSInstalled()
    {
        if (!m_guestOS.get())
        {
            throw std::runtime_error("OS doesn't installed");
        }
    }

    ProgressObserver* m_progressObserver;
    HardwareParams m_hardwareParams;
    std::string m_name;
    std::unique_ptr<IGuestOS> m_guestOS;
    GuestOS m_osType;
};

#endif // IVIRTUALMACHINE_HPP
