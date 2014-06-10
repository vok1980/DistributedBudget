
cmake_minimum_required(VERSION 2.8)


if (PROTOBUF_FOUND)
	file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/protobuf/*.proto")
	PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${ProtoFiles})
    include_directories(${PROTOBUF_INCLUDE_DIRS})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif (PROTOBUF_FOUND)

set ( INC_SERIALIZERS
        serializers/MemSaveSerializer.h
        serializers/MemLoadSerializer.h
        serializers/FileLoadSerializer.h
        serializers/FileSaveSerializer.h
        )

set ( SRC_SERIALIZERS
        serializers/MemSaveSerializer.cpp
        serializers/MemLoadSerializer.cpp
        serializers/FileLoadSerializer.cpp
        serializers/FileSaveSerializer.cpp
        )

set ( INC
        ${INC_SERIALIZERS}
        types.h
        TObjectHolder.h
        ISerializer.h
        IBalanceStriker.h
        Transaction.h
        Account.h
        Budget.h
        Category.h
        SHA1EngineExt.h
        SettingsMng.h
	) 

set ( SRC
        ${SRC_SERIALIZERS}
        ${PROTO_SRCS} 
        ${PROTO_HDRS}
        Transaction.cpp
        Account.cpp
        Budget.cpp
        Category.cpp
        SHA1EngineExt.cpp
        SettingsMng.cpp
	)


set ( SRC
        ${SRC}
#        DistributedItems/DistributedItemsFactory.cpp
        DistributedItems/DistributedItemsFactoryCtrl.cpp
    )

set ( INC
        ${INC}
        DistributedItems/DistributedItemsFactory.h
        DistributedItems/DistributedItemsFactoryCtrl.h
        DistributedItems/DistributedItem.h
    )

include_directories(./DistributedItems)


## Find Thread libraries
find_package(Threads REQUIRED)

include_directories(.)

add_library(core 
                ${SRC} 
                ${INC}
                ${SRC_SERIALIZERS}
                ${INC_SERIALIZERS}
        )
target_link_libraries(core 
                        ${CMAKE_THREAD_LIBS_INIT}
                        ${PROTOBUF_LIBRARIES} 
                        )


