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
#include <Standard_UUID.hxx>

void bind_Standard_UUID(py::module &mod){

py::class_<_GUID, std::unique_ptr<_GUID>> cls_Standard_UUID(mod, "Standard_UUID", "None");

// Constructors

// Fields
cls_Standard_UUID.def_readwrite("Data1", &_GUID::Data1, "None");
cls_Standard_UUID.def_readwrite("Data2", &_GUID::Data2, "None");
cls_Standard_UUID.def_readwrite("Data3", &_GUID::Data3, "None");
// cls_Standard_UUID.def_readwrite("Data4", &_GUID::Data4, "None");

// Methods

// Enums

}