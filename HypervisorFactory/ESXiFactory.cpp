#include "ESXiFactory.hpp"
#include "ESXiHypervisor.hpp"

std::unique_ptr<IHypervisor> ESXiFactory::getHypervisor(IProgressObserver* observer)
{
    return std::unique_ptr<IHypervisor>(new ESXiHypervisor(observer));
}
