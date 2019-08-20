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
#include <Geom2dGcc_QCurve.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dGcc_Circ2dTanCenGeo.hxx>

void bind_Geom2dGcc_Circ2dTanCenGeo(py::module &mod){

py::class_<Geom2dGcc_Circ2dTanCenGeo, std::unique_ptr<Geom2dGcc_Circ2dTanCenGeo>> cls_Geom2dGcc_Circ2dTanCenGeo(mod, "Geom2dGcc_Circ2dTanCenGeo", "This class implements the algorithms used to create 2d circles tangent to a curve and centered on a point. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCurv). -The center point Pcenter. - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an EnclosedCurv C1 with a tolerance Tolerance. If we did not use Tolerance it is impossible to find a solution in the following case : Pcenter is outside C1. With Tolerance we will give a solution if the distance between C1 and Pcenter is lower than or equal Tolerance/2.");

// Constructors
cls_Geom2dGcc_Circ2dTanCenGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Pcenter"), py::arg("Tolerance"));

// Fields

// Methods
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCenGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCenGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanCenGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanCenGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanCenGeo::*)() const) &Geom2dGcc_Circ2dTanCenGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2dTanCenGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanCenGeo::*)() const) &Geom2dGcc_Circ2dTanCenGeo::NbSolutions, "Returns the number of solutions and raises NotDone exception if the algorithm didn't succeed. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2dTanCenGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanCenGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanCenGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions or less than zero.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanCenGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanCenGeo::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanCenGeo::WhichQualifier, "None", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanCenGeo.def("Tangency1", [](Geom2dGcc_Circ2dTanCenGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntArg on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions or less than zero.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// Enums

}