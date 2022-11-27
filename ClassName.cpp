
#include "ClassName.h"

#include "ClassNameImpl.h"

using namespace Namespace;

ClassName::ptr ClassName::Create ()
{
	return ClassNameImpl::Create();
}

ClassName::ptr ClassName::Create (cptr rhs)
{
	auto rhs2 = std::dynamic_pointer_cast<const ClassNameImpl, const ClassName>(rhs);
	return ClassNameImpl::Create(rhs2);
}
