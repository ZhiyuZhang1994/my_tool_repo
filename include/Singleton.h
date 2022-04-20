// description: 单例模板
// author: zhangzhiyu
// date: 2022.4.19

#ifndef INCLUDE_SINGLETON
#define INCLUDE_SINGLETON

#include <iostream>
#include <atomic>
#include <utility>

template<typename class_name>
class Singleton
{
public:
    using singleton_ptr = class_name*;

public:
    template <typename... Args>
    static singleton_ptr get_instance(Args &&... args)
    {
        if (!get_instance_ptr().load()) {  // 判断是否第一次调用
            get_instance_ptr().exchange(new class_name(std::forward<Args>(args)...));
            std::cout << "create this class " << get_instance_ptr().load() << std::endl;
        }
        std::cout << "already created this class " << get_instance_ptr().load() << std::endl;
        return get_instance_ptr().load();
    }

    static void destory()
    {
        auto ptr = get_instance_ptr().exchange(nullptr);
        delete ptr;
    }

private:
    static std::atomic<singleton_ptr>& get_instance_ptr()
    {
        static std::atomic<singleton_ptr> instance_;
        return instance_;
    }

    Singleton() = delete;
    ~Singleton() = delete;

    DISALLOW_COPY_AND_ASSIGN(Singleton);
};

#define SINGLETON_CLASS(class_name) \
public: \
    friend class Singleton<class_name>; \
    template <typename... Args> \
    static class_name* get_instance(Args &&... args) \
    { \
        return Singleton<class_name>::get_instance(std::forward<Args>(args)...); \
    } \
    static void destory() \
    { \
        Singleton<class_name>::destory(); \
    }

#define DISALLOW_COPY_AND_ASSIGN(class_name) \
    class_name(const class_name&) = delete; \
    class_name& operator=(const class_name&) = delete

#endif