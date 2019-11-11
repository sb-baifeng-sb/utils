
#ifndef __UTILS_SINGLETON_H__
#define __UTILS_SINGLETON_H__

namespace utils {

template <typename T>
class Singleton {
public:
    virtual ~Singleton() {}
public:
    static T* Shared() {
        if (_instance == nullptr) {
            _instance = new T;
        }
        return _instance;
    }
    static void Destroy() {
        if (_instance != nullptr) {
            delete _instance;
            _instance = nullptr;
        }
    }
private:
    static T* _instance;
};

template <typename T>
T* Singleton<T>::_instance = nullptr;

}

#endif // __ART_SINGLETON_H__
