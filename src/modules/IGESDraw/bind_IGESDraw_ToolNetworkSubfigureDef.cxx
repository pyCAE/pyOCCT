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
#include <IGESDraw_NetworkSubfigureDef.hxx>
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
#include <IGESDraw_ToolNetworkSubfigureDef.hxx>

void bind_IGESDraw_ToolNetworkSubfigureDef(py::module &mod){

py::class_<IGESDraw_ToolNetworkSubfigureDef, std::unique_ptr<IGESDraw_ToolNetworkSubfigureDef>> cls_IGESDraw_ToolNetworkSubfigureDef(mod, "IGESDraw_ToolNetworkSubfigureDef", "Tool to work on a NetworkSubfigureDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolNetworkSubfigureDef.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolNetworkSubfigureDef::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolNetworkSubfigureDef::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolNetworkSubfigureDef::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolNetworkSubfigureDef::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolNetworkSubfigureDef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolNetworkSubfigureDef.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolNetworkSubfigureDef::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolNetworkSubfigureDef.def("ReadOwnParams", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolNetworkSubfigureDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("WriteOwnParams", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, IGESData_IGESWriter &) const) &IGESDraw_ToolNetworkSubfigureDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("OwnShared", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, Interface_EntityIterator &) const) &IGESDraw_ToolNetworkSubfigureDef::OwnShared, "Lists the Entities shared by a NetworkSubfigureDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &) const) &IGESDraw_ToolNetworkSubfigureDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("OwnCheck", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolNetworkSubfigureDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("OwnCopy", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, Interface_CopyTool &) const) &IGESDraw_ToolNetworkSubfigureDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolNetworkSubfigureDef.def("OwnDump", (void (IGESDraw_ToolNetworkSubfigureDef::*)(const opencascade::handle<IGESDraw_NetworkSubfigureDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolNetworkSubfigureDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}