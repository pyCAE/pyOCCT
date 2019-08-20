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
#include <StepBasic_NamedUnit.hxx>
#include <Standard_Handle.hxx>
#include <StepBasic_DimensionalExponents.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepBasic_ConversionBasedUnit.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ConversionBasedUnit(py::module &mod){

py::class_<StepBasic_ConversionBasedUnit, opencascade::handle<StepBasic_ConversionBasedUnit>, StepBasic_NamedUnit> cls_StepBasic_ConversionBasedUnit(mod, "StepBasic_ConversionBasedUnit", "None");

// Constructors
cls_StepBasic_ConversionBasedUnit.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ConversionBasedUnit.def("Init", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<StepBasic_DimensionalExponents> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnit::Init, "None", py::arg("aDimensions"), py::arg("aName"), py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnit.def("SetName", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ConversionBasedUnit::SetName, "None", py::arg("aName"));
cls_StepBasic_ConversionBasedUnit.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ConversionBasedUnit::*)() const) &StepBasic_ConversionBasedUnit::Name, "None");
cls_StepBasic_ConversionBasedUnit.def("SetConversionFactor", (void (StepBasic_ConversionBasedUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepBasic_ConversionBasedUnit::SetConversionFactor, "None", py::arg("aConversionFactor"));
cls_StepBasic_ConversionBasedUnit.def("ConversionFactor", (opencascade::handle<StepBasic_MeasureWithUnit> (StepBasic_ConversionBasedUnit::*)() const) &StepBasic_ConversionBasedUnit::ConversionFactor, "None");
cls_StepBasic_ConversionBasedUnit.def_static("get_type_name_", (const char * (*)()) &StepBasic_ConversionBasedUnit::get_type_name, "None");
cls_StepBasic_ConversionBasedUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ConversionBasedUnit::get_type_descriptor, "None");
cls_StepBasic_ConversionBasedUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ConversionBasedUnit::*)() const) &StepBasic_ConversionBasedUnit::DynamicType, "None");

// Enums

}