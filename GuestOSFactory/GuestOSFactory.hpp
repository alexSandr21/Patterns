#ifndef GUESTOSFACTORY_HPP
#define GUESTOSFACTORY_HPP

#include <IGuestOS.hpp>

class GuestOSFactory
{
public:
    static GuestOSFactory* getFactory();
    std::unique_ptr<IGuestOS> getGuestOS(GuestOS guest, ProgressObserver* observer);
private:
    explicit GuestOSFactory() {}
    GuestOSFactory(const GuestOSFactory&) = delete;
    GuestOSFactory(GuestOSFactory&&) = delete;
    GuestOSFactory & operator = (const GuestOSFactory&) = delete;
    GuestOSFactory & operator = (GuestOSFactory&&) = delete;
};

#endif // GUESTOSFACTORY_HPP
