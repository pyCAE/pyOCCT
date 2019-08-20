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
#include <StepBasic_SiUnit.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnitName.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_MassUnit.hxx>
#include <StepBasic_SiUnitAndMassUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_SiUnitAndMassUnit(py::module &mod){

py::class_<StepBasic_SiUnitAndMassUnit, opencascade::handle<StepBasic_SiUnitAndMassUnit>, StepBasic_SiUnit> cls_StepBasic_SiUnitAndMassUnit(mod, "StepBasic_SiUnitAndMassUnit", "None");

// Constructors
cls_StepBasic_SiUnitAndMassUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_SiUnitAndMassUnit.def("Init", (void (StepBasic_SiUnitAndMassUnit::*)(const Standard_Boolean, const StepBasic_SiPrefix, const StepBasic_SiUnitName)) &StepBasic_SiUnitAndMassUnit::Init, "None", py::arg("hasAprefix"), py::arg("aPrefix"), py::arg("aName"));
cls_StepBasic_SiUnitAndMassUnit.def("SetMassUnit", (void (StepBasic_SiUnitAndMassUnit::*)(const opencascade::handle<StepBasic_MassUnit> &)) &StepBasic_SiUnitAndMassUnit::SetMassUnit, "None", py::arg("aMassUnit"));
cls_StepBasic_SiUnitAndMassUnit.def("MassUnit", (opencascade::handle<StepBasic_MassUnit> (StepBasic_SiUnitAndMassUnit::*)() const) &StepBasic_SiUnitAndMassUnit::MassUnit, "None");
cls_StepBasic_SiUnitAndMassUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_SiUnitAndMassUnit::get_type_name, "None");
cls_StepBasic_SiUnitAndMassUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_SiUnitAndMassUnit::get_type_descriptor, "None");
cls_StepBasic_SiUnitAndMassUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_SiUnitAndMassUnit::*)() const) &StepBasic_SiUnitAndMassUnit::DynamicType, "None");

// Enums

}