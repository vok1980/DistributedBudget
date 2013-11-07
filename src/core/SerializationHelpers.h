
#pragma once

#include <algorithm>
#include "ISerializer.h"


template <typename TCollection>
int SerializationHelperColl(TCollection &coll, ISerializer &refSerializer, int32_t iVersion)
{
	int32_t iSize = coll.size();
	refSerializer.Serialize(iSize);
	coll.resize(iSize);

	std::for_each( coll.begin(), coll.end(),
		[&refSerializer, iVersion](typename TCollection::value_type& value)
		{
			value.Serialize( refSerializer, iVersion );
		}
	);

	return 0;
}


