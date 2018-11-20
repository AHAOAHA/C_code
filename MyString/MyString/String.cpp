#include "String.h"

const size_t AHAOAHA::String::npos = -1;

void AHAOAHA::String::Swap(AHAOAHA::String& s)
{
	char* tmpstr = _str;
	_str = s._str;
	s._str = tmpstr;

	size_t tmpsize = _size;
	_size = s._size;
	s._size = tmpsize;

	size_t tmpcapacity = _capacity;
	_capacity = s._capacity;
	s._capacity = _capacity;
}

void AHAOAHA::String::reserve(const size_t capacity)
{
	if (capacity > _capacity)
	{
		_capacity = capacity;
		char* newstr = new char[capacity + 1];
		strcpy(newstr, _str);
		delete _str;
		_str = newstr;
	}
}

void AHAOAHA::String::resize(const size_t size)
{
	if (size > _capacity)
	{
		reserve(size);
		_size = size;
	}
	else
	{
		if(size < _size)
		{
			_str[size] = '\0';
		}
		_size = size;
	}
}

AHAOAHA::String& AHAOAHA::String::operator=(const AHAOAHA::String& s)
{
	AHAOAHA::String tmp(s);
	this->Swap(tmp);
	return *this;
}

AHAOAHA::String& AHAOAHA::String::operator=(const char* pstr)
{
	AHAOAHA::String tmp(pstr);
	this->Swap(tmp);
	return *this;
}

AHAOAHA::String& AHAOAHA::String::operator=(const char ch)
{
	AHAOAHA::String tmp(ch);
	this->Swap(tmp);
	return *this;
}

AHAOAHA::String& AHAOAHA::String::append(const String& s)
{
	*this += s;

	return *this;
}

AHAOAHA::String& AHAOAHA::String::append(const char* pstr)
{
	AHAOAHA::String tmp(pstr);
	this->append(tmp);
	return *this;
}

void AHAOAHA::String::push_back(const char ch)
{
	if (_size >= _capacity)
	{
		this->reserve(_capacity * 2);
	}

	_str[_size + 1] = '\0';
	_str[_size] = ch;
	_size += 1;
}

char& AHAOAHA::String::operator[](size_t pos)
{
	assert(pos <= _size);
	return _str[pos];
}

const char& AHAOAHA::String::operator[](size_t pos)const
{
	assert(pos <= _size);
	return _str[pos];
}

AHAOAHA::String& AHAOAHA::String::insert(size_t pos, const String& s)
{
	assert(pos < _size);
	String tmp(_str + pos);
	_size += s._size;
	if (_size > _capacity)
	{
		this->reserve(_size);
	}

	strcpy(_str + pos, s._str);

	strcpy(_str + pos + s._size, tmp._str);

	return *this;
}

AHAOAHA::String& AHAOAHA::String::erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (len >= (_size - pos))
	{
		(*this)[pos] = '\0';
		_size -= (_size - pos);
		return *this;
	}
	
	String tmp(_str + pos + len);

	strcpy(_str + pos, tmp._str);

	_size -= len;

	return *this;
}

const bool AHAOAHA::String::empty()const
{
	return _size == _capacity;
}

size_t AHAOAHA::String::find(const String& s, size_t pos)const
{
	return find(s._str, pos);
}

size_t AHAOAHA::String::find(const char ch, size_t pos)const
{
	size_t start = 0;
	while (start < _size)
	{
		if ((*this)[start] == ch)
			return start;
		start++;
	}

	return -1;
}

size_t AHAOAHA::String::find(const char *s, size_t pos)const
{
	size_t begin = pos;

	while (begin < _size)
	{
		if(_str[begin] == s[0])
		{
			size_t start = 0;
			while (start < strlen(s))
			{
				if (_str[begin+start] != s[start])
					break;
				start++;
			}
			if (start == strlen(s))
				return begin;
		}
		begin++;
	}
	return -1;
}

size_t AHAOAHA::String::rfind(const String& s, size_t pos)const
{
	return 0;
}

AHAOAHA::String& AHAOAHA::String::operator+=(const AHAOAHA::String& s)
{
	size_t tmp_size = _size;
	_size += s._size;
	if (_size < _capacity)
	{
		this->reserve(_size);
	}

	strcpy(_str + tmp_size, s._str);
	return *this;
}
AHAOAHA::String& AHAOAHA::String::operator+=(const char* pstr)
{
	AHAOAHA::String tmp(pstr);
	return (*this) += tmp;
}
AHAOAHA::String& AHAOAHA::String::operator+=(const char ch)
{
	push_back(ch);
	return *this;
}

std::ostream& AHAOAHA::operator<<(std::ostream& out, const AHAOAHA::String& s)
{
	out << s._str;
	return out;
}
std::istream& AHAOAHA::operator>>(std::istream& in, const AHAOAHA::String& s)
{
	in >> s._str;
	return in;
}

AHAOAHA::String AHAOAHA::String::Substr(size_t pos, size_t len)
{
	assert(pos < _size);
	String tmp;
	size_t lentmp = 0;

	if (len > (_size - pos))
	{
		len = _size - pos;
	}
	while(lentmp++ != len)
	{
		tmp += _str[pos];
		pos += 1;
	}
	return tmp;
}