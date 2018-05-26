#include "HyperVFactory.hpp"
#include "HyperVHypervisor.hpp"

std::unique_ptr<IHypervisor> HyperVFactory::getHypervisor(IProgressObserver* observer)
{
    return std::unique_ptr<IHypervisor>(new HyperVHypervisor(observer));
}
