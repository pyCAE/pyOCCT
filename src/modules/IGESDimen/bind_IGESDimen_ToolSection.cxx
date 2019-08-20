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
#include <IGESDimen_Section.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESDimen_ToolSection.hxx>

void bind_IGESDimen_ToolSection(py::module &mod){

py::class_<IGESDimen_ToolSection, std::unique_ptr<IGESDimen_ToolSection>> cls_IGESDimen_ToolSection(mod, "IGESDimen_ToolSection", "Tool to work on a Section. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolSection.def(py::init<>());

// Fields

// Methods
// cls_IGESDimen_ToolSection.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolSection::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolSection.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolSection::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolSection::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolSection.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolSection::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolSection.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolSection::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolSection.def("ReadOwnParams", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolSection::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolSection.def("WriteOwnParams", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, IGESData_IGESWriter &) const) &IGESDimen_ToolSection::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolSection.def("OwnShared", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, Interface_EntityIterator &) const) &IGESDimen_ToolSection::OwnShared, "Lists the Entities shared by a Section <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolSection.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &) const) &IGESDimen_ToolSection::OwnCorrect, "Sets automatic unambiguous Correction on a Section (LineFont forced to Rank = 1, DataType forced to 1)", py::arg("ent"));
cls_IGESDimen_ToolSection.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &) const) &IGESDimen_ToolSection::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolSection.def("OwnCheck", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolSection::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolSection.def("OwnCopy", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const opencascade::handle<IGESDimen_Section> &, Interface_CopyTool &) const) &IGESDimen_ToolSection::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolSection.def("OwnDump", (void (IGESDimen_ToolSection::*)(const opencascade::handle<IGESDimen_Section> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolSection::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}