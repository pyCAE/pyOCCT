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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepShape_CsgSolid.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepShape_RWCsgSolid.hxx>

void bind_RWStepShape_RWCsgSolid(py::module &mod){

py::class_<RWStepShape_RWCsgSolid, std::unique_ptr<RWStepShape_RWCsgSolid>> cls_RWStepShape_RWCsgSolid(mod, "RWStepShape_RWCsgSolid", "Read & Write Module for CsgSolid");

// Constructors
cls_RWStepShape_RWCsgSolid.def(py::init<>());

// Fields

// Methods
// cls_RWStepShape_RWCsgSolid.def_static("operator new_", (void * (*)(size_t)) &RWStepShape_RWCsgSolid::operator new, "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete_", (void (*)(void *)) &RWStepShape_RWCsgSolid::operator delete, "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator new[]_", (void * (*)(size_t)) &RWStepShape_RWCsgSolid::operator new[], "None", py::arg("theSize"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete[]_", (void (*)(void *)) &RWStepShape_RWCsgSolid::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepShape_RWCsgSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepShape_RWCsgSolid.def_static("operator delete_", (void (*)(void *, void *)) &RWStepShape_RWCsgSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepShape_RWCsgSolid.def("ReadStep", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepShape_CsgSolid> &) const) &RWStepShape_RWCsgSolid::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepShape_RWCsgSolid.def("WriteStep", (void (RWStepShape_RWCsgSolid::*)(StepData_StepWriter &, const opencascade::handle<StepShape_CsgSolid> &) const) &RWStepShape_RWCsgSolid::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepShape_RWCsgSolid.def("Share", (void (RWStepShape_RWCsgSolid::*)(const opencascade::handle<StepShape_CsgSolid> &, Interface_EntityIterator &) const) &RWStepShape_RWCsgSolid::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}