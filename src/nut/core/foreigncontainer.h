#ifndef FOREIGNCONTAINER_H
#define FOREIGNCONTAINER_H

template<class _OBJECT, typename _KEY>
class ForeignContainer
{
    _OBJECT *_object{nullptr};
    _KEY _key;
    enum StorageType {
        Key,
        ClassValue
    };
    StorageType storageType;

public:
    ForeignContainer()
    {}

    ForeignContainer<_OBJECT, _KEY> operator =(const _KEY &key)
    {
        this->_key = key;
        this->_object = nullptr;
        this->storageType = Key;
        return *this;
    }

    ForeignContainer<_OBJECT, _KEY> operator =(const _OBJECT *value)
    {
        this->_object = value;
        this->storageType = ClassValue;
        return *this;
    }

    _KEY key()
    {
        if (this->storageType == Key)
            return _key;
        else
            return _object->primaryValue().template value<_KEY>();
    }

    _OBJECT *object()
    {
        return _object;
    }

    operator _KEY()
    {
        return key();
    }

    operator _OBJECT()
    {
        return object();
    }
};

#endif // FOREIGNCONTAINER_H
