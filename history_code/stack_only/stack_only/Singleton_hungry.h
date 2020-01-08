/*单例模式：一个类只能创建一个唯一的对象*/
/*如果一个类中含有静态变量，该静态变量只可以定义出一个对象*/

//饿汉模式：不管程序将来是否会使用，程序启动时，就创建出单例类对象
class Singleton
{
public:
	//设置接口创建唯一的类对象
	static Singleton* GetInstance()
	{
		return &m_Instance;
	}
private:
	//防拷贝
	Singleton(int i = 0)//构造函数私有化
		:_i(i)
	{}

	//删除拷贝构造函数
	Singleton(const Singleton& obj) = delete;

	//删除赋值运算符
	Singleton& operator=(const Singleton& obj) = delete;
	int _i;

	//类对象
	static Singleton m_Instance;
};


//在main函数执行之前就创建出唯一的类对象，饿汉模式即就是在进入main函数之前就已经创建好了唯一的类对象
Singleton Singleton::m_Instance;