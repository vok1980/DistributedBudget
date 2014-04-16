
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
        )

set ( SRC_SERIALIZERS
        serializers/MemSaveSerializer.cpp
        serializers/MemLoadSerializer.cpp
        )

set ( INC
        ${INC_SERIALIZERS}
        types.h
        TObjectHolder.h
        ISerializer.h
        DistributedItem.h
        IBalanceStriker.h
        Transaction.h
        Account.h
        Budget.h
        Category.h
        SerializationHelpers.h
        SHA1EngineExt.h
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
	)


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


