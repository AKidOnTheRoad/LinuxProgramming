#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <initializer_list>

using  namespace std;

class strBlobPtr;

class strBlob {
	friend class strBlobPtr;
	public:
		typedef vector<string>::size_type size_type;
		strBlob();//构造函数
		strBlob(initializer_list<string> il);//重载构造函数
		size_type size() const { return data->size();}
		bool empty() const { return data->empty();}
		void push_back(const string &t) { data->push_back(t);}
		void pop_back();

		string &front();
		const string& front() const;
		string &back();
		const string& back() const;

		strBlobPtr begin();
		strBlobPtr end();

	private:
		shared_ptr<vector<string>> data;
		void check(size_type i, const string &msg) const;
};

strBlob::strBlob() : data(make_shared<vector<string>>()) { }

strBlob::strBlob(initializer_list<string> il) : 
	data(make_shared<vector<string>>(il)) { }

void strBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);

}
string & strBlob::front()
{
	check(0, "front on empty strBlob");
	return data->front();
}
const string& strBlob::front() const
{
	check(0, "front on empty strBlob");
	return data->front();
}

string & strBlob::back() 
{
	check(0, "back on empty strBlob");
	return data->back();
}


const string & strBlob::back() const
{
	check(0, "back on empty strBlob");
	return data->back();
}

void strBlob::pop_back()
{
	check(0, "pop_back on empty strBlob");
	return data->pop_back();
}

class strBlobPtr {
	friend bool eq(const strBlobPtr&, const strBlobPtr&);
	public:
		strBlobPtr() : curr(0) { }
		strBlobPtr(strBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
		
		string & deref() const;
		strBlobPtr& incr();
		strBlobPtr& decr();

	private:
		shared_ptr<vector<string>>
			check(size_t, const string&) const;

		weak_ptr<vector<string>> wptr;
		size_t curr;
};

shared_ptr<vector<string>> strBlobPtr::check(size_t i, const string &msg) const 
{
	auto ret = wptr.lock();

	if(!ret)
		throw runtime_error("unbound strBlobPtr");
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& strBlobPtr::deref() const 
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

strBlobPtr& strBlobPtr::incr()
{
	check(curr, "increment past end of strBlobPtr");
	++curr;
	return *this;
}

strBlobPtr& strBlobPtr::decr()
{
	--curr;
	check(-1, "decrement past end of strBlobPtr");
	return *this;
}

strBlobPtr strBlob::begin()
{
	return strBlobPtr(*this);
}

strBlobPtr strBlob::end()
{
	auto ret = strBlobPtr(*this, data->size());
	return ret;
}

bool eq(const strBlobPtr &lhs, const strBlobPtr &rhs) 
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();//shared_ptr 变量

	if(l == r)//判断两者是否相等
		return (!r || lhs.curr == rhs.curr);//下标是否一致
	else
		return false;
}

bool neq(const strBlobPtr &lhs, const strBlobPtr &rhs)
{
	return !eq(lhs, rhs);
}
#endif
