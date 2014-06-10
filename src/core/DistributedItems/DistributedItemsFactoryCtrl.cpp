
#include "DistributedItemsFactoryCtrl.h"

#include <algorithm>


namespace core
{
    std::vector<DistributedItemsFactoryCtrl*> DistributedItemsFactoryCtrl::m_factories;
    

    DistributedItemsFactoryCtrl::DistributedItemsFactoryCtrl()
    {
        m_factories.push_back(this);
    }


    DistributedItemsFactoryCtrl::~DistributedItemsFactoryCtrl()
    {
        std::remove(m_factories.begin(), m_factories.end(), this);
    }


    int DistributedItemsFactoryCtrl::SerializeAll(ISerializer &serializer)
    {
        std::for_each(m_factories.begin(), m_factories.end(),
                      [&serializer](DistributedItemsFactoryCtrl *pFactory)
                      {
                          pFactory->Serialize(serializer);
                      });
        
        return 0;
    }

};
