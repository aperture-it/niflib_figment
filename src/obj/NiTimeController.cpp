/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiTimeController.h"
#include "../../include/obj/NiObjectNET.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTimeController::TYPE("NiTimeController", &NiObject::TYPE );

NiTimeController::NiTimeController() : nextController(NULL), flags((unsigned short)0), frequency(0.0f), phase(0.0f), startTime(0.0f), stopTime(0.0f), target(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiTimeController::~NiTimeController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiTimeController::GetType() const {
	return TYPE;
}

namespace Niflib {
	typedef NiObject*(*obj_factory_func)();
	extern map<string, obj_factory_func> global_object_map;

	//Initialization function
	static bool Initialization();

	//A static bool to force the initialization to happen pre-main
	static bool obj_initialized = Initialization();

	static bool Initialization() {
		//Add the function to the global object map
		global_object_map["NiTimeController"] = NiTimeController::Create;

		//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
		obj_initialized = true;
		return obj_initialized;
	}
}

NiObject * NiTimeController::Create() {
	return new NiTimeController;
}

void NiTimeController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( flags, in, info );
	NifStream( frequency, in, info );
	NifStream( phase, in, info );
	NifStream( startTime, in, info );
	NifStream( stopTime, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTimeController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, info );
	if ( nextController != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(nextController) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( flags, out, info );
	NifStream( frequency, out, info );
	NifStream( phase, out, info );
	NifStream( startTime, out, info );
	NifStream( stopTime, out, info );
	if ( target != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(target) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiTimeController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Next Controller:  " << nextController << endl;
	out << "  Flags:  " << flags << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Phase:  " << phase << endl;
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Target:  " << target << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiTimeController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, info );
	nextController = FixLink<NiTimeController>( objects, link_stack, info );
	target = FixLink<NiObjectNET>( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTimeController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextController != NULL )
		refs.push_back(StaticCast<NiObject>(nextController));
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

NiTimeControllerRef NiTimeController::GetNextController() const {
	return nextController;
}

void NiTimeController::SetNextController( const NiTimeControllerRef & obj ) {
	nextController = obj;
}

void NiTimeController::SetTarget( NiObjectNET * new_target ) {
	target = new_target;
}

Ref<NiObjectNET> NiTimeController::GetTarget() {
	return target;
}

unsigned short NiTimeController::GetFlags() const {
	return flags;
}

void NiTimeController::SetFlags( unsigned short n ) {
	flags = n;
}

float NiTimeController::GetFrequency() const {
	return frequency;
}

void NiTimeController::SetFrequency( float n ) {
	frequency = n;
}

float NiTimeController::GetPhase() const {
	return phase;
}

void NiTimeController::SetPhase( float n ) {
	phase = n;
}

float NiTimeController::GetStartTime() const {
	return startTime;
}

void NiTimeController::SetStartTime( float n ) {
	startTime = n;
}

float NiTimeController::GetStopTime() const {
	return stopTime;
}

void NiTimeController::SetStopTime( float n ) {
	stopTime = n;
}

//--END CUSTOM CODE--//
