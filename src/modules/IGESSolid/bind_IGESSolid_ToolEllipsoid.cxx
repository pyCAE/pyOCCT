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
#include <IGESSolid_Ellipsoid.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_ToolEllipsoid.hxx>

void bind_IGESSolid_ToolEllipsoid(py::module &mod){

py::class_<IGESSolid_ToolEllipsoid, std::unique_ptr<IGESSolid_ToolEllipsoid>> cls_IGESSolid_ToolEllipsoid(mod, "IGESSolid_ToolEllipsoid", "Tool to work on a Ellipsoid. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESSolid_ToolEllipsoid.def(py::init<>());

// Fields

// Methods
// cls_IGESSolid_ToolEllipsoid.def_static("operator new_", (void * (*)(size_t)) &IGESSolid_ToolEllipsoid::operator new, "None", py::arg("theSize"));
// cls_IGESSolid_ToolEllipsoid.def_static("operator delete_", (void (*)(void *)) &IGESSolid_ToolEllipsoid::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid_ToolEllipsoid.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid_ToolEllipsoid::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid_ToolEllipsoid.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid_ToolEllipsoid::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid_ToolEllipsoid.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid_ToolEllipsoid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid_ToolEllipsoid.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid_ToolEllipsoid::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid_ToolEllipsoid.def("ReadOwnParams", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESSolid_ToolEllipsoid::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESSolid_ToolEllipsoid.def("WriteOwnParams", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, IGESData_IGESWriter &) const) &IGESSolid_ToolEllipsoid::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESSolid_ToolEllipsoid.def("OwnShared", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, Interface_EntityIterator &) const) &IGESSolid_ToolEllipsoid::OwnShared, "Lists the Entities shared by a Ellipsoid <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESSolid_ToolEllipsoid.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &) const) &IGESSolid_ToolEllipsoid::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESSolid_ToolEllipsoid.def("OwnCheck", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESSolid_ToolEllipsoid::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESSolid_ToolEllipsoid.def("OwnCopy", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const opencascade::handle<IGESSolid_Ellipsoid> &, Interface_CopyTool &) const) &IGESSolid_ToolEllipsoid::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESSolid_ToolEllipsoid.def("OwnDump", (void (IGESSolid_ToolEllipsoid::*)(const opencascade::handle<IGESSolid_Ellipsoid> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSolid_ToolEllipsoid::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}