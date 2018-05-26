#ifndef HYPERVFACTORY_HPP
#define HYPERVFACTORY_HPP

#include "IHypervisorFactory.hpp"


class HyperVFactory : public IHypervisorFactory
{
public:
    std::unique_ptr<IHypervisor> getHypervisor(IProgressObserver* observer) override;
};

#endif // HYPERVFACTORY_HPP
