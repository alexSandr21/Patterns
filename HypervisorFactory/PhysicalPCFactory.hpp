#ifndef PHYSICALPCFACTORY_HPP
#define PHYSICALPCFACTORY_HPP

#include "IHypervisorFactory.hpp"


class PhysicalPCFactory : public IHypervisorFactory
{
public:
    std::unique_ptr<IHypervisor> getHypervisor(IProgressObserver* observer) override;
};

#endif // PHYSICALPCFACTORY_HPP
