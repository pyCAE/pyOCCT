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
#include <Geom_BSplineCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_Curve.hxx>
#include <Convert_ParameterisationType.hxx>
#include <Geom_Surface.hxx>
#include <TColGeom_Array1OfBSplineCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColGeom_HArray1OfBSplineCurve.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <GeomConvert_BSplineCurveKnotSplitting.hxx>
#include <GeomConvert_BSplineSurfaceKnotSplitting.hxx>
#include <GeomConvert_BSplineCurveToBezierCurve.hxx>
#include <GeomConvert_CompCurveToBSplineCurve.hxx>
#include <GeomConvert_BSplineSurfaceToBezierSurface.hxx>
#include <GeomConvert_CompBezierSurfacesToBSplineSurface.hxx>
#include <GeomConvert_ApproxSurface.hxx>
#include <GeomConvert_ApproxCurve.hxx>
#include <GeomConvert.hxx>

void bind_GeomConvert(py::module &mod){

py::class_<GeomConvert, std::unique_ptr<GeomConvert>> cls_GeomConvert(mod, "GeomConvert", "The GeomConvert package provides some global functions as follows - converting classical Geom curves into BSpline curves, - segmenting BSpline curves, particularly at knots values: this function may be used in conjunction with the GeomConvert_BSplineCurveKnotSplitting class to segment a BSpline curve into arcs which comply with required continuity levels, - converting classical Geom surfaces into BSpline surfaces, and - segmenting BSpline surfaces, particularly at knots values: this function may be used in conjunction with the GeomConvert_BSplineSurfaceKnotSplitting class to segment a BSpline surface into patches which comply with required continuity levels. All geometric entities used in this package are bounded.");

// Constructors

// Fields

// Methods
// cls_GeomConvert.def_static("operator new_", (void * (*)(size_t)) &GeomConvert::operator new, "None", py::arg("theSize"));
// cls_GeomConvert.def_static("operator delete_", (void (*)(void *)) &GeomConvert::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert.def_static("SplitBSplineCurve_", [](const opencascade::handle<Geom_BSplineCurve> & a0, const Standard_Integer a1, const Standard_Integer a2) -> opencascade::handle<Geom_BSplineCurve> { return GeomConvert::SplitBSplineCurve(a0, a1, a2); });
cls_GeomConvert.def_static("SplitBSplineCurve_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &GeomConvert::SplitBSplineCurve, "Convert a curve from Geom by an approximation method", py::arg("C"), py::arg("FromK1"), py::arg("ToK2"), py::arg("SameOrientation"));
cls_GeomConvert.def_static("SplitBSplineCurve_", [](const opencascade::handle<Geom_BSplineCurve> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> opencascade::handle<Geom_BSplineCurve> { return GeomConvert::SplitBSplineCurve(a0, a1, a2, a3); });
cls_GeomConvert.def_static("SplitBSplineCurve_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomConvert::SplitBSplineCurve, "This function computes the segment of B-spline curve between the parametric values FromU1, ToU2. If C is periodic the arc has the same orientation as C if SameOrientation = True. If C is not periodic SameOrientation is not used for the computation and C is oriented fromU1 toU2. If U1 and U2 and two parametric values we consider that U1 = U2 if Abs (U1 - U2) <= ParametricTolerance and ParametricTolerance must be greater or equal to Resolution from package gp.", py::arg("C"), py::arg("FromU1"), py::arg("ToU2"), py::arg("ParametricTolerance"), py::arg("SameOrientation"));
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3, a4); });
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Boolean a5) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3, a4, a5); });
cls_GeomConvert.def_static("SplitBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean)) &GeomConvert::SplitBSplineSurface, "Computes the B-spline surface patche between the knots values FromUK1, ToUK2, FromVK1, ToVK2. If S is periodic in one direction the patche has the same orientation as S in this direction if the flag is true in this direction (SameUOrientation, SameVOrientation). If S is not periodic SameUOrientation and SameVOrientation are not used for the computation and S is oriented FromUK1 ToUK2 and FromVK1 ToVK2. Raised if FromUK1 = ToUK2 or FromVK1 = ToVK2 FromUK1 or ToUK2 are out of the bounds [FirstUKnotIndex, LastUKnotIndex] FromVK1 or ToVK2 are out of the bounds [FirstVKnotIndex, LastVKnotIndex]", py::arg("S"), py::arg("FromUK1"), py::arg("ToUK2"), py::arg("FromVK1"), py::arg("ToVK2"), py::arg("SameUOrientation"), py::arg("SameVOrientation"));
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Boolean a3) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3); });
cls_GeomConvert.def_static("SplitBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean)) &GeomConvert::SplitBSplineSurface, "This method splits a B-spline surface patche between the knots values FromK1, ToK2 in one direction. If USplit = True then the splitting direction is the U parametric direction else it is the V parametric direction. If S is periodic in the considered direction the patche has the same orientation as S in this direction if SameOrientation is True If S is not periodic in this direction SameOrientation is not used for the computation and S is oriented FromK1 ToK2. Raised if FromK1 = ToK2 or if FromK1 or ToK2 are out of the bounds [FirstUKnotIndex, LastUKnotIndex] in the considered parametric direction.", py::arg("S"), py::arg("FromK1"), py::arg("ToK2"), py::arg("USplit"), py::arg("SameOrientation"));
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3, a4, a5); });
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomConvert.def_static("SplitBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &GeomConvert::SplitBSplineSurface, "This method computes the B-spline surface patche between the parametric values FromU1, ToU2, FromV1, ToV2. If S is periodic in one direction the patche has the same orientation as S in this direction if the flag is True in this direction (SameUOrientation, SameVOrientation). If S is not periodic SameUOrientation and SameVOrientation are not used for the computation and S is oriented FromU1 ToU2 and FromV1 ToV2. If U1 and U2 and two parametric values we consider that U1 = U2 if Abs (U1 - U2) <= ParametricTolerance and ParametricTolerance must be greater or equal to Resolution from package gp.", py::arg("S"), py::arg("FromU1"), py::arg("ToU2"), py::arg("FromV1"), py::arg("ToV2"), py::arg("ParametricTolerance"), py::arg("SameUOrientation"), py::arg("SameVOrientation"));
cls_GeomConvert.def_static("SplitBSplineSurface_", [](const opencascade::handle<Geom_BSplineSurface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Boolean a3, const Standard_Real a4) -> opencascade::handle<Geom_BSplineSurface> { return GeomConvert::SplitBSplineSurface(a0, a1, a2, a3, a4); });
cls_GeomConvert.def_static("SplitBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean)) &GeomConvert::SplitBSplineSurface, "This method splits the B-spline surface S in one direction between the parametric values FromParam1, ToParam2. If USplit = True then the Splitting direction is the U parametric direction else it is the V parametric direction. If S is periodic in the considered direction the patche has the same orientation as S in this direction if SameOrientation is true. If S is not periodic in the considered direction SameOrientation is not used for the computation and S is oriented FromParam1 ToParam2. If U1 and U2 and two parametric values we consider that U1 = U2 if Abs (U1 - U2) <= ParametricTolerance and ParametricTolerance must be greater or equal to Resolution from package gp.", py::arg("S"), py::arg("FromParam1"), py::arg("ToParam2"), py::arg("USplit"), py::arg("ParametricTolerance"), py::arg("SameOrientation"));
cls_GeomConvert.def_static("CurveToBSplineCurve_", [](const opencascade::handle<Geom_Curve> & a0) -> opencascade::handle<Geom_BSplineCurve> { return GeomConvert::CurveToBSplineCurve(a0); });
cls_GeomConvert.def_static("CurveToBSplineCurve_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Geom_Curve> &, const Convert_ParameterisationType)) &GeomConvert::CurveToBSplineCurve, "This function converts a non infinite curve from Geom into a B-spline curve. C must be an ellipse or a circle or a trimmed conic or a trimmed line or a Bezier curve or a trimmed Bezier curve or a BSpline curve or a trimmed BSpline curve or an OffsetCurve. The returned B-spline is not periodic except if C is a Circle or an Ellipse. If the Parameterisation is QuasiAngular than the returned curve is NOT periodic in case a periodic Geom_Circle or Geom_Ellipse. For TgtThetaOver2_1 and TgtThetaOver2_2 the method raises an exception in case of a periodic Geom_Circle or a Geom_Ellipse ParameterisationType applies only if the curve is a Circle or an ellipse : TgtThetaOver2, -- TgtThetaOver2_1, -- TgtThetaOver2_2, -- TgtThetaOver2_3, -- TgtThetaOver2_4,", py::arg("C"), py::arg("Parameterisation"));
cls_GeomConvert.def_static("SurfaceToBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_Surface> &)) &GeomConvert::SurfaceToBSplineSurface, "This algorithm converts a non infinite surface from Geom into a B-spline surface. S must be a trimmed plane or a trimmed cylinder or a trimmed cone or a trimmed sphere or a trimmed torus or a sphere or a torus or a Bezier surface of a trimmed Bezier surface or a trimmed swept surface with a corresponding basis curve which can be turned into a B-spline curve (see the method CurveToBSplineCurve). Raises DomainError if the type of the surface is not previously defined.", py::arg("S"));
cls_GeomConvert.def_static("ConcatG1_", (void (*)(TColGeom_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColGeom_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real)) &GeomConvert::ConcatG1, "This Method concatenates G1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedG1 indicates if the ArrayOfCurves is closed. In this case ClosedG1 contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfConcatenated"), py::arg("ClosedG1Flag"), py::arg("ClosedTolerance"));
cls_GeomConvert.def_static("ConcatC1_", (void (*)(TColGeom_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfInteger> &, opencascade::handle<TColGeom_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real)) &GeomConvert::ConcatC1, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedG1 indicates if the ArrayOfCurves is closed. In this case ClosedG1 contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedG1Flag"), py::arg("ClosedTolerance"));
cls_GeomConvert.def_static("ConcatC1_", (void (*)(TColGeom_Array1OfBSplineCurve &, const TColStd_Array1OfReal &, opencascade::handle<TColStd_HArray1OfInteger> &, opencascade::handle<TColGeom_HArray1OfBSplineCurve> &, const Standard_Boolean, const Standard_Real, const Standard_Real)) &GeomConvert::ConcatC1, "This Method concatenates C1 the ArrayOfCurves as far as it is possible. ArrayOfCurves[0..N-1] ArrayOfToler contains the biggest tolerance of the two points shared by two consecutives curves. Its dimension: [0..N-2] ClosedG1 indicates if the ArrayOfCurves is closed. In this case ClosedG1 contains the biggest tolerance of the two points which are at the closure. Otherwise its value is 0.0", py::arg("ArrayOfCurves"), py::arg("ArrayOfToler"), py::arg("ArrayOfIndices"), py::arg("ArrayOfConcatenated"), py::arg("ClosedG1Flag"), py::arg("ClosedTolerance"), py::arg("AngularTolerance"));
cls_GeomConvert.def_static("C0BSplineToC1BSplineCurve_", [](opencascade::handle<Geom_BSplineCurve> & a0, const Standard_Real a1) -> void { return GeomConvert::C0BSplineToC1BSplineCurve(a0, a1); });
cls_GeomConvert.def_static("C0BSplineToC1BSplineCurve_", (void (*)(opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real)) &GeomConvert::C0BSplineToC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns a new BSpline which could still be C0. tolerance is a geometrical tolerance. The Angular toleranceis in radians and mesures the angle of the tangents on the left and on the right to decide if the curve is G1 or not at a given point", py::arg("BS"), py::arg("tolerance"), py::arg("AngularTolerance"));
cls_GeomConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom_BSplineCurve> &, opencascade::handle<TColGeom_HArray1OfBSplineCurve> &, const Standard_Real)) &GeomConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. tolerance is a geometrical tolerance.", py::arg("BS"), py::arg("tabBS"), py::arg("tolerance"));
cls_GeomConvert.def_static("C0BSplineToArrayOfC1BSplineCurve_", (void (*)(const opencascade::handle<Geom_BSplineCurve> &, opencascade::handle<TColGeom_HArray1OfBSplineCurve> &, const Standard_Real, const Standard_Real)) &GeomConvert::C0BSplineToArrayOfC1BSplineCurve, "This Method reduces as far as it is possible the multiplicities of the knots of the BSpline BS.(keeping the geometry). It returns an array of BSpline C1. tolerance is a geometrical tolerance : it allows for the maximum deformation The Angular tolerance is in radians and mesures the angle of the tangents on the left and on the right to decide if the curve is C1 or not at a given point", py::arg("BS"), py::arg("tabBS"), py::arg("AngularTolerance"), py::arg("tolerance"));

// Enums

}