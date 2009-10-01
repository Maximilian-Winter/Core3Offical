/*
 *	server/zone/objects/cell/CellObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "CellObject.h"

/*
 *	CellObjectStub
 */

CellObject::CellObject(LuaObject* templateData) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new CellObjectImplementation(templateData);
	_impl->_setStub(this);
	_impl->_setClassHelper(CellObjectHelper::instance());

	((CellObjectImplementation*) _impl)->_serializationHelperMethod();
}

CellObject::CellObject(DummyConstructorParameter* param) : SceneObject(param) {
}

CellObject::~CellObject() {
}

void CellObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->sendBaselinesTo(player);
}

int CellObject::getCellNumber() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return ((CellObjectImplementation*) _impl)->getCellNumber();
}

void CellObject::setCellNumber(int number) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addSignedIntParameter(number);

		method.executeWithVoidReturn();
	} else
		((CellObjectImplementation*) _impl)->setCellNumber(number);
}

/*
 *	CellObjectImplementation
 */

CellObjectImplementation::CellObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_classHelper = CellObjectHelper::instance();
}

CellObjectImplementation::~CellObjectImplementation() {
}

void CellObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CellObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CellObjectImplementation::_getStub() {
	return _this;
}

CellObjectImplementation::operator const CellObject*() {
	return _this;
}

void CellObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CellObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CellObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CellObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CellObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CellObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CellObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CellObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("CellObject");

	addSerializableVariable("cellNumber", &cellNumber);
}

int CellObjectImplementation::getCellNumber() {
	// server/zone/objects/cell/CellObject.idl(80):  return cellNumber;
	return cellNumber;
}

void CellObjectImplementation::setCellNumber(int number) {
	// server/zone/objects/cell/CellObject.idl(84):  cellNumber = number;
	cellNumber = number;
}

/*
 *	CellObjectAdapter
 */

CellObjectAdapter::CellObjectAdapter(CellObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* CellObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		resp->insertSignedInt(getCellNumber());
		break;
	case 8:
		setCellNumber(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CellObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((CellObjectImplementation*) impl)->sendBaselinesTo(player);
}

int CellObjectAdapter::getCellNumber() {
	return ((CellObjectImplementation*) impl)->getCellNumber();
}

void CellObjectAdapter::setCellNumber(int number) {
	((CellObjectImplementation*) impl)->setCellNumber(number);
}

/*
 *	CellObjectHelper
 */

CellObjectHelper* CellObjectHelper::staticInitializer = CellObjectHelper::instance();

CellObjectHelper::CellObjectHelper() {
	className = "CellObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CellObjectHelper::finalizeHelper() {
	CellObjectHelper::finalize();
}

DistributedObject* CellObjectHelper::instantiateObject() {
	return new CellObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* CellObjectHelper::instantiateServant() {
	return new CellObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CellObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CellObjectAdapter((CellObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

