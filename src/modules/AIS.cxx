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
#include <AIS_KindOfSurface.hxx>
#include <AIS_DimensionSelectionMode.hxx>
#include <AIS_DisplaySpecialSymbol.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <AIS_KindOfDimension.hxx>
#include <AIS_TypeOfAngle.hxx>
#include <AIS_TypeOfAngleArrowVisibility.hxx>
#include <AIS_DisplayStatus.hxx>
#include <AIS_DisplayMode.hxx>
#include <AIS_ClearMode.hxx>
#include <AIS_SelectStatus.hxx>
#include <AIS_SelectionModesConcurrency.hxx>
#include <AIS_StatusOfDetection.hxx>
#include <AIS_StatusOfPick.hxx>
#include <AIS_TypeOfIso.hxx>
#include <AIS_TypeOfAxis.hxx>
#include <AIS_ConnectStatus.hxx>
#include <AIS_DragAction.hxx>
#include <AIS_TypeOfDist.hxx>
#include <AIS_TypeOfAttribute.hxx>
#include <AIS_KindOfRelation.hxx>
#include <AIS_KindOfUnit.hxx>
#include <AIS_ManipulatorMode.hxx>
#include <AIS_MouseGesture.hxx>
#include <AIS_NavigationMode.hxx>
#include <AIS_TypeOfPlane.hxx>
#include <AIS_RotationMode.hxx>
#include <AIS_StandardDatum.hxx>
#include <AIS_TrihedronSelectionMode.hxx>
#include <AIS_ViewInputBuffer.hxx>
#include <AIS_WalkDelta.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Plane.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <gp_Dir.hxx>
#include <Bnd_Box.hxx>
#include <gp_Elips.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <AIS.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <Standard_Std.hxx>
#include <AIS_DimensionOwner.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_Transient.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Standard_OStream.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_Dimension.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Circ.hxx>
#include <Prs3d_DimensionTextHorizontalPosition.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Handle.hxx>
#include <gp.hxx>
#include <AIS_AngleDimension.hxx>
#include <Media_Timer.hxx>
#include <AIS_AnimationTimer.hxx>
#include <AIS_Animation.hxx>
#include <AIS_AnimationCamera.hxx>
#include <V3d_View.hxx>
#include <Graphic3d_Camera.hxx>
#include <AIS_GlobalStatus.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <AIS_DataMapOfIOStatus.hxx>
#include <NCollection_List.hxx>
#include <AIS_ListOfInteractive.hxx>
#include <AIS_NListOfEntityOwner.hxx>
#include <AIS_Selection.hxx>
#include <V3d_Viewer.hxx>
#include <Prs3d_TypeOfHighlight.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <TopLoc_Location.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TransModeFlags.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_PickingStrategy.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Standard_ProgramError.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <AIS_AnimationObject.hxx>
#include <gp_Trsf.hxx>
#include <gp_TrsfNLerp.hxx>
#include <AIS_AttributeFilter.hxx>
#include <AIS_Axis.hxx>
#include <Geom_Line.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <AIS_BadEdgeFilter.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <AIS_C0RegularityFilter.hxx>
#include <TopTools_MapOfShape.hxx>
#include <AIS_CameraFrustum.hxx>
#include <NCollection_Array1.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <AIS_Relation.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <AIS_Chamf2dDimension.hxx>
#include <AIS_Chamf3dDimension.hxx>
#include <AIS_Circle.hxx>
#include <Geom_Circle.hxx>
#include <AIS_ColoredDrawer.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <AIS_DataMapOfShapeDrawer.hxx>
#include <AIS_Shape.hxx>
#include <Prs3d_TypeOfHLR.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopoDS_Compound.hxx>
#include <AIS_ColoredShape.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <AIS_ColorScale.hxx>
#include <Aspect_TypeOfColorScaleData.hxx>
#include <TColStd_SequenceOfExtendedString.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <Aspect_TypeOfColorScalePosition.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <AIS_ConcentricRelation.hxx>
#include <AIS_ConnectedInteractive.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <AIS_DataMapofIntegerListOfinteractive.hxx>
#include <AIS_DiameterDimension.hxx>
#include <AIS_EllipseRadiusDimension.hxx>
#include <Geom_OffsetCurve.hxx>
#include <AIS_EqualDistanceRelation.hxx>
#include <AIS_EqualRadiusRelation.hxx>
#include <AIS_ExclusionFilter.hxx>
#include <TColStd_DataMapOfIntegerListOfInteger.hxx>
#include <AIS_FixRelation.hxx>
#include <TopoDS_Wire.hxx>
#include <AIS_GraphicTool.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <AIS_IdenticRelation.hxx>
#include <Geom_Ellipse.hxx>
#include <AIS_IndexedDataMapOfOwnerPrs.hxx>
#include <AIS_LengthDimension.hxx>
#include <AIS_Line.hxx>
#include <Geom_Point.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <AIS_Manipulator.hxx>
#include <gp_Ax2.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Poly_Triangulation.hxx>
#include <gp_Ax1.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <AIS_ManipulatorOwner.hxx>
#include <NCollection_Map.hxx>
#include <AIS_MapOfInteractive.hxx>
#include <AIS_MaxRadiusDimension.hxx>
#include <AIS_MediaPlayer.hxx>
#include <Graphic3d_MediaTextureSet.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Media_PlayerContext.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <AIS_MidPointRelation.hxx>
#include <AIS_MinRadiusDimension.hxx>
#include <AIS_MultipleConnectedInteractive.hxx>
#include <AIS_OffsetDimension.hxx>
#include <AIS_ParallelRelation.hxx>
#include <AIS_PerpendicularRelation.hxx>
#include <AIS_Plane.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <AIS_PlaneTrihedron.hxx>
#include <AIS_Point.hxx>
#include <Prs3d_PointAspect.hxx>
#include <AIS_PointCloud.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Quantity_HArray1OfColor.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <AIS_RadiusDimension.hxx>
#include <AIS_RubberBand.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>
#include <AIS_SequenceOfDimension.hxx>
#include <AIS_SequenceOfInteractive.hxx>
#include <AIS_TypeFilter.hxx>
#include <AIS_SignatureFilter.hxx>
#include <AIS_SymmetricRelation.hxx>
#include <AIS_TangentRelation.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Font_FontAspect.hxx>
#include <Aspect_TypeOfDisplayText.hxx>
#include <AIS_TextLabel.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_Texture2Dmanual.hxx>
#include <Graphic3d_NameOfTexture2D.hxx>
#include <AIS_TexturedShape.hxx>
#include <AIS_Triangulation.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Graphic3d_Vec4.hxx>
#include <AIS_Trihedron.hxx>
#include <Prs3d_DatumMode.hxx>
#include <Prs3d_DatumParts.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <AIS_TrihedronOwner.hxx>
#include <Aspect_ScrollDelta.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <Aspect_VKeySet.hxx>
#include <Aspect_VKey.hxx>
#include <Aspect_VKeyFlags.hxx>
#include <Precision.hxx>
#include <OSD_Timer.hxx>
#include <Aspect_TouchMap.hxx>
#include <gp_Vec.hxx>
#include <AIS_ViewController.hxx>
#include <AIS_ViewCube.hxx>
#include <gp_XY.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_Map.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(AIS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Media");
py::module::import("OCCT.V3d");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.StdSelect");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.DsgPrs");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.Font");
py::module::import("OCCT.Image");
py::module::import("OCCT.Precision");
py::module::import("OCCT.OSD");

// ENUM: AIS_KINDOFSURFACE
py::enum_<AIS_KindOfSurface>(mod, "AIS_KindOfSurface", "None")
	.value("AIS_KOS_Plane", AIS_KindOfSurface::AIS_KOS_Plane)
	.value("AIS_KOS_Cylinder", AIS_KindOfSurface::AIS_KOS_Cylinder)
	.value("AIS_KOS_Cone", AIS_KindOfSurface::AIS_KOS_Cone)
	.value("AIS_KOS_Sphere", AIS_KindOfSurface::AIS_KOS_Sphere)
	.value("AIS_KOS_Torus", AIS_KindOfSurface::AIS_KOS_Torus)
	.value("AIS_KOS_Revolution", AIS_KindOfSurface::AIS_KOS_Revolution)
	.value("AIS_KOS_Extrusion", AIS_KindOfSurface::AIS_KOS_Extrusion)
	.value("AIS_KOS_OtherSurface", AIS_KindOfSurface::AIS_KOS_OtherSurface)
	.export_values();


// ENUM: AIS_DIMENSIONSELECTIONMODE
py::enum_<AIS_DimensionSelectionMode>(mod, "AIS_DimensionSelectionMode", "Specifies dimension selection modes.")
	.value("AIS_DSM_All", AIS_DimensionSelectionMode::AIS_DSM_All)
	.value("AIS_DSM_Line", AIS_DimensionSelectionMode::AIS_DSM_Line)
	.value("AIS_DSM_Text", AIS_DimensionSelectionMode::AIS_DSM_Text)
	.export_values();


// ENUM: AIS_DISPLAYSPECIALSYMBOL
py::enum_<AIS_DisplaySpecialSymbol>(mod, "AIS_DisplaySpecialSymbol", "Specifies dimension special symbol display options")
	.value("AIS_DSS_No", AIS_DisplaySpecialSymbol::AIS_DSS_No)
	.value("AIS_DSS_Before", AIS_DisplaySpecialSymbol::AIS_DSS_Before)
	.value("AIS_DSS_After", AIS_DisplaySpecialSymbol::AIS_DSS_After)
	.export_values();


// ENUM: AIS_KINDOFINTERACTIVE
py::enum_<AIS_KindOfInteractive>(mod, "AIS_KindOfInteractive", "Declares the type of Interactive Object. This is one of the following: - the Datum - the Object - the Relation - the Dimension - the None type. The Datum is the construction element. These include points, lines, axes and planes. The object brings together topological shapes. The Relation includes dimensions and constraints. The Dimension includes length, radius, diameter and angle dimensions. When the object is of an unknown type, the None type is declared.")
	.value("AIS_KOI_None", AIS_KindOfInteractive::AIS_KOI_None)
	.value("AIS_KOI_Datum", AIS_KindOfInteractive::AIS_KOI_Datum)
	.value("AIS_KOI_Shape", AIS_KindOfInteractive::AIS_KOI_Shape)
	.value("AIS_KOI_Object", AIS_KindOfInteractive::AIS_KOI_Object)
	.value("AIS_KOI_Relation", AIS_KindOfInteractive::AIS_KOI_Relation)
	.value("AIS_KOI_Dimension", AIS_KindOfInteractive::AIS_KOI_Dimension)
	.export_values();


// ENUM: AIS_KINDOFDIMENSION
py::enum_<AIS_KindOfDimension>(mod, "AIS_KindOfDimension", "Declares the kinds of dimensions needed in the display of Interactive Objects.")
	.value("AIS_KOD_NONE", AIS_KindOfDimension::AIS_KOD_NONE)
	.value("AIS_KOD_LENGTH", AIS_KindOfDimension::AIS_KOD_LENGTH)
	.value("AIS_KOD_PLANEANGLE", AIS_KindOfDimension::AIS_KOD_PLANEANGLE)
	.value("AIS_KOD_SOLIDANGLE", AIS_KindOfDimension::AIS_KOD_SOLIDANGLE)
	.value("AIS_KOD_AREA", AIS_KindOfDimension::AIS_KOD_AREA)
	.value("AIS_KOD_VOLUME", AIS_KindOfDimension::AIS_KOD_VOLUME)
	.value("AIS_KOD_MASS", AIS_KindOfDimension::AIS_KOD_MASS)
	.value("AIS_KOD_TIME", AIS_KindOfDimension::AIS_KOD_TIME)
	.value("AIS_KOD_RADIUS", AIS_KindOfDimension::AIS_KOD_RADIUS)
	.value("AIS_KOD_DIAMETER", AIS_KindOfDimension::AIS_KOD_DIAMETER)
	.value("AIS_KOD_CHAMF2D", AIS_KindOfDimension::AIS_KOD_CHAMF2D)
	.value("AIS_KOD_CHAMF3D", AIS_KindOfDimension::AIS_KOD_CHAMF3D)
	.value("AIS_KOD_OFFSET", AIS_KindOfDimension::AIS_KOD_OFFSET)
	.value("AIS_KOD_ELLIPSERADIUS", AIS_KindOfDimension::AIS_KOD_ELLIPSERADIUS)
	.export_values();


// ENUM: AIS_TYPEOFANGLE
py::enum_<AIS_TypeOfAngle>(mod, "AIS_TypeOfAngle", "Declares the type of angle.")
	.value("AIS_TOA_Interior", AIS_TypeOfAngle::AIS_TOA_Interior)
	.value("AIS_TOA_Exterior", AIS_TypeOfAngle::AIS_TOA_Exterior)
	.export_values();


// ENUM: AIS_TYPEOFANGLEARROWVISIBILITY
py::enum_<AIS_TypeOfAngleArrowVisibility>(mod, "AIS_TypeOfAngleArrowVisibility", "Declares what arrows are visible on angle presentation")
	.value("AIS_TOAV_Both", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_Both)
	.value("AIS_TOAV_First", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_First)
	.value("AIS_TOAV_Second", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_Second)
	.value("AIS_TOAV_None", AIS_TypeOfAngleArrowVisibility::AIS_TOAV_None)
	.export_values();


// ENUM: AIS_DISPLAYSTATUS
py::enum_<AIS_DisplayStatus>(mod, "AIS_DisplayStatus", "To give the display status of an Interactive Object.")
	.value("AIS_DS_Displayed", AIS_DisplayStatus::AIS_DS_Displayed)
	.value("AIS_DS_Erased", AIS_DisplayStatus::AIS_DS_Erased)
	.value("AIS_DS_None", AIS_DisplayStatus::AIS_DS_None)
	.export_values();


// ENUM: AIS_DISPLAYMODE
py::enum_<AIS_DisplayMode>(mod, "AIS_DisplayMode", "Sets display modes other than neutral point ones, for interactive objects. The possibilities include: - wireframe, - shaded,")
	.value("AIS_WireFrame", AIS_DisplayMode::AIS_WireFrame)
	.value("AIS_Shaded", AIS_DisplayMode::AIS_Shaded)
	.export_values();


// ENUM: AIS_CLEARMODE
py::enum_<AIS_ClearMode>(mod, "AIS_ClearMode", "Declares which entities in an opened local context are to be cleared of mode settings. Temporary graphic presentations such as those for sub-shapes, for example, are only created for the selection process. By means of these enumerations, they can be cleared from local context.")
	.value("AIS_CM_All", AIS_ClearMode::AIS_CM_All)
	.value("AIS_CM_Interactive", AIS_ClearMode::AIS_CM_Interactive)
	.value("AIS_CM_Filters", AIS_ClearMode::AIS_CM_Filters)
	.value("AIS_CM_StandardModes", AIS_ClearMode::AIS_CM_StandardModes)
	.value("AIS_CM_TemporaryShapePrs", AIS_ClearMode::AIS_CM_TemporaryShapePrs)
	.export_values();


// ENUM: AIS_SELECTSTATUS
py::enum_<AIS_SelectStatus>(mod, "AIS_SelectStatus", "None")
	.value("AIS_SS_Added", AIS_SelectStatus::AIS_SS_Added)
	.value("AIS_SS_Removed", AIS_SelectStatus::AIS_SS_Removed)
	.value("AIS_SS_NotDone", AIS_SelectStatus::AIS_SS_NotDone)
	.export_values();


// ENUM: AIS_SELECTIONMODESCONCURRENCY
py::enum_<AIS_SelectionModesConcurrency>(mod, "AIS_SelectionModesConcurrency", "The mode specifying how multiple active Selection Modes should be treated during activation of new one.")
	.value("AIS_SelectionModesConcurrency_Single", AIS_SelectionModesConcurrency::AIS_SelectionModesConcurrency_Single)
	.value("AIS_SelectionModesConcurrency_GlobalOrLocal", AIS_SelectionModesConcurrency::AIS_SelectionModesConcurrency_GlobalOrLocal)
	.value("AIS_SelectionModesConcurrency_Multiple", AIS_SelectionModesConcurrency::AIS_SelectionModesConcurrency_Multiple)
	.export_values();


// ENUM: AIS_STATUSOFDETECTION
py::enum_<AIS_StatusOfDetection>(mod, "AIS_StatusOfDetection", "None")
	.value("AIS_SOD_Error", AIS_StatusOfDetection::AIS_SOD_Error)
	.value("AIS_SOD_Nothing", AIS_StatusOfDetection::AIS_SOD_Nothing)
	.value("AIS_SOD_AllBad", AIS_StatusOfDetection::AIS_SOD_AllBad)
	.value("AIS_SOD_Selected", AIS_StatusOfDetection::AIS_SOD_Selected)
	.value("AIS_SOD_OnlyOneDetected", AIS_StatusOfDetection::AIS_SOD_OnlyOneDetected)
	.value("AIS_SOD_OnlyOneGood", AIS_StatusOfDetection::AIS_SOD_OnlyOneGood)
	.value("AIS_SOD_SeveralGood", AIS_StatusOfDetection::AIS_SOD_SeveralGood)
	.export_values();


// ENUM: AIS_STATUSOFPICK
py::enum_<AIS_StatusOfPick>(mod, "AIS_StatusOfPick", "None")
	.value("AIS_SOP_Error", AIS_StatusOfPick::AIS_SOP_Error)
	.value("AIS_SOP_NothingSelected", AIS_StatusOfPick::AIS_SOP_NothingSelected)
	.value("AIS_SOP_Removed", AIS_StatusOfPick::AIS_SOP_Removed)
	.value("AIS_SOP_OneSelected", AIS_StatusOfPick::AIS_SOP_OneSelected)
	.value("AIS_SOP_SeveralSelected", AIS_StatusOfPick::AIS_SOP_SeveralSelected)
	.export_values();


// ENUM: AIS_TYPEOFISO
py::enum_<AIS_TypeOfIso>(mod, "AIS_TypeOfIso", "Declares the type of isoparameter displayed.")
	.value("AIS_TOI_IsoU", AIS_TypeOfIso::AIS_TOI_IsoU)
	.value("AIS_TOI_IsoV", AIS_TypeOfIso::AIS_TOI_IsoV)
	.value("AIS_TOI_Both", AIS_TypeOfIso::AIS_TOI_Both)
	.export_values();


// ENUM: AIS_TYPEOFAXIS
py::enum_<AIS_TypeOfAxis>(mod, "AIS_TypeOfAxis", "Declares the type of axis.")
	.value("AIS_TOAX_Unknown", AIS_TypeOfAxis::AIS_TOAX_Unknown)
	.value("AIS_TOAX_XAxis", AIS_TypeOfAxis::AIS_TOAX_XAxis)
	.value("AIS_TOAX_YAxis", AIS_TypeOfAxis::AIS_TOAX_YAxis)
	.value("AIS_TOAX_ZAxis", AIS_TypeOfAxis::AIS_TOAX_ZAxis)
	.export_values();


// ENUM: AIS_CONNECTSTATUS
py::enum_<AIS_ConnectStatus>(mod, "AIS_ConnectStatus", "Gives the status of connection of an Interactive Object. This will be one of the following: - No connection - Connection - Transformation - Both connection and transformation This enumeration is used in AIS_ConnectedInteractive. Transform indicates that the Interactive Object reference geometry has changed location relative to the reference geometry.")
	.value("AIS_CS_None", AIS_ConnectStatus::AIS_CS_None)
	.value("AIS_CS_Connection", AIS_ConnectStatus::AIS_CS_Connection)
	.value("AIS_CS_Transform", AIS_ConnectStatus::AIS_CS_Transform)
	.value("AIS_CS_Both", AIS_ConnectStatus::AIS_CS_Both)
	.export_values();


// ENUM: AIS_DRAGACTION
py::enum_<AIS_DragAction>(mod, "AIS_DragAction", "Dragging action.")
	.value("AIS_DragAction_Start", AIS_DragAction::AIS_DragAction_Start)
	.value("AIS_DragAction_Update", AIS_DragAction::AIS_DragAction_Update)
	.value("AIS_DragAction_Stop", AIS_DragAction::AIS_DragAction_Stop)
	.value("AIS_DragAction_Abort", AIS_DragAction::AIS_DragAction_Abort)
	.export_values();


// ENUM: AIS_TYPEOFDIST
py::enum_<AIS_TypeOfDist>(mod, "AIS_TypeOfDist", "To declare the type of distance.")
	.value("AIS_TOD_Unknown", AIS_TypeOfDist::AIS_TOD_Unknown)
	.value("AIS_TOD_Horizontal", AIS_TypeOfDist::AIS_TOD_Horizontal)
	.value("AIS_TOD_Vertical", AIS_TypeOfDist::AIS_TOD_Vertical)
	.export_values();


// ENUM: AIS_TYPEOFATTRIBUTE
py::enum_<AIS_TypeOfAttribute>(mod, "AIS_TypeOfAttribute", "None")
	.value("AIS_TOA_Line", AIS_TypeOfAttribute::AIS_TOA_Line)
	.value("AIS_TOA_Dimension", AIS_TypeOfAttribute::AIS_TOA_Dimension)
	.value("AIS_TOA_Wire", AIS_TypeOfAttribute::AIS_TOA_Wire)
	.value("AIS_TOA_Plane", AIS_TypeOfAttribute::AIS_TOA_Plane)
	.value("AIS_TOA_Vector", AIS_TypeOfAttribute::AIS_TOA_Vector)
	.value("AIS_TOA_UIso", AIS_TypeOfAttribute::AIS_TOA_UIso)
	.value("AIS_TOA_VIso", AIS_TypeOfAttribute::AIS_TOA_VIso)
	.value("AIS_TOA_Free", AIS_TypeOfAttribute::AIS_TOA_Free)
	.value("AIS_TOA_UnFree", AIS_TypeOfAttribute::AIS_TOA_UnFree)
	.value("AIS_TOA_Section", AIS_TypeOfAttribute::AIS_TOA_Section)
	.value("AIS_TOA_Hidden", AIS_TypeOfAttribute::AIS_TOA_Hidden)
	.value("AIS_TOA_Seen", AIS_TypeOfAttribute::AIS_TOA_Seen)
	.value("AIS_TOA_FaceBoundary", AIS_TypeOfAttribute::AIS_TOA_FaceBoundary)
	.value("AIS_TOA_FirstAxis", AIS_TypeOfAttribute::AIS_TOA_FirstAxis)
	.value("AIS_TOA_SecondAxis", AIS_TypeOfAttribute::AIS_TOA_SecondAxis)
	.value("AIS_TOA_ThirdAxis", AIS_TypeOfAttribute::AIS_TOA_ThirdAxis)
	.export_values();


// ENUM: AIS_KINDOFRELATION
py::enum_<AIS_KindOfRelation>(mod, "AIS_KindOfRelation", "None")
	.value("AIS_KOR_NONE", AIS_KindOfRelation::AIS_KOR_NONE)
	.value("AIS_KOR_CONCENTRIC", AIS_KindOfRelation::AIS_KOR_CONCENTRIC)
	.value("AIS_KOR_EQUALDISTANCE", AIS_KindOfRelation::AIS_KOR_EQUALDISTANCE)
	.value("AIS_KOR_EQUALRADIUS", AIS_KindOfRelation::AIS_KOR_EQUALRADIUS)
	.value("AIS_KOR_FIX", AIS_KindOfRelation::AIS_KOR_FIX)
	.value("AIS_KOR_IDENTIC", AIS_KindOfRelation::AIS_KOR_IDENTIC)
	.value("AIS_KOR_OFFSET", AIS_KindOfRelation::AIS_KOR_OFFSET)
	.value("AIS_KOR_PARALLEL", AIS_KindOfRelation::AIS_KOR_PARALLEL)
	.value("AIS_KOR_PERPENDICULAR", AIS_KindOfRelation::AIS_KOR_PERPENDICULAR)
	.value("AIS_KOR_TANGENT", AIS_KindOfRelation::AIS_KOR_TANGENT)
	.value("AIS_KOR_SYMMETRIC", AIS_KindOfRelation::AIS_KOR_SYMMETRIC)
	.export_values();


// ENUM: AIS_KINDOFUNIT
py::enum_<AIS_KindOfUnit>(mod, "AIS_KindOfUnit", "Declares the type of Interactive Object unit.")
	.value("AIS_TOU_LENGTH", AIS_KindOfUnit::AIS_TOU_LENGTH)
	.value("AIS_TOU_SURFACE", AIS_KindOfUnit::AIS_TOU_SURFACE)
	.value("AIS_TOU_VOLUME", AIS_KindOfUnit::AIS_TOU_VOLUME)
	.value("AIS_TOU_PLANE_ANGLE", AIS_KindOfUnit::AIS_TOU_PLANE_ANGLE)
	.value("AIS_TOU_SOLID_ANGLE", AIS_KindOfUnit::AIS_TOU_SOLID_ANGLE)
	.value("AIS_TOU_MASS", AIS_KindOfUnit::AIS_TOU_MASS)
	.value("AIS_TOU_FORCE", AIS_KindOfUnit::AIS_TOU_FORCE)
	.value("AIS_TOU_TIME", AIS_KindOfUnit::AIS_TOU_TIME)
	.export_values();


// ENUM: AIS_MANIPULATORMODE
py::enum_<AIS_ManipulatorMode>(mod, "AIS_ManipulatorMode", "Mode to make definite kind of transformations with AIS_Manipulator object.")
	.value("AIS_MM_None", AIS_ManipulatorMode::AIS_MM_None)
	.value("AIS_MM_Translation", AIS_ManipulatorMode::AIS_MM_Translation)
	.value("AIS_MM_Rotation", AIS_ManipulatorMode::AIS_MM_Rotation)
	.value("AIS_MM_Scaling", AIS_ManipulatorMode::AIS_MM_Scaling)
	.value("AIS_MM_TranslationPlane", AIS_ManipulatorMode::AIS_MM_TranslationPlane)
	.export_values();


// ENUM: AIS_MOUSEGESTURE
py::enum_<AIS_MouseGesture>(mod, "AIS_MouseGesture", "Mouse gesture - only one can be active at one moment.")
	.value("AIS_MouseGesture_NONE", AIS_MouseGesture::AIS_MouseGesture_NONE)
	.value("AIS_MouseGesture_SelectRectangle", AIS_MouseGesture::AIS_MouseGesture_SelectRectangle)
	.value("AIS_MouseGesture_SelectLasso", AIS_MouseGesture::AIS_MouseGesture_SelectLasso)
	.value("AIS_MouseGesture_Zoom", AIS_MouseGesture::AIS_MouseGesture_Zoom)
	.value("AIS_MouseGesture_Pan", AIS_MouseGesture::AIS_MouseGesture_Pan)
	.value("AIS_MouseGesture_RotateOrbit", AIS_MouseGesture::AIS_MouseGesture_RotateOrbit)
	.value("AIS_MouseGesture_RotateView", AIS_MouseGesture::AIS_MouseGesture_RotateView)
	.export_values();


// ENUM: AIS_NAVIGATIONMODE
py::enum_<AIS_NavigationMode>(mod, "AIS_NavigationMode", "Camera navigation mode.")
	.value("AIS_NavigationMode_Orbit", AIS_NavigationMode::AIS_NavigationMode_Orbit)
	.value("AIS_NavigationMode_FirstPersonFlight", AIS_NavigationMode::AIS_NavigationMode_FirstPersonFlight)
	.value("AIS_NavigationMode_FirstPersonWalk", AIS_NavigationMode::AIS_NavigationMode_FirstPersonWalk)
	.export_values();


// ENUM: AIS_TYPEOFPLANE
py::enum_<AIS_TypeOfPlane>(mod, "AIS_TypeOfPlane", "Declares the type of plane.")
	.value("AIS_TOPL_Unknown", AIS_TypeOfPlane::AIS_TOPL_Unknown)
	.value("AIS_TOPL_XYPlane", AIS_TypeOfPlane::AIS_TOPL_XYPlane)
	.value("AIS_TOPL_XZPlane", AIS_TypeOfPlane::AIS_TOPL_XZPlane)
	.value("AIS_TOPL_YZPlane", AIS_TypeOfPlane::AIS_TOPL_YZPlane)
	.export_values();


// ENUM: AIS_ROTATIONMODE
py::enum_<AIS_RotationMode>(mod, "AIS_RotationMode", "Camera rotation mode.")
	.value("AIS_RotationMode_BndBoxActive", AIS_RotationMode::AIS_RotationMode_BndBoxActive)
	.value("AIS_RotationMode_PickLast", AIS_RotationMode::AIS_RotationMode_PickLast)
	.value("AIS_RotationMode_PickCenter", AIS_RotationMode::AIS_RotationMode_PickCenter)
	.value("AIS_RotationMode_CameraAt", AIS_RotationMode::AIS_RotationMode_CameraAt)
	.value("AIS_RotationMode_BndBoxScene", AIS_RotationMode::AIS_RotationMode_BndBoxScene)
	.export_values();


// ENUM: AIS_STANDARDDATUM
py::enum_<AIS_StandardDatum>(mod, "AIS_StandardDatum", "Declares the type of standard datum of an Interactive Object.")
	.value("AIS_SD_None", AIS_StandardDatum::AIS_SD_None)
	.value("AIS_SD_Point", AIS_StandardDatum::AIS_SD_Point)
	.value("AIS_SD_Axis", AIS_StandardDatum::AIS_SD_Axis)
	.value("AIS_SD_Trihedron", AIS_StandardDatum::AIS_SD_Trihedron)
	.value("AIS_SD_PlaneTrihedron", AIS_StandardDatum::AIS_SD_PlaneTrihedron)
	.value("AIS_SD_Line", AIS_StandardDatum::AIS_SD_Line)
	.value("AIS_SD_Circle", AIS_StandardDatum::AIS_SD_Circle)
	.value("AIS_SD_Plane", AIS_StandardDatum::AIS_SD_Plane)
	.export_values();


// ENUM: AIS_TRIHEDRONSELECTIONMODE
py::enum_<AIS_TrihedronSelectionMode>(mod, "AIS_TrihedronSelectionMode", "Enumeration defining selection modes supported by AIS_Trihedron.")
	.value("AIS_TrihedronSelectionMode_EntireObject", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_EntireObject)
	.value("AIS_TrihedronSelectionMode_Origin", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_Origin)
	.value("AIS_TrihedronSelectionMode_Axes", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_Axes)
	.value("AIS_TrihedronSelectionMode_MainPlanes", AIS_TrihedronSelectionMode::AIS_TrihedronSelectionMode_MainPlanes)
	.export_values();


// ENUM: AIS_VIEWSELECTIONTOOL
py::enum_<AIS_ViewSelectionTool>(mod, "AIS_ViewSelectionTool", "Selection mode")
	.value("AIS_ViewSelectionTool_Picking", AIS_ViewSelectionTool::AIS_ViewSelectionTool_Picking)
	.value("AIS_ViewSelectionTool_RubberBand", AIS_ViewSelectionTool::AIS_ViewSelectionTool_RubberBand)
	.value("AIS_ViewSelectionTool_Polygon", AIS_ViewSelectionTool::AIS_ViewSelectionTool_Polygon)
	.export_values();

py::enum_<AIS_ViewInputBufferType>(mod, "AIS_ViewInputBufferType", "Input buffer type.")
	.value("AIS_ViewInputBufferType_UI", AIS_ViewInputBufferType::AIS_ViewInputBufferType_UI)
	.value("AIS_ViewInputBufferType_GL", AIS_ViewInputBufferType::AIS_ViewInputBufferType_GL)
	.export_values();


// ENUM: AIS_WALKTRANSLATION
py::enum_<AIS_WalkTranslation>(mod, "AIS_WalkTranslation", "Walking translation components.")
	.value("AIS_WalkTranslation_Forward", AIS_WalkTranslation::AIS_WalkTranslation_Forward)
	.value("AIS_WalkTranslation_Side", AIS_WalkTranslation::AIS_WalkTranslation_Side)
	.value("AIS_WalkTranslation_Up", AIS_WalkTranslation::AIS_WalkTranslation_Up)
	.export_values();

py::enum_<AIS_WalkRotation>(mod, "AIS_WalkRotation", "Walking rotation components.")
	.value("AIS_WalkRotation_Yaw", AIS_WalkRotation::AIS_WalkRotation_Yaw)
	.value("AIS_WalkRotation_Pitch", AIS_WalkRotation::AIS_WalkRotation_Pitch)
	.value("AIS_WalkRotation_Roll", AIS_WalkRotation::AIS_WalkRotation_Roll)
	.export_values();


// CLASS: AIS
py::class_<AIS> cls_AIS(mod, "AIS", "Application Interactive Services provide the means to create links between an application GUI viewer and the packages which are used to manage selection and presentation. The tools AIS defined in order to do this include different sorts of entities: both the selectable viewable objects themselves and the context and attribute managers to define their selection and display. To orient the user as he works in a modeling environment, views and selections must be comprehensible. There must be several different sorts of selectable and viewable object defined. These must also be interactive, that is, connecting graphic representation and the underlying reference geometry. These entities are called Interactive Objects, and are divided into four types: - the Datum - the Relation - the Object - None. The Datum groups together the construction elements such as lines, circles, points, trihedra, plane trihedra, planes and axes. The Relation is made up of constraints on one or more interactive shapes and the corresponding reference geometry. For example, you might want to constrain two edges in a parallel relation. This contraint is considered as an object in its own right, and is shown as a sensitive primitive. This takes the graphic form of a perpendicular arrow marked with the || symbol and lying between the two edges. The Object type includes topological shapes, and connections between shapes. None, in order not to eliminate the object, tells the application to look further until it finds an object definition in its generation which is accepted. Inside these categories, you have the possibility of an additional characterization by means of a signature. The signature provides an index to the further characterization. By default, the Interactive Object has a None type and a signature of 0 (equivalent to None.) If you want to give a particular type and signature to your interactive object, you must redefine the two virtual methods: Type and Signature. In the C++ inheritance structure of the package, each class representing a specific Interactive Object inherits AIS_InteractiveObject. Among these inheriting classes, AIS_Relation functions as the abstract mother class for tinheriting classes defining display of specific relational constraints and types of dimension. Some of these include: - display of constraints based on relations of symmetry, tangency, parallelism and concentricity - display of dimensions for angles, offsets, diameters, radii and chamfers. No viewer can show everything at once with any coherence or clarity. Views must be managed carefully both sequentially and at any given instant. Another function of the view is that of a context to carry out design in. The design changes are applied to the objects in the view and then extended to the underlying reference geometry by a solver. To make sense of this complicated visual data, several display and selection tools are required. To facilitate management, each object and each construction element has a selection priority. There are also means to modify the default priority. To define an environment of dynamic detection, you can use standard filter classes or create your own. A filter questions the owner of the sensitive primitive to determine if it has the the desired qualities. If it answers positively, it is kept. If not, it is rejected. The standard filters supplied in AIS include: - AIS_AttributeFilter - AIS_SignatureFilter - AIS_TypeFilter. A set of functions allows you to choose the interactive objects which you want to act on, the selection modes which you want to activate. An interactive object can have a certain number of graphic attributes which are specific to it, such as visualization mode, color, and material. By the same token, the interactive context has a set of graphic attributes, the Drawer which is valid by default for the objects it controls. When an interactive object is visualized, the required graphic attributes are first taken from the object's own Drawer if one exists, or from the context drawer for the others.");

// Constructors
cls_AIS.def(py::init<>());

// Methods
// cls_AIS.def_static("operator new_", (void * (*)(size_t)) &AIS::operator new, "None", py::arg("theSize"));
// cls_AIS.def_static("operator delete_", (void (*)(void *)) &AIS::operator delete, "None", py::arg("theAddress"));
// cls_AIS.def_static("operator new[]_", (void * (*)(size_t)) &AIS::operator new[], "None", py::arg("theSize"));
// cls_AIS.def_static("operator delete[]_", (void (*)(void *)) &AIS::operator delete[], "None", py::arg("theAddress"));
// cls_AIS.def_static("operator new_", (void * (*)(size_t, void *)) &AIS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS.def_static("operator delete_", (void (*)(void *, void *)) &AIS::operator delete, "None", py::arg(""), py::arg(""));
cls_AIS.def_static("Nearest_", (gp_Pnt (*)(const TopoDS_Shape &, const gp_Pnt &)) &AIS::Nearest, "Returns the nearest point in a shape. This is used by several classes in calculation of dimensions.", py::arg("aShape"), py::arg("aPoint"));
cls_AIS.def_static("Nearest_", (gp_Pnt (*)(const gp_Lin &, const gp_Pnt &)) &AIS::Nearest, "Returns the nearest point on the line.", py::arg("theLine"), py::arg("thePoint"));
cls_AIS.def_static("Nearest_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, gp_Pnt &)) &AIS::Nearest, "For the given point finds nearest point on the curve,", py::arg("theCurve"), py::arg("thePoint"), py::arg("theFirstPoint"), py::arg("theLastPoint"), py::arg("theNearestPoint"));
cls_AIS.def_static("Farest_", (gp_Pnt (*)(const TopoDS_Shape &, const gp_Pnt &)) &AIS::Farest, "None", py::arg("aShape"), py::arg("aPoint"));
cls_AIS.def_static("ComputeGeometry_", (Standard_Boolean (*)(const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, gp_Pnt &, gp_Pnt &)) &AIS::ComputeGeometry, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theEdge, opencascade::handle<Geom_Curve> & theCurve, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt, Standard_Boolean & theIsInfinite){ Standard_Boolean rv = AIS::ComputeGeometry(theEdge, theCurve, theFirstPnt, theLastPnt, theIsInfinite); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theIsInfinite); }, "Used by dimensions only. Computes the 3d geometry of <anEdge>. Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"), py::arg("theIsInfinite"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theEdge, opencascade::handle<Geom_Curve> & theCurve, gp_Pnt & theFirstPnt, gp_Pnt & theLastPnt, opencascade::handle<Geom_Curve> & theExtCurve, Standard_Boolean & theIsInfinite, Standard_Boolean & theIsOnPlane, const opencascade::handle<Geom_Plane> & thePlane){ Standard_Boolean rv = AIS::ComputeGeometry(theEdge, theCurve, theFirstPnt, theLastPnt, theExtCurve, theIsInfinite, theIsOnPlane, thePlane); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, theIsInfinite, theIsOnPlane); }, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any. If <aCurve> is not in the current plane, <extCurve> contains the not projected curve associated to <anEdge>. If <anEdge> is infinite, <isinfinite> = true and the 2 parameters <FirstPnt> and <LastPnt> have no signification. Return TRUE if ok.", py::arg("theEdge"), py::arg("theCurve"), py::arg("theFirstPnt"), py::arg("theLastPnt"), py::arg("theExtCurve"), py::arg("theIsInfinite"), py::arg("theIsOnPlane"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeometry_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, opencascade::handle<Geom_Curve> &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, const opencascade::handle<Geom_Plane> &)) &AIS::ComputeGeometry, "Used by 2d Relation only Computes the 3d geometry of <anEdge> in the current WorkingPlane and the extremities if any Return TRUE if ok.", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theFirstEdge, const TopoDS_Edge & theSecondEdge, opencascade::handle<Geom_Curve> & theFirstCurve, opencascade::handle<Geom_Curve> & theSecondCurve, gp_Pnt & theFirstPnt1, gp_Pnt & theLastPnt1, gp_Pnt & theFirstPnt2, gp_Pnt & theLastPnt2, Standard_Boolean & theIsinfinite1, Standard_Boolean & theIsinfinite2){ Standard_Boolean rv = AIS::ComputeGeometry(theFirstEdge, theSecondEdge, theFirstCurve, theSecondCurve, theFirstPnt1, theLastPnt1, theFirstPnt2, theLastPnt2, theIsinfinite1, theIsinfinite2); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &>(rv, theIsinfinite1, theIsinfinite2); }, "Used by dimensions only.Computes the 3d geometry of<anEdge1> and <anEdge2> and checks if they are infinite.", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("theIsinfinite1"), py::arg("theIsinfinite2"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Edge & theFirstEdge, const TopoDS_Edge & theSecondEdge, Standard_Integer & theExtIndex, opencascade::handle<Geom_Curve> & theFirstCurve, opencascade::handle<Geom_Curve> & theSecondCurve, gp_Pnt & theFirstPnt1, gp_Pnt & theLastPnt1, gp_Pnt & theFirstPnt2, gp_Pnt & theLastPnt2, opencascade::handle<Geom_Curve> & theExtCurve, Standard_Boolean & theIsinfinite1, Standard_Boolean & theIsinfinite2, const opencascade::handle<Geom_Plane> & thePlane){ Standard_Boolean rv = AIS::ComputeGeometry(theFirstEdge, theSecondEdge, theExtIndex, theFirstCurve, theSecondCurve, theFirstPnt1, theLastPnt1, theFirstPnt2, theLastPnt2, theExtCurve, theIsinfinite1, theIsinfinite2, thePlane); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Boolean &, Standard_Boolean &>(rv, theExtIndex, theIsinfinite1, theIsinfinite2); }, "Used by 2d Relation only Computes the 3d geometry of<anEdge1> and <anEdge2> in the current Plane and the extremities if any. Return in ExtCurve the 3d curve (not projected in the plane) of the first edge if <indexExt> =1 or of the 2nd edge if <indexExt> = 2. If <indexExt> = 0, ExtCurve is Null. if there is an edge external to the plane, <isinfinite> is true if this edge is infinite. So, the extremities of it are not significant. Return TRUE if ok", py::arg("theFirstEdge"), py::arg("theSecondEdge"), py::arg("theExtIndex"), py::arg("theFirstCurve"), py::arg("theSecondCurve"), py::arg("theFirstPnt1"), py::arg("theLastPnt1"), py::arg("theFirstPnt2"), py::arg("theLastPnt2"), py::arg("theExtCurve"), py::arg("theIsinfinite1"), py::arg("theIsinfinite2"), py::arg("thePlane"));
cls_AIS.def_static("ComputeGeomCurve_", [](opencascade::handle<Geom_Curve> & aCurve, const Standard_Real first1, const Standard_Real last1, gp_Pnt & FirstPnt1, gp_Pnt & LastPnt1, const opencascade::handle<Geom_Plane> & aPlane, Standard_Boolean & isOnPlane){ Standard_Boolean rv = AIS::ComputeGeomCurve(aCurve, first1, last1, FirstPnt1, LastPnt1, aPlane, isOnPlane); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isOnPlane); }, "Checks if aCurve belongs to aPlane; if not, projects aCurve in aPlane and returns aCurve; Return TRUE if ok", py::arg("aCurve"), py::arg("first1"), py::arg("last1"), py::arg("FirstPnt1"), py::arg("LastPnt1"), py::arg("aPlane"), py::arg("isOnPlane"));
cls_AIS.def_static("ComputeGeometry_", [](const TopoDS_Vertex & aVertex, gp_Pnt & point, const opencascade::handle<Geom_Plane> & aPlane, Standard_Boolean & isOnPlane){ Standard_Boolean rv = AIS::ComputeGeometry(aVertex, point, aPlane, isOnPlane); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, isOnPlane); }, "None", py::arg("aVertex"), py::arg("point"), py::arg("aPlane"), py::arg("isOnPlane"));
cls_AIS.def_static("GetPlaneFromFace_", [](const TopoDS_Face & aFace, gp_Pln & aPlane, opencascade::handle<Geom_Surface> & aSurf, AIS_KindOfSurface & aSurfType, Standard_Real & Offset){ Standard_Boolean rv = AIS::GetPlaneFromFace(aFace, aPlane, aSurf, aSurfType, Offset); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Offset); }, "Tryes to get Plane from Face. Returns Surface of Face in aSurf. Returns Standard_True and Plane of Face in aPlane in following cases: Face is Plane, Offset of Plane, Extrusion of Line and Offset of Extrusion of Line Returns pure type of Surface which can be: Plane, Cylinder, Cone, Sphere, Torus, SurfaceOfRevolution, SurfaceOfExtrusion", py::arg("aFace"), py::arg("aPlane"), py::arg("aSurf"), py::arg("aSurfType"), py::arg("Offset"));
cls_AIS.def_static("InitFaceLength_", [](const TopoDS_Face & aFace, gp_Pln & aPlane, opencascade::handle<Geom_Surface> & aSurface, AIS_KindOfSurface & aSurfaceType, Standard_Real & anOffset){ AIS::InitFaceLength(aFace, aPlane, aSurface, aSurfaceType, anOffset); return anOffset; }, "None", py::arg("aFace"), py::arg("aPlane"), py::arg("aSurface"), py::arg("aSurfaceType"), py::arg("anOffset"));
cls_AIS.def_static("InitLengthBetweenCurvilinearFaces_", (void (*)(const TopoDS_Face &, const TopoDS_Face &, opencascade::handle<Geom_Surface> &, opencascade::handle<Geom_Surface> &, gp_Pnt &, gp_Pnt &, gp_Dir &)) &AIS::InitLengthBetweenCurvilinearFaces, "Finds attachment points on two curvilinear faces for length dimension.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theFirstSurf"), py::arg("theSecondSurf"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theDirOnPlane"));
cls_AIS.def_static("InitAngleBetweenPlanarFaces_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, gp_Pnt & a2, gp_Pnt & a3, gp_Pnt & a4) -> Standard_Boolean { return AIS::InitAngleBetweenPlanarFaces(a0, a1, a2, a3, a4); });
cls_AIS.def_static("InitAngleBetweenPlanarFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, gp_Pnt &, gp_Pnt &, gp_Pnt &, const Standard_Boolean)) &AIS::InitAngleBetweenPlanarFaces, "Finds three points for the angle dimension between two planes.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theCenter"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theIsFirstPointSet"));
cls_AIS.def_static("InitAngleBetweenCurvilinearFaces_", [](const TopoDS_Face & a0, const TopoDS_Face & a1, const AIS_KindOfSurface a2, const AIS_KindOfSurface a3, gp_Pnt & a4, gp_Pnt & a5, gp_Pnt & a6) -> Standard_Boolean { return AIS::InitAngleBetweenCurvilinearFaces(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("InitAngleBetweenCurvilinearFaces_", (Standard_Boolean (*)(const TopoDS_Face &, const TopoDS_Face &, const AIS_KindOfSurface, const AIS_KindOfSurface, gp_Pnt &, gp_Pnt &, gp_Pnt &, const Standard_Boolean)) &AIS::InitAngleBetweenCurvilinearFaces, "Finds three points for the angle dimension between two curvilinear surfaces.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("theFirstSurfType"), py::arg("theSecondSurfType"), py::arg("theCenter"), py::arg("theFirstAttach"), py::arg("theSecondAttach"), py::arg("theIsFirstPointSet"));
cls_AIS.def_static("ProjectPointOnPlane_", (gp_Pnt (*)(const gp_Pnt &, const gp_Pln &)) &AIS::ProjectPointOnPlane, "None", py::arg("aPoint"), py::arg("aPlane"));
cls_AIS.def_static("ProjectPointOnLine_", (gp_Pnt (*)(const gp_Pnt &, const gp_Lin &)) &AIS::ProjectPointOnLine, "None", py::arg("aPoint"), py::arg("aLine"));
cls_AIS.def_static("TranslatePointToBound_", (gp_Pnt (*)(const gp_Pnt &, const gp_Dir &, const Bnd_Box &)) &AIS::TranslatePointToBound, "None", py::arg("aPoint"), py::arg("aDir"), py::arg("aBndBox"));
cls_AIS.def_static("InDomain_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &AIS::InDomain, "returns True if point with anAttachPar is in domain of arc", py::arg("aFirstPar"), py::arg("aLastPar"), py::arg("anAttachPar"));
cls_AIS.def_static("NearestApex_", [](const gp_Elips & elips, const gp_Pnt & pApex, const gp_Pnt & nApex, const Standard_Real fpara, const Standard_Real lpara, Standard_Boolean & IsInDomain){ gp_Pnt rv = AIS::NearestApex(elips, pApex, nApex, fpara, lpara, IsInDomain); return std::tuple<gp_Pnt, Standard_Boolean &>(rv, IsInDomain); }, "computes nearest to ellipse arc apex", py::arg("elips"), py::arg("pApex"), py::arg("nApex"), py::arg("fpara"), py::arg("lpara"), py::arg("IsInDomain"));
cls_AIS.def_static("DistanceFromApex_", (Standard_Real (*)(const gp_Elips &, const gp_Pnt &, const Standard_Real)) &AIS::DistanceFromApex, "computes length of ellipse arc in parametric units", py::arg("elips"), py::arg("Apex"), py::arg("par"));
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6, const Standard_Real a7) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_AIS.def_static("ComputeProjEdgePresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Edge & a2, const opencascade::handle<Geom_Curve> & a3, const gp_Pnt & a4, const gp_Pnt & a5, const Quantity_NameOfColor a6, const Standard_Real a7, const Aspect_TypeOfLine a8) -> void { return AIS::ComputeProjEdgePresentation(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_AIS.def_static("ComputeProjEdgePresentation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Quantity_NameOfColor, const Standard_Real, const Aspect_TypeOfLine, const Aspect_TypeOfLine)) &AIS::ComputeProjEdgePresentation, "None", py::arg("aPres"), py::arg("aDrawer"), py::arg("anEdge"), py::arg("ProjCurve"), py::arg("FirstP"), py::arg("LastP"), py::arg("aColor"), py::arg("aWidth"), py::arg("aProjTOL"), py::arg("aCallTOL"));
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4, const Standard_Real a5) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4, a5); });
cls_AIS.def_static("ComputeProjVertexPresentation_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TopoDS_Vertex & a2, const gp_Pnt & a3, const Quantity_NameOfColor a4, const Standard_Real a5, const Aspect_TypeOfMarker a6) -> void { return AIS::ComputeProjVertexPresentation(a0, a1, a2, a3, a4, a5, a6); });
cls_AIS.def_static("ComputeProjVertexPresentation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TopoDS_Vertex &, const gp_Pnt &, const Quantity_NameOfColor, const Standard_Real, const Aspect_TypeOfMarker, const Aspect_TypeOfLine)) &AIS::ComputeProjVertexPresentation, "None", py::arg("aPres"), py::arg("aDrawer"), py::arg("aVertex"), py::arg("ProjPoint"), py::arg("aColor"), py::arg("aWidth"), py::arg("aProjTOM"), py::arg("aCallTOL"));

// CLASS: AIS_DIMENSIONOWNER
py::class_<AIS_DimensionOwner, opencascade::handle<AIS_DimensionOwner>, SelectMgr_EntityOwner> cls_AIS_DimensionOwner(mod, "AIS_DimensionOwner", "The owner is the entity which makes it possible to link the sensitive primitives and the reference shapes that you want to detect. It stocks the various pieces of information which make it possible to find objects. An owner has a priority which you can modulate, so as to make one entity more selectable than another. You might want to make edges more selectable than faces, for example. In that case, you could attribute sa higher priority to the one compared to the other. An edge, could have priority 5, for example, and a face, priority 4. The default priority is 5.");

// Constructors
cls_AIS_DimensionOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const AIS_DimensionSelectionMode>(), py::arg("theSelObject"), py::arg("theSelMode"));
cls_AIS_DimensionOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const AIS_DimensionSelectionMode, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theSelMode"), py::arg("thePriority"));

// Methods
cls_AIS_DimensionOwner.def_static("get_type_name_", (const char * (*)()) &AIS_DimensionOwner::get_type_name, "None");
cls_AIS_DimensionOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_DimensionOwner::get_type_descriptor, "None");
cls_AIS_DimensionOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_DimensionOwner::*)() const) &AIS_DimensionOwner::DynamicType, "None");
cls_AIS_DimensionOwner.def("SelectionMode", (AIS_DimensionSelectionMode (AIS_DimensionOwner::*)() const) &AIS_DimensionOwner::SelectionMode, "None");
cls_AIS_DimensionOwner.def("HilightWithColor", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); });
cls_AIS_DimensionOwner.def("HilightWithColor", (void (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_DimensionOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_DimensionOwner.def("IsHilighted", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); });
cls_AIS_DimensionOwner.def("IsHilighted", (Standard_Boolean (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_DimensionOwner::IsHilighted, "Returns true if an object with the selection mode aMode is highlighted in the presentation manager aPM.", py::arg("thePM"), py::arg("theMode"));
cls_AIS_DimensionOwner.def("Unhilight", [](AIS_DimensionOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); });
cls_AIS_DimensionOwner.def("Unhilight", (void (AIS_DimensionOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_DimensionOwner::Unhilight, "Removes highlighting from the selected part of dimension.", py::arg("thePM"), py::arg("theMode"));

// CLASS: AIS_INTERACTIVEOBJECT
py::class_<AIS_InteractiveObject, opencascade::handle<AIS_InteractiveObject>, SelectMgr_SelectableObject> cls_AIS_InteractiveObject(mod, "AIS_InteractiveObject", "Defines a class of objects with display and selection services. Entities which are visualized and selected are Interactive Objects. Specific attributes of entities such as arrow aspect for dimensions must be loaded in a Prs3d_Drawer.");

// Methods
cls_AIS_InteractiveObject.def_static("get_type_name_", (const char * (*)()) &AIS_InteractiveObject::get_type_name, "None");
cls_AIS_InteractiveObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_InteractiveObject::get_type_descriptor, "None");
cls_AIS_InteractiveObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::DynamicType, "None");
cls_AIS_InteractiveObject.def("Type", (AIS_KindOfInteractive (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Type, "Returns the kind of Interactive Object; AIS_KOI_None by default.");
cls_AIS_InteractiveObject.def("Signature", (Standard_Integer (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Signature, "Specifies additional characteristics of Interactive Object of Type(); -1 by default. Among the datums, this signature is attributed to the shape. The remaining datums have the following default signatures: - Point signature 1 - Axis signature 2 - Trihedron signature 3 - PlaneTrihedron signature 4 - Line signature 5 - Circle signature 6 - Plane signature 7.");
cls_AIS_InteractiveObject.def("Redisplay", [](AIS_InteractiveObject &self) -> void { return self.Redisplay(); });
cls_AIS_InteractiveObject.def("Redisplay", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::Redisplay, "Updates the active presentation; if <AllModes> = Standard_True all the presentations inside are recomputed. IMPORTANT: It is preferable to call Redisplay method of corresponding AIS_InteractiveContext instance for cases when it is accessible. This method just redirects call to myCTXPtr, so this class field must be up to date for proper result.", py::arg("AllModes"));
cls_AIS_InteractiveObject.def("HasInteractiveContext", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasInteractiveContext, "Indicates whether the Interactive Object has a pointer to an interactive context.");
cls_AIS_InteractiveObject.def("InteractiveContext", (AIS_InteractiveContext * (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::InteractiveContext, "Returns the context pointer to the interactive context.");
cls_AIS_InteractiveObject.def("SetContext", (void (AIS_InteractiveObject::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_InteractiveObject::SetContext, "Sets the interactive context aCtx and provides a link to the default drawing tool or 'Drawer' if there is none.", py::arg("aCtx"));
cls_AIS_InteractiveObject.def("HasOwner", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasOwner, "Returns true if the object has an owner attributed to it. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient.");
cls_AIS_InteractiveObject.def("GetOwner", (const opencascade::handle<Standard_Transient> & (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::GetOwner, "Returns the owner of the Interactive Object. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient. There are two types of owners: - Direct owners, decomposition shapes such as edges, wires, and faces. - Users, presentable objects connecting to sensitive primitives, or a shape which has been decomposed.");
cls_AIS_InteractiveObject.def("SetOwner", (void (AIS_InteractiveObject::*)(const opencascade::handle<Standard_Transient> &)) &AIS_InteractiveObject::SetOwner, "Allows you to attribute the owner theApplicativeEntity to an Interactive Object. This can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of. The owner takes the form of a transient.", py::arg("theApplicativeEntity"));
cls_AIS_InteractiveObject.def("ClearOwner", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::ClearOwner, "Each Interactive Object has methods which allow us to attribute an Owner to it in the form of a Transient. This method removes the owner from the graphic entity.");
cls_AIS_InteractiveObject.def("GetContext", (opencascade::handle<AIS_InteractiveContext> (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::GetContext, "Returns the context pointer to the interactive context.");
cls_AIS_InteractiveObject.def("HasPresentation", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasPresentation, "Returns TRUE when this object has a presentation in the current DisplayMode()");
cls_AIS_InteractiveObject.def("Presentation", (opencascade::handle<Prs3d_Presentation> (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Presentation, "Returns the current presentation of this object according to the current DisplayMode()");
cls_AIS_InteractiveObject.def("SetAspect", (void (AIS_InteractiveObject::*)(const opencascade::handle<Prs3d_BasicAspect> &)) &AIS_InteractiveObject::SetAspect, "Sets the graphic basic aspect to the current presentation.", py::arg("anAspect"));
cls_AIS_InteractiveObject.def("DumpJson", [](AIS_InteractiveObject &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_AIS_InteractiveObject.def("DumpJson", (void (AIS_InteractiveObject::*)(Standard_OStream &, const Standard_Integer) const) &AIS_InteractiveObject::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));

// CLASS: AIS_DIMENSION
py::class_<AIS_Dimension, opencascade::handle<AIS_Dimension>, AIS_InteractiveObject> cls_AIS_Dimension(mod, "AIS_Dimension", "AIS_Dimension is a base class for 2D presentations of linear (length, diameter, radius) and angular dimensions.");

// Methods
cls_AIS_Dimension.def("GetValue", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::GetValue, "Gets dimension measurement value. If the value to display is not specified by user, then the dimension object is responsible to compute it on its own in model space coordinates.");
cls_AIS_Dimension.def("SetComputedValue", (void (AIS_Dimension::*)()) &AIS_Dimension::SetComputedValue, "Sets computed dimension value. Resets custom value mode if it was set.");
cls_AIS_Dimension.def("SetCustomValue", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetCustomValue, "Sets user-defined dimension value. The user-defined dimension value is specified in model space, and affect by unit conversion during the display.", py::arg("theValue"));
cls_AIS_Dimension.def("SetCustomValue", (void (AIS_Dimension::*)(const TCollection_ExtendedString &)) &AIS_Dimension::SetCustomValue, "Sets user-defined dimension value. Unit conversion during the display is not applyed.", py::arg("theValue"));
cls_AIS_Dimension.def("GetCustomValue", (const TCollection_ExtendedString & (AIS_Dimension::*)() const) &AIS_Dimension::GetCustomValue, "Gets user-defined dimension value.");
cls_AIS_Dimension.def("GetPlane", (const gp_Pln & (AIS_Dimension::*)() const) &AIS_Dimension::GetPlane, "Get the dimension plane in which the 2D dimension presentation is computed. By default, if plane is not defined by user, it is computed automatically after dimension geometry is computed. If computed dimension geometry (points) can't be placed on the user-defined plane, dimension geometry was set as invalid (validity flag is set to false) and dimension presentation will not be computed. If user-defined plane allow geometry placement on it, it will be used for computing of the dimension presentation.");
cls_AIS_Dimension.def("GetGeometryType", (Standard_Integer (AIS_Dimension::*)() const) &AIS_Dimension::GetGeometryType, "Geometry type defines type of shapes on which the dimension is to be built.");
cls_AIS_Dimension.def("SetCustomPlane", (void (AIS_Dimension::*)(const gp_Pln &)) &AIS_Dimension::SetCustomPlane, "Sets user-defined plane where the 2D dimension presentation will be placed. Checks validity of this plane if geometry has been set already. Validity of the plane is checked according to the geometry set and has different criteria for different kinds of dimensions.", py::arg("thePlane"));
cls_AIS_Dimension.def("UnsetCustomPlane", (void (AIS_Dimension::*)()) &AIS_Dimension::UnsetCustomPlane, "Unsets user-defined plane. Therefore the plane for dimension will be computed automatically.");
cls_AIS_Dimension.def("IsTextPositionCustom", (Standard_Boolean (AIS_Dimension::*)() const) &AIS_Dimension::IsTextPositionCustom, "Returns TRUE if text position is set by user with method SetTextPosition().");
cls_AIS_Dimension.def("SetTextPosition", (void (AIS_Dimension::*)(const gp_Pnt &)) &AIS_Dimension::SetTextPosition, "Fixes the absolute text position and adjusts flyout, plane and text alignment according to it. Updates presentation if the text position is valid. ATTENTION! It does not change vertical text alignment.", py::arg(""));
cls_AIS_Dimension.def("GetTextPosition", (const gp_Pnt (AIS_Dimension::*)() const) &AIS_Dimension::GetTextPosition, "Computes absolute text position from dimension parameters (flyout, plane and text alignment).");
cls_AIS_Dimension.def("DimensionAspect", (opencascade::handle<Prs3d_DimensionAspect> (AIS_Dimension::*)() const) &AIS_Dimension::DimensionAspect, "Gets the dimension aspect from AIS object drawer. Dimension aspect contains aspects of line, text and arrows for dimension presentation.");
cls_AIS_Dimension.def("SetDimensionAspect", (void (AIS_Dimension::*)(const opencascade::handle<Prs3d_DimensionAspect> &)) &AIS_Dimension::SetDimensionAspect, "Sets new dimension aspect for the interactive object drawer. The dimension aspect provides dynamic properties which are generally used during computation of dimension presentations.", py::arg("theDimensionAspect"));
cls_AIS_Dimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_Dimension::*)() const) &AIS_Dimension::KindOfDimension, "Returns the kind of dimension.");
cls_AIS_Dimension.def("Type", (AIS_KindOfInteractive (AIS_Dimension::*)() const) &AIS_Dimension::Type, "Returns the kind of interactive.");
cls_AIS_Dimension.def("AcceptDisplayMode", (Standard_Boolean (AIS_Dimension::*)(const Standard_Integer) const) &AIS_Dimension::AcceptDisplayMode, "Returns true if the class of objects accepts the display mode theMode. The interactive context can have a default mode of representation for the set of Interactive Objects. This mode may not be accepted by object.", py::arg("theMode"));
cls_AIS_Dimension.def("DisplaySpecialSymbol", (AIS_DisplaySpecialSymbol (AIS_Dimension::*)() const) &AIS_Dimension::DisplaySpecialSymbol, "Returns dimension special symbol display options.");
cls_AIS_Dimension.def("SetDisplaySpecialSymbol", (void (AIS_Dimension::*)(const AIS_DisplaySpecialSymbol)) &AIS_Dimension::SetDisplaySpecialSymbol, "Specifies whether to display special symbol or not.", py::arg("theDisplaySpecSymbol"));
cls_AIS_Dimension.def("SpecialSymbol", (Standard_ExtCharacter (AIS_Dimension::*)() const) &AIS_Dimension::SpecialSymbol, "Returns special symbol.");
cls_AIS_Dimension.def("SetSpecialSymbol", (void (AIS_Dimension::*)(const Standard_ExtCharacter)) &AIS_Dimension::SetSpecialSymbol, "Specifies special symbol.", py::arg("theSpecialSymbol"));
cls_AIS_Dimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_Dimension::*)() const) &AIS_Dimension::GetDisplayUnits, "None");
cls_AIS_Dimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_Dimension::*)() const) &AIS_Dimension::GetModelUnits, "None");
cls_AIS_Dimension.def("SetDisplayUnits", (void (AIS_Dimension::*)(const TCollection_AsciiString &)) &AIS_Dimension::SetDisplayUnits, "None", py::arg(""));
cls_AIS_Dimension.def("SetModelUnits", (void (AIS_Dimension::*)(const TCollection_AsciiString &)) &AIS_Dimension::SetModelUnits, "None", py::arg(""));
cls_AIS_Dimension.def("UnsetFixedTextPosition", (void (AIS_Dimension::*)()) &AIS_Dimension::UnsetFixedTextPosition, "Unsets user defined text positioning and enables text positioning by other parameters: text alignment, extension size, flyout and custom plane.");
cls_AIS_Dimension.def("SelToleranceForText2d", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::SelToleranceForText2d, "Returns selection tolerance for text2d: For 2d text selection detection sensitive point with tolerance is used Important! Only for 2d text.");
cls_AIS_Dimension.def("SetSelToleranceForText2d", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetSelToleranceForText2d, "Sets selection tolerance for text2d: For 2d text selection detection sensitive point with tolerance is used to change this tolerance use this method Important! Only for 2d text.", py::arg("theTol"));
cls_AIS_Dimension.def("GetFlyout", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::GetFlyout, "Returns flyout value for dimension.");
cls_AIS_Dimension.def("SetFlyout", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetFlyout, "Sets flyout value for dimension.", py::arg("theFlyout"));
cls_AIS_Dimension.def("IsValid", (Standard_Boolean (AIS_Dimension::*)() const) &AIS_Dimension::IsValid, "Check that the input geometry for dimension is valid and the presentation can be successfully computed.");
cls_AIS_Dimension.def_static("get_type_name_", (const char * (*)()) &AIS_Dimension::get_type_name, "None");
cls_AIS_Dimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Dimension::get_type_descriptor, "None");
cls_AIS_Dimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Dimension::*)() const) &AIS_Dimension::DynamicType, "None");

// Enums
py::enum_<AIS_Dimension::ComputeMode>(cls_AIS_Dimension, "ComputeMode", "Specifies supported presentation compute modes. Used to compute only parts of presentation for advanced highlighting.")
	.value("ComputeMode_All", AIS_Dimension::ComputeMode::ComputeMode_All)
	.value("ComputeMode_Line", AIS_Dimension::ComputeMode::ComputeMode_Line)
	.value("ComputeMode_Text", AIS_Dimension::ComputeMode::ComputeMode_Text)
	.export_values();

// CLASS: AIS_ANGLEDIMENSION
py::class_<AIS_AngleDimension, opencascade::handle<AIS_AngleDimension>, AIS_Dimension> cls_AIS_AngleDimension(mod, "AIS_AngleDimension", "Angle dimension. Can be constructed: - on two intersected edges. - on three points or vertices. - on conical face. - between two intersected faces.");

// Constructors
cls_AIS_AngleDimension.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theFirstEdge"), py::arg("theSecondEdge"));
cls_AIS_AngleDimension.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("theThirdPoint"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &>(), py::arg("theFirstVertex"), py::arg("theSecondVertex"), py::arg("theThirdVertex"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &>(), py::arg("theCone"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_AngleDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &, const gp_Pnt &>(), py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("thePoint"));

// Methods
cls_AIS_AngleDimension.def("FirstPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::FirstPoint, "Returns first point forming the angle.");
cls_AIS_AngleDimension.def("SecondPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::SecondPoint, "Returns second point forming the angle.");
cls_AIS_AngleDimension.def("CenterPoint", (const gp_Pnt & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::CenterPoint, "Returns center point forming the angle.");
cls_AIS_AngleDimension.def("FirstShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::FirstShape, "Returns first argument shape.");
cls_AIS_AngleDimension.def("SecondShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::SecondShape, "Returns second argument shape.");
cls_AIS_AngleDimension.def("ThirdShape", (const TopoDS_Shape & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::ThirdShape, "Returns third argument shape.");
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures minimum angle dimension between two linear edges. These two edges should be intersected by each other. Otherwise the geometry is not valid.", py::arg("theFirstEdge"), py::arg("theSecondEdge"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle defined by three points.", py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("theThridPoint"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Vertex &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle defined by three vertices.", py::arg("theFirstVertex"), py::arg("theSecondVertex"), py::arg("theThirdVertex"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle of conical face.", py::arg("theCone"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &, const TopoDS_Face &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle between two planar faces.", py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_AngleDimension.def("SetMeasuredGeometry", (void (AIS_AngleDimension::*)(const TopoDS_Face &, const TopoDS_Face &, const gp_Pnt &)) &AIS_AngleDimension::SetMeasuredGeometry, "Measures angle between two planar faces.", py::arg("theFirstFace"), py::arg("theSecondFace"), py::arg("thePoint"));
cls_AIS_AngleDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_AngleDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_AngleDimension.def("SetDisplayUnits", (void (AIS_AngleDimension::*)(const TCollection_AsciiString &)) &AIS_AngleDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_AngleDimension.def("SetModelUnits", (void (AIS_AngleDimension::*)(const TCollection_AsciiString &)) &AIS_AngleDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_AngleDimension.def("SetTextPosition", (void (AIS_AngleDimension::*)(const gp_Pnt &)) &AIS_AngleDimension::SetTextPosition, "Principle of horizontal text alignment settings: - divide circle into two halves according to attachment points - if aTextPos is between attach points -> Center + positive flyout - if aTextPos is not between attach points but in this half -> Left or Right + positive flyout - if aTextPos is between reflections of attach points -> Center + negative flyout - if aTextPos is not between reflections of attach points -> Left or Right + negative flyout", py::arg("theTextPos"));
cls_AIS_AngleDimension.def("GetTextPosition", (const gp_Pnt (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetTextPosition, "None");
cls_AIS_AngleDimension.def("SetType", (void (AIS_AngleDimension::*)(const AIS_TypeOfAngle)) &AIS_AngleDimension::SetType, "Sets angle type.", py::arg("theType"));
cls_AIS_AngleDimension.def("GetType", (AIS_TypeOfAngle (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetType, "Returns the current angle type.");
cls_AIS_AngleDimension.def("SetArrowsVisibility", (void (AIS_AngleDimension::*)(const AIS_TypeOfAngleArrowVisibility &)) &AIS_AngleDimension::SetArrowsVisibility, "Sets visible arrows type", py::arg("theType"));
cls_AIS_AngleDimension.def("GetArrowsVisibility", (AIS_TypeOfAngleArrowVisibility (AIS_AngleDimension::*)() const) &AIS_AngleDimension::GetArrowsVisibility, "Returns the type of visibility of arrows.");
cls_AIS_AngleDimension.def_static("get_type_name_", (const char * (*)()) &AIS_AngleDimension::get_type_name, "None");
cls_AIS_AngleDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AngleDimension::get_type_descriptor, "None");
cls_AIS_AngleDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AngleDimension::*)() const) &AIS_AngleDimension::DynamicType, "None");

// TYPEDEF: AIS_ANIMATIONTIMER
py::class_<Media_Timer, opencascade::handle<Media_Timer>, Standard_Transient> cls_AIS_AnimationTimer(mod, "AIS_AnimationTimer", "Auxiliary class defining the animation timer.", py::module_local());

// Constructors
cls_AIS_AnimationTimer.def(py::init<>());

// Methods
cls_AIS_AnimationTimer.def_static("get_type_name_", (const char * (*)()) &Media_Timer::get_type_name, "None");
cls_AIS_AnimationTimer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Media_Timer::get_type_descriptor, "None");
cls_AIS_AnimationTimer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Media_Timer::*)() const) &Media_Timer::DynamicType, "None");
cls_AIS_AnimationTimer.def("ElapsedTime", (Standard_Real (Media_Timer::*)() const) &Media_Timer::ElapsedTime, "Return elapsed time in seconds.");
cls_AIS_AnimationTimer.def("PlaybackSpeed", (Standard_Real (Media_Timer::*)() const) &Media_Timer::PlaybackSpeed, "Return playback speed coefficient (1.0 means normal speed).");
cls_AIS_AnimationTimer.def("SetPlaybackSpeed", (void (Media_Timer::*)(const Standard_Real)) &Media_Timer::SetPlaybackSpeed, "Setup playback speed coefficient.", py::arg("theSpeed"));
cls_AIS_AnimationTimer.def("IsStarted", (Standard_Boolean (Media_Timer::*)() const) &Media_Timer::IsStarted, "Return true if timer has been started.");
cls_AIS_AnimationTimer.def("Start", (void (Media_Timer::*)()) &Media_Timer::Start, "Start the timer.");
cls_AIS_AnimationTimer.def("Pause", (void (Media_Timer::*)()) &Media_Timer::Pause, "Pause the timer.");
cls_AIS_AnimationTimer.def("Stop", (void (Media_Timer::*)()) &Media_Timer::Stop, "Stop the timer.");
cls_AIS_AnimationTimer.def("Seek", (void (Media_Timer::*)(const Standard_Real)) &Media_Timer::Seek, "Seek the timer to specified position.", py::arg("theTime"));

// CLASS: AIS_ANIMATIONPROGRESS
py::class_<AIS_AnimationProgress> cls_AIS_AnimationProgress(mod, "AIS_AnimationProgress", "Structure defining current animation progress.");

// Constructors
cls_AIS_AnimationProgress.def(py::init<>());

// Fields
cls_AIS_AnimationProgress.def_readwrite("Pts", &AIS_AnimationProgress::Pts, "global presentation timestamp");
cls_AIS_AnimationProgress.def_readwrite("LocalPts", &AIS_AnimationProgress::LocalPts, "presentation within current animation");
cls_AIS_AnimationProgress.def_readwrite("LocalNormalized", &AIS_AnimationProgress::LocalNormalized, "normalized position within current animation within 0..1 range");

// CLASS: AIS_ANIMATION
py::class_<AIS_Animation, opencascade::handle<AIS_Animation>, Standard_Transient> cls_AIS_Animation(mod, "AIS_Animation", "Class represents a basic animation class. AIS_Animation can be used as:");

// Constructors
cls_AIS_Animation.def(py::init<const TCollection_AsciiString &>(), py::arg("theAnimationName"));

// Methods
cls_AIS_Animation.def_static("get_type_name_", (const char * (*)()) &AIS_Animation::get_type_name, "None");
cls_AIS_Animation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Animation::get_type_descriptor, "None");
cls_AIS_Animation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Animation::*)() const) &AIS_Animation::DynamicType, "None");
cls_AIS_Animation.def("Name", (const TCollection_AsciiString & (AIS_Animation::*)() const) &AIS_Animation::Name, "Animation name.");
cls_AIS_Animation.def("StartPts", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::StartPts, "Returns start time of the animation in the timeline");
cls_AIS_Animation.def("SetStartPts", (void (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::SetStartPts, "Sets time limits for animation in the animation timeline", py::arg("thePtsStart"));
cls_AIS_Animation.def("Duration", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::Duration, "Returns duration of the animation in the timeline");
cls_AIS_Animation.def("UpdateTotalDuration", (void (AIS_Animation::*)()) &AIS_Animation::UpdateTotalDuration, "Update total duration considering all animations on timeline.");
cls_AIS_Animation.def("HasOwnDuration", (Standard_Boolean (AIS_Animation::*)() const) &AIS_Animation::HasOwnDuration, "Return true if duration is defined.");
cls_AIS_Animation.def("OwnDuration", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::OwnDuration, "Returns own duration of the animation in the timeline");
cls_AIS_Animation.def("SetOwnDuration", (void (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::SetOwnDuration, "Defines duration of the animation.", py::arg("theDuration"));
cls_AIS_Animation.def("Add", (void (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Add, "Add single animation to the timeline.", py::arg("theAnimation"));
cls_AIS_Animation.def("Clear", (void (AIS_Animation::*)()) &AIS_Animation::Clear, "Clear animation timeline - remove all animations from it.");
cls_AIS_Animation.def("Find", (opencascade::handle<AIS_Animation> (AIS_Animation::*)(const TCollection_AsciiString &) const) &AIS_Animation::Find, "Return the child animation with the given name.", py::arg("theAnimationName"));
cls_AIS_Animation.def("Remove", (Standard_Boolean (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Remove, "Remove the child animation.", py::arg("theAnimation"));
cls_AIS_Animation.def("Replace", (Standard_Boolean (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &, const opencascade::handle<AIS_Animation> &)) &AIS_Animation::Replace, "Replace the child animation.", py::arg("theAnimationOld"), py::arg("theAnimationNew"));
cls_AIS_Animation.def("CopyFrom", (void (AIS_Animation::*)(const opencascade::handle<AIS_Animation> &)) &AIS_Animation::CopyFrom, "Clears own children and then copy child animations from another object. Copy also Start Time and Duration values.", py::arg("theOther"));
cls_AIS_Animation.def("Children", (const NCollection_Sequence<opencascade::handle<AIS_Animation> > & (AIS_Animation::*)() const) &AIS_Animation::Children, "Return sequence of child animations.");
cls_AIS_Animation.def("StartTimer", [](AIS_Animation &self, const Standard_Real a0, const Standard_Real a1, const Standard_Boolean a2) -> void { return self.StartTimer(a0, a1, a2); });
cls_AIS_Animation.def("StartTimer", (void (AIS_Animation::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &AIS_Animation::StartTimer, "Start animation with internally defined timer instance. Calls ::Start() internally.", py::arg("theStartPts"), py::arg("thePlaySpeed"), py::arg("theToUpdate"), py::arg("theToStopTimer"));
cls_AIS_Animation.def("UpdateTimer", (Standard_Real (AIS_Animation::*)()) &AIS_Animation::UpdateTimer, "Update single frame of animation, update timer state");
cls_AIS_Animation.def("ElapsedTime", (Standard_Real (AIS_Animation::*)() const) &AIS_Animation::ElapsedTime, "Return elapsed time.");
cls_AIS_Animation.def("Start", (void (AIS_Animation::*)(const Standard_Boolean)) &AIS_Animation::Start, "Start animation. This method changes status of the animation to Started. This status defines whether animation is to be performed in the timeline or not.", py::arg("theToUpdate"));
cls_AIS_Animation.def("Pause", (void (AIS_Animation::*)()) &AIS_Animation::Pause, "Pause the process timeline.");
cls_AIS_Animation.def("Stop", (void (AIS_Animation::*)()) &AIS_Animation::Stop, "Stop animation. This method changed status of the animation to Stopped. This status shows that animation will not be performed in the timeline or it is finished.");
cls_AIS_Animation.def("IsStopped", (bool (AIS_Animation::*)()) &AIS_Animation::IsStopped, "Check if animation is to be performed in the animation timeline.");
cls_AIS_Animation.def("Update", (Standard_Boolean (AIS_Animation::*)(const Standard_Real)) &AIS_Animation::Update, "Update single frame of animation, update timer state", py::arg("thePts"));

// CLASS: AIS_ANIMATIONCAMERA
py::class_<AIS_AnimationCamera, opencascade::handle<AIS_AnimationCamera>, AIS_Animation> cls_AIS_AnimationCamera(mod, "AIS_AnimationCamera", "Camera animation.");

// Constructors
cls_AIS_AnimationCamera.def(py::init<const TCollection_AsciiString &, const opencascade::handle<V3d_View> &>(), py::arg("theAnimationName"), py::arg("theView"));

// Methods
cls_AIS_AnimationCamera.def_static("get_type_name_", (const char * (*)()) &AIS_AnimationCamera::get_type_name, "None");
cls_AIS_AnimationCamera.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AnimationCamera::get_type_descriptor, "None");
cls_AIS_AnimationCamera.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::DynamicType, "None");
cls_AIS_AnimationCamera.def("View", (const opencascade::handle<V3d_View> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::View, "Return the target view.");
cls_AIS_AnimationCamera.def("SetView", (void (AIS_AnimationCamera::*)(const opencascade::handle<V3d_View> &)) &AIS_AnimationCamera::SetView, "Set target view.", py::arg("theView"));
cls_AIS_AnimationCamera.def("CameraStart", (const opencascade::handle<Graphic3d_Camera> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::CameraStart, "Return camera start position.");
cls_AIS_AnimationCamera.def("SetCameraStart", (void (AIS_AnimationCamera::*)(const opencascade::handle<Graphic3d_Camera> &)) &AIS_AnimationCamera::SetCameraStart, "Define camera start position.", py::arg("theCameraStart"));
cls_AIS_AnimationCamera.def("CameraEnd", (const opencascade::handle<Graphic3d_Camera> & (AIS_AnimationCamera::*)() const) &AIS_AnimationCamera::CameraEnd, "Return camera end position.");
cls_AIS_AnimationCamera.def("SetCameraEnd", (void (AIS_AnimationCamera::*)(const opencascade::handle<Graphic3d_Camera> &)) &AIS_AnimationCamera::SetCameraEnd, "Define camera end position.", py::arg("theCameraEnd"));

// CLASS: AIS_GLOBALSTATUS
py::class_<AIS_GlobalStatus, opencascade::handle<AIS_GlobalStatus>, Standard_Transient> cls_AIS_GlobalStatus(mod, "AIS_GlobalStatus", "Stores information about objects in graphic context: - Status Of Display : in the main viewer hidden in the main viewer - Displayed Modes - Active Selection Modes - is the Interactive Object Current ? - Layer Index");

// Constructors
cls_AIS_GlobalStatus.def(py::init<>());
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"));
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"), py::arg("ishilighted"));
cls_AIS_GlobalStatus.def(py::init<const AIS_DisplayStatus, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer>(), py::arg("aStat"), py::arg("aDispMode"), py::arg("aSelMode"), py::arg("ishilighted"), py::arg("aLayerIndex"));

// Methods
cls_AIS_GlobalStatus.def_static("get_type_name_", (const char * (*)()) &AIS_GlobalStatus::get_type_name, "None");
cls_AIS_GlobalStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_GlobalStatus::get_type_descriptor, "None");
cls_AIS_GlobalStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::DynamicType, "None");
cls_AIS_GlobalStatus.def("SetGraphicStatus", (void (AIS_GlobalStatus::*)(const AIS_DisplayStatus)) &AIS_GlobalStatus::SetGraphicStatus, "None", py::arg("theStatus"));
cls_AIS_GlobalStatus.def("AddSelectionMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::AddSelectionMode, "None", py::arg("theMode"));
cls_AIS_GlobalStatus.def("SetDisplayMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::SetDisplayMode, "Sets display mode.", py::arg("theMode"));
cls_AIS_GlobalStatus.def("DisplayMode", (Standard_Integer (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::DisplayMode, "Returns the display mode.");
cls_AIS_GlobalStatus.def("SetLayerIndex", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::SetLayerIndex, "None", py::arg("theIndex"));
cls_AIS_GlobalStatus.def("SetHilightStatus", (void (AIS_GlobalStatus::*)(const Standard_Boolean)) &AIS_GlobalStatus::SetHilightStatus, "None", py::arg("theStatus"));
cls_AIS_GlobalStatus.def("SetHilightStyle", (void (AIS_GlobalStatus::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GlobalStatus::SetHilightStyle, "Changes applied highlight style for a particular object", py::arg("theStyle"));
cls_AIS_GlobalStatus.def("HilightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::HilightStyle, "Returns applied highlight style for a particular object");
cls_AIS_GlobalStatus.def("IsSubIntensityOn", (Standard_Boolean (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::IsSubIntensityOn, "None");
cls_AIS_GlobalStatus.def("SubIntensityOn", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::SubIntensityOn, "None");
cls_AIS_GlobalStatus.def("SubIntensityOff", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::SubIntensityOff, "None");
cls_AIS_GlobalStatus.def("RemoveSelectionMode", (void (AIS_GlobalStatus::*)(const Standard_Integer)) &AIS_GlobalStatus::RemoveSelectionMode, "None", py::arg("aMode"));
cls_AIS_GlobalStatus.def("ClearSelectionModes", (void (AIS_GlobalStatus::*)()) &AIS_GlobalStatus::ClearSelectionModes, "None");
cls_AIS_GlobalStatus.def("GraphicStatus", (AIS_DisplayStatus (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::GraphicStatus, "None");
cls_AIS_GlobalStatus.def("SelectionModes", (const TColStd_ListOfInteger & (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::SelectionModes, "keeps the active selection modes of the object in the main viewer.");
cls_AIS_GlobalStatus.def("IsHilighted", (Standard_Boolean (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::IsHilighted, "None");
cls_AIS_GlobalStatus.def("IsSModeIn", (Standard_Boolean (AIS_GlobalStatus::*)(const Standard_Integer) const) &AIS_GlobalStatus::IsSModeIn, "None", py::arg("aMode"));
cls_AIS_GlobalStatus.def("GetLayerIndex", (Standard_Integer (AIS_GlobalStatus::*)() const) &AIS_GlobalStatus::GetLayerIndex, "Returns layer index.");

// TYPEDEF: AIS_DATAMAPOFIOSTATUS
bind_NCollection_DataMap<opencascade::handle<AIS_InteractiveObject>, opencascade::handle<AIS_GlobalStatus>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "AIS_DataMapOfIOStatus", py::module_local(false));

// TYPEDEF: AIS_DATAMAPITERATOROFDATAMAPOFIOSTATUS

// TYPEDEF: AIS_LISTOFINTERACTIVE
bind_NCollection_List<opencascade::handle<AIS_InteractiveObject> >(mod, "AIS_ListOfInteractive", py::module_local(false));

// TYPEDEF: AIS_LISTITERATOROFLISTOFINTERACTIVE
bind_NCollection_TListIterator<opencascade::handle<AIS_InteractiveObject> >(mod, "AIS_ListIteratorOfListOfInteractive", py::module_local(false));

// TYPEDEF: AIS_NLISTOFENTITYOWNER
bind_NCollection_List<opencascade::handle<SelectMgr_EntityOwner> >(mod, "AIS_NListOfEntityOwner", py::module_local(false));

// CLASS: AIS_SELECTION
py::class_<AIS_Selection, opencascade::handle<AIS_Selection>, Standard_Transient> cls_AIS_Selection(mod, "AIS_Selection", "Class holding the list of selected owners.");

// Constructors
cls_AIS_Selection.def(py::init<>());

// Methods
cls_AIS_Selection.def_static("get_type_name_", (const char * (*)()) &AIS_Selection::get_type_name, "None");
cls_AIS_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Selection::get_type_descriptor, "None");
cls_AIS_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Selection::*)() const) &AIS_Selection::DynamicType, "None");
cls_AIS_Selection.def("Clear", (void (AIS_Selection::*)()) &AIS_Selection::Clear, "removes all the object of the selection.");
cls_AIS_Selection.def("Select", (AIS_SelectStatus (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::Select, "if the object is not yet in the selection, it will be added. if the object is already in the selection, it will be removed.", py::arg("theObject"));
cls_AIS_Selection.def("AddSelect", (AIS_SelectStatus (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::AddSelect, "the object is always add int the selection. faster when the number of objects selected is great.", py::arg("theObject"));
cls_AIS_Selection.def("ClearAndSelect", (void (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Selection::ClearAndSelect, "clears the selection and adds the object in the selection.", py::arg("theObject"));
cls_AIS_Selection.def("IsSelected", (Standard_Boolean (AIS_Selection::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_Selection::IsSelected, "checks if the object is in the selection.", py::arg("theObject"));
cls_AIS_Selection.def("Objects", (const AIS_NListOfEntityOwner & (AIS_Selection::*)() const) &AIS_Selection::Objects, "Return the list of selected objects.");
cls_AIS_Selection.def("Extent", (Standard_Integer (AIS_Selection::*)() const) &AIS_Selection::Extent, "Return the number of selected objects.");
cls_AIS_Selection.def("IsEmpty", (Standard_Boolean (AIS_Selection::*)() const) &AIS_Selection::IsEmpty, "Return true if list of selected objects is empty.");
cls_AIS_Selection.def("Init", (void (AIS_Selection::*)()) &AIS_Selection::Init, "Start iteration through selected objects.");
cls_AIS_Selection.def("More", (Standard_Boolean (AIS_Selection::*)() const) &AIS_Selection::More, "Return true if iterator points to selected object.");
cls_AIS_Selection.def("Next", (void (AIS_Selection::*)()) &AIS_Selection::Next, "Continue iteration through selected objects.");
cls_AIS_Selection.def("Value", (const opencascade::handle<SelectMgr_EntityOwner> & (AIS_Selection::*)() const) &AIS_Selection::Value, "Return selected object at iterator position.");

// CLASS: AIS_INTERACTIVECONTEXT
py::class_<AIS_InteractiveContext, opencascade::handle<AIS_InteractiveContext>, Standard_Transient> cls_AIS_InteractiveContext(mod, "AIS_InteractiveContext", "The Interactive Context allows you to manage graphic behavior and selection of Interactive Objects in one or more viewers. Class methods make this highly transparent. It is essential to remember that an Interactive Object which is already known by the Interactive Context must be modified using Context methods. You can only directly call the methods available for an Interactive Object if it has not been loaded into an Interactive Context.");

// Constructors
cls_AIS_InteractiveContext.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("MainViewer"));

// Methods
cls_AIS_InteractiveContext.def_static("get_type_name_", (const char * (*)()) &AIS_InteractiveContext::get_type_name, "None");
cls_AIS_InteractiveContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_InteractiveContext::get_type_descriptor, "None");
cls_AIS_InteractiveContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DynamicType, "None");
cls_AIS_InteractiveContext.def("DisplayStatus", (AIS_DisplayStatus (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::DisplayStatus, "Returns the display status of the entity anIobj. This will be one of the following: - AIS_DS_Displayed displayed in main viewer - AIS_DS_Erased hidden in main viewer - AIS_DS_Temporary temporarily displayed - AIS_DS_None nowhere displayed.", py::arg("anIobj"));
cls_AIS_InteractiveContext.def("Status", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, TCollection_ExtendedString &) const) &AIS_InteractiveContext::Status, "Returns the status of the Interactive Context for the view of the Interactive Object.", py::arg("anObj"), py::arg("astatus"));
cls_AIS_InteractiveContext.def("IsDisplayed", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::IsDisplayed, "Returns true if Object is displayed in the interactive context.", py::arg("anIobj"));
cls_AIS_InteractiveContext.def("IsDisplayed", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const) &AIS_InteractiveContext::IsDisplayed, "None", py::arg("aniobj"), py::arg("aMode"));
cls_AIS_InteractiveContext.def("SetAutoActivateSelection", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SetAutoActivateSelection, "Enable or disable automatic activation of default selection mode while displaying the object.", py::arg("theIsAuto"));
cls_AIS_InteractiveContext.def("GetAutoActivateSelection", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::GetAutoActivateSelection, "Manages displaying the new object should also automatically activate default selection mode; TRUE by default.");
cls_AIS_InteractiveContext.def("Display", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Display, "Displays the object in this Context using default Display Mode. This will be the object's default display mode, if there is one. Otherwise, it will be the context mode. The Interactive Object's default selection mode is activated if GetAutoActivateSelection() is TRUE. In general, this is 0.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Display", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Boolean a3) -> void { return self.Display(a0, a1, a2, a3); });
cls_AIS_InteractiveContext.def("Display", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const AIS_DisplayStatus)) &AIS_InteractiveContext::Display, "Sets status, display mode and selection mode for specified Object If theSelectionMode equals -1, theIObj will not be activated: it will be displayed but will not be selectable.", py::arg("theIObj"), py::arg("theDispMode"), py::arg("theSelectionMode"), py::arg("theToUpdateViewer"), py::arg("theDispStatus"));
cls_AIS_InteractiveContext.def("Load", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Load(a0); });
cls_AIS_InteractiveContext.def("Load", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::Load, "Allows you to load the Interactive Object with a given selection mode, and/or with the desired decomposition option, whether the object is visualized or not. The loaded objects will be selectable but displayable in highlighting only when detected by the Selector.", py::arg("theObj"), py::arg("theSelectionMode"));
cls_AIS_InteractiveContext.def("Display", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Display(a0, a1, a2, a3, a4); });
cls_AIS_InteractiveContext.def("Display", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const AIS_DisplayStatus)) &AIS_InteractiveContext::Display, "None", py::arg("theIObj"), py::arg("theDispMode"), py::arg("theSelectionMode"), py::arg("theToUpdateViewer"), py::arg("theToAllowDecomposition"), py::arg("theDispStatus"));
cls_AIS_InteractiveContext.def("Load", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, Standard_Integer, Standard_Boolean)) &AIS_InteractiveContext::Load, "None", py::arg("theObj"), py::arg("theSelectionMode"), py::arg(""));
cls_AIS_InteractiveContext.def("Erase", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Erase, "Hides the object. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show hidden objects, use Display().", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("EraseAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::EraseAll, "Hides all objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show all hidden objects, use DisplayAll().", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("DisplayAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::DisplayAll, "Displays all hidden objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("EraseSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::EraseSelected, "Hides selected objects. The object's presentations are simply flagged as invisible and therefore excluded from redrawing. To show hidden objects, use Display().", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("DisplaySelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::DisplaySelected, "Displays current objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ClearPrs", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::ClearPrs, "Empties the graphic presentation of the mode indexed by aMode. Warning! Removes theIObj. theIObj is still active if it was previously activated.", py::arg("theIObj"), py::arg("theMode"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Remove", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Remove, "Removes Object from every viewer.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("RemoveAll", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::RemoveAll, "Removes all the objects from Context.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Redisplay", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> void { return self.Redisplay(a0, a1); });
cls_AIS_InteractiveContext.def("Redisplay", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Boolean)) &AIS_InteractiveContext::Redisplay, "Recomputes the seen parts presentation of the Object. If theAllModes equals true, all presentations are present in the object even if unseen.", py::arg("theIObj"), py::arg("theToUpdateViewer"), py::arg("theAllModes"));
cls_AIS_InteractiveContext.def("Redisplay", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Redisplay, "Recomputes the Prs/Selection of displayed objects of a given type and a given signature. if signature = -1 doesn't take signature criterion.", py::arg("theTypeOfObject"), py::arg("theSignature"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("RecomputePrsOnly", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Boolean a1) -> void { return self.RecomputePrsOnly(a0, a1); });
cls_AIS_InteractiveContext.def("RecomputePrsOnly", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean, const Standard_Boolean)) &AIS_InteractiveContext::RecomputePrsOnly, "Recomputes the displayed presentations, flags the others. Doesn't update presentations.", py::arg("theIObj"), py::arg("theToUpdateViewer"), py::arg("theAllModes"));
cls_AIS_InteractiveContext.def("RecomputeSelectionOnly", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::RecomputeSelectionOnly, "Recomputes the active selections, flags the others. Doesn't update presentations.", py::arg("anIObj"));
cls_AIS_InteractiveContext.def("Update", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Update, "Updates displayed interactive object by checking and recomputing its flagged as 'to be recomputed' presentation and selection structures. This method does not force any recomputation on its own. The method recomputes selections even if they are loaded without activation in particular selector.", py::arg("theIObj"), py::arg("theUpdateViewer"));
cls_AIS_InteractiveContext.def("HighlightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)(const Prs3d_TypeOfHighlight) const) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style settings.", py::arg("theStyleType"));
cls_AIS_InteractiveContext.def("SetHighlightStyle", (void (AIS_InteractiveContext::*)(const Prs3d_TypeOfHighlight, const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetHighlightStyle, "Setup highlight style settings. It is preferred modifying existing style returned by method HighlightStyle() instead of creating a new drawer.", py::arg("theStyleType"), py::arg("theStyle"));
cls_AIS_InteractiveContext.def("HighlightStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HighlightStyle, "Returns current dynamic highlight style settings. By default: - the color of dynamic highlight is Quantity_NOC_CYAN1; - the presentation for dynamic highlight is completely opaque; - the type of highlight is Aspect_TOHM_COLOR.");
cls_AIS_InteractiveContext.def("SetHighlightStyle", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetHighlightStyle, "Setup the style of dynamic highlighting. It is preferred modifying existing style returned by method HighlightStyle() instead of creating a new drawer.", py::arg("theStyle"));
cls_AIS_InteractiveContext.def("SelectionStyle", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SelectionStyle, "Returns current selection style settings. By default: - the color of selection is Quantity_NOC_GRAY80; - the presentation for selection is completely opaque; - the type of highlight is Aspect_TOHM_COLOR.");
cls_AIS_InteractiveContext.def("SetSelectionStyle", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_InteractiveContext::SetSelectionStyle, "Setup the style of selection highlighting.", py::arg("theStyle"));
cls_AIS_InteractiveContext.def("HighlightStyle", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, opencascade::handle<Prs3d_Drawer> &) const) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style of the object if it is marked as highlighted via global status", py::arg("theObj"), py::arg("theStyle"));
cls_AIS_InteractiveContext.def("HighlightStyle", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, opencascade::handle<Prs3d_Drawer> &) const) &AIS_InteractiveContext::HighlightStyle, "Returns highlight style of the owner if it is selected", py::arg("theOwner"), py::arg("theStyle"));
cls_AIS_InteractiveContext.def("IsHilighted", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::IsHilighted, "Returns true if the object is marked as highlighted via its global status", py::arg("theObj"));
cls_AIS_InteractiveContext.def("IsHilighted", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_InteractiveContext::IsHilighted, "Returns true if the owner is marked as selected", py::arg("theOwner"));
cls_AIS_InteractiveContext.def("Hilight", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Hilight, "Updates the display in the viewer to take dynamic detection into account. On dynamic detection by the mouse cursor, sensitive primitives are highlighted. The highlight color of entities detected by mouse movement is white by default.", py::arg("theObj"), py::arg("theIsToUpdateViewer"));
cls_AIS_InteractiveContext.def("HilightWithColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightWithColor, "Changes the color of all the lines of the object in view.", py::arg("theObj"), py::arg("theStyle"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Unhilight", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::Unhilight, "Removes hilighting from the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("DisplayPriority", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::DisplayPriority, "Returns the display priority of the Object.", py::arg("theIObj"));
cls_AIS_InteractiveContext.def("SetDisplayPriority", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::SetDisplayPriority, "Sets the display priority of the seen parts presentation of the Object.", py::arg("theIObj"), py::arg("thePriority"));
cls_AIS_InteractiveContext.def("GetZLayer", (Graphic3d_ZLayerId (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::GetZLayer, "Get Z layer id set for displayed interactive object.", py::arg("theIObj"));
cls_AIS_InteractiveContext.def("SetZLayer", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Graphic3d_ZLayerId)) &AIS_InteractiveContext::SetZLayer, "Set Z layer id for interactive object. The Z layers can be used to display temporarily presentations of some object in front of the other objects in the scene. The ids for Z layers are generated by V3d_Viewer.", py::arg("theIObj"), py::arg("theLayerId"));
cls_AIS_InteractiveContext.def("SetViewAffinity", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::SetViewAffinity, "Setup object visibility in specified view. Has no effect if object is not displayed in this context.", py::arg("theIObj"), py::arg("theView"), py::arg("theIsVisible"));
cls_AIS_InteractiveContext.def("DisplayMode", (Standard_Integer (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DisplayMode, "Returns the Display Mode setting to be used by default.");
cls_AIS_InteractiveContext.def("SetDisplayMode", (void (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::SetDisplayMode, "Sets the display mode of seen Interactive Objects (which have no overridden Display Mode).", py::arg("theMode"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetDisplayMode", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::SetDisplayMode, "Sets the display mode of seen Interactive Objects. theMode provides the display mode index of the entity theIObj.", py::arg("theIObj"), py::arg("theMode"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetDisplayMode", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetDisplayMode, "Unsets the display mode of seen Interactive Objects.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetLocation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const TopLoc_Location &)) &AIS_InteractiveContext::SetLocation, "Puts the location on the initial graphic representation and the selection for the Object.", py::arg("theObject"), py::arg("theLocation"));
cls_AIS_InteractiveContext.def("ResetLocation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::ResetLocation, "Puts the Object back into its initial position.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("HasLocation", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::HasLocation, "Returns true if the Object has a location.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("Location", (TopLoc_Location (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::Location, "Returns the location of the Object.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("SetTransformPersistence", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_InteractiveContext::SetTransformPersistence, "Sets transform persistence.", py::arg("theObject"), py::arg("theTrsfPers"));
cls_AIS_InteractiveContext.def("SetTransformPersistence", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Graphic3d_TransModeFlags & a1) -> void { return self.SetTransformPersistence(a0, a1); });
cls_AIS_InteractiveContext.def("SetTransformPersistence", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Graphic3d_TransModeFlags &, const gp_Pnt &)) &AIS_InteractiveContext::SetTransformPersistence, "None", py::arg("theObj"), py::arg("theFlag"), py::arg("thePoint"));
cls_AIS_InteractiveContext.def("SetPixelTolerance", [](AIS_InteractiveContext &self) -> void { return self.SetPixelTolerance(); });
cls_AIS_InteractiveContext.def("SetPixelTolerance", (void (AIS_InteractiveContext::*)(const Standard_Integer)) &AIS_InteractiveContext::SetPixelTolerance, "Setup pixel tolerance for MoveTo() operation.", py::arg("thePrecision"));
cls_AIS_InteractiveContext.def("PixelTolerance", (Standard_Integer (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::PixelTolerance, "Returns the pixel tolerance, default is 2. Pixel Tolerance extends sensitivity within MoveTo() operation (picking by point) and can be adjusted by application based on user input precision (e.g. screen pixel density, input device precision, etc.).");
cls_AIS_InteractiveContext.def("SetSelectionSensitivity", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Integer)) &AIS_InteractiveContext::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSensitivity"));
cls_AIS_InteractiveContext.def("LastActiveView", (opencascade::handle<V3d_View> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::LastActiveView, "Returns last active View (argument of MoveTo()/Select() methods).");
cls_AIS_InteractiveContext.def("MoveTo", (AIS_StatusOfDetection (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::MoveTo, "Relays mouse position in pixels theXPix and theYPix to the interactive context selectors. This is done by the view theView passing this position to the main viewer and updating it. If theToRedrawOnUpdate is set to false, callee should call RedrawImmediate() to highlight detected object.", py::arg("theXPix"), py::arg("theYPix"), py::arg("theView"), py::arg("theToRedrawOnUpdate"));
cls_AIS_InteractiveContext.def("ClearDetected", [](AIS_InteractiveContext &self) -> Standard_Boolean { return self.ClearDetected(); });
cls_AIS_InteractiveContext.def("ClearDetected", (Standard_Boolean (AIS_InteractiveContext::*)(Standard_Boolean)) &AIS_InteractiveContext::ClearDetected, "Clears the list of entities detected by MoveTo() and resets dynamic highlighting.", py::arg("theToRedrawImmediate"));
cls_AIS_InteractiveContext.def("HasDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HasDetected, "Returns true if there is a mouse-detected entity in context.");
cls_AIS_InteractiveContext.def("DetectedOwner", (const opencascade::handle<SelectMgr_EntityOwner> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedOwner, "Returns the owner of the detected sensitive primitive which is currently dynamically highlighted. WARNING! This method is irrelevant to InitDetected()/MoreDetected()/NextDetected().");
cls_AIS_InteractiveContext.def("DetectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedInteractive, "Returns the interactive objects last detected in context. In general this is just a wrapper for Handle(AIS_InteractiveObject)::DownCast(DetectedOwner()->Selectable()).");
cls_AIS_InteractiveContext.def("HasDetectedShape", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HasDetectedShape, "Returns true if there is a detected shape in local context.");
cls_AIS_InteractiveContext.def("DetectedShape", (const TopoDS_Shape & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedShape, "Returns the shape detected in local context.");
cls_AIS_InteractiveContext.def("HasNextDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HasNextDetected, "returns True if other entities were detected in the last mouse detection");
cls_AIS_InteractiveContext.def("HilightNextDetected", [](AIS_InteractiveContext &self, const opencascade::handle<V3d_View> & a0) -> Standard_Integer { return self.HilightNextDetected(a0); });
cls_AIS_InteractiveContext.def("HilightNextDetected", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightNextDetected, "If more than 1 object is detected by the selector, only the 'best' owner is hilighted at the mouse position. This Method allows the user to hilight one after another the other detected entities. If The method select is called, the selected entity will be the hilighted one! WARNING: Loop Method. When all the detected entities have been hilighted, the next call will hilight the first one again.", py::arg("theView"), py::arg("theToRedrawImmediate"));
cls_AIS_InteractiveContext.def("HilightPreviousDetected", [](AIS_InteractiveContext &self, const opencascade::handle<V3d_View> & a0) -> Standard_Integer { return self.HilightPreviousDetected(a0); });
cls_AIS_InteractiveContext.def("HilightPreviousDetected", (Standard_Integer (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::HilightPreviousDetected, "Same as previous methods in reverse direction.", py::arg("theView"), py::arg("theToRedrawImmediate"));
cls_AIS_InteractiveContext.def("InitDetected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitDetected, "Initialization for iteration through mouse-detected objects in interactive context or in local context if it is opened.");
cls_AIS_InteractiveContext.def("MoreDetected", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::MoreDetected, "Return TRUE if there is more mouse-detected objects after the current one during iteration through mouse-detected interactive objects.");
cls_AIS_InteractiveContext.def("NextDetected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextDetected, "Gets next current object during iteration through mouse-detected interactive objects.");
cls_AIS_InteractiveContext.def("DetectedCurrentOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedCurrentOwner, "Returns the owner from detected list pointed by current iterator position. WARNING! This method is irrelevant to DetectedOwner() which returns last picked Owner regardless of iterator position!");
cls_AIS_InteractiveContext.def("SetSelectedAspect", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_BasicAspect> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelectedAspect, "Sets the graphic basic aspect to the current presentation of ALL selected objects.", py::arg("theAspect"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("AddSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_InteractiveContext::AddSelect, "Adds object in the selection.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("AddSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::AddSelect, "Adds object in the selection.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::Select, "Selects everything found in the bounding rectangle defined by the pixel minima and maxima, XPMin, YPMin, XPMax, and YPMax in the view. The objects detected are passed to the main viewer, which is then updated.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::Select, "polyline selection; clears the previous picked list", py::arg("thePolyline"), py::arg("theView"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Select", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::Select, "Stores and hilights the previous detected; Unhilights the previous picked.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Adds the last detected to the list of previous picked. If the last detected was already declared as picked, removes it from the Picked List.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Adds the last detected to the list of previous picked. If the last detected was already declared as picked, removes it from the Picked List.", py::arg("thePolyline"), py::arg("theView"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ShiftSelect", (AIS_StatusOfPick (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &AIS_InteractiveContext::ShiftSelect, "Rectangle of selection; adds new detected entities into the picked list, removes the detected entities that were already stored.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("BoundingBoxOfSelection", (Bnd_Box (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::BoundingBoxOfSelection, "Returns bounding box of selected objects.");
cls_AIS_InteractiveContext.def("FitSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::FitSelected, "Fits the view correspondingly to the bounds of selected objects. Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.", py::arg("theView"), py::arg("theMargin"), py::arg("theToUpdate"));
cls_AIS_InteractiveContext.def("FitSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::FitSelected, "Fits the view correspondingly to the bounds of selected objects. Infinite objects are ignored if infinite state of AIS_InteractiveObject is set to true.", py::arg("theView"));
cls_AIS_InteractiveContext.def("ToHilightSelected", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::ToHilightSelected, "Return value specified whether selected object must be hilighted when mouse cursor is moved above it");
cls_AIS_InteractiveContext.def("SetToHilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::SetToHilightSelected, "Specify whether selected object must be hilighted when mouse cursor is moved above it (in MoveTo method). By default this value is false and selected object is not hilighted in this case.", py::arg("toHilight"));
cls_AIS_InteractiveContext.def("AutomaticHilight", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::AutomaticHilight, "Returns true if the automatic highlight mode is active; TRUE by default.");
cls_AIS_InteractiveContext.def("SetAutomaticHilight", (void (AIS_InteractiveContext::*)(Standard_Boolean)) &AIS_InteractiveContext::SetAutomaticHilight, "Sets the highlighting status of detected and selected entities. This function allows you to disconnect the automatic mode.", py::arg("theStatus"));
cls_AIS_InteractiveContext.def("SetSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelected, "Unhighlights previously selected owners and marks them as not selected. Marks owner given as selected and highlights it. Performs selection filters check.", py::arg("theOwners"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelected, "Puts the interactive object aniObj in the list of selected objects. Performs selection filters check.", py::arg("theObject"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("AddOrRemoveSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveSelected, "Allows to highlight or unhighlight the owner given depending on its selection status", py::arg("theObject"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetSelectedState", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_InteractiveContext::SetSelectedState, "Updates Selected state of specified owner without calling HilightSelected(). Has no effect if Selected state is not changed, and redirects to AddOrRemoveSelected() otherwise.", py::arg("theOwner"), py::arg("theIsSelected"));
cls_AIS_InteractiveContext.def("HilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::HilightSelected, "Highlights selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnhilightSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::UnhilightSelected, "Removes highlighting from selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UpdateSelected", (void (AIS_InteractiveContext::*)(Standard_Boolean)) &AIS_InteractiveContext::UpdateSelected, "Updates the list of selected objects: i.e. highlights the newly selected ones and unhighlights previously selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ClearSelected", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ClearSelected, "Empties previous selected objects in order to get the selected objects detected by the selector using UpdateSelected.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("AddOrRemoveSelected", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveSelected, "Allows to highlight or unhighlight the owner given depending on its selection status", py::arg("theOwner"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("IsSelected", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_InteractiveContext::IsSelected, "Returns true is the owner given is selected", py::arg("theOwner"));
cls_AIS_InteractiveContext.def("IsSelected", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::IsSelected, "Returns true is the object given is selected", py::arg("theObj"));
cls_AIS_InteractiveContext.def("FirstSelectedObject", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::FirstSelectedObject, "Returns the first selected object in the list of current selected.");
cls_AIS_InteractiveContext.def("NbSelected", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NbSelected, "Count a number of selected entities using InitSelected()+MoreSelected()+NextSelected() iterator.");
cls_AIS_InteractiveContext.def("InitSelected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitSelected, "Initializes a scan of the selected objects.");
cls_AIS_InteractiveContext.def("MoreSelected", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::MoreSelected, "Returns true if there is another object found by the scan of the list of selected objects.");
cls_AIS_InteractiveContext.def("NextSelected", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextSelected, "Continues the scan to the next object in the list of selected objects.");
cls_AIS_InteractiveContext.def("SelectedOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SelectedOwner, "Returns the owner of the selected entity.");
cls_AIS_InteractiveContext.def("SelectedInteractive", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SelectedInteractive, "Return Handle(AIS_InteractiveObject)::DownCast (SelectedOwner()->Selectable()).");
cls_AIS_InteractiveContext.def("HasSelectedShape", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HasSelectedShape, "Returns TRUE if the interactive context has a shape selected.");
cls_AIS_InteractiveContext.def("SelectedShape", (TopoDS_Shape (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SelectedShape, "Returns the selected shape. Basically it is just a shape returned stored by StdSelect_BRepOwner with graphic transformation being applied:");
cls_AIS_InteractiveContext.def("HasApplicative", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HasApplicative, "Returns SelectedInteractive()->HasOwner().");
cls_AIS_InteractiveContext.def("Applicative", (opencascade::handle<Standard_Transient> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::Applicative, "Returns SelectedInteractive()->GetOwner().");
cls_AIS_InteractiveContext.def("BeginImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::BeginImmediateDraw, "initializes the list of presentations to be displayed returns False if no local context is opened.");
cls_AIS_InteractiveContext.def("ImmediateAdd", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> Standard_Boolean { return self.ImmediateAdd(a0); });
cls_AIS_InteractiveContext.def("ImmediateAdd", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::ImmediateAdd, "returns True if <anIObj> has been stored in the list.", py::arg("theObj"), py::arg("theMode"));
cls_AIS_InteractiveContext.def("EndImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::EndImmediateDraw, "returns True if the immediate display has been done.", py::arg("theView"));
cls_AIS_InteractiveContext.def("EndImmediateDraw", (Standard_Boolean (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::EndImmediateDraw, "Uses the First Active View of Main Viewer! returns True if the immediate display has been done.");
cls_AIS_InteractiveContext.def("IsImmediateModeOn", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::IsImmediateModeOn, "None");
cls_AIS_InteractiveContext.def("RedrawImmediate", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_Viewer> &)) &AIS_InteractiveContext::RedrawImmediate, "Redraws immediate structures in all views of the viewer given taking into account its visibility.", py::arg("theViewer"));
cls_AIS_InteractiveContext.def("SetSelectionModeActive", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> void { return self.SetSelectionModeActive(a0, a1, a2); });
cls_AIS_InteractiveContext.def("SetSelectionModeActive", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1, const Standard_Boolean a2, const AIS_SelectionModesConcurrency a3) -> void { return self.SetSelectionModeActive(a0, a1, a2, a3); });
cls_AIS_InteractiveContext.def("SetSelectionModeActive", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean, const AIS_SelectionModesConcurrency, const Standard_Boolean)) &AIS_InteractiveContext::SetSelectionModeActive, "Activates or deactivates the selection mode for specified object. Has no effect if selection mode was already active/deactivated.", py::arg("theObj"), py::arg("theMode"), py::arg("theToActivate"), py::arg("theConcurrency"), py::arg("theIsForce"));
cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Activate(a0); });
cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0, const Standard_Integer a1) -> void { return self.Activate(a0, a1); });
cls_AIS_InteractiveContext.def("Activate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Activate, "Activates the selection mode aMode whose index is given, for the given interactive entity anIobj.", py::arg("theObj"), py::arg("theMode"), py::arg("theIsForce"));
cls_AIS_InteractiveContext.def("Activate", [](AIS_InteractiveContext &self, const Standard_Integer a0) -> void { return self.Activate(a0); });
cls_AIS_InteractiveContext.def("Activate", (void (AIS_InteractiveContext::*)(const Standard_Integer, const Standard_Boolean)) &AIS_InteractiveContext::Activate, "Activates the given selection mode for the all displayed objects.", py::arg("theMode"), py::arg("theIsForce"));
cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection modes of an object.", py::arg("theObj"));
cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer)) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection modes of the interactive object anIobj with a given selection mode aMode.", py::arg("theObj"), py::arg("theMode"));
cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)(const Standard_Integer)) &AIS_InteractiveContext::Deactivate, "Deactivates the given selection mode for all displayed objects.", py::arg("theMode"));
cls_AIS_InteractiveContext.def("Deactivate", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::Deactivate, "Deactivates all the activated selection mode at all displayed objects.");
cls_AIS_InteractiveContext.def("ActivatedModes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, TColStd_ListOfInteger &) const) &AIS_InteractiveContext::ActivatedModes, "Returns the list of activated selection modes.", py::arg("anIobj"), py::arg("theList"));
cls_AIS_InteractiveContext.def("EntityOwners", [](AIS_InteractiveContext &self, opencascade::handle<SelectMgr_IndexedMapOfOwner> & a0, const opencascade::handle<AIS_InteractiveObject> & a1) -> void { return self.EntityOwners(a0, a1); });
cls_AIS_InteractiveContext.def("EntityOwners", (void (AIS_InteractiveContext::*)(opencascade::handle<SelectMgr_IndexedMapOfOwner> &, const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer) const) &AIS_InteractiveContext::EntityOwners, "Returns a collection containing all entity owners created for the interactive object in specified selection mode (in all active modes if the Mode == -1)", py::arg("theOwners"), py::arg("theIObj"), py::arg("theMode"));
cls_AIS_InteractiveContext.def("Filters", (const SelectMgr_ListOfFilter & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::Filters, "Returns the list of filters active in a local context.");
cls_AIS_InteractiveContext.def("AddFilter", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_InteractiveContext::AddFilter, "Allows you to add the filter.", py::arg("theFilter"));
cls_AIS_InteractiveContext.def("RemoveFilter", (void (AIS_InteractiveContext::*)(const opencascade::handle<SelectMgr_Filter> &)) &AIS_InteractiveContext::RemoveFilter, "Removes a filter from context.", py::arg("theFilter"));
cls_AIS_InteractiveContext.def("RemoveFilters", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::RemoveFilters, "Remove all filters from context.");
cls_AIS_InteractiveContext.def("PickingStrategy", (SelectMgr_PickingStrategy (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::PickingStrategy, "Return picking strategy; SelectMgr_PickingStrategy_FirstAcceptable by default.");
cls_AIS_InteractiveContext.def("SetPickingStrategy", (void (AIS_InteractiveContext::*)(const SelectMgr_PickingStrategy)) &AIS_InteractiveContext::SetPickingStrategy, "Setup picking strategy - which entities detected by picking line will be accepted, considering Selection Filters. By default (SelectMgr_PickingStrategy_FirstAcceptable), Selection Filters reduce the list of entities so that the context accepts topmost in remaining.", py::arg("theStrategy"));
cls_AIS_InteractiveContext.def("DefaultDrawer", (const opencascade::handle<Prs3d_Drawer> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DefaultDrawer, "Returns the default attribute manager. This contains all the color and line attributes which can be used by interactive objects which do not have their own attributes.");
cls_AIS_InteractiveContext.def("CurrentViewer", (const opencascade::handle<V3d_Viewer> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::CurrentViewer, "Returns the current viewer.");
cls_AIS_InteractiveContext.def("SelectionManager", (const opencascade::handle<SelectMgr_SelectionManager> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SelectionManager, "None");
cls_AIS_InteractiveContext.def("MainPrsMgr", (const opencascade::handle<PrsMgr_PresentationManager3d> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::MainPrsMgr, "None");
cls_AIS_InteractiveContext.def("MainSelector", (const opencascade::handle<StdSelect_ViewerSelector3d> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::MainSelector, "None");
cls_AIS_InteractiveContext.def("UpdateCurrentViewer", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::UpdateCurrentViewer, "Updates the current viewer.");
cls_AIS_InteractiveContext.def("DisplayedObjects", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &) const) &AIS_InteractiveContext::DisplayedObjects, "Returns the list of displayed objects of a particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals -1. This means that there is a check on type only.", py::arg("aListOfIO"));
cls_AIS_InteractiveContext.def("DisplayedObjects", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, AIS_ListOfInteractive &) const) &AIS_InteractiveContext::DisplayedObjects, "gives the list of displayed objects of a particular Type and signature. by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("theWhichKind"), py::arg("theWhichSignature"), py::arg("theListOfIO"));
cls_AIS_InteractiveContext.def("ErasedObjects", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &) const) &AIS_InteractiveContext::ErasedObjects, "Returns the list theListOfIO of erased objects (hidden objects) particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals 1. This means that there is a check on type only.", py::arg("theListOfIO"));
cls_AIS_InteractiveContext.def("ErasedObjects", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, AIS_ListOfInteractive &) const) &AIS_InteractiveContext::ErasedObjects, "gives the list of erased objects (hidden objects) Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("theWhichKind"), py::arg("theWhichSignature"), py::arg("theListOfIO"));
cls_AIS_InteractiveContext.def("ObjectsByDisplayStatus", (void (AIS_InteractiveContext::*)(const AIS_DisplayStatus, AIS_ListOfInteractive &) const) &AIS_InteractiveContext::ObjectsByDisplayStatus, "Returns the list theListOfIO of objects with indicated display status particular Type WhichKind and Signature WhichSignature. By Default, WhichSignature equals 1. This means that there is a check on type only.", py::arg("theStatus"), py::arg("theListOfIO"));
cls_AIS_InteractiveContext.def("ObjectsByDisplayStatus", (void (AIS_InteractiveContext::*)(const AIS_KindOfInteractive, const Standard_Integer, const AIS_DisplayStatus, AIS_ListOfInteractive &) const) &AIS_InteractiveContext::ObjectsByDisplayStatus, "gives the list of objects with indicated display status Type and signature by Default, <WhichSignature> = -1 means control only on <WhichKind>.", py::arg("WhichKind"), py::arg("WhichSignature"), py::arg("theStatus"), py::arg("theListOfIO"));
cls_AIS_InteractiveContext.def("ObjectsInside", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0) -> void { return self.ObjectsInside(a0); });
cls_AIS_InteractiveContext.def("ObjectsInside", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0, const AIS_KindOfInteractive a1) -> void { return self.ObjectsInside(a0, a1); });
cls_AIS_InteractiveContext.def("ObjectsInside", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &, const AIS_KindOfInteractive, const Standard_Integer) const) &AIS_InteractiveContext::ObjectsInside, "fills <aListOfIO> with objects of a particular Type and Signature with no consideration of display status. by Default, <WhichSignature> = -1 means control only on <WhichKind>. if <WhichKind> = AIS_KOI_None and <WhichSignature> = -1, all the objects are put into the list.", py::arg("aListOfIO"), py::arg("WhichKind"), py::arg("WhichSignature"));
cls_AIS_InteractiveContext.def("RebuildSelectionStructs", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::RebuildSelectionStructs, "Rebuilds 1st level of BVH selection forcibly");
cls_AIS_InteractiveContext.def("Disconnect", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Disconnect(a0); });
cls_AIS_InteractiveContext.def("Disconnect", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::Disconnect, "Disconnects theObjToDisconnect from theAssembly and removes dependent selection structures", py::arg("theAssembly"), py::arg("theObjToDisconnect"));
cls_AIS_InteractiveContext.def("ObjectsForView", [](AIS_InteractiveContext &self, AIS_ListOfInteractive & a0, const opencascade::handle<V3d_View> & a1, const Standard_Boolean a2) -> void { return self.ObjectsForView(a0, a1, a2); });
cls_AIS_InteractiveContext.def("ObjectsForView", (void (AIS_InteractiveContext::*)(AIS_ListOfInteractive &, const opencascade::handle<V3d_View> &, const Standard_Boolean, const AIS_DisplayStatus) const) &AIS_InteractiveContext::ObjectsForView, "Query objects visible or hidden in specified view due to affinity mask.", py::arg("theListOfIO"), py::arg("theView"), py::arg("theIsVisibleInView"), py::arg("theStatus"));
cls_AIS_InteractiveContext.def("PurgeDisplay", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::PurgeDisplay, "Clears all the structures which don't belong to objects displayed at neutral point only effective when no Local Context is opened... returns the number of removed structures from the viewers.");
cls_AIS_InteractiveContext.def("GravityPoint", (gp_Pnt (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &) const) &AIS_InteractiveContext::GravityPoint, "Return rotation gravity point.", py::arg("theView"));
cls_AIS_InteractiveContext.def("DisplayActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::DisplayActiveSensitive, "Visualization of sensitives - for debugging purposes!", py::arg("aView"));
cls_AIS_InteractiveContext.def("ClearActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::ClearActiveSensitive, "Clear visualization of sensitives.", py::arg("aView"));
cls_AIS_InteractiveContext.def("DisplayActiveSensitive", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<V3d_View> &)) &AIS_InteractiveContext::DisplayActiveSensitive, "Visualization of sensitives - for debugging purposes!", py::arg("anObject"), py::arg("aView"));
cls_AIS_InteractiveContext.def("SetLocalAttributes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &AIS_InteractiveContext::SetLocalAttributes, "Sets the graphic attributes of the interactive object, such as visualization mode, color, and material.", py::arg("theIObj"), py::arg("theDrawer"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetLocalAttributes", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetLocalAttributes, "Removes the settings for local attributes of the Object and returns to defaults.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetCurrentFacingModel", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.SetCurrentFacingModel(a0); });
cls_AIS_InteractiveContext.def("SetCurrentFacingModel", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Aspect_TypeOfFacingModel)) &AIS_InteractiveContext::SetCurrentFacingModel, "change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE. This mean that attributes is applying both on the front and back face.", py::arg("aniobj"), py::arg("aModel"));
cls_AIS_InteractiveContext.def("HasColor", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::HasColor, "Returns true if a view of the Interactive Object has color.", py::arg("aniobj"));
cls_AIS_InteractiveContext.def("Color", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, Quantity_Color &) const) &AIS_InteractiveContext::Color, "Returns the color of the Object in the interactive context.", py::arg("aniobj"), py::arg("acolor"));
cls_AIS_InteractiveContext.def("SetColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Quantity_Color &, const Standard_Boolean)) &AIS_InteractiveContext::SetColor, "Sets the color of the selected entity.", py::arg("theIObj"), py::arg("theColor"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetColor", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetColor, "Removes the color selection for the selected entity.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Width", (Standard_Real (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::Width, "Returns the width of the Interactive Object in the interactive context.", py::arg("aniobj"));
cls_AIS_InteractiveContext.def("SetWidth", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetWidth, "Sets the width of the Object.", py::arg("theIObj"), py::arg("theValue"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetWidth", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetWidth, "Removes the width setting of the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetMaterial", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Graphic3d_MaterialAspect &, const Standard_Boolean)) &AIS_InteractiveContext::SetMaterial, "Provides the type of material setting for the view of the Object.", py::arg("theIObj"), py::arg("theMaterial"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetMaterial", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetMaterial, "Removes the type of material setting for viewing the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetTransparency", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetTransparency, "Provides the transparency settings for viewing the Object. The transparency value aValue may be between 0.0, opaque, and 1.0, fully transparent.", py::arg("theIObj"), py::arg("theValue"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnsetTransparency", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::UnsetTransparency, "Removes the transparency settings for viewing the Object.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetPolygonOffsets", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal, const Standard_Boolean)) &AIS_InteractiveContext::SetPolygonOffsets, "Sets up polygon offsets for the given AIS_InteractiveObject. It simply calls AIS_InteractiveObject::SetPolygonOffsets().", py::arg("theIObj"), py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("HasPolygonOffsets", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::HasPolygonOffsets, "Simply calls AIS_InteractiveObject::HasPolygonOffsets().", py::arg("anObj"));
cls_AIS_InteractiveContext.def("PolygonOffsets", [](AIS_InteractiveContext &self, const opencascade::handle<AIS_InteractiveObject> & anObj, Standard_Integer & aMode, Standard_ShortReal & aFactor, Standard_ShortReal & aUnits){ self.PolygonOffsets(anObj, aMode, aFactor, aUnits); return aMode; }, "Retrieves current polygon offsets settings for Object.", py::arg("anObj"), py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
cls_AIS_InteractiveContext.def("SetTrihedronSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetTrihedronSize, "Sets the size aSize of the trihedron. Is used to change the default value 100 mm for display of trihedra. Use of this function in one of your own interactive objects requires a call to the Compute function of the new class. This will recalculate the presentation for every trihedron displayed.", py::arg("theSize"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("TrihedronSize", (Standard_Real (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::TrihedronSize, "returns the current value of trihedron size.");
cls_AIS_InteractiveContext.def("SetPlaneSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetPlaneSize, "Sets the plane size defined by the length in the X direction XSize and that in the Y direction YSize.", py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetPlaneSize", (void (AIS_InteractiveContext::*)(const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetPlaneSize, "Sets the plane size aSize.", py::arg("theSize"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("PlaneSize", [](AIS_InteractiveContext &self, Standard_Real & XSize, Standard_Real & YSize){ Standard_Boolean rv = self.PlaneSize(XSize, YSize); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, XSize, YSize); }, "Returns true if the length in the X direction XSize is the same as that in the Y direction YSize.", py::arg("XSize"), py::arg("YSize"));
cls_AIS_InteractiveContext.def("SetDeviationCoefficient", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetDeviationCoefficient, "Sets the deviation coefficient theCoefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through the method: SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.", py::arg("theIObj"), py::arg("theCoefficient"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetDeviationAngle", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetDeviationAngle, "None", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetAngleAndDeviation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetAngleAndDeviation, "Calls the AIS_Shape SetAngleAndDeviation to set both Angle and Deviation coefficients", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetHLRDeviationCoefficient", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRDeviationCoefficient, "Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations. The Default value is 0.02.", py::arg("theIObj"), py::arg("theCoefficient"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetHLRDeviationAngle", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRDeviationAngle, "None", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetHLRAngleAndDeviation", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Real, const Standard_Boolean)) &AIS_InteractiveContext::SetHLRAngleAndDeviation, "Computes a HLRAngle and a HLRDeviationCoefficient by means of the angle anAngle and sets the corresponding methods in the default drawing tool with these values.", py::arg("theIObj"), py::arg("theAngle"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SetDeviationCoefficient", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetDeviationCoefficient, "Sets the deviation coefficient theCoefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient theCoefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through the method: SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.", py::arg("theCoefficient"));
cls_AIS_InteractiveContext.def("DeviationCoefficient", (Standard_Real (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DeviationCoefficient, "Returns the deviation coefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through Prs3d_Drawer::SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.");
cls_AIS_InteractiveContext.def("SetDeviationAngle", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetDeviationAngle, "default 12 degrees", py::arg("anAngle"));
cls_AIS_InteractiveContext.def("DeviationAngle", (Standard_Real (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DeviationAngle, "None");
cls_AIS_InteractiveContext.def("SetHLRDeviationCoefficient", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRDeviationCoefficient, "Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations. The Default value is 0.02.", py::arg("aCoefficient"));
cls_AIS_InteractiveContext.def("HLRDeviationCoefficient", (Standard_Real (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HLRDeviationCoefficient, "Returns the real number value of the hidden line removal deviation coefficient. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient give the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. To find the hidden lines, hidden line display mode entails recalculation of the view at each different projector perspective. Because hidden lines entail calculations of more than usual complexity to decompose them into these triangles, a deviation coefficient allowing greater tolerance is used. This increases efficiency in calculation. The Default value is 0.02.");
cls_AIS_InteractiveContext.def("SetHLRAngle", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRAngle, "Sets the HLR angle.", py::arg("theAngle"));
cls_AIS_InteractiveContext.def("HLRAngle", (Standard_Real (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HLRAngle, "Returns the real number value of the deviation angle in hidden line removal views in this interactive context. The default value is 20*PI/180.");
cls_AIS_InteractiveContext.def("SetHLRAngleAndDeviation", (void (AIS_InteractiveContext::*)(const Standard_Real)) &AIS_InteractiveContext::SetHLRAngleAndDeviation, "compute with theAngle a HLRAngle and a HLRDeviationCoefficient and set them in myHLRAngle and in myHLRDeviationCoefficient of myDefaultDrawer; theAngle is in radian; ( 1 deg < angle in deg < 20 deg)", py::arg("theAngle"));
cls_AIS_InteractiveContext.def("HiddenLineAspect", (opencascade::handle<Prs3d_LineAspect> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::HiddenLineAspect, "Initializes hidden line aspect in the default drawing tool, or Drawer. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_DASH Width: 1.");
cls_AIS_InteractiveContext.def("SetHiddenLineAspect", (void (AIS_InteractiveContext::*)(const opencascade::handle<Prs3d_LineAspect> &) const) &AIS_InteractiveContext::SetHiddenLineAspect, "Sets the hidden line aspect anAspect. Aspect defines display attributes for hidden lines in HLR projections.", py::arg("anAspect"));
cls_AIS_InteractiveContext.def("DrawHiddenLine", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DrawHiddenLine, "returns Standard_True if the hidden lines are to be drawn. By default the hidden lines are not drawn.");
cls_AIS_InteractiveContext.def("EnableDrawHiddenLine", (void (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::EnableDrawHiddenLine, "None");
cls_AIS_InteractiveContext.def("DisableDrawHiddenLine", (void (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DisableDrawHiddenLine, "None");
cls_AIS_InteractiveContext.def("SetIsoNumber", [](AIS_InteractiveContext &self, const Standard_Integer a0) -> void { return self.SetIsoNumber(a0); });
cls_AIS_InteractiveContext.def("SetIsoNumber", (void (AIS_InteractiveContext::*)(const Standard_Integer, const AIS_TypeOfIso)) &AIS_InteractiveContext::SetIsoNumber, "Sets the number of U and V isoparameters displayed.", py::arg("NbIsos"), py::arg("WhichIsos"));
cls_AIS_InteractiveContext.def("IsoNumber", [](AIS_InteractiveContext &self) -> Standard_Integer { return self.IsoNumber(); });
cls_AIS_InteractiveContext.def("IsoNumber", (Standard_Integer (AIS_InteractiveContext::*)(const AIS_TypeOfIso)) &AIS_InteractiveContext::IsoNumber, "Returns the number of U and V isoparameters displayed.", py::arg("WhichIsos"));
cls_AIS_InteractiveContext.def("IsoOnPlane", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::IsoOnPlane, "Returns True if drawing isoparameters on planes is enabled.", py::arg("SwitchOn"));
cls_AIS_InteractiveContext.def("IsoOnPlane", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::IsoOnPlane, "Returns True if drawing isoparameters on planes is enabled. if <forUIsos> = False,");
cls_AIS_InteractiveContext.def("IsoOnTriangulation", (void (AIS_InteractiveContext::*)(const Standard_Boolean, const opencascade::handle<AIS_InteractiveObject> &)) &AIS_InteractiveContext::IsoOnTriangulation, "Enables or disables on-triangulation build for isolines for a particular object. In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.", py::arg("theIsEnabled"), py::arg("theObject"));
cls_AIS_InteractiveContext.def("IsoOnTriangulation", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::IsoOnTriangulation, "Enables or disables on-triangulation build for isolines for default drawer. In case if on-triangulation builder is disabled, default on-plane builder will compute isolines for the object given.", py::arg("theToSwitchOn"));
cls_AIS_InteractiveContext.def("IsoOnTriangulation", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::IsoOnTriangulation, "Returns true if drawing isolines on triangulation algorithm is enabled.");
cls_AIS_InteractiveContext.def("SetCurrentObject", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SetCurrentObject, "Updates the view of the current object in open context. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("AddOrRemoveCurrentObject", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::AddOrRemoveCurrentObject, "Allows to add or remove the object given to the list of current and highlight/unhighlight it correspondingly. Is valid for global context only; for local context use method AddOrRemoveSelected. Since this method makes sence only for neutral point selection of a whole object, if 0 selection of the object is empty this method simply does nothing.", py::arg("theObj"), py::arg("theIsToUpdateViewer"));
cls_AIS_InteractiveContext.def("UpdateCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::UpdateCurrent, "Updates the list of current objects, i.e. hilights new current objects, removes hilighting from former current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
cls_AIS_InteractiveContext.def("IsCurrent", (Standard_Boolean (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &) const) &AIS_InteractiveContext::IsCurrent, "Returns true if there is a non-null interactive object in Neutral Point. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theObject"));
cls_AIS_InteractiveContext.def("InitCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::InitCurrent, "Initializes a scan of the current selected objects in Neutral Point. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
cls_AIS_InteractiveContext.def("MoreCurrent", (Standard_Boolean (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::MoreCurrent, "Returns true if there is another object found by the scan of the list of current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
cls_AIS_InteractiveContext.def("NextCurrent", (void (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NextCurrent, "Continues the scan to the next object in the list of current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
cls_AIS_InteractiveContext.def("Current", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::Current, "Returns the current interactive object. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.");
cls_AIS_InteractiveContext.def("NbCurrents", (Standard_Integer (AIS_InteractiveContext::*)()) &AIS_InteractiveContext::NbCurrents, "None");
cls_AIS_InteractiveContext.def("HilightCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::HilightCurrents, "Highlights current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("UnhilightCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::UnhilightCurrents, "Removes highlighting from current objects. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("ClearCurrents", (void (AIS_InteractiveContext::*)(const Standard_Boolean)) &AIS_InteractiveContext::ClearCurrents, "Empties previous current objects in order to get the current objects detected by the selector using UpdateCurrent. Objects selected when there is no open local context are called current objects; those selected in open local context, selected objects.", py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("DetectedCurrentShape", (const TopoDS_Shape & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedCurrentShape, "Returns current mouse-detected shape or empty (null) shape, if current interactive object is not a shape (AIS_Shape) or there is no current mouse-detected interactive object at all. DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().");
cls_AIS_InteractiveContext.def("DetectedCurrentObject", (opencascade::handle<AIS_InteractiveObject> (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::DetectedCurrentObject, "Returns current mouse-detected interactive object or null object, if there is no currently detected interactives DetectedCurrentOwner()/InitDetected()/MoreDetected()/NextDetected().");
cls_AIS_InteractiveContext.def("SubIntensityColor", (const Quantity_Color & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::SubIntensityColor, "Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight, but without actual selection (e.g., global status and owner's selection state will not be updated). The method returns the color of such highlighting. By default, it is Quantity_NOC_GRAY40.");
cls_AIS_InteractiveContext.def("SetSubIntensityColor", (void (AIS_InteractiveContext::*)(const Quantity_Color &)) &AIS_InteractiveContext::SetSubIntensityColor, "Sub-intensity allows temporary highlighting of particular objects with specified color in a manner of selection highlight, but without actual selection (e.g., global status and owner's selection state will not be updated). The method sets up the color for such highlighting. By default, this is Quantity_NOC_GRAY40.", py::arg("theColor"));
cls_AIS_InteractiveContext.def("SubIntensityOn", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOn, "Highlights, and removes highlights from, the displayed object which is displayed at Neutral Point with subintensity color. Available only for active local context. There is no effect if there is no local context. If a local context is open, the presentation of the Interactive Object activates the selection mode.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("SubIntensityOff", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_InteractiveObject> &, const Standard_Boolean)) &AIS_InteractiveContext::SubIntensityOff, "Removes the subintensity option for the entity. If a local context is open, the presentation of the Interactive Object activates the selection mode.", py::arg("theIObj"), py::arg("theToUpdateViewer"));
cls_AIS_InteractiveContext.def("Selection", (const opencascade::handle<AIS_Selection> & (AIS_InteractiveContext::*)() const) &AIS_InteractiveContext::Selection, "Returns selection instance");
cls_AIS_InteractiveContext.def("SetSelection", (void (AIS_InteractiveContext::*)(const opencascade::handle<AIS_Selection> &)) &AIS_InteractiveContext::SetSelection, "Sets selection instance to manipulate a container of selected owners", py::arg("theSelection"));

// CLASS: AIS_ANIMATIONOBJECT
py::class_<AIS_AnimationObject, opencascade::handle<AIS_AnimationObject>, AIS_Animation> cls_AIS_AnimationObject(mod, "AIS_AnimationObject", "Animation defining object transformation.");

// Constructors
cls_AIS_AnimationObject.def(py::init<const TCollection_AsciiString &, const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const gp_Trsf &>(), py::arg("theAnimationName"), py::arg("theContext"), py::arg("theObject"), py::arg("theTrsfStart"), py::arg("theTrsfEnd"));

// Methods
cls_AIS_AnimationObject.def_static("get_type_name_", (const char * (*)()) &AIS_AnimationObject::get_type_name, "None");
cls_AIS_AnimationObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AnimationObject::get_type_descriptor, "None");
cls_AIS_AnimationObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AnimationObject::*)() const) &AIS_AnimationObject::DynamicType, "None");

// CLASS: AIS_ATTRIBUTEFILTER
py::class_<AIS_AttributeFilter, opencascade::handle<AIS_AttributeFilter>, SelectMgr_Filter> cls_AIS_AttributeFilter(mod, "AIS_AttributeFilter", "Selects Interactive Objects, which have the desired width or color. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it has the required color and width attributes. If the object returns true in each case, it is kept. If not, it is rejected. This filter is used only in an open local context. In the Collector viewer, you can only locate Interactive Objects, which answer positively to the filters, which are in position when a local context is open.");

// Constructors
cls_AIS_AttributeFilter.def(py::init<>());
cls_AIS_AttributeFilter.def(py::init<const Quantity_NameOfColor>(), py::arg("aCol"));
cls_AIS_AttributeFilter.def(py::init<const Standard_Real>(), py::arg("aWidth"));

// Methods
cls_AIS_AttributeFilter.def("HasColor", (Standard_Boolean (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::HasColor, "Indicates that the Interactive Object has the color setting specified by the argument aCol at construction time.");
cls_AIS_AttributeFilter.def("HasWidth", (Standard_Boolean (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::HasWidth, "Indicates that the Interactive Object has the width setting specified by the argument aWidth at construction time.");
cls_AIS_AttributeFilter.def("SetColor", (void (AIS_AttributeFilter::*)(const Quantity_NameOfColor)) &AIS_AttributeFilter::SetColor, "Sets the color aCol. This must be chosen from the list of colors in Quantity_NameOfColor.", py::arg("aCol"));
cls_AIS_AttributeFilter.def("SetWidth", (void (AIS_AttributeFilter::*)(const Standard_Real)) &AIS_AttributeFilter::SetWidth, "Sets the line width aWidth.", py::arg("aWidth"));
cls_AIS_AttributeFilter.def("UnsetColor", (void (AIS_AttributeFilter::*)()) &AIS_AttributeFilter::UnsetColor, "Removes the setting for color from the filter.");
cls_AIS_AttributeFilter.def("UnsetWidth", (void (AIS_AttributeFilter::*)()) &AIS_AttributeFilter::UnsetWidth, "Removes the setting for width from the filter.");
cls_AIS_AttributeFilter.def("IsOk", (Standard_Boolean (AIS_AttributeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_AttributeFilter::IsOk, "Indicates that the selected Interactive Object passes the filter. The owner, anObj, can be either direct or user. A direct owner is the corresponding construction element, whereas a user is the compound shape of which the entity forms a part. If the Interactive Object returns Standard_True when detected by the Local Context selector through the mouse, the object is kept; if not, it is rejected.", py::arg("anObj"));
cls_AIS_AttributeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_AttributeFilter::get_type_name, "None");
cls_AIS_AttributeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_AttributeFilter::get_type_descriptor, "None");
cls_AIS_AttributeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_AttributeFilter::*)() const) &AIS_AttributeFilter::DynamicType, "None");

// CLASS: AIS_AXIS
py::class_<AIS_Axis, opencascade::handle<AIS_Axis>, AIS_InteractiveObject> cls_AIS_Axis(mod, "AIS_Axis", "Locates the x, y and z axes in an Interactive Object. These are used to orient it correctly in presentations from different viewpoints, or to construct a revolved shape, for example, from one of the axes. Conversely, an axis can be created to build a revolved shape and then situated relative to one of the axes of the view.");

// Constructors
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Line> &>(), py::arg("aComponent"));
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfAxis>(), py::arg("aComponent"), py::arg("anAxisType"));
cls_AIS_Axis.def(py::init<const opencascade::handle<Geom_Axis1Placement> &>(), py::arg("anAxis"));

// Methods
cls_AIS_Axis.def_static("get_type_name_", (const char * (*)()) &AIS_Axis::get_type_name, "None");
cls_AIS_Axis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Axis::get_type_descriptor, "None");
cls_AIS_Axis.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Axis::*)() const) &AIS_Axis::DynamicType, "None");
cls_AIS_Axis.def("Component", (const opencascade::handle<Geom_Line> & (AIS_Axis::*)() const) &AIS_Axis::Component, "Returns the axis entity aComponent and identifies it as a component of a shape.");
cls_AIS_Axis.def("SetComponent", (void (AIS_Axis::*)(const opencascade::handle<Geom_Line> &)) &AIS_Axis::SetComponent, "Sets the coordinates of the lin aComponent.", py::arg("aComponent"));
cls_AIS_Axis.def("Axis2Placement", (const opencascade::handle<Geom_Axis2Placement> & (AIS_Axis::*)() const) &AIS_Axis::Axis2Placement, "Returns the position of axis2 and positions it by identifying it as the x, y, or z axis and giving its direction in 3D space. The coordinate system used is right-handed.");
cls_AIS_Axis.def("SetAxis2Placement", (void (AIS_Axis::*)(const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfAxis)) &AIS_Axis::SetAxis2Placement, "Allows you to provide settings for aComponent:the position and direction of an axis in 3D space. The coordinate system used is right-handed.", py::arg("aComponent"), py::arg("anAxisType"));
cls_AIS_Axis.def("SetAxis1Placement", (void (AIS_Axis::*)(const opencascade::handle<Geom_Axis1Placement> &)) &AIS_Axis::SetAxis1Placement, "Constructs a new line to serve as the axis anAxis in 3D space.", py::arg("anAxis"));
cls_AIS_Axis.def("TypeOfAxis", (AIS_TypeOfAxis (AIS_Axis::*)() const) &AIS_Axis::TypeOfAxis, "Returns the type of axis.");
cls_AIS_Axis.def("SetTypeOfAxis", (void (AIS_Axis::*)(const AIS_TypeOfAxis)) &AIS_Axis::SetTypeOfAxis, "Constructs the entity theTypeAxis to stock information concerning type of axis.", py::arg("theTypeAxis"));
cls_AIS_Axis.def("IsXYZAxis", (Standard_Boolean (AIS_Axis::*)() const) &AIS_Axis::IsXYZAxis, "Returns a signature of 2 for axis datums. When you activate mode 2 by a signature, you pick AIS objects of type AIS_Axis.");
cls_AIS_Axis.def("AcceptDisplayMode", (Standard_Boolean (AIS_Axis::*)(const Standard_Integer) const) &AIS_Axis::AcceptDisplayMode, "Returns true if the interactive object accepts the display mode aMode.", py::arg("aMode"));
cls_AIS_Axis.def("Compute", (void (AIS_Axis::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Axis::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Axis.def("Signature", (Standard_Integer (AIS_Axis::*)() const) &AIS_Axis::Signature, "None");
cls_AIS_Axis.def("Type", (AIS_KindOfInteractive (AIS_Axis::*)() const) &AIS_Axis::Type, "None");
cls_AIS_Axis.def("SetColor", (void (AIS_Axis::*)(const Quantity_Color &)) &AIS_Axis::SetColor, "None", py::arg("aColor"));
cls_AIS_Axis.def("SetWidth", (void (AIS_Axis::*)(const Standard_Real)) &AIS_Axis::SetWidth, "None", py::arg("aValue"));
cls_AIS_Axis.def("UnsetColor", (void (AIS_Axis::*)()) &AIS_Axis::UnsetColor, "None");
cls_AIS_Axis.def("UnsetWidth", (void (AIS_Axis::*)()) &AIS_Axis::UnsetWidth, "None");

// CLASS: AIS_BADEDGEFILTER
py::class_<AIS_BadEdgeFilter, opencascade::handle<AIS_BadEdgeFilter>, SelectMgr_Filter> cls_AIS_BadEdgeFilter(mod, "AIS_BadEdgeFilter", "A Class");

// Constructors
cls_AIS_BadEdgeFilter.def(py::init<>());

// Methods
cls_AIS_BadEdgeFilter.def("ActsOn", (Standard_Boolean (AIS_BadEdgeFilter::*)(const TopAbs_ShapeEnum) const) &AIS_BadEdgeFilter::ActsOn, "None", py::arg("aType"));
cls_AIS_BadEdgeFilter.def("IsOk", (Standard_Boolean (AIS_BadEdgeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_BadEdgeFilter::IsOk, "None", py::arg("EO"));
cls_AIS_BadEdgeFilter.def("SetContour", (void (AIS_BadEdgeFilter::*)(const Standard_Integer)) &AIS_BadEdgeFilter::SetContour, "sets <myContour> with current contour. used by IsOk.", py::arg("Index"));
cls_AIS_BadEdgeFilter.def("AddEdge", (void (AIS_BadEdgeFilter::*)(const TopoDS_Edge &, const Standard_Integer)) &AIS_BadEdgeFilter::AddEdge, "Adds an edge to the list of non-selectionnable edges.", py::arg("anEdge"), py::arg("Index"));
cls_AIS_BadEdgeFilter.def("RemoveEdges", (void (AIS_BadEdgeFilter::*)(const Standard_Integer)) &AIS_BadEdgeFilter::RemoveEdges, "removes from the list of non-selectionnable edges all edges in the contour <Index>.", py::arg("Index"));
cls_AIS_BadEdgeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_BadEdgeFilter::get_type_name, "None");
cls_AIS_BadEdgeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_BadEdgeFilter::get_type_descriptor, "None");
cls_AIS_BadEdgeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_BadEdgeFilter::*)() const) &AIS_BadEdgeFilter::DynamicType, "None");

// CLASS: AIS_C0REGULARITYFILTER
py::class_<AIS_C0RegularityFilter, opencascade::handle<AIS_C0RegularityFilter>, SelectMgr_Filter> cls_AIS_C0RegularityFilter(mod, "AIS_C0RegularityFilter", "None");

// Constructors
cls_AIS_C0RegularityFilter.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Methods
cls_AIS_C0RegularityFilter.def("ActsOn", (Standard_Boolean (AIS_C0RegularityFilter::*)(const TopAbs_ShapeEnum) const) &AIS_C0RegularityFilter::ActsOn, "None", py::arg("aType"));
cls_AIS_C0RegularityFilter.def("IsOk", (Standard_Boolean (AIS_C0RegularityFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_C0RegularityFilter::IsOk, "None", py::arg("EO"));
cls_AIS_C0RegularityFilter.def_static("get_type_name_", (const char * (*)()) &AIS_C0RegularityFilter::get_type_name, "None");
cls_AIS_C0RegularityFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_C0RegularityFilter::get_type_descriptor, "None");
cls_AIS_C0RegularityFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_C0RegularityFilter::*)() const) &AIS_C0RegularityFilter::DynamicType, "None");

// CLASS: AIS_CAMERAFRUSTUM
py::class_<AIS_CameraFrustum, opencascade::handle<AIS_CameraFrustum>, AIS_InteractiveObject> cls_AIS_CameraFrustum(mod, "AIS_CameraFrustum", "Presentation for drawing camera frustum. Default configuration is built with filling and some transparency.");

// Constructors
cls_AIS_CameraFrustum.def(py::init<>());

// Methods
cls_AIS_CameraFrustum.def_static("get_type_name_", (const char * (*)()) &AIS_CameraFrustum::get_type_name, "None");
cls_AIS_CameraFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_CameraFrustum::get_type_descriptor, "None");
cls_AIS_CameraFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_CameraFrustum::*)() const) &AIS_CameraFrustum::DynamicType, "None");
cls_AIS_CameraFrustum.def("SetCameraFrustum", (void (AIS_CameraFrustum::*)(const opencascade::handle<Graphic3d_Camera> &)) &AIS_CameraFrustum::SetCameraFrustum, "Sets camera frustum.", py::arg("theCamera"));
cls_AIS_CameraFrustum.def("SetColor", (void (AIS_CameraFrustum::*)(const Quantity_Color &)) &AIS_CameraFrustum::SetColor, "Setup custom color.", py::arg("theColor"));
cls_AIS_CameraFrustum.def("UnsetColor", (void (AIS_CameraFrustum::*)()) &AIS_CameraFrustum::UnsetColor, "Restore default color.");
cls_AIS_CameraFrustum.def("UnsetTransparency", (void (AIS_CameraFrustum::*)()) &AIS_CameraFrustum::UnsetTransparency, "Restore transparency setting.");
cls_AIS_CameraFrustum.def("AcceptDisplayMode", (Standard_Boolean (AIS_CameraFrustum::*)(const Standard_Integer) const) &AIS_CameraFrustum::AcceptDisplayMode, "Return true if specified display mode is supported.", py::arg("theMode"));

// Enums
py::enum_<AIS_CameraFrustum::SelectionMode>(cls_AIS_CameraFrustum, "SelectionMode", "Selection modes supported by this object")
	.value("SelectionMode_Edges", AIS_CameraFrustum::SelectionMode::SelectionMode_Edges)
	.value("SelectionMode_Volume", AIS_CameraFrustum::SelectionMode::SelectionMode_Volume)
	.export_values();

// CLASS: AIS_RELATION
py::class_<AIS_Relation, opencascade::handle<AIS_Relation>, AIS_InteractiveObject> cls_AIS_Relation(mod, "AIS_Relation", "One of the four types of interactive object in AIS,comprising dimensions and constraints. Serves as the abstract class for the seven relation classes as well as the seven dimension classes. The statuses available for relations between shapes are as follows: - 0 - there is no connection to a shape; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. The connection takes the form of an edge between the two shapes.");

// Methods
cls_AIS_Relation.def_static("get_type_name_", (const char * (*)()) &AIS_Relation::get_type_name, "None");
cls_AIS_Relation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Relation::get_type_descriptor, "None");
cls_AIS_Relation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Relation::*)() const) &AIS_Relation::DynamicType, "None");
cls_AIS_Relation.def("SetColor", (void (AIS_Relation::*)(const Quantity_Color &)) &AIS_Relation::SetColor, "Allows you to provide settings for the color theColor of the lines representing the relation between the two shapes.", py::arg("theColor"));
cls_AIS_Relation.def("UnsetColor", (void (AIS_Relation::*)()) &AIS_Relation::UnsetColor, "Allows you to remove settings for the color of the lines representing the relation between the two shapes.");
cls_AIS_Relation.def("Type", (AIS_KindOfInteractive (AIS_Relation::*)() const) &AIS_Relation::Type, "None");
cls_AIS_Relation.def("KindOfDimension", (AIS_KindOfDimension (AIS_Relation::*)() const) &AIS_Relation::KindOfDimension, "Indicates that the type of dimension is unknown.");
cls_AIS_Relation.def("IsMovable", (Standard_Boolean (AIS_Relation::*)() const) &AIS_Relation::IsMovable, "Returns true if the interactive object is movable.");
cls_AIS_Relation.def("FirstShape", (const TopoDS_Shape & (AIS_Relation::*)() const) &AIS_Relation::FirstShape, "None");
cls_AIS_Relation.def("SetFirstShape", (void (AIS_Relation::*)(const TopoDS_Shape &)) &AIS_Relation::SetFirstShape, "None", py::arg("aFShape"));
cls_AIS_Relation.def("SecondShape", (const TopoDS_Shape & (AIS_Relation::*)() const) &AIS_Relation::SecondShape, "Returns the second shape.");
cls_AIS_Relation.def("SetSecondShape", (void (AIS_Relation::*)(const TopoDS_Shape &)) &AIS_Relation::SetSecondShape, "Allows you to identify the second shape aSShape relative to the first.", py::arg("aSShape"));
cls_AIS_Relation.def("SetBndBox", (void (AIS_Relation::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AIS_Relation::SetBndBox, "None", py::arg("theXmin"), py::arg("theYmin"), py::arg("theZmin"), py::arg("theXmax"), py::arg("theYmax"), py::arg("theZmax"));
cls_AIS_Relation.def("UnsetBndBox", (void (AIS_Relation::*)()) &AIS_Relation::UnsetBndBox, "None");
cls_AIS_Relation.def("Plane", (const opencascade::handle<Geom_Plane> & (AIS_Relation::*)() const) &AIS_Relation::Plane, "Returns the plane.");
cls_AIS_Relation.def("SetPlane", (void (AIS_Relation::*)(const opencascade::handle<Geom_Plane> &)) &AIS_Relation::SetPlane, "Allows you to set the plane thePlane. This is used to define relations and dimensions in several daughter classes.", py::arg("thePlane"));
cls_AIS_Relation.def("Value", (Standard_Real (AIS_Relation::*)() const) &AIS_Relation::Value, "Returns the value of each object in the relation.");
cls_AIS_Relation.def("SetValue", (void (AIS_Relation::*)(const Standard_Real)) &AIS_Relation::SetValue, "Allows you to provide settings for the value theVal for each object in the relation.", py::arg("theVal"));
cls_AIS_Relation.def("Position", (const gp_Pnt & (AIS_Relation::*)() const) &AIS_Relation::Position, "Returns the position set using SetPosition.");
cls_AIS_Relation.def("SetPosition", (void (AIS_Relation::*)(const gp_Pnt &)) &AIS_Relation::SetPosition, "Allows you to provide the objects in the relation with settings for a non-default position.", py::arg("thePosition"));
cls_AIS_Relation.def("Text", (const TCollection_ExtendedString & (AIS_Relation::*)() const) &AIS_Relation::Text, "Returns settings for text aspect.");
cls_AIS_Relation.def("SetText", (void (AIS_Relation::*)(const TCollection_ExtendedString &)) &AIS_Relation::SetText, "Allows you to provide the settings theText for text aspect.", py::arg("theText"));
cls_AIS_Relation.def("ArrowSize", (Standard_Real (AIS_Relation::*)() const) &AIS_Relation::ArrowSize, "Returns the value for the size of the arrow identifying the relation between the two shapes.");
cls_AIS_Relation.def("SetArrowSize", (void (AIS_Relation::*)(const Standard_Real)) &AIS_Relation::SetArrowSize, "Allows you to provide settings for the size of the arrow theArrowSize identifying the relation between the two shapes.", py::arg("theArrowSize"));
cls_AIS_Relation.def("SymbolPrs", (DsgPrs_ArrowSide (AIS_Relation::*)() const) &AIS_Relation::SymbolPrs, "Returns the value of the symbol presentation. This will be one of: - AS_NONE - none - AS_FIRSTAR - first arrow - AS_LASTAR - last arrow - AS_BOTHAR - both arrows - AS_FIRSTPT - first point - AS_LASTPT - last point - AS_BOTHPT - both points - AS_FIRSTAR_LASTPT - first arrow, last point - AS_FIRSTPT_LASTAR - first point, last arrow");
cls_AIS_Relation.def("SetSymbolPrs", (void (AIS_Relation::*)(const DsgPrs_ArrowSide)) &AIS_Relation::SetSymbolPrs, "Allows you to provide settings for the symbol presentation.", py::arg("theSymbolPrs"));
cls_AIS_Relation.def("SetExtShape", (void (AIS_Relation::*)(const Standard_Integer)) &AIS_Relation::SetExtShape, "Allows you to set the status of the extension shape by the index aIndex. The status will be one of the following: - 0 - there is no connection to a shape; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape.", py::arg("theIndex"));
cls_AIS_Relation.def("ExtShape", (Standard_Integer (AIS_Relation::*)() const) &AIS_Relation::ExtShape, "Returns the status index of the extension shape.");
cls_AIS_Relation.def("AcceptDisplayMode", (Standard_Boolean (AIS_Relation::*)(const Standard_Integer) const) &AIS_Relation::AcceptDisplayMode, "Returns true if the display mode aMode is accepted for the Interactive Objects in the relation. ComputeProjPresentation(me; aPres : Presentation from Prs3d; Curve1 : Curve from Geom; Curve2 : Curve from Geom; FirstP1 : Pnt from gp; LastP1 : Pnt from gp; FirstP2 : Pnt from gp; LastP2 : Pnt from gp; aColor : NameOfColor from Quantity = Quantity_NOC_PURPLE; aWidth : Real from Standard = 2; aProjTOL : TypeOfLine from Aspect = Aspect_TOL_DASH; aCallTOL : TypeOfLine from Aspect = Aspect_TOL_DOT)", py::arg("aMode"));
cls_AIS_Relation.def("SetAutomaticPosition", (void (AIS_Relation::*)(const Standard_Boolean)) &AIS_Relation::SetAutomaticPosition, "None", py::arg("theStatus"));
cls_AIS_Relation.def("AutomaticPosition", (Standard_Boolean (AIS_Relation::*)() const) &AIS_Relation::AutomaticPosition, "None");

// CLASS: AIS_CHAMF2DDIMENSION
py::class_<AIS_Chamf2dDimension, opencascade::handle<AIS_Chamf2dDimension>, AIS_Relation> cls_AIS_Chamf2dDimension(mod, "AIS_Chamf2dDimension", "A framework to define display of 2D chamfers. A chamfer is displayed with arrows and text. The text gives the length of the chamfer if it is a symmetrical chamfer, or the angle if it is not.");

// Constructors
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"));
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_Chamf2dDimension.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aFShape"), py::arg("aPlane"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Methods
cls_AIS_Chamf2dDimension.def_static("get_type_name_", (const char * (*)()) &AIS_Chamf2dDimension::get_type_name, "None");
cls_AIS_Chamf2dDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Chamf2dDimension::get_type_descriptor, "None");
cls_AIS_Chamf2dDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::DynamicType, "None");
cls_AIS_Chamf2dDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::KindOfDimension, "Indicates that we are concerned with a 2d length.");
cls_AIS_Chamf2dDimension.def("IsMovable", (Standard_Boolean (AIS_Chamf2dDimension::*)() const) &AIS_Chamf2dDimension::IsMovable, "Returns true if the 2d chamfer dimension is movable.");
cls_AIS_Chamf2dDimension.def("Compute", (void (AIS_Chamf2dDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Chamf2dDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_CHAMF3DDIMENSION
py::class_<AIS_Chamf3dDimension, opencascade::handle<AIS_Chamf3dDimension>, AIS_Relation> cls_AIS_Chamf3dDimension(mod, "AIS_Chamf3dDimension", "A framework to define display of 3D chamfers. A chamfer is displayed with arrows and text. The text gives the length of the chamfer if it is a symmetrical chamfer, or the angle if it is not.");

// Constructors
cls_AIS_Chamf3dDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aFShape"), py::arg("aVal"), py::arg("aText"));
cls_AIS_Chamf3dDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aFShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_Chamf3dDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aFShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Methods
cls_AIS_Chamf3dDimension.def_static("get_type_name_", (const char * (*)()) &AIS_Chamf3dDimension::get_type_name, "None");
cls_AIS_Chamf3dDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Chamf3dDimension::get_type_descriptor, "None");
cls_AIS_Chamf3dDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Chamf3dDimension::*)() const) &AIS_Chamf3dDimension::DynamicType, "None");
cls_AIS_Chamf3dDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_Chamf3dDimension::*)() const) &AIS_Chamf3dDimension::KindOfDimension, "Indicates that we are concerned with a 3d length.");
cls_AIS_Chamf3dDimension.def("IsMovable", (Standard_Boolean (AIS_Chamf3dDimension::*)() const) &AIS_Chamf3dDimension::IsMovable, "Returns true if the 3d chamfer dimension is movable.");
cls_AIS_Chamf3dDimension.def("Compute", (void (AIS_Chamf3dDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Chamf3dDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_CIRCLE
py::class_<AIS_Circle, opencascade::handle<AIS_Circle>, AIS_InteractiveObject> cls_AIS_Circle(mod, "AIS_Circle", "Constructs circle datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &>(), py::arg("aCircle"));
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real>(), py::arg("theCircle"), py::arg("theUStart"), py::arg("theUEnd"));
cls_AIS_Circle.def(py::init<const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theCircle"), py::arg("theUStart"), py::arg("theUEnd"), py::arg("theIsFilledCircleSens"));

// Methods
cls_AIS_Circle.def_static("get_type_name_", (const char * (*)()) &AIS_Circle::get_type_name, "None");
cls_AIS_Circle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Circle::get_type_descriptor, "None");
cls_AIS_Circle.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Circle::*)() const) &AIS_Circle::DynamicType, "None");
cls_AIS_Circle.def("Compute", (void (AIS_Circle::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Circle::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Circle.def("Signature", (Standard_Integer (AIS_Circle::*)() const) &AIS_Circle::Signature, "Returns index 6 by default.");
cls_AIS_Circle.def("Type", (AIS_KindOfInteractive (AIS_Circle::*)() const) &AIS_Circle::Type, "Indicates that the type of Interactive Object is a datum.");
cls_AIS_Circle.def("Circle", (const opencascade::handle<Geom_Circle> & (AIS_Circle::*)() const) &AIS_Circle::Circle, "Returns the circle component defined in SetCircle.");
cls_AIS_Circle.def("Parameters", [](AIS_Circle &self, Standard_Real & theU1, Standard_Real & theU2){ self.Parameters(theU1, theU2); return std::tuple<Standard_Real &, Standard_Real &>(theU1, theU2); }, "Constructs instances of the starting point and the end point parameters, theU1 and theU2.", py::arg("theU1"), py::arg("theU2"));
cls_AIS_Circle.def("SetCircle", (void (AIS_Circle::*)(const opencascade::handle<Geom_Circle> &)) &AIS_Circle::SetCircle, "Allows you to provide settings for the circle datum aCircle.", py::arg("theCircle"));
cls_AIS_Circle.def("SetFirstParam", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetFirstParam, "Allows you to set the parameter theU for the starting point of an arc.", py::arg("theU"));
cls_AIS_Circle.def("SetLastParam", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetLastParam, "Allows you to provide the parameter theU for the end point of an arc.", py::arg("theU"));
cls_AIS_Circle.def("SetColor", (void (AIS_Circle::*)(const Quantity_Color &)) &AIS_Circle::SetColor, "None", py::arg("aColor"));
cls_AIS_Circle.def("SetWidth", (void (AIS_Circle::*)(const Standard_Real)) &AIS_Circle::SetWidth, "Assigns the width aValue to the solid line boundary of the circle datum.", py::arg("aValue"));
cls_AIS_Circle.def("UnsetColor", (void (AIS_Circle::*)()) &AIS_Circle::UnsetColor, "Removes color from the solid line boundary of the circle datum.");
cls_AIS_Circle.def("UnsetWidth", (void (AIS_Circle::*)()) &AIS_Circle::UnsetWidth, "Removes width settings from the solid line boundary of the circle datum.");
cls_AIS_Circle.def("IsFilledCircleSens", (Standard_Boolean (AIS_Circle::*)() const) &AIS_Circle::IsFilledCircleSens, "Returns the type of sensitivity for the circle;");
cls_AIS_Circle.def("SetFilledCircleSens", (void (AIS_Circle::*)(const Standard_Boolean)) &AIS_Circle::SetFilledCircleSens, "Sets the type of sensitivity for the circle. If theIsFilledCircleSens set to Standard_True then the whole circle will be detectable, otherwise only the boundary of the circle.", py::arg("theIsFilledCircleSens"));

// CLASS: AIS_COLOREDDRAWER
py::class_<AIS_ColoredDrawer, opencascade::handle<AIS_ColoredDrawer>, Prs3d_Drawer> cls_AIS_ColoredDrawer(mod, "AIS_ColoredDrawer", "Customizable properties.");

// Constructors
cls_AIS_ColoredDrawer.def(py::init<const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theLink"));

// Fields
cls_AIS_ColoredDrawer.def_readwrite("myIsHidden", &AIS_ColoredDrawer::myIsHidden, "");
cls_AIS_ColoredDrawer.def_readwrite("myHasOwnColor", &AIS_ColoredDrawer::myHasOwnColor, "None");
cls_AIS_ColoredDrawer.def_readwrite("myHasOwnTransp", &AIS_ColoredDrawer::myHasOwnTransp, "None");
cls_AIS_ColoredDrawer.def_readwrite("myHasOwnWidth", &AIS_ColoredDrawer::myHasOwnWidth, "None");

// Methods
cls_AIS_ColoredDrawer.def_static("get_type_name_", (const char * (*)()) &AIS_ColoredDrawer::get_type_name, "None");
cls_AIS_ColoredDrawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColoredDrawer::get_type_descriptor, "None");
cls_AIS_ColoredDrawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::DynamicType, "None");
cls_AIS_ColoredDrawer.def("IsHidden", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::IsHidden, "None");
cls_AIS_ColoredDrawer.def("SetHidden", (void (AIS_ColoredDrawer::*)(const bool)) &AIS_ColoredDrawer::SetHidden, "None", py::arg("theToHide"));
cls_AIS_ColoredDrawer.def("HasOwnColor", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::HasOwnColor, "None");
cls_AIS_ColoredDrawer.def("UnsetOwnColor", (void (AIS_ColoredDrawer::*)()) &AIS_ColoredDrawer::UnsetOwnColor, "None");
cls_AIS_ColoredDrawer.def("SetOwnColor", (void (AIS_ColoredDrawer::*)(const Quantity_Color &)) &AIS_ColoredDrawer::SetOwnColor, "None", py::arg(""));
cls_AIS_ColoredDrawer.def("HasOwnTransparency", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::HasOwnTransparency, "None");
cls_AIS_ColoredDrawer.def("UnsetOwnTransparency", (void (AIS_ColoredDrawer::*)()) &AIS_ColoredDrawer::UnsetOwnTransparency, "None");
cls_AIS_ColoredDrawer.def("SetOwnTransparency", (void (AIS_ColoredDrawer::*)(Standard_Real)) &AIS_ColoredDrawer::SetOwnTransparency, "None", py::arg(""));
cls_AIS_ColoredDrawer.def("HasOwnWidth", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::HasOwnWidth, "None");
cls_AIS_ColoredDrawer.def("UnsetOwnWidth", (void (AIS_ColoredDrawer::*)()) &AIS_ColoredDrawer::UnsetOwnWidth, "None");
cls_AIS_ColoredDrawer.def("SetOwnWidth", (void (AIS_ColoredDrawer::*)(const Standard_Real)) &AIS_ColoredDrawer::SetOwnWidth, "None", py::arg(""));

// TYPEDEF: AIS_DATAMAPOFSHAPEDRAWER
bind_NCollection_DataMap<TopoDS_Shape, opencascade::handle<AIS_ColoredDrawer>, TopTools_ShapeMapHasher>(mod, "AIS_DataMapOfShapeDrawer", py::module_local(false));

// CLASS: AIS_SHAPE
py::class_<AIS_Shape, opencascade::handle<AIS_Shape>, AIS_InteractiveObject> cls_AIS_Shape(mod, "AIS_Shape", "A framework to manage presentation and selection of shapes. AIS_Shape is the interactive object which is used the most by applications. There are standard functions available which allow you to prepare selection operations on the constituent elements of shapes - vertices, edges, faces etc - in an open local context. The selection modes specific to 'Shape' type objects are referred to as Standard Activation Mode. These modes are only taken into account in open local context and only act on Interactive Objects which have redefined the virtual method AcceptShapeDecomposition so that it returns true. Several advanced functions are also available. These include functions to manage deviation angle and deviation coefficient - both HLR and non-HLR - of an inheriting shape class. These services allow you to select one type of shape interactive object for higher precision drawing. When you do this, the Prs3d_Drawer::IsOwn... functions corresponding to the above deviation angle and coefficient functions return true indicating that there is a local setting available for the specific object.");

// Constructors
cls_AIS_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("shap"));

// Methods
cls_AIS_Shape.def_static("get_type_name_", (const char * (*)()) &AIS_Shape::get_type_name, "None");
cls_AIS_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Shape::get_type_descriptor, "None");
cls_AIS_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Shape::*)() const) &AIS_Shape::DynamicType, "None");
cls_AIS_Shape.def("Signature", (Standard_Integer (AIS_Shape::*)() const) &AIS_Shape::Signature, "Returns index 0. This value refers to SHAPE from TopAbs_ShapeEnum");
cls_AIS_Shape.def("Type", (AIS_KindOfInteractive (AIS_Shape::*)() const) &AIS_Shape::Type, "Returns Object as the type of Interactive Object.");
cls_AIS_Shape.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_Shape::*)() const) &AIS_Shape::AcceptShapeDecomposition, "Returns true if the Interactive Object accepts shape decomposition.");
cls_AIS_Shape.def("AcceptDisplayMode", (Standard_Boolean (AIS_Shape::*)(const Standard_Integer) const) &AIS_Shape::AcceptDisplayMode, "Return true if specified display mode is supported.", py::arg("theMode"));
cls_AIS_Shape.def("Shape", (const TopoDS_Shape & (AIS_Shape::*)() const) &AIS_Shape::Shape, "Returns this shape object.");
cls_AIS_Shape.def("SetShape", (void (AIS_Shape::*)(const TopoDS_Shape &)) &AIS_Shape::SetShape, "Constructs an instance of the shape object theShape.", py::arg("theShape"));
cls_AIS_Shape.def("Set", (void (AIS_Shape::*)(const TopoDS_Shape &)) &AIS_Shape::Set, "Alias for ::SetShape().", py::arg("theShape"));
cls_AIS_Shape.def("SetOwnDeviationCoefficient", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnDeviationCoefficient, "Sets a local value for deviation coefficient for this specific shape.");
cls_AIS_Shape.def("SetOwnHLRDeviationCoefficient", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnHLRDeviationCoefficient, "Sets a local value for HLR deviation coefficient for this specific shape.");
cls_AIS_Shape.def("SetOwnDeviationAngle", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnDeviationAngle, "Sets a local value for deviation angle for this specific shape.");
cls_AIS_Shape.def("SetOwnHLRDeviationAngle", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnHLRDeviationAngle, "Sets a local value for HLR deviation angle for this specific shape.");
cls_AIS_Shape.def("SetOwnDeviationCoefficient", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnDeviationCoefficient, "Sets a local value for deviation coefficient for this specific shape.", py::arg("aCoefficient"));
cls_AIS_Shape.def("SetOwnHLRDeviationCoefficient", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnHLRDeviationCoefficient, "sets myOwnHLRDeviationCoefficient field in Prs3d_Drawer & recomputes presentation", py::arg("aCoefficient"));
cls_AIS_Shape.def("SetAngleAndDeviation", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetAngleAndDeviation, "this compute a new angle and Deviation from the value anAngle and set the values stored in myDrawer with these that become local to the shape", py::arg("anAngle"));
cls_AIS_Shape.def("UserAngle", (Standard_Real (AIS_Shape::*)() const) &AIS_Shape::UserAngle, "gives back the angle initial value put by the User.");
cls_AIS_Shape.def("SetOwnDeviationAngle", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnDeviationAngle, "sets myOwnDeviationAngle field in Prs3d_Drawer & recomputes presentation", py::arg("anAngle"));
cls_AIS_Shape.def("SetHLRAngleAndDeviation", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetHLRAngleAndDeviation, "this compute a new Angle and Deviation from the value anAngle for HLR and set the values stored in myDrawer for with these that become local to the shape", py::arg("anAngle"));
cls_AIS_Shape.def("SetOwnHLRDeviationAngle", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnHLRDeviationAngle, "sets myOwnHLRDeviationAngle field in Prs3d_Drawer & recomputes presentation", py::arg("anAngle"));
cls_AIS_Shape.def("OwnDeviationCoefficient", [](AIS_Shape &self, Standard_Real & aCoefficient, Standard_Real & aPreviousCoefficient){ Standard_Boolean rv = self.OwnDeviationCoefficient(aCoefficient, aPreviousCoefficient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, aCoefficient, aPreviousCoefficient); }, "Returns true and the values of the deviation coefficient aCoefficient and the previous deviation coefficient aPreviousCoefficient. If these values are not already set, false is returned.", py::arg("aCoefficient"), py::arg("aPreviousCoefficient"));
cls_AIS_Shape.def("OwnHLRDeviationCoefficient", [](AIS_Shape &self, Standard_Real & aCoefficient, Standard_Real & aPreviousCoefficient){ Standard_Boolean rv = self.OwnHLRDeviationCoefficient(aCoefficient, aPreviousCoefficient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, aCoefficient, aPreviousCoefficient); }, "Returns true and the values of the HLR deviation coefficient aCoefficient and the previous HLR deviation coefficient aPreviousCoefficient. If these values are not already set, false is returned.", py::arg("aCoefficient"), py::arg("aPreviousCoefficient"));
cls_AIS_Shape.def("OwnDeviationAngle", [](AIS_Shape &self, Standard_Real & anAngle, Standard_Real & aPreviousAngle){ Standard_Boolean rv = self.OwnDeviationAngle(anAngle, aPreviousAngle); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, anAngle, aPreviousAngle); }, "Returns true and the values of the deviation angle anAngle and the previous deviation angle aPreviousAngle. If these values are not already set, false is returned.", py::arg("anAngle"), py::arg("aPreviousAngle"));
cls_AIS_Shape.def("OwnHLRDeviationAngle", [](AIS_Shape &self, Standard_Real & anAngle, Standard_Real & aPreviousAngle){ Standard_Boolean rv = self.OwnHLRDeviationAngle(anAngle, aPreviousAngle); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, anAngle, aPreviousAngle); }, "Returns true and the values of the HLR deviation angle anAngle and of the previous HLR deviation angle aPreviousAngle. If these values are not already set, false is returned.", py::arg("anAngle"), py::arg("aPreviousAngle"));
cls_AIS_Shape.def("SetTypeOfHLR", (void (AIS_Shape::*)(const Prs3d_TypeOfHLR)) &AIS_Shape::SetTypeOfHLR, "Sets the type of HLR algorithm used by the shape", py::arg("theTypeOfHLR"));
cls_AIS_Shape.def("TypeOfHLR", (Prs3d_TypeOfHLR (AIS_Shape::*)() const) &AIS_Shape::TypeOfHLR, "Gets the type of HLR algorithm");
cls_AIS_Shape.def("SetColor", (void (AIS_Shape::*)(const Quantity_Color &)) &AIS_Shape::SetColor, "Sets the color aColor in the reconstructed compound shape. Acts via the Drawer methods below on the appearance of: - free boundaries: Prs3d_Drawer_FreeBoundaryAspect, - isos: Prs3d_Drawer_UIsoAspect, Prs3dDrawer_VIsoAspect, - shared boundaries: Prs3d_Drawer_UnFreeBoundaryAspect, - shading: Prs3d_Drawer_ShadingAspect, - visible line color in hidden line mode: Prs3d_Drawer_SeenLineAspect - hidden line color in hidden line mode: Prs3d_Drawer_HiddenLineAspect.", py::arg("theColor"));
cls_AIS_Shape.def("UnsetColor", (void (AIS_Shape::*)()) &AIS_Shape::UnsetColor, "Removes settings for color in the reconstructed compound shape.");
cls_AIS_Shape.def("SetWidth", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetWidth, "Sets the value aValue for line width in the reconstructed compound shape. Changes line aspects for lines presentation.", py::arg("aValue"));
cls_AIS_Shape.def("UnsetWidth", (void (AIS_Shape::*)()) &AIS_Shape::UnsetWidth, "Removes the setting for line width in the reconstructed compound shape.");
cls_AIS_Shape.def("SetMaterial", (void (AIS_Shape::*)(const Graphic3d_MaterialAspect &)) &AIS_Shape::SetMaterial, "Allows you to provide settings for the material aName in the reconstructed compound shape.", py::arg("aName"));
cls_AIS_Shape.def("UnsetMaterial", (void (AIS_Shape::*)()) &AIS_Shape::UnsetMaterial, "Removes settings for material in the reconstructed compound shape.");
cls_AIS_Shape.def("SetTransparency", [](AIS_Shape &self) -> void { return self.SetTransparency(); });
cls_AIS_Shape.def("SetTransparency", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetTransparency, "Sets the value aValue for transparency in the reconstructed compound shape.", py::arg("aValue"));
cls_AIS_Shape.def("UnsetTransparency", (void (AIS_Shape::*)()) &AIS_Shape::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");
cls_AIS_Shape.def("BoundingBox", (const Bnd_Box & (AIS_Shape::*)()) &AIS_Shape::BoundingBox, "Constructs a bounding box with which to reconstruct compound topological shapes for presentation.");
cls_AIS_Shape.def("Color", (void (AIS_Shape::*)(Quantity_Color &) const) &AIS_Shape::Color, "Returns the Color attributes of the shape accordingly to the current facing model;", py::arg("aColor"));
cls_AIS_Shape.def("Material", (Graphic3d_NameOfMaterial (AIS_Shape::*)() const) &AIS_Shape::Material, "Returns the NameOfMaterial attributes of the shape accordingly to the current facing model;");
cls_AIS_Shape.def("Transparency", (Standard_Real (AIS_Shape::*)() const) &AIS_Shape::Transparency, "Returns the transparency attributes of the shape accordingly to the current facing model;");
cls_AIS_Shape.def_static("SelectionType_", (TopAbs_ShapeEnum (*)(const Standard_Integer)) &AIS_Shape::SelectionType, "Return shape type for specified selection mode.", py::arg("theSelMode"));
cls_AIS_Shape.def_static("SelectionMode_", (Standard_Integer (*)(const TopAbs_ShapeEnum)) &AIS_Shape::SelectionMode, "Return selection mode for specified shape type.", py::arg("theShapeType"));
cls_AIS_Shape.def("TextureRepeatUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureRepeatUV, "Return texture repeat UV values; (1, 1) by default.");
cls_AIS_Shape.def("SetTextureRepeatUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureRepeatUV, "Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1). Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax).", py::arg("theRepeatUV"));
cls_AIS_Shape.def("TextureOriginUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureOriginUV, "Return texture origin UV position; (0, 0) by default.");
cls_AIS_Shape.def("SetTextureOriginUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureOriginUV, "Use this method to change the origin of the texture. The texel (0,0) will be mapped to the surface (myUVOrigin.X(), myUVOrigin.Y()).", py::arg("theOriginUV"));
cls_AIS_Shape.def("TextureScaleUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureScaleUV, "Return scale factor for UV coordinates; (1, 1) by default.");
cls_AIS_Shape.def("SetTextureScaleUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureScaleUV, "Use this method to scale the texture (percent of the face). You can specify a scale factor for both U and V. Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat, the texture will appear twice on the face in each direction.", py::arg("theScaleUV"));
cls_AIS_Shape.def_static("computeHlrPresentation_", (void (*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &AIS_Shape::computeHlrPresentation, "Compute HLR presentation for specified shape.", py::arg("theProjector"), py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));

// CLASS: AIS_COLOREDSHAPE
py::class_<AIS_ColoredShape, opencascade::handle<AIS_ColoredShape>, AIS_Shape> cls_AIS_ColoredShape(mod, "AIS_ColoredShape", "Presentation of the shape with customizable sub-shapes properties.");

// Constructors
cls_AIS_ColoredShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_AIS_ColoredShape.def(py::init<const opencascade::handle<AIS_Shape> &>(), py::arg("theShape"));

// Methods
cls_AIS_ColoredShape.def("CustomAspects", (opencascade::handle<AIS_ColoredDrawer> (AIS_ColoredShape::*)(const TopoDS_Shape &)) &AIS_ColoredShape::CustomAspects, "Customize properties of specified sub-shape. The shape will be stored in the map but ignored, if it is not sub-shape of main Shape! This method can be used to mark sub-shapes with customizable properties.", py::arg("theShape"));
cls_AIS_ColoredShape.def("ClearCustomAspects", (void (AIS_ColoredShape::*)()) &AIS_ColoredShape::ClearCustomAspects, "Reset the map of custom sub-shape aspects.");
cls_AIS_ColoredShape.def("UnsetCustomAspects", [](AIS_ColoredShape &self, const TopoDS_Shape & a0) -> void { return self.UnsetCustomAspects(a0); });
cls_AIS_ColoredShape.def("UnsetCustomAspects", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Standard_Boolean)) &AIS_ColoredShape::UnsetCustomAspects, "Reset custom properties of specified sub-shape.", py::arg("theShape"), py::arg("theToUnregister"));
cls_AIS_ColoredShape.def("SetCustomColor", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Quantity_Color &)) &AIS_ColoredShape::SetCustomColor, "Customize color of specified sub-shape", py::arg("theShape"), py::arg("theColor"));
cls_AIS_ColoredShape.def("SetCustomTransparency", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, Standard_Real)) &AIS_ColoredShape::SetCustomTransparency, "Customize transparency of specified sub-shape", py::arg("theShape"), py::arg("theTransparency"));
cls_AIS_ColoredShape.def("SetCustomWidth", (void (AIS_ColoredShape::*)(const TopoDS_Shape &, const Standard_Real)) &AIS_ColoredShape::SetCustomWidth, "Customize line width of specified sub-shape", py::arg("theShape"), py::arg("theLineWidth"));
cls_AIS_ColoredShape.def("CustomAspectsMap", (const AIS_DataMapOfShapeDrawer & (AIS_ColoredShape::*)() const) &AIS_ColoredShape::CustomAspectsMap, "Return the map of custom aspects.");
cls_AIS_ColoredShape.def("ChangeCustomAspectsMap", (AIS_DataMapOfShapeDrawer & (AIS_ColoredShape::*)()) &AIS_ColoredShape::ChangeCustomAspectsMap, "Return the map of custom aspects.");
cls_AIS_ColoredShape.def("SetColor", (void (AIS_ColoredShape::*)(const Quantity_Color &)) &AIS_ColoredShape::SetColor, "Setup color of entire shape.", py::arg("theColor"));
cls_AIS_ColoredShape.def("SetWidth", (void (AIS_ColoredShape::*)(const Standard_Real)) &AIS_ColoredShape::SetWidth, "Setup line width of entire shape.", py::arg("theLineWidth"));
cls_AIS_ColoredShape.def("SetTransparency", (void (AIS_ColoredShape::*)(const Standard_Real)) &AIS_ColoredShape::SetTransparency, "Sets transparency value.", py::arg("theValue"));
cls_AIS_ColoredShape.def("SetMaterial", (void (AIS_ColoredShape::*)(const Graphic3d_MaterialAspect &)) &AIS_ColoredShape::SetMaterial, "Sets the material aspect.", py::arg("theAspect"));
cls_AIS_ColoredShape.def("UnsetTransparency", (void (AIS_ColoredShape::*)()) &AIS_ColoredShape::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");
cls_AIS_ColoredShape.def("UnsetWidth", (void (AIS_ColoredShape::*)()) &AIS_ColoredShape::UnsetWidth, "Setup line width of entire shape.");
cls_AIS_ColoredShape.def_static("get_type_name_", (const char * (*)()) &AIS_ColoredShape::get_type_name, "None");
cls_AIS_ColoredShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColoredShape::get_type_descriptor, "None");
cls_AIS_ColoredShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColoredShape::*)() const) &AIS_ColoredShape::DynamicType, "None");

// CLASS: AIS_COLORSCALE
py::class_<AIS_ColorScale, opencascade::handle<AIS_ColorScale>, AIS_InteractiveObject> cls_AIS_ColorScale(mod, "AIS_ColorScale", "Class for drawing a custom color scale.");

// Constructors
cls_AIS_ColorScale.def(py::init<>());

// Methods
cls_AIS_ColorScale.def_static("get_type_name_", (const char * (*)()) &AIS_ColorScale::get_type_name, "None");
cls_AIS_ColorScale.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColorScale::get_type_descriptor, "None");
cls_AIS_ColorScale.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColorScale::*)() const) &AIS_ColorScale::DynamicType, "None");
cls_AIS_ColorScale.def_static("FindColor_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Graphic3d_Vec3d &, const Graphic3d_Vec3d &, Quantity_Color &)) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theMin"), py::arg("theMax"), py::arg("theColorsCount"), py::arg("theColorHlsMin"), py::arg("theColorHlsMax"), py::arg("theColor"));
cls_AIS_ColorScale.def_static("FindColor_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, Quantity_Color &)) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theMin"), py::arg("theMax"), py::arg("theColorsCount"), py::arg("theColor"));
cls_AIS_ColorScale.def_static("hueToValidRange_", (Standard_Real (*)(const Standard_Real)) &AIS_ColorScale::hueToValidRange, "Shift hue into valid range. Lightness and Saturation should be specified in valid range [0.0, 1.0], however Hue might be given out of Quantity_Color range to specify desired range for interpolation.", py::arg("theHue"));
cls_AIS_ColorScale.def("FindColor", (Standard_Boolean (AIS_ColorScale::*)(const Standard_Real, Quantity_Color &) const) &AIS_ColorScale::FindColor, "Calculate color according passed value; returns true if value is in range or false, if isn't", py::arg("theValue"), py::arg("theColor"));
cls_AIS_ColorScale.def("GetMin", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::GetMin, "Returns minimal value of color scale, 0.0 by default.");
cls_AIS_ColorScale.def("SetMin", (void (AIS_ColorScale::*)(const Standard_Real)) &AIS_ColorScale::SetMin, "Sets the minimal value of color scale.", py::arg("theMin"));
cls_AIS_ColorScale.def("GetMax", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::GetMax, "Returns maximal value of color scale, 1.0 by default.");
cls_AIS_ColorScale.def("SetMax", (void (AIS_ColorScale::*)(const Standard_Real)) &AIS_ColorScale::SetMax, "Sets the maximal value of color scale.", py::arg("theMax"));
cls_AIS_ColorScale.def("GetRange", [](AIS_ColorScale &self, Standard_Real & theMin, Standard_Real & theMax){ self.GetRange(theMin, theMax); return std::tuple<Standard_Real &, Standard_Real &>(theMin, theMax); }, "Returns minimal and maximal values of color scale, 0.0 to 1.0 by default.", py::arg("theMin"), py::arg("theMax"));
cls_AIS_ColorScale.def("SetRange", (void (AIS_ColorScale::*)(const Standard_Real, const Standard_Real)) &AIS_ColorScale::SetRange, "Sets the minimal and maximal value of color scale. Note that values order will be ignored - the minimum and maximum values will be swapped if needed. ::SetReversed() should be called to swap displaying order.", py::arg("theMin"), py::arg("theMax"));
cls_AIS_ColorScale.def("HueMin", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::HueMin, "Returns the hue angle corresponding to minimum value, 230 by default (blue).");
cls_AIS_ColorScale.def("HueMax", (Standard_Real (AIS_ColorScale::*)() const) &AIS_ColorScale::HueMax, "Returns the hue angle corresponding to maximum value, 0 by default (red).");
cls_AIS_ColorScale.def("HueRange", [](AIS_ColorScale &self, Standard_Real & theMinAngle, Standard_Real & theMaxAngle){ self.HueRange(theMinAngle, theMaxAngle); return std::tuple<Standard_Real &, Standard_Real &>(theMinAngle, theMaxAngle); }, "Returns the hue angle range corresponding to minimum and maximum values, 230 to 0 by default (blue to red).", py::arg("theMinAngle"), py::arg("theMaxAngle"));
cls_AIS_ColorScale.def("SetHueRange", (void (AIS_ColorScale::*)(const Standard_Real, const Standard_Real)) &AIS_ColorScale::SetHueRange, "Sets hue angle range corresponding to minimum and maximum values. The valid angle range is [0, 360], see Quantity_Color and Quantity_TOC_HLS for more details.", py::arg("theMinAngle"), py::arg("theMaxAngle"));
cls_AIS_ColorScale.def("ColorRange", (void (AIS_ColorScale::*)(Quantity_Color &, Quantity_Color &) const) &AIS_ColorScale::ColorRange, "Returns color range corresponding to minimum and maximum values, blue to red by default.", py::arg("theMinColor"), py::arg("theMaxColor"));
cls_AIS_ColorScale.def("SetColorRange", (void (AIS_ColorScale::*)(const Quantity_Color &, const Quantity_Color &)) &AIS_ColorScale::SetColorRange, "Sets color range corresponding to minimum and maximum values.", py::arg("theMinColor"), py::arg("theMaxColor"));
cls_AIS_ColorScale.def("GetLabelType", (Aspect_TypeOfColorScaleData (AIS_ColorScale::*)() const) &AIS_ColorScale::GetLabelType, "Returns the type of labels, Aspect_TOCSD_AUTO by default. Aspect_TOCSD_AUTO - labels as boundary values for intervals Aspect_TOCSD_USER - user specified label is used");
cls_AIS_ColorScale.def("SetLabelType", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScaleData)) &AIS_ColorScale::SetLabelType, "Sets the type of labels. Aspect_TOCSD_AUTO - labels as boundary values for intervals Aspect_TOCSD_USER - user specified label is used", py::arg("theType"));
cls_AIS_ColorScale.def("GetColorType", (Aspect_TypeOfColorScaleData (AIS_ColorScale::*)() const) &AIS_ColorScale::GetColorType, "Returns the type of colors, Aspect_TOCSD_AUTO by default. Aspect_TOCSD_AUTO - value between Red and Blue Aspect_TOCSD_USER - user specified color from color map");
cls_AIS_ColorScale.def("SetColorType", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScaleData)) &AIS_ColorScale::SetColorType, "Sets the type of colors. Aspect_TOCSD_AUTO - value between Red and Blue Aspect_TOCSD_USER - user specified color from color map", py::arg("theType"));
cls_AIS_ColorScale.def("GetNumberOfIntervals", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetNumberOfIntervals, "Returns the number of color scale intervals, 10 by default.");
cls_AIS_ColorScale.def("SetNumberOfIntervals", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetNumberOfIntervals, "Sets the number of color scale intervals.", py::arg("theNum"));
cls_AIS_ColorScale.def("GetTitle", (const TCollection_ExtendedString & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTitle, "Returns the color scale title string, empty string by default.");
cls_AIS_ColorScale.def("SetTitle", (void (AIS_ColorScale::*)(const TCollection_ExtendedString &)) &AIS_ColorScale::SetTitle, "Sets the color scale title string.", py::arg("theTitle"));
cls_AIS_ColorScale.def("GetFormat", (const TCollection_AsciiString & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetFormat, "Returns the format for numbers, '%.4g' by default. The same like format for function printf(). Used if GetLabelType() is TOCSD_AUTO;");
cls_AIS_ColorScale.def("Format", (const TCollection_AsciiString & (AIS_ColorScale::*)() const) &AIS_ColorScale::Format, "Returns the format of text.");
cls_AIS_ColorScale.def("SetFormat", (void (AIS_ColorScale::*)(const TCollection_AsciiString &)) &AIS_ColorScale::SetFormat, "Sets the color scale auto label format specification.", py::arg("theFormat"));
cls_AIS_ColorScale.def("GetLabel", (TCollection_ExtendedString (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::GetLabel, "Returns the user specified label with index theIndex. Index is in range from 1 to GetNumberOfIntervals() or to GetNumberOfIntervals() + 1 if IsLabelAtBorder() is true. Returns empty string if label not defined.", py::arg("theIndex"));
cls_AIS_ColorScale.def("GetIntervalColor", (Quantity_Color (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::GetIntervalColor, "Returns the user specified color from color map with index (starts at 1). Returns default color if index is out of range in color map.", py::arg("theIndex"));
cls_AIS_ColorScale.def("SetIntervalColor", (void (AIS_ColorScale::*)(const Quantity_Color &, const Standard_Integer)) &AIS_ColorScale::SetIntervalColor, "Sets the color of the specified interval. Note that list is automatically resized to include specified index.", py::arg("theColor"), py::arg("theIndex"));
cls_AIS_ColorScale.def("GetLabels", (void (AIS_ColorScale::*)(TColStd_SequenceOfExtendedString &) const) &AIS_ColorScale::GetLabels, "Returns the user specified labels.", py::arg("theLabels"));
cls_AIS_ColorScale.def("Labels", (const TColStd_SequenceOfExtendedString & (AIS_ColorScale::*)() const) &AIS_ColorScale::Labels, "Returns the user specified labels.");
cls_AIS_ColorScale.def("SetLabels", (void (AIS_ColorScale::*)(const TColStd_SequenceOfExtendedString &)) &AIS_ColorScale::SetLabels, "Sets the color scale labels. The length of the sequence should be equal to GetNumberOfIntervals() or to GetNumberOfIntervals() + 1 if IsLabelAtBorder() is true. If length of the sequence does not much the number of intervals, then these labels will be considered as 'free' and will be located at the virtual intervals corresponding to the number of labels (with flag IsLabelAtBorder() having the same effect as in normal case).", py::arg("theSeq"));
cls_AIS_ColorScale.def("GetColors", (void (AIS_ColorScale::*)(Aspect_SequenceOfColor &) const) &AIS_ColorScale::GetColors, "Returns the user specified colors.", py::arg("theColors"));
cls_AIS_ColorScale.def("GetColors", (const Aspect_SequenceOfColor & (AIS_ColorScale::*)() const) &AIS_ColorScale::GetColors, "Returns the user specified colors.");
cls_AIS_ColorScale.def("SetColors", (void (AIS_ColorScale::*)(const Aspect_SequenceOfColor &)) &AIS_ColorScale::SetColors, "Sets the color scale colors. The length of the sequence should be equal to GetNumberOfIntervals().", py::arg("theSeq"));
cls_AIS_ColorScale.def("GetLabelPosition", (Aspect_TypeOfColorScalePosition (AIS_ColorScale::*)() const) &AIS_ColorScale::GetLabelPosition, "Returns the position of labels concerning color filled rectangles, Aspect_TOCSP_RIGHT by default.");
cls_AIS_ColorScale.def("SetLabelPosition", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScalePosition)) &AIS_ColorScale::SetLabelPosition, "Sets the color scale labels position relative to color bar.", py::arg("thePos"));
cls_AIS_ColorScale.def("GetTitlePosition", (Aspect_TypeOfColorScalePosition (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTitlePosition, "Returns the position of color scale title, Aspect_TOCSP_LEFT by default.");
cls_AIS_ColorScale.def("SetTitlePosition", (void (AIS_ColorScale::*)(const Aspect_TypeOfColorScalePosition)) &AIS_ColorScale::SetTitlePosition, "Sets the color scale title position.", py::arg("thePos"));
cls_AIS_ColorScale.def("IsReversed", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsReversed, "Returns TRUE if the labels and colors used in reversed order, FALSE by default. - Normal, bottom-up order with Minimal value on the Bottom and Maximum value on Top. - Reversed, top-down order with Maximum value on the Bottom and Minimum value on Top.");
cls_AIS_ColorScale.def("SetReversed", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetReversed, "Sets true if the labels and colors used in reversed order.", py::arg("theReverse"));
cls_AIS_ColorScale.def("IsSmoothTransition", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsSmoothTransition, "Return TRUE if color transition between neighbor intervals should be linearly interpolated, FALSE by default.");
cls_AIS_ColorScale.def("SetSmoothTransition", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetSmoothTransition, "Setup smooth color transition.", py::arg("theIsSmooth"));
cls_AIS_ColorScale.def("IsLabelAtBorder", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsLabelAtBorder, "Returns TRUE if the labels are placed at border of color intervals, TRUE by default. The automatically generated label will show value exactly on the current position: - value connecting two neighbor intervals (TRUE) - value in the middle of interval (FALSE)");
cls_AIS_ColorScale.def("SetLabelAtBorder", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetLabelAtBorder, "Sets true if the labels are placed at border of color intervals (TRUE by default). If set to False, labels will be drawn at color intervals rather than at borders.", py::arg("theOn"));
cls_AIS_ColorScale.def("IsLogarithmic", (Standard_Boolean (AIS_ColorScale::*)() const) &AIS_ColorScale::IsLogarithmic, "Returns TRUE if the color scale has logarithmic intervals, FALSE by default.");
cls_AIS_ColorScale.def("SetLogarithmic", (void (AIS_ColorScale::*)(const Standard_Boolean)) &AIS_ColorScale::SetLogarithmic, "Sets true if the color scale has logarithmic intervals.", py::arg("isLogarithmic"));
cls_AIS_ColorScale.def("SetLabel", (void (AIS_ColorScale::*)(const TCollection_ExtendedString &, const Standard_Integer)) &AIS_ColorScale::SetLabel, "Sets the color scale label at index. Note that list is automatically resized to include specified index.", py::arg("theLabel"), py::arg("theIndex"));
cls_AIS_ColorScale.def("GetSize", [](AIS_ColorScale &self, Standard_Integer & theBreadth, Standard_Integer & theHeight){ self.GetSize(theBreadth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theBreadth, theHeight); }, "Returns the size of color bar, 0 and 0 by default (e.g. should be set by user explicitly before displaying).", py::arg("theBreadth"), py::arg("theHeight"));
cls_AIS_ColorScale.def("SetSize", (void (AIS_ColorScale::*)(const Standard_Integer, const Standard_Integer)) &AIS_ColorScale::SetSize, "Sets the size of color bar.", py::arg("theBreadth"), py::arg("theHeight"));
cls_AIS_ColorScale.def("GetBreadth", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetBreadth, "Returns the breadth of color bar, 0 by default (e.g. should be set by user explicitly before displaying).");
cls_AIS_ColorScale.def("SetBreadth", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetBreadth, "Sets the width of color bar.", py::arg("theBreadth"));
cls_AIS_ColorScale.def("GetHeight", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetHeight, "Returns the height of color bar, 0 by default (e.g. should be set by user explicitly before displaying).");
cls_AIS_ColorScale.def("SetHeight", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetHeight, "Sets the height of color bar.", py::arg("theHeight"));
cls_AIS_ColorScale.def("GetPosition", [](AIS_ColorScale &self, Standard_Real & theX, Standard_Real & theY){ self.GetPosition(theX, theY); return std::tuple<Standard_Real &, Standard_Real &>(theX, theY); }, "Returns the bottom-left position of color scale, 0x0 by default.", py::arg("theX"), py::arg("theY"));
cls_AIS_ColorScale.def("SetPosition", (void (AIS_ColorScale::*)(const Standard_Integer, const Standard_Integer)) &AIS_ColorScale::SetPosition, "Sets the position of color scale.", py::arg("theX"), py::arg("theY"));
cls_AIS_ColorScale.def("GetXPosition", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetXPosition, "Returns the left position of color scale, 0 by default.");
cls_AIS_ColorScale.def("SetXPosition", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetXPosition, "Sets the left position of color scale.", py::arg("theX"));
cls_AIS_ColorScale.def("GetYPosition", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetYPosition, "Returns the bottom position of color scale, 0 by default.");
cls_AIS_ColorScale.def("SetYPosition", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetYPosition, "Sets the bottom position of color scale.", py::arg("theY"));
cls_AIS_ColorScale.def("GetTextHeight", (Standard_Integer (AIS_ColorScale::*)() const) &AIS_ColorScale::GetTextHeight, "Returns the font height of text labels, 20 by default.");
cls_AIS_ColorScale.def("SetTextHeight", (void (AIS_ColorScale::*)(const Standard_Integer)) &AIS_ColorScale::SetTextHeight, "Sets the height of text of color scale.", py::arg("theHeight"));
cls_AIS_ColorScale.def("TextWidth", (Standard_Integer (AIS_ColorScale::*)(const TCollection_ExtendedString &) const) &AIS_ColorScale::TextWidth, "Returns the width of text.", py::arg("theText"));
cls_AIS_ColorScale.def("TextHeight", (Standard_Integer (AIS_ColorScale::*)(const TCollection_ExtendedString &) const) &AIS_ColorScale::TextHeight, "Returns the height of text.", py::arg("theText"));
cls_AIS_ColorScale.def("TextSize", [](AIS_ColorScale &self, const TCollection_ExtendedString & theText, const Standard_Integer theHeight, Standard_Integer & theWidth, Standard_Integer & theAscent, Standard_Integer & theDescent){ self.TextSize(theText, theHeight, theWidth, theAscent, theDescent); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theAscent, theDescent); }, "None", py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_AIS_ColorScale.def("AcceptDisplayMode", (Standard_Boolean (AIS_ColorScale::*)(const Standard_Integer) const) &AIS_ColorScale::AcceptDisplayMode, "Return true if specified display mode is supported.", py::arg("theMode"));
cls_AIS_ColorScale.def("Compute", (void (AIS_ColorScale::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &AIS_ColorScale::Compute, "Compute presentation.", py::arg("thePresentationManager"), py::arg("thePresentation"), py::arg("theMode"));
cls_AIS_ColorScale.def("ComputeSelection", (void (AIS_ColorScale::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_ColorScale::ComputeSelection, "Compute selection - not implemented for color scale.", py::arg(""), py::arg(""));

// CLASS: AIS_CONCENTRICRELATION
py::class_<AIS_ConcentricRelation, opencascade::handle<AIS_ConcentricRelation>, AIS_Relation> cls_AIS_ConcentricRelation(mod, "AIS_ConcentricRelation", "A framework to define a constraint by a relation of concentricity between two or more interactive datums. The display of this constraint is also defined. A plane is used to create an axis along which the relation of concentricity can be extended.");

// Constructors
cls_AIS_ConcentricRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"));

// Methods
cls_AIS_ConcentricRelation.def_static("get_type_name_", (const char * (*)()) &AIS_ConcentricRelation::get_type_name, "None");
cls_AIS_ConcentricRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ConcentricRelation::get_type_descriptor, "None");
cls_AIS_ConcentricRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ConcentricRelation::*)() const) &AIS_ConcentricRelation::DynamicType, "None");
cls_AIS_ConcentricRelation.def("Compute", (void (AIS_ConcentricRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_ConcentricRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_CONNECTEDINTERACTIVE
py::class_<AIS_ConnectedInteractive, opencascade::handle<AIS_ConnectedInteractive>, AIS_InteractiveObject> cls_AIS_ConnectedInteractive(mod, "AIS_ConnectedInteractive", "Creates an arbitrary located instance of another Interactive Object, which serves as a reference. This allows you to use the Connected Interactive Object without having to recalculate presentation, selection or graphic structure. These are deduced from your reference object. The relation between the connected interactive object and its source is generally one of geometric transformation. AIS_ConnectedInteractive class supports selection mode 0 for any InteractiveObject and all standard modes if its reference based on AIS_Shape. Descendants may redefine ComputeSelection() though. Also ConnectedInteractive will handle HLR if its reference based on AIS_Shape.");

// Constructors
cls_AIS_ConnectedInteractive.def(py::init<>());
cls_AIS_ConnectedInteractive.def(py::init<const PrsMgr_TypeOfPresentation3d>(), py::arg("aTypeOfPresentation3d"));

// Methods
cls_AIS_ConnectedInteractive.def_static("get_type_name_", (const char * (*)()) &AIS_ConnectedInteractive::get_type_name, "None");
cls_AIS_ConnectedInteractive.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ConnectedInteractive::get_type_descriptor, "None");
cls_AIS_ConnectedInteractive.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::DynamicType, "None");
cls_AIS_ConnectedInteractive.def("Type", (AIS_KindOfInteractive (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::Type, "Returns KOI_Object");
cls_AIS_ConnectedInteractive.def("Signature", (Standard_Integer (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::Signature, "Returns 0");
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference.", py::arg("theAnotherObj"));
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference. Locates instance in aLocation.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_ConnectedInteractive.def("Connect", (void (AIS_ConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Geom_Transformation> &)) &AIS_ConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, anotherIobj, and its reference. Locates instance in aLocation.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_ConnectedInteractive.def("HasConnection", (Standard_Boolean (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::HasConnection, "Returns true if there is a connection established between the presentation and its source reference.");
cls_AIS_ConnectedInteractive.def("ConnectedTo", (const opencascade::handle<AIS_InteractiveObject> & (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::ConnectedTo, "Returns the connection with the reference Interactive Object.");
cls_AIS_ConnectedInteractive.def("Disconnect", (void (AIS_ConnectedInteractive::*)()) &AIS_ConnectedInteractive::Disconnect, "Clears the connection with a source reference. The presentation will no longer be displayed. Warning Must be done before deleting the presentation.");
cls_AIS_ConnectedInteractive.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_ConnectedInteractive::*)() const) &AIS_ConnectedInteractive::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.");
cls_AIS_ConnectedInteractive.def("AcceptDisplayMode", (Standard_Boolean (AIS_ConnectedInteractive::*)(const Standard_Integer) const) &AIS_ConnectedInteractive::AcceptDisplayMode, "Return true if reference presentation accepts specified display mode.", py::arg("theMode"));

// TYPEDEF: AIS_DATAMAPOFINTEGERLISTOFINTERACTIVE
bind_NCollection_DataMap<int, NCollection_List<opencascade::handle<AIS_InteractiveObject> >, NCollection_DefaultHasher<int> >(mod, "AIS_DataMapofIntegerListOfinteractive", py::module_local(false));

// TYPEDEF: AIS_DATAMAPITERATOROFDATAMAPOFINTEGERLISTOFINTERACTIVE

// CLASS: AIS_DIAMETERDIMENSION
py::class_<AIS_DiameterDimension, opencascade::handle<AIS_DiameterDimension>, AIS_Dimension> cls_AIS_DiameterDimension(mod, "AIS_DiameterDimension", "Diameter dimension. Can be constructued: - On generic circle. - On generic circle with user-defined anchor point on that circle (dimension plane is oriented to follow the anchor point). - On generic circle in the specified plane. - On generic shape containing geometry that can be measured by diameter dimension: circle wire, circular face, etc. The anchor point is the location of the left attachement point of dimension on the circle. The anchor point computation is processed after dimension plane setting so that positive flyout direction stands with normal of the circle and the normal of the plane. If the plane is user-defined the anchor point was computed as intersection of the plane and the basis circle. Among two intersection points the one is selected so that positive flyout direction vector and the circle normal on the one side form the circle plane. (corner between positive flyout directio nand the circle normal is acute.) If the plane is computed automatically (by default it is the circle plane), the anchor point is the zero parameter point of the circle.");

// Constructors
cls_AIS_DiameterDimension.def(py::init<const gp_Circ &>(), py::arg("theCircle"));
cls_AIS_DiameterDimension.def(py::init<const gp_Circ &, const gp_Pln &>(), py::arg("theCircle"), py::arg("thePlane"));
cls_AIS_DiameterDimension.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
cls_AIS_DiameterDimension.def(py::init<const TopoDS_Shape &, const gp_Pln &>(), py::arg("theShape"), py::arg("thePlane"));

// Methods
cls_AIS_DiameterDimension.def("Circle", (const gp_Circ & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::Circle, "Returns measured geometry circle.");
cls_AIS_DiameterDimension.def("AnchorPoint", (gp_Pnt (AIS_DiameterDimension::*)()) &AIS_DiameterDimension::AnchorPoint, "Returns anchor point on circle for diameter dimension.");
cls_AIS_DiameterDimension.def("Shape", (const TopoDS_Shape & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::Shape, "Returns the measured shape.");
cls_AIS_DiameterDimension.def("SetMeasuredGeometry", (void (AIS_DiameterDimension::*)(const gp_Circ &)) &AIS_DiameterDimension::SetMeasuredGeometry, "Measure diameter of the circle. The actual dimension plane is used for determining anchor points on the circle to attach the dimension lines to. The dimension will become invalid if the diameter of the circle is less than Precision::Confusion().", py::arg("theCircle"));
cls_AIS_DiameterDimension.def("SetMeasuredGeometry", (void (AIS_DiameterDimension::*)(const TopoDS_Shape &)) &AIS_DiameterDimension::SetMeasuredGeometry, "Measure diameter on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"));
cls_AIS_DiameterDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_DiameterDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_DiameterDimension.def("SetDisplayUnits", (void (AIS_DiameterDimension::*)(const TCollection_AsciiString &)) &AIS_DiameterDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_DiameterDimension.def("SetModelUnits", (void (AIS_DiameterDimension::*)(const TCollection_AsciiString &)) &AIS_DiameterDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_DiameterDimension.def("SetTextPosition", (void (AIS_DiameterDimension::*)(const gp_Pnt &)) &AIS_DiameterDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_DiameterDimension.def("GetTextPosition", (const gp_Pnt (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::GetTextPosition, "None");
cls_AIS_DiameterDimension.def_static("get_type_name_", (const char * (*)()) &AIS_DiameterDimension::get_type_name, "None");
cls_AIS_DiameterDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_DiameterDimension::get_type_descriptor, "None");
cls_AIS_DiameterDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_DiameterDimension::*)() const) &AIS_DiameterDimension::DynamicType, "None");

// CLASS: AIS_ELLIPSERADIUSDIMENSION
py::class_<AIS_EllipseRadiusDimension, opencascade::handle<AIS_EllipseRadiusDimension>, AIS_Relation> cls_AIS_EllipseRadiusDimension(mod, "AIS_EllipseRadiusDimension", "Computes geometry ( basis curve and plane of dimension) for input shape aShape from TopoDS Root class for MinRadiusDimension and MaxRadiusDimension");

// Methods
cls_AIS_EllipseRadiusDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::KindOfDimension, "None");
cls_AIS_EllipseRadiusDimension.def("IsMovable", (Standard_Boolean (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::IsMovable, "None");
cls_AIS_EllipseRadiusDimension.def("ComputeGeometry", (void (AIS_EllipseRadiusDimension::*)()) &AIS_EllipseRadiusDimension::ComputeGeometry, "None");
cls_AIS_EllipseRadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_EllipseRadiusDimension::get_type_name, "None");
cls_AIS_EllipseRadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EllipseRadiusDimension::get_type_descriptor, "None");
cls_AIS_EllipseRadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EllipseRadiusDimension::*)() const) &AIS_EllipseRadiusDimension::DynamicType, "None");

// CLASS: AIS_EQUALDISTANCERELATION
py::class_<AIS_EqualDistanceRelation, opencascade::handle<AIS_EqualDistanceRelation>, AIS_Relation> cls_AIS_EqualDistanceRelation(mod, "AIS_EqualDistanceRelation", "A framework to display equivalent distances between shapes and a given plane. The distance is the length of a projection from the shape to the plane. These distances are used to compare shapes by this vector alone.");

// Constructors
cls_AIS_EqualDistanceRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aShape1"), py::arg("aShape2"), py::arg("aShape3"), py::arg("aShape4"), py::arg("aPlane"));

// Methods
cls_AIS_EqualDistanceRelation.def_static("get_type_name_", (const char * (*)()) &AIS_EqualDistanceRelation::get_type_name, "None");
cls_AIS_EqualDistanceRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EqualDistanceRelation::get_type_descriptor, "None");
cls_AIS_EqualDistanceRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::DynamicType, "None");
cls_AIS_EqualDistanceRelation.def("SetShape3", (void (AIS_EqualDistanceRelation::*)(const TopoDS_Shape &)) &AIS_EqualDistanceRelation::SetShape3, "Sets the shape aShape to be used as the shape aShape3 in the framework created at construction time.", py::arg("aShape"));
cls_AIS_EqualDistanceRelation.def("Shape3", (const TopoDS_Shape & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::Shape3, "Returns the shape aShape3 from the framework created at construction time.");
cls_AIS_EqualDistanceRelation.def("SetShape4", (void (AIS_EqualDistanceRelation::*)(const TopoDS_Shape &)) &AIS_EqualDistanceRelation::SetShape4, "Sets the shape aShape to be used as the shape aShape4 in the framework created at construction time.", py::arg("aShape"));
cls_AIS_EqualDistanceRelation.def("Shape4", (const TopoDS_Shape & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::Shape4, "Returns the shape aShape4 from the framework created at construction time.");
cls_AIS_EqualDistanceRelation.def("Compute", (void (AIS_EqualDistanceRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_EqualDistanceRelation::Compute, "Computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_EqualDistanceRelation.def_static("ComputeTwoEdgesLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeTwoEdgesLength, "Computes the location of an intreval between between two edges. FirstAttach , SecondAttach are the returned extreme points of the interval.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstEdge"), py::arg("SecondEdge"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));
cls_AIS_EqualDistanceRelation.def_static("ComputeTwoVerticesLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Vertex &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, const AIS_TypeOfDist, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeTwoVerticesLength, "Computes the interval position between two vertexs. FirstAttach, SecondAttach are the returned extreme points of the interval.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstVertex"), py::arg("SecondVertex"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("TypeDist"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));
cls_AIS_EqualDistanceRelation.def_static("ComputeOneEdgeOneVertexLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeOneEdgeOneVertexLength, "Compute the interval location between a vertex and an edge. Edge may be a line or a circle.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));

// CLASS: AIS_EQUALRADIUSRELATION
py::class_<AIS_EqualRadiusRelation, opencascade::handle<AIS_EqualRadiusRelation>, AIS_Relation> cls_AIS_EqualRadiusRelation(mod, "AIS_EqualRadiusRelation", "None");

// Constructors
cls_AIS_EqualRadiusRelation.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFirstEdge"), py::arg("aSecondEdge"), py::arg("aPlane"));

// Methods
cls_AIS_EqualRadiusRelation.def_static("get_type_name_", (const char * (*)()) &AIS_EqualRadiusRelation::get_type_name, "None");
cls_AIS_EqualRadiusRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EqualRadiusRelation::get_type_descriptor, "None");
cls_AIS_EqualRadiusRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EqualRadiusRelation::*)() const) &AIS_EqualRadiusRelation::DynamicType, "None");
cls_AIS_EqualRadiusRelation.def("Compute", (void (AIS_EqualRadiusRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_EqualRadiusRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_EXCLUSIONFILTER
py::class_<AIS_ExclusionFilter, opencascade::handle<AIS_ExclusionFilter>, SelectMgr_Filter> cls_AIS_ExclusionFilter(mod, "AIS_ExclusionFilter", "A framework to reject or to accept only objects of given types and/or signatures. Objects are stored, and the stored objects - along with the flag settings - are used to define the filter. Objects to be filtered are compared with the stored objects added to the filter, and are accepted or rejected according to the exclusion flag setting. - Exclusion flag on - the function IsOk answers true for all objects, except those of the types and signatures stored in the filter framework - Exclusion flag off - the funciton IsOk answers true for all objects which have the same type and signature as the stored ones.");

// Constructors
cls_AIS_ExclusionFilter.def(py::init<>());
cls_AIS_ExclusionFilter.def(py::init<const Standard_Boolean>(), py::arg("ExclusionFlagOn"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive>(), py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Boolean>(), py::arg("TypeToExclude"), py::arg("ExclusionFlagOn"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer>(), py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer, const Standard_Boolean>(), py::arg("TypeToExclude"), py::arg("SignatureInType"), py::arg("ExclusionFlagOn"));

// Methods
cls_AIS_ExclusionFilter.def("IsOk", (Standard_Boolean (AIS_ExclusionFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_ExclusionFilter::IsOk, "None", py::arg("anObj"));
cls_AIS_ExclusionFilter.def("Add", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive)) &AIS_ExclusionFilter::Add, "Adds the type TypeToExclude to the list of types.", py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def("Add", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, const Standard_Integer)) &AIS_ExclusionFilter::Add, "None", py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def("Remove", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive)) &AIS_ExclusionFilter::Remove, "None", py::arg("TypeToExclude"));
cls_AIS_ExclusionFilter.def("Remove", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, const Standard_Integer)) &AIS_ExclusionFilter::Remove, "None", py::arg("TypeToExclude"), py::arg("SignatureInType"));
cls_AIS_ExclusionFilter.def("Clear", (void (AIS_ExclusionFilter::*)()) &AIS_ExclusionFilter::Clear, "None");
cls_AIS_ExclusionFilter.def("IsExclusionFlagOn", (Standard_Boolean (AIS_ExclusionFilter::*)() const) &AIS_ExclusionFilter::IsExclusionFlagOn, "None");
cls_AIS_ExclusionFilter.def("SetExclusionFlag", (void (AIS_ExclusionFilter::*)(const Standard_Boolean)) &AIS_ExclusionFilter::SetExclusionFlag, "None", py::arg("Status"));
cls_AIS_ExclusionFilter.def("IsStored", (Standard_Boolean (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive) const) &AIS_ExclusionFilter::IsStored, "None", py::arg("aType"));
cls_AIS_ExclusionFilter.def("ListOfStoredTypes", (void (AIS_ExclusionFilter::*)(TColStd_ListOfInteger &) const) &AIS_ExclusionFilter::ListOfStoredTypes, "None", py::arg("TheList"));
cls_AIS_ExclusionFilter.def("ListOfSignature", (void (AIS_ExclusionFilter::*)(const AIS_KindOfInteractive, TColStd_ListOfInteger &) const) &AIS_ExclusionFilter::ListOfSignature, "None", py::arg("aType"), py::arg("TheStoredList"));
cls_AIS_ExclusionFilter.def_static("get_type_name_", (const char * (*)()) &AIS_ExclusionFilter::get_type_name, "None");
cls_AIS_ExclusionFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ExclusionFilter::get_type_descriptor, "None");
cls_AIS_ExclusionFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ExclusionFilter::*)() const) &AIS_ExclusionFilter::DynamicType, "None");

// CLASS: AIS_FIXRELATION
py::class_<AIS_FixRelation, opencascade::handle<AIS_FixRelation>, AIS_Relation> cls_AIS_FixRelation(mod, "AIS_FixRelation", "Constructs and manages a constraint by a fixed relation between two or more interactive datums. This constraint is represented by a wire from a shape - point, vertex, or edge - in the first datum and a corresponding shape in the second. Warning: This relation is not bound with any kind of parametric constraint : it represents the 'status' of an parametric object.");

// Constructors
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &, const gp_Pnt &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"), py::arg("aPosition"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const TopoDS_Wire &, const gp_Pnt &, const Standard_Real>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aWire"), py::arg("aPosition"), py::arg("anArrowSize"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aShape"), py::arg("aPlane"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aPosition"));
cls_AIS_FixRelation.def(py::init<const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const Standard_Real>(), py::arg("aShape"), py::arg("aPlane"), py::arg("aPosition"), py::arg("anArrowSize"));

// Methods
cls_AIS_FixRelation.def_static("get_type_name_", (const char * (*)()) &AIS_FixRelation::get_type_name, "None");
cls_AIS_FixRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_FixRelation::get_type_descriptor, "None");
cls_AIS_FixRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_FixRelation::*)() const) &AIS_FixRelation::DynamicType, "None");
cls_AIS_FixRelation.def("Wire", (TopoDS_Wire (AIS_FixRelation::*)()) &AIS_FixRelation::Wire, "Returns the wire which connects vertices in a fixed relation.");
cls_AIS_FixRelation.def("SetWire", (void (AIS_FixRelation::*)(const TopoDS_Wire &)) &AIS_FixRelation::SetWire, "Constructs the wire aWire. This connects vertices which are in a fixed relation.", py::arg("aWire"));
cls_AIS_FixRelation.def("IsMovable", (Standard_Boolean (AIS_FixRelation::*)() const) &AIS_FixRelation::IsMovable, "Returns true if the Interactive Objects in the relation are movable.");
cls_AIS_FixRelation.def("Compute", (void (AIS_FixRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_FixRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_GRAPHICTOOL
py::class_<AIS_GraphicTool> cls_AIS_GraphicTool(mod, "AIS_GraphicTool", "None");

// Constructors
cls_AIS_GraphicTool.def(py::init<>());

// Methods
// cls_AIS_GraphicTool.def_static("operator new_", (void * (*)(size_t)) &AIS_GraphicTool::operator new, "None", py::arg("theSize"));
// cls_AIS_GraphicTool.def_static("operator delete_", (void (*)(void *)) &AIS_GraphicTool::operator delete, "None", py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator new[]_", (void * (*)(size_t)) &AIS_GraphicTool::operator new[], "None", py::arg("theSize"));
// cls_AIS_GraphicTool.def_static("operator delete[]_", (void (*)(void *)) &AIS_GraphicTool::operator delete[], "None", py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator new_", (void * (*)(size_t, void *)) &AIS_GraphicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator delete_", (void (*)(void *, void *)) &AIS_GraphicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_AIS_GraphicTool.def_static("GetLineColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute, Quantity_Color &)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("TheLineColor"));
cls_AIS_GraphicTool.def_static("GetLineWidth_", (Standard_Real (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineWidth, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineType_", (Aspect_TypeOfLine (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineType, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineAtt_", [](const opencascade::handle<Prs3d_Drawer> & aDrawer, const AIS_TypeOfAttribute TheTypeOfAttributes, Quantity_NameOfColor & aCol, Standard_Real & aWidth, Aspect_TypeOfLine & aTyp){ AIS_GraphicTool::GetLineAtt(aDrawer, TheTypeOfAttributes, aCol, aWidth, aTyp); return aWidth; }, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("aCol"), py::arg("aWidth"), py::arg("aTyp"));
cls_AIS_GraphicTool.def_static("GetInteriorColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"));
cls_AIS_GraphicTool.def_static("GetInteriorColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, Quantity_Color &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"), py::arg("aColor"));
cls_AIS_GraphicTool.def_static("GetMaterial_", (Graphic3d_MaterialAspect (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetMaterial, "None", py::arg("aDrawer"));

// CLASS: AIS_IDENTICRELATION
py::class_<AIS_IdenticRelation, opencascade::handle<AIS_IdenticRelation>, AIS_Relation> cls_AIS_IdenticRelation(mod, "AIS_IdenticRelation", "Constructs a constraint by a relation of identity between two or more datums figuring in shape Interactive Objects.");

// Constructors
cls_AIS_IdenticRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("aPlane"));

// Methods
cls_AIS_IdenticRelation.def("HasUsers", (Standard_Boolean (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::HasUsers, "None");
cls_AIS_IdenticRelation.def("Users", (const TColStd_ListOfTransient & (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::Users, "None");
cls_AIS_IdenticRelation.def("AddUser", (void (AIS_IdenticRelation::*)(const opencascade::handle<Standard_Transient> &)) &AIS_IdenticRelation::AddUser, "None", py::arg("theUser"));
cls_AIS_IdenticRelation.def("ClearUsers", (void (AIS_IdenticRelation::*)()) &AIS_IdenticRelation::ClearUsers, "None");
cls_AIS_IdenticRelation.def("IsMovable", (Standard_Boolean (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::IsMovable, "Returns true if the interactive object is movable.");
cls_AIS_IdenticRelation.def("Compute", (void (AIS_IdenticRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_IdenticRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_IdenticRelation.def_static("get_type_name_", (const char * (*)()) &AIS_IdenticRelation::get_type_name, "None");
cls_AIS_IdenticRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_IdenticRelation::get_type_descriptor, "None");
cls_AIS_IdenticRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_IdenticRelation::*)() const) &AIS_IdenticRelation::DynamicType, "None");

// TYPEDEF: AIS_INDEXEDDATAMAPOFOWNERPRS
bind_NCollection_IndexedDataMap<opencascade::handle<SelectMgr_EntityOwner>, opencascade::handle<Graphic3d_Structure>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "AIS_IndexedDataMapOfOwnerPrs", py::module_local(false));

// CLASS: AIS_LENGTHDIMENSION
py::class_<AIS_LengthDimension, opencascade::handle<AIS_LengthDimension>, AIS_Dimension> cls_AIS_LengthDimension(mod, "AIS_LengthDimension", "Length dimension. Can be constructued: - Between two generic points. - Between two vertices. - Between two faces. - Between two parallel edges. - Between face and edge.");

// Constructors
cls_AIS_LengthDimension.def(py::init<const TopoDS_Face &, const TopoDS_Edge &>(), py::arg("theFace"), py::arg("theEdge"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Face &, const TopoDS_Face &>(), py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_LengthDimension.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pln &>(), py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("thePlane"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const gp_Pln &>(), py::arg("theFirstShape"), py::arg("theSecondShape"), py::arg("thePlane"));
cls_AIS_LengthDimension.def(py::init<const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge"), py::arg("thePlane"));

// Methods
cls_AIS_LengthDimension.def("FirstPoint", (const gp_Pnt & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::FirstPoint, "Returns first attachement point.");
cls_AIS_LengthDimension.def("SecondPoint", (const gp_Pnt & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::SecondPoint, "Returns second attachement point.");
cls_AIS_LengthDimension.def("FirstShape", (const TopoDS_Shape & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::FirstShape, "Returns first attachement shape.");
cls_AIS_LengthDimension.def("SecondShape", (const TopoDS_Shape & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::SecondShape, "Returns second attachement shape.");
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pln &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between two points. The dimension will become invalid if the new distance between attachement points is less than Precision::Confusion().", py::arg("theFirstPoint"), py::arg("theSecondPoint"), py::arg("thePlane"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Edge &, const gp_Pln &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure length of edge. The dimension will become invalid if the new length of edge is less than Precision::Confusion().", py::arg("theEdge"), py::arg("thePlane"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Face &, const TopoDS_Face &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between two faces. The dimension will become invalid if the distance can not be measured or it is less than Precision::Confusion().", py::arg("theFirstFace"), py::arg("theSecondFace"));
cls_AIS_LengthDimension.def("SetMeasuredGeometry", (void (AIS_LengthDimension::*)(const TopoDS_Face &, const TopoDS_Edge &)) &AIS_LengthDimension::SetMeasuredGeometry, "Measure distance between face and edge. The dimension will become invalid if the distance can not be measured or it is less than Precision::Confusion().", py::arg("theFace"), py::arg("theEdge"));
cls_AIS_LengthDimension.def("SetMeasuredShapes", (void (AIS_LengthDimension::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &AIS_LengthDimension::SetMeasuredShapes, "Measure distance between generic pair of shapes (edges, vertices, length), where measuring is applicable.", py::arg("theFirstShape"), py::arg("theSecondShape"));
cls_AIS_LengthDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_LengthDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_LengthDimension.def("SetDisplayUnits", (void (AIS_LengthDimension::*)(const TCollection_AsciiString &)) &AIS_LengthDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_LengthDimension.def("SetModelUnits", (void (AIS_LengthDimension::*)(const TCollection_AsciiString &)) &AIS_LengthDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_LengthDimension.def("SetTextPosition", (void (AIS_LengthDimension::*)(const gp_Pnt &)) &AIS_LengthDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_LengthDimension.def("GetTextPosition", (const gp_Pnt (AIS_LengthDimension::*)() const) &AIS_LengthDimension::GetTextPosition, "None");
cls_AIS_LengthDimension.def("SetDirection", [](AIS_LengthDimension &self, const gp_Dir & a0) -> void { return self.SetDirection(a0); });
cls_AIS_LengthDimension.def("SetDirection", (void (AIS_LengthDimension::*)(const gp_Dir &, const Standard_Boolean)) &AIS_LengthDimension::SetDirection, "Set custom direction for dimension. If it is not set, the direction is obtained from the measured geometry (e.g. line between points of dimension) The direction does not change flyout direction of dimension.", py::arg("theDirection"), py::arg("theUseDirection"));
cls_AIS_LengthDimension.def_static("get_type_name_", (const char * (*)()) &AIS_LengthDimension::get_type_name, "None");
cls_AIS_LengthDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_LengthDimension::get_type_descriptor, "None");
cls_AIS_LengthDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_LengthDimension::*)() const) &AIS_LengthDimension::DynamicType, "None");

// CLASS: AIS_LINE
py::class_<AIS_Line, opencascade::handle<AIS_Line>, AIS_InteractiveObject> cls_AIS_Line(mod, "AIS_Line", "Constructs line datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Line.def(py::init<const opencascade::handle<Geom_Line> &>(), py::arg("aLine"));
cls_AIS_Line.def(py::init<const opencascade::handle<Geom_Point> &, const opencascade::handle<Geom_Point> &>(), py::arg("aStartPoint"), py::arg("aEndPoint"));

// Methods
cls_AIS_Line.def_static("get_type_name_", (const char * (*)()) &AIS_Line::get_type_name, "None");
cls_AIS_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Line::get_type_descriptor, "None");
cls_AIS_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Line::*)() const) &AIS_Line::DynamicType, "None");
cls_AIS_Line.def("Compute", (void (AIS_Line::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Line::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Line.def("Signature", (Standard_Integer (AIS_Line::*)() const) &AIS_Line::Signature, "Returns the signature 5.");
cls_AIS_Line.def("Type", (AIS_KindOfInteractive (AIS_Line::*)() const) &AIS_Line::Type, "Returns the type Datum.");
cls_AIS_Line.def("Line", (const opencascade::handle<Geom_Line> & (AIS_Line::*)() const) &AIS_Line::Line, "Constructs an infinite line.");
cls_AIS_Line.def("Points", (void (AIS_Line::*)(opencascade::handle<Geom_Point> &, opencascade::handle<Geom_Point> &) const) &AIS_Line::Points, "Returns the starting point thePStart and the end point thePEnd of the line set by SetPoints.", py::arg("thePStart"), py::arg("thePEnd"));
cls_AIS_Line.def("SetLine", (void (AIS_Line::*)(const opencascade::handle<Geom_Line> &)) &AIS_Line::SetLine, "instantiates an infinite line.", py::arg("theLine"));
cls_AIS_Line.def("SetPoints", (void (AIS_Line::*)(const opencascade::handle<Geom_Point> &, const opencascade::handle<Geom_Point> &)) &AIS_Line::SetPoints, "Sets the starting point thePStart and ending point thePEnd of the infinite line to create a finite line segment.", py::arg("thePStart"), py::arg("thePEnd"));
cls_AIS_Line.def("SetColor", (void (AIS_Line::*)(const Quantity_Color &)) &AIS_Line::SetColor, "Provides a new color setting aColor for the line in the drawing tool, or 'Drawer'.", py::arg("aColor"));
cls_AIS_Line.def("SetWidth", (void (AIS_Line::*)(const Standard_Real)) &AIS_Line::SetWidth, "Provides the new width setting aValue for the line in the drawing tool, or 'Drawer'.", py::arg("aValue"));
cls_AIS_Line.def("UnsetColor", (void (AIS_Line::*)()) &AIS_Line::UnsetColor, "Removes the color setting and returns the original color.");
cls_AIS_Line.def("UnsetWidth", (void (AIS_Line::*)()) &AIS_Line::UnsetWidth, "Removes the width setting and returns the original width.");

// CLASS: AIS_MANIPULATOROBJECTSEQUENCE
py::class_<AIS_ManipulatorObjectSequence, opencascade::handle<AIS_ManipulatorObjectSequence>, Standard_Transient> cls_AIS_ManipulatorObjectSequence(mod, "AIS_ManipulatorObjectSequence", "None", py::multiple_inheritance());

// Constructors
cls_AIS_ManipulatorObjectSequence.def(py::init<>());
cls_AIS_ManipulatorObjectSequence.def(py::init<const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > &>(), py::arg("theOther"));

// Methods
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg("theSize"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new[]_", (void * (*)(size_t)) &AIS_ManipulatorObjectSequence::operator new[], "None", py::arg("theSize"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete[]_", (void (*)(void *)) &AIS_ManipulatorObjectSequence::operator delete[], "None", py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t, void *)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *, void *)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg(""), py::arg(""));
// cls_AIS_ManipulatorObjectSequence.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AIS_ManipulatorObjectSequence::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AIS_ManipulatorObjectSequence.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AIS_ManipulatorObjectSequence::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AIS_ManipulatorObjectSequence.def("Sequence", (const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > & (AIS_ManipulatorObjectSequence::*)() const) &AIS_ManipulatorObjectSequence::Sequence, "None");
cls_AIS_ManipulatorObjectSequence.def("Append", (void (AIS_ManipulatorObjectSequence::*)(const NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> >::value_type &)) &AIS_ManipulatorObjectSequence::Append, "None", py::arg("theItem"));
cls_AIS_ManipulatorObjectSequence.def("Append", (void (AIS_ManipulatorObjectSequence::*)(NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > &)) &AIS_ManipulatorObjectSequence::Append, "None", py::arg("theSequence"));
cls_AIS_ManipulatorObjectSequence.def("ChangeSequence", (NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> > & (AIS_ManipulatorObjectSequence::*)()) &AIS_ManipulatorObjectSequence::ChangeSequence, "None");
cls_AIS_ManipulatorObjectSequence.def_static("get_type_name_", (const char * (*)()) &AIS_ManipulatorObjectSequence::get_type_name, "None");
cls_AIS_ManipulatorObjectSequence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ManipulatorObjectSequence::get_type_descriptor, "None");
cls_AIS_ManipulatorObjectSequence.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ManipulatorObjectSequence::*)() const) &AIS_ManipulatorObjectSequence::DynamicType, "None");

// CLASS: AIS_MANIPULATOR
py::class_<AIS_Manipulator, opencascade::handle<AIS_Manipulator>, AIS_InteractiveObject> cls_AIS_Manipulator(mod, "AIS_Manipulator", "Interactive object class to manipulate local transformation of another interactive object or a group of objects via mouse. It manages three types of manipulations in 3D space: - translation through axis - scaling within axis - rotation around axis To enable one of this modes, selection mode (from 1 to 3) is to be activated. There are three orthogonal transformation axes defined by position property of the manipulator. Particular transformation mode can be disabled for each of the axes or all of them. Furthermore each of the axes can be hidden or made visible. The following steps demonstrate how to attach, configure and use manipulator for an interactive object: Step 1. Create manipulator object and adjust it appearance: Note that you can enable only one manipulation mode but have all visual parts displayed. This code allows you to view manipulator and select its manipulation parts. Note that manipulator activates mode on part selection. If this mode is activated, no selection will be performed for manipulator. It can be activated with highlighting. To enable this: Step 2. To perform transformation of object use next code in your event processing chain: Step 3. To deactivate current manipulation mode use: Step 4. To detach manipulator from object use: The last method erases manipulator object.");

// Constructors
cls_AIS_Manipulator.def(py::init<>());
cls_AIS_Manipulator.def(py::init<const gp_Ax2 &>(), py::arg("thePosition"));

// Methods
cls_AIS_Manipulator.def("SetPart", (void (AIS_Manipulator::*)(const Standard_Integer, const AIS_ManipulatorMode, const Standard_Boolean)) &AIS_Manipulator::SetPart, "Disable or enable visual parts for translation, rotation or scaling for some axis. By default all parts are enabled (will be displayed).", py::arg("theAxisIndex"), py::arg("theMode"), py::arg("theIsEnabled"));
cls_AIS_Manipulator.def("SetPart", (void (AIS_Manipulator::*)(const AIS_ManipulatorMode, const Standard_Boolean)) &AIS_Manipulator::SetPart, "Disable or enable visual parts for translation, rotation or scaling for ALL axes. By default all parts are enabled (will be displayed).", py::arg("theMode"), py::arg("theIsEnabled"));
cls_AIS_Manipulator.def("Attach", [](AIS_Manipulator &self, const opencascade::handle<AIS_InteractiveObject> & a0) -> void { return self.Attach(a0); });
cls_AIS_Manipulator.def("Attach", (void (AIS_Manipulator::*)(const opencascade::handle<AIS_InteractiveObject> &, const AIS_Manipulator::OptionsForAttach &)) &AIS_Manipulator::Attach, "Attaches himself to the input interactive object and become displayed in the same context. It is placed in the center of object bounding box, and its size is adjusted to the object bounding box.", py::arg("theObject"), py::arg("theOptions"));
cls_AIS_Manipulator.def("Attach", [](AIS_Manipulator &self, const opencascade::handle<AIS_ManipulatorObjectSequence> & a0) -> void { return self.Attach(a0); });
cls_AIS_Manipulator.def("Attach", (void (AIS_Manipulator::*)(const opencascade::handle<AIS_ManipulatorObjectSequence> &, const AIS_Manipulator::OptionsForAttach &)) &AIS_Manipulator::Attach, "Attaches himself to the input interactive object group and become displayed in the same context. It become attached to the first object, baut manage manipulation of the whole group. It is placed in the center of object bounding box, and its size is adjusted to the object bounding box.", py::arg("theObject"), py::arg("theOptions"));
cls_AIS_Manipulator.def("EnableMode", (void (AIS_Manipulator::*)(const AIS_ManipulatorMode)) &AIS_Manipulator::EnableMode, "Enable manipualtion mode.", py::arg("theMode"));
cls_AIS_Manipulator.def("SetModeActivationOnDetection", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::SetModeActivationOnDetection, "Enables mode activation on detection (highlighting). By default, mode is activated on selection of manipulator part.", py::arg("theToEnable"));
cls_AIS_Manipulator.def("IsModeActivationOnDetection", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsModeActivationOnDetection, "Returns true if manual mode activation is enabled.");
cls_AIS_Manipulator.def("StartTransform", (void (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &AIS_Manipulator::StartTransform, "Init start (reference) transformation.", py::arg("theX"), py::arg("theY"), py::arg("theView"));
cls_AIS_Manipulator.def("Transform", (void (AIS_Manipulator::*)(const gp_Trsf &)) &AIS_Manipulator::Transform, "Apply to the owning objects the input transformation.", py::arg("aTrsf"));
cls_AIS_Manipulator.def("StopTransform", [](AIS_Manipulator &self) -> void { return self.StopTransform(); });
cls_AIS_Manipulator.def("StopTransform", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::StopTransform, "Reset start (reference) transformation.", py::arg("theToApply"));
cls_AIS_Manipulator.def("Transform", (gp_Trsf (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &AIS_Manipulator::Transform, "Apply transformation made from mouse moving from start position (save on the first Tranform() call and reset on DeactivateCurrentMode() call.) to the in/out mouse position (theX, theY)", py::arg("theX"), py::arg("theY"), py::arg("theView"));
cls_AIS_Manipulator.def("ObjectTransformation", (Standard_Boolean (AIS_Manipulator::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &, gp_Trsf &)) &AIS_Manipulator::ObjectTransformation, "Computes transformation of parent object according to the active mode and input motion vector. You can use this method to get object transformation according to current mode or use own algorithm to implement any other tranformation for modes.", py::arg("theX"), py::arg("theY"), py::arg("theView"), py::arg("theTrsf"));
cls_AIS_Manipulator.def("DeactivateCurrentMode", (void (AIS_Manipulator::*)()) &AIS_Manipulator::DeactivateCurrentMode, "Make inactive the current selected manipulator part and reset current axis index and current mode. After its call HasActiveMode() returns false.");
cls_AIS_Manipulator.def("Detach", (void (AIS_Manipulator::*)()) &AIS_Manipulator::Detach, "Detaches himself from the owner object, and removes itself from context.");
cls_AIS_Manipulator.def("Objects", (opencascade::handle<AIS_ManipulatorObjectSequence> (AIS_Manipulator::*)() const) &AIS_Manipulator::Objects, "Returns all owning objects.");
cls_AIS_Manipulator.def("Object", (opencascade::handle<AIS_InteractiveObject> (AIS_Manipulator::*)() const) &AIS_Manipulator::Object, "Returns the first (leading) object of the owning objects.");
cls_AIS_Manipulator.def("Object", (opencascade::handle<AIS_InteractiveObject> (AIS_Manipulator::*)(const Standard_Integer) const) &AIS_Manipulator::Object, "Returns one of the owning objects. raises program error if theIndex is more than owning objects count or less than 1.", py::arg("theIndex"));
cls_AIS_Manipulator.def("IsAttached", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsAttached, "Returns true if manipulator is attached to some interactive object (has owning object).");
cls_AIS_Manipulator.def("HasActiveMode", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::HasActiveMode, "Returns true if some part of manipulator is selected (transformation mode is active, and owning object can be transformed).");
cls_AIS_Manipulator.def("HasActiveTransformation", (Standard_Boolean (AIS_Manipulator::*)()) &AIS_Manipulator::HasActiveTransformation, "None");
cls_AIS_Manipulator.def("StartTransformation", (gp_Trsf (AIS_Manipulator::*)() const) &AIS_Manipulator::StartTransformation, "None");
cls_AIS_Manipulator.def("StartTransformation", (gp_Trsf (AIS_Manipulator::*)(Standard_Integer) const) &AIS_Manipulator::StartTransformation, "None", py::arg("theIndex"));
cls_AIS_Manipulator.def("SetZoomPersistence", (void (AIS_Manipulator::*)(const Standard_Boolean)) &AIS_Manipulator::SetZoomPersistence, "Enable or disable zoom persistence mode for the manipulator. With this mode turned on the presentation will keep fixed screen size.", py::arg("theToEnable"));
cls_AIS_Manipulator.def("ZoomPersistence", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::ZoomPersistence, "Returns state of zoom persistence mode, whether it turned on or off.");
cls_AIS_Manipulator.def("SetTransformPersistence", (void (AIS_Manipulator::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_Manipulator::SetTransformPersistence, "Redefines transform persistence management to setup transformation for sub-presentation of axes.", py::arg("theTrsfPers"));
cls_AIS_Manipulator.def("ActiveMode", (AIS_ManipulatorMode (AIS_Manipulator::*)() const) &AIS_Manipulator::ActiveMode, "");
cls_AIS_Manipulator.def("Position", (const gp_Ax2 & (AIS_Manipulator::*)() const) &AIS_Manipulator::Position, "Returns poition of manipulator interactive object.");
cls_AIS_Manipulator.def("SetPosition", (void (AIS_Manipulator::*)(const gp_Ax2 &)) &AIS_Manipulator::SetPosition, "Sets position of the manipulator object.", py::arg("thePosition"));
cls_AIS_Manipulator.def("Size", (Standard_ShortReal (AIS_Manipulator::*)() const) &AIS_Manipulator::Size, "None");
cls_AIS_Manipulator.def("SetSize", (void (AIS_Manipulator::*)(const Standard_ShortReal)) &AIS_Manipulator::SetSize, "Sets size (length of side of the manipulator cubic bounding box.", py::arg("theSideLength"));
cls_AIS_Manipulator.def("SetGap", (void (AIS_Manipulator::*)(const Standard_ShortReal)) &AIS_Manipulator::SetGap, "Sets gaps between translator, scaler and rotator sub-presentations.", py::arg("theValue"));
cls_AIS_Manipulator.def("SetTransformBehavior", (void (AIS_Manipulator::*)(const AIS_Manipulator::BehaviorOnTransform &)) &AIS_Manipulator::SetTransformBehavior, "Sets behavior settings for transformation action carried on the manipulator, whether it translates, rotates together with the transformed object or not.", py::arg("theSettings"));
cls_AIS_Manipulator.def("ChangeTransformBehavior", (AIS_Manipulator::BehaviorOnTransform & (AIS_Manipulator::*)()) &AIS_Manipulator::ChangeTransformBehavior, "Returns behavior settings for transformation action of the manipulator.");
cls_AIS_Manipulator.def("TransformBehavior", (const AIS_Manipulator::BehaviorOnTransform & (AIS_Manipulator::*)() const) &AIS_Manipulator::TransformBehavior, "Returns behavior settings for transformation action of the manipulator.");
cls_AIS_Manipulator.def("Compute", [](AIS_Manipulator &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Presentation> & a1) -> void { return self.Compute(a0, a1); });
cls_AIS_Manipulator.def("Compute", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &AIS_Manipulator::Compute, "Fills presentation.", py::arg("thePrsMgr"), py::arg("thePrs"), py::arg("theMode"));
cls_AIS_Manipulator.def("ComputeSelection", (void (AIS_Manipulator::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_Manipulator::ComputeSelection, "Computes selection sensitive zones (triangulation) for manipulator.", py::arg("theSelection"), py::arg("theMode"));
cls_AIS_Manipulator.def("IsAutoHilight", (Standard_Boolean (AIS_Manipulator::*)() const) &AIS_Manipulator::IsAutoHilight, "Disables auto highlighting to use HilightSelected() and HilightOwnerWithColor() overridden methods.");
cls_AIS_Manipulator.def("ClearSelected", (void (AIS_Manipulator::*)()) &AIS_Manipulator::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw ).");
cls_AIS_Manipulator.def("HilightSelected", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &AIS_Manipulator::HilightSelected, "Method which draws selected owners ( for fast presentation draw ).", py::arg("thePM"), py::arg("theSeq"));
cls_AIS_Manipulator.def("HilightOwnerWithColor", (void (AIS_Manipulator::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Manipulator::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw ).", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));
cls_AIS_Manipulator.def_static("get_type_name_", (const char * (*)()) &AIS_Manipulator::get_type_name, "None");
cls_AIS_Manipulator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Manipulator::get_type_descriptor, "None");
cls_AIS_Manipulator.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Manipulator::*)() const) &AIS_Manipulator::DynamicType, "None");

// CLASS: AIS_MANIPULATOROWNER
py::class_<AIS_ManipulatorOwner, opencascade::handle<AIS_ManipulatorOwner>, SelectMgr_EntityOwner> cls_AIS_ManipulatorOwner(mod, "AIS_ManipulatorOwner", "Entity owner for selection management of AIS_Manipulator object.");

// Constructors
cls_AIS_ManipulatorOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const AIS_ManipulatorMode>(), py::arg("theSelObject"), py::arg("theIndex"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const AIS_ManipulatorMode, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theIndex"), py::arg("theMode"), py::arg("thePriority"));

// Methods
cls_AIS_ManipulatorOwner.def_static("get_type_name_", (const char * (*)()) &AIS_ManipulatorOwner::get_type_name, "None");
cls_AIS_ManipulatorOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ManipulatorOwner::get_type_descriptor, "None");
cls_AIS_ManipulatorOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::DynamicType, "None");
cls_AIS_ManipulatorOwner.def("HilightWithColor", (void (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_ManipulatorOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("IsHilighted", (Standard_Boolean (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_ManipulatorOwner::IsHilighted, "None", py::arg("thePM"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("Unhilight", (void (AIS_ManipulatorOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_ManipulatorOwner::Unhilight, "None", py::arg("thePM"), py::arg("theMode"));
cls_AIS_ManipulatorOwner.def("Mode", (AIS_ManipulatorMode (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::Mode, "None");
cls_AIS_ManipulatorOwner.def("Index", (Standard_Integer (AIS_ManipulatorOwner::*)() const) &AIS_ManipulatorOwner::Index, "Returns index of manipulator axis.");

// TYPEDEF: AIS_MAPOFINTERACTIVE
bind_NCollection_Map<opencascade::handle<AIS_InteractiveObject>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "AIS_MapOfInteractive", py::module_local(false));

// TYPEDEF: AIS_MAPITERATOROFMAPOFINTERACTIVE

// CLASS: AIS_MAXRADIUSDIMENSION
py::class_<AIS_MaxRadiusDimension, opencascade::handle<AIS_MaxRadiusDimension>, AIS_EllipseRadiusDimension> cls_AIS_MaxRadiusDimension(mod, "AIS_MaxRadiusDimension", "Ellipse Max radius dimension of a Shape which can be Edge or Face (planar or cylindrical(surface of extrusion or surface of offset))");

// Constructors
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"));
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_MaxRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Methods
cls_AIS_MaxRadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_MaxRadiusDimension::get_type_name, "None");
cls_AIS_MaxRadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MaxRadiusDimension::get_type_descriptor, "None");
cls_AIS_MaxRadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MaxRadiusDimension::*)() const) &AIS_MaxRadiusDimension::DynamicType, "None");
cls_AIS_MaxRadiusDimension.def("Compute", (void (AIS_MaxRadiusDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MaxRadiusDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_MEDIAPLAYER
py::class_<AIS_MediaPlayer, opencascade::handle<AIS_MediaPlayer>, AIS_InteractiveObject> cls_AIS_MediaPlayer(mod, "AIS_MediaPlayer", "Presentation for video playback.");

// Constructors
cls_AIS_MediaPlayer.def(py::init<>());

// Methods
cls_AIS_MediaPlayer.def_static("get_type_name_", (const char * (*)()) &AIS_MediaPlayer::get_type_name, "None");
cls_AIS_MediaPlayer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MediaPlayer::get_type_descriptor, "None");
cls_AIS_MediaPlayer.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MediaPlayer::*)() const) &AIS_MediaPlayer::DynamicType, "None");
cls_AIS_MediaPlayer.def("SetCallback", (void (AIS_MediaPlayer::*)(Graphic3d_MediaTextureSet::CallbackOnUpdate_t, void *)) &AIS_MediaPlayer::SetCallback, "Setup callback to be called on queue progress (e.g. when new frame should be displayed).", py::arg("theCallbackFunction"), py::arg("theCallbackUserPtr"));
cls_AIS_MediaPlayer.def("OpenInput", (void (AIS_MediaPlayer::*)(const TCollection_AsciiString &, Standard_Boolean)) &AIS_MediaPlayer::OpenInput, "Open specified file.", py::arg("thePath"), py::arg("theToWait"));
cls_AIS_MediaPlayer.def("PresentFrame", (bool (AIS_MediaPlayer::*)(const Graphic3d_Vec2i &, const Graphic3d_Vec2i &)) &AIS_MediaPlayer::PresentFrame, "Display new frame.", py::arg("theLeftCorner"), py::arg("theMaxSize"));
cls_AIS_MediaPlayer.def("PlayerContext", (const opencascade::handle<Media_PlayerContext> & (AIS_MediaPlayer::*)() const) &AIS_MediaPlayer::PlayerContext, "Return player context.");
cls_AIS_MediaPlayer.def("PlayPause", (void (AIS_MediaPlayer::*)()) &AIS_MediaPlayer::PlayPause, "Switch playback state.");
cls_AIS_MediaPlayer.def("SetClosePlayer", (void (AIS_MediaPlayer::*)()) &AIS_MediaPlayer::SetClosePlayer, "Schedule player to be closed.");
cls_AIS_MediaPlayer.def("Duration", (double (AIS_MediaPlayer::*)() const) &AIS_MediaPlayer::Duration, "Return duration.");

// CLASS: AIS_MIDPOINTRELATION
py::class_<AIS_MidPointRelation, opencascade::handle<AIS_MidPointRelation>, AIS_Relation> cls_AIS_MidPointRelation(mod, "AIS_MidPointRelation", "presentation of equal distance to point myMidPoint");

// Constructors
cls_AIS_MidPointRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aSymmTool"), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("aPlane"));

// Methods
cls_AIS_MidPointRelation.def_static("get_type_name_", (const char * (*)()) &AIS_MidPointRelation::get_type_name, "None");
cls_AIS_MidPointRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MidPointRelation::get_type_descriptor, "None");
cls_AIS_MidPointRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MidPointRelation::*)() const) &AIS_MidPointRelation::DynamicType, "None");
cls_AIS_MidPointRelation.def("IsMovable", (Standard_Boolean (AIS_MidPointRelation::*)() const) &AIS_MidPointRelation::IsMovable, "None");
cls_AIS_MidPointRelation.def("SetTool", (void (AIS_MidPointRelation::*)(const TopoDS_Shape &)) &AIS_MidPointRelation::SetTool, "None", py::arg("aMidPointTool"));
cls_AIS_MidPointRelation.def("GetTool", (const TopoDS_Shape & (AIS_MidPointRelation::*)() const) &AIS_MidPointRelation::GetTool, "None");
cls_AIS_MidPointRelation.def("Compute", (void (AIS_MidPointRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MidPointRelation::Compute, "Computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_MINRADIUSDIMENSION
py::class_<AIS_MinRadiusDimension, opencascade::handle<AIS_MinRadiusDimension>, AIS_EllipseRadiusDimension> cls_AIS_MinRadiusDimension(mod, "AIS_MinRadiusDimension", "-- Ellipse Min radius dimension of a Shape which can be Edge or Face (planar or cylindrical(surface of extrusion or surface of offset))");

// Constructors
cls_AIS_MinRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"));
cls_AIS_MinRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_MinRadiusDimension.def(py::init<const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aShape"), py::arg("aVal"), py::arg("aText"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Methods
cls_AIS_MinRadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_MinRadiusDimension::get_type_name, "None");
cls_AIS_MinRadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MinRadiusDimension::get_type_descriptor, "None");
cls_AIS_MinRadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MinRadiusDimension::*)() const) &AIS_MinRadiusDimension::DynamicType, "None");
cls_AIS_MinRadiusDimension.def("Compute", (void (AIS_MinRadiusDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MinRadiusDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// TYPEDEF: AIS_MOUSEGESTUREMAP
bind_NCollection_DataMap<unsigned int, AIS_MouseGesture, NCollection_DefaultHasher<unsigned int> >(mod, "AIS_MouseGestureMap", py::module_local(false));

// CLASS: AIS_MULTIPLECONNECTEDINTERACTIVE
py::class_<AIS_MultipleConnectedInteractive, opencascade::handle<AIS_MultipleConnectedInteractive>, AIS_InteractiveObject> cls_AIS_MultipleConnectedInteractive(mod, "AIS_MultipleConnectedInteractive", "Defines an Interactive Object by gathering together several object presentations. This is done through a list of interactive objects. These can also be Connected objects. That way memory-costly calculations of presentation are avoided.");

// Constructors
cls_AIS_MultipleConnectedInteractive.def(py::init<>());

// Methods
cls_AIS_MultipleConnectedInteractive.def_static("get_type_name_", (const char * (*)()) &AIS_MultipleConnectedInteractive::get_type_name, "None");
cls_AIS_MultipleConnectedInteractive.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_MultipleConnectedInteractive::get_type_descriptor, "None");
cls_AIS_MultipleConnectedInteractive.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::DynamicType, "None");
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and applies specified transformation persistence mode.", py::arg("theAnotherObj"), py::arg("theLocation"), py::arg("theTrsfPers"));
cls_AIS_MultipleConnectedInteractive.def("Type", (AIS_KindOfInteractive (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::Type, "None");
cls_AIS_MultipleConnectedInteractive.def("Signature", (Standard_Integer (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::Signature, "None");
cls_AIS_MultipleConnectedInteractive.def("HasConnection", (Standard_Boolean (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::HasConnection, "Returns true if the object is connected to others.");
cls_AIS_MultipleConnectedInteractive.def("Disconnect", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_MultipleConnectedInteractive::Disconnect, "Removes the connection with theInteractive.", py::arg("theInteractive"));
cls_AIS_MultipleConnectedInteractive.def("DisconnectAll", (void (AIS_MultipleConnectedInteractive::*)()) &AIS_MultipleConnectedInteractive::DisconnectAll, "Clears all the connections to objects.");
cls_AIS_MultipleConnectedInteractive.def("Compute", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MultipleConnectedInteractive::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_MultipleConnectedInteractive.def("Compute", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_MultipleConnectedInteractive::Compute, "None", py::arg("aProjector"), py::arg("aPresentation"));
cls_AIS_MultipleConnectedInteractive.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection.");
cls_AIS_MultipleConnectedInteractive.def("GetAssemblyOwner", (const opencascade::handle<SelectMgr_EntityOwner> & (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::GetAssemblyOwner, "Returns common entity owner if the object is an assembly");
cls_AIS_MultipleConnectedInteractive.def("GlobalSelOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_MultipleConnectedInteractive::*)() const) &AIS_MultipleConnectedInteractive::GlobalSelOwner, "Returns the owner of mode for selection of object as a whole");
cls_AIS_MultipleConnectedInteractive.def("SetContext", (void (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_MultipleConnectedInteractive::SetContext, "Assigns interactive context.", py::arg("theCtx"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Copies local transformation and transformation persistence mode from theInteractive.", py::arg("theAnotherObj"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and copies transformation persistence mode from theInteractive.", py::arg("theAnotherObj"), py::arg("theLocation"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const opencascade::handle<Graphic3d_TransformPers> &)) &AIS_MultipleConnectedInteractive::Connect, "Establishes the connection between the Connected Interactive Object, theInteractive, and its reference. Locates instance in theLocation and applies specified transformation persistence mode.", py::arg("theAnotherObj"), py::arg("theLocation"), py::arg("theTrsfPers"));
cls_AIS_MultipleConnectedInteractive.def("Connect", (opencascade::handle<AIS_InteractiveObject> (AIS_MultipleConnectedInteractive::*)(const opencascade::handle<AIS_InteractiveObject> &, const gp_Trsf &, const Graphic3d_TransModeFlags &, const gp_Pnt &)) &AIS_MultipleConnectedInteractive::Connect, "None", py::arg("theInteractive"), py::arg("theLocation"), py::arg("theTrsfPersFlag"), py::arg("theTrsfPersPoint"));

// CLASS: AIS_OFFSETDIMENSION
py::class_<AIS_OffsetDimension, opencascade::handle<AIS_OffsetDimension>, AIS_Relation> cls_AIS_OffsetDimension(mod, "AIS_OffsetDimension", "A framework to display dimensions of offsets. The relation between the offset and the basis shape is indicated. This relation is displayed with arrows and text. The text gives the dsitance between the offset and the basis shape.");

// Constructors
cls_AIS_OffsetDimension.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Real, const TCollection_ExtendedString &>(), py::arg("FistShape"), py::arg("SecondShape"), py::arg("aVal"), py::arg("aText"));

// Methods
cls_AIS_OffsetDimension.def_static("get_type_name_", (const char * (*)()) &AIS_OffsetDimension::get_type_name, "None");
cls_AIS_OffsetDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_OffsetDimension::get_type_descriptor, "None");
cls_AIS_OffsetDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::DynamicType, "None");
cls_AIS_OffsetDimension.def("Compute", (void (AIS_OffsetDimension::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_OffsetDimension::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_OffsetDimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::KindOfDimension, "Indicates that the dimension we are concerned with is an offset.");
cls_AIS_OffsetDimension.def("IsMovable", (Standard_Boolean (AIS_OffsetDimension::*)() const) &AIS_OffsetDimension::IsMovable, "Returns true if the offset datum is movable.");
cls_AIS_OffsetDimension.def("SetRelativePos", (void (AIS_OffsetDimension::*)(const gp_Trsf &)) &AIS_OffsetDimension::SetRelativePos, "Sets a transformation aTrsf for presentation and selection to a relative position.", py::arg("aTrsf"));

// CLASS: AIS_PARALLELRELATION
py::class_<AIS_ParallelRelation, opencascade::handle<AIS_ParallelRelation>, AIS_Relation> cls_AIS_ParallelRelation(mod, "AIS_ParallelRelation", "A framework to display constraints of parallelism between two or more Interactive Objects. These entities can be faces or edges.");

// Constructors
cls_AIS_ParallelRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"));
cls_AIS_ParallelRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const DsgPrs_ArrowSide>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"), py::arg("aPosition"), py::arg("aSymbolPrs"));
cls_AIS_ParallelRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Real>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"), py::arg("aPosition"), py::arg("aSymbolPrs"), py::arg("anArrowSize"));

// Methods
cls_AIS_ParallelRelation.def_static("get_type_name_", (const char * (*)()) &AIS_ParallelRelation::get_type_name, "None");
cls_AIS_ParallelRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ParallelRelation::get_type_descriptor, "None");
cls_AIS_ParallelRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ParallelRelation::*)() const) &AIS_ParallelRelation::DynamicType, "None");
cls_AIS_ParallelRelation.def("IsMovable", (Standard_Boolean (AIS_ParallelRelation::*)() const) &AIS_ParallelRelation::IsMovable, "Returns true if the parallelism is movable.");
cls_AIS_ParallelRelation.def("Compute", (void (AIS_ParallelRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_ParallelRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_PERPENDICULARRELATION
py::class_<AIS_PerpendicularRelation, opencascade::handle<AIS_PerpendicularRelation>, AIS_Relation> cls_AIS_PerpendicularRelation(mod, "AIS_PerpendicularRelation", "A framework to display constraints of perpendicularity between two or more interactive datums. These datums can be edges or faces.");

// Constructors
cls_AIS_PerpendicularRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"));
cls_AIS_PerpendicularRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("aFShape"), py::arg("aSShape"));

// Methods
cls_AIS_PerpendicularRelation.def_static("get_type_name_", (const char * (*)()) &AIS_PerpendicularRelation::get_type_name, "None");
cls_AIS_PerpendicularRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PerpendicularRelation::get_type_descriptor, "None");
cls_AIS_PerpendicularRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PerpendicularRelation::*)() const) &AIS_PerpendicularRelation::DynamicType, "None");
cls_AIS_PerpendicularRelation.def("Compute", (void (AIS_PerpendicularRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_PerpendicularRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_PLANE
py::class_<AIS_Plane, opencascade::handle<AIS_Plane>, AIS_InteractiveObject> cls_AIS_Plane(mod, "AIS_Plane", "Constructs plane datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &>(), py::arg("aComponent"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &>(), py::arg("aComponent"), py::arg("aCenter"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"), py::arg("aCurrentMode"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane>(), py::arg("aComponent"), py::arg("aPlaneType"));
cls_AIS_Plane.def(py::init<const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane, const Standard_Boolean>(), py::arg("aComponent"), py::arg("aPlaneType"), py::arg("aCurrentMode"));

// Methods
cls_AIS_Plane.def_static("get_type_name_", (const char * (*)()) &AIS_Plane::get_type_name, "None");
cls_AIS_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Plane::get_type_descriptor, "None");
cls_AIS_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Plane::*)() const) &AIS_Plane::DynamicType, "None");
cls_AIS_Plane.def("SetSize", (void (AIS_Plane::*)(const Standard_Real)) &AIS_Plane::SetSize, "Same value for x and y directions", py::arg("aValue"));
cls_AIS_Plane.def("SetSize", (void (AIS_Plane::*)(const Standard_Real, const Standard_Real)) &AIS_Plane::SetSize, "Sets the size defined by the length along the X axis XVal and the length along the Y axis YVal.", py::arg("Xval"), py::arg("YVal"));
cls_AIS_Plane.def("UnsetSize", (void (AIS_Plane::*)()) &AIS_Plane::UnsetSize, "None");
cls_AIS_Plane.def("Size", [](AIS_Plane &self, Standard_Real & X, Standard_Real & Y){ Standard_Boolean rv = self.Size(X, Y); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, X, Y); }, "None", py::arg("X"), py::arg("Y"));
cls_AIS_Plane.def("HasOwnSize", (Standard_Boolean (AIS_Plane::*)() const) &AIS_Plane::HasOwnSize, "None");
cls_AIS_Plane.def("Signature", (Standard_Integer (AIS_Plane::*)() const) &AIS_Plane::Signature, "None");
cls_AIS_Plane.def("Type", (AIS_KindOfInteractive (AIS_Plane::*)() const) &AIS_Plane::Type, "None");
cls_AIS_Plane.def("Component", (const opencascade::handle<Geom_Plane> & (AIS_Plane::*)()) &AIS_Plane::Component, "Returns the component specified in SetComponent.");
cls_AIS_Plane.def("SetComponent", (void (AIS_Plane::*)(const opencascade::handle<Geom_Plane> &)) &AIS_Plane::SetComponent, "Creates an instance of the plane aComponent.", py::arg("aComponent"));
cls_AIS_Plane.def("PlaneAttributes", (Standard_Boolean (AIS_Plane::*)(opencascade::handle<Geom_Plane> &, gp_Pnt &, gp_Pnt &, gp_Pnt &)) &AIS_Plane::PlaneAttributes, "Returns the settings for the selected plane aComponent, provided in SetPlaneAttributes. These include the points aCenter, aPmin, and aPmax", py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def("SetPlaneAttributes", (void (AIS_Plane::*)(const opencascade::handle<Geom_Plane> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &AIS_Plane::SetPlaneAttributes, "Allows you to provide settings other than default ones for the selected plane. These include: center point aCenter, maximum aPmax and minimum aPmin.", py::arg("aComponent"), py::arg("aCenter"), py::arg("aPmin"), py::arg("aPmax"));
cls_AIS_Plane.def("Center", (const gp_Pnt & (AIS_Plane::*)() const) &AIS_Plane::Center, "Returns the coordinates of the center point.");
cls_AIS_Plane.def("SetCenter", (void (AIS_Plane::*)(const gp_Pnt &)) &AIS_Plane::SetCenter, "Provides settings for the center theCenter other than (0, 0, 0).", py::arg("theCenter"));
cls_AIS_Plane.def("SetAxis2Placement", (void (AIS_Plane::*)(const opencascade::handle<Geom_Axis2Placement> &, const AIS_TypeOfPlane)) &AIS_Plane::SetAxis2Placement, "Allows you to provide settings for the position and direction of one of the plane's axes, aComponent, in 3D space. The coordinate system used is right-handed, and the type of plane aPlaneType is one of: - AIS_ TOPL_Unknown - AIS_ TOPL_XYPlane - AIS_ TOPL_XZPlane - AIS_ TOPL_YZPlane}.", py::arg("aComponent"), py::arg("aPlaneType"));
cls_AIS_Plane.def("Axis2Placement", (opencascade::handle<Geom_Axis2Placement> (AIS_Plane::*)()) &AIS_Plane::Axis2Placement, "Returns the position of the plane's axis2 system identifying the x, y, or z axis and giving the plane a direction in 3D space. An axis2 system is a right-handed coordinate system.");
cls_AIS_Plane.def("TypeOfPlane", (AIS_TypeOfPlane (AIS_Plane::*)()) &AIS_Plane::TypeOfPlane, "Returns the type of plane - xy, yz, xz or unknown.");
cls_AIS_Plane.def("IsXYZPlane", (Standard_Boolean (AIS_Plane::*)()) &AIS_Plane::IsXYZPlane, "Returns the type of plane - xy, yz, or xz.");
cls_AIS_Plane.def("CurrentMode", (Standard_Boolean (AIS_Plane::*)()) &AIS_Plane::CurrentMode, "Returns the non-default current display mode set by SetCurrentMode.");
cls_AIS_Plane.def("SetCurrentMode", (void (AIS_Plane::*)(const Standard_Boolean)) &AIS_Plane::SetCurrentMode, "Allows you to provide settings for a non-default current display mode.", py::arg("theCurrentMode"));
cls_AIS_Plane.def("AcceptDisplayMode", (Standard_Boolean (AIS_Plane::*)(const Standard_Integer) const) &AIS_Plane::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid for planes.", py::arg("aMode"));
cls_AIS_Plane.def("SetContext", (void (AIS_Plane::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_Plane::SetContext, "connection to <aCtx> default drawer implies a recomputation of Frame values.", py::arg("aCtx"));
cls_AIS_Plane.def("TypeOfSensitivity", (Select3D_TypeOfSensitivity (AIS_Plane::*)() const) &AIS_Plane::TypeOfSensitivity, "Returns the type of sensitivity for the plane;");
cls_AIS_Plane.def("SetTypeOfSensitivity", (void (AIS_Plane::*)(Select3D_TypeOfSensitivity)) &AIS_Plane::SetTypeOfSensitivity, "Sets the type of sensitivity for the plane.", py::arg("theTypeOfSensitivity"));
cls_AIS_Plane.def("Compute", (void (AIS_Plane::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Plane::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Plane.def("ComputeSelection", (void (AIS_Plane::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_Plane::ComputeSelection, "None", py::arg("theSelection"), py::arg("theMode"));
cls_AIS_Plane.def("SetColor", (void (AIS_Plane::*)(const Quantity_Color &)) &AIS_Plane::SetColor, "None", py::arg("aColor"));
cls_AIS_Plane.def("UnsetColor", (void (AIS_Plane::*)()) &AIS_Plane::UnsetColor, "None");

// CLASS: AIS_PLANETRIHEDRON
py::class_<AIS_PlaneTrihedron, opencascade::handle<AIS_PlaneTrihedron>, AIS_InteractiveObject> cls_AIS_PlaneTrihedron(mod, "AIS_PlaneTrihedron", "To construct a selectable 2d axis system in a 3d drawing. This can be placed anywhere in the 3d system, and provides a coordinate system for drawing curves and shapes in a plane. There are 3 selection modes: - mode 0 selection of the whole plane 'trihedron' - mode 1 selection of the origin of the plane 'trihedron' - mode 2 selection of the axes. Warning For the presentation of planes and trihedra, the millimetre is default unit of length, and 100 the default value for the representation of the axes. If you modify these dimensions, you must temporarily recover the Drawer object. From inside it, take the Aspects in which the values for length are stocked, for example, PlaneAspect for planes and LineAspect for trihedra. Change these values and recalculate the presentation.");

// Constructors
cls_AIS_PlaneTrihedron.def(py::init<const opencascade::handle<Geom_Plane> &>(), py::arg("aPlane"));

// Methods
cls_AIS_PlaneTrihedron.def_static("get_type_name_", (const char * (*)()) &AIS_PlaneTrihedron::get_type_name, "None");
cls_AIS_PlaneTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PlaneTrihedron::get_type_descriptor, "None");
cls_AIS_PlaneTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::DynamicType, "None");
cls_AIS_PlaneTrihedron.def("Component", (opencascade::handle<Geom_Plane> (AIS_PlaneTrihedron::*)()) &AIS_PlaneTrihedron::Component, "Returns the component specified in SetComponent.");
cls_AIS_PlaneTrihedron.def("SetComponent", (void (AIS_PlaneTrihedron::*)(const opencascade::handle<Geom_Plane> &)) &AIS_PlaneTrihedron::SetComponent, "Creates an instance of the component object aPlane.", py::arg("aPlane"));
cls_AIS_PlaneTrihedron.def("XAxis", (opencascade::handle<AIS_Line> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::XAxis, "Returns the 'XAxis'.");
cls_AIS_PlaneTrihedron.def("YAxis", (opencascade::handle<AIS_Line> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::YAxis, "Returns the 'YAxis'.");
cls_AIS_PlaneTrihedron.def("Position", (opencascade::handle<AIS_Point> (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Position, "Returns the point of origin of the plane trihedron.");
cls_AIS_PlaneTrihedron.def("SetLength", (void (AIS_PlaneTrihedron::*)(const Standard_Real)) &AIS_PlaneTrihedron::SetLength, "Sets the length of the X and Y axes.", py::arg("theLength"));
cls_AIS_PlaneTrihedron.def("GetLength", (Standard_Real (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::GetLength, "Returns the length of X and Y axes.");
cls_AIS_PlaneTrihedron.def("AcceptDisplayMode", (Standard_Boolean (AIS_PlaneTrihedron::*)(const Standard_Integer) const) &AIS_PlaneTrihedron::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid.", py::arg("aMode"));
cls_AIS_PlaneTrihedron.def("Compute", (void (AIS_PlaneTrihedron::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_PlaneTrihedron::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_PlaneTrihedron.def("Signature", (Standard_Integer (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Signature, "None");
cls_AIS_PlaneTrihedron.def("Type", (AIS_KindOfInteractive (AIS_PlaneTrihedron::*)() const) &AIS_PlaneTrihedron::Type, "Returns datum as the type of Interactive Object.");
cls_AIS_PlaneTrihedron.def("SetColor", (void (AIS_PlaneTrihedron::*)(const Quantity_Color &)) &AIS_PlaneTrihedron::SetColor, "Allows you to provide settings for the color aColor.", py::arg("theColor"));
cls_AIS_PlaneTrihedron.def("SetXLabel", (void (AIS_PlaneTrihedron::*)(const TCollection_AsciiString &)) &AIS_PlaneTrihedron::SetXLabel, "None", py::arg("theLabel"));
cls_AIS_PlaneTrihedron.def("SetYLabel", (void (AIS_PlaneTrihedron::*)(const TCollection_AsciiString &)) &AIS_PlaneTrihedron::SetYLabel, "None", py::arg("theLabel"));

// CLASS: AIS_POINT
py::class_<AIS_Point, opencascade::handle<AIS_Point>, AIS_InteractiveObject> cls_AIS_Point(mod, "AIS_Point", "Constructs point datums to be used in construction of composite shapes. The datum is displayed as the plus marker +.");

// Constructors
cls_AIS_Point.def(py::init<const opencascade::handle<Geom_Point> &>(), py::arg("aComponent"));

// Methods
cls_AIS_Point.def_static("get_type_name_", (const char * (*)()) &AIS_Point::get_type_name, "None");
cls_AIS_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Point::get_type_descriptor, "None");
cls_AIS_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Point::*)() const) &AIS_Point::DynamicType, "None");
cls_AIS_Point.def("Signature", (Standard_Integer (AIS_Point::*)() const) &AIS_Point::Signature, "Returns index 1, the default index for a point.");
cls_AIS_Point.def("Type", (AIS_KindOfInteractive (AIS_Point::*)() const) &AIS_Point::Type, "Indicates that a point is a datum.");
cls_AIS_Point.def("Component", (opencascade::handle<Geom_Point> (AIS_Point::*)()) &AIS_Point::Component, "Returns the component specified in SetComponent.");
cls_AIS_Point.def("SetComponent", (void (AIS_Point::*)(const opencascade::handle<Geom_Point> &)) &AIS_Point::SetComponent, "Constructs an instance of the point aComponent.", py::arg("aComponent"));
cls_AIS_Point.def("AcceptDisplayMode", (Standard_Boolean (AIS_Point::*)(const Standard_Integer) const) &AIS_Point::AcceptDisplayMode, "Returns true if the display mode selected is valid for point datums.", py::arg("aMode"));
cls_AIS_Point.def("Compute", (void (AIS_Point::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Point::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Point.def("SetColor", (void (AIS_Point::*)(const Quantity_Color &)) &AIS_Point::SetColor, "Allows you to provide settings for the Color.", py::arg("theColor"));
cls_AIS_Point.def("UnsetColor", (void (AIS_Point::*)()) &AIS_Point::UnsetColor, "Allows you to remove color settings.");
cls_AIS_Point.def("SetMarker", (void (AIS_Point::*)(const Aspect_TypeOfMarker)) &AIS_Point::SetMarker, "Allows you to provide settings for a marker. These include - type of marker, - marker color, - scale factor.", py::arg("aType"));
cls_AIS_Point.def("UnsetMarker", (void (AIS_Point::*)()) &AIS_Point::UnsetMarker, "Removes the marker settings.");
cls_AIS_Point.def("HasMarker", (Standard_Boolean (AIS_Point::*)() const) &AIS_Point::HasMarker, "Returns true if the point datum has a marker.");
cls_AIS_Point.def("Vertex", (TopoDS_Vertex (AIS_Point::*)() const) &AIS_Point::Vertex, "Converts a point into a vertex.");

// CLASS: AIS_POINTCLOUD
py::class_<AIS_PointCloud, opencascade::handle<AIS_PointCloud>, AIS_InteractiveObject> cls_AIS_PointCloud(mod, "AIS_PointCloud", "Interactive object for set of points. The presentation supports two display modes: - Points. - Bounding box for highlighting. Presentation provides selection by bouding box. Selection and consequently highlighting can disabled by setting default selection mode to -1. There will be no way to select object from interactive view. Any calls to AIS_InteractiveContext::AddOrRemoveSelected should be also prohibited, to avoid programmatic highlighting (workaround is setting non-supported hilight mode, e.g. 100);");

// Constructors
cls_AIS_PointCloud.def(py::init<>());

// Methods
cls_AIS_PointCloud.def_static("get_type_name_", (const char * (*)()) &AIS_PointCloud::get_type_name, "None");
cls_AIS_PointCloud.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PointCloud::get_type_descriptor, "None");
cls_AIS_PointCloud.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PointCloud::*)() const) &AIS_PointCloud::DynamicType, "None");
cls_AIS_PointCloud.def("SetPoints", (void (AIS_PointCloud::*)(const opencascade::handle<Graphic3d_ArrayOfPoints> &)) &AIS_PointCloud::SetPoints, "Sets the points from array of points. Method will not copy the input data - array will be stored as handle.", py::arg("thePoints"));
cls_AIS_PointCloud.def("SetPoints", [](AIS_PointCloud &self, const opencascade::handle<TColgp_HArray1OfPnt> & a0) -> void { return self.SetPoints(a0); });
cls_AIS_PointCloud.def("SetPoints", [](AIS_PointCloud &self, const opencascade::handle<TColgp_HArray1OfPnt> & a0, const opencascade::handle<Quantity_HArray1OfColor> & a1) -> void { return self.SetPoints(a0, a1); });
cls_AIS_PointCloud.def("SetPoints", (void (AIS_PointCloud::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, const opencascade::handle<Quantity_HArray1OfColor> &, const opencascade::handle<TColgp_HArray1OfDir> &)) &AIS_PointCloud::SetPoints, "Sets the points with optional colors. The input data will be copied into internal buffer. The input arrays should have equal length, otherwise the presentation will not be computed and displayed.", py::arg("theCoords"), py::arg("theColors"), py::arg("theNormals"));
cls_AIS_PointCloud.def("GetPoints", (const opencascade::handle<Graphic3d_ArrayOfPoints> (AIS_PointCloud::*)() const) &AIS_PointCloud::GetPoints, "Get the points array. Method might be overridden to fill in points array dynamically from application data structures.");
cls_AIS_PointCloud.def("GetBoundingBox", (Bnd_Box (AIS_PointCloud::*)() const) &AIS_PointCloud::GetBoundingBox, "Get bounding box for presentation.");
cls_AIS_PointCloud.def("SetColor", (void (AIS_PointCloud::*)(const Quantity_Color &)) &AIS_PointCloud::SetColor, "Setup custom color. Affects presentation only when no per-point color attribute has been assigned.", py::arg("theColor"));
cls_AIS_PointCloud.def("UnsetColor", (void (AIS_PointCloud::*)()) &AIS_PointCloud::UnsetColor, "Restore default color.");
cls_AIS_PointCloud.def("SetMaterial", (void (AIS_PointCloud::*)(const Graphic3d_MaterialAspect &)) &AIS_PointCloud::SetMaterial, "Setup custom material. Affects presentation only when normals are defined.", py::arg("theMat"));
cls_AIS_PointCloud.def("UnsetMaterial", (void (AIS_PointCloud::*)()) &AIS_PointCloud::UnsetMaterial, "Restore default material.");

// Enums
py::enum_<AIS_PointCloud::DisplayMode>(cls_AIS_PointCloud, "enumDisplayMode", "Display modes supported by this Point Cloud object")
	.value("DM_Points", AIS_PointCloud::DisplayMode::DM_Points)
	.value("DM_BndBox", AIS_PointCloud::DisplayMode::DM_BndBox)
	.export_values();
py::enum_<AIS_PointCloud::SelectionMode>(cls_AIS_PointCloud, "SelectionMode", "Selection modes supported by this Point Cloud object")
	.value("SM_Points", AIS_PointCloud::SelectionMode::SM_Points)
	.value("SM_SubsetOfPoints", AIS_PointCloud::SelectionMode::SM_SubsetOfPoints)
	.value("SM_BndBox", AIS_PointCloud::SelectionMode::SM_BndBox)
	.export_values();

// CLASS: AIS_POINTCLOUDOWNER
py::class_<AIS_PointCloudOwner, opencascade::handle<AIS_PointCloudOwner>, SelectMgr_EntityOwner> cls_AIS_PointCloudOwner(mod, "AIS_PointCloudOwner", "Custom owner for highlighting selected points.");

// Constructors
cls_AIS_PointCloudOwner.def(py::init<const opencascade::handle<AIS_PointCloud> &>(), py::arg("theOrigin"));

// Methods
cls_AIS_PointCloudOwner.def_static("get_type_name_", (const char * (*)()) &AIS_PointCloudOwner::get_type_name, "None");
cls_AIS_PointCloudOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_PointCloudOwner::get_type_descriptor, "None");
cls_AIS_PointCloudOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_PointCloudOwner::*)() const) &AIS_PointCloudOwner::DynamicType, "None");
cls_AIS_PointCloudOwner.def("SelectedPoints", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (AIS_PointCloudOwner::*)() const) &AIS_PointCloudOwner::SelectedPoints, "Return selected points. WARNING! Indexation starts with 0 (shifted by -1 comparing to Graphic3d_ArrayOfPoints::Vertice()).");
cls_AIS_PointCloudOwner.def("DetectedPoints", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (AIS_PointCloudOwner::*)() const) &AIS_PointCloudOwner::DetectedPoints, "Return last detected points. WARNING! Indexation starts with 0 (shifted by -1 comparing to Graphic3d_ArrayOfPoints::Vertice()).");
cls_AIS_PointCloudOwner.def("IsForcedHilight", (Standard_Boolean (AIS_PointCloudOwner::*)() const) &AIS_PointCloudOwner::IsForcedHilight, "Always update dynamic highlighting.");
cls_AIS_PointCloudOwner.def("HilightWithColor", (void (AIS_PointCloudOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_PointCloudOwner::HilightWithColor, "Handle dynamic highlighting.", py::arg("thePrsMgr"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_PointCloudOwner.def("Unhilight", (void (AIS_PointCloudOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_PointCloudOwner::Unhilight, "Removes highlighting.", py::arg("thePrsMgr"), py::arg("theMode"));
cls_AIS_PointCloudOwner.def("Clear", (void (AIS_PointCloudOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_PointCloudOwner::Clear, "Clears presentation.", py::arg("thePrsMgr"), py::arg("theMode"));

// CLASS: AIS_RADIUSDIMENSION
py::class_<AIS_RadiusDimension, opencascade::handle<AIS_RadiusDimension>, AIS_Dimension> cls_AIS_RadiusDimension(mod, "AIS_RadiusDimension", "Radius dimension. Can be constructued: - On generic circle. - On generic circle with user-defined anchor point on that circle. - On generic shape containing geometry that can be measured by diameter dimension: circle wire, arc, circular face, etc. The anchor point is the location of left attachement point of dimension on the circle. It can be user-specified, or computed as middle point on the arc. The radius dimension always lies in the plane of the measured circle. The dimension is considered as invalid if the user-specified anchor point is not lying on the circle, if the radius of the circle is less than Precision::Confusion(). In case if the dimension is built on the arbitrary shape, it can be considered as invalid if the shape does not contain circle geometry.");

// Constructors
cls_AIS_RadiusDimension.def(py::init<const gp_Circ &>(), py::arg("theCircle"));
cls_AIS_RadiusDimension.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("theCircle"), py::arg("theAnchorPoint"));
cls_AIS_RadiusDimension.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_AIS_RadiusDimension.def("Circle", (const gp_Circ & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::Circle, "Returns measured geometry circle.");
cls_AIS_RadiusDimension.def("AnchorPoint", (const gp_Pnt & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::AnchorPoint, "Returns anchor point on circle for radius dimension.");
cls_AIS_RadiusDimension.def("Shape", (const TopoDS_Shape & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::Shape, "Returns the measured shape.");
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const gp_Circ &)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius of the circle. The dimension will become invalid if the radius of the circle is less than Precision::Confusion().", py::arg("theCircle"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", [](AIS_RadiusDimension &self, const gp_Circ & a0, const gp_Pnt & a1) -> void { return self.SetMeasuredGeometry(a0, a1); });
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const gp_Circ &, const gp_Pnt &, const Standard_Boolean)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius of the circle and orient the dimension so the dimension lines attaches to anchor point on the circle. The dimension will become invalid if the radius of the circle is less than Precision::Confusion().", py::arg("theCircle"), py::arg("theAnchorPoint"), py::arg("theHasAnchor"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const TopoDS_Shape &)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"));
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", [](AIS_RadiusDimension &self, const TopoDS_Shape & a0, const gp_Pnt & a1) -> void { return self.SetMeasuredGeometry(a0, a1); });
cls_AIS_RadiusDimension.def("SetMeasuredGeometry", (void (AIS_RadiusDimension::*)(const TopoDS_Shape &, const gp_Pnt &, const Standard_Boolean)) &AIS_RadiusDimension::SetMeasuredGeometry, "Measure radius on the passed shape, if applicable. The dimension will become invalid if the passed shape is not measurable or if measured diameter value is less than Precision::Confusion().", py::arg("theShape"), py::arg("theAnchorPoint"), py::arg("theHasAnchor"));
cls_AIS_RadiusDimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetDisplayUnits, "Returns the display units string.");
cls_AIS_RadiusDimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetModelUnits, "Returns the model units string.");
cls_AIS_RadiusDimension.def("SetDisplayUnits", (void (AIS_RadiusDimension::*)(const TCollection_AsciiString &)) &AIS_RadiusDimension::SetDisplayUnits, "None", py::arg("theUnits"));
cls_AIS_RadiusDimension.def("SetModelUnits", (void (AIS_RadiusDimension::*)(const TCollection_AsciiString &)) &AIS_RadiusDimension::SetModelUnits, "None", py::arg("theUnits"));
cls_AIS_RadiusDimension.def("SetTextPosition", (void (AIS_RadiusDimension::*)(const gp_Pnt &)) &AIS_RadiusDimension::SetTextPosition, "None", py::arg("theTextPos"));
cls_AIS_RadiusDimension.def("GetTextPosition", (const gp_Pnt (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::GetTextPosition, "None");
cls_AIS_RadiusDimension.def_static("get_type_name_", (const char * (*)()) &AIS_RadiusDimension::get_type_name, "None");
cls_AIS_RadiusDimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_RadiusDimension::get_type_descriptor, "None");
cls_AIS_RadiusDimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_RadiusDimension::*)() const) &AIS_RadiusDimension::DynamicType, "None");

// CLASS: AIS_RUBBERBAND
py::class_<AIS_RubberBand, opencascade::handle<AIS_RubberBand>, AIS_InteractiveObject> cls_AIS_RubberBand(mod, "AIS_RubberBand", "Presentation for drawing rubber band selection. It supports rectangle and polygonal selection. It is constructed in 2d overlay. Default configaration is built without filling. For rectangle selection use SetRectangle() method. For polygonal selection use AddPoint() and GetPoints() methods.");

// Constructors
cls_AIS_RubberBand.def(py::init<>());
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine>(), py::arg("theLineColor"), py::arg("theType"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theLineWidth"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Standard_Boolean>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theLineWidth"), py::arg("theIsPolygonClosed"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"), py::arg("theLineWidth"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"), py::arg("theLineWidth"), py::arg("theIsPolygonClosed"));

// Methods
cls_AIS_RubberBand.def_static("get_type_name_", (const char * (*)()) &AIS_RubberBand::get_type_name, "None");
cls_AIS_RubberBand.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_RubberBand::get_type_descriptor, "None");
cls_AIS_RubberBand.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_RubberBand::*)() const) &AIS_RubberBand::DynamicType, "None");
cls_AIS_RubberBand.def("SetRectangle", (void (AIS_RubberBand::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &AIS_RubberBand::SetRectangle, "Sets rectangle bounds.", py::arg("theMinX"), py::arg("theMinY"), py::arg("theMaxX"), py::arg("theMaxY"));
cls_AIS_RubberBand.def("AddPoint", (void (AIS_RubberBand::*)(const Graphic3d_Vec2i &)) &AIS_RubberBand::AddPoint, "Adds last point to the list of points. They are used to build polygon for rubber band.", py::arg("thePoint"));
cls_AIS_RubberBand.def("RemoveLastPoint", (void (AIS_RubberBand::*)()) &AIS_RubberBand::RemoveLastPoint, "Remove last point from the list of points for the rubber band polygon.");
cls_AIS_RubberBand.def("Points", (const NCollection_Sequence<Graphic3d_Vec2i> & (AIS_RubberBand::*)() const) &AIS_RubberBand::Points, "Returns points for the rubber band polygon.");
cls_AIS_RubberBand.def("ClearPoints", (void (AIS_RubberBand::*)()) &AIS_RubberBand::ClearPoints, "Remove all points for the rubber band polygon.");
cls_AIS_RubberBand.def("LineColor", (Quantity_Color (AIS_RubberBand::*)() const) &AIS_RubberBand::LineColor, "Returns the Color attributes.");
cls_AIS_RubberBand.def("SetLineColor", (void (AIS_RubberBand::*)(const Quantity_Color &)) &AIS_RubberBand::SetLineColor, "Sets color of lines for rubber band presentation.", py::arg("theColor"));
cls_AIS_RubberBand.def("FillColor", (Quantity_Color (AIS_RubberBand::*)() const) &AIS_RubberBand::FillColor, "Returns the color of rubber band filling.");
cls_AIS_RubberBand.def("SetFillColor", (void (AIS_RubberBand::*)(const Quantity_Color &)) &AIS_RubberBand::SetFillColor, "Sets color of rubber band filling.", py::arg("theColor"));
cls_AIS_RubberBand.def("SetLineWidth", (void (AIS_RubberBand::*)(const Standard_Real) const) &AIS_RubberBand::SetLineWidth, "Sets width of line for rubber band presentation.", py::arg("theWidth"));
cls_AIS_RubberBand.def("LineWidth", (Standard_Real (AIS_RubberBand::*)() const) &AIS_RubberBand::LineWidth, "Returns width of lines.");
cls_AIS_RubberBand.def("SetLineType", (void (AIS_RubberBand::*)(const Aspect_TypeOfLine)) &AIS_RubberBand::SetLineType, "Sets type of line for rubber band presentation.", py::arg("theType"));
cls_AIS_RubberBand.def("LineType", (Aspect_TypeOfLine (AIS_RubberBand::*)() const) &AIS_RubberBand::LineType, "Returns type of lines.");
cls_AIS_RubberBand.def("SetFillTransparency", (void (AIS_RubberBand::*)(const Standard_Real) const) &AIS_RubberBand::SetFillTransparency, "Sets fill transparency.", py::arg("theValue"));
cls_AIS_RubberBand.def("FillTransparency", (Standard_Real (AIS_RubberBand::*)() const) &AIS_RubberBand::FillTransparency, "Returns fill transparency.");
cls_AIS_RubberBand.def("SetFilling", (void (AIS_RubberBand::*)(const Standard_Boolean)) &AIS_RubberBand::SetFilling, "Enable or disable filling of rubber band.", py::arg("theIsFilling"));
cls_AIS_RubberBand.def("SetFilling", (void (AIS_RubberBand::*)(const Quantity_Color, const Standard_Real)) &AIS_RubberBand::SetFilling, "Enable filling of rubber band with defined parameters.", py::arg("theColor"), py::arg("theTransparency"));
cls_AIS_RubberBand.def("IsFilling", (Standard_Boolean (AIS_RubberBand::*)() const) &AIS_RubberBand::IsFilling, "Returns true if filling of rubber band is enabled.");
cls_AIS_RubberBand.def("IsPolygonClosed", (Standard_Boolean (AIS_RubberBand::*)() const) &AIS_RubberBand::IsPolygonClosed, "Returns true if automatic closing of rubber band is enabled.");
cls_AIS_RubberBand.def("SetPolygonClosed", (void (AIS_RubberBand::*)(Standard_Boolean)) &AIS_RubberBand::SetPolygonClosed, "Automatically create an additional line connecting the first and the last screen points to close the boundary polyline", py::arg("theIsPolygonClosed"));

// TYPEDEF: AIS_SEQUENCEOFDIMENSION
bind_NCollection_Sequence<opencascade::handle<AIS_Relation> >(mod, "AIS_SequenceOfDimension", py::module_local(false));

// TYPEDEF: AIS_SEQUENCEOFINTERACTIVE
bind_NCollection_Sequence<opencascade::handle<AIS_InteractiveObject> >(mod, "AIS_SequenceOfInteractive", py::module_local(false));

// CLASS: AIS_TYPEFILTER
py::class_<AIS_TypeFilter, opencascade::handle<AIS_TypeFilter>, SelectMgr_Filter> cls_AIS_TypeFilter(mod, "AIS_TypeFilter", "Selects Interactive Objects through their types. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it is of the desired type. If the object returns true in each case, it is kept. If not, it is rejected. By default, the interactive object has a None type and a signature of 0. A filter for type specifies a choice of type out of a range at any level enumerated for type or kind. The choice could be for kind of interactive object, of dimension, of unit, or type of axis, plane or attribute. If you want to give a particular type and signature to your Interactive Object, you must redefine two virtual methods: Type and Signature. This filter is used in both Neutral Point and open local contexts. In the Collector viewer, you can only locate Interactive Objects which answer positively to the positioned filters when a local context is open. Warning When you close a local context, all temporary interactive objects are deleted, all selection modes concerning the context are cancelled, and all content filters are emptied.");

// Constructors
cls_AIS_TypeFilter.def(py::init<const AIS_KindOfInteractive>(), py::arg("aGivenKind"));

// Methods
cls_AIS_TypeFilter.def("IsOk", (Standard_Boolean (AIS_TypeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_TypeFilter::IsOk, "Returns False if the transient is not an Interactive Object, or if the type of the Interactive Object is not the same as that stored in the filter.", py::arg("anobj"));
cls_AIS_TypeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_TypeFilter::get_type_name, "None");
cls_AIS_TypeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TypeFilter::get_type_descriptor, "None");
cls_AIS_TypeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TypeFilter::*)() const) &AIS_TypeFilter::DynamicType, "None");

// CLASS: AIS_SIGNATUREFILTER
py::class_<AIS_SignatureFilter, opencascade::handle<AIS_SignatureFilter>, AIS_TypeFilter> cls_AIS_SignatureFilter(mod, "AIS_SignatureFilter", "Selects Interactive Objects through their signatures and types. The signature provides an additional characterization of an object's type, and takes the form of an index. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it has the desired signature. If the object returns true in each case, it is kept. If not, it is rejected. By default, the interactive object has a None type and a signature of 0. If you want to give a particular type and signature to your Interactive Object, you must redefine two virtual methods: Type and Signature. This filter is only used in an open local contexts. In the Collector viewer, you can only locate Interactive Objects which answer positively to the positioned filters when a local context is open. Warning Some signatures have already been used by standard objects delivered in AIS. These include: - signature 0 - Shape - signature 1 - Point - signature 2 - Axis - signature 3 - Trihedron - signature 4 - PlaneTrihedron - signature 5 - Line - signature 6 - Circle - signature 7 - Plane");

// Constructors
cls_AIS_SignatureFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer>(), py::arg("aGivenKind"), py::arg("aGivenSignature"));

// Methods
cls_AIS_SignatureFilter.def("IsOk", (Standard_Boolean (AIS_SignatureFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_SignatureFilter::IsOk, "Returns False if the transient is not an AIS_InteractiveObject. Returns False if the signature of InteractiveObject is not the same as the stored one in the filter...", py::arg("anobj"));
cls_AIS_SignatureFilter.def_static("get_type_name_", (const char * (*)()) &AIS_SignatureFilter::get_type_name, "None");
cls_AIS_SignatureFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_SignatureFilter::get_type_descriptor, "None");
cls_AIS_SignatureFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_SignatureFilter::*)() const) &AIS_SignatureFilter::DynamicType, "None");

// CLASS: AIS_SYMMETRICRELATION
py::class_<AIS_SymmetricRelation, opencascade::handle<AIS_SymmetricRelation>, AIS_Relation> cls_AIS_SymmetricRelation(mod, "AIS_SymmetricRelation", "A framework to display constraints of symmetricity between two or more datum Interactive Objects. A plane serves as the axis of symmetry between the shapes of which the datums are parts.");

// Constructors
cls_AIS_SymmetricRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aSymmTool"), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("aPlane"));

// Methods
cls_AIS_SymmetricRelation.def_static("get_type_name_", (const char * (*)()) &AIS_SymmetricRelation::get_type_name, "None");
cls_AIS_SymmetricRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_SymmetricRelation::get_type_descriptor, "None");
cls_AIS_SymmetricRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_SymmetricRelation::*)() const) &AIS_SymmetricRelation::DynamicType, "None");
cls_AIS_SymmetricRelation.def("IsMovable", (Standard_Boolean (AIS_SymmetricRelation::*)() const) &AIS_SymmetricRelation::IsMovable, "Returns true if the symmetric constraint display is movable.");
cls_AIS_SymmetricRelation.def("SetTool", (void (AIS_SymmetricRelation::*)(const TopoDS_Shape &)) &AIS_SymmetricRelation::SetTool, "Sets the tool aSymmetricTool composed of a first shape, a second shape, and a plane. This tool is initially created at construction time.", py::arg("aSymmetricTool"));
cls_AIS_SymmetricRelation.def("GetTool", (const TopoDS_Shape & (AIS_SymmetricRelation::*)() const) &AIS_SymmetricRelation::GetTool, "Returns the tool composed of a first shape, a second shape, and a plane. This tool is created at construction time.");
cls_AIS_SymmetricRelation.def("Compute", (void (AIS_SymmetricRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_SymmetricRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_TANGENTRELATION
py::class_<AIS_TangentRelation, opencascade::handle<AIS_TangentRelation>, AIS_Relation> cls_AIS_TangentRelation(mod, "AIS_TangentRelation", "A framework to display tangency constraints between two or more Interactive Objects of the datum type. The datums are normally faces or edges.");

// Constructors
cls_AIS_TangentRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"));
cls_AIS_TangentRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Integer>(), py::arg("aFShape"), py::arg("aSShape"), py::arg("aPlane"), py::arg("anExternRef"));

// Methods
cls_AIS_TangentRelation.def_static("get_type_name_", (const char * (*)()) &AIS_TangentRelation::get_type_name, "None");
cls_AIS_TangentRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TangentRelation::get_type_descriptor, "None");
cls_AIS_TangentRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TangentRelation::*)() const) &AIS_TangentRelation::DynamicType, "None");
cls_AIS_TangentRelation.def("ExternRef", (Standard_Integer (AIS_TangentRelation::*)()) &AIS_TangentRelation::ExternRef, "Returns the external reference for tangency. The values are as follows: - 0 - there is no connection; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. This reference is defined at construction time.");
cls_AIS_TangentRelation.def("SetExternRef", (void (AIS_TangentRelation::*)(const Standard_Integer)) &AIS_TangentRelation::SetExternRef, "Sets the external reference for tangency, aRef. The values are as follows: - 0 - there is no connection; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. This reference is initially defined at construction time.", py::arg("aRef"));
cls_AIS_TangentRelation.def("Compute", (void (AIS_TangentRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_TangentRelation::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));

// CLASS: AIS_TEXTLABEL
py::class_<AIS_TextLabel, opencascade::handle<AIS_TextLabel>, AIS_InteractiveObject> cls_AIS_TextLabel(mod, "AIS_TextLabel", "Presentation of the text.");

// Constructors
cls_AIS_TextLabel.def(py::init<>());

// Methods
cls_AIS_TextLabel.def("SetColor", (void (AIS_TextLabel::*)(const Quantity_Color &)) &AIS_TextLabel::SetColor, "Setup color of entire text.", py::arg("theColor"));
cls_AIS_TextLabel.def("SetTransparency", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetTransparency, "Setup transparency within [0, 1] range.", py::arg("theValue"));
cls_AIS_TextLabel.def("UnsetTransparency", (void (AIS_TextLabel::*)()) &AIS_TextLabel::UnsetTransparency, "Removes the transparency setting.");
cls_AIS_TextLabel.def("SetMaterial", (void (AIS_TextLabel::*)(const Graphic3d_MaterialAspect &)) &AIS_TextLabel::SetMaterial, "Material has no effect for text label.", py::arg(""));
cls_AIS_TextLabel.def("SetText", (void (AIS_TextLabel::*)(const TCollection_ExtendedString &)) &AIS_TextLabel::SetText, "Setup text.", py::arg("theText"));
cls_AIS_TextLabel.def("SetPosition", (void (AIS_TextLabel::*)(const gp_Pnt &)) &AIS_TextLabel::SetPosition, "Setup position.", py::arg("thePosition"));
cls_AIS_TextLabel.def("SetHJustification", (void (AIS_TextLabel::*)(const Graphic3d_HorizontalTextAlignment)) &AIS_TextLabel::SetHJustification, "Setup horizontal justification.", py::arg("theHJust"));
cls_AIS_TextLabel.def("SetVJustification", (void (AIS_TextLabel::*)(const Graphic3d_VerticalTextAlignment)) &AIS_TextLabel::SetVJustification, "Setup vertical justification.", py::arg("theVJust"));
cls_AIS_TextLabel.def("SetAngle", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetAngle, "Setup angle.", py::arg("theAngle"));
cls_AIS_TextLabel.def("SetZoomable", (void (AIS_TextLabel::*)(const Standard_Boolean)) &AIS_TextLabel::SetZoomable, "Setup zoomable property.", py::arg("theIsZoomable"));
cls_AIS_TextLabel.def("SetHeight", (void (AIS_TextLabel::*)(const Standard_Real)) &AIS_TextLabel::SetHeight, "Setup height.", py::arg("theHeight"));
cls_AIS_TextLabel.def("SetFontAspect", (void (AIS_TextLabel::*)(const Font_FontAspect)) &AIS_TextLabel::SetFontAspect, "Setup font aspect.", py::arg("theFontAspect"));
cls_AIS_TextLabel.def("SetFont", (void (AIS_TextLabel::*)(Standard_CString)) &AIS_TextLabel::SetFont, "Setup font.", py::arg("theFont"));
cls_AIS_TextLabel.def("SetOrientation3D", (void (AIS_TextLabel::*)(const gp_Ax2 &)) &AIS_TextLabel::SetOrientation3D, "Setup label orientation in the model 3D space.", py::arg("theOrientation"));
cls_AIS_TextLabel.def("UnsetOrientation3D", (void (AIS_TextLabel::*)()) &AIS_TextLabel::UnsetOrientation3D, "Reset label orientation in the model 3D space.");
cls_AIS_TextLabel.def("Position", (const gp_Pnt & (AIS_TextLabel::*)() const) &AIS_TextLabel::Position, "Returns position.");
cls_AIS_TextLabel.def("Orientation3D", (const gp_Ax2 & (AIS_TextLabel::*)() const) &AIS_TextLabel::Orientation3D, "Returns label orientation in the model 3D space.");
cls_AIS_TextLabel.def("HasOrientation3D", (Standard_Boolean (AIS_TextLabel::*)() const) &AIS_TextLabel::HasOrientation3D, "Returns true if the current text placement mode uses text orientation in the model 3D space.");
cls_AIS_TextLabel.def("SetFlipping", (void (AIS_TextLabel::*)(const Standard_Boolean)) &AIS_TextLabel::SetFlipping, "None", py::arg("theIsFlipping"));
cls_AIS_TextLabel.def("HasFlipping", (Standard_Boolean (AIS_TextLabel::*)() const) &AIS_TextLabel::HasFlipping, "None");
cls_AIS_TextLabel.def("SetDisplayType", (void (AIS_TextLabel::*)(const Aspect_TypeOfDisplayText)) &AIS_TextLabel::SetDisplayType, "Define the display type of the text.", py::arg("theDisplayType"));
cls_AIS_TextLabel.def("SetColorSubTitle", (void (AIS_TextLabel::*)(const Quantity_Color &)) &AIS_TextLabel::SetColorSubTitle, "Modifies the colour of the subtitle for the TODT_SUBTITLE TextDisplayType and the colour of backgroubd for the TODT_DEKALE TextDisplayType.", py::arg("theColor"));
cls_AIS_TextLabel.def_static("get_type_name_", (const char * (*)()) &AIS_TextLabel::get_type_name, "None");
cls_AIS_TextLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TextLabel::get_type_descriptor, "None");
cls_AIS_TextLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TextLabel::*)() const) &AIS_TextLabel::DynamicType, "None");

// CLASS: AIS_TEXTUREDSHAPE
py::class_<AIS_TexturedShape, opencascade::handle<AIS_TexturedShape>, AIS_Shape> cls_AIS_TexturedShape(mod, "AIS_TexturedShape", "This class allows to map textures on shapes. Presentations modes AIS_WireFrame (0) and AIS_Shaded (1) behave in the same manner as in AIS_Shape, whilst new modes 2 (bounding box) and 3 (texture mapping) extends it functionality.");

// Constructors
cls_AIS_TexturedShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_AIS_TexturedShape.def("SetTextureFileName", (void (AIS_TexturedShape::*)(const TCollection_AsciiString &)) &AIS_TexturedShape::SetTextureFileName, "Sets the texture source. <theTextureFileName> can specify path to texture image or one of the standard predefined textures. The accepted file types are those used in Image_AlienPixMap with extensions such as rgb, png, jpg and more. To specify the standard predefined texture, the <theTextureFileName> should contain integer - the Graphic3d_NameOfTexture2D enumeration index. Setting texture source using this method resets the source pixmap (if was set previously).", py::arg("theTextureFileName"));
cls_AIS_TexturedShape.def("SetTexturePixMap", (void (AIS_TexturedShape::*)(const opencascade::handle<Image_PixMap> &)) &AIS_TexturedShape::SetTexturePixMap, "Sets the texture source. <theTexturePixMap> specifies image data. Please note that the data should be in Bottom-Up order, the flag of Image_PixMap::IsTopDown() will be ignored by graphic driver. Setting texture source using this method resets the source by filename (if was set previously).", py::arg("theTexturePixMap"));
cls_AIS_TexturedShape.def("TextureMapState", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureMapState, "Returns flag to control texture mapping (for presentation mode 3)");
cls_AIS_TexturedShape.def("SetTextureMapOn", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::SetTextureMapOn, "Enables texture mapping");
cls_AIS_TexturedShape.def("SetTextureMapOff", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::SetTextureMapOff, "Disables texture mapping");
cls_AIS_TexturedShape.def("TextureFile", (Standard_CString (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureFile, "Returns path to the texture file");
cls_AIS_TexturedShape.def("TexturePixMap", (const opencascade::handle<Image_PixMap> & (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TexturePixMap, "Returns the source pixmap for texture map");
cls_AIS_TexturedShape.def("UpdateAttributes", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UpdateAttributes, "Use this method to display the textured shape without recomputing the whole presentation. Use this method when ONLY the texture content has been changed. If other parameters (ie: scale factors, texture origin, texture repeat...) have changed, the whole presentation has to be recomputed:");
cls_AIS_TexturedShape.def("SetColor", (void (AIS_TexturedShape::*)(const Quantity_Color &)) &AIS_TexturedShape::SetColor, "Sets the color.", py::arg("theColor"));
cls_AIS_TexturedShape.def("UnsetColor", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UnsetColor, "Removes settings for the color.");
cls_AIS_TexturedShape.def("SetMaterial", (void (AIS_TexturedShape::*)(const Graphic3d_MaterialAspect &)) &AIS_TexturedShape::SetMaterial, "Sets the material aspect.", py::arg("theAspect"));
cls_AIS_TexturedShape.def("UnsetMaterial", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UnsetMaterial, "Removes settings for material aspect.");
cls_AIS_TexturedShape.def("EnableTextureModulate", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::EnableTextureModulate, "Enables texture modulation");
cls_AIS_TexturedShape.def("DisableTextureModulate", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::DisableTextureModulate, "Disables texture modulation");
cls_AIS_TexturedShape.def("TextureRepeat", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureRepeat, "Returns texture repeat flag");
cls_AIS_TexturedShape.def("URepeat", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::URepeat, "Returns texture repeat U value");
cls_AIS_TexturedShape.def("VRepeat", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::VRepeat, "Returns texture repeat V value");
cls_AIS_TexturedShape.def("SetTextureRepeat", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureRepeat(a0); });
cls_AIS_TexturedShape.def("SetTextureRepeat", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureRepeat(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureRepeat", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureRepeat, "Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1). Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax). If RepeatYN is set to false, texture coordinates are clamped in the range (0,1)x(0,1) of the face.", py::arg("theToRepeat"), py::arg("theURepeat"), py::arg("theVRepeat"));
cls_AIS_TexturedShape.def("TextureOrigin", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureOrigin, "Returns true if texture UV origin has been modified");
cls_AIS_TexturedShape.def("TextureUOrigin", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureUOrigin, "Returns texture origin U position (0.0 by default)");
cls_AIS_TexturedShape.def("TextureVOrigin", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureVOrigin, "Returns texture origin V position (0.0 by default)");
cls_AIS_TexturedShape.def("SetTextureOrigin", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureOrigin(a0); });
cls_AIS_TexturedShape.def("SetTextureOrigin", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureOrigin(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureOrigin", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureOrigin, "Use this method to change the origin of the texture. The texel (0,0) will be mapped to the surface (UOrigin,VOrigin)", py::arg("theToSetTextureOrigin"), py::arg("theUOrigin"), py::arg("theVOrigin"));
cls_AIS_TexturedShape.def("TextureScale", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScale, "Returns true if scale factor should be applied to texture mapping");
cls_AIS_TexturedShape.def("TextureScaleU", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScaleU, "Returns scale factor for U coordinate (1.0 by default)");
cls_AIS_TexturedShape.def("TextureScaleV", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScaleV, "Returns scale factor for V coordinate (1.0 by default)");
cls_AIS_TexturedShape.def("SetTextureScale", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureScale(a0); });
cls_AIS_TexturedShape.def("SetTextureScale", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureScale(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureScale", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureScale, "Use this method to scale the texture (percent of the face). You can specify a scale factor for both U and V. Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat, the texture will appear twice on the face in each direction.", py::arg("theToSetTextureScale"), py::arg("theScaleU"), py::arg("theScaleV"));
cls_AIS_TexturedShape.def("ShowTriangles", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::ShowTriangles, "Returns true if displaying of triangles is requested");
cls_AIS_TexturedShape.def("ShowTriangles", (void (AIS_TexturedShape::*)(const Standard_Boolean)) &AIS_TexturedShape::ShowTriangles, "Use this method to show the triangulation of the shape (for debugging etc.).", py::arg("theToShowTriangles"));
cls_AIS_TexturedShape.def("TextureModulate", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureModulate, "Returns true if texture color modulation is turned on");
cls_AIS_TexturedShape.def("AcceptDisplayMode", (Standard_Boolean (AIS_TexturedShape::*)(const Standard_Integer) const) &AIS_TexturedShape::AcceptDisplayMode, "Return true if specified display mode is supported (extends AIS_Shape with Display Mode 3).", py::arg("theMode"));
cls_AIS_TexturedShape.def_static("get_type_name_", (const char * (*)()) &AIS_TexturedShape::get_type_name, "None");
cls_AIS_TexturedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TexturedShape::get_type_descriptor, "None");
cls_AIS_TexturedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TexturedShape::*)() const) &AIS_TexturedShape::DynamicType, "None");

// CLASS: AIS_TRIANGULATION
py::class_<AIS_Triangulation, opencascade::handle<AIS_Triangulation>, AIS_InteractiveObject> cls_AIS_Triangulation(mod, "AIS_Triangulation", "Interactive object that draws data from Poly_Triangulation, optionally with colors associated with each triangulation vertex. For maximum efficiency colors are represented as 32-bit integers instead of classic Quantity_Color values. Interactive selection of triangles and vertices is not yet implemented.");

// Constructors
cls_AIS_Triangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("aTriangulation"));

// Methods
cls_AIS_Triangulation.def_static("get_type_name_", (const char * (*)()) &AIS_Triangulation::get_type_name, "None");
cls_AIS_Triangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Triangulation::get_type_descriptor, "None");
cls_AIS_Triangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Triangulation::*)() const) &AIS_Triangulation::DynamicType, "None");
cls_AIS_Triangulation.def("SetColors", (void (AIS_Triangulation::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &AIS_Triangulation::SetColors, "Set the color for each node. Each 32-bit color is Alpha << 24 + Blue << 16 + Green << 8 + Red Order of color components is essential for further usage by OpenGL", py::arg("aColor"));
cls_AIS_Triangulation.def("GetColors", (opencascade::handle<TColStd_HArray1OfInteger> (AIS_Triangulation::*)() const) &AIS_Triangulation::GetColors, "Get the color for each node. Each 32-bit color is Alpha << 24 + Blue << 16 + Green << 8 + Red");
cls_AIS_Triangulation.def("HasVertexColors", (Standard_Boolean (AIS_Triangulation::*)() const) &AIS_Triangulation::HasVertexColors, "Returns true if triangulation has vertex colors.");
cls_AIS_Triangulation.def("SetTriangulation", (void (AIS_Triangulation::*)(const opencascade::handle<Poly_Triangulation> &)) &AIS_Triangulation::SetTriangulation, "None", py::arg("aTriangulation"));
cls_AIS_Triangulation.def("GetTriangulation", (opencascade::handle<Poly_Triangulation> (AIS_Triangulation::*)() const) &AIS_Triangulation::GetTriangulation, "Returns Poly_Triangulation .");
cls_AIS_Triangulation.def("SetTransparency", [](AIS_Triangulation &self) -> void { return self.SetTransparency(); });
cls_AIS_Triangulation.def("SetTransparency", (void (AIS_Triangulation::*)(const Standard_Real)) &AIS_Triangulation::SetTransparency, "Sets the value aValue for transparency in the reconstructed compound shape.", py::arg("aValue"));
cls_AIS_Triangulation.def("UnsetTransparency", (void (AIS_Triangulation::*)()) &AIS_Triangulation::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");

// CLASS: AIS_TRIHEDRON
py::class_<AIS_Trihedron, opencascade::handle<AIS_Trihedron>, AIS_InteractiveObject> cls_AIS_Trihedron(mod, "AIS_Trihedron", "Create a selectable trihedron The trihedron includes 1 origin, 3 axes and 3 labels. Default text of labels are 'X', 'Y', 'Z'. Color of origin and any axis, color of arrows and labels may be changed. Visual presentation might be shown in two, shaded and wireframe modes, wireframe by default). There are 4 modes of selection: - AIS_TrihedronSelectionMode_EntireObject to select trihedron, priority = 1 - AIS_TrihedronSelectionMode_Origin to select its origin, priority = 5 - AIS_TrihedronSelectionMode_Axes to select its axis, priority = 3 - AIS_TrihedronSelectionMode_MainPlanes to select its planes, priority = 2");

// Constructors
cls_AIS_Trihedron.def(py::init<const opencascade::handle<Geom_Axis2Placement> &>(), py::arg("theComponent"));

// Methods
cls_AIS_Trihedron.def_static("get_type_name_", (const char * (*)()) &AIS_Trihedron::get_type_name, "None");
cls_AIS_Trihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Trihedron::get_type_descriptor, "None");
cls_AIS_Trihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Trihedron::*)() const) &AIS_Trihedron::DynamicType, "None");
cls_AIS_Trihedron.def("SetDatumDisplayMode", (void (AIS_Trihedron::*)(Prs3d_DatumMode)) &AIS_Trihedron::SetDatumDisplayMode, "Sets Shading or Wireframe display mode, triangle or segment graphic group is used relatively.", py::arg("theMode"));
cls_AIS_Trihedron.def("DatumDisplayMode", (Prs3d_DatumMode (AIS_Trihedron::*)() const) &AIS_Trihedron::DatumDisplayMode, "Returns datum display mode.");
cls_AIS_Trihedron.def("Component", (const opencascade::handle<Geom_Axis2Placement> & (AIS_Trihedron::*)() const) &AIS_Trihedron::Component, "Returns the right-handed coordinate system set in SetComponent.");
cls_AIS_Trihedron.def("SetComponent", (void (AIS_Trihedron::*)(const opencascade::handle<Geom_Axis2Placement> &)) &AIS_Trihedron::SetComponent, "Constructs the right-handed coordinate system aComponent.", py::arg("theComponent"));
cls_AIS_Trihedron.def("HasOwnSize", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasOwnSize, "Returns true if the trihedron object has a size other than the default size of 100 mm. along each axis.");
cls_AIS_Trihedron.def("SetSize", (void (AIS_Trihedron::*)(const Standard_Real)) &AIS_Trihedron::SetSize, "Sets the size aValue for the trihedron object. The default value is 100 mm.", py::arg("theValue"));
cls_AIS_Trihedron.def("UnsetSize", (void (AIS_Trihedron::*)()) &AIS_Trihedron::UnsetSize, "Removes any non-default settings for size of this trihedron object. If the object has 1 color, the default size of the drawer is reproduced, otherwise DatumAspect becomes null.");
cls_AIS_Trihedron.def("Size", (Standard_Real (AIS_Trihedron::*)() const) &AIS_Trihedron::Size, "None");
cls_AIS_Trihedron.def("AcceptDisplayMode", (Standard_Boolean (AIS_Trihedron::*)(const Standard_Integer) const) &AIS_Trihedron::AcceptDisplayMode, "Returns true if the display mode selected, aMode, is valid for trihedron datums.", py::arg("theMode"));
cls_AIS_Trihedron.def("Signature", (Standard_Integer (AIS_Trihedron::*)() const) &AIS_Trihedron::Signature, "Returns index 3, selection of the planes XOY, YOZ, XOZ.");
cls_AIS_Trihedron.def("Type", (AIS_KindOfInteractive (AIS_Trihedron::*)() const) &AIS_Trihedron::Type, "Indicates that the type of Interactive Object is datum.");
cls_AIS_Trihedron.def("SetColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetColor, "Sets the color theColor for this trihedron object, it changes color of axes.", py::arg("theColor"));
cls_AIS_Trihedron.def("SetTextColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetTextColor, "Sets color of label of trihedron axes.", py::arg("theColor"));
cls_AIS_Trihedron.def("HasTextColor", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasTextColor, "Returns true if trihedron has own text color");
cls_AIS_Trihedron.def("TextColor", (Quantity_Color (AIS_Trihedron::*)() const) &AIS_Trihedron::TextColor, "Returns trihedron text color");
cls_AIS_Trihedron.def("SetArrowColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetArrowColor, "Sets color of arrow of trihedron axes. Used only in wireframe mode", py::arg("theColor"));
cls_AIS_Trihedron.def("HasArrowColor", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::HasArrowColor, "Returns true if trihedron has own arrow color");
cls_AIS_Trihedron.def("ArrowColor", (Quantity_Color (AIS_Trihedron::*)() const) &AIS_Trihedron::ArrowColor, "Returns trihedron arrow color");
cls_AIS_Trihedron.def("UnsetColor", (void (AIS_Trihedron::*)()) &AIS_Trihedron::UnsetColor, "Removes the settings for color.");
cls_AIS_Trihedron.def("SetDatumPartColor", (void (AIS_Trihedron::*)(const Prs3d_DatumParts, const Quantity_Color &)) &AIS_Trihedron::SetDatumPartColor, "Sets color of datum part: origin or some of trihedron axes. If presentation is shading mode, this color is set for both sides of facing model", py::arg("thePart"), py::arg("theColor"));
cls_AIS_Trihedron.def("DatumPartColor", (Quantity_Color (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::DatumPartColor, "Returns color of datum part: origin or some of trihedron axes.", py::arg("thePart"));
cls_AIS_Trihedron.def("SetOriginColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetOriginColor, "Sets color of origin. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetXAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetXAxisColor, "Sets color of x-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetYAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetYAxisColor, "Sets color of y-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("SetAxisColor", (void (AIS_Trihedron::*)(const Quantity_Color &)) &AIS_Trihedron::SetAxisColor, "Sets color of z-axis. Standard_DEPRECATED('This method is deprecated - SetColor() should be called instead')", py::arg("theColor"));
cls_AIS_Trihedron.def("ToDrawArrows", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::ToDrawArrows, "Returns true if arrows are to be drawn");
cls_AIS_Trihedron.def("SetDrawArrows", (void (AIS_Trihedron::*)(const Standard_Boolean)) &AIS_Trihedron::SetDrawArrows, "Sets whether to draw the arrows in visualization", py::arg("theToDraw"));
cls_AIS_Trihedron.def("SetSelectionPriority", (void (AIS_Trihedron::*)(Prs3d_DatumParts, Standard_Integer)) &AIS_Trihedron::SetSelectionPriority, "Sets priority of selection for owner of the given type", py::arg("thePart"), py::arg("thePriority"));
cls_AIS_Trihedron.def("SelectionPriority", (Standard_Integer (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::SelectionPriority, "Sets priority of selection for owner of the given type", py::arg("thePart"));
cls_AIS_Trihedron.def("SetLabel", (void (AIS_Trihedron::*)(const Prs3d_DatumParts, const TCollection_ExtendedString &)) &AIS_Trihedron::SetLabel, "Sets text label for trihedron axis. Parameter thePart should be XAxis, YAxis or ZAxis", py::arg("thePart"), py::arg("thePriority"));
cls_AIS_Trihedron.def("Label", (const TCollection_ExtendedString & (AIS_Trihedron::*)(Prs3d_DatumParts)) &AIS_Trihedron::Label, "Returns text of axis. Parameter thePart should be XAxis, YAxis or ZAxis", py::arg("thePart"));
cls_AIS_Trihedron.def("IsAutoHilight", (Standard_Boolean (AIS_Trihedron::*)() const) &AIS_Trihedron::IsAutoHilight, "Disables auto highlighting to use HilightSelected() and HilightOwnerWithColor() overridden methods.");
cls_AIS_Trihedron.def("ClearSelected", (void (AIS_Trihedron::*)()) &AIS_Trihedron::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw ).");
cls_AIS_Trihedron.def("HilightSelected", (void (AIS_Trihedron::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &AIS_Trihedron::HilightSelected, "Method which draws selected owners ( for fast presentation draw ).", py::arg("thePM"), py::arg("theOwners"));
cls_AIS_Trihedron.def("HilightOwnerWithColor", (void (AIS_Trihedron::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_Trihedron::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw ).", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));

// CLASS: AIS_TRIHEDRONOWNER
py::class_<AIS_TrihedronOwner, opencascade::handle<AIS_TrihedronOwner>, SelectMgr_EntityOwner> cls_AIS_TrihedronOwner(mod, "AIS_TrihedronOwner", "Entity owner for selection management of AIS_Trihedron object.");

// Constructors
cls_AIS_TrihedronOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Prs3d_DatumParts, const Standard_Integer>(), py::arg("theSelObject"), py::arg("theDatumPart"), py::arg("thePriority"));

// Methods
cls_AIS_TrihedronOwner.def_static("get_type_name_", (const char * (*)()) &AIS_TrihedronOwner::get_type_name, "None");
cls_AIS_TrihedronOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TrihedronOwner::get_type_descriptor, "None");
cls_AIS_TrihedronOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TrihedronOwner::*)() const) &AIS_TrihedronOwner::DynamicType, "None");
cls_AIS_TrihedronOwner.def("DatumPart", (Prs3d_DatumParts (AIS_TrihedronOwner::*)() const) &AIS_TrihedronOwner::DatumPart, "Returns the datum part identifier.");
cls_AIS_TrihedronOwner.def("HilightWithColor", (void (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &AIS_TrihedronOwner::HilightWithColor, "Highlights selectable object's presentation.", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
cls_AIS_TrihedronOwner.def("IsHilighted", (Standard_Boolean (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const) &AIS_TrihedronOwner::IsHilighted, "Returns true if the presentation manager thePM highlights selections corresponding to the selection mode aMode.", py::arg("thePM"), py::arg("theMode"));
cls_AIS_TrihedronOwner.def("Unhilight", (void (AIS_TrihedronOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &AIS_TrihedronOwner::Unhilight, "Removes highlighting from the owner of a detected selectable object in the presentation manager thePM.", py::arg("thePM"), py::arg("theMode"));

// CLASS: AIS_VIEWINPUTBUFFER
py::class_<AIS_ViewInputBuffer> cls_AIS_ViewInputBuffer(mod, "AIS_ViewInputBuffer", "Auxiliary structure defining viewer events");

// Constructors
cls_AIS_ViewInputBuffer.def(py::init<>());

// Fields
cls_AIS_ViewInputBuffer.def_readwrite("IsNewGesture", &AIS_ViewInputBuffer::IsNewGesture, "transition from one action to another");
cls_AIS_ViewInputBuffer.def_readwrite("ZoomActions", &AIS_ViewInputBuffer::ZoomActions, "the queue with zoom actions");
cls_AIS_ViewInputBuffer.def_readwrite("Orientation", &AIS_ViewInputBuffer::Orientation, "None");
cls_AIS_ViewInputBuffer.def_readwrite("MoveTo", &AIS_ViewInputBuffer::MoveTo, "None");
cls_AIS_ViewInputBuffer.def_readwrite("Selection", &AIS_ViewInputBuffer::Selection, "None");
cls_AIS_ViewInputBuffer.def_readwrite("Panning", &AIS_ViewInputBuffer::Panning, "None");
cls_AIS_ViewInputBuffer.def_readwrite("Dragging", &AIS_ViewInputBuffer::Dragging, "None");
cls_AIS_ViewInputBuffer.def_readwrite("OrbitRotation", &AIS_ViewInputBuffer::OrbitRotation, "None");
cls_AIS_ViewInputBuffer.def_readwrite("ViewRotation", &AIS_ViewInputBuffer::ViewRotation, "None");
cls_AIS_ViewInputBuffer.def_readwrite("ZRotate", &AIS_ViewInputBuffer::ZRotate, "None");

// Methods
cls_AIS_ViewInputBuffer.def("Reset", (void (AIS_ViewInputBuffer::*)()) &AIS_ViewInputBuffer::Reset, "Reset events buffer.");

// CLASS: AIS_WALKPART
py::class_<AIS_WalkPart> cls_AIS_WalkPart(mod, "AIS_WalkPart", "Walking value.");

// Constructors
cls_AIS_WalkPart.def(py::init<>());

// Fields
cls_AIS_WalkPart.def_readwrite("Value", &AIS_WalkPart::Value, "value");
cls_AIS_WalkPart.def_readwrite("Pressure", &AIS_WalkPart::Pressure, "key pressure");
cls_AIS_WalkPart.def_readwrite("Duration", &AIS_WalkPart::Duration, "duration");

// Methods
cls_AIS_WalkPart.def("IsEmpty", (bool (AIS_WalkPart::*)() const) &AIS_WalkPart::IsEmpty, "Return TRUE if delta is empty.");

// CLASS: AIS_WALKDELTA
py::class_<AIS_WalkDelta> cls_AIS_WalkDelta(mod, "AIS_WalkDelta", "Walking values.");

// Constructors
cls_AIS_WalkDelta.def(py::init<>());

// Methods
cls_AIS_WalkDelta.def("__getitem__", (const AIS_WalkPart & (AIS_WalkDelta::*)(AIS_WalkTranslation) const) &AIS_WalkDelta::operator[], py::is_operator(), "Return translation component.", py::arg("thePart"));
cls_AIS_WalkDelta.def("__getitem__", (AIS_WalkPart & (AIS_WalkDelta::*)(AIS_WalkTranslation)) &AIS_WalkDelta::operator[], py::is_operator(), "Return translation component.", py::arg("thePart"));
cls_AIS_WalkDelta.def("__getitem__", (const AIS_WalkPart & (AIS_WalkDelta::*)(AIS_WalkRotation) const) &AIS_WalkDelta::operator[], py::is_operator(), "Return rotation component.", py::arg("thePart"));
cls_AIS_WalkDelta.def("__getitem__", (AIS_WalkPart & (AIS_WalkDelta::*)(AIS_WalkRotation)) &AIS_WalkDelta::operator[], py::is_operator(), "Return rotation component.", py::arg("thePart"));
cls_AIS_WalkDelta.def("IsJumping", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::IsJumping, "Return jumping state.");
cls_AIS_WalkDelta.def("SetJumping", (void (AIS_WalkDelta::*)(bool)) &AIS_WalkDelta::SetJumping, "Set jumping state.", py::arg("theIsJumping"));
cls_AIS_WalkDelta.def("IsCrouching", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::IsCrouching, "Return crouching state.");
cls_AIS_WalkDelta.def("SetCrouching", (void (AIS_WalkDelta::*)(bool)) &AIS_WalkDelta::SetCrouching, "Set crouching state.", py::arg("theIsCrouching"));
cls_AIS_WalkDelta.def("IsRunning", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::IsRunning, "Return running state.");
cls_AIS_WalkDelta.def("SetRunning", (void (AIS_WalkDelta::*)(bool)) &AIS_WalkDelta::SetRunning, "Set running state.", py::arg("theIsRunning"));
cls_AIS_WalkDelta.def("IsEmpty", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::IsEmpty, "Return TRUE when both Rotation and Translation deltas are empty.");
cls_AIS_WalkDelta.def("ToMove", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::ToMove, "Return TRUE if translation delta is defined.");
cls_AIS_WalkDelta.def("ToRotate", (bool (AIS_WalkDelta::*)() const) &AIS_WalkDelta::ToRotate, "Return TRUE if rotation delta is defined.");

// CLASS: AIS_VIEWCONTROLLER
py::class_<AIS_ViewController> cls_AIS_ViewController(mod, "AIS_ViewController", "Auxiliary structure for handling viewer events between GUI and Rendering threads.");

// Constructors
cls_AIS_ViewController.def(py::init<>());

// Methods
cls_AIS_ViewController.def("InputBuffer", (const AIS_ViewInputBuffer & (AIS_ViewController::*)(AIS_ViewInputBufferType) const) &AIS_ViewController::InputBuffer, "Return input buffer.", py::arg("theType"));
cls_AIS_ViewController.def("ChangeInputBuffer", (AIS_ViewInputBuffer & (AIS_ViewController::*)(AIS_ViewInputBufferType)) &AIS_ViewController::ChangeInputBuffer, "Return input buffer.", py::arg("theType"));
cls_AIS_ViewController.def("ViewAnimation", (const opencascade::handle<AIS_AnimationCamera> & (AIS_ViewController::*)() const) &AIS_ViewController::ViewAnimation, "Return view animation; empty (but not NULL) animation by default.");
cls_AIS_ViewController.def("SetViewAnimation", (void (AIS_ViewController::*)(const opencascade::handle<AIS_AnimationCamera> &)) &AIS_ViewController::SetViewAnimation, "Set view animation to be handled within handleViewRedraw().", py::arg("theAnimation"));
cls_AIS_ViewController.def("AbortViewAnimation", (void (AIS_ViewController::*)()) &AIS_ViewController::AbortViewAnimation, "Interrupt active view animation.");
cls_AIS_ViewController.def("RotationMode", (AIS_RotationMode (AIS_ViewController::*)() const) &AIS_ViewController::RotationMode, "Return camera rotation mode, AIS_RotationMode_BndBoxActive by default.");
cls_AIS_ViewController.def("SetRotationMode", (void (AIS_ViewController::*)(AIS_RotationMode)) &AIS_ViewController::SetRotationMode, "Set camera rotation mode.", py::arg("theMode"));
cls_AIS_ViewController.def("NavigationMode", (AIS_NavigationMode (AIS_ViewController::*)() const) &AIS_ViewController::NavigationMode, "Return camera navigation mode; AIS_NavigationMode_Orbit by default.");
cls_AIS_ViewController.def("SetNavigationMode", (void (AIS_ViewController::*)(AIS_NavigationMode)) &AIS_ViewController::SetNavigationMode, "Set camera navigation mode.", py::arg("theMode"));
cls_AIS_ViewController.def("MouseAcceleration", (float (AIS_ViewController::*)() const) &AIS_ViewController::MouseAcceleration, "Return mouse input acceleration ratio in First Person mode; 1.0 by default.");
cls_AIS_ViewController.def("SetMouseAcceleration", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetMouseAcceleration, "Set mouse input acceleration ratio.", py::arg("theRatio"));
cls_AIS_ViewController.def("OrbitAcceleration", (float (AIS_ViewController::*)() const) &AIS_ViewController::OrbitAcceleration, "Return orbit rotation acceleration ratio; 1.0 by default.");
cls_AIS_ViewController.def("SetOrbitAcceleration", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetOrbitAcceleration, "Set orbit rotation acceleration ratio.", py::arg("theRatio"));
cls_AIS_ViewController.def("ToShowPanAnchorPoint", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToShowPanAnchorPoint, "Return TRUE if panning anchor point within perspective projection should be displayed in 3D Viewer; TRUE by default.");
cls_AIS_ViewController.def("SetShowPanAnchorPoint", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetShowPanAnchorPoint, "Set if panning anchor point within perspective projection should be displayed in 3D Viewer.", py::arg("theToShow"));
cls_AIS_ViewController.def("ToShowRotateCenter", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToShowRotateCenter, "Return TRUE if rotation point should be displayed in 3D Viewer; TRUE by default.");
cls_AIS_ViewController.def("SetShowRotateCenter", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetShowRotateCenter, "Set if rotation point should be displayed in 3D Viewer.", py::arg("theToShow"));
cls_AIS_ViewController.def("ToLockOrbitZUp", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToLockOrbitZUp, "Return TRUE if camera up orientation within AIS_NavigationMode_Orbit rotation mode should be forced Z up; FALSE by default.");
cls_AIS_ViewController.def("SetLockOrbitZUp", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetLockOrbitZUp, "Set if camera up orientation within AIS_NavigationMode_Orbit rotation mode should be forced Z up.", py::arg("theToForceUp"));
cls_AIS_ViewController.def("ToAllowTouchZRotation", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowTouchZRotation, "Return TRUE if z-rotation via two-touches gesture is enabled; FALSE by default.");
cls_AIS_ViewController.def("SetAllowTouchZRotation", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowTouchZRotation, "Set if z-rotation via two-touches gesture is enabled.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowRotation", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowRotation, "Return TRUE if camera rotation is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowRotation", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowRotation, "Set if camera rotation is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowPanning", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowPanning, "Return TRUE if panning is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowPanning", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowPanning, "Set if panning is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowZooming", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowZooming, "Return TRUE if zooming is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowZooming", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowZooming, "Set if zooming is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowZFocus", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowZFocus, "Return TRUE if ZFocus change is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowZFocus", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowZFocus, "Set if ZFocus change is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowHighlight", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowHighlight, "Return TRUE if dynamic highlight on mouse move is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowHighlight", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowHighlight, "Set if dragging object is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToAllowDragging", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToAllowDragging, "Return TRUE if dragging object is allowed; TRUE by default.");
cls_AIS_ViewController.def("SetAllowDragging", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetAllowDragging, "Set if dynamic highlight on mouse move is allowed.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToStickToRayOnZoom", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToStickToRayOnZoom, "Return TRUE if picked point should be projected to picking ray on zooming at point; TRUE by default.");
cls_AIS_ViewController.def("SetStickToRayOnZoom", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetStickToRayOnZoom, "Set if picked point should be projected to picking ray on zooming at point.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToStickToRayOnRotation", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToStickToRayOnRotation, "Return TRUE if picked point should be projected to picking ray on rotating around point; TRUE by default.");
cls_AIS_ViewController.def("SetStickToRayOnRotation", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetStickToRayOnRotation, "Set if picked point should be projected to picking ray on rotating around point.", py::arg("theToEnable"));
cls_AIS_ViewController.def("ToInvertPitch", (bool (AIS_ViewController::*)() const) &AIS_ViewController::ToInvertPitch, "Return TRUE if pitch direction should be inverted while processing Aspect_VKey_NavLookUp/Aspect_VKey_NavLookDown; FALSE by default.");
cls_AIS_ViewController.def("SetInvertPitch", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::SetInvertPitch, "Set flag inverting pitch direction.", py::arg("theToInvert"));
cls_AIS_ViewController.def("WalkSpeedAbsolute", (float (AIS_ViewController::*)() const) &AIS_ViewController::WalkSpeedAbsolute, "Return normal walking speed, in m/s; 1.5 by default.");
cls_AIS_ViewController.def("SetWalkSpeedAbsolute", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetWalkSpeedAbsolute, "Set normal walking speed, in m/s; 1.5 by default.", py::arg("theSpeed"));
cls_AIS_ViewController.def("WalkSpeedRelative", (float (AIS_ViewController::*)() const) &AIS_ViewController::WalkSpeedRelative, "Return walking speed relative to scene bounding box; 0.1 by default.");
cls_AIS_ViewController.def("SetWalkSpeedRelative", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetWalkSpeedRelative, "Set walking speed relative to scene bounding box.", py::arg("theFactor"));
cls_AIS_ViewController.def("ThrustSpeed", (float (AIS_ViewController::*)() const) &AIS_ViewController::ThrustSpeed, "Return active thrust value; 0.0f by default.");
cls_AIS_ViewController.def("SetThrustSpeed", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetThrustSpeed, "Set active thrust value.", py::arg("theSpeed"));
cls_AIS_ViewController.def("HasPreviousMoveTo", (bool (AIS_ViewController::*)() const) &AIS_ViewController::HasPreviousMoveTo, "Return TRUE if previous position of MoveTo has been defined.");
cls_AIS_ViewController.def("PreviousMoveTo", (const Graphic3d_Vec2i & (AIS_ViewController::*)() const) &AIS_ViewController::PreviousMoveTo, "Return previous position of MoveTo event in 3D viewer.");
cls_AIS_ViewController.def("ResetPreviousMoveTo", (void (AIS_ViewController::*)()) &AIS_ViewController::ResetPreviousMoveTo, "Reset previous position of MoveTo.");
cls_AIS_ViewController.def("Keys", (const Aspect_VKeySet & (AIS_ViewController::*)() const) &AIS_ViewController::Keys, "Return keyboard state.");
cls_AIS_ViewController.def("ChangeKeys", (Aspect_VKeySet & (AIS_ViewController::*)()) &AIS_ViewController::ChangeKeys, "Return keyboard state.");
cls_AIS_ViewController.def("KeyDown", [](AIS_ViewController &self, Aspect_VKey a0, double a1) -> void { return self.KeyDown(a0, a1); });
cls_AIS_ViewController.def("KeyDown", (void (AIS_ViewController::*)(Aspect_VKey, double, double)) &AIS_ViewController::KeyDown, "Press key.", py::arg("theKey"), py::arg("theTime"), py::arg("thePressure"));
cls_AIS_ViewController.def("KeyUp", (void (AIS_ViewController::*)(Aspect_VKey, double)) &AIS_ViewController::KeyUp, "Release key.", py::arg("theKey"), py::arg("theTime"));
cls_AIS_ViewController.def("KeyFromAxis", (void (AIS_ViewController::*)(Aspect_VKey, Aspect_VKey, double, double)) &AIS_ViewController::KeyFromAxis, "Simulate key up/down events from axis value.", py::arg("theNegative"), py::arg("thePositive"), py::arg("theTime"), py::arg("thePressure"));
cls_AIS_ViewController.def("FetchNavigationKeys", (AIS_WalkDelta (AIS_ViewController::*)(Standard_Real, Standard_Real)) &AIS_ViewController::FetchNavigationKeys, "Fetch active navigation actions.", py::arg("theCrouchRatio"), py::arg("theRunRatio"));
cls_AIS_ViewController.def("MouseGestureMap", (const AIS_MouseGestureMap & (AIS_ViewController::*)() const) &AIS_ViewController::MouseGestureMap, "Return map defining mouse gestures.");
cls_AIS_ViewController.def("ChangeMouseGestureMap", (AIS_MouseGestureMap & (AIS_ViewController::*)()) &AIS_ViewController::ChangeMouseGestureMap, "Return map defining mouse gestures.");
cls_AIS_ViewController.def("MouseDoubleClickInterval", (double (AIS_ViewController::*)() const) &AIS_ViewController::MouseDoubleClickInterval, "Return double click interval in seconds; 0.4 by default.");
cls_AIS_ViewController.def("SetMouseDoubleClickInterval", (void (AIS_ViewController::*)(double)) &AIS_ViewController::SetMouseDoubleClickInterval, "Set double click interval in seconds.", py::arg("theSeconds"));
cls_AIS_ViewController.def("SelectInViewer", [](AIS_ViewController &self, const Graphic3d_Vec2i & a0) -> void { return self.SelectInViewer(a0); });
cls_AIS_ViewController.def("SelectInViewer", (void (AIS_ViewController::*)(const Graphic3d_Vec2i &, const bool)) &AIS_ViewController::SelectInViewer, "Perform selection in 3D viewer. This method is expected to be called from UI thread.", py::arg("thePnt"), py::arg("theIsXOR"));
cls_AIS_ViewController.def("SelectInViewer", [](AIS_ViewController &self, const NCollection_Sequence<Graphic3d_Vec2i> & a0) -> void { return self.SelectInViewer(a0); });
cls_AIS_ViewController.def("SelectInViewer", (void (AIS_ViewController::*)(const NCollection_Sequence<Graphic3d_Vec2i> &, const bool)) &AIS_ViewController::SelectInViewer, "Perform selection in 3D viewer. This method is expected to be called from UI thread.", py::arg("thePnts"), py::arg("theIsXOR"));
cls_AIS_ViewController.def("UpdateRubberBand", [](AIS_ViewController &self, const Graphic3d_Vec2i & a0, const Graphic3d_Vec2i & a1) -> void { return self.UpdateRubberBand(a0, a1); });
cls_AIS_ViewController.def("UpdateRubberBand", (void (AIS_ViewController::*)(const Graphic3d_Vec2i &, const Graphic3d_Vec2i &, const bool)) &AIS_ViewController::UpdateRubberBand, "Update rectangle selection tool. This method is expected to be called from UI thread.", py::arg("thePntFrom"), py::arg("thePntTo"), py::arg("theIsXOR"));
cls_AIS_ViewController.def("UpdatePolySelection", (void (AIS_ViewController::*)(const Graphic3d_Vec2i &, bool)) &AIS_ViewController::UpdatePolySelection, "Update polygonal selection tool. This method is expected to be called from UI thread.", py::arg("thePnt"), py::arg("theToAppend"));
cls_AIS_ViewController.def("UpdateZoom", (bool (AIS_ViewController::*)(const Aspect_ScrollDelta &)) &AIS_ViewController::UpdateZoom, "Update zoom event (e.g. from mouse scroll). This method is expected to be called from UI thread.", py::arg("theDelta"));
cls_AIS_ViewController.def("UpdateZRotation", (bool (AIS_ViewController::*)(double)) &AIS_ViewController::UpdateZRotation, "Update Z rotation event.", py::arg("theAngle"));
cls_AIS_ViewController.def("UpdateMouseScroll", (bool (AIS_ViewController::*)(const Aspect_ScrollDelta &)) &AIS_ViewController::UpdateMouseScroll, "Update mouse scroll event; redirects to UpdateZoom by default. This method is expected to be called from UI thread.", py::arg("theDelta"));
cls_AIS_ViewController.def("UpdateMouseButtons", (bool (AIS_ViewController::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewController::UpdateMouseButtons, "Handle mouse button press/release event. This method is expected to be called from UI thread.", py::arg("thePoint"), py::arg("theButtons"), py::arg("theModifiers"), py::arg("theIsEmulated"));
cls_AIS_ViewController.def("UpdateMousePosition", (bool (AIS_ViewController::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewController::UpdateMousePosition, "Handle mouse cursor movement event. This method is expected to be called from UI thread.", py::arg("thePoint"), py::arg("theButtons"), py::arg("theModifiers"), py::arg("theIsEmulated"));
cls_AIS_ViewController.def("PressMouseButton", (bool (AIS_ViewController::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewController::PressMouseButton, "Handle mouse button press event. This method is expected to be called from UI thread.", py::arg("thePoint"), py::arg("theButton"), py::arg("theModifiers"), py::arg("theIsEmulated"));
cls_AIS_ViewController.def("ReleaseMouseButton", (bool (AIS_ViewController::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewController::ReleaseMouseButton, "Handle mouse button release event. This method is expected to be called from UI thread.", py::arg("thePoint"), py::arg("theButton"), py::arg("theModifiers"), py::arg("theIsEmulated"));
cls_AIS_ViewController.def("UpdateMouseClick", (bool (AIS_ViewController::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewController::UpdateMouseClick, "Handle mouse button click event (emulated by UpdateMouseButtons() while releasing single button). Note that as this method is called by UpdateMouseButtons(), it should be executed from UI thread. Default implementation redirects to SelectInViewer(). This method is expected to be called from UI thread.", py::arg("thePoint"), py::arg("theButton"), py::arg("theModifiers"), py::arg("theIsDoubleClick"));
cls_AIS_ViewController.def("PressedMouseButtons", (Aspect_VKeyMouse (AIS_ViewController::*)() const) &AIS_ViewController::PressedMouseButtons, "Return currently pressed mouse buttons.");
cls_AIS_ViewController.def("LastMouseFlags", (Aspect_VKeyFlags (AIS_ViewController::*)() const) &AIS_ViewController::LastMouseFlags, "Return active key modifiers passed with last mouse event.");
cls_AIS_ViewController.def("LastMousePosition", (const Graphic3d_Vec2i & (AIS_ViewController::*)() const) &AIS_ViewController::LastMousePosition, "Return last mouse position.");
cls_AIS_ViewController.def("TouchToleranceScale", (float (AIS_ViewController::*)() const) &AIS_ViewController::TouchToleranceScale, "Return scale factor for adjusting tolerances for starting multi-touch gestures; 1.0 by default This scale factor is expected to be computed from touch screen resolution.");
cls_AIS_ViewController.def("SetTouchToleranceScale", (void (AIS_ViewController::*)(float)) &AIS_ViewController::SetTouchToleranceScale, "Set scale factor for adjusting tolerances for starting multi-touch gestures.", py::arg("theTolerance"));
cls_AIS_ViewController.def("HasTouchPoints", (bool (AIS_ViewController::*)() const) &AIS_ViewController::HasTouchPoints, "Return TRUE if touches map is not empty.");
cls_AIS_ViewController.def("AddTouchPoint", [](AIS_ViewController &self, Standard_Size a0, const Graphic3d_Vec2d & a1) -> void { return self.AddTouchPoint(a0, a1); });
cls_AIS_ViewController.def("AddTouchPoint", (void (AIS_ViewController::*)(Standard_Size, const Graphic3d_Vec2d &, Standard_Boolean)) &AIS_ViewController::AddTouchPoint, "Add touch point with the given ID. This method is expected to be called from UI thread.", py::arg("theId"), py::arg("thePnt"), py::arg("theClearBefore"));
cls_AIS_ViewController.def("RemoveTouchPoint", [](AIS_ViewController &self, Standard_Size a0) -> bool { return self.RemoveTouchPoint(a0); });
cls_AIS_ViewController.def("RemoveTouchPoint", (bool (AIS_ViewController::*)(Standard_Size, Standard_Boolean)) &AIS_ViewController::RemoveTouchPoint, "Remove touch point with the given ID. This method is expected to be called from UI thread.", py::arg("theId"), py::arg("theClearSelectPnts"));
cls_AIS_ViewController.def("UpdateTouchPoint", (void (AIS_ViewController::*)(Standard_Size, const Graphic3d_Vec2d &)) &AIS_ViewController::UpdateTouchPoint, "Update touch point with the given ID. If point with specified ID was not registered before, it will be added. This method is expected to be called from UI thread.", py::arg("theId"), py::arg("thePnt"));
cls_AIS_ViewController.def("EventTime", (double (AIS_ViewController::*)() const) &AIS_ViewController::EventTime, "Return event time (e.g. current time).");
cls_AIS_ViewController.def("ResetViewInput", (void (AIS_ViewController::*)()) &AIS_ViewController::ResetViewInput, "Reset input state (pressed keys, mouse buttons, etc.) e.g. on window focus loss. This method is expected to be called from UI thread.");
cls_AIS_ViewController.def("UpdateViewOrientation", (void (AIS_ViewController::*)(V3d_TypeOfOrientation, bool)) &AIS_ViewController::UpdateViewOrientation, "Reset view orientation. This method is expected to be called from UI thread.", py::arg("theOrientation"), py::arg("theToFitAll"));
cls_AIS_ViewController.def("FlushViewEvents", [](AIS_ViewController &self, const opencascade::handle<AIS_InteractiveContext> & a0, const opencascade::handle<V3d_View> & a1) -> void { return self.FlushViewEvents(a0, a1); });
cls_AIS_ViewController.def("FlushViewEvents", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &, Standard_Boolean)) &AIS_ViewController::FlushViewEvents, "Update buffer for rendering thread. This method is expected to be called within synchronization barrier between GUI and Rendering threads (e.g. GUI thread should be locked beforehand to avoid data races).", py::arg("theCtx"), py::arg("theView"), py::arg("theToHandle"));
cls_AIS_ViewController.def("HandleViewEvents", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &)) &AIS_ViewController::HandleViewEvents, "Process events within rendering thread.", py::arg("theCtx"), py::arg("theView"));
cls_AIS_ViewController.def("OnSelectionChanged", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &)) &AIS_ViewController::OnSelectionChanged, "Callback called by handleMoveTo() on Selection in 3D Viewer. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"));
cls_AIS_ViewController.def("OnObjectDragged", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &, AIS_DragAction)) &AIS_ViewController::OnObjectDragged, "Callback called by handleMoveTo() on dragging object in 3D Viewer. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"), py::arg("theAction"));
cls_AIS_ViewController.def("PickPoint", (bool (AIS_ViewController::*)(gp_Pnt &, const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &, const Graphic3d_Vec2i &, bool)) &AIS_ViewController::PickPoint, "Pick closest point under mouse cursor. This method is expected to be called from rendering thread.", py::arg("thePnt"), py::arg("theCtx"), py::arg("theView"), py::arg("theCursor"), py::arg("theToStickToPickRay"));
cls_AIS_ViewController.def("GravityPoint", (gp_Pnt (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &)) &AIS_ViewController::GravityPoint, "Compute rotation gravity center point depending on rotation mode. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"));
cls_AIS_ViewController.def("handleCameraActions", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &, const AIS_WalkDelta &)) &AIS_ViewController::handleCameraActions, "Perform camera actions. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"), py::arg("theWalk"));
cls_AIS_ViewController.def("handleMoveTo", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &)) &AIS_ViewController::handleMoveTo, "Perform moveto/selection/dragging. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"));
cls_AIS_ViewController.def("toAskNextFrame", (bool (AIS_ViewController::*)() const) &AIS_ViewController::toAskNextFrame, "Return TRUE if another frame should be drawn right after this one.");
cls_AIS_ViewController.def("setAskNextFrame", [](AIS_ViewController &self) -> void { return self.setAskNextFrame(); });
cls_AIS_ViewController.def("setAskNextFrame", (void (AIS_ViewController::*)(bool)) &AIS_ViewController::setAskNextFrame, "Set if another frame should be drawn right after this one.", py::arg("theToDraw"));
cls_AIS_ViewController.def("hasPanningAnchorPoint", (bool (AIS_ViewController::*)() const) &AIS_ViewController::hasPanningAnchorPoint, "Return if panning anchor point has been defined.");
cls_AIS_ViewController.def("panningAnchorPoint", (const gp_Pnt & (AIS_ViewController::*)() const) &AIS_ViewController::panningAnchorPoint, "Return active panning anchor point.");
cls_AIS_ViewController.def("setPanningAnchorPoint", (void (AIS_ViewController::*)(const gp_Pnt &)) &AIS_ViewController::setPanningAnchorPoint, "Set active panning anchor point.", py::arg("thePnt"));
cls_AIS_ViewController.def("handlePanning", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &)) &AIS_ViewController::handlePanning, "Handle panning event myGL.Panning.", py::arg("theView"));
cls_AIS_ViewController.def("handleZRotate", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &)) &AIS_ViewController::handleZRotate, "Handle Z rotation event myGL.ZRotate.", py::arg("theView"));
cls_AIS_ViewController.def("MinZoomDistance", (double (AIS_ViewController::*)() const) &AIS_ViewController::MinZoomDistance, "Return minimal camera distance for zoom operation.");
cls_AIS_ViewController.def("SetMinZoomDistance", (void (AIS_ViewController::*)(double)) &AIS_ViewController::SetMinZoomDistance, "Set minimal camera distance for zoom operation.", py::arg("theDist"));
cls_AIS_ViewController.def("handleZoom", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &, const Aspect_ScrollDelta &, const gp_Pnt *)) &AIS_ViewController::handleZoom, "Handle zoom event myGL.ZoomActions. This method is expected to be called from rendering thread.", py::arg("theView"), py::arg("theParams"), py::arg("thePnt"));
cls_AIS_ViewController.def("handleZFocusScroll", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &, const Aspect_ScrollDelta &)) &AIS_ViewController::handleZFocusScroll, "Handle ZScroll event myGL.ZoomActions. This method is expected to be called from rendering thread.", py::arg("theView"), py::arg("theParams"));
cls_AIS_ViewController.def("handleOrbitRotation", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &, const gp_Pnt &, bool)) &AIS_ViewController::handleOrbitRotation, "Handle orbital rotation events myGL.OrbitRotation.", py::arg("theView"), py::arg("thePnt"), py::arg("theToLockZUp"));
cls_AIS_ViewController.def("handleViewRotation", (void (AIS_ViewController::*)(const opencascade::handle<V3d_View> &, double, double, double, bool)) &AIS_ViewController::handleViewRotation, "Handle view direction rotation events myGL.ViewRotation. This method is expected to be called from rendering thread.", py::arg("theView"), py::arg("theYawExtra"), py::arg("thePitchExtra"), py::arg("theRoll"), py::arg("theToRestartOnIncrement"));
cls_AIS_ViewController.def("handleViewRedraw", (void (AIS_ViewController::*)(const opencascade::handle<AIS_InteractiveContext> &, const opencascade::handle<V3d_View> &)) &AIS_ViewController::handleViewRedraw, "Handle view redraw. This method is expected to be called from rendering thread.", py::arg("theCtx"), py::arg("theView"));

// CLASS: AIS_VIEWCUBE
py::class_<AIS_ViewCube, opencascade::handle<AIS_ViewCube>, AIS_InteractiveObject> cls_AIS_ViewCube(mod, "AIS_ViewCube", "Interactive object for displaying the view manipulation cube.");

// Constructors
cls_AIS_ViewCube.def(py::init<>());

// Methods
cls_AIS_ViewCube.def_static("get_type_name_", (const char * (*)()) &AIS_ViewCube::get_type_name, "None");
cls_AIS_ViewCube.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ViewCube::get_type_descriptor, "None");
cls_AIS_ViewCube.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ViewCube::*)() const) &AIS_ViewCube::DynamicType, "None");
cls_AIS_ViewCube.def_static("IsBoxSide_", (bool (*)(V3d_TypeOfOrientation)) &AIS_ViewCube::IsBoxSide, "Return TRUE if specified orientation belongs to box side.", py::arg("theOrient"));
cls_AIS_ViewCube.def_static("IsBoxEdge_", (bool (*)(V3d_TypeOfOrientation)) &AIS_ViewCube::IsBoxEdge, "Return TRUE if specified orientation belongs to box edge.", py::arg("theOrient"));
cls_AIS_ViewCube.def_static("IsBoxCorner_", (bool (*)(V3d_TypeOfOrientation)) &AIS_ViewCube::IsBoxCorner, "Return TRUE if specified orientation belongs to box corner (vertex).", py::arg("theOrient"));
cls_AIS_ViewCube.def("ViewAnimation", (const opencascade::handle<AIS_AnimationCamera> & (AIS_ViewCube::*)() const) &AIS_ViewCube::ViewAnimation, "Return view animation.");
cls_AIS_ViewCube.def("SetViewAnimation", (void (AIS_ViewCube::*)(const opencascade::handle<AIS_AnimationCamera> &)) &AIS_ViewCube::SetViewAnimation, "Set view animation.", py::arg("theAnimation"));
cls_AIS_ViewCube.def("ToAutoStartAnimation", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToAutoStartAnimation, "Return TRUE if automatic camera transformation on selection (highlighting) is enabled; TRUE by default.");
cls_AIS_ViewCube.def("SetAutoStartAnimation", (void (AIS_ViewCube::*)(bool)) &AIS_ViewCube::SetAutoStartAnimation, "Enable/disable automatic camera transformation on selection (highlighting). The automatic logic can be disabled if application wants performing action manually basing on picking results (AIS_ViewCubeOwner).", py::arg("theToEnable"));
cls_AIS_ViewCube.def("IsFixedAnimationLoop", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::IsFixedAnimationLoop, "Return TRUE if camera animation should be done in uninterruptible loop; TRUE by default.");
cls_AIS_ViewCube.def("SetFixedAnimationLoop", (void (AIS_ViewCube::*)(bool)) &AIS_ViewCube::SetFixedAnimationLoop, "Set if camera animation should be done in uninterruptible loop.", py::arg("theToEnable"));
cls_AIS_ViewCube.def("ResetStyles", (void (AIS_ViewCube::*)()) &AIS_ViewCube::ResetStyles, "Reset all size and style parameters to default.");
cls_AIS_ViewCube.def("Size", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::Size, "Returns size (width and height) of View cube sides; 100 by default.");
cls_AIS_ViewCube.def("SetSize", [](AIS_ViewCube &self, Standard_Real a0) -> void { return self.SetSize(a0); });
cls_AIS_ViewCube.def("SetSize", (void (AIS_ViewCube::*)(Standard_Real, Standard_Boolean)) &AIS_ViewCube::SetSize, "Sets size (width and height) of View cube sides.", py::arg("theValue"), py::arg("theToAdaptAnother"));
cls_AIS_ViewCube.def("BoxFacetExtension", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxFacetExtension, "Return box facet extension to edge/corner facet split; 10 by default.");
cls_AIS_ViewCube.def("SetBoxFacetExtension", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetBoxFacetExtension, "Set new value of box facet extension.", py::arg("theValue"));
cls_AIS_ViewCube.def("AxesPadding", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::AxesPadding, "Return padding between axes and 3D part (box); 10 by default.");
cls_AIS_ViewCube.def("SetAxesPadding", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetAxesPadding, "Set new value of padding between axes and 3D part (box).", py::arg("theValue"));
cls_AIS_ViewCube.def("BoxEdgeGap", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxEdgeGap, "Return gap between box edges and box sides; 0 by default.");
cls_AIS_ViewCube.def("SetBoxEdgeGap", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetBoxEdgeGap, "Set new value of box edges gap.", py::arg("theValue"));
cls_AIS_ViewCube.def("BoxEdgeMinSize", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxEdgeMinSize, "Return minimal size of box edge; 2 by default.");
cls_AIS_ViewCube.def("SetBoxEdgeMinSize", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetBoxEdgeMinSize, "Set new value of box edge minimal size.", py::arg("theValue"));
cls_AIS_ViewCube.def("BoxCornerMinSize", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxCornerMinSize, "Return minimal size of box corner; 2 by default.");
cls_AIS_ViewCube.def("SetBoxCornerMinSize", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetBoxCornerMinSize, "Set new value of box corner minimal size.", py::arg("theValue"));
cls_AIS_ViewCube.def("RoundRadius", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::RoundRadius, "Return relative radius of side corners (round rectangle); 0.0 by default. The value in within [0, 0.5] range meaning absolute radius = RoundRadius() / Size().");
cls_AIS_ViewCube.def("SetRoundRadius", (void (AIS_ViewCube::*)(const Standard_Real)) &AIS_ViewCube::SetRoundRadius, "Set relative radius of View Cube sides corners (round rectangle). The value should be within [0, 0.5] range.", py::arg("theValue"));
cls_AIS_ViewCube.def("ToDrawAxes", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToDrawAxes, "Returns TRUE if trihedron is drawn; TRUE by default.");
cls_AIS_ViewCube.def("SetDrawAxes", (void (AIS_ViewCube::*)(Standard_Boolean)) &AIS_ViewCube::SetDrawAxes, "Enable/disable drawing of trihedron.", py::arg("theValue"));
cls_AIS_ViewCube.def("ToDrawEdges", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToDrawEdges, "Returns TRUE if edges of View Cube is drawn; TRUE by default.");
cls_AIS_ViewCube.def("SetDrawEdges", (void (AIS_ViewCube::*)(Standard_Boolean)) &AIS_ViewCube::SetDrawEdges, "Enable/disable drawing of edges of View Cube.", py::arg("theValue"));
cls_AIS_ViewCube.def("ToDrawVertices", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToDrawVertices, "Return TRUE if vertices (vertex) of View Cube is drawn; TRUE by default.");
cls_AIS_ViewCube.def("SetDrawVertices", (void (AIS_ViewCube::*)(Standard_Boolean)) &AIS_ViewCube::SetDrawVertices, "Enable/disable drawing of vertices (corners) of View Cube.", py::arg("theValue"));
cls_AIS_ViewCube.def("IsYup", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::IsYup, "Return TRUE if application expects Y-up viewer orientation instead of Z-up; FALSE by default.");
cls_AIS_ViewCube.def("SetYup", [](AIS_ViewCube &self, Standard_Boolean a0) -> void { return self.SetYup(a0); });
cls_AIS_ViewCube.def("SetYup", (void (AIS_ViewCube::*)(Standard_Boolean, Standard_Boolean)) &AIS_ViewCube::SetYup, "Set if application expects Y-up viewer orientation instead of Z-up.", py::arg("theIsYup"), py::arg("theToUpdateLabels"));
cls_AIS_ViewCube.def("BoxSideStyle", (const opencascade::handle<Prs3d_ShadingAspect> & (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxSideStyle, "Return shading style of box sides.");
cls_AIS_ViewCube.def("BoxEdgeStyle", (const opencascade::handle<Prs3d_ShadingAspect> & (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxEdgeStyle, "Return shading style of box edges.");
cls_AIS_ViewCube.def("BoxCornerStyle", (const opencascade::handle<Prs3d_ShadingAspect> & (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxCornerStyle, "Return shading style of box corners.");
cls_AIS_ViewCube.def("BoxColor", (const Quantity_Color & (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxColor, "Return value of front color for the 3D part of object.");
cls_AIS_ViewCube.def("SetBoxColor", (void (AIS_ViewCube::*)(const Quantity_Color &)) &AIS_ViewCube::SetBoxColor, "Set new value of front color for the 3D part of object.", py::arg("theColor"));
cls_AIS_ViewCube.def("BoxTransparency", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::BoxTransparency, "Return transparency for 3D part of object.");
cls_AIS_ViewCube.def("SetBoxTransparency", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetBoxTransparency, "Set new value of transparency for 3D part of object.", py::arg("theValue"));
cls_AIS_ViewCube.def("InnerColor", (const Quantity_Color & (AIS_ViewCube::*)() const) &AIS_ViewCube::InnerColor, "Return color of sides back material.");
cls_AIS_ViewCube.def("SetInnerColor", (void (AIS_ViewCube::*)(const Quantity_Color &)) &AIS_ViewCube::SetInnerColor, "Set color of sides back material. Alias for:", py::arg("theColor"));
cls_AIS_ViewCube.def("BoxSideLabel", (TCollection_AsciiString (AIS_ViewCube::*)(V3d_TypeOfOrientation) const) &AIS_ViewCube::BoxSideLabel, "Return box side label or empty string if undefined. Default labels: FRONT, BACK, LEFT, RIGHT, TOP, BOTTOM.", py::arg("theSide"));
cls_AIS_ViewCube.def("SetBoxSideLabel", (void (AIS_ViewCube::*)(const V3d_TypeOfOrientation, const TCollection_AsciiString &)) &AIS_ViewCube::SetBoxSideLabel, "Set box side label.", py::arg("theSide"), py::arg("theLabel"));
cls_AIS_ViewCube.def("TextColor", (const Quantity_Color & (AIS_ViewCube::*)() const) &AIS_ViewCube::TextColor, "Return text color of labels of box sides; BLACK by default.");
cls_AIS_ViewCube.def("SetTextColor", (void (AIS_ViewCube::*)(const Quantity_Color &)) &AIS_ViewCube::SetTextColor, "Set color of text labels on box sides. Alias for:", py::arg("theColor"));
cls_AIS_ViewCube.def("Font", (const TCollection_AsciiString & (AIS_ViewCube::*)() const) &AIS_ViewCube::Font, "Return font name that is used for displaying of sides and axes text. Alias for:");
cls_AIS_ViewCube.def("SetFont", (void (AIS_ViewCube::*)(const TCollection_AsciiString &)) &AIS_ViewCube::SetFont, "Set font name that is used for displaying of sides and axes text. Alias for:", py::arg("theFont"));
cls_AIS_ViewCube.def("FontHeight", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::FontHeight, "Return height of font");
cls_AIS_ViewCube.def("SetFontHeight", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetFontHeight, "Change font height. Alias for:", py::arg("theValue"));
cls_AIS_ViewCube.def("AxisLabel", (TCollection_AsciiString (AIS_ViewCube::*)(Prs3d_DatumParts) const) &AIS_ViewCube::AxisLabel, "Return axes labels or empty string if undefined. Default labels: X, Y, Z.", py::arg("theAxis"));
cls_AIS_ViewCube.def("SetAxesLabels", (void (AIS_ViewCube::*)(const TCollection_AsciiString &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &AIS_ViewCube::SetAxesLabels, "Set axes labels.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_AIS_ViewCube.def("SetColor", (void (AIS_ViewCube::*)(const Quantity_Color &)) &AIS_ViewCube::SetColor, "Set new value of color for the whole object.", py::arg("theColor"));
cls_AIS_ViewCube.def("UnsetColor", (void (AIS_ViewCube::*)()) &AIS_ViewCube::UnsetColor, "Reset color for the whole object.");
cls_AIS_ViewCube.def("SetTransparency", (void (AIS_ViewCube::*)(const Standard_Real)) &AIS_ViewCube::SetTransparency, "Set new value of transparency for the whole object.", py::arg("theValue"));
cls_AIS_ViewCube.def("UnsetTransparency", (void (AIS_ViewCube::*)()) &AIS_ViewCube::UnsetTransparency, "Reset transparency for the whole object.");
cls_AIS_ViewCube.def("SetMaterial", (void (AIS_ViewCube::*)(const Graphic3d_MaterialAspect &)) &AIS_ViewCube::SetMaterial, "Sets the material for the interactive object.", py::arg("theMat"));
cls_AIS_ViewCube.def("UnsetMaterial", (void (AIS_ViewCube::*)()) &AIS_ViewCube::UnsetMaterial, "Sets the material for the interactive object.");
cls_AIS_ViewCube.def("Duration", (Standard_Real (AIS_ViewCube::*)() const) &AIS_ViewCube::Duration, "Return duration of animation in seconds; 0.5 sec by default");
cls_AIS_ViewCube.def("SetDuration", (void (AIS_ViewCube::*)(Standard_Real)) &AIS_ViewCube::SetDuration, "Set duration of animation.", py::arg("theValue"));
cls_AIS_ViewCube.def("ToResetCameraUp", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToResetCameraUp, "Return TRUE if new camera Up direction should be always set to default value for a new camera Direction; FALSE by default. When this flag is FALSE, the new camera Up will be set as current Up orthogonalized to the new camera Direction, and will set to default Up on second click.");
cls_AIS_ViewCube.def("SetResetCamera", (void (AIS_ViewCube::*)(Standard_Boolean)) &AIS_ViewCube::SetResetCamera, "Set if new camera Up direction should be always set to default value for a new camera Direction.", py::arg("theToReset"));
cls_AIS_ViewCube.def("ToFitSelected", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::ToFitSelected, "Return TRUE if animation should fit selected objects and FALSE to fit entire scene; TRUE by default.");
cls_AIS_ViewCube.def("SetFitSelected", (void (AIS_ViewCube::*)(Standard_Boolean)) &AIS_ViewCube::SetFitSelected, "Set if animation should fit selected objects or to fit entire scene.", py::arg("theToFitSelected"));
cls_AIS_ViewCube.def("HasAnimation", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::HasAnimation, "Returns TRUE if View Cube has unfinished animation of view camera.");
cls_AIS_ViewCube.def("StartAnimation", (void (AIS_ViewCube::*)(const opencascade::handle<AIS_ViewCubeOwner> &)) &AIS_ViewCube::StartAnimation, "Start camera transformation corresponding to the input detected owner.", py::arg("theOwner"));
cls_AIS_ViewCube.def("UpdateAnimation", (Standard_Boolean (AIS_ViewCube::*)(const Standard_Boolean)) &AIS_ViewCube::UpdateAnimation, "Perform one step of current camera transformation. theToUpdate [in] enable/disable update of view.", py::arg("theToUpdate"));
cls_AIS_ViewCube.def("HandleClick", (void (AIS_ViewCube::*)(const opencascade::handle<AIS_ViewCubeOwner> &)) &AIS_ViewCube::HandleClick, "Perform camera transformation corresponding to the input detected owner.", py::arg("theOwner"));
cls_AIS_ViewCube.def("AcceptDisplayMode", (Standard_Boolean (AIS_ViewCube::*)(const Standard_Integer) const) &AIS_ViewCube::AcceptDisplayMode, "Return TRUE for supported display mode.", py::arg("theMode"));
cls_AIS_ViewCube.def("GlobalSelOwner", (opencascade::handle<SelectMgr_EntityOwner> (AIS_ViewCube::*)() const) &AIS_ViewCube::GlobalSelOwner, "Global selection has no meaning for this class.");
cls_AIS_ViewCube.def("Compute", [](AIS_ViewCube &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Presentation> & a1) -> void { return self.Compute(a0, a1); });
cls_AIS_ViewCube.def("Compute", (void (AIS_ViewCube::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &AIS_ViewCube::Compute, "Compute 3D part of View Cube.", py::arg("thePrsMgr"), py::arg("thePrs"), py::arg("theMode"));
cls_AIS_ViewCube.def("ComputeSelection", (void (AIS_ViewCube::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &AIS_ViewCube::ComputeSelection, "Redefine computing of sensitive entities for View Cube.", py::arg("theSelection"), py::arg("theMode"));
cls_AIS_ViewCube.def("IsAutoHilight", (Standard_Boolean (AIS_ViewCube::*)() const) &AIS_ViewCube::IsAutoHilight, "Disables auto highlighting to use HilightSelected() and HilightOwnerWithColor() overridden methods.");
cls_AIS_ViewCube.def("ClearSelected", (void (AIS_ViewCube::*)()) &AIS_ViewCube::ClearSelected, "Method which clear all selected owners belonging to this selectable object.");
cls_AIS_ViewCube.def("HilightOwnerWithColor", (void (AIS_ViewCube::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &AIS_ViewCube::HilightOwnerWithColor, "Method which highlights input owner belonging to this selectable object.", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));
cls_AIS_ViewCube.def("HilightSelected", (void (AIS_ViewCube::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &AIS_ViewCube::HilightSelected, "Method which draws selected owners.", py::arg("thePM"), py::arg("theSeq"));
cls_AIS_ViewCube.def("UnsetAttributes", (void (AIS_ViewCube::*)()) &AIS_ViewCube::UnsetAttributes, "Set default parameters for visual attributes");
cls_AIS_ViewCube.def("UnsetHilightAttributes", (void (AIS_ViewCube::*)()) &AIS_ViewCube::UnsetHilightAttributes, "Set default parameters for dynamic highlighting attributes, reset highlight attributes");

// CLASS: AIS_VIEWCUBEOWNER
py::class_<AIS_ViewCubeOwner, opencascade::handle<AIS_ViewCubeOwner>, SelectMgr_EntityOwner> cls_AIS_ViewCubeOwner(mod, "AIS_ViewCubeOwner", "Redefined entity owner that is highlighted when owner is detected, even if Interactive Context highlighted on last detection procedure.");

// Constructors
cls_AIS_ViewCubeOwner.def(py::init<const opencascade::handle<AIS_ViewCube> &, V3d_TypeOfOrientation>(), py::arg("theObject"), py::arg("theOrient"));
cls_AIS_ViewCubeOwner.def(py::init<const opencascade::handle<AIS_ViewCube> &, V3d_TypeOfOrientation, Standard_Integer>(), py::arg("theObject"), py::arg("theOrient"), py::arg("thePriority"));

// Methods
cls_AIS_ViewCubeOwner.def_static("get_type_name_", (const char * (*)()) &AIS_ViewCubeOwner::get_type_name, "None");
cls_AIS_ViewCubeOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ViewCubeOwner::get_type_descriptor, "None");
cls_AIS_ViewCubeOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ViewCubeOwner::*)() const) &AIS_ViewCubeOwner::DynamicType, "None");
cls_AIS_ViewCubeOwner.def("IsForcedHilight", (Standard_Boolean (AIS_ViewCubeOwner::*)() const) &AIS_ViewCubeOwner::IsForcedHilight, "Returns TRUE. This owner will always call method Hilight for its Selectable Object when the owner is detected.");
cls_AIS_ViewCubeOwner.def("MainOrientation", (V3d_TypeOfOrientation (AIS_ViewCubeOwner::*)() const) &AIS_ViewCubeOwner::MainOrientation, "Return new orientation to set.");
cls_AIS_ViewCubeOwner.def("HandleMouseClick", (Standard_Boolean (AIS_ViewCubeOwner::*)(const Graphic3d_Vec2i &, Aspect_VKeyMouse, Aspect_VKeyFlags, bool)) &AIS_ViewCubeOwner::HandleMouseClick, "Handle mouse button click event.", py::arg("thePoint"), py::arg("theButton"), py::arg("theModifiers"), py::arg("theIsDoubleClick"));


}
