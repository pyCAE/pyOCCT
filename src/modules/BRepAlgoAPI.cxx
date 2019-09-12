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
#include <BOPAlgo_Builder.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <BOPAlgo_Options.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BRepAlgoAPI_Algo.hxx>
#include <BOPAlgo_PaveFiller.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_GlueEnum.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <BRepAlgoAPI_BuilderAlgo.hxx>
#include <BOPAlgo_Operation.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepAlgoAPI_BooleanOperation.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <BRepAlgoAPI_Check.hxx>
#include <BRepAlgoAPI_Common.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <BRepTools_History.hxx>
#include <BOPAlgo_RemoveFeatures.hxx>
#include <BRepAlgoAPI_Defeaturing.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <BRepAlgoAPI_Section.hxx>
#include <BRepAlgoAPI_Splitter.hxx>
#include <Message_Alert.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Message_Report.hxx>

PYBIND11_MODULE(BRepAlgoAPI, mod) {

py::module::import("OCCT.BOPAlgo");
py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Message");

// CLASS: BREPALGOAPI_ALGO
py::class_<BRepAlgoAPI_Algo, std::unique_ptr<BRepAlgoAPI_Algo, py::nodelete>, BRepBuilderAPI_MakeShape> cls_BRepAlgoAPI_Algo(mod, "BRepAlgoAPI_Algo", "Provides the root interface for the API algorithms", py::multiple_inheritance());

// Methods
// cls_BRepAlgoAPI_Algo.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Algo::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Algo::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Algo::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Algo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Algo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Algo.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Algo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Algo.def("Shape", (const TopoDS_Shape & (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::Shape, "None");

/*
// FIXME Access protected members of this class that are made available with "using" in BRepAlgoAPI_Algo class definition. Need to write as lambdas.
// CLASS: BOPALGO_OPTIONS
// Following method not accessible since protected in parent class, BOPAlgo_Options, and not exposed with using
//cls_BRepAlgoAPI_Algo.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::Allocator, "Returns allocator");
cls_BRepAlgoAPI_Algo.def("Clear", (void (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::Clear, "Clears all warnings and errors, and any data cached by the algorithm. User defined options are not cleared.");
// Following method not accessible since protected in parent class, BOPAlgo_Options, and not exposed with using
//cls_BRepAlgoAPI_Algo.def("AddError", (void (BRepAlgoAPI_Algo::*)(const opencascade::handle<Message_Alert> &)) &BRepAlgoAPI_Algo::AddError, "Adds the alert as error (fail)", py::arg("theAlert"));
// Following method not accessible since protected in parent class, BOPAlgo_Options, and not exposed with using
//cls_BRepAlgoAPI_Algo.def("AddWarning", (void (BRepAlgoAPI_Algo::*)(const opencascade::handle<Message_Alert> &)) &BRepAlgoAPI_Algo::AddWarning, "Adds the alert as warning", py::arg("theAlert"));
cls_BRepAlgoAPI_Algo.def("HasErrors", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::HasErrors, "Returns true if algorithm has failed");
cls_BRepAlgoAPI_Algo.def("HasError", (Standard_Boolean (BRepAlgoAPI_Algo::*)(const opencascade::handle<Standard_Type> &) const) &BRepAlgoAPI_Algo::HasError, "Returns true if algorithm has generated error of specified type", py::arg("theType"));
cls_BRepAlgoAPI_Algo.def("HasWarnings", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::HasWarnings, "Returns true if algorithm has generated some warning alerts");
cls_BRepAlgoAPI_Algo.def("HasWarning", (Standard_Boolean (BRepAlgoAPI_Algo::*)(const opencascade::handle<Standard_Type> &) const) &BRepAlgoAPI_Algo::HasWarning, "Returns true if algorithm has generated warning of specified type", py::arg("theType"));
cls_BRepAlgoAPI_Algo.def("GetReport", (const opencascade::handle<Message_Report> & (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::GetReport, "Returns report collecting all errors and warnings");
cls_BRepAlgoAPI_Algo.def("DumpErrors", (void (BRepAlgoAPI_Algo::*)(Standard_OStream &) const) &BRepAlgoAPI_Algo::DumpErrors, "Dumps the error status into the given stream", py::arg("theOS"));
cls_BRepAlgoAPI_Algo.def("DumpWarnings", (void (BRepAlgoAPI_Algo::*)(Standard_OStream &) const) &BRepAlgoAPI_Algo::DumpWarnings, "Dumps the warning statuses into the given stream", py::arg("theOS"));
cls_BRepAlgoAPI_Algo.def("ClearWarnings", (void (BRepAlgoAPI_Algo::*)()) &BRepAlgoAPI_Algo::ClearWarnings, "Clears the warnings of the algorithm");
cls_BRepAlgoAPI_Algo.def("SetFuzzyValue", (void (BRepAlgoAPI_Algo::*)(const Standard_Real)) &BRepAlgoAPI_Algo::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
cls_BRepAlgoAPI_Algo.def("FuzzyValue", (Standard_Real (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::FuzzyValue, "Returns the additional tolerance");
cls_BRepAlgoAPI_Algo.def("SetProgressIndicator", (void (BRepAlgoAPI_Algo::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BRepAlgoAPI_Algo::SetProgressIndicator, "Set the Progress Indicator object.", py::arg("theObj"));
cls_BRepAlgoAPI_Algo.def("SetRunParallel", (void (BRepAlgoAPI_Algo::*)(const Standard_Boolean)) &BRepAlgoAPI_Algo::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
cls_BRepAlgoAPI_Algo.def("RunParallel", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::RunParallel, "Returns the flag of parallel processing");
cls_BRepAlgoAPI_Algo.def("SetUseOBB", (void (BRepAlgoAPI_Algo::*)(const Standard_Boolean)) &BRepAlgoAPI_Algo::SetUseOBB, "Enables/Disables the usage of OBB", py::arg("theUseOBB"));
// Following method not accessible since protected in parent class, BOPAlgo_Options, and not exposed with using
//cls_BRepAlgoAPI_Algo.def("UseOBB", (Standard_Boolean (BRepAlgoAPI_Algo::*)() const) &BRepAlgoAPI_Algo::UseOBB, "Returns the flag defining usage of OBB");
*/

// CLASS: BREPALGOAPI_BUILDERALGO
py::class_<BRepAlgoAPI_BuilderAlgo, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_BuilderAlgo(mod, "BRepAlgoAPI_BuilderAlgo", "The class contains API level of the General Fuse algorithm.");

// Constructors
cls_BRepAlgoAPI_BuilderAlgo.def(py::init<>());
cls_BRepAlgoAPI_BuilderAlgo.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("thePF"));

