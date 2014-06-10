
#pragma once

#include <vector>


class ISerializer;


namespace core
{


    class DistributedItemsFactoryCtrl
    {
    public:
        DistributedItemsFactoryCtrl();
        virtual ~DistributedItemsFactoryCtrl();
    
        int SerializeAll(ISerializer &serializer);
        virtual int Serialize(ISerializer&) = 0;
    
    private:
        static std::vector<DistributedItemsFactoryCtrl*> m_factories;
    };
}

