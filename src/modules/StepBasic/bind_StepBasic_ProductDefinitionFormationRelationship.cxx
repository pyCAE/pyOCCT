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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepBasic_ProductDefinitionFormationRelationship.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_ProductDefinitionFormationRelationship(py::module &mod){

py::class_<StepBasic_ProductDefinitionFormationRelationship, opencascade::handle<StepBasic_ProductDefinitionFormationRelationship>, Standard_Transient> cls_StepBasic_ProductDefinitionFormationRelationship(mod, "StepBasic_ProductDefinitionFormationRelationship", "Representation of STEP entity ProductDefinitionFormationRelationship");

// Constructors
cls_StepBasic_ProductDefinitionFormationRelationship.def(py::init<>());

// Fields

// Methods
cls_StepBasic_ProductDefinitionFormationRelationship.def("Init", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &, const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("aDescription"), py::arg("aRelatingProductDefinitionFormation"), py::arg("aRelatedProductDefinitionFormation"));
cls_StepBasic_ProductDefinitionFormationRelationship.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::Id, "Returns field Id");
cls_StepBasic_ProductDefinitionFormationRelationship.def("SetId", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetId, "Set field Id", py::arg("Id"));
cls_StepBasic_ProductDefinitionFormationRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::Name, "Returns field Name");
cls_StepBasic_ProductDefinitionFormationRelationship.def("SetName", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepBasic_ProductDefinitionFormationRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::Description, "Returns field Description");
cls_StepBasic_ProductDefinitionFormationRelationship.def("SetDescription", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepBasic_ProductDefinitionFormationRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepBasic_ProductDefinitionFormationRelationship.def("RelatingProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::RelatingProductDefinitionFormation, "Returns field RelatingProductDefinitionFormation");
cls_StepBasic_ProductDefinitionFormationRelationship.def("SetRelatingProductDefinitionFormation", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::SetRelatingProductDefinitionFormation, "Set field RelatingProductDefinitionFormation", py::arg("RelatingProductDefinitionFormation"));
cls_StepBasic_ProductDefinitionFormationRelationship.def("RelatedProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::RelatedProductDefinitionFormation, "Returns field RelatedProductDefinitionFormation");
cls_StepBasic_ProductDefinitionFormationRelationship.def("SetRelatedProductDefinitionFormation", (void (StepBasic_ProductDefinitionFormationRelationship::*)(const opencascade::handle<StepBasic_ProductDefinitionFormation> &)) &StepBasic_ProductDefinitionFormationRelationship::SetRelatedProductDefinitionFormation, "Set field RelatedProductDefinitionFormation", py::arg("RelatedProductDefinitionFormation"));
cls_StepBasic_ProductDefinitionFormationRelationship.def_static("get_type_name_", (const char * (*)()) &StepBasic_ProductDefinitionFormationRelationship::get_type_name, "None");
cls_StepBasic_ProductDefinitionFormationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_ProductDefinitionFormationRelationship::get_type_descriptor, "None");
cls_StepBasic_ProductDefinitionFormationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_ProductDefinitionFormationRelationship::*)() const) &StepBasic_ProductDefinitionFormationRelationship::DynamicType, "None");

// Enums

}