// Methods
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_BuilderAlgo::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_BuilderAlgo::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_BuilderAlgo::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_BuilderAlgo::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_BuilderAlgo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_BuilderAlgo.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_BuilderAlgo::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_BuilderAlgo.def("SetNonDestructive", (void (BRepAlgoAPI_BuilderAlgo::*)(const Standard_Boolean)) &BRepAlgoAPI_BuilderAlgo::SetNonDestructive, "Sets the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.", py::arg("theFlag"));
cls_BRepAlgoAPI_BuilderAlgo.def("NonDestructive", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::NonDestructive, "Returns the flag that defines the mode of treatment. In non-destructive mode the argument shapes are not modified. Instead a copy of a sub-shape is created in the result if it is needed to be updated.");
cls_BRepAlgoAPI_BuilderAlgo.def("SetGlue", (void (BRepAlgoAPI_BuilderAlgo::*)(const BOPAlgo_GlueEnum)) &BRepAlgoAPI_BuilderAlgo::SetGlue, "Sets the glue option for the algorithm", py::arg("theGlue"));
cls_BRepAlgoAPI_BuilderAlgo.def("Glue", (BOPAlgo_GlueEnum (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Glue, "Returns the glue option of the algorithm");
cls_BRepAlgoAPI_BuilderAlgo.def("SetCheckInverted", (void (BRepAlgoAPI_BuilderAlgo::*)(const Standard_Boolean)) &BRepAlgoAPI_BuilderAlgo::SetCheckInverted, "Enables/Disables the check of the input solids for inverted status", py::arg("theCheck"));
cls_BRepAlgoAPI_BuilderAlgo.def("CheckInverted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::CheckInverted, "Returns the flag defining whether the check for input solids on inverted status should be performed or not.");
cls_BRepAlgoAPI_BuilderAlgo.def("SetArguments", (void (BRepAlgoAPI_BuilderAlgo::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BuilderAlgo::SetArguments, "Sets the arguments", py::arg("theLS"));
cls_BRepAlgoAPI_BuilderAlgo.def("Arguments", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Arguments, "Gets the arguments");
cls_BRepAlgoAPI_BuilderAlgo.def("Build", (void (BRepAlgoAPI_BuilderAlgo::*)()) &BRepAlgoAPI_BuilderAlgo::Build, "Performs the algorithm");
cls_BRepAlgoAPI_BuilderAlgo.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
cls_BRepAlgoAPI_BuilderAlgo.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
cls_BRepAlgoAPI_BuilderAlgo.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BuilderAlgo::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BuilderAlgo::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
cls_BRepAlgoAPI_BuilderAlgo.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BuilderAlgo.def("DSFiller", (const BOPAlgo_PPaveFiller & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::DSFiller, "Returns the Intersection tool");
cls_BRepAlgoAPI_BuilderAlgo.def("Builder", (const BOPAlgo_PBuilder & (BRepAlgoAPI_BuilderAlgo::*)() const) &BRepAlgoAPI_BuilderAlgo::Builder, "Returns the Building tool");

// CLASS: BREPALGOAPI_BOOLEANOPERATION
py::class_<BRepAlgoAPI_BooleanOperation, BRepAlgoAPI_BuilderAlgo> cls_BRepAlgoAPI_BooleanOperation(mod, "BRepAlgoAPI_BooleanOperation", "The abstract class BooleanOperation is the root class of Boolean Operations (see Overview). Boolean Operations algorithm is divided onto two parts: - The first one is computing interference between arguments; - The second one is building the result of operation; The class BooleanOperation provides API level of both parts.");

// Methods
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_BooleanOperation::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_BooleanOperation::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_BooleanOperation::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_BooleanOperation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_BooleanOperation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_BooleanOperation.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_BooleanOperation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_BooleanOperation.def("Shape1", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Shape1, "Returns the first argument involved in this Boolean operation. Obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("Shape2", (const TopoDS_Shape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Shape2, "Returns the second argument involved in this Boolean operation. Obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("SetTools", (void (BRepAlgoAPI_BooleanOperation::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_BooleanOperation::SetTools, "Sets the tools", py::arg("theLS"));
cls_BRepAlgoAPI_BooleanOperation.def("Tools", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Tools, "Gets the tools");
cls_BRepAlgoAPI_BooleanOperation.def("SetOperation", (void (BRepAlgoAPI_BooleanOperation::*)(const BOPAlgo_Operation)) &BRepAlgoAPI_BooleanOperation::SetOperation, "Sets the type of Boolean operation", py::arg("anOp"));
cls_BRepAlgoAPI_BooleanOperation.def("Operation", (BOPAlgo_Operation (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::Operation, "Returns the type of Boolean Operation");
cls_BRepAlgoAPI_BooleanOperation.def("Build", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
cls_BRepAlgoAPI_BooleanOperation.def("BuilderCanWork", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::BuilderCanWork, "Returns True if there was no errors occured obsolete");
cls_BRepAlgoAPI_BooleanOperation.def("FuseEdges", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::FuseEdges, "Returns the flag of edge refining");
cls_BRepAlgoAPI_BooleanOperation.def("RefineEdges", (void (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::RefineEdges, "Fuse C1 edges");
cls_BRepAlgoAPI_BooleanOperation.def("SectionEdges", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)()) &BRepAlgoAPI_BooleanOperation::SectionEdges, "Returns a list of section edges. The edges represent the result of intersection between arguments of Boolean Operation. They are computed during operation execution.");
cls_BRepAlgoAPI_BooleanOperation.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("aS"));
cls_BRepAlgoAPI_BooleanOperation.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::IsDeleted, "Returns true if the shape S has been deleted. The result shape of the operation does not contain the shape S.", py::arg("aS"));
cls_BRepAlgoAPI_BooleanOperation.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgoAPI_BooleanOperation::Generated, "Returns the list of shapes generated from the shape <S>. For use in BRepNaming.", py::arg("S"));
cls_BRepAlgoAPI_BooleanOperation.def("HasModified", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasModified, "Returns true if there is at least one modified shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BooleanOperation.def("HasGenerated", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasGenerated, "Returns true if there is at least one generated shape. For use in BRepNaming.");
cls_BRepAlgoAPI_BooleanOperation.def("HasDeleted", (Standard_Boolean (BRepAlgoAPI_BooleanOperation::*)() const) &BRepAlgoAPI_BooleanOperation::HasDeleted, "Returns true if there is at least one deleted shape. For use in BRepNaming.");

// CLASS: BREPALGOAPI_CHECK
py::class_<BRepAlgoAPI_Check, BOPAlgo_Options> cls_BRepAlgoAPI_Check(mod, "BRepAlgoAPI_Check", "The class Check provides a diagnostic tool for checking the validity of the single shape or couple of shapes. The shapes are checked on: - Topological validity; - Small edges; - Self-interference; - Validity for Boolean operation of certain type (for couple of shapes only).");

// Constructors
cls_BRepAlgoAPI_Check.def(py::init<>());
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &>(), py::arg("theS"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("theS1"), py::arg("theS2"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));

// Methods
// cls_BRepAlgoAPI_Check.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Check::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Check.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Check::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Check::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Check.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Check::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Check::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Check::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0) -> void { return self.SetData(a0); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.SetData(a0, a1); });
cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Initializes the algorithm with single shape.", py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.SetData(a0, a1); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2) -> void { return self.SetData(a0, a1, a2); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2, const Standard_Boolean a3) -> void { return self.SetData(a0, a1, a2, a3); });
cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Initializes the algorithm with couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type.", py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def("Perform", (void (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Perform, "Performs the check.");
cls_BRepAlgoAPI_Check.def("IsValid", (Standard_Boolean (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::IsValid, "Shows whether shape(s) valid or not.");
cls_BRepAlgoAPI_Check.def("Result", (const BOPAlgo_ListOfCheckResult & (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Result, "Returns faulty shapes.");

// CLASS: BREPALGOAPI_COMMON
py::class_<BRepAlgoAPI_Common, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Common(mod, "BRepAlgoAPI_Common", "The class provides Boolean common operation between arguments and tools (Boolean Intersection).");

// Constructors
cls_BRepAlgoAPI_Common.def(py::init<>());
cls_BRepAlgoAPI_Common.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Common.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Common.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("PF"));

// Methods
// cls_BRepAlgoAPI_Common.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Common::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Common.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Common::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Common.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Common::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Common.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Common::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Common.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Common::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Common.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Common::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: BREPALGOAPI_CUT
py::class_<BRepAlgoAPI_Cut, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Cut(mod, "BRepAlgoAPI_Cut", "The class Cut provides Boolean cut operation between arguments and tools (Boolean Subtraction).");

// Constructors
cls_BRepAlgoAPI_Cut.def(py::init<>());
cls_BRepAlgoAPI_Cut.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));
cls_BRepAlgoAPI_Cut.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"), py::arg("bFWD"));

// Methods
// cls_BRepAlgoAPI_Cut.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Cut::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Cut.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Cut::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Cut.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Cut::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Cut.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Cut::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Cut.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Cut::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Cut.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Cut::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: BREPALGOAPI_DEFEATURING
py::class_<BRepAlgoAPI_Defeaturing, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_Defeaturing(mod, "BRepAlgoAPI_Defeaturing", "The BRepAlgoAPI_Defeaturing algorithm is the API algorithm intended for removal of the unwanted parts from the shape. The unwanted parts (or features) can be holes, protrusions, gaps, chamfers, fillets etc. The shape itself is not modified, the new shape is built as the result.");

// Constructors
cls_BRepAlgoAPI_Defeaturing.def(py::init<>());

// Methods
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Defeaturing::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Defeaturing::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Defeaturing::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Defeaturing::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Defeaturing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Defeaturing::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Defeaturing.def("SetShape", (void (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::SetShape, "Sets the shape for processing.", py::arg("theShape"));
cls_BRepAlgoAPI_Defeaturing.def("InputShape", (const TopoDS_Shape & (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::InputShape, "Returns the input shape");
cls_BRepAlgoAPI_Defeaturing.def("AddFaceToRemove", (void (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::AddFaceToRemove, "Adds the features to remove from the input shape.", py::arg("theFace"));
cls_BRepAlgoAPI_Defeaturing.def("AddFacesToRemove", (void (BRepAlgoAPI_Defeaturing::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_Defeaturing::AddFacesToRemove, "Adds the faces to remove from the input shape.", py::arg("theFaces"));
cls_BRepAlgoAPI_Defeaturing.def("FacesToRemove", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::FacesToRemove, "Returns the list of faces which have been requested for removal from the input shape.");
cls_BRepAlgoAPI_Defeaturing.def("Build", (void (BRepAlgoAPI_Defeaturing::*)()) &BRepAlgoAPI_Defeaturing::Build, "Performs the operation");
cls_BRepAlgoAPI_Defeaturing.def("TrackHistory", (void (BRepAlgoAPI_Defeaturing::*)(const Standard_Boolean)) &BRepAlgoAPI_Defeaturing::TrackHistory, "Defines whether to track the modification of the shapes or not.", py::arg("theFlag"));
cls_BRepAlgoAPI_Defeaturing.def("HasHistory", (Standard_Boolean (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::HasHistory, "Returns whether the history was requested or not.");
cls_BRepAlgoAPI_Defeaturing.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::Modified, "Returns the list of shapes modified from the shape <theS> during the operation.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::Generated, "Returns the list of shapes generated from the shape <theS> during the operation.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::IsDeleted, "Returns true if the shape <theS> has been deleted during the operation. It means that the shape has no any trace in the result. Otherwise it returns false.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("GetHistory", (opencascade::handle<BRepTools_History> (BRepAlgoAPI_Defeaturing::*)()) &BRepAlgoAPI_Defeaturing::GetHistory, "Returns the History of shapes modifications");

// CLASS: BREPALGOAPI_FUSE
py::class_<BRepAlgoAPI_Fuse, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Fuse(mod, "BRepAlgoAPI_Fuse", "The class provides Boolean fusion operation between arguments and tools (Boolean Union).");

// Constructors
cls_BRepAlgoAPI_Fuse.def(py::init<>());
cls_BRepAlgoAPI_Fuse.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Fuse.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));

// Methods
// cls_BRepAlgoAPI_Fuse.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Fuse::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Fuse::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Fuse::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Fuse::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Fuse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Fuse.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Fuse::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: BREPALGOAPI_SECTION
py::class_<BRepAlgoAPI_Section, BRepAlgoAPI_BooleanOperation> cls_BRepAlgoAPI_Section(mod, "BRepAlgoAPI_Section", "The algorithm is to build a Secton operation between arguments and tools. The result of Section operation consists of vertices and edges. The result of Section operation contains: 1. new vertices that are subjects of V/V, E/E, E/F, F/F interferences 2. vertices that are subjects of V/E, V/F interferences 3. new edges that are subjects of F/F interferences 4. edges that are Common Blocks");

// Constructors
cls_BRepAlgoAPI_Section.def(py::init<>());
cls_BRepAlgoAPI_Section.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("PF"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("S1"), py::arg("S2"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_PaveFiller &, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("aDSF"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("S1"), py::arg("Pl"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const gp_Pln &, const Standard_Boolean>(), py::arg("S1"), py::arg("Pl"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &>(), py::arg("S1"), py::arg("Sf"));
cls_BRepAlgoAPI_Section.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S1"), py::arg("Sf"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &>(), py::arg("Sf"), py::arg("S2"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const TopoDS_Shape &, const Standard_Boolean>(), py::arg("Sf"), py::arg("S2"), py::arg("PerformNow"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("Sf1"), py::arg("Sf2"));
cls_BRepAlgoAPI_Section.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("Sf1"), py::arg("Sf2"), py::arg("PerformNow"));

// Methods
// cls_BRepAlgoAPI_Section.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Section::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Section.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Section::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Section::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Section.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Section::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Section::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Section.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Section::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <S1> - argument Obsolete", py::arg("S1"));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Pl> - argument Obsolete", py::arg("Pl"));
cls_BRepAlgoAPI_Section.def("Init1", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init1, "initialize the argument <Sf> - argument Obsolete", py::arg("Sf"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <S2> - tool Obsolete", py::arg("S2"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const gp_Pln &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Pl> - tool Obsolete", py::arg("Pl"));
cls_BRepAlgoAPI_Section.def("Init2", (void (BRepAlgoAPI_Section::*)(const opencascade::handle<Geom_Surface> &)) &BRepAlgoAPI_Section::Init2, "initialize the tool <Sf> - tool Obsolete", py::arg("Sf"));
cls_BRepAlgoAPI_Section.def("Approximation", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::Approximation, "None", py::arg("B"));
cls_BRepAlgoAPI_Section.def("ComputePCurveOn1", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn1, "Indicates whether the P-Curve should be (or not) performed on the argument. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the argument to the constructed edges. Obsolete", py::arg("B"));
cls_BRepAlgoAPI_Section.def("ComputePCurveOn2", (void (BRepAlgoAPI_Section::*)(const Standard_Boolean)) &BRepAlgoAPI_Section::ComputePCurveOn2, "Indicates whether the P-Curve should be (or not) performed on the tool. By default, no parametric 2D curve (pcurve) is defined for the edges of the result. If ComputePCurve1 equals true, further computations performed to attach an P-Curve in the parametric space of the tool to the constructed edges. Obsolete", py::arg("B"));
cls_BRepAlgoAPI_Section.def("Build", (void (BRepAlgoAPI_Section::*)()) &BRepAlgoAPI_Section::Build, "Performs the algorithm Filling interference Data Structure (if it is necessary) Building the result of the operation.");
cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn1", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgoAPI_Section::HasAncestorFaceOn1, "get the face of the first part giving section edge <E>. Returns True on the 3 following conditions : 1/ <E> is an edge returned by the Shape() metwod. 2/ First part of section performed is a shape. 3/ <E> is built on a intersection curve (i.e <E> is not the result of common edges) When False, F remains untouched. Obsolete", py::arg("E"), py::arg("F"));
cls_BRepAlgoAPI_Section.def("HasAncestorFaceOn2", (Standard_Boolean (BRepAlgoAPI_Section::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &BRepAlgoAPI_Section::HasAncestorFaceOn2, "Identifies the ancestor faces of the intersection edge E resulting from the last computation performed in this framework, that is, the faces of the two original shapes on which the edge E lies: - HasAncestorFaceOn1 gives the ancestor face in the first shape, and - HasAncestorFaceOn2 gives the ancestor face in the second shape. These functions return true if an ancestor face F is found, or false if not. An ancestor face is identifiable for the edge E if the following conditions are satisfied: - the first part on which this algorithm performed its last computation is a shape, that is, it was not given as a surface or a plane at the time of construction of this algorithm or at a later time by the Init1 function, - E is one of the elementary edges built by the last computation of this section algorithm. To use these functions properly, you have to test the returned Boolean value before using the ancestor face: F is significant only if the returned Boolean value equals true. Obsolete", py::arg("E"), py::arg("F"));

// CLASS: BREPALGOAPI_SPLITTER
py::class_<BRepAlgoAPI_Splitter, BRepAlgoAPI_BuilderAlgo> cls_BRepAlgoAPI_Splitter(mod, "BRepAlgoAPI_Splitter", "The class contains API level of the **Splitter** algorithm, which allows splitting a group of arbitrary shapes by the other group of arbitrary shapes. The arguments of the operation are divided on two groups: *Objects* - shapes that will be split; *Tools* - shapes by which the *Objects* will be split. The result of the operation contains only the split parts of the shapes from the group of *Objects*. The split parts of the shapes from the group of *Tools* are excluded from the result. The shapes can be split by the other shapes from the same group (in case these shapes are interfering).");

// Constructors
cls_BRepAlgoAPI_Splitter.def(py::init<>());
cls_BRepAlgoAPI_Splitter.def(py::init<const BOPAlgo_PaveFiller &>(), py::arg("thePF"));

// Methods
// cls_BRepAlgoAPI_Splitter.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Splitter::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Splitter.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Splitter::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Splitter.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Splitter::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Splitter.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Splitter::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Splitter.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Splitter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Splitter.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Splitter::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Splitter.def("Build", (void (BRepAlgoAPI_Splitter::*)()) &BRepAlgoAPI_Splitter::Build, "Performs the algorithm. Performs the intersection of the objects with tools and build the result of the operation.");
cls_BRepAlgoAPI_Splitter.def("SetTools", (void (BRepAlgoAPI_Splitter::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_Splitter::SetTools, "Sets the tools", py::arg("theLS"));
cls_BRepAlgoAPI_Splitter.def("Tools", (const TopTools_ListOfShape & (BRepAlgoAPI_Splitter::*)() const) &BRepAlgoAPI_Splitter::Tools, "Gets the tools");


}