/*����ģʽ��һ����ֻ�ܴ���һ��Ψһ�Ķ���*/
/*���һ�����к��о�̬�������þ�̬����ֻ���Զ����һ������*/

//����ģʽ�����ܳ������Ƿ��ʹ�ã���������ʱ���ʹ��������������
class Singleton
{
public:
	//���ýӿڴ���Ψһ�������
	static Singleton* GetInstance()
	{
		return &m_Instance;
	}
private:
	//������
	Singleton(int i = 0)//���캯��˽�л�
		:_i(i)
	{}

	//ɾ���������캯��
	Singleton(const Singleton& obj) = delete;

	//ɾ����ֵ�����
	Singleton& operator=(const Singleton& obj) = delete;
	int _i;

	//�����
	static Singleton m_Instance;
};


//��main����ִ��֮ǰ�ʹ�����Ψһ������󣬶���ģʽ�������ڽ���main����֮ǰ���Ѿ���������Ψһ�������
Singleton Singleton::m_Instance;