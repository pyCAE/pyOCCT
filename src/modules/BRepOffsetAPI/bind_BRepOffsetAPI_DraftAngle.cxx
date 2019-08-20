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
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <Draft_ErrorStatus.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_ReShape.hxx>
#include <BRepOffsetAPI_DraftAngle.hxx>

void bind_BRepOffsetAPI_DraftAngle(py::module &mod){

py::class_<BRepOffsetAPI_DraftAngle, std::unique_ptr<BRepOffsetAPI_DraftAngle>, BRepBuilderAPI_ModifyShape> cls_BRepOffsetAPI_DraftAngle(mod, "BRepOffsetAPI_DraftAngle", "Taper-adding transformations on a shape. The resulting shape is constructed by defining one face to be tapered after another one, as well as the geometric properties of their tapered transformation. Each tapered transformation is propagated along the series of faces which are tangential to one another and which contains the face to be tapered. This algorithm is useful in the construction of molds or dies. It facilitates the removal of the article being produced. A DraftAngle object provides a framework for: - initializing the construction algorithm with a given shape, - acquiring the data characterizing the faces to be tapered, - implementing the construction algorithm, and - consulting the results. Warning - This algorithm treats planar, cylindrical and conical faces. - Do not use shapes, which with a draft angle added to a face would modify the topology. This would, for example, involve creation of new vertices, edges or faces, or suppression of existing vertices, edges or faces. - Any face, which is continuous in tangency with the face to be tapered, will also be tapered. These connected faces must also respect the above criteria.");

// Constructors
cls_BRepOffsetAPI_DraftAngle.def(py::init<>());
cls_BRepOffsetAPI_DraftAngle.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_DraftAngle::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_DraftAngle::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_DraftAngle::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_DraftAngle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_DraftAngle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_DraftAngle.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_DraftAngle::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_DraftAngle.def("Clear", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::Clear, "Cancels the results of all taper-adding transformations performed by this algorithm on the initial shape. These results will have been defined by successive calls to the function Add.");
cls_BRepOffsetAPI_DraftAngle.def("Init", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Init, "Initializes, or reinitializes this taper-adding algorithm with the shape S. S will be referred to as the initial shape of this algorithm.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("Add", [](BRepOffsetAPI_DraftAngle &self, const TopoDS_Face & a0, const gp_Dir & a1, const Standard_Real a2, const gp_Pln & a3) -> void { return self.Add(a0, a1, a2, a3); });
cls_BRepOffsetAPI_DraftAngle.def("Add", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &, const gp_Dir &, const Standard_Real, const gp_Pln &, const Standard_Boolean)) &BRepOffsetAPI_DraftAngle::Add, "Adds the face F, the direction Direction, the angle Angle, the plane NeutralPlane, and the flag Flag to the framework created at construction time, and with this data, defines the taper-adding transformation. F is a face, which belongs to the initial shape of this algorithm or to the shape loaded by the function Init. Only planar, cylindrical or conical faces can be tapered: - If the face F is planar, it is tapered by inclining it through the angle Angle about the line of intersection between the plane NeutralPlane and F. Direction indicates the side of NeutralPlane from which matter is removed if Angle is positive or added if Angle is negative. - If F is cylindrical or conical, it is transformed in the same way on a single face, resulting in a conical face if F is cylindrical, and a conical or cylindrical face if it is already conical. The taper-adding transformation is propagated from the face F along the series of planar, cylindrical or conical faces containing F, which are tangential to one another. Use the function AddDone to check if this taper-adding transformation is successful. Warning Nothing is done if: - the face F does not belong to the initial shape of this algorithm, or - the face F is not planar, cylindrical or conical. Exceptions - Standard_NullObject if the initial shape is not defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function. - Standard_ConstructionError if the previous call to Add has failed. The function AddDone ought to have been used to check for this, and the function Remove to cancel the results of the unsuccessful taper-adding transformation and to retrieve the previous shape.", py::arg("F"), py::arg("Direction"), py::arg("Angle"), py::arg("NeutralPlane"), py::arg("Flag"));
cls_BRepOffsetAPI_DraftAngle.def("AddDone", (Standard_Boolean (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::AddDone, "Returns true if the previous taper-adding transformation performed by this algorithm in the last call to Add, was successful. If AddDone returns false: - the function ProblematicShape returns the face on which the error occurred, - the function Remove has to be used to cancel the results of the unsuccessful taper-adding transformation and to retrieve the previous shape. Exceptions Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the .Init function.");
cls_BRepOffsetAPI_DraftAngle.def("Remove", (void (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &)) &BRepOffsetAPI_DraftAngle::Remove, "Cancels the taper-adding transformation previously performed by this algorithm on the face F and the series of tangential faces which contain F, and retrieves the shape before the last taper-adding transformation. Warning You will have to use this function if the previous call to Add fails. Use the function AddDone to check it. Exceptions - Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function. - Standard_NoSuchObject if F has not been added or has already been removed.", py::arg("F"));
cls_BRepOffsetAPI_DraftAngle.def("ProblematicShape", (const TopoDS_Shape & (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::ProblematicShape, "Returns the shape on which an error occurred after an unsuccessful call to Add or when IsDone returns false. Exceptions Standard_NullObject if the initial shape has not been defined, i.e. if this algorithm has not been initialized with the non-empty constructor or the Init function.");
cls_BRepOffsetAPI_DraftAngle.def("Status", (Draft_ErrorStatus (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::Status, "Returns an error status when an error has occured (Face, Edge or Vertex recomputaion problem). Otherwise returns Draft_NoError. The method may be called if AddDone returns Standard_False, or when IsDone returns Standard_False.");
cls_BRepOffsetAPI_DraftAngle.def("ConnectedFaces", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Face &) const) &BRepOffsetAPI_DraftAngle::ConnectedFaces, "Returns all the faces which have been added together with the face <F>.", py::arg("F"));
cls_BRepOffsetAPI_DraftAngle.def("ModifiedFaces", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)() const) &BRepOffsetAPI_DraftAngle::ModifiedFaces, "Returns all the faces on which a modification has been given.");
cls_BRepOffsetAPI_DraftAngle.def("Build", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepOffsetAPI_DraftAngle.def("CorrectWires", (void (BRepOffsetAPI_DraftAngle::*)()) &BRepOffsetAPI_DraftAngle::CorrectWires, "None");
cls_BRepOffsetAPI_DraftAngle.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("Modified", (const TopTools_ListOfShape & (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &)) &BRepOffsetAPI_DraftAngle::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_DraftAngle.def("ModifiedShape", (TopoDS_Shape (BRepOffsetAPI_DraftAngle::*)(const TopoDS_Shape &) const) &BRepOffsetAPI_DraftAngle::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Raises exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied.", py::arg("S"));

// Enums

}