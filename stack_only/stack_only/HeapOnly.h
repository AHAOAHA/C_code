class HeapOnly//ֻ���ڶ��ϴ������󣬼�ֻ����ͨ��new���������󣬷������п��Դ�������Ľӿڣ�д��һ��ֻ�����ڶ��ϴ�������Ľӿ�
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