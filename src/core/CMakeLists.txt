
cmake_minimum_required(VERSION 2.8)

find_package(Protobuf REQUIRED)

if (PROTOBUF_FOUND)
	file(GLOB ProtoFiles "${CMAKE_CURRENT_SOURCE_DIR}/protobuf/*.proto")
	PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${ProtoFiles})
	message("qwerty ${PROTO_SRCS} / ${PROTO_HDRS}")
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
        IDistributedItem.h
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
target_link_libraries(core ${CMAKE_THREAD_LIBS_INIT} )


