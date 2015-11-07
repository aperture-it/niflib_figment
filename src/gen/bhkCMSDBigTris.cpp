/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/bhkCMSDBigTris.h"
using namespace Niflib;

//Constructor
bhkCMSDBigTris::bhkCMSDBigTris() : triangle1((unsigned short)0), triangle2((unsigned short)0), triangle3((unsigned short)0), material((unsigned int)0), weldingInfo((unsigned short)0) {};

//Copy Constructor
bhkCMSDBigTris::bhkCMSDBigTris( const bhkCMSDBigTris & src ) {
	*this = src;
};

//Copy Operator
bhkCMSDBigTris & bhkCMSDBigTris::operator=( const bhkCMSDBigTris & src ) {
	this->triangle1 = src.triangle1;
	this->triangle2 = src.triangle2;
	this->triangle3 = src.triangle3;
	this->material = src.material;
	this->weldingInfo = src.weldingInfo;
	return *this;
};

//Destructor
bhkCMSDBigTris::~bhkCMSDBigTris() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
