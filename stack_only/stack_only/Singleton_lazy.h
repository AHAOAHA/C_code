/*单例模式，懒汉模式*/

//懒汉模式：不会一开始运行就创建出类对象，会在需要的时候创建出类对象
#include<mutex>

class Singleton
{
public:
	static Singleton* GetInstance();

	class CGarbo
	{
	public:
		//我们需要在main函数return之后释放我们所开辟的值，由于没有办法显示的在return语句之后执行代码
		//所以写出一个没用开辟过堆空间的内部类，在main函数的return语句执行完之后，内部类的析构函数会被
		//自动调用，所以我们可以在该内部类中，释放单例类对象的空间
		~CGarbo()
		{
			if (mp_Instance != nullptr)
			{
				delete mp_Instance;
			}
		}
	};
	
private:
	//构造函数私有化
	Singleton()
	{}

	//防拷贝
	Singleton(const Singleton& obj) = delete;
	Singleton& operator=(const Singleton& obj) = delete;

	//类对象
	static Singleton* mp_Instance;

	//定义出一个静态内部类的对象，用来析构所创建的单例类对象
	static CGarbo Garbo;

	//锁子
	static std::mutex _mux;
};

//在main主函数指向之前，先将指向类对象的指针初始化为nullptr
Singleton* Singleton::mp_Instance = nullptr;

//定义出内部类的成员
Singleton::CGarbo Garbo;

//在main函数执行之前，创建出互斥锁的对象
std::mutex Singleton::_mux;

/*懒汉模式创建单例类对象时，因为进程在cpu上的运行并不是连续的，当一个进程的运行时间片到达时，
另一个进程就会加载进内存，这时候上一个进程就会重新排队，等待自己被调度运行，所以就会出现下面这种
情况：一个进程正在创建单例类对象，正当创建要成功的前一步，该进程的时间片到达，这时候它就不可以
继续运行，必须去重新排队，这时候另一个新的进程被加载到cpu上继续运行，新进程的任务也需要创建单例
类对象，这时候新进程进来看，发现mp_Instance这时候还是nullptr，那么新进程就进去创建出了单例类对象，
当刚刚退出去等待的旧进程回到cpu上继续执行时，继续执行它的下一步，又创建出一个单例类对象，这时候，
程序中就会存在两个单例类对象，这是不被允许的。*/
/*要解决这个问题，就要采用信号量集的办法，我们需要给创建单例模式的地方加上一个二元信号量锁，当一
个进程走来创建单例类对象时，即使这时候该进程的时间片到达，另一个进程也不能进来创建单例类对象*/

/*为什么要以double check的方式加锁？*/
/*因为我们要确保加锁前与加锁后，单例对象都没有被创建出来，假设一种情况，当进程A走进来创建单例对象
检查一次这时候mp_Instance的值还是nullptr，所以该进程越过了if(nullptr == mp_Instance)，刚越过这句代码，
进程A的时间片到达，这时候它必须去重新排队，又有一个新的进程B来创建单例类对象，进程B发现此时mp_Insatnce
的值依旧是nullptr，那么它就进来加上锁，创建单例类对象，打开锁，退出，这时候终于轮到进程A继续执行了
，如果这里没有采用double_check锁的方式，进程A直接执行它的下一句代码，直接加上锁，创建单例类对象，打开
锁，退出，我们发现，这时候就算加上了锁，依然会有创建出两个单例类对象的情况出现*/
Singleton* Singleton::GetInstance()
{
	//这里一定要以Double-Check的方式加锁
	if (nullptr == mp_Instance)
	{
		Singleton::_mux.lock();
		if (nullptr == mp_Instance)
		{
			Singleton *p = new Singleton();
		}
		Singleton::_mux.unlock();
	}
	
	return mp_Instance;
		
}


