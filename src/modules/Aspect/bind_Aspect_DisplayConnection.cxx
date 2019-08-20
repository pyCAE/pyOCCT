/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_Aspect_DisplayConnection(py::module &mod){

py::class_<Aspect_DisplayConnection, opencascade::handle<Aspect_DisplayConnection>, Standard_Transient> cls_Aspect_DisplayConnection(mod, "Aspect_DisplayConnection", "This class creates and provides connection with X server. Raises exception if can not connect to X server. On Windows and Mac OS X (in case when Cocoa used) platforms this class do nothing. WARRNING: Do not close display connection manualy!");

// Constructors
cls_Aspect_DisplayConnection.def(py::init<>());

// Fields

// Methods
cls_Aspect_DisplayConnection.def_static("get_type_name_", (const char * (*)()) &Aspect_DisplayConnection::get_type_name, "None");
cls_Aspect_DisplayConnection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_DisplayConnection::get_type_descriptor, "None");
cls_Aspect_DisplayConnection.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_DisplayConnection::*)() const) &Aspect_DisplayConnection::DynamicType, "None");

// Enums

}