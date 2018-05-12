#include "GuestOSFactory.hpp"
#include "LinuxGuestOS.hpp"
#include "WindowsGuestOS.hpp"

GuestOSFactory *GuestOSFactory::getFactory()
{
    static std::unique_ptr<GuestOSFactory> factory;
    if (!factory.get())
    {
        factory.reset(new GuestOSFactory());
    }
    return factory.get();
}

std::unique_ptr<IGuestOS> GuestOSFactory::getGuestOS(GuestOS guest, ProgressObserver* observer)
{
    std::unique_ptr<IGuestOS> guestPtr;

    switch (guest)
    {
    case GuestOS::Linux:
        guestPtr.reset(new LinuxGuestOS(observer));
        break;
    case GuestOS::Windows:
        guestPtr.reset(new WindowsGuestOS(observer));
        break;
    default:
        throw std::runtime_error("Wrong type of guest OS");
    }

    return std::move(guestPtr);
}
