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
#include <GeomFill_TrihedronLaw.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_Fixed.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_Fixed(py::module &mod){

py::class_<GeomFill_Fixed, opencascade::handle<GeomFill_Fixed>, GeomFill_TrihedronLaw> cls_GeomFill_Fixed(mod, "GeomFill_Fixed", "Defined an constant TrihedronLaw");

// Constructors
cls_GeomFill_Fixed.def(py::init<const gp_Vec &, const gp_Vec &>(), py::arg("Tangent"), py::arg("Normal"));

// Fields

// Methods
cls_GeomFill_Fixed.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_Fixed::*)() const) &GeomFill_Fixed::Copy, "None");
cls_GeomFill_Fixed.def("D0", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_Fixed.def("D1", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_Fixed.def("D2", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_Fixed.def("NbIntervals", (Standard_Integer (GeomFill_Fixed::*)(const GeomAbs_Shape) const) &GeomFill_Fixed::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_Fixed.def("Intervals", (void (GeomFill_Fixed::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_Fixed::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_Fixed.def("GetAverageLaw", (void (GeomFill_Fixed::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_Fixed.def("IsConstant", (Standard_Boolean (GeomFill_Fixed::*)() const) &GeomFill_Fixed::IsConstant, "Return True.");
cls_GeomFill_Fixed.def_static("get_type_name_", (const char * (*)()) &GeomFill_Fixed::get_type_name, "None");
cls_GeomFill_Fixed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Fixed::get_type_descriptor, "None");
cls_GeomFill_Fixed.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Fixed::*)() const) &GeomFill_Fixed::DynamicType, "None");

// Enums

}