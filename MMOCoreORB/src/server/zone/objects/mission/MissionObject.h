/*
 *	server/zone/objects/mission/MissionObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef MISSIONOBJECT_H_
#define MISSIONOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject : public SceneObject {
public:
	MissionObject(LuaObject* templateData);

	void sendBaselinesTo(SceneObject* player);

protected:
	MissionObject(DummyConstructorParameter* param);

	virtual ~MissionObject();

	friend class MissionObjectHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObjectImplementation : public SceneObjectImplementation {

public:
	MissionObjectImplementation(LuaObject* templateData);

	MissionObjectImplementation(DummyConstructorParameter* param);

	void sendBaselinesTo(SceneObject* player);

	MissionObject* _this;

	operator const MissionObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~MissionObjectImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class MissionObject;
};

class MissionObjectAdapter : public SceneObjectAdapter {
public:
	MissionObjectAdapter(MissionObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendBaselinesTo(SceneObject* player);

};

class MissionObjectHelper : public DistributedObjectClassHelper, public Singleton<MissionObjectHelper> {
	static MissionObjectHelper* staticInitializer;

public:
	MissionObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<MissionObjectHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*MISSIONOBJECT_H_*/
