class StackOnly//只在栈上创建对象
{
public:
	StackOnly(int i = 0)
		:_i(i)
	{}
	StackOnly(const StackOnly& obj)
	{
		_i = obj._i;
	}
private:
	void* operator new(size_t size) = delete;
	void operator delete(void* ptr) = delete;

	int _i;
};