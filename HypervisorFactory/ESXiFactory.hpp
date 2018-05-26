#ifndef ESXIFACTORY_HPP
#define ESXIFACTORY_HPP

#include "IHypervisorFactory.hpp"


class ESXiFactory : public IHypervisorFactory
{
public:
    std::unique_ptr<IHypervisor> getHypervisor(IProgressObserver* observer) override;
};


#endif // ESXIFACTORY_HPP
