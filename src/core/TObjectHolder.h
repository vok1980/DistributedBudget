
#pragma once 


#include "types.h"
#include "DistributedItem.h"
#include "ISerializer.h"


namespace core {

template <class TObject>
class TObjectHolder : public DistributedItem<typename TObject::t_Buffer>
{
public:
    typedef t_shared_ptr<TObject> t_ObjectPtr;
    
    TObjectHolder();
    TObjectHolder(t_ObjectPtr);
    TObjectHolder(const t_DistibutedId &objectId);

    void SetObject(t_ObjectPtr ptr);
    void SetObject(const t_DistibutedId &objectId);

    TObjectHolder<TObject>& operator =(t_ObjectPtr);
    TObjectHolder<TObject>& operator =(const t_DistibutedId&);
    
    t_ObjectPtr GetObject(void);
    t_ObjectPtr GetObject(t_DistibutedId &objectId);
    
    virtual int GetId(t_DistibutedId &refId);
    
    virtual int LoadFrom(const typename TObject::t_Buffer&);
    virtual int SaveTo(typename TObject::t_Buffer&);
    
    bool IsSolid(void) const;
    
private:
    bool UpdateId(void);
    
private:
    t_DistibutedId m_objectId;
    t_ObjectPtr m_pObject;
};

};

#include "DistributedItemsFactory.h"

namespace core {

template <class TObject>
int TObjectHolder<TObject>::LoadFrom(const typename TObject::t_Buffer &protobuf)
{
    if (!m_pObject)
    {
        m_pObject = TDistributedItemsFactory<TObject>::Instance().CreateObject();
    }

    int iRetCode = m_pObject->LoadFrom(protobuf);
    UpdateId();
    assert(IsSolid());
    
    return iRetCode;
}


template <class TObject>
int TObjectHolder<TObject>::SaveTo(typename TObject::t_Buffer &protobuf)
{
    if (m_pObject)
        return m_pObject->SaveTo(protobuf);
    
    return 1;
}


template <class TObject>
int TObjectHolder<TObject>::GetId(t_DistibutedId &refId)
{
    UpdateId();
    refId = m_objectId;
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
    assert(IsSolid());
}


template <class TObject>
TObjectHolder<TObject>::TObjectHolder(const t_DistibutedId &objectId)
{
    SetObject(objectId);
}


template <class TObject>
void TObjectHolder<TObject>::SetObject(typename TObjectHolder<TObject>::t_ObjectPtr ptr)
{
    m_objectId.clear();
    m_pObject = ptr;
    UpdateId();
    assert(!ptr || IsSolid());
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
    assert(!ptr || IsSolid());
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
    if (!m_pObject && !m_objectId.empty())
        m_pObject = TDistributedItemsFactory<TObject>::Instance().CreateObject(m_objectId);
    else
        UpdateId();
    
    assert(IsSolid() || m_objectId.empty());
    return m_pObject;
}


template <class TObject>
typename TObjectHolder<TObject>::t_ObjectPtr TObjectHolder<TObject>::GetObject(t_DistibutedId &objectId)
{
    objectId = m_objectId;
    return GetObject();
}


template <class TObject>
bool TObjectHolder<TObject>::IsSolid(void) const
{
    t_DistibutedId objId;
    return !m_objectId.empty() && NULL != m_pObject && 0 == m_pObject->GetId(objId) && objId == m_objectId;
}
    
    
    template <class TObject>
    bool TObjectHolder<TObject>::UpdateId(void)
    {
        if (m_pObject)
        {
            t_DistibutedId newId;

            if (0 == m_pObject->GetId(newId) && newId != m_objectId)
            {
                m_objectId = newId;
                assert(IsSolid());
                return true;
            }
        }
        
        return false;
    }


};


