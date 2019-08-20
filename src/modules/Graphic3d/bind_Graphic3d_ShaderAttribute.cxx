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
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ShaderAttribute.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_ShaderAttribute(py::module &mod){

py::class_<Graphic3d_ShaderAttribute, opencascade::handle<Graphic3d_ShaderAttribute>, Standard_Transient> cls_Graphic3d_ShaderAttribute(mod, "Graphic3d_ShaderAttribute", "Describes custom vertex shader attribute.");

// Constructors
cls_Graphic3d_ShaderAttribute.def(py::init<const TCollection_AsciiString &, const int>(), py::arg("theName"), py::arg("theLocation"));

// Fields

// Methods
cls_Graphic3d_ShaderAttribute.def("Name", (const TCollection_AsciiString & (Graphic3d_ShaderAttribute::*)() const) &Graphic3d_ShaderAttribute::Name, "Returns name of shader variable.");
cls_Graphic3d_ShaderAttribute.def("Location", (int (Graphic3d_ShaderAttribute::*)() const) &Graphic3d_ShaderAttribute::Location, "Returns attribute location to be bound on GLSL program linkage stage.");
cls_Graphic3d_ShaderAttribute.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ShaderAttribute::get_type_name, "None");
cls_Graphic3d_ShaderAttribute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ShaderAttribute::get_type_descriptor, "None");
cls_Graphic3d_ShaderAttribute.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ShaderAttribute::*)() const) &Graphic3d_ShaderAttribute::DynamicType, "None");

// Enums

}