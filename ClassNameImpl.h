
#pragma once

#include "ClassName.h"

namespace Namespace {

class ClassNameImpl : public ClassName
{
public:
	using ptr		= std::shared_ptr<ClassNameImpl>;
	using cptr		= std::shared_ptr<const ClassNameImpl>;
	using wptr		= std::weak_ptr<ClassNameImpl>;
	using vector	= std::vector<ptr>;

	static ClassName::ptr Create ();
	static ClassName::ptr Create (ClassNameImpl::cptr rhs);

	virtual auto Prop1 () const -> int override;

	virtual void setProp1 (int val) override;

	virtual auto Prop2 () const -> int override;

	virtual void Method1 () override;

	virtual std::string to_string () const override;

protected:
	wptr _self;

	void _init();
	void _copy (ClassNameImpl::cptr rhs);
	void _update();

	int _prop1;
	int _prop2;

protected:
	class protected_token {}; /* exists to prevent public use of ctor */
						 	  /* we want the ctor to be public so we can use make_shared in Create()
							   * which reduces heap fragmentation */
public:
	ClassNameImpl() = delete;
	ClassNameImpl(protected_token) {}
	virtual ~ClassNameImpl () override = default;

	/* remove copy ctors and assignment */
	ClassNameImpl (const ClassNameImpl &) = delete;
	ClassNameImpl (ClassNameImpl &&) = delete;
	ClassNameImpl& operator= (const ClassNameImpl &) = delete;	
	ClassNameImpl& operator= (ClassNameImpl &&) = delete;	

};

#if 0
inline std::string to_string (const ClassNameImpl& rhs) 
{
	return rhs.to_string();
}

inline std::ostream& operator<< (std::ostream& os, const ClassNameImpl& rhs) 
{
	/* TODO: write object to ostream */
	return os;
}

inline std::ostream& operator<< (std::ostream& os, const ClassNameImpl::ptr rhs) 
{
	os << *rhs;
	return os;
}


inline std::istream& operator>> (std::istream& is, ClassNameImpl& rhs) 
{
	/* TODO: parse object from istream */
	return is;
}

inline std::istream& operator>> (std::istream& is, ClassNameImpl::ptr& rhs) 
{
	/* ptr passed to us is empty, allocate an actual object */
	//rhs = std::make_shared<ClassName>();
	//rhs = ClassName::Create();

	is >> *rhs;
	return is;
}
#endif

}

