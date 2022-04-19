// description: 单例模板
// author: zhangzhiyu
// date: 2022.4.19

#include <iostream>

template<typename class_name>
class Singleton
{
public:
    using singleton_ptr = class_name*;

public:
    template <typename... Args>
    static singleton_ptr GetInstance(Args... args)
    {
        if (instance_ == nullptr) {  // 判断是否第一次调用
            instance_ = new class_name(args...);
            std::cout << "create this class " << instance_ << std::endl;
        }
        std::cout << "already created this class" << std::endl;
        return instance_;
    }
    ~Singleton();

private:
    Singleton() {}
    DISALLOW_COPY_AND_ASSIGN(Singleton);

private:
    static singleton_ptr instance_;
};

template<typename class_name>
class_name* Singleton<class_name>::instance_ = nullptr; // 私有的静态成员变量也可以在类外初始化

template<typename class_name>
Singleton<class_name>::~Singleton()
{
}

#define SINGLETON_CLASS(class_name) \
public: \
    friend class Singleton<class_name>; \
    template <typename... Args> \
    static class_name* GetInstance(Args... args) \
    { \
        return Singleton<class_name>::GetInstance(args...); \
    }

#define DISALLOW_COPY_AND_ASSIGN(class_name) \
class_name(const class_name&) = delete; \
class_name& operator=(const class_name&) = delete;

