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

void bind_XmlTObjDrivers(py::module &);
void bind_XmlTObjDrivers_DocumentRetrievalDriver(py::module &);
void bind_XmlTObjDrivers_DocumentStorageDriver(py::module &);
void bind_XmlTObjDrivers_IntSparseArrayDriver(py::module &);
void bind_XmlTObjDrivers_ModelDriver(py::module &);
void bind_XmlTObjDrivers_ObjectDriver(py::module &);
void bind_XmlTObjDrivers_ReferenceDriver(py::module &);
void bind_XmlTObjDrivers_XYZDriver(py::module &);

PYBIND11_MODULE(XmlTObjDrivers, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.XmlMDF");
py::module::import("OCCT.Message");
py::module::import("OCCT.XmlLDrivers");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDF");
py::module::import("OCCT.XmlObjMgt");

bind_XmlTObjDrivers(mod);
bind_XmlTObjDrivers_DocumentRetrievalDriver(mod);
bind_XmlTObjDrivers_DocumentStorageDriver(mod);
bind_XmlTObjDrivers_IntSparseArrayDriver(mod);
bind_XmlTObjDrivers_ModelDriver(mod);
bind_XmlTObjDrivers_ObjectDriver(mod);
bind_XmlTObjDrivers_ReferenceDriver(mod);
bind_XmlTObjDrivers_XYZDriver(mod);

}