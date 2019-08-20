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
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <BinXCAFDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>

void bind_BinXCAFDrivers_DocumentRetrievalDriver(py::module &mod){

py::class_<BinXCAFDrivers_DocumentRetrievalDriver, opencascade::handle<BinXCAFDrivers_DocumentRetrievalDriver>, BinDrivers_DocumentRetrievalDriver> cls_BinXCAFDrivers_DocumentRetrievalDriver(mod, "BinXCAFDrivers_DocumentRetrievalDriver", "None");

// Constructors
cls_BinXCAFDrivers_DocumentRetrievalDriver.def(py::init<>());

// Fields

// Methods
cls_BinXCAFDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinXCAFDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<Message_Messenger> &)) &BinXCAFDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
cls_BinXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinXCAFDrivers_DocumentRetrievalDriver::get_type_name, "None");
cls_BinXCAFDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinXCAFDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
cls_BinXCAFDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinXCAFDrivers_DocumentRetrievalDriver::*)() const) &BinXCAFDrivers_DocumentRetrievalDriver::DynamicType, "None");

// Enums

}