#ifndef SCVMMFACTORY_HPP
#define SCVMMFACTORY_HPP

#include "IHypervisorFactory.hpp"


class SCVMMFactory : public IHypervisorFactory
{
public:
    std::unique_ptr<IHypervisor> getHypervisor(IProgressObserver* observer) override;
};

#endif // SCVMMFACTORY_HPP
