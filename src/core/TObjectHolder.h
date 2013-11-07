
#pragma once 

#include <tr1/memory>

//#include "types.h"
#include "IDistributedItem.h"
#include "ISerializer.h"


template <class TObject>
class TObjectHolder : public IDistributedItem
{
public:
    typedef std::tr1::shared_ptr<TObject> t_ObjectPtr;
    
    TObjectHolder();
    TObjectHolder(t_ObjectPtr);

    void SetObject(t_ObjectPtr ptr);
    void SetObject(const t_DistibutedId &objectId);

    TObjectHolder<TObject>& operator =(t_ObjectPtr);
    TObjectHolder<TObject>& operator =(const t_DistibutedId&);
    
    t_ObjectPtr GetObject(void);
    t_ObjectPtr GetObject(t_DistibutedId &objectId);
    
    virtual int GetId(t_DistibutedId &refId);
    virtual int Serialize(ISerializer &serializer, int32_t iVersion = LAST_SERIALIZE_VERSION);
    
private:
    t_DistibutedId m_objectId;
    t_ObjectPtr m_pObject;
};


template <class TObject>
int TObjectHolder<TObject>::GetId(t_DistibutedId &refId)
{
    GetObject(refId);
    return 0;
}


template <class TObject>
TObjectHolder<TObject>::TObjectHolder()
{
}


template <class TObject>
TObjectHolder<TObject>::TObjectHolder(t_ObjectPtr pObj)
{
	SetObject(pObj);
}


template <class TObject>
int TObjectHolder<TObject>::Serialize(ISerializer &serializer, int32_t iVersion /*= LAST_SERIALIZE_VERSION*/)
{
    t_DistibutedId objectId = m_objectId;
    serializer.Serialize(objectId);
    SetObject(objectId);
    return 0;
}


template <class TObject>
void TObjectHolder<TObject>::SetObject(TObjectHolder<TObject>::t_ObjectPtr ptr)
{
    m_objectId.clear();
    m_pObject = ptr;
    
    if (m_pObject)
        m_pObject->GetId(m_objectId);
}


template <class TObject>
void TObjectHolder<TObject>::SetObject(const t_DistibutedId &objectId)
{
    if (m_objectId != objectId)
    {
        m_objectId = objectId;
        m_pObject.reset();
    }
}


template <class TObject>
TObjectHolder<TObject>& TObjectHolder<TObject>::operator =(t_ObjectPtr ptr)
{
    SetObject(ptr);
    return *this;
}


template <class TObject>
TObjectHolder<TObject>& TObjectHolder<TObject>::operator =(const t_DistibutedId &refId)
{
    SetObject(refId);
    return *this;
}


template <class TObject>
typename TObjectHolder<TObject>::t_ObjectPtr TObjectHolder<TObject>::GetObject(void)
{
    if (!m_pObject)
    {
        ///\todo: recieve object from factory
    }
    
    return m_pObject;
}


template <class TObject>
typename TObjectHolder<TObject>::t_ObjectPtr TObjectHolder<TObject>::GetObject(t_DistibutedId &objectId)
{
    objectId = m_objectId;
    return m_pObject;
}


