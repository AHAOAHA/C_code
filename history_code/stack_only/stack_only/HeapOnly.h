class HeapOnly//只能在堆上创建对象，即只可以通过new来创建对象，封死所有可以创建对象的接口，写出一个只可以在堆上创建对象的接口
{
public:
	static HeapOnly* GetObj(int i = 0)
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

	~HeapOnly()
	{
		delete this;
	}
private:
	HeapOnly(int i = 0)
		:_i(i)
	{}
	HeapOnly(const HeapOnly& obj) = delete;
	int _i;
};