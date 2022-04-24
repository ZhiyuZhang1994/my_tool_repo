本代码仓为个人所写一些工具类  
1、一行宏定义使一个类变为单例类  
2、编写类自动注册宏  
3、实现了观察者机制  
4、一行宏声明结构体所有比较函数  

目录结构如下：  
/  
│──main.cpp  
│──readme.md  
│  
├─.vscode                                           // Vscode配置文件
│    
├─include  
│  │─test_moudle.h  
│  │  
│  └─tools  
│     │─class_register.h                                // 相同类的自注册框架  
│     │─construct_define.h                              // 构造函数宏定义  
│     │─declare_operator_funcs.h                        // 通过宏声明结构体的比较函数  
│     │─notifier_and_observer.h                         // 观察者机制  
│     │─Singleton.h                                     // 单例模板  
│       
└─source  
   └─tools  
      └─notifier_and_observer.cpp                        // 观察者机制  
