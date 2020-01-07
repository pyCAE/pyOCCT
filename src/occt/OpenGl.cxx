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
#include <Precision.hxx>
#include <bind_BVH_Geometry.hxx>
#include <bind_BVH_Set.hxx>
#include <OpenGl_RenderFilter.hxx>
#include <OpenGl_ShaderProgramDumpLevel.hxx>
#include <OpenGl_Material.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_ShaderProgram.hxx>
#include <OpenGl_LayerFilter.hxx>
#include <OpenGl_SetOfShaderPrograms.hxx>
#include <OpenGl_GlFunctions.hxx>
#include <Aspect_Handle.hxx>
#include <OpenGl_ArbDbg.hxx>
#include <OpenGl_ArbFBO.hxx>
#include <OpenGl_ArbIns.hxx>
#include <OpenGl_ArbSamplerObject.hxx>
#include <OpenGl_ArbTBO.hxx>
#include <OpenGl_ArbTexBindless.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Graphic3d_Aspects.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_AspectsProgram.hxx>
#include <OpenGl_TextureSet.hxx>
#include <OpenGl_PointSprite.hxx>
#include <OpenGl_AspectsTextureSet.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Graphic3d_Vec4.hxx>
#include <OpenGl_AspectsSprite.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Standard_OStream.hxx>
#include <OpenGl_Aspects.hxx>
#include <OpenGl_GlCore11Fwd.hxx>
#include <OpenGl_GlCore11.hxx>
#include <OpenGl_GlCore12.hxx>
#include <OpenGl_GlCore13.hxx>
#include <OpenGl_GlCore14.hxx>
#include <OpenGl_GlCore15.hxx>
#include <OpenGl_GlCore20.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OpenGl_Resource.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <OpenGl_Caps.hxx>
#include <NCollection_DataMap.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <OpenGl_LineAttributes.hxx>
#include <Graphic3d_Vec2.hxx>
#include <OpenGl_Vec.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Graphic3d_Mat4.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Quantity_Color.hxx>
#include <NCollection_Array1.hxx>
#include <OpenGl_Texture.hxx>
#include <OpenGl_ClippingIterator.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <NCollection_Vector.hxx>
#include <OpenGl_Clipping.hxx>
#include <OpenGl_GlCore21.hxx>
#include <OpenGl_GlCore30.hxx>
#include <OpenGl_GlCore31.hxx>
#include <OpenGl_GlCore32.hxx>
#include <OpenGl_GlCore33.hxx>
#include <OpenGl_GlCore40.hxx>
#include <OpenGl_GlCore41.hxx>
#include <OpenGl_GlCore42.hxx>
#include <OpenGl_GlCore43.hxx>
#include <OpenGl_GlCore44.hxx>
#include <OpenGl_GlCore45.hxx>
#include <OpenGl_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <OpenGl_ShaderManager.hxx>
#include <Graphic3d_TextureUnit.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Message_Messenger.hxx>
#include <Message.hxx>
#include <TCollection_ExtendedString.hxx>
#include <OpenGl_FrameStats.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Graphic3d_TextureParams.hxx>
#include <OpenGl_FrameBuffer.hxx>
#include <OpenGl_ExtGS.hxx>
#include <OpenGl_MatrixState.hxx>
#include <NCollection_List.hxx>
#include <NCollection_Handle.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <OpenGl_Matrix.hxx>
#include <OpenGl_NamedResource.hxx>
#include <OpenGl_ShaderObject.hxx>
#include <NCollection_Sequence.hxx>
#include <Graphic3d_ShaderObject.hxx>
#include <Graphic3d_TypeOfShaderObject.hxx>
#include <Quantity_Date.hxx>
#include <Graphic3d_ShaderVariable.hxx>
#include <OpenGl_View.hxx>
#include <Graphic3d_Buffer.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <OpenGl_IndexBuffer.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <OpenGl_PrimitiveArray.hxx>
#include <OpenGl_Group.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_MapOfAspectsToAspects.hxx>
#include <Graphic3d_Text.hxx>
#include <gp_Ax2.hxx>
#include <OpenGl_Structure.hxx>
#include <OpenGl_CappingAlgo.hxx>
#include <OpenGl_Sampler.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_TypeOfTexture.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Graphic3d_CubeMap.hxx>
#include <Image_Format.hxx>
#include <Graphic3d_BufferType.hxx>
#include <OpenGl_TextureBufferArb.hxx>
#include <Aspect_Window.hxx>
#include <Graphic3d_TypeOfBackground.hxx>
#include <Aspect_FillMethod.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <OpenGl_BackgroundArray.hxx>
#include <gp_XYZ.hxx>
#include <OpenGl_CappingPlaneResource.hxx>
#include <OpenGl_Flipper.hxx>
#include <Font_Rect.hxx>
#include <Font_FTFont.hxx>
#include <OpenGl_Font.hxx>
#include <Graphic3d_FrameStats.hxx>
#include <Graphic3d_CView.hxx>
#include <NCollection_IndexedMap.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Font_TextFormatter.hxx>
#include <OpenGl_VertexBufferEditor.hxx>
#include <OpenGl_TextBuilder.hxx>
#include <NCollection_String.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <OpenGl_GraduatedTrihedron.hxx>
#include <OpenGl_Text.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <OpenGl_FrameStatsPrs.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Graphic3d_TypeOfLimit.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <NCollection_Map.hxx>
#include <OpenGl_HaltonSampler.hxx>
#include <Graphic3d_Layer.hxx>
#include <OpenGl_Layer.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <OpenGl_LayerList.hxx>
#include <OpenGl_ShaderStates.hxx>
#include <Graphic3d_LightSet.hxx>
#include <OpenGl_MaterialState.hxx>
#include <BVH_Types.hxx>
#include <OpenGl_SceneGeometry.hxx>
#include <BVH_Tree.hxx>
#include <BVH_Triangulation.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Geometry.hxx>
#include <NCollection_StdAllocator.hxx>
#include <gp.hxx>
#include <Graphic3d_AlphaMode.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Graphic3d_StereoMode.hxx>
#include <OpenGl_StencilTest.hxx>
#include <Geom_Transformation.hxx>
#include <OpenGl_StructureShadow.hxx>
#include <Image_PixMapTypedData.hxx>
#include <OpenGl_TileSampler.hxx>
#include <NCollection_Buffer.hxx>
#include <OpenGl_VertexBufferCompat.hxx>
#include <Bnd_Box.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_TypeOfBackfacingModel.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Graphic3d_CullingTool.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <Graphic3d_ToneMappingMethod.hxx>
#include <math_BullardGenerator.hxx>
#include <bind_OpenGl_TmplCore12.hxx>
#include <bind_OpenGl_TmplCore14.hxx>
#include <bind_OpenGl_TmplCore15.hxx>
#include <bind_OpenGl_TmplCore20.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Vec2.hxx>
#include <bind_NCollection_Vec3.hxx>
#include <bind_NCollection_Vec4.hxx>
#include <bind_NCollection_Mat4.hxx>
#include <bind_OpenGl_TmplCore21.hxx>
#include <bind_OpenGl_TmplCore30.hxx>
#include <bind_OpenGl_TmplCore31.hxx>
#include <bind_OpenGl_TmplCore32.hxx>
#include <bind_OpenGl_TmplCore33.hxx>
#include <bind_OpenGl_TmplCore40.hxx>
#include <bind_OpenGl_TmplCore41.hxx>
#include <bind_OpenGl_TmplCore42.hxx>
#include <bind_OpenGl_TmplCore43.hxx>
#include <bind_OpenGl_TmplCore44.hxx>
#include <bind_OpenGl_TmplCore45.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Vector.hxx>
#include <bind_BVH_Triangulation.hxx>
#include <bind_NCollection_List.hxx>

PYBIND11_MODULE(OpenGl, mod) {

py::module::import("OCCT.Precision");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Message");
py::module::import("OCCT.gp");
py::module::import("OCCT.Image");
py::module::import("OCCT.Font");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.BVH");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.math");

// ENUM: OPENGL_RENDERFILTER
py::enum_<OpenGl_RenderFilter>(mod, "OpenGl_RenderFilter", "Filter for rendering elements.")
	.value("OpenGl_RenderFilter_Empty", OpenGl_RenderFilter::OpenGl_RenderFilter_Empty)
	.value("OpenGl_RenderFilter_OpaqueOnly", OpenGl_RenderFilter::OpenGl_RenderFilter_OpaqueOnly)
	.value("OpenGl_RenderFilter_TransparentOnly", OpenGl_RenderFilter::OpenGl_RenderFilter_TransparentOnly)
	.value("OpenGl_RenderFilter_NonRaytraceableOnly", OpenGl_RenderFilter::OpenGl_RenderFilter_NonRaytraceableOnly)
	.value("OpenGl_RenderFilter_FillModeOnly", OpenGl_RenderFilter::OpenGl_RenderFilter_FillModeOnly)
	.export_values();


// ENUM: OPENGL_SHADERPROGRAMDUMPLEVEL
py::enum_<OpenGl_ShaderProgramDumpLevel>(mod, "OpenGl_ShaderProgramDumpLevel", "Definition of shader programs source code dump levels.")
	.value("OpenGl_ShaderProgramDumpLevel_Off", OpenGl_ShaderProgramDumpLevel::OpenGl_ShaderProgramDumpLevel_Off)
	.value("OpenGl_ShaderProgramDumpLevel_Short", OpenGl_ShaderProgramDumpLevel::OpenGl_ShaderProgramDumpLevel_Short)
	.value("OpenGl_ShaderProgramDumpLevel_Full", OpenGl_ShaderProgramDumpLevel::OpenGl_ShaderProgramDumpLevel_Full)
	.export_values();


// ENUM: OPENGL_MATERIALFLAG
py::enum_<OpenGl_MaterialFlag>(mod, "OpenGl_MaterialFlag", "Material flag")
	.value("OpenGl_MaterialFlag_Front", OpenGl_MaterialFlag::OpenGl_MaterialFlag_Front)
	.value("OpenGl_MaterialFlag_Back", OpenGl_MaterialFlag::OpenGl_MaterialFlag_Back)
	.export_values();


// ENUM: OPENGL_FEATUREFLAG
py::enum_<OpenGl_FeatureFlag>(mod, "OpenGl_FeatureFlag", "None")
	.value("OpenGl_FeatureNotAvailable", OpenGl_FeatureFlag::OpenGl_FeatureNotAvailable)
	.value("OpenGl_FeatureInExtensions", OpenGl_FeatureFlag::OpenGl_FeatureInExtensions)
	.value("OpenGl_FeatureInCore", OpenGl_FeatureFlag::OpenGl_FeatureInCore)
	.export_values();


// ENUM: OPENGL_STATEVARIABLE
py::enum_<OpenGl_StateVariable>(mod, "OpenGl_StateVariable", "The enumeration of OCCT-specific OpenGL/GLSL variables.")
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX)
	.value("OpenGl_OCC_PROJECTION_MATRIX", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_INVERSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_INVERSE)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_TRANSPOSE)
	.value("OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_MODEL_WORLD_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_WORLD_VIEW_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_PROJECTION_MATRIX_INVERSE_TRANSPOSE", OpenGl_StateVariable::OpenGl_OCC_PROJECTION_MATRIX_INVERSE_TRANSPOSE)
	.value("OpenGl_OCC_CLIP_PLANE_EQUATIONS", OpenGl_StateVariable::OpenGl_OCC_CLIP_PLANE_EQUATIONS)
	.value("OpenGl_OCC_CLIP_PLANE_CHAINS", OpenGl_StateVariable::OpenGl_OCC_CLIP_PLANE_CHAINS)
	.value("OpenGl_OCC_CLIP_PLANE_COUNT", OpenGl_StateVariable::OpenGl_OCC_CLIP_PLANE_COUNT)
	.value("OpenGl_OCC_LIGHT_SOURCE_COUNT", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_COUNT)
	.value("OpenGl_OCC_LIGHT_SOURCE_TYPES", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_TYPES)
	.value("OpenGl_OCC_LIGHT_SOURCE_PARAMS", OpenGl_StateVariable::OpenGl_OCC_LIGHT_SOURCE_PARAMS)
	.value("OpenGl_OCC_LIGHT_AMBIENT", OpenGl_StateVariable::OpenGl_OCC_LIGHT_AMBIENT)
	.value("OpenGl_OCCT_TEXTURE_ENABLE", OpenGl_StateVariable::OpenGl_OCCT_TEXTURE_ENABLE)
	.value("OpenGl_OCCT_DISTINGUISH_MODE", OpenGl_StateVariable::OpenGl_OCCT_DISTINGUISH_MODE)
	.value("OpenGl_OCCT_FRONT_MATERIAL", OpenGl_StateVariable::OpenGl_OCCT_FRONT_MATERIAL)
	.value("OpenGl_OCCT_BACK_MATERIAL", OpenGl_StateVariable::OpenGl_OCCT_BACK_MATERIAL)
	.value("OpenGl_OCCT_ALPHA_CUTOFF", OpenGl_StateVariable::OpenGl_OCCT_ALPHA_CUTOFF)
	.value("OpenGl_OCCT_COLOR", OpenGl_StateVariable::OpenGl_OCCT_COLOR)
	.value("OpenGl_OCCT_OIT_OUTPUT", OpenGl_StateVariable::OpenGl_OCCT_OIT_OUTPUT)
	.value("OpenGl_OCCT_OIT_DEPTH_FACTOR", OpenGl_StateVariable::OpenGl_OCCT_OIT_DEPTH_FACTOR)
	.value("OpenGl_OCCT_TEXTURE_TRSF2D", OpenGl_StateVariable::OpenGl_OCCT_TEXTURE_TRSF2D)
	.value("OpenGl_OCCT_POINT_SIZE", OpenGl_StateVariable::OpenGl_OCCT_POINT_SIZE)
	.value("OpenGl_OCCT_VIEWPORT", OpenGl_StateVariable::OpenGl_OCCT_VIEWPORT)
	.value("OpenGl_OCCT_LINE_WIDTH", OpenGl_StateVariable::OpenGl_OCCT_LINE_WIDTH)
	.value("OpenGl_OCCT_LINE_FEATHER", OpenGl_StateVariable::OpenGl_OCCT_LINE_FEATHER)
	.value("OpenGl_OCCT_LINE_STIPPLE_PATTERN", OpenGl_StateVariable::OpenGl_OCCT_LINE_STIPPLE_PATTERN)
	.value("OpenGl_OCCT_LINE_STIPPLE_FACTOR", OpenGl_StateVariable::OpenGl_OCCT_LINE_STIPPLE_FACTOR)
	.value("OpenGl_OCCT_WIREFRAME_COLOR", OpenGl_StateVariable::OpenGl_OCCT_WIREFRAME_COLOR)
	.value("OpenGl_OCCT_QUAD_MODE_STATE", OpenGl_StateVariable::OpenGl_OCCT_QUAD_MODE_STATE)
	.value("OpenGl_OCCT_ORTHO_SCALE", OpenGl_StateVariable::OpenGl_OCCT_ORTHO_SCALE)
	.value("OpenGl_OCCT_SILHOUETTE_THICKNESS", OpenGl_StateVariable::OpenGl_OCCT_SILHOUETTE_THICKNESS)
	.value("OpenGl_OCCT_NUMBER_OF_STATE_VARIABLES", OpenGl_StateVariable::OpenGl_OCCT_NUMBER_OF_STATE_VARIABLES)
	.export_values();

py::enum_<OpenGl_UniformStateType>(mod, "OpenGl_UniformStateType", "Defines types of uniform state variables.")
	.value("OpenGl_LIGHT_SOURCES_STATE", OpenGl_UniformStateType::OpenGl_LIGHT_SOURCES_STATE)
	.value("OpenGl_CLIP_PLANES_STATE", OpenGl_UniformStateType::OpenGl_CLIP_PLANES_STATE)
	.value("OpenGl_MODEL_WORLD_STATE", OpenGl_UniformStateType::OpenGl_MODEL_WORLD_STATE)
	.value("OpenGl_WORLD_VIEW_STATE", OpenGl_UniformStateType::OpenGl_WORLD_VIEW_STATE)
	.value("OpenGl_PROJECTION_STATE", OpenGl_UniformStateType::OpenGl_PROJECTION_STATE)
	.value("OpenGl_MATERIAL_STATE", OpenGl_UniformStateType::OpenGl_MATERIAL_STATE)
	.value("OpenGl_SURF_DETAIL_STATE", OpenGl_UniformStateType::OpenGl_SURF_DETAIL_STATE)
	.value("OpenGL_OIT_STATE", OpenGl_UniformStateType::OpenGL_OIT_STATE)
	.value("OpenGl_UniformStateType_NB", OpenGl_UniformStateType::OpenGl_UniformStateType_NB)
	.export_values();


// ENUM: OPENGL_LAYERFILTER
py::enum_<OpenGl_LayerFilter>(mod, "OpenGl_LayerFilter", "Tool object to specify processed OpenGL layers for intermixed rendering of raytracable and non-raytracable layers.")
	.value("OpenGl_LF_All", OpenGl_LayerFilter::OpenGl_LF_All)
	.value("OpenGl_LF_Upper", OpenGl_LayerFilter::OpenGl_LF_Upper)
	.value("OpenGl_LF_Bottom", OpenGl_LayerFilter::OpenGl_LF_Bottom)
	.value("OpenGl_LF_RayTracable", OpenGl_LayerFilter::OpenGl_LF_RayTracable)
	.export_values();


// ENUM: OPENGL_PROGRAMOPTIONS
py::enum_<OpenGl_ProgramOptions>(mod, "OpenGl_ProgramOptions", "Standard GLSL program combination bits.")
	.value("OpenGl_PO_VertColor", OpenGl_ProgramOptions::OpenGl_PO_VertColor)
	.value("OpenGl_PO_TextureRGB", OpenGl_ProgramOptions::OpenGl_PO_TextureRGB)
	.value("OpenGl_PO_PointSimple", OpenGl_ProgramOptions::OpenGl_PO_PointSimple)
	.value("OpenGl_PO_PointSprite", OpenGl_ProgramOptions::OpenGl_PO_PointSprite)
	.value("OpenGl_PO_PointSpriteA", OpenGl_ProgramOptions::OpenGl_PO_PointSpriteA)
	.value("OpenGl_PO_TextureEnv", OpenGl_ProgramOptions::OpenGl_PO_TextureEnv)
	.value("OpenGl_PO_StippleLine", OpenGl_ProgramOptions::OpenGl_PO_StippleLine)
	.value("OpenGl_PO_ClipPlanes1", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanes1)
	.value("OpenGl_PO_ClipPlanes2", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanes2)
	.value("OpenGl_PO_ClipPlanesN", OpenGl_ProgramOptions::OpenGl_PO_ClipPlanesN)
	.value("OpenGl_PO_ClipChains", OpenGl_ProgramOptions::OpenGl_PO_ClipChains)
	.value("OpenGl_PO_MeshEdges", OpenGl_ProgramOptions::OpenGl_PO_MeshEdges)
	.value("OpenGl_PO_AlphaTest", OpenGl_ProgramOptions::OpenGl_PO_AlphaTest)
	.value("OpenGl_PO_WriteOit", OpenGl_ProgramOptions::OpenGl_PO_WriteOit)
	.value("OpenGl_PO_NB", OpenGl_ProgramOptions::OpenGl_PO_NB)
	.value("OpenGl_PO_IsPoint", OpenGl_ProgramOptions::OpenGl_PO_IsPoint)
	.value("OpenGl_PO_HasTextures", OpenGl_ProgramOptions::OpenGl_PO_HasTextures)
	.value("OpenGl_PO_NeedsGeomShader", OpenGl_ProgramOptions::OpenGl_PO_NeedsGeomShader)
	.export_values();


// CLASS: OPENGL_GLFUNCTIONS
py::class_<OpenGl_GlFunctions> cls_OpenGl_GlFunctions(mod, "OpenGl_GlFunctions", "Mega structure defines the complete list of OpenGL functions.");

// Constructors
cls_OpenGl_GlFunctions.def(py::init<>());

// Fields
cls_OpenGl_GlFunctions.def_readwrite("glBlendColor", &OpenGl_GlFunctions::glBlendColor, "");
cls_OpenGl_GlFunctions.def_readwrite("glBlendEquation", &OpenGl_GlFunctions::glBlendEquation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawRangeElements", &OpenGl_GlFunctions::glDrawRangeElements, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexImage3D", &OpenGl_GlFunctions::glTexImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexSubImage3D", &OpenGl_GlFunctions::glTexSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyTexSubImage3D", &OpenGl_GlFunctions::glCopyTexSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glActiveTexture", &OpenGl_GlFunctions::glActiveTexture, "");
cls_OpenGl_GlFunctions.def_readwrite("glSampleCoverage", &OpenGl_GlFunctions::glSampleCoverage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexImage3D", &OpenGl_GlFunctions::glCompressedTexImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexImage2D", &OpenGl_GlFunctions::glCompressedTexImage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexImage1D", &OpenGl_GlFunctions::glCompressedTexImage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexSubImage3D", &OpenGl_GlFunctions::glCompressedTexSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexSubImage2D", &OpenGl_GlFunctions::glCompressedTexSubImage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTexSubImage1D", &OpenGl_GlFunctions::glCompressedTexSubImage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetCompressedTexImage", &OpenGl_GlFunctions::glGetCompressedTexImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClientActiveTexture", &OpenGl_GlFunctions::glClientActiveTexture, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1d", &OpenGl_GlFunctions::glMultiTexCoord1d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1dv", &OpenGl_GlFunctions::glMultiTexCoord1dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1f", &OpenGl_GlFunctions::glMultiTexCoord1f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1fv", &OpenGl_GlFunctions::glMultiTexCoord1fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1i", &OpenGl_GlFunctions::glMultiTexCoord1i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1iv", &OpenGl_GlFunctions::glMultiTexCoord1iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1s", &OpenGl_GlFunctions::glMultiTexCoord1s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord1sv", &OpenGl_GlFunctions::glMultiTexCoord1sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2d", &OpenGl_GlFunctions::glMultiTexCoord2d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2dv", &OpenGl_GlFunctions::glMultiTexCoord2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2f", &OpenGl_GlFunctions::glMultiTexCoord2f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2fv", &OpenGl_GlFunctions::glMultiTexCoord2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2i", &OpenGl_GlFunctions::glMultiTexCoord2i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2iv", &OpenGl_GlFunctions::glMultiTexCoord2iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2s", &OpenGl_GlFunctions::glMultiTexCoord2s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord2sv", &OpenGl_GlFunctions::glMultiTexCoord2sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3d", &OpenGl_GlFunctions::glMultiTexCoord3d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3dv", &OpenGl_GlFunctions::glMultiTexCoord3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3f", &OpenGl_GlFunctions::glMultiTexCoord3f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3fv", &OpenGl_GlFunctions::glMultiTexCoord3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3i", &OpenGl_GlFunctions::glMultiTexCoord3i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3iv", &OpenGl_GlFunctions::glMultiTexCoord3iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3s", &OpenGl_GlFunctions::glMultiTexCoord3s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord3sv", &OpenGl_GlFunctions::glMultiTexCoord3sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4d", &OpenGl_GlFunctions::glMultiTexCoord4d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4dv", &OpenGl_GlFunctions::glMultiTexCoord4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4f", &OpenGl_GlFunctions::glMultiTexCoord4f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4fv", &OpenGl_GlFunctions::glMultiTexCoord4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4i", &OpenGl_GlFunctions::glMultiTexCoord4i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4iv", &OpenGl_GlFunctions::glMultiTexCoord4iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4s", &OpenGl_GlFunctions::glMultiTexCoord4s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoord4sv", &OpenGl_GlFunctions::glMultiTexCoord4sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glLoadTransposeMatrixf", &OpenGl_GlFunctions::glLoadTransposeMatrixf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glLoadTransposeMatrixd", &OpenGl_GlFunctions::glLoadTransposeMatrixd, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultTransposeMatrixf", &OpenGl_GlFunctions::glMultTransposeMatrixf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultTransposeMatrixd", &OpenGl_GlFunctions::glMultTransposeMatrixd, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlendFuncSeparate", &OpenGl_GlFunctions::glBlendFuncSeparate, "");
cls_OpenGl_GlFunctions.def_readwrite("glMultiDrawArrays", &OpenGl_GlFunctions::glMultiDrawArrays, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiDrawElements", &OpenGl_GlFunctions::glMultiDrawElements, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPointParameterf", &OpenGl_GlFunctions::glPointParameterf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPointParameterfv", &OpenGl_GlFunctions::glPointParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPointParameteri", &OpenGl_GlFunctions::glPointParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPointParameteriv", &OpenGl_GlFunctions::glPointParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenQueries", &OpenGl_GlFunctions::glGenQueries, "");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteQueries", &OpenGl_GlFunctions::glDeleteQueries, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsQuery", &OpenGl_GlFunctions::glIsQuery, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBeginQuery", &OpenGl_GlFunctions::glBeginQuery, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEndQuery", &OpenGl_GlFunctions::glEndQuery, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryiv", &OpenGl_GlFunctions::glGetQueryiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryObjectiv", &OpenGl_GlFunctions::glGetQueryObjectiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryObjectuiv", &OpenGl_GlFunctions::glGetQueryObjectuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindBuffer", &OpenGl_GlFunctions::glBindBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteBuffers", &OpenGl_GlFunctions::glDeleteBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenBuffers", &OpenGl_GlFunctions::glGenBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsBuffer", &OpenGl_GlFunctions::glIsBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBufferData", &OpenGl_GlFunctions::glBufferData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBufferSubData", &OpenGl_GlFunctions::glBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetBufferSubData", &OpenGl_GlFunctions::glGetBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMapBuffer", &OpenGl_GlFunctions::glMapBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUnmapBuffer", &OpenGl_GlFunctions::glUnmapBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetBufferParameteriv", &OpenGl_GlFunctions::glGetBufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetBufferPointerv", &OpenGl_GlFunctions::glGetBufferPointerv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlendEquationSeparate", &OpenGl_GlFunctions::glBlendEquationSeparate, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawBuffers", &OpenGl_GlFunctions::glDrawBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glStencilOpSeparate", &OpenGl_GlFunctions::glStencilOpSeparate, "None");
cls_OpenGl_GlFunctions.def_readwrite("glStencilFuncSeparate", &OpenGl_GlFunctions::glStencilFuncSeparate, "None");
cls_OpenGl_GlFunctions.def_readwrite("glStencilMaskSeparate", &OpenGl_GlFunctions::glStencilMaskSeparate, "None");
cls_OpenGl_GlFunctions.def_readwrite("glAttachShader", &OpenGl_GlFunctions::glAttachShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindAttribLocation", &OpenGl_GlFunctions::glBindAttribLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompileShader", &OpenGl_GlFunctions::glCompileShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateProgram", &OpenGl_GlFunctions::glCreateProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateShader", &OpenGl_GlFunctions::glCreateShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteProgram", &OpenGl_GlFunctions::glDeleteProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteShader", &OpenGl_GlFunctions::glDeleteShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDetachShader", &OpenGl_GlFunctions::glDetachShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDisableVertexAttribArray", &OpenGl_GlFunctions::glDisableVertexAttribArray, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEnableVertexAttribArray", &OpenGl_GlFunctions::glEnableVertexAttribArray, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveAttrib", &OpenGl_GlFunctions::glGetActiveAttrib, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveUniform", &OpenGl_GlFunctions::glGetActiveUniform, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetAttachedShaders", &OpenGl_GlFunctions::glGetAttachedShaders, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetAttribLocation", &OpenGl_GlFunctions::glGetAttribLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramiv", &OpenGl_GlFunctions::glGetProgramiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramInfoLog", &OpenGl_GlFunctions::glGetProgramInfoLog, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetShaderiv", &OpenGl_GlFunctions::glGetShaderiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetShaderInfoLog", &OpenGl_GlFunctions::glGetShaderInfoLog, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetShaderSource", &OpenGl_GlFunctions::glGetShaderSource, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformLocation", &OpenGl_GlFunctions::glGetUniformLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformfv", &OpenGl_GlFunctions::glGetUniformfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformiv", &OpenGl_GlFunctions::glGetUniformiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribdv", &OpenGl_GlFunctions::glGetVertexAttribdv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribfv", &OpenGl_GlFunctions::glGetVertexAttribfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribiv", &OpenGl_GlFunctions::glGetVertexAttribiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribPointerv", &OpenGl_GlFunctions::glGetVertexAttribPointerv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsProgram", &OpenGl_GlFunctions::glIsProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsShader", &OpenGl_GlFunctions::glIsShader, "None");
cls_OpenGl_GlFunctions.def_readwrite("glLinkProgram", &OpenGl_GlFunctions::glLinkProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glShaderSource", &OpenGl_GlFunctions::glShaderSource, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUseProgram", &OpenGl_GlFunctions::glUseProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1f", &OpenGl_GlFunctions::glUniform1f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2f", &OpenGl_GlFunctions::glUniform2f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3f", &OpenGl_GlFunctions::glUniform3f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4f", &OpenGl_GlFunctions::glUniform4f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1i", &OpenGl_GlFunctions::glUniform1i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2i", &OpenGl_GlFunctions::glUniform2i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3i", &OpenGl_GlFunctions::glUniform3i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4i", &OpenGl_GlFunctions::glUniform4i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1fv", &OpenGl_GlFunctions::glUniform1fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2fv", &OpenGl_GlFunctions::glUniform2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3fv", &OpenGl_GlFunctions::glUniform3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4fv", &OpenGl_GlFunctions::glUniform4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1iv", &OpenGl_GlFunctions::glUniform1iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2iv", &OpenGl_GlFunctions::glUniform2iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3iv", &OpenGl_GlFunctions::glUniform3iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4iv", &OpenGl_GlFunctions::glUniform4iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2fv", &OpenGl_GlFunctions::glUniformMatrix2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3fv", &OpenGl_GlFunctions::glUniformMatrix3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4fv", &OpenGl_GlFunctions::glUniformMatrix4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glValidateProgram", &OpenGl_GlFunctions::glValidateProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1d", &OpenGl_GlFunctions::glVertexAttrib1d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1dv", &OpenGl_GlFunctions::glVertexAttrib1dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1f", &OpenGl_GlFunctions::glVertexAttrib1f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1fv", &OpenGl_GlFunctions::glVertexAttrib1fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1s", &OpenGl_GlFunctions::glVertexAttrib1s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib1sv", &OpenGl_GlFunctions::glVertexAttrib1sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2d", &OpenGl_GlFunctions::glVertexAttrib2d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2dv", &OpenGl_GlFunctions::glVertexAttrib2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2f", &OpenGl_GlFunctions::glVertexAttrib2f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2fv", &OpenGl_GlFunctions::glVertexAttrib2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2s", &OpenGl_GlFunctions::glVertexAttrib2s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib2sv", &OpenGl_GlFunctions::glVertexAttrib2sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3d", &OpenGl_GlFunctions::glVertexAttrib3d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3dv", &OpenGl_GlFunctions::glVertexAttrib3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3f", &OpenGl_GlFunctions::glVertexAttrib3f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3fv", &OpenGl_GlFunctions::glVertexAttrib3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3s", &OpenGl_GlFunctions::glVertexAttrib3s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib3sv", &OpenGl_GlFunctions::glVertexAttrib3sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nbv", &OpenGl_GlFunctions::glVertexAttrib4Nbv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Niv", &OpenGl_GlFunctions::glVertexAttrib4Niv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nsv", &OpenGl_GlFunctions::glVertexAttrib4Nsv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nub", &OpenGl_GlFunctions::glVertexAttrib4Nub, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nubv", &OpenGl_GlFunctions::glVertexAttrib4Nubv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nuiv", &OpenGl_GlFunctions::glVertexAttrib4Nuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4Nusv", &OpenGl_GlFunctions::glVertexAttrib4Nusv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4bv", &OpenGl_GlFunctions::glVertexAttrib4bv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4d", &OpenGl_GlFunctions::glVertexAttrib4d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4dv", &OpenGl_GlFunctions::glVertexAttrib4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4f", &OpenGl_GlFunctions::glVertexAttrib4f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4fv", &OpenGl_GlFunctions::glVertexAttrib4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4iv", &OpenGl_GlFunctions::glVertexAttrib4iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4s", &OpenGl_GlFunctions::glVertexAttrib4s, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4sv", &OpenGl_GlFunctions::glVertexAttrib4sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4ubv", &OpenGl_GlFunctions::glVertexAttrib4ubv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4uiv", &OpenGl_GlFunctions::glVertexAttrib4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttrib4usv", &OpenGl_GlFunctions::glVertexAttrib4usv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribPointer", &OpenGl_GlFunctions::glVertexAttribPointer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2x3fv", &OpenGl_GlFunctions::glUniformMatrix2x3fv, "");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3x2fv", &OpenGl_GlFunctions::glUniformMatrix3x2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2x4fv", &OpenGl_GlFunctions::glUniformMatrix2x4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4x2fv", &OpenGl_GlFunctions::glUniformMatrix4x2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3x4fv", &OpenGl_GlFunctions::glUniformMatrix3x4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4x3fv", &OpenGl_GlFunctions::glUniformMatrix4x3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsRenderbuffer", &OpenGl_GlFunctions::glIsRenderbuffer, "");
cls_OpenGl_GlFunctions.def_readwrite("glBindRenderbuffer", &OpenGl_GlFunctions::glBindRenderbuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteRenderbuffers", &OpenGl_GlFunctions::glDeleteRenderbuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenRenderbuffers", &OpenGl_GlFunctions::glGenRenderbuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glRenderbufferStorage", &OpenGl_GlFunctions::glRenderbufferStorage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetRenderbufferParameteriv", &OpenGl_GlFunctions::glGetRenderbufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsFramebuffer", &OpenGl_GlFunctions::glIsFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindFramebuffer", &OpenGl_GlFunctions::glBindFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteFramebuffers", &OpenGl_GlFunctions::glDeleteFramebuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenFramebuffers", &OpenGl_GlFunctions::glGenFramebuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCheckFramebufferStatus", &OpenGl_GlFunctions::glCheckFramebufferStatus, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferTexture1D", &OpenGl_GlFunctions::glFramebufferTexture1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferTexture2D", &OpenGl_GlFunctions::glFramebufferTexture2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferTexture3D", &OpenGl_GlFunctions::glFramebufferTexture3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferRenderbuffer", &OpenGl_GlFunctions::glFramebufferRenderbuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetFramebufferAttachmentParameteriv", &OpenGl_GlFunctions::glGetFramebufferAttachmentParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenerateMipmap", &OpenGl_GlFunctions::glGenerateMipmap, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlitFramebuffer", &OpenGl_GlFunctions::glBlitFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glRenderbufferStorageMultisample", &OpenGl_GlFunctions::glRenderbufferStorageMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferTextureLayer", &OpenGl_GlFunctions::glFramebufferTextureLayer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindVertexArray", &OpenGl_GlFunctions::glBindVertexArray, "");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteVertexArrays", &OpenGl_GlFunctions::glDeleteVertexArrays, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenVertexArrays", &OpenGl_GlFunctions::glGenVertexArrays, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsVertexArray", &OpenGl_GlFunctions::glIsVertexArray, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMapBufferRange", &OpenGl_GlFunctions::glMapBufferRange, "");
cls_OpenGl_GlFunctions.def_readwrite("glFlushMappedBufferRange", &OpenGl_GlFunctions::glFlushMappedBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glColorMaski", &OpenGl_GlFunctions::glColorMaski, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetBooleani_v", &OpenGl_GlFunctions::glGetBooleani_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetIntegeri_v", &OpenGl_GlFunctions::glGetIntegeri_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEnablei", &OpenGl_GlFunctions::glEnablei, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDisablei", &OpenGl_GlFunctions::glDisablei, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsEnabledi", &OpenGl_GlFunctions::glIsEnabledi, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBeginTransformFeedback", &OpenGl_GlFunctions::glBeginTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEndTransformFeedback", &OpenGl_GlFunctions::glEndTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindBufferRange", &OpenGl_GlFunctions::glBindBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindBufferBase", &OpenGl_GlFunctions::glBindBufferBase, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTransformFeedbackVaryings", &OpenGl_GlFunctions::glTransformFeedbackVaryings, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTransformFeedbackVarying", &OpenGl_GlFunctions::glGetTransformFeedbackVarying, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClampColor", &OpenGl_GlFunctions::glClampColor, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBeginConditionalRender", &OpenGl_GlFunctions::glBeginConditionalRender, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEndConditionalRender", &OpenGl_GlFunctions::glEndConditionalRender, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribIPointer", &OpenGl_GlFunctions::glVertexAttribIPointer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribIiv", &OpenGl_GlFunctions::glGetVertexAttribIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribIuiv", &OpenGl_GlFunctions::glGetVertexAttribIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI1i", &OpenGl_GlFunctions::glVertexAttribI1i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI2i", &OpenGl_GlFunctions::glVertexAttribI2i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI3i", &OpenGl_GlFunctions::glVertexAttribI3i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4i", &OpenGl_GlFunctions::glVertexAttribI4i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI1ui", &OpenGl_GlFunctions::glVertexAttribI1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI2ui", &OpenGl_GlFunctions::glVertexAttribI2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI3ui", &OpenGl_GlFunctions::glVertexAttribI3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4ui", &OpenGl_GlFunctions::glVertexAttribI4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI1iv", &OpenGl_GlFunctions::glVertexAttribI1iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI2iv", &OpenGl_GlFunctions::glVertexAttribI2iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI3iv", &OpenGl_GlFunctions::glVertexAttribI3iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4iv", &OpenGl_GlFunctions::glVertexAttribI4iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI1uiv", &OpenGl_GlFunctions::glVertexAttribI1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI2uiv", &OpenGl_GlFunctions::glVertexAttribI2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI3uiv", &OpenGl_GlFunctions::glVertexAttribI3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4uiv", &OpenGl_GlFunctions::glVertexAttribI4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4bv", &OpenGl_GlFunctions::glVertexAttribI4bv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4sv", &OpenGl_GlFunctions::glVertexAttribI4sv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4ubv", &OpenGl_GlFunctions::glVertexAttribI4ubv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribI4usv", &OpenGl_GlFunctions::glVertexAttribI4usv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformuiv", &OpenGl_GlFunctions::glGetUniformuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindFragDataLocation", &OpenGl_GlFunctions::glBindFragDataLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetFragDataLocation", &OpenGl_GlFunctions::glGetFragDataLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1ui", &OpenGl_GlFunctions::glUniform1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2ui", &OpenGl_GlFunctions::glUniform2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3ui", &OpenGl_GlFunctions::glUniform3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4ui", &OpenGl_GlFunctions::glUniform4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1uiv", &OpenGl_GlFunctions::glUniform1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2uiv", &OpenGl_GlFunctions::glUniform2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3uiv", &OpenGl_GlFunctions::glUniform3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4uiv", &OpenGl_GlFunctions::glUniform4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexParameterIiv", &OpenGl_GlFunctions::glTexParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexParameterIuiv", &OpenGl_GlFunctions::glTexParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTexParameterIiv", &OpenGl_GlFunctions::glGetTexParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTexParameterIuiv", &OpenGl_GlFunctions::glGetTexParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferiv", &OpenGl_GlFunctions::glClearBufferiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferuiv", &OpenGl_GlFunctions::glClearBufferuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferfv", &OpenGl_GlFunctions::glClearBufferfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferfi", &OpenGl_GlFunctions::glClearBufferfi, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetStringi", &OpenGl_GlFunctions::glGetStringi, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformIndices", &OpenGl_GlFunctions::glGetUniformIndices, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveUniformsiv", &OpenGl_GlFunctions::glGetActiveUniformsiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveUniformName", &OpenGl_GlFunctions::glGetActiveUniformName, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformBlockIndex", &OpenGl_GlFunctions::glGetUniformBlockIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveUniformBlockiv", &OpenGl_GlFunctions::glGetActiveUniformBlockiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveUniformBlockName", &OpenGl_GlFunctions::glGetActiveUniformBlockName, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformBlockBinding", &OpenGl_GlFunctions::glUniformBlockBinding, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyBufferSubData", &OpenGl_GlFunctions::glCopyBufferSubData, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawArraysInstanced", &OpenGl_GlFunctions::glDrawArraysInstanced, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsInstanced", &OpenGl_GlFunctions::glDrawElementsInstanced, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexBuffer", &OpenGl_GlFunctions::glTexBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPrimitiveRestartIndex", &OpenGl_GlFunctions::glPrimitiveRestartIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsBaseVertex", &OpenGl_GlFunctions::glDrawElementsBaseVertex, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawRangeElementsBaseVertex", &OpenGl_GlFunctions::glDrawRangeElementsBaseVertex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsInstancedBaseVertex", &OpenGl_GlFunctions::glDrawElementsInstancedBaseVertex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiDrawElementsBaseVertex", &OpenGl_GlFunctions::glMultiDrawElementsBaseVertex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProvokingVertex", &OpenGl_GlFunctions::glProvokingVertex, "");
cls_OpenGl_GlFunctions.def_readwrite("glFenceSync", &OpenGl_GlFunctions::glFenceSync, "");
cls_OpenGl_GlFunctions.def_readwrite("glIsSync", &OpenGl_GlFunctions::glIsSync, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteSync", &OpenGl_GlFunctions::glDeleteSync, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClientWaitSync", &OpenGl_GlFunctions::glClientWaitSync, "None");
cls_OpenGl_GlFunctions.def_readwrite("glWaitSync", &OpenGl_GlFunctions::glWaitSync, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetInteger64v", &OpenGl_GlFunctions::glGetInteger64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSynciv", &OpenGl_GlFunctions::glGetSynciv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexImage2DMultisample", &OpenGl_GlFunctions::glTexImage2DMultisample, "");
cls_OpenGl_GlFunctions.def_readwrite("glTexImage3DMultisample", &OpenGl_GlFunctions::glTexImage3DMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetMultisamplefv", &OpenGl_GlFunctions::glGetMultisamplefv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSampleMaski", &OpenGl_GlFunctions::glSampleMaski, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetInteger64i_v", &OpenGl_GlFunctions::glGetInteger64i_v, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetBufferParameteri64v", &OpenGl_GlFunctions::glGetBufferParameteri64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferTexture", &OpenGl_GlFunctions::glFramebufferTexture, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindFragDataLocationIndexed", &OpenGl_GlFunctions::glBindFragDataLocationIndexed, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetFragDataIndex", &OpenGl_GlFunctions::glGetFragDataIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenSamplers", &OpenGl_GlFunctions::glGenSamplers, "");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteSamplers", &OpenGl_GlFunctions::glDeleteSamplers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsSampler", &OpenGl_GlFunctions::glIsSampler, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindSampler", &OpenGl_GlFunctions::glBindSampler, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameteri", &OpenGl_GlFunctions::glSamplerParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameteriv", &OpenGl_GlFunctions::glSamplerParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameterf", &OpenGl_GlFunctions::glSamplerParameterf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameterfv", &OpenGl_GlFunctions::glSamplerParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameterIiv", &OpenGl_GlFunctions::glSamplerParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSamplerParameterIuiv", &OpenGl_GlFunctions::glSamplerParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSamplerParameteriv", &OpenGl_GlFunctions::glGetSamplerParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSamplerParameterIiv", &OpenGl_GlFunctions::glGetSamplerParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSamplerParameterfv", &OpenGl_GlFunctions::glGetSamplerParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSamplerParameterIuiv", &OpenGl_GlFunctions::glGetSamplerParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glQueryCounter", &OpenGl_GlFunctions::glQueryCounter, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryObjecti64v", &OpenGl_GlFunctions::glGetQueryObjecti64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryObjectui64v", &OpenGl_GlFunctions::glGetQueryObjectui64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP2ui", &OpenGl_GlFunctions::glVertexP2ui, "");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP2uiv", &OpenGl_GlFunctions::glVertexP2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP3ui", &OpenGl_GlFunctions::glVertexP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP3uiv", &OpenGl_GlFunctions::glVertexP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP4ui", &OpenGl_GlFunctions::glVertexP4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexP4uiv", &OpenGl_GlFunctions::glVertexP4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP1ui", &OpenGl_GlFunctions::glTexCoordP1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP1uiv", &OpenGl_GlFunctions::glTexCoordP1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP2ui", &OpenGl_GlFunctions::glTexCoordP2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP2uiv", &OpenGl_GlFunctions::glTexCoordP2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP3ui", &OpenGl_GlFunctions::glTexCoordP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP3uiv", &OpenGl_GlFunctions::glTexCoordP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP4ui", &OpenGl_GlFunctions::glTexCoordP4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexCoordP4uiv", &OpenGl_GlFunctions::glTexCoordP4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP1ui", &OpenGl_GlFunctions::glMultiTexCoordP1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP1uiv", &OpenGl_GlFunctions::glMultiTexCoordP1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP2ui", &OpenGl_GlFunctions::glMultiTexCoordP2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP2uiv", &OpenGl_GlFunctions::glMultiTexCoordP2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP3ui", &OpenGl_GlFunctions::glMultiTexCoordP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP3uiv", &OpenGl_GlFunctions::glMultiTexCoordP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP4ui", &OpenGl_GlFunctions::glMultiTexCoordP4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiTexCoordP4uiv", &OpenGl_GlFunctions::glMultiTexCoordP4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNormalP3ui", &OpenGl_GlFunctions::glNormalP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNormalP3uiv", &OpenGl_GlFunctions::glNormalP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glColorP3ui", &OpenGl_GlFunctions::glColorP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glColorP3uiv", &OpenGl_GlFunctions::glColorP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glColorP4ui", &OpenGl_GlFunctions::glColorP4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glColorP4uiv", &OpenGl_GlFunctions::glColorP4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSecondaryColorP3ui", &OpenGl_GlFunctions::glSecondaryColorP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glSecondaryColorP3uiv", &OpenGl_GlFunctions::glSecondaryColorP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP1ui", &OpenGl_GlFunctions::glVertexAttribP1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP1uiv", &OpenGl_GlFunctions::glVertexAttribP1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP2ui", &OpenGl_GlFunctions::glVertexAttribP2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP2uiv", &OpenGl_GlFunctions::glVertexAttribP2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP3ui", &OpenGl_GlFunctions::glVertexAttribP3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP3uiv", &OpenGl_GlFunctions::glVertexAttribP3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP4ui", &OpenGl_GlFunctions::glVertexAttribP4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribP4uiv", &OpenGl_GlFunctions::glVertexAttribP4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribDivisor", &OpenGl_GlFunctions::glVertexAttribDivisor, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawArraysIndirect", &OpenGl_GlFunctions::glDrawArraysIndirect, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsIndirect", &OpenGl_GlFunctions::glDrawElementsIndirect, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1d", &OpenGl_GlFunctions::glUniform1d, "");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2d", &OpenGl_GlFunctions::glUniform2d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3d", &OpenGl_GlFunctions::glUniform3d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4d", &OpenGl_GlFunctions::glUniform4d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform1dv", &OpenGl_GlFunctions::glUniform1dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform2dv", &OpenGl_GlFunctions::glUniform2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform3dv", &OpenGl_GlFunctions::glUniform3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniform4dv", &OpenGl_GlFunctions::glUniform4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2dv", &OpenGl_GlFunctions::glUniformMatrix2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3dv", &OpenGl_GlFunctions::glUniformMatrix3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4dv", &OpenGl_GlFunctions::glUniformMatrix4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2x3dv", &OpenGl_GlFunctions::glUniformMatrix2x3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix2x4dv", &OpenGl_GlFunctions::glUniformMatrix2x4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3x2dv", &OpenGl_GlFunctions::glUniformMatrix3x2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix3x4dv", &OpenGl_GlFunctions::glUniformMatrix3x4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4x2dv", &OpenGl_GlFunctions::glUniformMatrix4x2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformMatrix4x3dv", &OpenGl_GlFunctions::glUniformMatrix4x3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformdv", &OpenGl_GlFunctions::glGetUniformdv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetSubroutineUniformLocation", &OpenGl_GlFunctions::glGetSubroutineUniformLocation, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetSubroutineIndex", &OpenGl_GlFunctions::glGetSubroutineIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveSubroutineUniformiv", &OpenGl_GlFunctions::glGetActiveSubroutineUniformiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveSubroutineUniformName", &OpenGl_GlFunctions::glGetActiveSubroutineUniformName, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveSubroutineName", &OpenGl_GlFunctions::glGetActiveSubroutineName, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformSubroutinesuiv", &OpenGl_GlFunctions::glUniformSubroutinesuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetUniformSubroutineuiv", &OpenGl_GlFunctions::glGetUniformSubroutineuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramStageiv", &OpenGl_GlFunctions::glGetProgramStageiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPatchParameteri", &OpenGl_GlFunctions::glPatchParameteri, "");
cls_OpenGl_GlFunctions.def_readwrite("glPatchParameterfv", &OpenGl_GlFunctions::glPatchParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindTransformFeedback", &OpenGl_GlFunctions::glBindTransformFeedback, "");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteTransformFeedbacks", &OpenGl_GlFunctions::glDeleteTransformFeedbacks, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenTransformFeedbacks", &OpenGl_GlFunctions::glGenTransformFeedbacks, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsTransformFeedback", &OpenGl_GlFunctions::glIsTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPauseTransformFeedback", &OpenGl_GlFunctions::glPauseTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glResumeTransformFeedback", &OpenGl_GlFunctions::glResumeTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawTransformFeedback", &OpenGl_GlFunctions::glDrawTransformFeedback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawTransformFeedbackStream", &OpenGl_GlFunctions::glDrawTransformFeedbackStream, "");
cls_OpenGl_GlFunctions.def_readwrite("glBeginQueryIndexed", &OpenGl_GlFunctions::glBeginQueryIndexed, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEndQueryIndexed", &OpenGl_GlFunctions::glEndQueryIndexed, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryIndexediv", &OpenGl_GlFunctions::glGetQueryIndexediv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMinSampleShading", &OpenGl_GlFunctions::glMinSampleShading, "");
cls_OpenGl_GlFunctions.def_readwrite("glBlendEquationi", &OpenGl_GlFunctions::glBlendEquationi, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlendEquationSeparatei", &OpenGl_GlFunctions::glBlendEquationSeparatei, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlendFunci", &OpenGl_GlFunctions::glBlendFunci, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlendFuncSeparatei", &OpenGl_GlFunctions::glBlendFuncSeparatei, "None");
cls_OpenGl_GlFunctions.def_readwrite("glReleaseShaderCompiler", &OpenGl_GlFunctions::glReleaseShaderCompiler, "");
cls_OpenGl_GlFunctions.def_readwrite("glShaderBinary", &OpenGl_GlFunctions::glShaderBinary, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetShaderPrecisionFormat", &OpenGl_GlFunctions::glGetShaderPrecisionFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDepthRangef", &OpenGl_GlFunctions::glDepthRangef, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearDepthf", &OpenGl_GlFunctions::glClearDepthf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramBinary", &OpenGl_GlFunctions::glGetProgramBinary, "");
cls_OpenGl_GlFunctions.def_readwrite("glProgramBinary", &OpenGl_GlFunctions::glProgramBinary, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramParameteri", &OpenGl_GlFunctions::glProgramParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUseProgramStages", &OpenGl_GlFunctions::glUseProgramStages, "");
cls_OpenGl_GlFunctions.def_readwrite("glActiveShaderProgram", &OpenGl_GlFunctions::glActiveShaderProgram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateShaderProgramv", &OpenGl_GlFunctions::glCreateShaderProgramv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindProgramPipeline", &OpenGl_GlFunctions::glBindProgramPipeline, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDeleteProgramPipelines", &OpenGl_GlFunctions::glDeleteProgramPipelines, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenProgramPipelines", &OpenGl_GlFunctions::glGenProgramPipelines, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsProgramPipeline", &OpenGl_GlFunctions::glIsProgramPipeline, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramPipelineiv", &OpenGl_GlFunctions::glGetProgramPipelineiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1i", &OpenGl_GlFunctions::glProgramUniform1i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1iv", &OpenGl_GlFunctions::glProgramUniform1iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1f", &OpenGl_GlFunctions::glProgramUniform1f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1fv", &OpenGl_GlFunctions::glProgramUniform1fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1d", &OpenGl_GlFunctions::glProgramUniform1d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1dv", &OpenGl_GlFunctions::glProgramUniform1dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1ui", &OpenGl_GlFunctions::glProgramUniform1ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform1uiv", &OpenGl_GlFunctions::glProgramUniform1uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2i", &OpenGl_GlFunctions::glProgramUniform2i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2iv", &OpenGl_GlFunctions::glProgramUniform2iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2f", &OpenGl_GlFunctions::glProgramUniform2f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2fv", &OpenGl_GlFunctions::glProgramUniform2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2d", &OpenGl_GlFunctions::glProgramUniform2d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2dv", &OpenGl_GlFunctions::glProgramUniform2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2ui", &OpenGl_GlFunctions::glProgramUniform2ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform2uiv", &OpenGl_GlFunctions::glProgramUniform2uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3i", &OpenGl_GlFunctions::glProgramUniform3i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3iv", &OpenGl_GlFunctions::glProgramUniform3iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3f", &OpenGl_GlFunctions::glProgramUniform3f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3fv", &OpenGl_GlFunctions::glProgramUniform3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3d", &OpenGl_GlFunctions::glProgramUniform3d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3dv", &OpenGl_GlFunctions::glProgramUniform3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3ui", &OpenGl_GlFunctions::glProgramUniform3ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform3uiv", &OpenGl_GlFunctions::glProgramUniform3uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4i", &OpenGl_GlFunctions::glProgramUniform4i, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4iv", &OpenGl_GlFunctions::glProgramUniform4iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4f", &OpenGl_GlFunctions::glProgramUniform4f, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4fv", &OpenGl_GlFunctions::glProgramUniform4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4d", &OpenGl_GlFunctions::glProgramUniform4d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4dv", &OpenGl_GlFunctions::glProgramUniform4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4ui", &OpenGl_GlFunctions::glProgramUniform4ui, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniform4uiv", &OpenGl_GlFunctions::glProgramUniform4uiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2fv", &OpenGl_GlFunctions::glProgramUniformMatrix2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3fv", &OpenGl_GlFunctions::glProgramUniformMatrix3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4fv", &OpenGl_GlFunctions::glProgramUniformMatrix4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2dv", &OpenGl_GlFunctions::glProgramUniformMatrix2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3dv", &OpenGl_GlFunctions::glProgramUniformMatrix3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4dv", &OpenGl_GlFunctions::glProgramUniformMatrix4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2x3fv", &OpenGl_GlFunctions::glProgramUniformMatrix2x3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3x2fv", &OpenGl_GlFunctions::glProgramUniformMatrix3x2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2x4fv", &OpenGl_GlFunctions::glProgramUniformMatrix2x4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4x2fv", &OpenGl_GlFunctions::glProgramUniformMatrix4x2fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3x4fv", &OpenGl_GlFunctions::glProgramUniformMatrix3x4fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4x3fv", &OpenGl_GlFunctions::glProgramUniformMatrix4x3fv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2x3dv", &OpenGl_GlFunctions::glProgramUniformMatrix2x3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3x2dv", &OpenGl_GlFunctions::glProgramUniformMatrix3x2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix2x4dv", &OpenGl_GlFunctions::glProgramUniformMatrix2x4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4x2dv", &OpenGl_GlFunctions::glProgramUniformMatrix4x2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix3x4dv", &OpenGl_GlFunctions::glProgramUniformMatrix3x4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformMatrix4x3dv", &OpenGl_GlFunctions::glProgramUniformMatrix4x3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glValidateProgramPipeline", &OpenGl_GlFunctions::glValidateProgramPipeline, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramPipelineInfoLog", &OpenGl_GlFunctions::glGetProgramPipelineInfoLog, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL1d", &OpenGl_GlFunctions::glVertexAttribL1d, "");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL2d", &OpenGl_GlFunctions::glVertexAttribL2d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL3d", &OpenGl_GlFunctions::glVertexAttribL3d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL4d", &OpenGl_GlFunctions::glVertexAttribL4d, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL1dv", &OpenGl_GlFunctions::glVertexAttribL1dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL2dv", &OpenGl_GlFunctions::glVertexAttribL2dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL3dv", &OpenGl_GlFunctions::glVertexAttribL3dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL4dv", &OpenGl_GlFunctions::glVertexAttribL4dv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribLPointer", &OpenGl_GlFunctions::glVertexAttribLPointer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribLdv", &OpenGl_GlFunctions::glGetVertexAttribLdv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glViewportArrayv", &OpenGl_GlFunctions::glViewportArrayv, "");
cls_OpenGl_GlFunctions.def_readwrite("glViewportIndexedf", &OpenGl_GlFunctions::glViewportIndexedf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glViewportIndexedfv", &OpenGl_GlFunctions::glViewportIndexedfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glScissorArrayv", &OpenGl_GlFunctions::glScissorArrayv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glScissorIndexed", &OpenGl_GlFunctions::glScissorIndexed, "None");
cls_OpenGl_GlFunctions.def_readwrite("glScissorIndexedv", &OpenGl_GlFunctions::glScissorIndexedv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDepthRangeArrayv", &OpenGl_GlFunctions::glDepthRangeArrayv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDepthRangeIndexed", &OpenGl_GlFunctions::glDepthRangeIndexed, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetFloati_v", &OpenGl_GlFunctions::glGetFloati_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetDoublei_v", &OpenGl_GlFunctions::glGetDoublei_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawArraysInstancedBaseInstance", &OpenGl_GlFunctions::glDrawArraysInstancedBaseInstance, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsInstancedBaseInstance", &OpenGl_GlFunctions::glDrawElementsInstancedBaseInstance, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawElementsInstancedBaseVertexBaseInstance", &OpenGl_GlFunctions::glDrawElementsInstancedBaseVertexBaseInstance, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDrawTransformFeedbackInstanced", &OpenGl_GlFunctions::glDrawTransformFeedbackInstanced, "");
cls_OpenGl_GlFunctions.def_readwrite("glDrawTransformFeedbackStreamInstanced", &OpenGl_GlFunctions::glDrawTransformFeedbackStreamInstanced, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetInternalformativ", &OpenGl_GlFunctions::glGetInternalformativ, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetActiveAtomicCounterBufferiv", &OpenGl_GlFunctions::glGetActiveAtomicCounterBufferiv, "");
cls_OpenGl_GlFunctions.def_readwrite("glBindImageTexture", &OpenGl_GlFunctions::glBindImageTexture, "");
cls_OpenGl_GlFunctions.def_readwrite("glMemoryBarrier", &OpenGl_GlFunctions::glMemoryBarrier, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexStorage1D", &OpenGl_GlFunctions::glTexStorage1D, "");
cls_OpenGl_GlFunctions.def_readwrite("glTexStorage2D", &OpenGl_GlFunctions::glTexStorage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexStorage3D", &OpenGl_GlFunctions::glTexStorage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferData", &OpenGl_GlFunctions::glClearBufferData, "");
cls_OpenGl_GlFunctions.def_readwrite("glClearBufferSubData", &OpenGl_GlFunctions::glClearBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDispatchCompute", &OpenGl_GlFunctions::glDispatchCompute, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDispatchComputeIndirect", &OpenGl_GlFunctions::glDispatchComputeIndirect, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyImageSubData", &OpenGl_GlFunctions::glCopyImageSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFramebufferParameteri", &OpenGl_GlFunctions::glFramebufferParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetFramebufferParameteriv", &OpenGl_GlFunctions::glGetFramebufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetInternalformati64v", &OpenGl_GlFunctions::glGetInternalformati64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateTexSubImage", &OpenGl_GlFunctions::glInvalidateTexSubImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateTexImage", &OpenGl_GlFunctions::glInvalidateTexImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateBufferSubData", &OpenGl_GlFunctions::glInvalidateBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateBufferData", &OpenGl_GlFunctions::glInvalidateBufferData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateFramebuffer", &OpenGl_GlFunctions::glInvalidateFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateSubFramebuffer", &OpenGl_GlFunctions::glInvalidateSubFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiDrawArraysIndirect", &OpenGl_GlFunctions::glMultiDrawArraysIndirect, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMultiDrawElementsIndirect", &OpenGl_GlFunctions::glMultiDrawElementsIndirect, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramInterfaceiv", &OpenGl_GlFunctions::glGetProgramInterfaceiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramResourceIndex", &OpenGl_GlFunctions::glGetProgramResourceIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramResourceName", &OpenGl_GlFunctions::glGetProgramResourceName, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramResourceiv", &OpenGl_GlFunctions::glGetProgramResourceiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramResourceLocation", &OpenGl_GlFunctions::glGetProgramResourceLocation, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetProgramResourceLocationIndex", &OpenGl_GlFunctions::glGetProgramResourceLocationIndex, "None");
cls_OpenGl_GlFunctions.def_readwrite("glShaderStorageBlockBinding", &OpenGl_GlFunctions::glShaderStorageBlockBinding, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexBufferRange", &OpenGl_GlFunctions::glTexBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexStorage2DMultisample", &OpenGl_GlFunctions::glTexStorage2DMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTexStorage3DMultisample", &OpenGl_GlFunctions::glTexStorage3DMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureView", &OpenGl_GlFunctions::glTextureView, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindVertexBuffer", &OpenGl_GlFunctions::glBindVertexBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribFormat", &OpenGl_GlFunctions::glVertexAttribFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribIFormat", &OpenGl_GlFunctions::glVertexAttribIFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribLFormat", &OpenGl_GlFunctions::glVertexAttribLFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribBinding", &OpenGl_GlFunctions::glVertexAttribBinding, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexBindingDivisor", &OpenGl_GlFunctions::glVertexBindingDivisor, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDebugMessageControl", &OpenGl_GlFunctions::glDebugMessageControl, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDebugMessageInsert", &OpenGl_GlFunctions::glDebugMessageInsert, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDebugMessageCallback", &OpenGl_GlFunctions::glDebugMessageCallback, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetDebugMessageLog", &OpenGl_GlFunctions::glGetDebugMessageLog, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPushDebugGroup", &OpenGl_GlFunctions::glPushDebugGroup, "None");
cls_OpenGl_GlFunctions.def_readwrite("glPopDebugGroup", &OpenGl_GlFunctions::glPopDebugGroup, "None");
cls_OpenGl_GlFunctions.def_readwrite("glObjectLabel", &OpenGl_GlFunctions::glObjectLabel, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetObjectLabel", &OpenGl_GlFunctions::glGetObjectLabel, "None");
cls_OpenGl_GlFunctions.def_readwrite("glObjectPtrLabel", &OpenGl_GlFunctions::glObjectPtrLabel, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetObjectPtrLabel", &OpenGl_GlFunctions::glGetObjectPtrLabel, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBufferStorage", &OpenGl_GlFunctions::glBufferStorage, "");
cls_OpenGl_GlFunctions.def_readwrite("glClearTexImage", &OpenGl_GlFunctions::glClearTexImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearTexSubImage", &OpenGl_GlFunctions::glClearTexSubImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindBuffersBase", &OpenGl_GlFunctions::glBindBuffersBase, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindBuffersRange", &OpenGl_GlFunctions::glBindBuffersRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindTextures", &OpenGl_GlFunctions::glBindTextures, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindSamplers", &OpenGl_GlFunctions::glBindSamplers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindImageTextures", &OpenGl_GlFunctions::glBindImageTextures, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindVertexBuffers", &OpenGl_GlFunctions::glBindVertexBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClipControl", &OpenGl_GlFunctions::glClipControl, "");
cls_OpenGl_GlFunctions.def_readwrite("glCreateTransformFeedbacks", &OpenGl_GlFunctions::glCreateTransformFeedbacks, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTransformFeedbackBufferBase", &OpenGl_GlFunctions::glTransformFeedbackBufferBase, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTransformFeedbackBufferRange", &OpenGl_GlFunctions::glTransformFeedbackBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTransformFeedbackiv", &OpenGl_GlFunctions::glGetTransformFeedbackiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTransformFeedbacki_v", &OpenGl_GlFunctions::glGetTransformFeedbacki_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTransformFeedbacki64_v", &OpenGl_GlFunctions::glGetTransformFeedbacki64_v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateBuffers", &OpenGl_GlFunctions::glCreateBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedBufferStorage", &OpenGl_GlFunctions::glNamedBufferStorage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedBufferData", &OpenGl_GlFunctions::glNamedBufferData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedBufferSubData", &OpenGl_GlFunctions::glNamedBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyNamedBufferSubData", &OpenGl_GlFunctions::glCopyNamedBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedBufferData", &OpenGl_GlFunctions::glClearNamedBufferData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedBufferSubData", &OpenGl_GlFunctions::glClearNamedBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMapNamedBuffer", &OpenGl_GlFunctions::glMapNamedBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMapNamedBufferRange", &OpenGl_GlFunctions::glMapNamedBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUnmapNamedBuffer", &OpenGl_GlFunctions::glUnmapNamedBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glFlushMappedNamedBufferRange", &OpenGl_GlFunctions::glFlushMappedNamedBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedBufferParameteriv", &OpenGl_GlFunctions::glGetNamedBufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedBufferParameteri64v", &OpenGl_GlFunctions::glGetNamedBufferParameteri64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedBufferPointerv", &OpenGl_GlFunctions::glGetNamedBufferPointerv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedBufferSubData", &OpenGl_GlFunctions::glGetNamedBufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateFramebuffers", &OpenGl_GlFunctions::glCreateFramebuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferRenderbuffer", &OpenGl_GlFunctions::glNamedFramebufferRenderbuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferParameteri", &OpenGl_GlFunctions::glNamedFramebufferParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferTexture", &OpenGl_GlFunctions::glNamedFramebufferTexture, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferTextureLayer", &OpenGl_GlFunctions::glNamedFramebufferTextureLayer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferDrawBuffer", &OpenGl_GlFunctions::glNamedFramebufferDrawBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferDrawBuffers", &OpenGl_GlFunctions::glNamedFramebufferDrawBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedFramebufferReadBuffer", &OpenGl_GlFunctions::glNamedFramebufferReadBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateNamedFramebufferData", &OpenGl_GlFunctions::glInvalidateNamedFramebufferData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glInvalidateNamedFramebufferSubData", &OpenGl_GlFunctions::glInvalidateNamedFramebufferSubData, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedFramebufferiv", &OpenGl_GlFunctions::glClearNamedFramebufferiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedFramebufferuiv", &OpenGl_GlFunctions::glClearNamedFramebufferuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedFramebufferfv", &OpenGl_GlFunctions::glClearNamedFramebufferfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glClearNamedFramebufferfi", &OpenGl_GlFunctions::glClearNamedFramebufferfi, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBlitNamedFramebuffer", &OpenGl_GlFunctions::glBlitNamedFramebuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCheckNamedFramebufferStatus", &OpenGl_GlFunctions::glCheckNamedFramebufferStatus, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedFramebufferParameteriv", &OpenGl_GlFunctions::glGetNamedFramebufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedFramebufferAttachmentParameteriv", &OpenGl_GlFunctions::glGetNamedFramebufferAttachmentParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateRenderbuffers", &OpenGl_GlFunctions::glCreateRenderbuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedRenderbufferStorage", &OpenGl_GlFunctions::glNamedRenderbufferStorage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glNamedRenderbufferStorageMultisample", &OpenGl_GlFunctions::glNamedRenderbufferStorageMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetNamedRenderbufferParameteriv", &OpenGl_GlFunctions::glGetNamedRenderbufferParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateTextures", &OpenGl_GlFunctions::glCreateTextures, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureBuffer", &OpenGl_GlFunctions::glTextureBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureBufferRange", &OpenGl_GlFunctions::glTextureBufferRange, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureStorage1D", &OpenGl_GlFunctions::glTextureStorage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureStorage2D", &OpenGl_GlFunctions::glTextureStorage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureStorage3D", &OpenGl_GlFunctions::glTextureStorage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureStorage2DMultisample", &OpenGl_GlFunctions::glTextureStorage2DMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureStorage3DMultisample", &OpenGl_GlFunctions::glTextureStorage3DMultisample, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureSubImage1D", &OpenGl_GlFunctions::glTextureSubImage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureSubImage2D", &OpenGl_GlFunctions::glTextureSubImage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureSubImage3D", &OpenGl_GlFunctions::glTextureSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTextureSubImage1D", &OpenGl_GlFunctions::glCompressedTextureSubImage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTextureSubImage2D", &OpenGl_GlFunctions::glCompressedTextureSubImage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCompressedTextureSubImage3D", &OpenGl_GlFunctions::glCompressedTextureSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyTextureSubImage1D", &OpenGl_GlFunctions::glCopyTextureSubImage1D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyTextureSubImage2D", &OpenGl_GlFunctions::glCopyTextureSubImage2D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCopyTextureSubImage3D", &OpenGl_GlFunctions::glCopyTextureSubImage3D, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameterf", &OpenGl_GlFunctions::glTextureParameterf, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameterfv", &OpenGl_GlFunctions::glTextureParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameteri", &OpenGl_GlFunctions::glTextureParameteri, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameterIiv", &OpenGl_GlFunctions::glTextureParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameterIuiv", &OpenGl_GlFunctions::glTextureParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureParameteriv", &OpenGl_GlFunctions::glTextureParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGenerateTextureMipmap", &OpenGl_GlFunctions::glGenerateTextureMipmap, "None");
cls_OpenGl_GlFunctions.def_readwrite("glBindTextureUnit", &OpenGl_GlFunctions::glBindTextureUnit, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureImage", &OpenGl_GlFunctions::glGetTextureImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetCompressedTextureImage", &OpenGl_GlFunctions::glGetCompressedTextureImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureLevelParameterfv", &OpenGl_GlFunctions::glGetTextureLevelParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureLevelParameteriv", &OpenGl_GlFunctions::glGetTextureLevelParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureParameterfv", &OpenGl_GlFunctions::glGetTextureParameterfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureParameterIiv", &OpenGl_GlFunctions::glGetTextureParameterIiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureParameterIuiv", &OpenGl_GlFunctions::glGetTextureParameterIuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureParameteriv", &OpenGl_GlFunctions::glGetTextureParameteriv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateVertexArrays", &OpenGl_GlFunctions::glCreateVertexArrays, "None");
cls_OpenGl_GlFunctions.def_readwrite("glDisableVertexArrayAttrib", &OpenGl_GlFunctions::glDisableVertexArrayAttrib, "None");
cls_OpenGl_GlFunctions.def_readwrite("glEnableVertexArrayAttrib", &OpenGl_GlFunctions::glEnableVertexArrayAttrib, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayElementBuffer", &OpenGl_GlFunctions::glVertexArrayElementBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayVertexBuffer", &OpenGl_GlFunctions::glVertexArrayVertexBuffer, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayVertexBuffers", &OpenGl_GlFunctions::glVertexArrayVertexBuffers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayAttribBinding", &OpenGl_GlFunctions::glVertexArrayAttribBinding, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayAttribFormat", &OpenGl_GlFunctions::glVertexArrayAttribFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayAttribIFormat", &OpenGl_GlFunctions::glVertexArrayAttribIFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayAttribLFormat", &OpenGl_GlFunctions::glVertexArrayAttribLFormat, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexArrayBindingDivisor", &OpenGl_GlFunctions::glVertexArrayBindingDivisor, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexArrayiv", &OpenGl_GlFunctions::glGetVertexArrayiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexArrayIndexediv", &OpenGl_GlFunctions::glGetVertexArrayIndexediv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexArrayIndexed64iv", &OpenGl_GlFunctions::glGetVertexArrayIndexed64iv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateSamplers", &OpenGl_GlFunctions::glCreateSamplers, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateProgramPipelines", &OpenGl_GlFunctions::glCreateProgramPipelines, "None");
cls_OpenGl_GlFunctions.def_readwrite("glCreateQueries", &OpenGl_GlFunctions::glCreateQueries, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryBufferObjecti64v", &OpenGl_GlFunctions::glGetQueryBufferObjecti64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryBufferObjectiv", &OpenGl_GlFunctions::glGetQueryBufferObjectiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryBufferObjectui64v", &OpenGl_GlFunctions::glGetQueryBufferObjectui64v, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetQueryBufferObjectuiv", &OpenGl_GlFunctions::glGetQueryBufferObjectuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMemoryBarrierByRegion", &OpenGl_GlFunctions::glMemoryBarrierByRegion, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureSubImage", &OpenGl_GlFunctions::glGetTextureSubImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetCompressedTextureSubImage", &OpenGl_GlFunctions::glGetCompressedTextureSubImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetGraphicsResetStatus", &OpenGl_GlFunctions::glGetGraphicsResetStatus, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnCompressedTexImage", &OpenGl_GlFunctions::glGetnCompressedTexImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnTexImage", &OpenGl_GlFunctions::glGetnTexImage, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnUniformdv", &OpenGl_GlFunctions::glGetnUniformdv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnUniformfv", &OpenGl_GlFunctions::glGetnUniformfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnUniformiv", &OpenGl_GlFunctions::glGetnUniformiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnUniformuiv", &OpenGl_GlFunctions::glGetnUniformuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glReadnPixels", &OpenGl_GlFunctions::glReadnPixels, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnMapdv", &OpenGl_GlFunctions::glGetnMapdv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnMapfv", &OpenGl_GlFunctions::glGetnMapfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnMapiv", &OpenGl_GlFunctions::glGetnMapiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnPixelMapfv", &OpenGl_GlFunctions::glGetnPixelMapfv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnPixelMapuiv", &OpenGl_GlFunctions::glGetnPixelMapuiv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnPixelMapusv", &OpenGl_GlFunctions::glGetnPixelMapusv, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnPolygonStipple", &OpenGl_GlFunctions::glGetnPolygonStipple, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnColorTable", &OpenGl_GlFunctions::glGetnColorTable, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnConvolutionFilter", &OpenGl_GlFunctions::glGetnConvolutionFilter, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnSeparableFilter", &OpenGl_GlFunctions::glGetnSeparableFilter, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnHistogram", &OpenGl_GlFunctions::glGetnHistogram, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetnMinmax", &OpenGl_GlFunctions::glGetnMinmax, "None");
cls_OpenGl_GlFunctions.def_readwrite("glTextureBarrier", &OpenGl_GlFunctions::glTextureBarrier, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramParameteriEXT", &OpenGl_GlFunctions::glProgramParameteriEXT, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureHandleARB", &OpenGl_GlFunctions::glGetTextureHandleARB, "");
cls_OpenGl_GlFunctions.def_readwrite("glGetTextureSamplerHandleARB", &OpenGl_GlFunctions::glGetTextureSamplerHandleARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMakeTextureHandleResidentARB", &OpenGl_GlFunctions::glMakeTextureHandleResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMakeTextureHandleNonResidentARB", &OpenGl_GlFunctions::glMakeTextureHandleNonResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetImageHandleARB", &OpenGl_GlFunctions::glGetImageHandleARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMakeImageHandleResidentARB", &OpenGl_GlFunctions::glMakeImageHandleResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glMakeImageHandleNonResidentARB", &OpenGl_GlFunctions::glMakeImageHandleNonResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformHandleui64ARB", &OpenGl_GlFunctions::glUniformHandleui64ARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glUniformHandleui64vARB", &OpenGl_GlFunctions::glUniformHandleui64vARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformHandleui64ARB", &OpenGl_GlFunctions::glProgramUniformHandleui64ARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glProgramUniformHandleui64vARB", &OpenGl_GlFunctions::glProgramUniformHandleui64vARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsTextureHandleResidentARB", &OpenGl_GlFunctions::glIsTextureHandleResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glIsImageHandleResidentARB", &OpenGl_GlFunctions::glIsImageHandleResidentARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL1ui64ARB", &OpenGl_GlFunctions::glVertexAttribL1ui64ARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glVertexAttribL1ui64vARB", &OpenGl_GlFunctions::glVertexAttribL1ui64vARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("glGetVertexAttribLui64vARB", &OpenGl_GlFunctions::glGetVertexAttribLui64vARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglGetExtensionsStringARB", &OpenGl_GlFunctions::wglGetExtensionsStringARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglSwapIntervalEXT", &OpenGl_GlFunctions::wglSwapIntervalEXT, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglChoosePixelFormatARB", &OpenGl_GlFunctions::wglChoosePixelFormatARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglCreateContextAttribsARB", &OpenGl_GlFunctions::wglCreateContextAttribsARB, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXSetResourceShareHandleNV", &OpenGl_GlFunctions::wglDXSetResourceShareHandleNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXOpenDeviceNV", &OpenGl_GlFunctions::wglDXOpenDeviceNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXCloseDeviceNV", &OpenGl_GlFunctions::wglDXCloseDeviceNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXRegisterObjectNV", &OpenGl_GlFunctions::wglDXRegisterObjectNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXUnregisterObjectNV", &OpenGl_GlFunctions::wglDXUnregisterObjectNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXObjectAccessNV", &OpenGl_GlFunctions::wglDXObjectAccessNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXLockObjectsNV", &OpenGl_GlFunctions::wglDXLockObjectsNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglDXUnlockObjectsNV", &OpenGl_GlFunctions::wglDXUnlockObjectsNV, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglGetGPUIDsAMD", &OpenGl_GlFunctions::wglGetGPUIDsAMD, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglGetGPUInfoAMD", &OpenGl_GlFunctions::wglGetGPUInfoAMD, "None");
cls_OpenGl_GlFunctions.def_readwrite("wglGetContextGPUIDAMD", &OpenGl_GlFunctions::wglGetContextGPUIDAMD, "None");

// CLASS: OPENGL_ARBDBG
py::class_<OpenGl_ArbDbg> cls_OpenGl_ArbDbg(mod, "OpenGl_ArbDbg", "Debug context routines");

// Constructors
cls_OpenGl_ArbDbg.def(py::init<>());

// CLASS: OPENGL_ARBFBO
py::class_<OpenGl_ArbFBO> cls_OpenGl_ArbFBO(mod, "OpenGl_ArbFBO", "FBO is available on OpenGL 2.0+ hardware");

// Constructors
cls_OpenGl_ArbFBO.def(py::init<>());

// CLASS: OPENGL_ARBFBOBLIT
py::class_<OpenGl_ArbFBOBlit> cls_OpenGl_ArbFBOBlit(mod, "OpenGl_ArbFBOBlit", "FBO blit is available in OpenGL 3.0+. Moved out from OpenGl_ArbFBO since it is unavailable in OpenGL ES 2.0.");

// Constructors
cls_OpenGl_ArbFBOBlit.def(py::init<>());

// CLASS: OPENGL_ARBINS
py::class_<OpenGl_ArbIns> cls_OpenGl_ArbIns(mod, "OpenGl_ArbIns", "Instancing is available on OpenGL 3.0+ hardware");

// Constructors
cls_OpenGl_ArbIns.def(py::init<>());

// CLASS: OPENGL_ARBSAMPLEROBJECT
py::class_<OpenGl_ArbSamplerObject> cls_OpenGl_ArbSamplerObject(mod, "OpenGl_ArbSamplerObject", "Provide Sampler Object functionality (texture parameters stored independently from texture itself). Available since OpenGL 3.3+ (GL_ARB_sampler_objects extension) and OpenGL ES 3.0+.");

// Constructors
cls_OpenGl_ArbSamplerObject.def(py::init<>());

// CLASS: OPENGL_ARBTBO
py::class_<OpenGl_ArbTBO> cls_OpenGl_ArbTBO(mod, "OpenGl_ArbTBO", "TBO is available on OpenGL 3.0+ and OpenGL ES 3.2+ hardware");

// Constructors
cls_OpenGl_ArbTBO.def(py::init<>());

// CLASS: OPENGL_ARBTEXBINDLESS
py::class_<OpenGl_ArbTexBindless> cls_OpenGl_ArbTexBindless(mod, "OpenGl_ArbTexBindless", "Provides bindless textures. This extension allows OpenGL applications to access texture objects in shaders without first binding each texture to one of a limited number of texture image units.");

// Constructors
cls_OpenGl_ArbTexBindless.def(py::init<>());

// CLASS: OPENGL_ELEMENT
py::class_<OpenGl_Element, std::unique_ptr<OpenGl_Element, py::nodelete>> cls_OpenGl_Element(mod, "OpenGl_Element", "Base interface for drawable elements.");

// Methods
cls_OpenGl_Element.def("Render", (void (OpenGl_Element::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Element::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Element.def("Release", (void (OpenGl_Element::*)(OpenGl_Context *)) &OpenGl_Element::Release, "Release GPU resources. Pointer to the context is used because this method might be called when the context is already being destroyed and usage of a handle would be unsafe", py::arg("theContext"));
cls_OpenGl_Element.def("IsFillDrawMode", (Standard_Boolean (OpenGl_Element::*)() const) &OpenGl_Element::IsFillDrawMode, "Return TRUE if primitive type generates shaded triangulation (to be used in filters).");
cls_OpenGl_Element.def("SynchronizeAspects", (void (OpenGl_Element::*)()) &OpenGl_Element::SynchronizeAspects, "Update parameters of the drawable elements.");
// cls_OpenGl_Element.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Element::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Element.def_static("operator delete_", (void (*)(void *)) &OpenGl_Element::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Element::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Element.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Element::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Element::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Element.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Element::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_ASPECTSPROGRAM
py::class_<OpenGl_AspectsProgram> cls_OpenGl_AspectsProgram(mod, "OpenGl_AspectsProgram", "OpenGl resources for custom shading program.");

// Constructors
cls_OpenGl_AspectsProgram.def(py::init<>());

// Methods
// cls_OpenGl_AspectsProgram.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectsProgram::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectsProgram.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectsProgram::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectsProgram.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectsProgram::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectsProgram.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectsProgram::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectsProgram.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectsProgram::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectsProgram.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectsProgram::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_AspectsProgram.def("ShaderProgram", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_AspectsProgram::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_ShaderProgram> &)) &OpenGl_AspectsProgram::ShaderProgram, "Return shading program.", py::arg("theCtx"), py::arg("theShader"));
cls_OpenGl_AspectsProgram.def("UpdateRediness", (void (OpenGl_AspectsProgram::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_AspectsProgram::UpdateRediness, "Update shader resource up-to-date state.", py::arg("theAspect"));
cls_OpenGl_AspectsProgram.def("Release", (void (OpenGl_AspectsProgram::*)(OpenGl_Context *)) &OpenGl_AspectsProgram::Release, "Release resource.", py::arg("theCtx"));

// CLASS: OPENGL_ASPECTSTEXTURESET
py::class_<OpenGl_AspectsTextureSet> cls_OpenGl_AspectsTextureSet(mod, "OpenGl_AspectsTextureSet", "OpenGl resources for custom textures.");

// Constructors
cls_OpenGl_AspectsTextureSet.def(py::init<>());

// Methods
// cls_OpenGl_AspectsTextureSet.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectsTextureSet::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectsTextureSet.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectsTextureSet::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectsTextureSet.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectsTextureSet::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectsTextureSet.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectsTextureSet::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectsTextureSet.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectsTextureSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectsTextureSet.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectsTextureSet::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_AspectsTextureSet.def("IsReady", (bool (OpenGl_AspectsTextureSet::*)() const) &OpenGl_AspectsTextureSet::IsReady, "Return TRUE if resource is up-to-date.");
cls_OpenGl_AspectsTextureSet.def("Invalidate", (void (OpenGl_AspectsTextureSet::*)()) &OpenGl_AspectsTextureSet::Invalidate, "Invalidate resource state.");
cls_OpenGl_AspectsTextureSet.def("TextureSet", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_AspectsTextureSet::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_Aspects> &, const opencascade::handle<OpenGl_PointSprite> &, const opencascade::handle<OpenGl_PointSprite> &, bool)) &OpenGl_AspectsTextureSet::TextureSet, "Return textures array.", py::arg("theCtx"), py::arg("theAspect"), py::arg("theSprite"), py::arg("theSpriteA"), py::arg("theToHighlight"));
cls_OpenGl_AspectsTextureSet.def("UpdateRediness", (void (OpenGl_AspectsTextureSet::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_AspectsTextureSet::UpdateRediness, "Update texture resource up-to-date state.", py::arg("theAspect"));
cls_OpenGl_AspectsTextureSet.def("Release", (void (OpenGl_AspectsTextureSet::*)(OpenGl_Context *)) &OpenGl_AspectsTextureSet::Release, "Release texture resource.", py::arg("theCtx"));

// CLASS: OPENGL_ASPECTSSPRITE
py::class_<OpenGl_AspectsSprite> cls_OpenGl_AspectsSprite(mod, "OpenGl_AspectsSprite", "OpenGl resources for custom point sprites.");

// Constructors
cls_OpenGl_AspectsSprite.def(py::init<>());

// Methods
// cls_OpenGl_AspectsSprite.def_static("operator new_", (void * (*)(size_t)) &OpenGl_AspectsSprite::operator new, "None", py::arg("theSize"));
// cls_OpenGl_AspectsSprite.def_static("operator delete_", (void (*)(void *)) &OpenGl_AspectsSprite::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_AspectsSprite.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_AspectsSprite::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_AspectsSprite.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_AspectsSprite::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_AspectsSprite.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_AspectsSprite::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_AspectsSprite.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_AspectsSprite::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_AspectsSprite.def("MarkerSize", (Standard_ShortReal (OpenGl_AspectsSprite::*)() const) &OpenGl_AspectsSprite::MarkerSize, "None");
cls_OpenGl_AspectsSprite.def("IsReady", (bool (OpenGl_AspectsSprite::*)() const) &OpenGl_AspectsSprite::IsReady, "Return TRUE if resource is up-to-date.");
cls_OpenGl_AspectsSprite.def("Invalidate", (void (OpenGl_AspectsSprite::*)()) &OpenGl_AspectsSprite::Invalidate, "Invalidate resource state.");
cls_OpenGl_AspectsSprite.def("HasPointSprite", (bool (OpenGl_AspectsSprite::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_AspectsSprite::HasPointSprite, "Return TRUE if OpenGl point sprite resource defines texture.", py::arg("theCtx"), py::arg("theAspects"));
cls_OpenGl_AspectsSprite.def("IsDisplayListSprite", (bool (OpenGl_AspectsSprite::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_AspectsSprite::IsDisplayListSprite, "Return TRUE if OpenGl point sprite resource defined by obsolete Display List (bitmap).", py::arg("theCtx"), py::arg("theAspects"));
cls_OpenGl_AspectsSprite.def("Sprite", (const opencascade::handle<OpenGl_PointSprite> & (OpenGl_AspectsSprite::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_Aspects> &, bool)) &OpenGl_AspectsSprite::Sprite, "Return sprite.", py::arg("theCtx"), py::arg("theAspects"), py::arg("theIsAlphaSprite"));
cls_OpenGl_AspectsSprite.def("UpdateRediness", (void (OpenGl_AspectsSprite::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_AspectsSprite::UpdateRediness, "Update texture resource up-to-date state.", py::arg("theAspect"));
cls_OpenGl_AspectsSprite.def("Release", (void (OpenGl_AspectsSprite::*)(OpenGl_Context *)) &OpenGl_AspectsSprite::Release, "Release texture resource.", py::arg("theCtx"));

// CLASS: OPENGL_ASPECTS
py::class_<OpenGl_Aspects, OpenGl_Element> cls_OpenGl_Aspects(mod, "OpenGl_Aspects", "The element holding Graphic3d_Aspects.");

// Constructors
cls_OpenGl_Aspects.def(py::init<>());
cls_OpenGl_Aspects.def(py::init<const opencascade::handle<Graphic3d_Aspects> &>(), py::arg("theAspect"));

// Methods
cls_OpenGl_Aspects.def("Aspect", (const opencascade::handle<Graphic3d_Aspects> & (OpenGl_Aspects::*)() const) &OpenGl_Aspects::Aspect, "Return aspect.");
cls_OpenGl_Aspects.def("SetAspect", (void (OpenGl_Aspects::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_Aspects::SetAspect, "Assign parameters.", py::arg("theAspect"));
cls_OpenGl_Aspects.def("ShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_Aspects::*)() const) &OpenGl_Aspects::ShadingModel, "Returns Shading Model.");
cls_OpenGl_Aspects.def("SetNoLighting", (void (OpenGl_Aspects::*)()) &OpenGl_Aspects::SetNoLighting, "Set if lighting should be disabled or not.");
cls_OpenGl_Aspects.def("TextureSet", [](OpenGl_Aspects &self, const opencascade::handle<OpenGl_Context> & a0) -> const opencascade::handle<OpenGl_TextureSet> & { return self.TextureSet(a0); });
cls_OpenGl_Aspects.def("TextureSet", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Context> &, bool) const) &OpenGl_Aspects::TextureSet, "Returns textures map.", py::arg("theCtx"), py::arg("theToHighlight"));
cls_OpenGl_Aspects.def("ShaderProgramRes", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Aspects::ShaderProgramRes, "Init and return OpenGl shader program resource.", py::arg("theCtx"));
cls_OpenGl_Aspects.def("MarkerSize", (Standard_ShortReal (OpenGl_Aspects::*)() const) &OpenGl_Aspects::MarkerSize, "Returns marker size");
cls_OpenGl_Aspects.def("HasPointSprite", (bool (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Aspects::HasPointSprite, "Return TRUE if OpenGl point sprite resource defines texture.", py::arg("theCtx"));
cls_OpenGl_Aspects.def("IsDisplayListSprite", (bool (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Aspects::IsDisplayListSprite, "Return TRUE if OpenGl point sprite resource defined by obsolete Display List (bitmap).", py::arg("theCtx"));
cls_OpenGl_Aspects.def("SpriteRes", (const opencascade::handle<OpenGl_PointSprite> & (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Context> &, bool) const) &OpenGl_Aspects::SpriteRes, "Init and return OpenGl point sprite resource.", py::arg("theCtx"), py::arg("theIsAlphaSprite"));
cls_OpenGl_Aspects.def("Render", (void (OpenGl_Aspects::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Aspects::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Aspects.def("Release", (void (OpenGl_Aspects::*)(OpenGl_Context *)) &OpenGl_Aspects::Release, "None", py::arg("theContext"));
cls_OpenGl_Aspects.def("SynchronizeAspects", (void (OpenGl_Aspects::*)()) &OpenGl_Aspects::SynchronizeAspects, "Update presentation aspects parameters after their modification.");
cls_OpenGl_Aspects.def("DumpJson", [](OpenGl_Aspects &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_OpenGl_Aspects.def("DumpJson", (void (OpenGl_Aspects::*)(Standard_OStream &, const Standard_Integer) const) &OpenGl_Aspects::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
// cls_OpenGl_Aspects.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Aspects::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Aspects.def_static("operator delete_", (void (*)(void *)) &OpenGl_Aspects::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Aspects.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Aspects::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Aspects.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Aspects::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Aspects.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Aspects::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Aspects.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Aspects::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_GLCORE11FWD
py::class_<OpenGl_GlCore11Fwd> cls_OpenGl_GlCore11Fwd(mod, "OpenGl_GlCore11Fwd", "OpenGL 1.1 core without deprecated Fixed Pipeline entry points. Notice that all functions within this structure are actually exported by system GL library. The main purpose for these hint - to control visibility of functions per GL version (global functions should not be used directly to achieve this effect!).");

// Constructors
cls_OpenGl_GlCore11Fwd.def(py::init<>());

// Methods
cls_OpenGl_GlCore11Fwd.def("glClearColor", (void (OpenGl_GlCore11Fwd::*)(GLclampf, GLclampf, GLclampf, GLclampf)) &OpenGl_GlCore11Fwd::glClearColor, "", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11Fwd.def("glClear", (void (OpenGl_GlCore11Fwd::*)(GLbitfield)) &OpenGl_GlCore11Fwd::glClear, "None", py::arg("theMask"));
cls_OpenGl_GlCore11Fwd.def("glColorMask", (void (OpenGl_GlCore11Fwd::*)(GLboolean, GLboolean, GLboolean, GLboolean)) &OpenGl_GlCore11Fwd::glColorMask, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11Fwd.def("glBlendFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum)) &OpenGl_GlCore11Fwd::glBlendFunc, "None", py::arg("sfactor"), py::arg("dfactor"));
cls_OpenGl_GlCore11Fwd.def("glCullFace", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glCullFace, "None", py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glFrontFace", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glFrontFace, "None", py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glLineWidth", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glLineWidth, "None", py::arg("theWidth"));
cls_OpenGl_GlCore11Fwd.def("glPolygonOffset", (void (OpenGl_GlCore11Fwd::*)(GLfloat, GLfloat)) &OpenGl_GlCore11Fwd::glPolygonOffset, "None", py::arg("theFactor"), py::arg("theUnits"));
cls_OpenGl_GlCore11Fwd.def("glScissor", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glScissor, "None", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_GlCore11Fwd.def("glEnable", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glEnable, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glDisable", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glDisable, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glIsEnabled", (GLboolean (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glIsEnabled, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glGetBooleanv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLboolean *)) &OpenGl_GlCore11Fwd::glGetBooleanv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetFloatv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLfloat *)) &OpenGl_GlCore11Fwd::glGetFloatv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetIntegerv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint *)) &OpenGl_GlCore11Fwd::glGetIntegerv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetError", (GLenum (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glGetError, "None");
cls_OpenGl_GlCore11Fwd.def("glGetString", (const GLubyte * (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glGetString, "None", py::arg("theName"));
cls_OpenGl_GlCore11Fwd.def("glFinish", (void (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glFinish, "None");
cls_OpenGl_GlCore11Fwd.def("glFlush", (void (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glFlush, "None");
cls_OpenGl_GlCore11Fwd.def("glHint", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum)) &OpenGl_GlCore11Fwd::glHint, "None", py::arg("theTarget"), py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glClearDepth", (void (OpenGl_GlCore11Fwd::*)(GLclampd)) &OpenGl_GlCore11Fwd::glClearDepth, "", py::arg("theDepth"));
cls_OpenGl_GlCore11Fwd.def("glClearDepthf", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glClearDepthf, "None", py::arg("theDepth"));
cls_OpenGl_GlCore11Fwd.def("glDepthFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glDepthFunc, "None", py::arg("theFunc"));
cls_OpenGl_GlCore11Fwd.def("glDepthMask", (void (OpenGl_GlCore11Fwd::*)(GLboolean)) &OpenGl_GlCore11Fwd::glDepthMask, "None", py::arg("theFlag"));
cls_OpenGl_GlCore11Fwd.def("glDepthRange", (void (OpenGl_GlCore11Fwd::*)(GLclampd, GLclampd)) &OpenGl_GlCore11Fwd::glDepthRange, "None", py::arg("theNearValue"), py::arg("theFarValue"));
cls_OpenGl_GlCore11Fwd.def("glDepthRangef", (void (OpenGl_GlCore11Fwd::*)(GLfloat, GLfloat)) &OpenGl_GlCore11Fwd::glDepthRangef, "None", py::arg("theNearValue"), py::arg("theFarValue"));
cls_OpenGl_GlCore11Fwd.def("glViewport", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glViewport, "", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_GlCore11Fwd.def("glDrawArrays", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLsizei)) &OpenGl_GlCore11Fwd::glDrawArrays, "", py::arg("theMode"), py::arg("theFirst"), py::arg("theCount"));
cls_OpenGl_GlCore11Fwd.def("glDrawElements", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLsizei, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glDrawElements, "None", py::arg("theMode"), py::arg("theCount"), py::arg("theType"), py::arg("theIndices"));
cls_OpenGl_GlCore11Fwd.def("glPixelStorei", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint)) &OpenGl_GlCore11Fwd::glPixelStorei, "", py::arg("theParamName"), py::arg("theParam"));
cls_OpenGl_GlCore11Fwd.def("glReadPixels", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *)) &OpenGl_GlCore11Fwd::glReadPixels, "None", py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glStencilFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLuint)) &OpenGl_GlCore11Fwd::glStencilFunc, "", py::arg("func"), py::arg("ref"), py::arg("mask"));
cls_OpenGl_GlCore11Fwd.def("glStencilMask", (void (OpenGl_GlCore11Fwd::*)(GLuint)) &OpenGl_GlCore11Fwd::glStencilMask, "None", py::arg("mask"));
cls_OpenGl_GlCore11Fwd.def("glStencilOp", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLenum)) &OpenGl_GlCore11Fwd::glStencilOp, "None", py::arg("fail"), py::arg("zfail"), py::arg("zpass"));
cls_OpenGl_GlCore11Fwd.def("glClearStencil", (void (OpenGl_GlCore11Fwd::*)(GLint)) &OpenGl_GlCore11Fwd::glClearStencil, "None", py::arg("s"));
cls_OpenGl_GlCore11Fwd.def("glTexParameterf", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11Fwd::glTexParameterf, "", py::arg("target"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11Fwd.def("glTexParameteri", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11Fwd::glTexParameteri, "None", py::arg("target"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11Fwd.def("glTexParameterfv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11Fwd::glTexParameterfv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glTexParameteriv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11Fwd::glTexParameteriv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glGetTexParameterfv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11Fwd::glGetTexParameterfv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glGetTexParameteriv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11Fwd::glGetTexParameteriv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glTexImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexImage2D, "None", py::arg("target"), py::arg("level"), py::arg("internalFormat"), py::arg("width"), py::arg("height"), py::arg("border"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glGenTextures", (void (OpenGl_GlCore11Fwd::*)(GLsizei, GLuint *)) &OpenGl_GlCore11Fwd::glGenTextures, "None", py::arg("n"), py::arg("textures"));
cls_OpenGl_GlCore11Fwd.def("glDeleteTextures", (void (OpenGl_GlCore11Fwd::*)(GLsizei, const GLuint *)) &OpenGl_GlCore11Fwd::glDeleteTextures, "None", py::arg("n"), py::arg("textures"));
cls_OpenGl_GlCore11Fwd.def("glBindTexture", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLuint)) &OpenGl_GlCore11Fwd::glBindTexture, "None", py::arg("target"), py::arg("texture"));
cls_OpenGl_GlCore11Fwd.def("glIsTexture", (GLboolean (OpenGl_GlCore11Fwd::*)(GLuint)) &OpenGl_GlCore11Fwd::glIsTexture, "None", py::arg("texture"));
cls_OpenGl_GlCore11Fwd.def("glTexSubImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexSubImage2D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("yoffset"), py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)) &OpenGl_GlCore11Fwd::glCopyTexImage2D, "None", py::arg("target"), py::arg("level"), py::arg("internalformat"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("border"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexSubImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glCopyTexSubImage2D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("yoffset"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"));
cls_OpenGl_GlCore11Fwd.def("glTexImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexImage1D, "None", py::arg("target"), py::arg("level"), py::arg("internalFormat"), py::arg("width"), py::arg("border"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glTexSubImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexSubImage1D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("width"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)) &OpenGl_GlCore11Fwd::glCopyTexImage1D, "None", py::arg("target"), py::arg("level"), py::arg("internalformat"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("border"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexSubImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLint, GLsizei)) &OpenGl_GlCore11Fwd::glCopyTexSubImage1D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("x"), py::arg("y"), py::arg("width"));
cls_OpenGl_GlCore11Fwd.def("glGetTexImage", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLenum, GLvoid *)) &OpenGl_GlCore11Fwd::glGetTexImage, "None", py::arg("target"), py::arg("level"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glAlphaFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLclampf)) &OpenGl_GlCore11Fwd::glAlphaFunc, "None", py::arg("theFunc"), py::arg("theRef"));
cls_OpenGl_GlCore11Fwd.def("glPointSize", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glPointSize, "None", py::arg("theSize"));

// CLASS: OPENGL_GLCORE11
py::class_<OpenGl_GlCore11> cls_OpenGl_GlCore11(mod, "OpenGl_GlCore11", "OpenGL 1.1 core. Notice that all functions within this structure are actually exported by system GL library. The main purpose for these hint - to control visibility of functions per GL version (global functions should not be used directly to achieve this effect!).");

// Constructors
cls_OpenGl_GlCore11.def(py::init<>());

// Methods
cls_OpenGl_GlCore11.def("glRotated", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRotated, "None", py::arg("theAngleDegrees"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glScaled", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glScaled, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glTranslated", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTranslated, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glBegin", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glBegin, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glEnd", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glEnd, "None");
cls_OpenGl_GlCore11.def("glVertex2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex2d, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex2f, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glVertex2i, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glVertex2s, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex3d, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex3f, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glVertex3i, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glVertex3s, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex4d, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex4f, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glVertex4i, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glVertex4s, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex2dv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex2fv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex2iv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex2sv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex3dv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex3fv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex3iv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex3sv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex4dv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex4fv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex4iv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex4sv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glNormal3b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glNormal3b, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glNormal3d, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glNormal3f, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glNormal3i, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glNormal3s, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glNormal3bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glNormal3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glNormal3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glNormal3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glNormal3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glIndexd", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glIndexd, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexf", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glIndexf, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexi", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glIndexi, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexs", (void (OpenGl_GlCore11::*)(GLshort)) &OpenGl_GlCore11::glIndexs, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexub", (void (OpenGl_GlCore11::*)(GLubyte)) &OpenGl_GlCore11::glIndexub, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexdv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glIndexdv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexfv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glIndexfv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexiv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glIndexiv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexsv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glIndexsv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glIndexubv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glColor3b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glColor3b, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glColor3d, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glColor3f, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glColor3i, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glColor3s, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3ub", (void (OpenGl_GlCore11::*)(GLubyte, GLubyte, GLubyte)) &OpenGl_GlCore11::glColor3ub, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3ui", (void (OpenGl_GlCore11::*)(GLuint, GLuint, GLuint)) &OpenGl_GlCore11::glColor3ui, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3us", (void (OpenGl_GlCore11::*)(GLushort, GLushort, GLushort)) &OpenGl_GlCore11::glColor3us, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor4b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glColor4b, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glColor4d, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glColor4f, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glColor4i, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glColor4s, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4ub", (void (OpenGl_GlCore11::*)(GLubyte, GLubyte, GLubyte, GLubyte)) &OpenGl_GlCore11::glColor4ub, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4ui", (void (OpenGl_GlCore11::*)(GLuint, GLuint, GLuint, GLuint)) &OpenGl_GlCore11::glColor4ui, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4us", (void (OpenGl_GlCore11::*)(GLushort, GLushort, GLushort, GLushort)) &OpenGl_GlCore11::glColor4us, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor3bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glColor3bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glColor3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glColor3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glColor3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glColor3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3ubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glColor3ubv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3uiv", (void (OpenGl_GlCore11::*)(const GLuint *)) &OpenGl_GlCore11::glColor3uiv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3usv", (void (OpenGl_GlCore11::*)(const GLushort *)) &OpenGl_GlCore11::glColor3usv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glColor4bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glColor4dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glColor4fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glColor4iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glColor4sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4ubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glColor4ubv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4uiv", (void (OpenGl_GlCore11::*)(const GLuint *)) &OpenGl_GlCore11::glColor4uiv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4usv", (void (OpenGl_GlCore11::*)(const GLushort *)) &OpenGl_GlCore11::glColor4usv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glTexCoord1d", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glTexCoord1d, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1f", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glTexCoord1f, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1i", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glTexCoord1i, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1s", (void (OpenGl_GlCore11::*)(GLshort)) &OpenGl_GlCore11::glTexCoord1s, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord2d, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord2f, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glTexCoord2i, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord2s, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord3d, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord3f, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glTexCoord3i, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord3s, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord4d, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord4f, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glTexCoord4i, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord4s, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord1dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord1dv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord1fv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord1iv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord1sv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord2dv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord2fv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord2iv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord2sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glTexCoord3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord3dv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord3fv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord3iv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord3sv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord4dv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord4fv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord4iv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord4sv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glMatrixMode", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glMatrixMode, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glOrtho", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glOrtho, "None", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNearVal"), py::arg("theFarVal"));
cls_OpenGl_GlCore11.def("glFrustum", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glFrustum, "None", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNearVal"), py::arg("theFarVal"));
cls_OpenGl_GlCore11.def("glPushMatrix", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPushMatrix, "None");
cls_OpenGl_GlCore11.def("glPopMatrix", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopMatrix, "None");
cls_OpenGl_GlCore11.def("glLoadIdentity", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glLoadIdentity, "None");
cls_OpenGl_GlCore11.def("glLoadMatrixd", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glLoadMatrixd, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glLoadMatrixf", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glLoadMatrixf, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glMultMatrixd", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glMultMatrixd, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glMultMatrixf", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glMultMatrixf, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glLineStipple", (void (OpenGl_GlCore11::*)(GLint, GLushort)) &OpenGl_GlCore11::glLineStipple, "None", py::arg("theFactor"), py::arg("thePattern"));
cls_OpenGl_GlCore11.def("glPolygonStipple", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glPolygonStipple, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glGetPolygonStipple", (void (OpenGl_GlCore11::*)(GLubyte *)) &OpenGl_GlCore11::glGetPolygonStipple, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPushAttrib", (void (OpenGl_GlCore11::*)(GLbitfield)) &OpenGl_GlCore11::glPushAttrib, "", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPopAttrib", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopAttrib, "None");
cls_OpenGl_GlCore11.def("glPushClientAttrib", (void (OpenGl_GlCore11::*)(GLbitfield)) &OpenGl_GlCore11::glPushClientAttrib, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPopClientAttrib", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopClientAttrib, "None");
cls_OpenGl_GlCore11.def("glShadeModel", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glShadeModel, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glLightf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glLightf, "None", py::arg("theLight"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLighti", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glLighti, "None", py::arg("theLight"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glLightfv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glLightiv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetLightfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetLightfv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetLightiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetLightiv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightModelf", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glLightModelf, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightModeli", (void (OpenGl_GlCore11::*)(GLenum, GLint)) &OpenGl_GlCore11::glLightModeli, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightModelfv", (void (OpenGl_GlCore11::*)(GLenum, const GLfloat *)) &OpenGl_GlCore11::glLightModelfv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightModeliv", (void (OpenGl_GlCore11::*)(GLenum, const GLint *)) &OpenGl_GlCore11::glLightModeliv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMaterialf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glMaterialf, "None", py::arg("face"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glMateriali", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glMateriali, "None", py::arg("face"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glMaterialfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glMaterialfv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMaterialiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glMaterialiv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetMaterialfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetMaterialfv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetMaterialiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetMaterialiv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glColorMaterial", (void (OpenGl_GlCore11::*)(GLenum, GLenum)) &OpenGl_GlCore11::glColorMaterial, "None", py::arg("face"), py::arg("mode"));
cls_OpenGl_GlCore11.def("glClipPlane", (void (OpenGl_GlCore11::*)(GLenum, const GLdouble *)) &OpenGl_GlCore11::glClipPlane, "", py::arg("thePlane"), py::arg("theEquation"));
cls_OpenGl_GlCore11.def("glGetClipPlane", (void (OpenGl_GlCore11::*)(GLenum, GLdouble *)) &OpenGl_GlCore11::glGetClipPlane, "None", py::arg("thePlane"), py::arg("theEquation"));
cls_OpenGl_GlCore11.def("glIsList", (GLboolean (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glIsList, "", py::arg("theList"));
cls_OpenGl_GlCore11.def("glDeleteLists", (void (OpenGl_GlCore11::*)(GLuint, GLsizei)) &OpenGl_GlCore11::glDeleteLists, "None", py::arg("theList"), py::arg("theRange"));
cls_OpenGl_GlCore11.def("glGenLists", (GLuint (OpenGl_GlCore11::*)(GLsizei)) &OpenGl_GlCore11::glGenLists, "None", py::arg("theRange"));
cls_OpenGl_GlCore11.def("glNewList", (void (OpenGl_GlCore11::*)(GLuint, GLenum)) &OpenGl_GlCore11::glNewList, "None", py::arg("theList"), py::arg("theMode"));
cls_OpenGl_GlCore11.def("glEndList", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glEndList, "None");
cls_OpenGl_GlCore11.def("glCallList", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glCallList, "None", py::arg("theList"));
cls_OpenGl_GlCore11.def("glCallLists", (void (OpenGl_GlCore11::*)(GLsizei, GLenum, const GLvoid *)) &OpenGl_GlCore11::glCallLists, "None", py::arg("theNb"), py::arg("theType"), py::arg("theLists"));
cls_OpenGl_GlCore11.def("glListBase", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glListBase, "None", py::arg("theBase"));
cls_OpenGl_GlCore11.def("glRasterPos2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos2d, "", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos2f, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glRasterPos2i, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos2s, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos3d, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos3f, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glRasterPos3i, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos3s, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos4d, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos4f, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glRasterPos4i, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos4s, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos2dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos2fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos2iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos2sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos4dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos4fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos4iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos4sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRectd", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRectd, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRectf", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRectf, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRecti", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glRecti, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRects", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRects, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRectdv", (void (OpenGl_GlCore11::*)(const GLdouble *, const GLdouble *)) &OpenGl_GlCore11::glRectdv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectfv", (void (OpenGl_GlCore11::*)(const GLfloat *, const GLfloat *)) &OpenGl_GlCore11::glRectfv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectiv", (void (OpenGl_GlCore11::*)(const GLint *, const GLint *)) &OpenGl_GlCore11::glRectiv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectsv", (void (OpenGl_GlCore11::*)(const GLshort *, const GLshort *)) &OpenGl_GlCore11::glRectsv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glTexGend", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble)) &OpenGl_GlCore11::glTexGend, "", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGenf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glTexGenf, "None", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGeni", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glTexGeni, "None", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGendv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLdouble *)) &OpenGl_GlCore11::glTexGendv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glTexGenfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glTexGenfv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glTexGeniv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glTexGeniv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGendv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble *)) &OpenGl_GlCore11::glGetTexGendv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGenfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetTexGenfv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGeniv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetTexGeniv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glPrioritizeTextures", (void (OpenGl_GlCore11::*)(GLsizei, const GLuint *, const GLclampf *)) &OpenGl_GlCore11::glPrioritizeTextures, "", py::arg("n"), py::arg("textures"), py::arg("priorities"));
cls_OpenGl_GlCore11.def("glAreTexturesResident", (GLboolean (OpenGl_GlCore11::*)(GLsizei, const GLuint *, GLboolean *)) &OpenGl_GlCore11::glAreTexturesResident, "None", py::arg("n"), py::arg("textures"), py::arg("residences"));
cls_OpenGl_GlCore11.def("glDrawPixels", (void (OpenGl_GlCore11::*)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11::glDrawPixels, "", py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11.def("glCopyPixels", (void (OpenGl_GlCore11::*)(GLint, GLint, GLsizei, GLsizei, GLenum)) &OpenGl_GlCore11::glCopyPixels, "None", py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("type"));
cls_OpenGl_GlCore11.def("glBitmap", (void (OpenGl_GlCore11::*)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *)) &OpenGl_GlCore11::glBitmap, "None", py::arg("width"), py::arg("height"), py::arg("xorig"), py::arg("yorig"), py::arg("xmove"), py::arg("ymove"), py::arg("bitmap"));
cls_OpenGl_GlCore11.def("glPixelZoom", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glPixelZoom, "None", py::arg("xfactor"), py::arg("yfactor"));
cls_OpenGl_GlCore11.def("glFogf", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glFogf, "", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glFogi", (void (OpenGl_GlCore11::*)(GLenum, GLint)) &OpenGl_GlCore11::glFogi, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glFogfv", (void (OpenGl_GlCore11::*)(GLenum, const GLfloat *)) &OpenGl_GlCore11::glFogfv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glFogiv", (void (OpenGl_GlCore11::*)(GLenum, const GLint *)) &OpenGl_GlCore11::glFogiv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMap1d", (void (OpenGl_GlCore11::*)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) &OpenGl_GlCore11::glMap1d, "", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("stride"), py::arg("order"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap1f", (void (OpenGl_GlCore11::*)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) &OpenGl_GlCore11::glMap1f, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("stride"), py::arg("order"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap2d", (void (OpenGl_GlCore11::*)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) &OpenGl_GlCore11::glMap2d, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("ustride"), py::arg("uorder"), py::arg("v1"), py::arg("v2"), py::arg("vstride"), py::arg("vorder"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap2f", (void (OpenGl_GlCore11::*)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) &OpenGl_GlCore11::glMap2f, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("ustride"), py::arg("uorder"), py::arg("v1"), py::arg("v2"), py::arg("vstride"), py::arg("vorder"), py::arg("points"));
cls_OpenGl_GlCore11.def("glGetMapdv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble *)) &OpenGl_GlCore11::glGetMapdv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glGetMapfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetMapfv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glGetMapiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetMapiv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord1d", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glEvalCoord1d, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1f", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glEvalCoord1f, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glEvalCoord1dv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glEvalCoord1fv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glEvalCoord2d, "None", py::arg("u"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glEvalCoord2f, "None", py::arg("u"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glEvalCoord2dv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glEvalCoord2fv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glMapGrid1d", (void (OpenGl_GlCore11::*)(GLint, GLdouble, GLdouble)) &OpenGl_GlCore11::glMapGrid1d, "None", py::arg("un"), py::arg("u1"), py::arg("u2"));
cls_OpenGl_GlCore11.def("glMapGrid1f", (void (OpenGl_GlCore11::*)(GLint, GLfloat, GLfloat)) &OpenGl_GlCore11::glMapGrid1f, "None", py::arg("un"), py::arg("u1"), py::arg("u2"));
cls_OpenGl_GlCore11.def("glMapGrid2d", (void (OpenGl_GlCore11::*)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble)) &OpenGl_GlCore11::glMapGrid2d, "None", py::arg("un"), py::arg("u1"), py::arg("u2"), py::arg("vn"), py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glMapGrid2f", (void (OpenGl_GlCore11::*)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat)) &OpenGl_GlCore11::glMapGrid2f, "None", py::arg("un"), py::arg("u1"), py::arg("u2"), py::arg("vn"), py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glEvalPoint1", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glEvalPoint1, "None", py::arg("i"));
cls_OpenGl_GlCore11.def("glEvalPoint2", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glEvalPoint2, "None", py::arg("i"), py::arg("j"));
cls_OpenGl_GlCore11.def("glEvalMesh1", (void (OpenGl_GlCore11::*)(GLenum, GLint, GLint)) &OpenGl_GlCore11::glEvalMesh1, "None", py::arg("mode"), py::arg("i1"), py::arg("i2"));
cls_OpenGl_GlCore11.def("glEvalMesh2", (void (OpenGl_GlCore11::*)(GLenum, GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glEvalMesh2, "None", py::arg("mode"), py::arg("i1"), py::arg("i2"), py::arg("j1"), py::arg("j2"));
cls_OpenGl_GlCore11.def("glFeedbackBuffer", (void (OpenGl_GlCore11::*)(GLsizei, GLenum, GLfloat *)) &OpenGl_GlCore11::glFeedbackBuffer, "", py::arg("theSize"), py::arg("theType"), py::arg("theBuffer"));
cls_OpenGl_GlCore11.def("glPassThrough", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glPassThrough, "None", py::arg("token"));
cls_OpenGl_GlCore11.def("glSelectBuffer", (void (OpenGl_GlCore11::*)(GLsizei, GLuint *)) &OpenGl_GlCore11::glSelectBuffer, "None", py::arg("theSize"), py::arg("theBuffer"));
cls_OpenGl_GlCore11.def("glInitNames", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glInitNames, "None");
cls_OpenGl_GlCore11.def("glLoadName", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glLoadName, "None", py::arg("theName"));
cls_OpenGl_GlCore11.def("glPushName", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glPushName, "None", py::arg("theName"));
cls_OpenGl_GlCore11.def("glPopName", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopName, "None");
cls_OpenGl_GlCore11.def("glClearAccum", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glClearAccum, "", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glAccum", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glAccum, "None", py::arg("theOp"), py::arg("theValue"));
cls_OpenGl_GlCore11.def("glEdgeFlag", (void (OpenGl_GlCore11::*)(GLboolean)) &OpenGl_GlCore11::glEdgeFlag, "", py::arg("theFlag"));
cls_OpenGl_GlCore11.def("glEdgeFlagv", (void (OpenGl_GlCore11::*)(const GLboolean *)) &OpenGl_GlCore11::glEdgeFlagv, "None", py::arg("theFlag"));
cls_OpenGl_GlCore11.def("glIndexPointer", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glIndexPointer, "None", py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glEdgeFlagPointer", (void (OpenGl_GlCore11::*)(GLsizei, const GLvoid *)) &OpenGl_GlCore11::glEdgeFlagPointer, "None", py::arg("theStride"), py::arg("thePtr"));
// cls_OpenGl_GlCore11.def("glGetPointerv", (void (OpenGl_GlCore11::*)(GLenum, GLvoid **)) &OpenGl_GlCore11::glGetPointerv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glInterleavedArrays", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glInterleavedArrays, "None", py::arg("theFormat"), py::arg("theStride"), py::arg("thePointer"));
cls_OpenGl_GlCore11.def("glVertexPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glVertexPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glNormalPointer", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glNormalPointer, "None", py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glColorPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glColorPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glTexCoordPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glTexCoordPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glEnableClientState", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glEnableClientState, "None", py::arg("theCap"));
cls_OpenGl_GlCore11.def("glDisableClientState", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glDisableClientState, "None", py::arg("theCap"));

// TYPEDEF: OPENGL_GLCORE12
bind_OpenGl_TmplCore12<OpenGl_GlCore11>(mod, "OpenGl_GlCore12", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE12FWD
bind_OpenGl_TmplCore12<OpenGl_GlCore11Fwd>(mod, "OpenGl_GlCore12Fwd", py::module_local(false));

// CLASS: OPENGL_GLCORE13FWD
py::class_<OpenGl_GlCore13Fwd> cls_OpenGl_GlCore13Fwd(mod, "OpenGl_GlCore13Fwd", "OpenGL 1.3 without deprecated entry points.");

// Constructors
cls_OpenGl_GlCore13Fwd.def(py::init<>());

// CLASS: OPENGL_GLCORE13
py::class_<OpenGl_GlCore13> cls_OpenGl_GlCore13(mod, "OpenGl_GlCore13", "OpenGL 1.3 core based on 1.2 version.");

// Constructors
cls_OpenGl_GlCore13.def(py::init<>());

// TYPEDEF: OPENGL_GLCORE14
bind_OpenGl_TmplCore14<OpenGl_GlCore13>(mod, "OpenGl_GlCore14", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE14FWD
bind_OpenGl_TmplCore14<OpenGl_GlCore13Fwd>(mod, "OpenGl_GlCore14Fwd", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE15
bind_OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> >(mod, "OpenGl_GlCore15", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE15FWD
bind_OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> >(mod, "OpenGl_GlCore15Fwd", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE20
bind_OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > >(mod, "OpenGl_GlCore20", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE20FWD
bind_OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > >(mod, "OpenGl_GlCore20Fwd", py::module_local(false));

// CLASS: OPENGL_RESOURCE
py::class_<OpenGl_Resource, opencascade::handle<OpenGl_Resource>, Standard_Transient> cls_OpenGl_Resource(mod, "OpenGl_Resource", "Interface for OpenGl resource with following meaning: - object can be constructed at any time; - should be explicitly Initialized within active OpenGL context; - should be explicitly Released within active OpenGL context (virtual Release() method); - can be destroyed at any time. Destruction of object with unreleased GPU resources will cause leaks which will be ignored in release mode and will immediately stop program execution in debug mode using assert.");

// Methods
cls_OpenGl_Resource.def("Release", (void (OpenGl_Resource::*)(OpenGl_Context *)) &OpenGl_Resource::Release, "Release GPU resources. Notice that implementation should be SAFE for several consecutive calls (thus should invalidate internal structures / ids to avoid multiple-free errors).", py::arg("theGlCtx"));
cls_OpenGl_Resource.def("EstimatedDataSize", (Standard_Size (OpenGl_Resource::*)() const) &OpenGl_Resource::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_Resource.def_static("get_type_name_", (const char * (*)()) &OpenGl_Resource::get_type_name, "None");
cls_OpenGl_Resource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Resource::get_type_descriptor, "None");
cls_OpenGl_Resource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Resource::*)() const) &OpenGl_Resource::DynamicType, "None");

// CLASS: OPENGL_CAPS
py::class_<OpenGl_Caps, opencascade::handle<OpenGl_Caps>, Standard_Transient> cls_OpenGl_Caps(mod, "OpenGl_Caps", "Class to define graphic driver capabilities. Notice that these options will be ignored if particular functionality does not provided by GL driver");

// Constructors
cls_OpenGl_Caps.def(py::init<>());

// Fields
cls_OpenGl_Caps.def_readwrite("vboDisable", &OpenGl_Caps::vboDisable, "flag permits VBO usage, will significantly affect performance (OFF by default)");
cls_OpenGl_Caps.def_readwrite("pntSpritesDisable", &OpenGl_Caps::pntSpritesDisable, "flag permits Point Sprites usage, will significantly affect performance (OFF by default)");
cls_OpenGl_Caps.def_readwrite("keepArrayData", &OpenGl_Caps::keepArrayData, "Disables freeing CPU memory after building VBOs (OFF by default)");
cls_OpenGl_Caps.def_readwrite("ffpEnable", &OpenGl_Caps::ffpEnable, "Enables FFP (fixed-function pipeline), do not use built-in GLSL programs (OFF by default)");
cls_OpenGl_Caps.def_readwrite("usePolygonMode", &OpenGl_Caps::usePolygonMode, "Enables Polygon Mode instead of built-in GLSL programs (OFF by default; unsupported on OpenGL ES)");
cls_OpenGl_Caps.def_readwrite("useSystemBuffer", &OpenGl_Caps::useSystemBuffer, "Enables usage of system backbuffer for blitting (OFF by default on desktop OpenGL and ON on OpenGL ES for testing)");
cls_OpenGl_Caps.def_readwrite("swapInterval", &OpenGl_Caps::swapInterval, "controls swap interval - 0 for VSync off and 1 for VSync on, 1 by default");
cls_OpenGl_Caps.def_readwrite("buffersNoSwap", &OpenGl_Caps::buffersNoSwap, "Specify that driver should not swap back/front buffers at the end of frame. Useful when OCCT Viewer is integrated into existing OpenGL rendering pipeline as part, thus swapping part is performed outside.");
cls_OpenGl_Caps.def_readwrite("contextStereo", &OpenGl_Caps::contextStereo, "Request stereoscopic context (with Quad Buffer). This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("contextDebug", &OpenGl_Caps::contextDebug, "Request debug GL context. This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("contextSyncDebug", &OpenGl_Caps::contextSyncDebug, "Request debug GL context to emit messages within main thread (when contextDebug is specified!).");
cls_OpenGl_Caps.def_readwrite("contextNoAccel", &OpenGl_Caps::contextNoAccel, "Disable hardware acceleration.");
cls_OpenGl_Caps.def_readwrite("contextCompatible", &OpenGl_Caps::contextCompatible, "Request backward-compatible GL context. This flag requires support in OpenGL driver.");
cls_OpenGl_Caps.def_readwrite("contextNoExtensions", &OpenGl_Caps::contextNoExtensions, "Disallow using OpenGL extensions. Should be used for debugging purposes only!");
cls_OpenGl_Caps.def_readwrite("contextMajorVersionUpper", &OpenGl_Caps::contextMajorVersionUpper, "Synthetically restrict upper version of OpenGL functionality to be used. Should be used for debugging purposes only!");
cls_OpenGl_Caps.def_readwrite("contextMinorVersionUpper", &OpenGl_Caps::contextMinorVersionUpper, "None");
cls_OpenGl_Caps.def_readwrite("glslWarnings", &OpenGl_Caps::glslWarnings, "Print GLSL program compilation/linkage warnings, if any. OFF by default.");
cls_OpenGl_Caps.def_readwrite("suppressExtraMsg", &OpenGl_Caps::suppressExtraMsg, "Suppress redundant messages from debug GL context. ON by default.");
cls_OpenGl_Caps.def_readwrite("glslDumpLevel", &OpenGl_Caps::glslDumpLevel, "Print GLSL program source code. OFF by default.");

// Methods
// cls_OpenGl_Caps.def("operator=", (OpenGl_Caps & (OpenGl_Caps::*)(const OpenGl_Caps &)) &OpenGl_Caps::operator=, "Copy maker.", py::arg("theCopy"));
cls_OpenGl_Caps.def_static("get_type_name_", (const char * (*)()) &OpenGl_Caps::get_type_name, "None");
cls_OpenGl_Caps.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Caps::get_type_descriptor, "None");
cls_OpenGl_Caps.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Caps::*)() const) &OpenGl_Caps::DynamicType, "None");

// TYPEDEF: OPENGL_MAPOFHATCHSTYLESANDIDS
bind_NCollection_DataMap<opencascade::handle<Graphic3d_HatchStyle>, unsigned int, NCollection_DefaultHasher<opencascade::handle<Graphic3d_HatchStyle> > >(mod, "OpenGl_MapOfHatchStylesAndIds", py::module_local(false));

// CLASS: OPENGL_LINEATTRIBUTES
/*
py::class_<OpenGl_LineAttributes, opencascade::handle<OpenGl_LineAttributes>, OpenGl_Resource> cls_OpenGl_LineAttributes(mod, "OpenGl_LineAttributes", "Utility class to manage OpenGL state of polygon hatching rasterization and keeping its cached state. The hatching rasterization is implemented using glPolygonStipple function of OpenGL. State of hatching is controlled by two parameters - type of hatching and IsEnabled parameter. The hatching rasterization is enabled only if non-zero index pattern type is selected (zero by default is reserved for solid filling) and if IsEnabled flag is set to true. The IsEnabled parameter is useful for temporarily turning on/off the hatching rasterization without making any costly GL calls for changing the hatch pattern. This is a sharable resource class - it creates OpenGL context objects for each hatch pattern to achieve quicker switching between them, thesse GL objects are freed when the resource is released by owner context.");

// Constructors
cls_OpenGl_LineAttributes.def(py::init<>());

// Methods
cls_OpenGl_LineAttributes.def("Release", (void (OpenGl_LineAttributes::*)(OpenGl_Context *)) &OpenGl_LineAttributes::Release, "Release GL resources.", py::arg("theGlCtx"));
cls_OpenGl_LineAttributes.def("EstimatedDataSize", (Standard_Size (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_LineAttributes.def("TypeOfHatch", (int (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::TypeOfHatch, "Index of currently selected type of hatch.");
cls_OpenGl_LineAttributes.def("SetTypeOfHatch", (int (OpenGl_LineAttributes::*)(const OpenGl_Context *, const opencascade::handle<Graphic3d_HatchStyle> &)) &OpenGl_LineAttributes::SetTypeOfHatch, "Sets type of the hatch.", py::arg("theGlCtx"), py::arg("theStyle"));
cls_OpenGl_LineAttributes.def("IsEnabled", (bool (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::IsEnabled, "Current enabled state of the hatching rasterization.");
cls_OpenGl_LineAttributes.def("SetEnabled", (bool (OpenGl_LineAttributes::*)(const OpenGl_Context *, const bool)) &OpenGl_LineAttributes::SetEnabled, "Turns on/off the hatching rasterization rasterization.", py::arg("theGlCtx"), py::arg("theToEnable"));
cls_OpenGl_LineAttributes.def_static("get_type_name_", (const char * (*)()) &OpenGl_LineAttributes::get_type_name, "None");
cls_OpenGl_LineAttributes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_LineAttributes::get_type_descriptor, "None");
cls_OpenGl_LineAttributes.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_LineAttributes::*)() const) &OpenGl_LineAttributes::DynamicType, "None");
*/

// TYPEDEF: OPENGL_VEC2I
bind_NCollection_Vec2<int>(mod, "OpenGl_Vec2i", py::module_local());

// TYPEDEF: OPENGL_VEC3I
bind_NCollection_Vec3<int>(mod, "OpenGl_Vec3i", py::module_local());

// TYPEDEF: OPENGL_VEC4I
bind_NCollection_Vec4<int>(mod, "OpenGl_Vec4i", py::module_local());

// TYPEDEF: OPENGL_VEC2B
bind_NCollection_Vec2<char>(mod, "OpenGl_Vec2b", py::module_local());

// TYPEDEF: OPENGL_VEC3B
bind_NCollection_Vec3<char>(mod, "OpenGl_Vec3b", py::module_local());

// TYPEDEF: OPENGL_VEC4B
bind_NCollection_Vec4<char>(mod, "OpenGl_Vec4b", py::module_local());

// TYPEDEF: OPENGL_VEC2U
bind_NCollection_Vec2<unsigned int>(mod, "OpenGl_Vec2u", py::module_local());

// TYPEDEF: OPENGL_VEC3U
bind_NCollection_Vec3<unsigned int>(mod, "OpenGl_Vec3u", py::module_local());

// TYPEDEF: OPENGL_VEC4U
bind_NCollection_Vec4<unsigned int>(mod, "OpenGl_Vec4u", py::module_local());

// TYPEDEF: OPENGL_VEC2UB
bind_NCollection_Vec2<unsigned char>(mod, "OpenGl_Vec2ub", py::module_local());

// TYPEDEF: OPENGL_VEC3UB
bind_NCollection_Vec3<unsigned char>(mod, "OpenGl_Vec3ub", py::module_local());

// TYPEDEF: OPENGL_VEC4UB
bind_NCollection_Vec4<unsigned char>(mod, "OpenGl_Vec4ub", py::module_local());

// TYPEDEF: OPENGL_VEC2
bind_NCollection_Vec2<float>(mod, "OpenGl_Vec2", py::module_local());

// TYPEDEF: OPENGL_VEC3
bind_NCollection_Vec3<float>(mod, "OpenGl_Vec3", py::module_local());

// TYPEDEF: OPENGL_VEC4
bind_NCollection_Vec4<float>(mod, "OpenGl_Vec4", py::module_local());

// TYPEDEF: OPENGL_VEC2D
bind_NCollection_Vec2<double>(mod, "OpenGl_Vec2d", py::module_local());

// TYPEDEF: OPENGL_VEC3D
bind_NCollection_Vec3<double>(mod, "OpenGl_Vec3d", py::module_local());

// TYPEDEF: OPENGL_VEC4D
bind_NCollection_Vec4<double>(mod, "OpenGl_Vec4d", py::module_local());

// TYPEDEF: OPENGL_MAT4
bind_NCollection_Mat4<float>(mod, "OpenGl_Mat4", py::module_local());

// TYPEDEF: OPENGL_MAT4D
bind_NCollection_Mat4<double>(mod, "OpenGl_Mat4d", py::module_local());

// CLASS: OPENGL_MATERIAL
py::class_<OpenGl_Material> cls_OpenGl_Material(mod, "OpenGl_Material", "OpenGL material definition");

// Constructors
cls_OpenGl_Material.def(py::init<>());

// Fields
cls_OpenGl_Material.def_readwrite("Ambient", &OpenGl_Material::Ambient, "ambient reflection coefficient");
cls_OpenGl_Material.def_readwrite("Diffuse", &OpenGl_Material::Diffuse, "diffuse reflection coefficient");
cls_OpenGl_Material.def_readwrite("Specular", &OpenGl_Material::Specular, "glossy reflection coefficient");
cls_OpenGl_Material.def_readwrite("Emission", &OpenGl_Material::Emission, "material emission");
cls_OpenGl_Material.def_readwrite("Params", &OpenGl_Material::Params, "extra packed parameters");

// Methods
cls_OpenGl_Material.def("Shine", (float (OpenGl_Material::*)() const) &OpenGl_Material::Shine, "None");
cls_OpenGl_Material.def("ChangeShine", (float & (OpenGl_Material::*)()) &OpenGl_Material::ChangeShine, "None");
cls_OpenGl_Material.def("Transparency", (float (OpenGl_Material::*)() const) &OpenGl_Material::Transparency, "None");
cls_OpenGl_Material.def("ChangeTransparency", (float & (OpenGl_Material::*)()) &OpenGl_Material::ChangeTransparency, "None");
cls_OpenGl_Material.def("SetColor", (void (OpenGl_Material::*)(const OpenGl_Vec4 &)) &OpenGl_Material::SetColor, "Set material color.", py::arg("theColor"));
// cls_OpenGl_Material.def("Init", (void (OpenGl_Material::*)(const Graphic3d_MaterialAspect &, const Quantity_Color &)) &OpenGl_Material::Init, "Initialize material", py::arg("theProp"), py::arg("theInteriorColor"));
cls_OpenGl_Material.def("Packed", (const OpenGl_Vec4 * (OpenGl_Material::*)() const) &OpenGl_Material::Packed, "Returns packed (serialized) representation of material properties");
cls_OpenGl_Material.def_static("NbOfVec4_", (Standard_Integer (*)()) &OpenGl_Material::NbOfVec4, "None");
cls_OpenGl_Material.def("IsEqual", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::IsEqual, "Check this material for equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__eq__", (bool (OpenGl_Material::*)(const OpenGl_Material &)) &OpenGl_Material::operator==, py::is_operator(), "Check this material for equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__eq__", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::operator==, py::is_operator(), "None", py::arg("theOther"));
cls_OpenGl_Material.def("__ne__", (bool (OpenGl_Material::*)(const OpenGl_Material &)) &OpenGl_Material::operator!=, py::is_operator(), "Check this material for non-equality with another material (without tolerance!).", py::arg("theOther"));
cls_OpenGl_Material.def("__ne__", (bool (OpenGl_Material::*)(const OpenGl_Material &) const) &OpenGl_Material::operator!=, py::is_operator(), "None", py::arg("theOther"));

// CLASS: OPENGL_TEXTURESET
py::class_<OpenGl_TextureSet, opencascade::handle<OpenGl_TextureSet>, Standard_Transient> cls_OpenGl_TextureSet(mod, "OpenGl_TextureSet", "Class holding array of textures to be mapped as a set.");

// Constructors
cls_OpenGl_TextureSet.def(py::init<>());
cls_OpenGl_TextureSet.def(py::init<Standard_Integer>(), py::arg("theNbTextures"));
cls_OpenGl_TextureSet.def(py::init<const opencascade::handle<OpenGl_Texture> &>(), py::arg("theTexture"));

// Methods
cls_OpenGl_TextureSet.def_static("get_type_name_", (const char * (*)()) &OpenGl_TextureSet::get_type_name, "None");
cls_OpenGl_TextureSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TextureSet::get_type_descriptor, "None");
cls_OpenGl_TextureSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::DynamicType, "None");
cls_OpenGl_TextureSet.def("IsEmpty", (Standard_Boolean (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::IsEmpty, "Return TRUE if texture array is empty.");
cls_OpenGl_TextureSet.def("Size", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Size, "Return number of textures.");
cls_OpenGl_TextureSet.def("Lower", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Lower, "Return the lower index in texture set.");
cls_OpenGl_TextureSet.def("Upper", (Standard_Integer (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Upper, "Return the upper index in texture set.");
cls_OpenGl_TextureSet.def("First", (const opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::First, "Return the first texture.");
cls_OpenGl_TextureSet.def("ChangeFirst", (opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)()) &OpenGl_TextureSet::ChangeFirst, "Return the first texture.");
cls_OpenGl_TextureSet.def("Last", (const opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::Last, "Return the last texture.");
cls_OpenGl_TextureSet.def("ChangeLast", (opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)()) &OpenGl_TextureSet::ChangeLast, "Return the last texture.");
cls_OpenGl_TextureSet.def("Value", (const opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)(Standard_Integer) const) &OpenGl_TextureSet::Value, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
cls_OpenGl_TextureSet.def("ChangeValue", (opencascade::handle<OpenGl_Texture> & (OpenGl_TextureSet::*)(Standard_Integer)) &OpenGl_TextureSet::ChangeValue, "Return the texture at specified position within [0, Size()) range.", py::arg("theIndex"));
cls_OpenGl_TextureSet.def("IsModulate", (bool (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::IsModulate, "Return TRUE if texture color modulation has been enabled for the first texture or if texture is not set at all.");
cls_OpenGl_TextureSet.def("HasNonPointSprite", (bool (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::HasNonPointSprite, "Return TRUE if other than point sprite textures are defined within point set.");
cls_OpenGl_TextureSet.def("HasPointSprite", (bool (OpenGl_TextureSet::*)() const) &OpenGl_TextureSet::HasPointSprite, "Return TRUE if last texture is a point sprite.");
cls_OpenGl_TextureSet.def("InitZero", (void (OpenGl_TextureSet::*)()) &OpenGl_TextureSet::InitZero, "Nullify all handles.");

// CLASS: OPENGL_CLIPPING
py::class_<OpenGl_Clipping> cls_OpenGl_Clipping(mod, "OpenGl_Clipping", "This class contains logics related to tracking and modification of clipping plane state for particular OpenGl context. It contains information about enabled clipping planes and provides method to change clippings in context. The methods should be executed within OpenGl context associated with instance of this class.");

// Constructors
cls_OpenGl_Clipping.def(py::init<>());

// Methods
cls_OpenGl_Clipping.def("Init", (void (OpenGl_Clipping::*)()) &OpenGl_Clipping::Init, "Initialize.");
cls_OpenGl_Clipping.def("Reset", (void (OpenGl_Clipping::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_Clipping::Reset, "Setup list of global (for entire view) clipping planes and clears local plane list if it was not released before.", py::arg("thePlanes"));
cls_OpenGl_Clipping.def("SetLocalPlanes", (void (OpenGl_Clipping::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_Clipping::SetLocalPlanes, "Setup list of local (for current object) clipping planes.", py::arg("thePlanes"));
cls_OpenGl_Clipping.def("IsCappingOn", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsCappingOn, "Returns true if there are enabled capping planes");
cls_OpenGl_Clipping.def("IsClippingOrCappingOn", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsClippingOrCappingOn, "Returns true if there are enabled clipping or capping planes");
cls_OpenGl_Clipping.def("NbClippingOrCappingOn", (Standard_Integer (OpenGl_Clipping::*)() const) &OpenGl_Clipping::NbClippingOrCappingOn, "Returns number of enabled clipping + capping planes");
cls_OpenGl_Clipping.def("HasClippingChains", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::HasClippingChains, "Return TRUE if there are clipping chains in the list (defining more than 1 sub-plane)");
cls_OpenGl_Clipping.def("HasDisabled", (Standard_Boolean (OpenGl_Clipping::*)() const) &OpenGl_Clipping::HasDisabled, "Return true if some clipping planes have been temporarily disabled.");
cls_OpenGl_Clipping.def("SetEnabled", (Standard_Boolean (OpenGl_Clipping::*)(const OpenGl_ClippingIterator &, const Standard_Boolean)) &OpenGl_Clipping::SetEnabled, "Disable plane temporarily.", py::arg("thePlane"), py::arg("theIsEnabled"));
cls_OpenGl_Clipping.def("DisableGlobal", (void (OpenGl_Clipping::*)()) &OpenGl_Clipping::DisableGlobal, "Temporarily disable all planes from the global (view) list, keep only local (object) list.");
cls_OpenGl_Clipping.def("RestoreDisabled", (void (OpenGl_Clipping::*)()) &OpenGl_Clipping::RestoreDisabled, "Restore all temporarily disabled planes. Does NOT affect constantly disabled planes Graphic3d_ClipPlane::IsOn().");
cls_OpenGl_Clipping.def("CappedChain", (const opencascade::handle<Graphic3d_ClipPlane> & (OpenGl_Clipping::*)() const) &OpenGl_Clipping::CappedChain, "Chain which is either temporary disabled or the only one enabled for Capping algorithm.");
cls_OpenGl_Clipping.def("CappedSubPlane", (Standard_Integer (OpenGl_Clipping::*)() const) &OpenGl_Clipping::CappedSubPlane, "Sub-plane index within filtered Chain; positive number for DisableAllExcept and negative for EnableAllExcept.");
cls_OpenGl_Clipping.def("IsCappingFilterOn", (bool (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsCappingFilterOn, "Return TRUE if capping algorithm is in state, when all clipping planes are temporarily disabled except currently processed one.");
cls_OpenGl_Clipping.def("IsCappingDisableAllExcept", (bool (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsCappingDisableAllExcept, "Return TRUE if capping algorithm is in state, when all clipping planes are temporarily disabled except currently processed one.");
cls_OpenGl_Clipping.def("IsCappingEnableAllExcept", (bool (OpenGl_Clipping::*)() const) &OpenGl_Clipping::IsCappingEnableAllExcept, "Return TRUE if capping algorithm is in state, when all clipping planes are enabled except currently rendered one.");
cls_OpenGl_Clipping.def("DisableAllExcept", (void (OpenGl_Clipping::*)(const opencascade::handle<Graphic3d_ClipPlane> &, const Standard_Integer)) &OpenGl_Clipping::DisableAllExcept, "Temporarily disable all planes except specified one for Capping algorithm. Does not affect already disabled planes.", py::arg("theChain"), py::arg("theSubPlaneIndex"));
cls_OpenGl_Clipping.def("EnableAllExcept", (void (OpenGl_Clipping::*)(const opencascade::handle<Graphic3d_ClipPlane> &, const Standard_Integer)) &OpenGl_Clipping::EnableAllExcept, "Enable back planes disabled by ::DisableAllExcept() for Capping algorithm. Keeps only specified plane enabled.", py::arg("theChain"), py::arg("theSubPlaneIndex"));
cls_OpenGl_Clipping.def("ResetCappingFilter", (void (OpenGl_Clipping::*)()) &OpenGl_Clipping::ResetCappingFilter, "Resets chain filter for Capping algorithm.");

// TYPEDEF: OPENGL_GLCORE12
if (py::hasattr(mod, "OpenGl_GlCore12")) {
	mod.attr("OpenGl_GlCore12") = mod.attr("OpenGl_GlCore12");
}

// TYPEDEF: OPENGL_GLCORE12FWD
if (py::hasattr(mod, "OpenGl_GlCore12Fwd")) {
	mod.attr("OpenGl_GlCore12Fwd") = mod.attr("OpenGl_GlCore12Fwd");
}

// TYPEDEF: OPENGL_GLCORE14
if (py::hasattr(mod, "OpenGl_GlCore14")) {
	mod.attr("OpenGl_GlCore14") = mod.attr("OpenGl_GlCore14");
}

// TYPEDEF: OPENGL_GLCORE14FWD
if (py::hasattr(mod, "OpenGl_GlCore14Fwd")) {
	mod.attr("OpenGl_GlCore14Fwd") = mod.attr("OpenGl_GlCore14Fwd");
}

// TYPEDEF: OPENGL_GLCORE15
if (py::hasattr(mod, "OpenGl_GlCore15")) {
	mod.attr("OpenGl_GlCore15") = mod.attr("OpenGl_GlCore15");
}

// TYPEDEF: OPENGL_GLCORE15FWD
if (py::hasattr(mod, "OpenGl_GlCore15Fwd")) {
	mod.attr("OpenGl_GlCore15Fwd") = mod.attr("OpenGl_GlCore15Fwd");
}

// TYPEDEF: OPENGL_GLCORE20
if (py::hasattr(mod, "OpenGl_GlCore20")) {
	mod.attr("OpenGl_GlCore20") = mod.attr("OpenGl_GlCore20");
}

// TYPEDEF: OPENGL_GLCORE20FWD
if (py::hasattr(mod, "OpenGl_GlCore20Fwd")) {
	mod.attr("OpenGl_GlCore20Fwd") = mod.attr("OpenGl_GlCore20Fwd");
}

// TYPEDEF: OPENGL_GLCORE21
bind_OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > >(mod, "OpenGl_GlCore21", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE21FWD
bind_OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > >(mod, "OpenGl_GlCore21Fwd", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE30
bind_OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > >(mod, "OpenGl_GlCore30", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE30FWD
bind_OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > >(mod, "OpenGl_GlCore30Fwd", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE31BACK
bind_OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > >(mod, "OpenGl_GlCore31Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE31
bind_OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > >(mod, "OpenGl_GlCore31", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE32BACK
bind_OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > >(mod, "OpenGl_GlCore32Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE32
bind_OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > >(mod, "OpenGl_GlCore32", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE33BACK
bind_OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > >(mod, "OpenGl_GlCore33Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE33
bind_OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > >(mod, "OpenGl_GlCore33", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE40BACK
bind_OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > >(mod, "OpenGl_GlCore40Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE40
bind_OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > >(mod, "OpenGl_GlCore40", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE41BACK
bind_OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > > >(mod, "OpenGl_GlCore41Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE41
bind_OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > > >(mod, "OpenGl_GlCore41", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE42BACK
bind_OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > > > >(mod, "OpenGl_GlCore42Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE42
bind_OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > > > >(mod, "OpenGl_GlCore42", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE43BACK
bind_OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > > > > >(mod, "OpenGl_GlCore43Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE43
bind_OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > > > > >(mod, "OpenGl_GlCore43", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE44BACK
bind_OpenGl_TmplCore44<OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > > > > > >(mod, "OpenGl_GlCore44Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE44
bind_OpenGl_TmplCore44<OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > > > > > >(mod, "OpenGl_GlCore44", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE45BACK
bind_OpenGl_TmplCore45<OpenGl_TmplCore44<OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13> > > > > > > > > > > > > >(mod, "OpenGl_GlCore45Back", py::module_local(false));

// TYPEDEF: OPENGL_GLCORE45
bind_OpenGl_TmplCore45<OpenGl_TmplCore44<OpenGl_TmplCore43<OpenGl_TmplCore42<OpenGl_TmplCore41<OpenGl_TmplCore40<OpenGl_TmplCore33<OpenGl_TmplCore32<OpenGl_TmplCore31<OpenGl_TmplCore30<OpenGl_TmplCore21<OpenGl_TmplCore20<OpenGl_TmplCore15<OpenGl_TmplCore14<OpenGl_GlCore13Fwd> > > > > > > > > > > > > >(mod, "OpenGl_GlCore45", py::module_local(false));

// CLASS: OPENGL_CONTEXT
py::class_<OpenGl_Context, opencascade::handle<OpenGl_Context>, Standard_Transient> cls_OpenGl_Context(mod, "OpenGl_Context", "This class generalize access to the GL context and available extensions.");

// Constructors
cls_OpenGl_Context.def(py::init<>());
cls_OpenGl_Context.def(py::init<const opencascade::handle<OpenGl_Caps> &>(), py::arg("theCaps"));

// Fields
// cls_OpenGl_Context.def_readwrite("core11", &OpenGl_Context::core11, "OpenGL 1.1 core functionality");
// cls_OpenGl_Context.def_readwrite("core11fwd", &OpenGl_Context::core11fwd, "OpenGL 1.1 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core15", &OpenGl_Context::core15, "OpenGL 1.5 core functionality");
// cls_OpenGl_Context.def_readwrite("core15fwd", &OpenGl_Context::core15fwd, "OpenGL 1.5 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core20", &OpenGl_Context::core20, "OpenGL 2.0 core functionality (includes 1.5)");
// cls_OpenGl_Context.def_readwrite("core20fwd", &OpenGl_Context::core20fwd, "OpenGL 2.0 without deprecated entry points");
// cls_OpenGl_Context.def_readwrite("core32", &OpenGl_Context::core32, "OpenGL 3.2 core profile");
// cls_OpenGl_Context.def_readwrite("core32back", &OpenGl_Context::core32back, "OpenGL 3.2 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core33", &OpenGl_Context::core33, "OpenGL 3.3 core profile");
// cls_OpenGl_Context.def_readwrite("core33back", &OpenGl_Context::core33back, "OpenGL 3.3 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core41", &OpenGl_Context::core41, "OpenGL 4.1 core profile");
// cls_OpenGl_Context.def_readwrite("core41back", &OpenGl_Context::core41back, "OpenGL 4.1 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core42", &OpenGl_Context::core42, "OpenGL 4.2 core profile");
// cls_OpenGl_Context.def_readwrite("core42back", &OpenGl_Context::core42back, "OpenGL 4.2 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core43", &OpenGl_Context::core43, "OpenGL 4.3 core profile");
// cls_OpenGl_Context.def_readwrite("core43back", &OpenGl_Context::core43back, "OpenGL 4.3 backward compatibility profile");
// cls_OpenGl_Context.def_readwrite("core44", &OpenGl_Context::core44, "OpenGL 4.4 core profile");
// cls_OpenGl_Context.def_readwrite("core44back", &OpenGl_Context::core44back, "OpenGL 4.4 backward compatibility profile");
cls_OpenGl_Context.def_readwrite("core45", &OpenGl_Context::core45, "OpenGL 4.5 core profile");
cls_OpenGl_Context.def_readwrite("core45back", &OpenGl_Context::core45back, "OpenGL 4.5 backward compatibility profile");
cls_OpenGl_Context.def_readwrite("caps", &OpenGl_Context::caps, "context options");
cls_OpenGl_Context.def_readwrite("hasHighp", &OpenGl_Context::hasHighp, "highp in GLSL ES fragment shader is supported");
cls_OpenGl_Context.def_readwrite("hasUintIndex", &OpenGl_Context::hasUintIndex, "GLuint for index buffer is supported (always available on desktop; on OpenGL ES - since 3.0 or as extension GL_OES_element_index_uint)");
cls_OpenGl_Context.def_readwrite("hasTexRGBA8", &OpenGl_Context::hasTexRGBA8, "always available on desktop; on OpenGL ES - since 3.0 or as extension GL_OES_rgb8_rgba8");
cls_OpenGl_Context.def_readwrite("hasFlatShading", &OpenGl_Context::hasFlatShading, "Complex flag indicating support of Flat shading (Graphic3d_TOSM_FACET) (always available on desktop; on OpenGL ES - since 3.0 or as extension GL_OES_standard_derivatives)");
cls_OpenGl_Context.def_readwrite("hasGlslBitwiseOps", &OpenGl_Context::hasGlslBitwiseOps, "GLSL supports bitwise operations; OpenGL 3.0 / OpenGL ES 3.0 (GLSL 130 / GLSL ES 300) or OpenGL 2.1 + GL_EXT_gpu_shader4");
cls_OpenGl_Context.def_readwrite("hasDrawBuffers", &OpenGl_Context::hasDrawBuffers, "Complex flag indicating support of multiple draw buffers (desktop OpenGL 2.0, OpenGL ES 3.0, GL_ARB_draw_buffers, GL_EXT_draw_buffers)");
cls_OpenGl_Context.def_readwrite("hasFloatBuffer", &OpenGl_Context::hasFloatBuffer, "Complex flag indicating support of float color buffer format (desktop OpenGL 3.0, GL_ARB_color_buffer_float, GL_EXT_color_buffer_float)");
cls_OpenGl_Context.def_readwrite("hasHalfFloatBuffer", &OpenGl_Context::hasHalfFloatBuffer, "Complex flag indicating support of half-float color buffer format (desktop OpenGL 3.0, GL_ARB_color_buffer_float, GL_EXT_color_buffer_half_float)");
cls_OpenGl_Context.def_readwrite("hasSampleVariables", &OpenGl_Context::hasSampleVariables, "Complex flag indicating support of MSAA variables in GLSL shader (desktop OpenGL 4.0, GL_ARB_sample_shading)");
cls_OpenGl_Context.def_readwrite("hasGeometryStage", &OpenGl_Context::hasGeometryStage, "Complex flag indicating support of Geometry shader (desktop OpenGL 3.2, OpenGL ES 3.2, GL_EXT_geometry_shader)");
cls_OpenGl_Context.def_readwrite("arbDrawBuffers", &OpenGl_Context::arbDrawBuffers, "GL_ARB_draw_buffers");
cls_OpenGl_Context.def_readwrite("arbNPTW", &OpenGl_Context::arbNPTW, "GL_ARB_texture_non_power_of_two");
cls_OpenGl_Context.def_readwrite("arbTexRG", &OpenGl_Context::arbTexRG, "GL_ARB_texture_rg");
cls_OpenGl_Context.def_readwrite("arbTexFloat", &OpenGl_Context::arbTexFloat, "GL_ARB_texture_float (on desktop OpenGL - since 3.0 or as extension GL_ARB_texture_float; on OpenGL ES - since 3.0)");
cls_OpenGl_Context.def_readwrite("arbSamplerObject", &OpenGl_Context::arbSamplerObject, "GL_ARB_sampler_objects (on desktop OpenGL - since 3.3 or as extension GL_ARB_sampler_objects; on OpenGL ES - since 3.0)");
cls_OpenGl_Context.def_readwrite("arbTexBindless", &OpenGl_Context::arbTexBindless, "GL_ARB_bindless_texture");
cls_OpenGl_Context.def_readwrite("arbTBO", &OpenGl_Context::arbTBO, "GL_ARB_texture_buffer_object");
cls_OpenGl_Context.def_readwrite("arbTboRGB32", &OpenGl_Context::arbTboRGB32, "GL_ARB_texture_buffer_object_rgb32 (3-component TBO), in core since 4.0");
cls_OpenGl_Context.def_readwrite("arbIns", &OpenGl_Context::arbIns, "GL_ARB_draw_instanced");
cls_OpenGl_Context.def_readwrite("arbDbg", &OpenGl_Context::arbDbg, "GL_ARB_debug_output");
cls_OpenGl_Context.def_readwrite("arbFBO", &OpenGl_Context::arbFBO, "GL_ARB_framebuffer_object");
cls_OpenGl_Context.def_readwrite("arbFBOBlit", &OpenGl_Context::arbFBOBlit, "glBlitFramebuffer function, moved out from OpenGl_ArbFBO structure for compatibility with OpenGL ES 2.0");
cls_OpenGl_Context.def_readwrite("arbSampleShading", &OpenGl_Context::arbSampleShading, "GL_ARB_sample_shading");
cls_OpenGl_Context.def_readwrite("extFragDepth", &OpenGl_Context::extFragDepth, "GL_EXT_frag_depth on OpenGL ES 2.0 (gl_FragDepthEXT built-in variable, before OpenGL ES 3.0)");
cls_OpenGl_Context.def_readwrite("extDrawBuffers", &OpenGl_Context::extDrawBuffers, "GL_EXT_draw_buffers");
cls_OpenGl_Context.def_readwrite("extGS", &OpenGl_Context::extGS, "GL_EXT_geometry_shader4");
cls_OpenGl_Context.def_readwrite("extBgra", &OpenGl_Context::extBgra, "GL_EXT_bgra or GL_EXT_texture_format_BGRA8888 on OpenGL ES");
cls_OpenGl_Context.def_readwrite("extAnis", &OpenGl_Context::extAnis, "GL_EXT_texture_filter_anisotropic");
cls_OpenGl_Context.def_readwrite("extPDS", &OpenGl_Context::extPDS, "GL_EXT_packed_depth_stencil");
cls_OpenGl_Context.def_readwrite("atiMem", &OpenGl_Context::atiMem, "GL_ATI_meminfo");
cls_OpenGl_Context.def_readwrite("nvxMem", &OpenGl_Context::nvxMem, "GL_NVX_gpu_memory_info");
cls_OpenGl_Context.def_readwrite("oesSampleVariables", &OpenGl_Context::oesSampleVariables, "GL_OES_sample_variables");
cls_OpenGl_Context.def_readwrite("oesStdDerivatives", &OpenGl_Context::oesStdDerivatives, "GL_OES_standard_derivatives");
cls_OpenGl_Context.def_readwrite("ModelWorldState", &OpenGl_Context::ModelWorldState, "state of orientation matrix");
cls_OpenGl_Context.def_readwrite("WorldViewState", &OpenGl_Context::WorldViewState, "state of orientation matrix");
cls_OpenGl_Context.def_readwrite("ProjectionState", &OpenGl_Context::ProjectionState, "state of projection matrix");

// Methods
cls_OpenGl_Context.def_static("get_type_name_", (const char * (*)()) &OpenGl_Context::get_type_name, "None");
cls_OpenGl_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Context::get_type_descriptor, "None");
cls_OpenGl_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Context::*)() const) &OpenGl_Context::DynamicType, "None");
cls_OpenGl_Context.def_static("GetPowerOfTwo_", (Standard_Integer (*)(const Standard_Integer, const Standard_Integer)) &OpenGl_Context::GetPowerOfTwo, "Function for getting power of to number larger or equal to input number.", py::arg("theNumber"), py::arg("theThreshold"));
cls_OpenGl_Context.def("forcedRelease", (void (OpenGl_Context::*)()) &OpenGl_Context::forcedRelease, "Release all resources, including shared ones");
cls_OpenGl_Context.def("Share", (void (OpenGl_Context::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Context::Share, "Share GL context resources. theShareCtx - handle to context to retrieve handles to shared resources.", py::arg("theShareCtx"));
cls_OpenGl_Context.def("Init", [](OpenGl_Context &self) -> Standard_Boolean { return self.Init(); });
cls_OpenGl_Context.def("Init", (Standard_Boolean (OpenGl_Context::*)(const Standard_Boolean)) &OpenGl_Context::Init, "Initialize class from currently bound OpenGL context. Method should be called only once.", py::arg("theIsCoreProfile"));
cls_OpenGl_Context.def("IsValid", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsValid, "Returns true if this context is valid (has been initialized)");
cls_OpenGl_Context.def("Init", [](OpenGl_Context &self, const Aspect_Handle a0, const Aspect_Handle a1, const Aspect_RenderingContext a2) -> Standard_Boolean { return self.Init(a0, a1, a2); });
cls_OpenGl_Context.def("Init", (Standard_Boolean (OpenGl_Context::*)(const Aspect_Handle, const Aspect_Handle, const Aspect_RenderingContext, const Standard_Boolean)) &OpenGl_Context::Init, "Initialize class from specified window and rendering context. Method should be called only once.", py::arg("theWindow"), py::arg("theWindowDC"), py::arg("theGContext"), py::arg("theIsCoreProfile"));
cls_OpenGl_Context.def("Window", (Aspect_Handle (OpenGl_Context::*)() const) &OpenGl_Context::Window, "Returns the window handle (HWND) currently bound to this OpenGL context");
cls_OpenGl_Context.def_static("ReadGlVersion_", [](Standard_Integer & theGlVerMajor, Standard_Integer & theGlVerMinor){ OpenGl_Context::ReadGlVersion(theGlVerMajor, theGlVerMinor); return std::tuple<Standard_Integer &, Standard_Integer &>(theGlVerMajor, theGlVerMinor); }, "Read OpenGL version information from active context.", py::arg("theGlVerMajor"), py::arg("theGlVerMinor"));
cls_OpenGl_Context.def("CheckExtension", (Standard_Boolean (OpenGl_Context::*)(const char *) const) &OpenGl_Context::CheckExtension, "Check if theExtName extension is supported by active GL context.", py::arg("theExtName"));
cls_OpenGl_Context.def_static("CheckExtension_", (Standard_Boolean (*)(const char *, const char *)) &OpenGl_Context::CheckExtension, "Check if theExtName extension is in extensions string.", py::arg("theExtString"), py::arg("theExtName"));
cls_OpenGl_Context.def("IsGlGreaterEqual", (Standard_Boolean (OpenGl_Context::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_Context::IsGlGreaterEqual, "Returns true if detected GL version is greater or equal to requested one.", py::arg("theVerMajor"), py::arg("theVerMinor"));
cls_OpenGl_Context.def("VersionMajor", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::VersionMajor, "Return cached GL version major number.");
cls_OpenGl_Context.def("VersionMinor", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::VersionMinor, "Return cached GL version minor number.");
cls_OpenGl_Context.def("Functions", (const OpenGl_GlFunctions * (OpenGl_Context::*)() const) &OpenGl_Context::Functions, "Access entire map of loaded OpenGL functions.");
cls_OpenGl_Context.def("ResetErrors", [](OpenGl_Context &self) -> bool { return self.ResetErrors(); });
cls_OpenGl_Context.def("ResetErrors", (bool (OpenGl_Context::*)(const bool)) &OpenGl_Context::ResetErrors, "Clean up errors stack for this GL context (glGetError() in loop).", py::arg("theToPrintErrors"));
cls_OpenGl_Context.def("IsCurrent", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsCurrent, "This method uses system-dependent API to retrieve information about GL context bound to the current thread.");
cls_OpenGl_Context.def("MakeCurrent", (Standard_Boolean (OpenGl_Context::*)()) &OpenGl_Context::MakeCurrent, "Activates current context. Class should be initialized with appropriate info.");
cls_OpenGl_Context.def("SwapBuffers", (void (OpenGl_Context::*)()) &OpenGl_Context::SwapBuffers, "Swap front/back buffers for this GL context (should be activated before!).");
cls_OpenGl_Context.def("SetSwapInterval", (Standard_Boolean (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetSwapInterval, "Setup swap interval (VSync).", py::arg("theInterval"));
cls_OpenGl_Context.def("IsRender", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsRender, "Return true if active mode is GL_RENDER (cached state)");
cls_OpenGl_Context.def("IsFeedback", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsFeedback, "Return true if active mode is GL_FEEDBACK (cached state)");
cls_OpenGl_Context.def("AvailableMemory", (Standard_Size (OpenGl_Context::*)() const) &OpenGl_Context::AvailableMemory, "This function retrieves information from GL about free GPU memory that is: - OS-dependent. On some OS it is per-process and on others - for entire system. - Vendor-dependent. Currently available only on NVIDIA and AMD/ATi drivers only. - Numbers meaning may vary. You should use this info only for diagnostics purposes.");
cls_OpenGl_Context.def("MemoryInfo", (TCollection_AsciiString (OpenGl_Context::*)() const) &OpenGl_Context::MemoryInfo, "This function retrieves information from GL about GPU memory and contains more vendor-specific values than AvailableMemory().");
cls_OpenGl_Context.def("MemoryInfo", (void (OpenGl_Context::*)(TColStd_IndexedDataMapOfStringString &) const) &OpenGl_Context::MemoryInfo, "This function retrieves information from GL about GPU memory.", py::arg("theDict"));
cls_OpenGl_Context.def("DiagnosticInformation", (void (OpenGl_Context::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &OpenGl_Context::DiagnosticInformation, "Fill in the dictionary with OpenGL info. Should be called with bound context.", py::arg("theDict"), py::arg("theFlags"));
cls_OpenGl_Context.def("GetResource", (const opencascade::handle<OpenGl_Resource> & (OpenGl_Context::*)(const TCollection_AsciiString &) const) &OpenGl_Context::GetResource, "Access shared resource by its name.", py::arg("theKey"));
cls_OpenGl_Context.def("ShareResource", (Standard_Boolean (OpenGl_Context::*)(const TCollection_AsciiString &, const opencascade::handle<OpenGl_Resource> &)) &OpenGl_Context::ShareResource, "Register shared resource. Notice that after registration caller shouldn't release it by himself - it will be automatically released on context destruction.", py::arg("theKey"), py::arg("theResource"));
cls_OpenGl_Context.def("ReleaseResource", [](OpenGl_Context &self, const TCollection_AsciiString & a0) -> void { return self.ReleaseResource(a0); });
cls_OpenGl_Context.def("ReleaseResource", (void (OpenGl_Context::*)(const TCollection_AsciiString &, const Standard_Boolean)) &OpenGl_Context::ReleaseResource, "Release shared resource. If there are more than one reference to this resource (also used by some other existing object) then call will be ignored. This means that current object itself should nullify handle before this call. Notice that this is unrecommended operation at all and should be used only in case of fat resources to release memory for other needs.", py::arg("theKey"), py::arg("theToDelay"));
cls_OpenGl_Context.def("ReleaseDelayed", (void (OpenGl_Context::*)()) &OpenGl_Context::ReleaseDelayed, "Clean up the delayed release queue.");
cls_OpenGl_Context.def("SharedResources", (const OpenGl_Context::OpenGl_ResourcesMap & (OpenGl_Context::*)() const) &OpenGl_Context::SharedResources, "Return map of shared resources.");
cls_OpenGl_Context.def("ChangeClipping", (OpenGl_Clipping & (OpenGl_Context::*)()) &OpenGl_Context::ChangeClipping, "Returns tool for management of clippings within this context.");
cls_OpenGl_Context.def("Clipping", (const OpenGl_Clipping & (OpenGl_Context::*)() const) &OpenGl_Context::Clipping, "Returns tool for management of clippings within this context.");
cls_OpenGl_Context.def("ShaderManager", (const opencascade::handle<OpenGl_ShaderManager> & (OpenGl_Context::*)() const) &OpenGl_Context::ShaderManager, "Returns tool for management of shader programs within this context.");
cls_OpenGl_Context.def("TextureWrapClamp", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::TextureWrapClamp, "Either GL_CLAMP_TO_EDGE (1.2+) or GL_CLAMP (1.1).");
cls_OpenGl_Context.def("MaxDegreeOfAnisotropy", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDegreeOfAnisotropy, "Returns maximum degree of anisotropy texture filter");
cls_OpenGl_Context.def("MaxTextureSize", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxTextureSize, "Returns value for GL_MAX_TEXTURE_SIZE");
cls_OpenGl_Context.def("MaxCombinedTextureUnits", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxCombinedTextureUnits, "Returns value for GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS");
cls_OpenGl_Context.def("MaxTextureUnitsFFP", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxTextureUnitsFFP, "This method returns the multi-texture limit for obsolete fixed-function pipeline. Use MaxCombinedTextureUnits() instead for limits for using programmable pipeline.");
cls_OpenGl_Context.def("SpriteTextureUnit", (Graphic3d_TextureUnit (OpenGl_Context::*)() const) &OpenGl_Context::SpriteTextureUnit, "Returns texture unit to be used for sprites");
cls_OpenGl_Context.def("MaxMsaaSamples", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxMsaaSamples, "Returns value for GL_MAX_SAMPLES");
cls_OpenGl_Context.def("MaxDumpSizeX", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDumpSizeX, "Returns maximum FBO width for image dump");
cls_OpenGl_Context.def("MaxDumpSizeY", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDumpSizeY, "Returns maximum FBO height for image dump");
cls_OpenGl_Context.def("MaxDrawBuffers", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxDrawBuffers, "Returns value for GL_MAX_DRAW_BUFFERS");
cls_OpenGl_Context.def("MaxColorAttachments", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxColorAttachments, "Returns value for GL_MAX_COLOR_ATTACHMENTS");
cls_OpenGl_Context.def("MaxClipPlanes", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::MaxClipPlanes, "Get maximum number of clip planes supported by OpenGl. This value is implementation dependent. At least 6 planes should be supported by OpenGl (see specs).");
cls_OpenGl_Context.def("HasRayTracing", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracing, "Returns TRUE if ray tracing mode is supported");
cls_OpenGl_Context.def("HasRayTracingTextures", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracingTextures, "Returns TRUE if textures in ray tracing mode are supported");
cls_OpenGl_Context.def("HasRayTracingAdaptiveSampling", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracingAdaptiveSampling, "Returns TRUE if adaptive screen sampling in ray tracing mode is supported");
cls_OpenGl_Context.def("HasRayTracingAdaptiveSamplingAtomic", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRayTracingAdaptiveSamplingAtomic, "Returns TRUE if atomic adaptive screen sampling in ray tracing mode is supported");
cls_OpenGl_Context.def("ToUseVbo", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ToUseVbo, "Returns true if VBO is supported and permitted.");
cls_OpenGl_Context.def("IsGlNormalizeEnabled", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsGlNormalizeEnabled, "Returns cached state of GL_NORMALIZE.");
cls_OpenGl_Context.def("SetGlNormalizeEnabled", (Standard_Boolean (OpenGl_Context::*)(Standard_Boolean)) &OpenGl_Context::SetGlNormalizeEnabled, "Sets GL_NORMALIZE enabled or disabled.", py::arg("isEnabled"));
cls_OpenGl_Context.def("PolygonMode", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::PolygonMode, "Returns cached state of polygon rasterization mode (glPolygonMode()).");
cls_OpenGl_Context.def("SetPolygonMode", (Standard_Integer (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetPolygonMode, "Sets polygon rasterization mode (glPolygonMode() function).", py::arg("theMode"));
cls_OpenGl_Context.def("IsPolygonHatchEnabled", (bool (OpenGl_Context::*)() const) &OpenGl_Context::IsPolygonHatchEnabled, "Returns cached enabled state of polygon hatching rasterization.");
cls_OpenGl_Context.def("SetPolygonHatchEnabled", (bool (OpenGl_Context::*)(const bool)) &OpenGl_Context::SetPolygonHatchEnabled, "Sets enabled state of polygon hatching rasterization without affecting currently selected hatching pattern.", py::arg("theIsEnabled"));
cls_OpenGl_Context.def("PolygonHatchStyle", (Standard_Integer (OpenGl_Context::*)() const) &OpenGl_Context::PolygonHatchStyle, "Returns cached state of polygon hatch type.");
cls_OpenGl_Context.def("SetPolygonHatchStyle", (Standard_Integer (OpenGl_Context::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &OpenGl_Context::SetPolygonHatchStyle, "Sets polygon hatch pattern. Zero-index value is a default alias for solid filling.", py::arg("theStyle"));
cls_OpenGl_Context.def("SetPolygonOffset", (void (OpenGl_Context::*)(const Graphic3d_PolygonOffset &)) &OpenGl_Context::SetPolygonOffset, "Sets and applies current polygon offset.", py::arg("theOffset"));
cls_OpenGl_Context.def("PolygonOffset", (const Graphic3d_PolygonOffset & (OpenGl_Context::*)() const) &OpenGl_Context::PolygonOffset, "Returns currently applied polygon offset parameters.");
cls_OpenGl_Context.def("ApplyModelWorldMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyModelWorldMatrix, "Applies matrix stored in ModelWorldState to OpenGl.");
cls_OpenGl_Context.def("ApplyWorldViewMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyWorldViewMatrix, "Applies matrix stored in WorldViewState to OpenGl.");
cls_OpenGl_Context.def("ApplyModelViewMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyModelViewMatrix, "Applies combination of matrices stored in ModelWorldState and WorldViewState to OpenGl.");
cls_OpenGl_Context.def("ApplyProjectionMatrix", (void (OpenGl_Context::*)()) &OpenGl_Context::ApplyProjectionMatrix, "Applies matrix stored in ProjectionState to OpenGl.");
cls_OpenGl_Context.def("Messenger", (const opencascade::handle<Message_Messenger> & (OpenGl_Context::*)() const) &OpenGl_Context::Messenger, "Returns messenger instance");
cls_OpenGl_Context.def("PushMessage", (void (OpenGl_Context::*)(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const TCollection_ExtendedString &)) &OpenGl_Context::PushMessage, "Callback for GL_ARB_debug_output extension", py::arg("theSource"), py::arg("theType"), py::arg("theId"), py::arg("theSeverity"), py::arg("theMessage"));
cls_OpenGl_Context.def("ExcludeMessage", (Standard_Boolean (OpenGl_Context::*)(const unsigned int, const unsigned int)) &OpenGl_Context::ExcludeMessage, "Adds a filter for messages with theId and theSource (GL_DEBUG_SOURCE_)", py::arg("theSource"), py::arg("theId"));
cls_OpenGl_Context.def("IncludeMessage", (Standard_Boolean (OpenGl_Context::*)(const unsigned int, const unsigned int)) &OpenGl_Context::IncludeMessage, "Removes a filter for messages with theId and theSource (GL_DEBUG_SOURCE_)", py::arg("theSource"), py::arg("theId"));
cls_OpenGl_Context.def("HasStereoBuffers", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasStereoBuffers, "Returns true if OpenGl context supports left and right rendering buffers.");
cls_OpenGl_Context.def("FrameStats", (const opencascade::handle<OpenGl_FrameStats> & (OpenGl_Context::*)() const) &OpenGl_Context::FrameStats, "Return structure holding frame statistics.");
cls_OpenGl_Context.def("SetFrameStats", (void (OpenGl_Context::*)(const opencascade::handle<OpenGl_FrameStats> &)) &OpenGl_Context::SetFrameStats, "Set structure holding frame statistics. This call makes sense only if application defines OpenGl_FrameStats sub-class.", py::arg("theStats"));
cls_OpenGl_Context.def("Viewport", (const Standard_Integer * (OpenGl_Context::*)() const) &OpenGl_Context::Viewport, "Return cached viewport definition (x, y, width, height).");
// cls_OpenGl_Context.def("ResizeViewport", (void (OpenGl_Context::*)(const Standard_Integer [4])) &OpenGl_Context::ResizeViewport, "Resize the viewport (alias for glViewport).", py::arg("theRect"));
cls_OpenGl_Context.def("VirtualViewport", (const Standard_Integer * (OpenGl_Context::*)() const) &OpenGl_Context::VirtualViewport, "Return virtual viewport definition (x, y, width, height).");
cls_OpenGl_Context.def("ReadBuffer", (Standard_Integer (OpenGl_Context::*)()) &OpenGl_Context::ReadBuffer, "Return active read buffer.");
cls_OpenGl_Context.def("SetReadBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetReadBuffer, "Switch read buffer, wrapper for ::glReadBuffer().", py::arg("theReadBuffer"));
cls_OpenGl_Context.def("DrawBuffer", [](OpenGl_Context &self) -> Standard_Integer { return self.DrawBuffer(); });
cls_OpenGl_Context.def("DrawBuffer", (Standard_Integer (OpenGl_Context::*)(Standard_Integer) const) &OpenGl_Context::DrawBuffer, "Return active draw buffer attached to a render target referred by index (layout location).", py::arg("theIndex"));
cls_OpenGl_Context.def("SetDrawBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetDrawBuffer, "Switch draw buffer, wrapper for ::glDrawBuffer().", py::arg("theDrawBuffer"));
cls_OpenGl_Context.def("SetDrawBuffers", (void (OpenGl_Context::*)(const Standard_Integer, const Standard_Integer *)) &OpenGl_Context::SetDrawBuffers, "Switch draw buffer, wrapper for ::glDrawBuffers (GLsizei, const GLenum*).", py::arg("theNb"), py::arg("theDrawBuffers"));
cls_OpenGl_Context.def("SetReadDrawBuffer", (void (OpenGl_Context::*)(const Standard_Integer)) &OpenGl_Context::SetReadDrawBuffer, "Switch read/draw buffers.", py::arg("theBuffer"));
cls_OpenGl_Context.def("ColorMask", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ColorMask, "Return cached flag indicating writing into color buffer is enabled or disabled (glColorMask).");
cls_OpenGl_Context.def("SetColorMask", (bool (OpenGl_Context::*)(bool)) &OpenGl_Context::SetColorMask, "Enable/disable writing into color buffer (wrapper for glColorMask).", py::arg("theToWriteColor"));
cls_OpenGl_Context.def("AllowSampleAlphaToCoverage", (bool (OpenGl_Context::*)() const) &OpenGl_Context::AllowSampleAlphaToCoverage, "Return TRUE if GL_SAMPLE_ALPHA_TO_COVERAGE usage is allowed.");
cls_OpenGl_Context.def("SetAllowSampleAlphaToCoverage", (void (OpenGl_Context::*)(bool)) &OpenGl_Context::SetAllowSampleAlphaToCoverage, "Allow GL_SAMPLE_ALPHA_TO_COVERAGE usage.", py::arg("theToEnable"));
cls_OpenGl_Context.def("SampleAlphaToCoverage", (bool (OpenGl_Context::*)() const) &OpenGl_Context::SampleAlphaToCoverage, "Return GL_SAMPLE_ALPHA_TO_COVERAGE state.");
cls_OpenGl_Context.def("SetSampleAlphaToCoverage", (bool (OpenGl_Context::*)(bool)) &OpenGl_Context::SetSampleAlphaToCoverage, "Enable/disable GL_SAMPLE_ALPHA_TO_COVERAGE.", py::arg("theToEnable"));
cls_OpenGl_Context.def("ToCullBackFaces", (bool (OpenGl_Context::*)() const) &OpenGl_Context::ToCullBackFaces, "Return back face culling state.");
cls_OpenGl_Context.def("SetCullBackFaces", (void (OpenGl_Context::*)(bool)) &OpenGl_Context::SetCullBackFaces, "Enable or disable back face culling (glEnable (GL_CULL_FACE)).", py::arg("theToEnable"));
cls_OpenGl_Context.def("FetchState", (void (OpenGl_Context::*)()) &OpenGl_Context::FetchState, "Fetch OpenGl context state. This class tracks value of several OpenGl state variables. Consulting the cached values is quicker than doing the same via OpenGl API. Call this method if any of the controlled OpenGl state variables has a possibility of being out-of-date.");
cls_OpenGl_Context.def("ActiveTextures", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_Context::*)() const) &OpenGl_Context::ActiveTextures, "Returns active textures");
cls_OpenGl_Context.def("BindTextures", (opencascade::handle<OpenGl_TextureSet> (OpenGl_Context::*)(const opencascade::handle<OpenGl_TextureSet> &)) &OpenGl_Context::BindTextures, "Bind specified texture set to current context, or unbind previous one when NULL specified.", py::arg("theTextures"));
cls_OpenGl_Context.def("ActiveProgram", (const opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_Context::*)() const) &OpenGl_Context::ActiveProgram, "Returns active GLSL program");
cls_OpenGl_Context.def("BindProgram", (Standard_Boolean (OpenGl_Context::*)(const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_Context::BindProgram, "Bind specified program to current context, or unbind previous one when NULL specified.", py::arg("theProgram"));
cls_OpenGl_Context.def("SetShadingMaterial", (void (OpenGl_Context::*)(const OpenGl_Aspects *, const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Context::SetShadingMaterial, "Setup current shading material.", py::arg("theAspect"), py::arg("theHighlight"));
cls_OpenGl_Context.def_static("CheckIsTransparent_", (Standard_Boolean (*)(const OpenGl_Aspects *, const opencascade::handle<Graphic3d_PresentationAttributes> &, Standard_ShortReal &, Standard_ShortReal &)) &OpenGl_Context::CheckIsTransparent, "Checks if transparency is required for the given aspect and highlight style.", py::arg("theAspect"), py::arg("theHighlight"), py::arg("theAlphaFront"), py::arg("theAlphaBack"));
cls_OpenGl_Context.def_static("CheckIsTransparent_", (Standard_Boolean (*)(const OpenGl_Aspects *, const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Context::CheckIsTransparent, "Checks if transparency is required for the given aspect and highlight style.", py::arg("theAspect"), py::arg("theHighlight"));
cls_OpenGl_Context.def("SetColor4fv", (void (OpenGl_Context::*)(const OpenGl_Vec4 &)) &OpenGl_Context::SetColor4fv, "Setup current color.", py::arg("theColor"));
cls_OpenGl_Context.def("SetTypeOfLine", [](OpenGl_Context &self, const Aspect_TypeOfLine a0) -> void { return self.SetTypeOfLine(a0); });
cls_OpenGl_Context.def("SetTypeOfLine", (void (OpenGl_Context::*)(const Aspect_TypeOfLine, const Standard_ShortReal)) &OpenGl_Context::SetTypeOfLine, "Setup type of line.", py::arg("theType"), py::arg("theFactor"));
cls_OpenGl_Context.def("SetLineWidth", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetLineWidth, "Setup width of line.", py::arg("theWidth"));
cls_OpenGl_Context.def("SetPointSize", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetPointSize, "Setup point size.", py::arg("theSize"));
cls_OpenGl_Context.def("SetPointSpriteOrigin", (void (OpenGl_Context::*)()) &OpenGl_Context::SetPointSpriteOrigin, "Setup point sprite origin using GL_POINT_SPRITE_COORD_ORIGIN state: - GL_UPPER_LEFT when GLSL program is active; flipping should be handled in GLSL program for compatibility with OpenGL ES - GL_LOWER_LEFT for FFP");
cls_OpenGl_Context.def("SetTextureMatrix", (void (OpenGl_Context::*)(const opencascade::handle<Graphic3d_TextureParams> &)) &OpenGl_Context::SetTextureMatrix, "Setup texture matrix to active GLSL program or to FFP global state using glMatrixMode (GL_TEXTURE).", py::arg("theParams"));
cls_OpenGl_Context.def("BindDefaultVao", (void (OpenGl_Context::*)()) &OpenGl_Context::BindDefaultVao, "Bind default Vertex Array Object");
cls_OpenGl_Context.def("DefaultFrameBuffer", (const opencascade::handle<OpenGl_FrameBuffer> & (OpenGl_Context::*)() const) &OpenGl_Context::DefaultFrameBuffer, "Default Frame Buffer Object.");
cls_OpenGl_Context.def("SetDefaultFrameBuffer", (opencascade::handle<OpenGl_FrameBuffer> (OpenGl_Context::*)(const opencascade::handle<OpenGl_FrameBuffer> &)) &OpenGl_Context::SetDefaultFrameBuffer, "Setup new Default Frame Buffer Object and return previously set. This call doesn't change Active FBO!", py::arg("theFbo"));
cls_OpenGl_Context.def("IsDebugContext", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::IsDebugContext, "Return debug context initialization state.");
cls_OpenGl_Context.def("EnableFeatures", (void (OpenGl_Context::*)() const) &OpenGl_Context::EnableFeatures, "None");
cls_OpenGl_Context.def("DisableFeatures", (void (OpenGl_Context::*)() const) &OpenGl_Context::DisableFeatures, "None");
cls_OpenGl_Context.def("Resolution", (unsigned int (OpenGl_Context::*)() const) &OpenGl_Context::Resolution, "Return resolution for rendering text.");
cls_OpenGl_Context.def("ResolutionRatio", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::ResolutionRatio, "Resolution scale factor (rendered resolution to standard resolution). This scaling factor for parameters like text size to be properly displayed on device (screen / printer).");
cls_OpenGl_Context.def("RenderScale", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::RenderScale, "Rendering scale factor (rendering viewport height to real window buffer height).");
cls_OpenGl_Context.def("HasRenderScale", (Standard_Boolean (OpenGl_Context::*)() const) &OpenGl_Context::HasRenderScale, "Return TRUE if rendering scale factor is not 1.");
cls_OpenGl_Context.def("RenderScaleInv", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::RenderScaleInv, "Rendering scale factor (inverted value).");
cls_OpenGl_Context.def("LineWidthScale", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::LineWidthScale, "Return scale factor for line width.");
cls_OpenGl_Context.def("SetResolution", (void (OpenGl_Context::*)(unsigned int, Standard_ShortReal, Standard_ShortReal)) &OpenGl_Context::SetResolution, "Set resolution ratio. Note that this method rounds to nearest integer.", py::arg("theResolution"), py::arg("theRatio"), py::arg("theScale"));
cls_OpenGl_Context.def("SetResolutionRatio", (void (OpenGl_Context::*)(const Standard_ShortReal)) &OpenGl_Context::SetResolutionRatio, "Set resolution ratio. Note that this method rounds to nearest integer.", py::arg("theRatio"));
cls_OpenGl_Context.def("LineFeather", (Standard_ShortReal (OpenGl_Context::*)() const) &OpenGl_Context::LineFeather, "Return line feater width in pixels.");
cls_OpenGl_Context.def("SetLineFeather", (void (OpenGl_Context::*)(Standard_ShortReal)) &OpenGl_Context::SetLineFeather, "Set line feater width.", py::arg("theValue"));
cls_OpenGl_Context.def("Vendor", (const TCollection_AsciiString & (OpenGl_Context::*)() const) &OpenGl_Context::Vendor, "Return Graphics Driver's vendor.");

// CLASS: OPENGL_MATRIX
py::class_<OpenGl_Matrix> cls_OpenGl_Matrix(mod, "OpenGl_Matrix", "None");

// Constructors
cls_OpenGl_Matrix.def(py::init<>());

// Fields
// cls_OpenGl_Matrix.def_readwrite("mat", &OpenGl_Matrix::mat, "None");

// Methods
// cls_OpenGl_Matrix.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Matrix::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Matrix.def_static("operator delete_", (void (*)(void *)) &OpenGl_Matrix::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Matrix::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Matrix.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Matrix::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Matrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Matrix.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Matrix::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_NAMEDRESOURCE
py::class_<OpenGl_NamedResource, opencascade::handle<OpenGl_NamedResource>, OpenGl_Resource> cls_OpenGl_NamedResource(mod, "OpenGl_NamedResource", "Named resource object.");

// Methods
cls_OpenGl_NamedResource.def_static("get_type_name_", (const char * (*)()) &OpenGl_NamedResource::get_type_name, "None");
cls_OpenGl_NamedResource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_NamedResource::get_type_descriptor, "None");
cls_OpenGl_NamedResource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_NamedResource::*)() const) &OpenGl_NamedResource::DynamicType, "None");
cls_OpenGl_NamedResource.def("ResourceId", (const TCollection_AsciiString & (OpenGl_NamedResource::*)() const) &OpenGl_NamedResource::ResourceId, "Return resource name.");

// CLASS: OPENGL_SHADEROBJECT
py::class_<OpenGl_ShaderObject, opencascade::handle<OpenGl_ShaderObject>, OpenGl_Resource> cls_OpenGl_ShaderObject(mod, "OpenGl_ShaderObject", "Wrapper for OpenGL shader object.");

// Constructors
cls_OpenGl_ShaderObject.def(py::init<GLenum>(), py::arg("theType"));

// Methods
cls_OpenGl_ShaderObject.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderObject::get_type_name, "None");
cls_OpenGl_ShaderObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderObject::get_type_descriptor, "None");
cls_OpenGl_ShaderObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::DynamicType, "None");
cls_OpenGl_ShaderObject.def_static("CreateFromSource_", [](TCollection_AsciiString & a0, Graphic3d_TypeOfShaderObject a1, const OpenGl_ShaderObject::ShaderVariableList & a2, const OpenGl_ShaderObject::ShaderVariableList & a3) -> opencascade::handle<Graphic3d_ShaderObject> { return OpenGl_ShaderObject::CreateFromSource(a0, a1, a2, a3); });
cls_OpenGl_ShaderObject.def_static("CreateFromSource_", [](TCollection_AsciiString & a0, Graphic3d_TypeOfShaderObject a1, const OpenGl_ShaderObject::ShaderVariableList & a2, const OpenGl_ShaderObject::ShaderVariableList & a3, const TCollection_AsciiString & a4) -> opencascade::handle<Graphic3d_ShaderObject> { return OpenGl_ShaderObject::CreateFromSource(a0, a1, a2, a3, a4); });
cls_OpenGl_ShaderObject.def_static("CreateFromSource_", [](TCollection_AsciiString & a0, Graphic3d_TypeOfShaderObject a1, const OpenGl_ShaderObject::ShaderVariableList & a2, const OpenGl_ShaderObject::ShaderVariableList & a3, const TCollection_AsciiString & a4, const TCollection_AsciiString & a5) -> opencascade::handle<Graphic3d_ShaderObject> { return OpenGl_ShaderObject::CreateFromSource(a0, a1, a2, a3, a4, a5); });
cls_OpenGl_ShaderObject.def_static("CreateFromSource_", (opencascade::handle<Graphic3d_ShaderObject> (*)(TCollection_AsciiString &, Graphic3d_TypeOfShaderObject, const OpenGl_ShaderObject::ShaderVariableList &, const OpenGl_ShaderObject::ShaderVariableList &, const TCollection_AsciiString &, const TCollection_AsciiString &, Standard_Integer)) &OpenGl_ShaderObject::CreateFromSource, "This is a preprocessor for Graphic3d_ShaderObject::CreateFromSource() function. Creates a new shader object from specified source according to list of uniforms and in/out variables.", py::arg("theSource"), py::arg("theType"), py::arg("theUniforms"), py::arg("theStageInOuts"), py::arg("theInName"), py::arg("theOutName"), py::arg("theNbGeomInputVerts"));
cls_OpenGl_ShaderObject.def("LoadSource", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &)) &OpenGl_ShaderObject::LoadSource, "Loads shader source code.", py::arg("theCtx"), py::arg("theSource"));
cls_OpenGl_ShaderObject.def("Compile", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderObject::Compile, "Compiles the shader object.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("LoadAndCompile", [](OpenGl_ShaderObject &self, const opencascade::handle<OpenGl_Context> & a0, const TCollection_AsciiString & a1, const TCollection_AsciiString & a2) -> Standard_Boolean { return self.LoadAndCompile(a0, a1, a2); });
cls_OpenGl_ShaderObject.def("LoadAndCompile", [](OpenGl_ShaderObject &self, const opencascade::handle<OpenGl_Context> & a0, const TCollection_AsciiString & a1, const TCollection_AsciiString & a2, bool a3) -> Standard_Boolean { return self.LoadAndCompile(a0, a1, a2, a3); });
cls_OpenGl_ShaderObject.def("LoadAndCompile", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &, const TCollection_AsciiString &, bool, bool)) &OpenGl_ShaderObject::LoadAndCompile, "Wrapper for compiling shader object with verbose printing on error.", py::arg("theCtx"), py::arg("theId"), py::arg("theSource"), py::arg("theIsVerbose"), py::arg("theToPrintSource"));
cls_OpenGl_ShaderObject.def("DumpSourceCode", (void (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &, const TCollection_AsciiString &) const) &OpenGl_ShaderObject::DumpSourceCode, "Print source code of this shader object to messenger.", py::arg("theCtx"), py::arg("theId"), py::arg("theSource"));
cls_OpenGl_ShaderObject.def("FetchInfoLog", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, TCollection_AsciiString &)) &OpenGl_ShaderObject::FetchInfoLog, "Fetches information log of the last compile operation.", py::arg("theCtx"), py::arg("theLog"));
cls_OpenGl_ShaderObject.def("Create", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderObject::Create, "Creates new empty shader object of specified type.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("Release", (void (OpenGl_ShaderObject::*)(OpenGl_Context *)) &OpenGl_ShaderObject::Release, "Destroys shader object.", py::arg("theCtx"));
cls_OpenGl_ShaderObject.def("EstimatedDataSize", (Standard_Size (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_ShaderObject.def("Type", (GLenum (OpenGl_ShaderObject::*)() const) &OpenGl_ShaderObject::Type, "Returns type of shader object.");
cls_OpenGl_ShaderObject.def("updateDebugDump", (Standard_Boolean (OpenGl_ShaderObject::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &, const TCollection_AsciiString &, Standard_Boolean, Standard_Boolean)) &OpenGl_ShaderObject::updateDebugDump, "Update the shader object from external file in the following way: 1) If external file does not exist, then it will be created (current source code will be dumped, no recompilation) and FALSE will be returned. 2) If external file exists and it has the same timestamp as myDumpDate, nothing will be done and FALSE will be returned. 3) If external file exists and it has newer timestamp than myDumpDate, shader will be recompiled and TRUE will be returned.", py::arg("theCtx"), py::arg("theId"), py::arg("theFolder"), py::arg("theToBeautify"), py::arg("theToReset"));

// CLASS: OPENGL_SETTERINTERFACE
py::class_<OpenGl_SetterInterface> cls_OpenGl_SetterInterface(mod, "OpenGl_SetterInterface", "Interface for generic setter of user-defined uniform variables.");

// Methods
cls_OpenGl_SetterInterface.def("Set", (void (OpenGl_SetterInterface::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_ShaderVariable> &, OpenGl_ShaderProgram *)) &OpenGl_SetterInterface::Set, "Sets user-defined uniform variable to specified program.", py::arg("theCtx"), py::arg("theVariable"), py::arg("theProgram"));

// TYPEDEF: OPENGL_SHADERLIST
bind_NCollection_Sequence<opencascade::handle<OpenGl_ShaderObject> >(mod, "OpenGl_ShaderList", py::module_local(false));

// TYPEDEF: OPENGL_SETTERLIST
/*
bind_NCollection_DataMap<unsigned long long, OpenGl_SetterInterface *, NCollection_DefaultHasher<unsigned long long> >(mod, "OpenGl_SetterList", py::module_local(false));
*/

// CLASS: OPENGL_VARIABLESETTERSELECTOR
/*
py::class_<OpenGl_VariableSetterSelector> cls_OpenGl_VariableSetterSelector(mod, "OpenGl_VariableSetterSelector", "Support tool for setting user-defined uniform variables.");

// Constructors
cls_OpenGl_VariableSetterSelector.def(py::init<>());

// Methods
cls_OpenGl_VariableSetterSelector.def("Set", (void (OpenGl_VariableSetterSelector::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_ShaderVariable> &, OpenGl_ShaderProgram *) const) &OpenGl_VariableSetterSelector::Set, "Sets user-defined uniform variable to specified program.", py::arg("theCtx"), py::arg("theVariable"), py::arg("theProgram"));
*/

// CLASS: OPENGL_SHADERUNIFORMLOCATION
py::class_<OpenGl_ShaderUniformLocation> cls_OpenGl_ShaderUniformLocation(mod, "OpenGl_ShaderUniformLocation", "Simple class represents GLSL program variable location.");

// Constructors
cls_OpenGl_ShaderUniformLocation.def(py::init<>());
cls_OpenGl_ShaderUniformLocation.def(py::init<GLint>(), py::arg("theLocation"));

// Methods
cls_OpenGl_ShaderUniformLocation.def("IsValid", (bool (OpenGl_ShaderUniformLocation::*)() const) &OpenGl_ShaderUniformLocation::IsValid, "Note you may safely put invalid location in functions like glUniform* - the data passed in will be silently ignored.");

// CLASS: OPENGL_SHADERPROGRAM
/*
py::class_<OpenGl_ShaderProgram, opencascade::handle<OpenGl_ShaderProgram>, OpenGl_NamedResource> cls_OpenGl_ShaderProgram(mod, "OpenGl_ShaderProgram", "Wrapper for OpenGL program object.");

// Constructors
cls_OpenGl_ShaderProgram.def(py::init<>());
cls_OpenGl_ShaderProgram.def(py::init<const opencascade::handle<Graphic3d_ShaderProgram> &>(), py::arg("theProxy"));
cls_OpenGl_ShaderProgram.def(py::init<const opencascade::handle<Graphic3d_ShaderProgram> &, const TCollection_AsciiString &>(), py::arg("theProxy"), py::arg("theId"));

// Methods
cls_OpenGl_ShaderProgram.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderProgram::get_type_name, "None");
cls_OpenGl_ShaderProgram.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderProgram::get_type_descriptor, "None");
cls_OpenGl_ShaderProgram.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::DynamicType, "None");
cls_OpenGl_ShaderProgram.def_static("compileShaderVerbose_", [](const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<OpenGl_ShaderObject> & a1, const TCollection_AsciiString & a2) -> bool { return OpenGl_ShaderProgram::compileShaderVerbose(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def_static("compileShaderVerbose_", (bool (*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_ShaderObject> &, const TCollection_AsciiString &, bool)) &OpenGl_ShaderProgram::compileShaderVerbose, "Wrapper for compiling shader object with verbose printing on error.", py::arg("theCtx"), py::arg("theShader"), py::arg("theSource"), py::arg("theToPrintSource"));
cls_OpenGl_ShaderProgram.def("Create", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderProgram::Create, "Creates new empty shader program of specified type.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("Release", (void (OpenGl_ShaderProgram::*)(OpenGl_Context *)) &OpenGl_ShaderProgram::Release, "Destroys shader program.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("EstimatedDataSize", (Standard_Size (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::EstimatedDataSize, "Returns estimated GPU memory usage - cannot be easily estimated.");
cls_OpenGl_ShaderProgram.def("AttachShader", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_ShaderObject> &)) &OpenGl_ShaderProgram::AttachShader, "Attaches shader object to the program object.", py::arg("theCtx"), py::arg("theShader"));
cls_OpenGl_ShaderProgram.def("DetachShader", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_ShaderObject> &)) &OpenGl_ShaderProgram::DetachShader, "Detaches shader object to the program object.", py::arg("theCtx"), py::arg("theShader"));
cls_OpenGl_ShaderProgram.def("Initialize", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_ShaderObjectList &)) &OpenGl_ShaderProgram::Initialize, "Initializes program object with the list of shader objects.", py::arg("theCtx"), py::arg("theShaders"));
cls_OpenGl_ShaderProgram.def("Link", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0) -> Standard_Boolean { return self.Link(a0); });
cls_OpenGl_ShaderProgram.def("Link", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, bool)) &OpenGl_ShaderProgram::Link, "Links the program object.", py::arg("theCtx"), py::arg("theIsVerbose"));
cls_OpenGl_ShaderProgram.def("FetchInfoLog", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, TCollection_AsciiString &)) &OpenGl_ShaderProgram::FetchInfoLog, "Fetches information log of the last link operation.", py::arg("theCtx"), py::arg("theLog"));
cls_OpenGl_ShaderProgram.def("ApplyVariables", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_ShaderProgram::ApplyVariables, "Fetches uniform variables from proxy shader program.", py::arg("theCtx"));
cls_OpenGl_ShaderProgram.def("IsValid", (bool (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::IsValid, "Returns true if current object was initialized");
cls_OpenGl_ShaderProgram.def("ProgramId", (GLuint (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::ProgramId, "Returns program ID");
cls_OpenGl_ShaderProgram.def("HasTessellationStage", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasTessellationStage, "Return TRUE if program defines tessellation stage.");
cls_OpenGl_ShaderProgram.def("NbLightsMax", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbLightsMax, "Return the length of array of light sources (THE_MAX_LIGHTS), to be used for initialization occLightSources (OpenGl_OCC_LIGHT_SOURCE_PARAMS).");
cls_OpenGl_ShaderProgram.def("NbClipPlanesMax", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbClipPlanesMax, "Return the length of array of clipping planes (THE_MAX_CLIP_PLANES), to be used for initialization occClipPlaneEquations (OpenGl_OCC_CLIP_PLANE_EQUATIONS) and occClipPlaneChains (OpenGl_OCC_CLIP_PLANE_CHAINS).");
cls_OpenGl_ShaderProgram.def("NbFragmentOutputs", (Standard_Integer (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::NbFragmentOutputs, "Return the length of array of Fragment Shader outputs (THE_NB_FRAG_OUTPUTS), to be used for initialization occFragColorArray/occFragColorN.");
cls_OpenGl_ShaderProgram.def("HasAlphaTest", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasAlphaTest, "Return true if Fragment Shader should perform alpha test; FALSE by default.");
cls_OpenGl_ShaderProgram.def("HasWeightOitOutput", (Standard_Boolean (OpenGl_ShaderProgram::*)() const) &OpenGl_ShaderProgram::HasWeightOitOutput, "Return true if Fragment Shader color should output the weighted OIT coverage; FALSE by default.");
cls_OpenGl_ShaderProgram.def("GetUniformLocation", (OpenGl_ShaderUniformLocation (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *) const) &OpenGl_ShaderProgram::GetUniformLocation, "Returns location of the specific uniform variable.", py::arg("theCtx"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("GetAttributeLocation", (GLint (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *) const) &OpenGl_ShaderProgram::GetAttributeLocation, "Returns index of the generic vertex attribute by variable name.", py::arg("theCtx"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("GetStateLocation", (const OpenGl_ShaderUniformLocation & (OpenGl_ShaderProgram::*)(OpenGl_StateVariable) const) &OpenGl_ShaderProgram::GetStateLocation, "Returns location of the OCCT state uniform variable.", py::arg("theVariable"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetUniform, "None", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the float uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetUniform, "Returns the value of the float uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the integer vertex attribute.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4i &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the integer vertex attribute.", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the float vertex attribute.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("GetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, OpenGl_Vec4 &) const) &OpenGl_ShaderProgram::GetAttribute, "Returns the float vertex attribute.", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttributeName", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const GLchar *)) &OpenGl_ShaderProgram::SetAttributeName, "Wrapper for glBindAttribLocation()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theName"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLfloat)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib1f()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLfloat)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib1f()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib2fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib2fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib3fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib3fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib4fv()", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetAttribute", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetAttribute, "Wrapper for glVertexAttrib4fv()", py::arg("theCtx"), py::arg("theIndex"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLint)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLint)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 2D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 2D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 3D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 3D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 4D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4i &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform 4D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2u &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the unsigned integer uniform 2D vector (uvec2).", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2u &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the unsigned integer uniform 2D vector (uvec2).", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const GLsizei, const OpenGl_Vec2u *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the uvec2 uniform array", py::arg("theCtx"), py::arg("theName"), py::arg("theCount"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const GLsizei, const OpenGl_Vec2u *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the uvec2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, GLfloat)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLfloat)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 2D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec2 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 2D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 3D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec3 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 3D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4D vector.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Vec4 &)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4D vector.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const GLchar * a1, const OpenGl_Mat4 & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Mat4 &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, GLint a1, const OpenGl_Mat4 & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Mat4 &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const GLchar * a1, const OpenGl_Matrix & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const OpenGl_Matrix &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theName"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, GLint a1, const OpenGl_Matrix & a2) -> Standard_Boolean { return self.SetUniform(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const OpenGl_Matrix &, GLboolean)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform 4x4 matrix.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theValue"), py::arg("theTranspose"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const Standard_ShortReal *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec2 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec3 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float3 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec4 *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the float4 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const Standard_Integer *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the integer uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec2i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int2 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec3i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int3 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetUniform", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, GLuint, const OpenGl_Vec4i *)) &OpenGl_ShaderProgram::SetUniform, "Specifies the value of the int4 uniform array", py::arg("theCtx"), py::arg("theLocation"), py::arg("theCount"), py::arg("theData"));
cls_OpenGl_ShaderProgram.def("SetSampler", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const GLchar *, const Graphic3d_TextureUnit)) &OpenGl_ShaderProgram::SetSampler, "Specifies the value of the sampler uniform variable.", py::arg("theCtx"), py::arg("theName"), py::arg("theTextureUnit"));
cls_OpenGl_ShaderProgram.def("SetSampler", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, GLint, const Graphic3d_TextureUnit)) &OpenGl_ShaderProgram::SetSampler, "Specifies the value of the sampler uniform variable.", py::arg("theCtx"), py::arg("theLocation"), py::arg("theTextureUnit"));
cls_OpenGl_ShaderProgram.def("UpdateDebugDump", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0) -> Standard_Boolean { return self.UpdateDebugDump(a0); });
cls_OpenGl_ShaderProgram.def("UpdateDebugDump", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const TCollection_AsciiString & a1) -> Standard_Boolean { return self.UpdateDebugDump(a0, a1); });
cls_OpenGl_ShaderProgram.def("UpdateDebugDump", [](OpenGl_ShaderProgram &self, const opencascade::handle<OpenGl_Context> & a0, const TCollection_AsciiString & a1, Standard_Boolean a2) -> Standard_Boolean { return self.UpdateDebugDump(a0, a1, a2); });
cls_OpenGl_ShaderProgram.def("UpdateDebugDump", (Standard_Boolean (OpenGl_ShaderProgram::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_AsciiString &, Standard_Boolean, Standard_Boolean)) &OpenGl_ShaderProgram::UpdateDebugDump, "Update the shader program from external files (per shader stage) in the following way: 1) If external file does not exist, then it will be created (current source code will be dumped, no recompilation) and FALSE will be returned. 2) If external file exists and it has the same timestamp as myDumpDate, nothing will be done and FALSE will be returned. 3) If external file exists and it has newer timestamp than myDumpDate, shader will be recompiled and relinked and TRUE will be returned.", py::arg("theCtx"), py::arg("theFolder"), py::arg("theToBeautify"), py::arg("theToReset"));
*/

// CLASS: OPENGL_VERTEXBUFFER
py::class_<OpenGl_VertexBuffer, opencascade::handle<OpenGl_VertexBuffer>, OpenGl_Resource> cls_OpenGl_VertexBuffer(mod, "OpenGl_VertexBuffer", "Vertex Buffer Object - is a general storage object for vertex attributes (position, normal, color). Notice that you should use OpenGl_IndexBuffer specialization for array of indices.");

// Constructors
cls_OpenGl_VertexBuffer.def(py::init<>());

// Methods
cls_OpenGl_VertexBuffer.def("GetTarget", (GLenum (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetTarget, "None");
cls_OpenGl_VertexBuffer.def("IsVirtual", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::IsVirtual, "Return TRUE if this is a virtual (for backward compatibility) VBO object.");
cls_OpenGl_VertexBuffer.def("IsValid", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::IsValid, "Returns true if current object was initialized");
cls_OpenGl_VertexBuffer.def("GetComponentsNb", (GLuint (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetComponentsNb, "Returns the number of components per generic vertex attribute.");
cls_OpenGl_VertexBuffer.def("GetElemsNb", (GLsizei (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetElemsNb, "Returns number of vertex attributes / number of vertices specified within ::Init()");
cls_OpenGl_VertexBuffer.def("SetElemsNb", (void (OpenGl_VertexBuffer::*)(GLsizei)) &OpenGl_VertexBuffer::SetElemsNb, "Overrides the number of vertex attributes / number of vertexes. It is up to user specifying this number correct (e.g. below initial value)!", py::arg("theNbElems"));
cls_OpenGl_VertexBuffer.def("GetDataType", (GLenum (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetDataType, "Returns data type of each component in the array.");
cls_OpenGl_VertexBuffer.def("GetDataOffset", (GLubyte * (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::GetDataOffset, "Returns offset to data, NULL by default");
cls_OpenGl_VertexBuffer.def("Create", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_VertexBuffer::Create, "Creates VBO name (id) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Release", (void (OpenGl_VertexBuffer::*)(OpenGl_Context *)) &OpenGl_VertexBuffer::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Bind", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::Bind, "Bind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Unbind", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::Unbind, "Unbind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLfloat *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLuint *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLushort *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("Init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLubyte *)) &OpenGl_VertexBuffer::Init, "Notice that VBO will be unbound after this call.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLfloat *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLuint *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLushort *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("SubData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLubyte *)) &OpenGl_VertexBuffer::SubData, "Notice that VBO will be unbound after this call. Function replaces portion of data within this VBO using glBufferSubData(). The VBO should be initialized before call.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_VertexBuffer.def("BindVertexAttrib", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint) const) &OpenGl_VertexBuffer::BindVertexAttrib, "Bind this VBO to active GLSL program.", py::arg("theGlCtx"), py::arg("theAttribLoc"));
cls_OpenGl_VertexBuffer.def("UnbindVertexAttrib", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint) const) &OpenGl_VertexBuffer::UnbindVertexAttrib, "Unbind any VBO from active GLSL program.", py::arg("theGlCtx"), py::arg("theAttribLoc"));
cls_OpenGl_VertexBuffer.def("BindAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute) const) &OpenGl_VertexBuffer::BindAttribute, "Bind this VBO and enable specified attribute in OpenGl_Context::ActiveProgram() or FFP.", py::arg("theCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("UnbindAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute) const) &OpenGl_VertexBuffer::UnbindAttribute, "Unbind this VBO and disable specified attribute in OpenGl_Context::ActiveProgram() or FFP.", py::arg("theCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("EstimatedDataSize", (Standard_Size (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_VertexBuffer.def_static("sizeOfGlType_", (size_t (*)(const GLenum)) &OpenGl_VertexBuffer::sizeOfGlType, "Returns size of specified GL type", py::arg("theType"));
cls_OpenGl_VertexBuffer.def("init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum, const GLsizei)) &OpenGl_VertexBuffer::init, "Initialize buffer with new data.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"), py::arg("theStride"));
cls_OpenGl_VertexBuffer.def("init", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBuffer::init, "Initialize buffer with new data.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBuffer.def("subData", (bool (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBuffer::subData, "Update part of the buffer with new data.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBuffer.def_static("bindAttribute_", (void (*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute, const GLint, const GLenum, const GLsizei, const GLvoid *)) &OpenGl_VertexBuffer::bindAttribute, "Setup array pointer - either for active GLSL program OpenGl_Context::ActiveProgram() or for FFP using bindFixed() when no program bound.", py::arg("theGlCtx"), py::arg("theMode"), py::arg("theNbComp"), py::arg("theDataType"), py::arg("theStride"), py::arg("theOffset"));
cls_OpenGl_VertexBuffer.def_static("unbindAttribute_", (void (*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfAttribute)) &OpenGl_VertexBuffer::unbindAttribute, "Disable GLSL array pointer - either for active GLSL program OpenGl_Context::ActiveProgram() or for FFP using unbindFixed() when no program bound.", py::arg("theGlCtx"), py::arg("theMode"));
cls_OpenGl_VertexBuffer.def("HasColorAttribute", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::HasColorAttribute, "Returns true if buffer contains per-vertex color attribute");
cls_OpenGl_VertexBuffer.def("HasNormalAttribute", (bool (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::HasNormalAttribute, "Returns true if buffer contains per-vertex normal attribute");
cls_OpenGl_VertexBuffer.def("BindAllAttributes", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::BindAllAttributes, "Bind all vertex attributes to active program OpenGl_Context::ActiveProgram() or for FFP. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("BindPositionAttribute", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::BindPositionAttribute, "Bind vertex position attribute only. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def("UnbindAllAttributes", (void (OpenGl_VertexBuffer::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBuffer::UnbindAllAttributes, "Unbind all vertex attributes. Default implementation does nothing.", py::arg("theGlCtx"));
cls_OpenGl_VertexBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_VertexBuffer::get_type_name, "None");
cls_OpenGl_VertexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_VertexBuffer::get_type_descriptor, "None");
cls_OpenGl_VertexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_VertexBuffer::*)() const) &OpenGl_VertexBuffer::DynamicType, "None");

// CLASS: OPENGL_INDEXBUFFER
py::class_<OpenGl_IndexBuffer, opencascade::handle<OpenGl_IndexBuffer>, OpenGl_VertexBuffer> cls_OpenGl_IndexBuffer(mod, "OpenGl_IndexBuffer", "Index buffer is just a VBO with special target (GL_ELEMENT_ARRAY_BUFFER).");

// Constructors
cls_OpenGl_IndexBuffer.def(py::init<>());

// Methods
cls_OpenGl_IndexBuffer.def("GetTarget", (GLenum (OpenGl_IndexBuffer::*)() const) &OpenGl_IndexBuffer::GetTarget, "None");
cls_OpenGl_IndexBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_IndexBuffer::get_type_name, "None");
cls_OpenGl_IndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_IndexBuffer::get_type_descriptor, "None");
cls_OpenGl_IndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_IndexBuffer::*)() const) &OpenGl_IndexBuffer::DynamicType, "None");

// CLASS: OPENGL_PRIMITIVEARRAY
py::class_<OpenGl_PrimitiveArray, OpenGl_Element> cls_OpenGl_PrimitiveArray(mod, "OpenGl_PrimitiveArray", "Class for rendering of arbitrary primitive array.");

// Constructors
cls_OpenGl_PrimitiveArray.def(py::init<const OpenGl_GraphicDriver *>(), py::arg("theDriver"));
cls_OpenGl_PrimitiveArray.def(py::init<const OpenGl_GraphicDriver *, const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &>(), py::arg("theDriver"), py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"));

// Methods
cls_OpenGl_PrimitiveArray.def("Render", (void (OpenGl_PrimitiveArray::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_PrimitiveArray::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_PrimitiveArray.def("Release", (void (OpenGl_PrimitiveArray::*)(OpenGl_Context *)) &OpenGl_PrimitiveArray::Release, "Release OpenGL resources (VBOs)", py::arg("theContext"));
cls_OpenGl_PrimitiveArray.def("IsInitialized", (Standard_Boolean (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IsInitialized, "Return true if VBOs initialization has been performed. VBO initialization is performed during first Render() call. Notice that this flag does not indicate VBOs validity.");
cls_OpenGl_PrimitiveArray.def("Invalidate", (void (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Invalidate, "Invalidate VBO content without destruction.");
cls_OpenGl_PrimitiveArray.def("DrawMode", (GLint (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::DrawMode, "Returns primitive type (GL_LINES, GL_TRIANGLES and others)");
cls_OpenGl_PrimitiveArray.def("IsFillDrawMode", (Standard_Boolean (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IsFillDrawMode, "Return TRUE if primitive type generates shaded triangulation.");
cls_OpenGl_PrimitiveArray.def("Indices", (const opencascade::handle<Graphic3d_IndexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Indices, "Returns indices array");
cls_OpenGl_PrimitiveArray.def("Attributes", (const opencascade::handle<Graphic3d_Buffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Attributes, "Returns attributes array");
cls_OpenGl_PrimitiveArray.def("Bounds", (const opencascade::handle<Graphic3d_BoundBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::Bounds, "Returns bounds array");
cls_OpenGl_PrimitiveArray.def("GetUID", (Standard_Size (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::GetUID, "Returns unique ID of primitive array.");
cls_OpenGl_PrimitiveArray.def("InitBuffers", (void (OpenGl_PrimitiveArray::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &)) &OpenGl_PrimitiveArray::InitBuffers, "Initialize indices, attributes and bounds with new data.", py::arg("theContext"), py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"));
cls_OpenGl_PrimitiveArray.def("IndexVbo", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::IndexVbo, "Returns index VBO.");
cls_OpenGl_PrimitiveArray.def("AttributesVbo", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_PrimitiveArray::*)() const) &OpenGl_PrimitiveArray::AttributesVbo, "Returns attributes VBO.");
// cls_OpenGl_PrimitiveArray.def_static("operator new_", (void * (*)(size_t)) &OpenGl_PrimitiveArray::operator new, "None", py::arg("theSize"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete_", (void (*)(void *)) &OpenGl_PrimitiveArray::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_PrimitiveArray::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_PrimitiveArray::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_PrimitiveArray::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_PrimitiveArray.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_PrimitiveArray::operator delete, "None", py::arg(""), py::arg(""));

// Enums
cls_OpenGl_PrimitiveArray.attr("DRAW_MODE_NONE") = py::cast(int(OpenGl_PrimitiveArray::DRAW_MODE_NONE));

// CLASS: OPENGL_ELEMENTNODE
py::class_<OpenGl_ElementNode> cls_OpenGl_ElementNode(mod, "OpenGl_ElementNode", "None");

// Constructors
cls_OpenGl_ElementNode.def(py::init<>());

// Fields
cls_OpenGl_ElementNode.def_readwrite("elem", &OpenGl_ElementNode::elem, "None");
cls_OpenGl_ElementNode.def_readwrite("next", &OpenGl_ElementNode::next, "None");

// Methods
// cls_OpenGl_ElementNode.def_static("operator new_", (void * (*)(size_t)) &OpenGl_ElementNode::operator new, "None", py::arg("theSize"));
// cls_OpenGl_ElementNode.def_static("operator delete_", (void (*)(void *)) &OpenGl_ElementNode::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_ElementNode::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_ElementNode.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_ElementNode::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_ElementNode::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_ElementNode.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_ElementNode::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_GROUP
py::class_<OpenGl_Group, opencascade::handle<OpenGl_Group>, Graphic3d_Group> cls_OpenGl_Group(mod, "OpenGl_Group", "Implementation of low-level graphic group.");

// Constructors
cls_OpenGl_Group.def(py::init<const opencascade::handle<Graphic3d_Structure> &>(), py::arg("theStruct"));

// Methods
cls_OpenGl_Group.def("Clear", (void (OpenGl_Group::*)(const Standard_Boolean)) &OpenGl_Group::Clear, "None", py::arg("theToUpdateStructureMgr"));
cls_OpenGl_Group.def("Aspects", (opencascade::handle<Graphic3d_Aspects> (OpenGl_Group::*)() const) &OpenGl_Group::Aspects, "Return line aspect.");
cls_OpenGl_Group.def("SetGroupPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_Group::SetGroupPrimitivesAspect, "Update aspect.", py::arg("theAspect"));
cls_OpenGl_Group.def("SetPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_Group::SetPrimitivesAspect, "Append aspect as an element.", py::arg("theAspect"));
cls_OpenGl_Group.def("SynchronizeAspects", (void (OpenGl_Group::*)()) &OpenGl_Group::SynchronizeAspects, "Update presentation aspects after their modification.");
cls_OpenGl_Group.def("ReplaceAspects", (void (OpenGl_Group::*)(const Graphic3d_MapOfAspectsToAspects &)) &OpenGl_Group::ReplaceAspects, "Replace aspects specified in the replacement map.", py::arg("theMap"));
cls_OpenGl_Group.def("AddPrimitiveArray", (void (OpenGl_Group::*)(const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &, const Standard_Boolean)) &OpenGl_Group::AddPrimitiveArray, "Add primitive array element", py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"), py::arg("theToEvalMinMax"));
cls_OpenGl_Group.def("AddText", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_Text> &, const Standard_Boolean)) &OpenGl_Group::AddText, "Adds a text for display", py::arg("theTextParams"), py::arg("theToEvalMinMax"));
cls_OpenGl_Group.def("SetFlippingOptions", (void (OpenGl_Group::*)(const Standard_Boolean, const gp_Ax2 &)) &OpenGl_Group::SetFlippingOptions, "Add flipping element", py::arg("theIsEnabled"), py::arg("theRefPlane"));
cls_OpenGl_Group.def("SetStencilTestOptions", (void (OpenGl_Group::*)(const Standard_Boolean)) &OpenGl_Group::SetStencilTestOptions, "Add stencil test element", py::arg("theIsEnabled"));
// cls_OpenGl_Group.def("GlStruct", (OpenGl_Structure * (OpenGl_Group::*)() const) &OpenGl_Group::GlStruct, "None");
cls_OpenGl_Group.def("AddElement", (void (OpenGl_Group::*)(OpenGl_Element *)) &OpenGl_Group::AddElement, "None", py::arg("theElem"));
cls_OpenGl_Group.def("Render", (void (OpenGl_Group::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Group::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Group.def("Release", (void (OpenGl_Group::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Group::Release, "None", py::arg("theGlCtx"));
cls_OpenGl_Group.def("FirstNode", (const OpenGl_ElementNode * (OpenGl_Group::*)() const) &OpenGl_Group::FirstNode, "Returns first OpenGL element node of the group.");
cls_OpenGl_Group.def("GlAspects", (const OpenGl_Aspects * (OpenGl_Group::*)() const) &OpenGl_Group::GlAspects, "Returns OpenGL aspect.");
cls_OpenGl_Group.def("IsRaytracable", (Standard_Boolean (OpenGl_Group::*)() const) &OpenGl_Group::IsRaytracable, "Is the group ray-tracable (contains ray-tracable elements)?");
cls_OpenGl_Group.def("DumpJson", [](OpenGl_Group &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_OpenGl_Group.def("DumpJson", (void (OpenGl_Group::*)(Standard_OStream &, const Standard_Integer) const) &OpenGl_Group::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_OpenGl_Group.def_static("get_type_name_", (const char * (*)()) &OpenGl_Group::get_type_name, "None");
cls_OpenGl_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Group::get_type_descriptor, "None");
cls_OpenGl_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Group::*)() const) &OpenGl_Group::DynamicType, "None");

// CLASS: OPENGL_CAPPINGALGO
py::class_<OpenGl_CappingAlgo> cls_OpenGl_CappingAlgo(mod, "OpenGl_CappingAlgo", "Capping surface rendering algorithm.");

// Constructors
cls_OpenGl_CappingAlgo.def(py::init<>());

// Methods
cls_OpenGl_CappingAlgo.def_static("RenderCapping_", (void (*)(const opencascade::handle<OpenGl_Workspace> &, const OpenGl_Structure &)) &OpenGl_CappingAlgo::RenderCapping, "Draw capping surfaces by OpenGl for the clipping planes enabled in current context state. Depth buffer must be generated for the passed groups.", py::arg("theWorkspace"), py::arg("theStructure"));

// CLASS: OPENGL_SAMPLER
py::class_<OpenGl_Sampler, opencascade::handle<OpenGl_Sampler>, OpenGl_Resource> cls_OpenGl_Sampler(mod, "OpenGl_Sampler", "Class implements OpenGL sampler object resource that stores the sampling parameters for a texture access.");

// Constructors
cls_OpenGl_Sampler.def(py::init<const opencascade::handle<Graphic3d_TextureParams> &>(), py::arg("theParams"));

// Methods
cls_OpenGl_Sampler.def_static("get_type_name_", (const char * (*)()) &OpenGl_Sampler::get_type_name, "None");
cls_OpenGl_Sampler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Sampler::get_type_descriptor, "None");
cls_OpenGl_Sampler.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Sampler::*)() const) &OpenGl_Sampler::DynamicType, "None");
cls_OpenGl_Sampler.def("Release", (void (OpenGl_Sampler::*)(OpenGl_Context *)) &OpenGl_Sampler::Release, "Destroys object - will release GPU memory if any.", py::arg("theContext"));
cls_OpenGl_Sampler.def("EstimatedDataSize", (Standard_Size (OpenGl_Sampler::*)() const) &OpenGl_Sampler::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_Sampler.def("Create", (Standard_Boolean (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Create, "Creates an uninitialized sampler object.", py::arg("theContext"));
cls_OpenGl_Sampler.def("Init", (Standard_Boolean (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_Texture &)) &OpenGl_Sampler::Init, "Creates and initializes sampler object. Existing object will be reused if possible, however if existing Sampler Object has Immutable flag and texture parameters should be re-initialized, then Sampler Object will be recreated.", py::arg("theContext"), py::arg("theTexture"));
cls_OpenGl_Sampler.def("IsValid", (Standard_Boolean (OpenGl_Sampler::*)() const) &OpenGl_Sampler::IsValid, "Returns true if current object was initialized.");
cls_OpenGl_Sampler.def("Bind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Bind, "Binds sampler object to texture unit specified in parameters.", py::arg("theCtx"));
cls_OpenGl_Sampler.def("Unbind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Sampler::Unbind, "Unbinds sampler object from texture unit specified in parameters.", py::arg("theCtx"));
cls_OpenGl_Sampler.def("Bind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit)) &OpenGl_Sampler::Bind, "Binds sampler object to the given texture unit.", py::arg("theCtx"), py::arg("theUnit"));
cls_OpenGl_Sampler.def("Unbind", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit)) &OpenGl_Sampler::Unbind, "Unbinds sampler object from the given texture unit.", py::arg("theCtx"), py::arg("theUnit"));
cls_OpenGl_Sampler.def("SetParameter", (void (OpenGl_Sampler::*)(const opencascade::handle<OpenGl_Context> &, GLenum, GLenum, GLint)) &OpenGl_Sampler::SetParameter, "Sets specific sampler parameter.", py::arg("theCtx"), py::arg("theTarget"), py::arg("theParam"), py::arg("theValue"));
cls_OpenGl_Sampler.def("SamplerID", (GLuint (OpenGl_Sampler::*)() const) &OpenGl_Sampler::SamplerID, "Returns OpenGL sampler ID.");
cls_OpenGl_Sampler.def("IsImmutable", (bool (OpenGl_Sampler::*)() const) &OpenGl_Sampler::IsImmutable, "Return immutable flag preventing further modifications of sampler parameters, FALSE by default. Immutable flag might be set when Sampler Object is used within Bindless Texture.");
cls_OpenGl_Sampler.def("SetImmutable", (void (OpenGl_Sampler::*)()) &OpenGl_Sampler::SetImmutable, "Setup immutable flag. It is not possible unsetting this flag without Sampler destruction.");
cls_OpenGl_Sampler.def("Parameters", (const opencascade::handle<Graphic3d_TextureParams> & (OpenGl_Sampler::*)()) &OpenGl_Sampler::Parameters, "Returns texture parameters.");
cls_OpenGl_Sampler.def("SetParameters", (void (OpenGl_Sampler::*)(const opencascade::handle<Graphic3d_TextureParams> &)) &OpenGl_Sampler::SetParameters, "Sets texture parameters.", py::arg("theParams"));
cls_OpenGl_Sampler.def("ToUpdateParameters", (bool (OpenGl_Sampler::*)() const) &OpenGl_Sampler::ToUpdateParameters, "Returns texture parameters initialization state.");

// CLASS: OPENGL_TEXTUREFORMAT
py::class_<OpenGl_TextureFormat> cls_OpenGl_TextureFormat(mod, "OpenGl_TextureFormat", "Stores parameters of OpenGL texture format.");

// Methods
cls_OpenGl_TextureFormat.def("Format", (GLenum (OpenGl_TextureFormat::*)() const) &OpenGl_TextureFormat::Format, "Returns OpenGL format of the pixel data.");
cls_OpenGl_TextureFormat.def("Internal", (GLint (OpenGl_TextureFormat::*)() const) &OpenGl_TextureFormat::Internal, "Returns OpenGL internal format of the pixel data.");
cls_OpenGl_TextureFormat.def("DataType", (GLint (OpenGl_TextureFormat::*)() const) &OpenGl_TextureFormat::DataType, "Returns OpenGL data type of the pixel data.");

// CLASS: OPENGL_TEXTURE
py::class_<OpenGl_Texture, opencascade::handle<OpenGl_Texture>, OpenGl_NamedResource> cls_OpenGl_Texture(mod, "OpenGl_Texture", "Texture resource.");

// Constructors
cls_OpenGl_Texture.def(py::init<>());
cls_OpenGl_Texture.def(py::init<const TCollection_AsciiString &>(), py::arg("theResourceId"));
cls_OpenGl_Texture.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Graphic3d_TextureParams> &>(), py::arg("theResourceId"), py::arg("theParams"));

// Methods
cls_OpenGl_Texture.def_static("get_type_name_", (const char * (*)()) &OpenGl_Texture::get_type_name, "None");
cls_OpenGl_Texture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Texture::get_type_descriptor, "None");
cls_OpenGl_Texture.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Texture::*)() const) &OpenGl_Texture::DynamicType, "None");
cls_OpenGl_Texture.def_static("PixelSizeOfPixelFormat_", (Standard_Size (*)(Standard_Integer)) &OpenGl_Texture::PixelSizeOfPixelFormat, "Return pixel size of pixel format in bytes. Note that this method considers that OpenGL natively supports this pixel format, which might be not the case - in the latter case, actual pixel size might differ!", py::arg("theInternalFormat"));
cls_OpenGl_Texture.def("IsValid", (bool (OpenGl_Texture::*)() const) &OpenGl_Texture::IsValid, "Returns true if current object was initialized");
cls_OpenGl_Texture.def("GetTarget", (GLenum (OpenGl_Texture::*)() const) &OpenGl_Texture::GetTarget, "Returns target to which the texture is bound (GL_TEXTURE_1D, GL_TEXTURE_2D)");
cls_OpenGl_Texture.def("SizeX", (GLsizei (OpenGl_Texture::*)() const) &OpenGl_Texture::SizeX, "Returns texture width (0 LOD)");
cls_OpenGl_Texture.def("SizeY", (GLsizei (OpenGl_Texture::*)() const) &OpenGl_Texture::SizeY, "Returns texture height (0 LOD)");
cls_OpenGl_Texture.def("TextureId", (GLuint (OpenGl_Texture::*)() const) &OpenGl_Texture::TextureId, "Returns texture ID");
cls_OpenGl_Texture.def("GetFormat", (GLenum (OpenGl_Texture::*)() const) &OpenGl_Texture::GetFormat, "Returns texture format (not sized)");
cls_OpenGl_Texture.def("SizedFormat", (GLint (OpenGl_Texture::*)() const) &OpenGl_Texture::SizedFormat, "Returns texture format (sized)");
cls_OpenGl_Texture.def("IsAlpha", (bool (OpenGl_Texture::*)() const) &OpenGl_Texture::IsAlpha, "Return true for GL_RED and GL_ALPHA formats.");
cls_OpenGl_Texture.def("SetAlpha", (void (OpenGl_Texture::*)(const bool)) &OpenGl_Texture::SetAlpha, "Setup to interprete the format as Alpha by Shader Manager (should be GL_ALPHA within compatible context or GL_RED otherwise).", py::arg("theValue"));
cls_OpenGl_Texture.def("Create", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Texture::Create, "Creates Texture id if not yet generated. Data should be initialized by another method.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Release", (void (OpenGl_Texture::*)(OpenGl_Context *)) &OpenGl_Texture::Release, "Destroy object - will release GPU memory if any.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Sampler", (const opencascade::handle<OpenGl_Sampler> & (OpenGl_Texture::*)() const) &OpenGl_Texture::Sampler, "Return texture sampler.");
cls_OpenGl_Texture.def("SetSampler", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Sampler> &)) &OpenGl_Texture::SetSampler, "Set texture sampler.", py::arg("theSampler"));
cls_OpenGl_Texture.def("InitSamplerObject", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Texture::InitSamplerObject, "Initialize the Sampler Object (as OpenGL object).", py::arg("theCtx"));
cls_OpenGl_Texture.def("Bind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Texture::Bind, "Bind this Texture to the unit specified in sampler parameters. Also binds Sampler Object if it is allocated.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Unbind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_Texture::Unbind, "Unbind texture from the unit specified in sampler parameters. Also unbinds Sampler Object if it is allocated.", py::arg("theCtx"));
cls_OpenGl_Texture.def("Bind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_Texture::Bind, "Bind this Texture to specified unit. Also binds Sampler Object if it is allocated.", py::arg("theCtx"), py::arg("theTextureUnit"));
cls_OpenGl_Texture.def("Unbind", (void (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_Texture::Unbind, "Unbind texture from specified unit. Also unbinds Sampler Object if it is allocated.", py::arg("theCtx"), py::arg("theTextureUnit"));
cls_OpenGl_Texture.def("Revision", (Standard_Size (OpenGl_Texture::*)() const) &OpenGl_Texture::Revision, "Revision of associated data source.");
cls_OpenGl_Texture.def("SetRevision", (void (OpenGl_Texture::*)(const Standard_Size)) &OpenGl_Texture::SetRevision, "Set revision of associated data source.", py::arg("theRevision"));
cls_OpenGl_Texture.def("Init", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Image_PixMap &, const Graphic3d_TypeOfTexture)) &OpenGl_Texture::Init, "Notice that texture will be unbound after this call.", py::arg("theCtx"), py::arg("theImage"), py::arg("theType"));
cls_OpenGl_Texture.def("Init", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const GLint a1, const GLenum a2, const GLenum a3, const GLsizei a4, const GLsizei a5, const Graphic3d_TypeOfTexture a6) -> bool { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_OpenGl_Texture.def("Init", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLint, const GLenum, const GLenum, const GLsizei, const GLsizei, const Graphic3d_TypeOfTexture, const Image_PixMap *)) &OpenGl_Texture::Init, "Initialize the texture with specified format, size and texture type. If theImage is empty the texture data will contain trash. Notice that texture will be unbound after this call.", py::arg("theCtx"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theType"), py::arg("theImage"));
cls_OpenGl_Texture.def("Init", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_TextureMap> &)) &OpenGl_Texture::Init, "Initialize the texture with Graphic3d_TextureMap. It is an universal way to initialize. Sitable initialization method will be chosen.", py::arg("theCtx"), py::arg("theTextureMap"));
cls_OpenGl_Texture.def("Init2DMultisample", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLint, const GLsizei, const GLsizei)) &OpenGl_Texture::Init2DMultisample, "Initialize the 2D multisampling texture using glTexImage2DMultisample().", py::arg("theCtx"), py::arg("theNbSamples"), py::arg("theTextFormat"), py::arg("theSizeX"), py::arg("theSizeY"));
cls_OpenGl_Texture.def("InitRectangle", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Integer, const Standard_Integer, const OpenGl_TextureFormat &)) &OpenGl_Texture::InitRectangle, "Allocates texture rectangle with specified format and size.", py::arg("theCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theFormat"));
cls_OpenGl_Texture.def("Init3D", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const GLint, const GLenum, const GLenum, const Standard_Integer, const Standard_Integer, const Standard_Integer, const void *)) &OpenGl_Texture::Init3D, "Initializes 3D texture rectangle with specified format and size.", py::arg("theCtx"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theSizeZ"), py::arg("thePixels"));
cls_OpenGl_Texture.def("InitCubeMap", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<Graphic3d_CubeMap> & a1) -> bool { return self.InitCubeMap(a0, a1); });
cls_OpenGl_Texture.def("InitCubeMap", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<Graphic3d_CubeMap> & a1, Standard_Size a2) -> bool { return self.InitCubeMap(a0, a1, a2); });
cls_OpenGl_Texture.def("InitCubeMap", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<Graphic3d_CubeMap> & a1, Standard_Size a2, Image_Format a3) -> bool { return self.InitCubeMap(a0, a1, a2, a3); });
cls_OpenGl_Texture.def("InitCubeMap", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_CubeMap> &, Standard_Size, Image_Format, Standard_Boolean)) &OpenGl_Texture::InitCubeMap, "Initializes 6 sides of cubemap. If theCubeMap is not NULL then size and format will be taken from it and corresponding arguments will be ignored. Otherwise this parametres will be taken from arguments. theToGenMipmap allows to generate mipmaped cubemap.", py::arg("theCtx"), py::arg("theCubeMap"), py::arg("theSize"), py::arg("theFormat"), py::arg("theToGenMipmap"));
cls_OpenGl_Texture.def("InitCubeMap", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<Graphic3d_CubeMap> & a1, Standard_Boolean a2) -> bool { return self.InitCubeMap(a0, a1, a2); });
cls_OpenGl_Texture.def("InitCubeMap", [](OpenGl_Texture &self, const opencascade::handle<OpenGl_Context> & a0, const opencascade::handle<Graphic3d_CubeMap> & a1, Standard_Boolean a2, Standard_Size a3) -> bool { return self.InitCubeMap(a0, a1, a2, a3); });
cls_OpenGl_Texture.def("InitCubeMap", (bool (OpenGl_Texture::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_CubeMap> &, Standard_Boolean, Standard_Size, Image_Format)) &OpenGl_Texture::InitCubeMap, "The same InitCubeMap but there is another order of arguments.", py::arg("theCtx"), py::arg("theCubeMap"), py::arg("theToGenMipmap"), py::arg("theSize"), py::arg("theFormat"));
cls_OpenGl_Texture.def("HasMipmaps", (Standard_Boolean (OpenGl_Texture::*)() const) &OpenGl_Texture::HasMipmaps, "Returns true if texture was generated within mipmaps");
cls_OpenGl_Texture.def_static("GetDataFormat_", (bool (*)(const opencascade::handle<OpenGl_Context> &, const Image_Format, GLint &, GLenum &, GLenum &)) &OpenGl_Texture::GetDataFormat, "Return texture type and format by Image_Format.", py::arg("theCtx"), py::arg("theFromat"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"));
cls_OpenGl_Texture.def_static("GetDataFormat_", (bool (*)(const opencascade::handle<OpenGl_Context> &, const Image_PixMap &, GLint &, GLenum &, GLenum &)) &OpenGl_Texture::GetDataFormat, "Return texture type and format by Image_PixMap data format.", py::arg("theCtx"), py::arg("theData"), py::arg("theTextFormat"), py::arg("thePixelFormat"), py::arg("theDataType"));
cls_OpenGl_Texture.def("EstimatedDataSize", (Standard_Size (OpenGl_Texture::*)() const) &OpenGl_Texture::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_Texture.def("IsPointSprite", (bool (OpenGl_Texture::*)() const) &OpenGl_Texture::IsPointSprite, "Returns TRUE for point sprite texture.");

// TYPEDEF: OPENGL_COLORFORMATS
bind_NCollection_Vector<int>(mod, "OpenGl_ColorFormats", py::module_local(false));

// CLASS: OPENGL_FRAMEBUFFER
py::class_<OpenGl_FrameBuffer, opencascade::handle<OpenGl_FrameBuffer>, OpenGl_Resource> cls_OpenGl_FrameBuffer(mod, "OpenGl_FrameBuffer", "Class implements FrameBuffer Object (FBO) resource intended for off-screen rendering.");

// Constructors
cls_OpenGl_FrameBuffer.def(py::init<>());

// Methods
cls_OpenGl_FrameBuffer.def_static("BufferDump_", (Standard_Boolean (*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_FrameBuffer> &, Image_PixMap &, Graphic3d_BufferType)) &OpenGl_FrameBuffer::BufferDump, "Dump content into image.", py::arg("theGlCtx"), py::arg("theFbo"), py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_FrameBuffer.def("Release", (void (OpenGl_FrameBuffer::*)(OpenGl_Context *)) &OpenGl_FrameBuffer::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("NbSamples", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::NbSamples, "Number of multisampling samples.");
cls_OpenGl_FrameBuffer.def("NbColorBuffers", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::NbColorBuffers, "Number of color buffers.");
cls_OpenGl_FrameBuffer.def("HasColor", (bool (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::HasColor, "Return true if FBO has been created with color attachment.");
cls_OpenGl_FrameBuffer.def("HasDepth", (bool (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::HasDepth, "Return true if FBO has been created with depth attachment.");
cls_OpenGl_FrameBuffer.def("GetSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetSizeX, "Textures width.");
cls_OpenGl_FrameBuffer.def("GetSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetSizeY, "Textures height.");
cls_OpenGl_FrameBuffer.def("GetVPSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetVPSizeX, "Viewport width.");
cls_OpenGl_FrameBuffer.def("GetVPSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetVPSizeY, "Viewport height.");
cls_OpenGl_FrameBuffer.def("GetInitVPSizeX", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetInitVPSizeX, "Viewport width.");
cls_OpenGl_FrameBuffer.def("GetInitVPSizeY", (GLsizei (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::GetInitVPSizeY, "Viewport height.");
cls_OpenGl_FrameBuffer.def("IsValid", (Standard_Boolean (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::IsValid, "Returns true if current object was initialized");
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const opencascade::handle<OpenGl_Texture> & a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const opencascade::handle<OpenGl_Texture> &, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into single/multiple color buffer and depth textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormats"), py::arg("theDepthStencilTexture"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("Init", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const GLint a4) -> Standard_Boolean { return self.Init(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("Init", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const GLint, const GLsizei)) &OpenGl_FrameBuffer::Init, "Initialize FBO for rendering into single/multiple color buffer and depth textures.", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormats"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.InitLazy(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLsizei)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with specified dimensions.", py::arg("theGlCtx"), py::arg("theViewportSizeX"), py::arg("theViewportSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const OpenGl_ColorFormats & a3, const GLint a4) -> Standard_Boolean { return self.InitLazy(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const OpenGl_ColorFormats &, const GLint, const GLsizei)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with specified dimensions.", py::arg("theGlCtx"), py::arg("theViewportSizeX"), py::arg("theViewportSizeY"), py::arg("theColorFormats"), py::arg("theDepthFormat"), py::arg("theNbSamples"));
cls_OpenGl_FrameBuffer.def("InitLazy", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_FrameBuffer &)) &OpenGl_FrameBuffer::InitLazy, "(Re-)initialize FBO with properties taken from another FBO.", py::arg("theGlCtx"), py::arg("theFbo"));
cls_OpenGl_FrameBuffer.def("InitWithRB", [](OpenGl_FrameBuffer &self, const opencascade::handle<OpenGl_Context> & a0, const GLsizei a1, const GLsizei a2, const GLint a3, const GLint a4) -> Standard_Boolean { return self.InitWithRB(a0, a1, a2, a3, a4); });
cls_OpenGl_FrameBuffer.def("InitWithRB", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const GLint, const GLint, const GLuint)) &OpenGl_FrameBuffer::InitWithRB, "(Re-)initialize FBO with specified dimensions. The Render Buffer Objects will be used for Color, Depth and Stencil attachments (as opposite to textures).", py::arg("theGlCtx"), py::arg("theSizeX"), py::arg("theSizeY"), py::arg("theColorFormat"), py::arg("theDepthFormat"), py::arg("theColorRBufferFromWindow"));
cls_OpenGl_FrameBuffer.def("InitWrapper", (Standard_Boolean (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::InitWrapper, "Initialize class from currently bound FBO. Retrieved OpenGL objects will not be destroyed on Release.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("SetupViewport", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::SetupViewport, "Setup viewport to render into FBO", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("ChangeViewport", (void (OpenGl_FrameBuffer::*)(const GLsizei, const GLsizei)) &OpenGl_FrameBuffer::ChangeViewport, "Override viewport settings", py::arg("theVPSizeX"), py::arg("theVPSizeY"));
cls_OpenGl_FrameBuffer.def("BindBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindBuffer, "Bind frame buffer for drawing and reading (to render into the texture).", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("BindDrawBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindDrawBuffer, "Bind frame buffer for drawing GL_DRAW_FRAMEBUFFER (to render into the texture).", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("BindReadBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::BindReadBuffer, "Bind frame buffer for reading GL_READ_FRAMEBUFFER", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("UnbindBuffer", (void (OpenGl_FrameBuffer::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_FrameBuffer::UnbindBuffer, "Unbind frame buffer.", py::arg("theGlCtx"));
cls_OpenGl_FrameBuffer.def("ColorTexture", [](OpenGl_FrameBuffer &self) -> const opencascade::handle<OpenGl_Texture> & { return self.ColorTexture(); });
cls_OpenGl_FrameBuffer.def("ColorTexture", (const opencascade::handle<OpenGl_Texture> & (OpenGl_FrameBuffer::*)(const GLint) const) &OpenGl_FrameBuffer::ColorTexture, "Returns the color texture for the given color buffer index.", py::arg("theColorBufferIndex"));
cls_OpenGl_FrameBuffer.def("DepthStencilTexture", (const opencascade::handle<OpenGl_Texture> & (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DepthStencilTexture, "Returns the depth-stencil texture.");
cls_OpenGl_FrameBuffer.def("ColorRenderBuffer", (GLuint (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::ColorRenderBuffer, "Returns the color Render Buffer.");
cls_OpenGl_FrameBuffer.def("DepthStencilRenderBuffer", (GLuint (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DepthStencilRenderBuffer, "Returns the depth Render Buffer.");
cls_OpenGl_FrameBuffer.def("EstimatedDataSize", (Standard_Size (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::EstimatedDataSize, "Returns estimated GPU memory usage for holding data without considering overheads and allocation alignment rules.");
cls_OpenGl_FrameBuffer.def_static("get_type_name_", (const char * (*)()) &OpenGl_FrameBuffer::get_type_name, "None");
cls_OpenGl_FrameBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_FrameBuffer::get_type_descriptor, "None");
cls_OpenGl_FrameBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_FrameBuffer::*)() const) &OpenGl_FrameBuffer::DynamicType, "None");

// CLASS: OPENGL_TEXTUREBUFFERARB
py::class_<OpenGl_TextureBufferArb, opencascade::handle<OpenGl_TextureBufferArb>, OpenGl_VertexBuffer> cls_OpenGl_TextureBufferArb(mod, "OpenGl_TextureBufferArb", "Texture Buffer Object. This is a special 1D texture that VBO-style initialized. The main differences from general 1D texture: - no interpolation between field; - greater sizes; - special sampler object in GLSL shader to access data by index.");

// Constructors
cls_OpenGl_TextureBufferArb.def(py::init<>());

// Methods
cls_OpenGl_TextureBufferArb.def_static("get_type_name_", (const char * (*)()) &OpenGl_TextureBufferArb::get_type_name, "None");
cls_OpenGl_TextureBufferArb.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TextureBufferArb::get_type_descriptor, "None");
cls_OpenGl_TextureBufferArb.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::DynamicType, "None");
cls_OpenGl_TextureBufferArb.def("GetTarget", (GLenum (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::GetTarget, "Override VBO target");
cls_OpenGl_TextureBufferArb.def("IsValid", (bool (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::IsValid, "Returns true if TBO is valid. Notice that no any real GL call is performed!");
cls_OpenGl_TextureBufferArb.def("Release", (void (OpenGl_TextureBufferArb::*)(OpenGl_Context *)) &OpenGl_TextureBufferArb::Release, "Destroy object - will release GPU memory if any.", py::arg("theGlCtx"));
cls_OpenGl_TextureBufferArb.def("Create", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_TextureBufferArb::Create, "Creates VBO and Texture names (ids) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLfloat *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLuint *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLushort *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("Init", (bool (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const GLubyte *)) &OpenGl_TextureBufferArb::Init, "Perform TBO initialization with specified data. Existing data will be deleted.", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"));
cls_OpenGl_TextureBufferArb.def("BindTexture", (void (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_TextureBufferArb::BindTexture, "Bind TBO to specified Texture Unit.", py::arg("theGlCtx"), py::arg("theTextureUnit"));
cls_OpenGl_TextureBufferArb.def("UnbindTexture", (void (OpenGl_TextureBufferArb::*)(const opencascade::handle<OpenGl_Context> &, const Graphic3d_TextureUnit) const) &OpenGl_TextureBufferArb::UnbindTexture, "Unbind TBO.", py::arg("theGlCtx"), py::arg("theTextureUnit"));
cls_OpenGl_TextureBufferArb.def("TextureId", (GLuint (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::TextureId, "Returns name of TBO.");
cls_OpenGl_TextureBufferArb.def("TextureFormat", (GLenum (OpenGl_TextureBufferArb::*)() const) &OpenGl_TextureBufferArb::TextureFormat, "Returns internal texture format.");

// CLASS: OPENGL_WINDOW
py::class_<OpenGl_Window, opencascade::handle<OpenGl_Window>, Standard_Transient> cls_OpenGl_Window(mod, "OpenGl_Window", "This class represents low-level wrapper over window with GL context. The window itself should be provided to constructor.");

// Constructors
cls_OpenGl_Window.def(py::init<const opencascade::handle<OpenGl_GraphicDriver> &, const opencascade::handle<Aspect_Window> &, Aspect_RenderingContext, const opencascade::handle<OpenGl_Caps> &, const opencascade::handle<OpenGl_Context> &>(), py::arg("theDriver"), py::arg("thePlatformWindow"), py::arg("theGContext"), py::arg("theCaps"), py::arg("theShareCtx"));

// Methods
cls_OpenGl_Window.def("Resize", (void (OpenGl_Window::*)()) &OpenGl_Window::Resize, "Resizes the window.");
cls_OpenGl_Window.def("PlatformWindow", (opencascade::handle<Aspect_Window> (OpenGl_Window::*)()) &OpenGl_Window::PlatformWindow, "None");
cls_OpenGl_Window.def("Width", (Standard_Integer (OpenGl_Window::*)() const) &OpenGl_Window::Width, "None");
cls_OpenGl_Window.def("Height", (Standard_Integer (OpenGl_Window::*)() const) &OpenGl_Window::Height, "None");
cls_OpenGl_Window.def("GetGlContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_Window::*)() const) &OpenGl_Window::GetGlContext, "None");
cls_OpenGl_Window.def("Init", (void (OpenGl_Window::*)()) &OpenGl_Window::Init, "Activates GL context and setup viewport.");
cls_OpenGl_Window.def("Activate", (Standard_Boolean (OpenGl_Window::*)()) &OpenGl_Window::Activate, "Makes GL context for this window active in current thread");
cls_OpenGl_Window.def("SetSwapInterval", (void (OpenGl_Window::*)()) &OpenGl_Window::SetSwapInterval, "Sets swap interval for this window according to the context's settings.");
cls_OpenGl_Window.def_static("get_type_name_", (const char * (*)()) &OpenGl_Window::get_type_name, "None");
cls_OpenGl_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Window::get_type_descriptor, "None");
cls_OpenGl_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Window::*)() const) &OpenGl_Window::DynamicType, "None");
// cls_OpenGl_Window.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Window::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Window.def_static("operator delete_", (void (*)(void *)) &OpenGl_Window::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Window::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Window.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Window::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Window::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Window.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Window::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_WORKSPACE
/*
py::class_<OpenGl_Workspace, opencascade::handle<OpenGl_Workspace>, Standard_Transient> cls_OpenGl_Workspace(mod, "OpenGl_Workspace", "Rendering workspace. Provides methods to render primitives and maintain GL state.");

// Constructors
cls_OpenGl_Workspace.def(py::init<OpenGl_View *, const opencascade::handle<OpenGl_Window> &>(), py::arg("theView"), py::arg("theWindow"));

// Methods
cls_OpenGl_Workspace.def("Activate", (Standard_Boolean (OpenGl_Workspace::*)()) &OpenGl_Workspace::Activate, "Activate rendering context.");
cls_OpenGl_Workspace.def("View", (OpenGl_View * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::View, "None");
cls_OpenGl_Workspace.def("GetGlContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_Workspace::*)()) &OpenGl_Workspace::GetGlContext, "None");
cls_OpenGl_Workspace.def("FBOCreate", (opencascade::handle<OpenGl_FrameBuffer> (OpenGl_Workspace::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_Workspace::FBOCreate, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_Workspace.def("FBORelease", (void (OpenGl_Workspace::*)(opencascade::handle<OpenGl_FrameBuffer> &)) &OpenGl_Workspace::FBORelease, "None", py::arg("theFbo"));
// cls_OpenGl_Workspace.def("BufferDump", (Standard_Boolean (OpenGl_Workspace::*)(const opencascade::handle<OpenGl_FrameBuffer> &, Image_PixMap &, const Graphic3d_BufferType &)) &OpenGl_Workspace::BufferDump, "None", py::arg("theFbo"), py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_Workspace.def("Width", (Standard_Integer (OpenGl_Workspace::*)() const) &OpenGl_Workspace::Width, "None");
cls_OpenGl_Workspace.def("Height", (Standard_Integer (OpenGl_Workspace::*)() const) &OpenGl_Workspace::Height, "None");
cls_OpenGl_Workspace.def("SetUseZBuffer", (Standard_Boolean (OpenGl_Workspace::*)(const Standard_Boolean)) &OpenGl_Workspace::SetUseZBuffer, "Setup Z-buffer usage flag (without affecting GL state!). Returns previously set flag.", py::arg("theToUse"));
cls_OpenGl_Workspace.def("UseZBuffer", (Standard_Boolean & (OpenGl_Workspace::*)()) &OpenGl_Workspace::UseZBuffer, "Returns true if usage of Z buffer is enabled.");
cls_OpenGl_Workspace.def("UseDepthWrite", (Standard_Boolean & (OpenGl_Workspace::*)()) &OpenGl_Workspace::UseDepthWrite, "Returns true if depth writing is enabled.");
cls_OpenGl_Workspace.def("SetDefaultPolygonOffset", (Graphic3d_PolygonOffset (OpenGl_Workspace::*)(const Graphic3d_PolygonOffset &)) &OpenGl_Workspace::SetDefaultPolygonOffset, "Configure default polygon offset parameters. Return previous settings.", py::arg("theOffset"));
cls_OpenGl_Workspace.def("ToAllowFaceCulling", (bool (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ToAllowFaceCulling, "Return true if active group might activate face culling (e.g. primitives are closed).");
cls_OpenGl_Workspace.def("SetAllowFaceCulling", (bool (OpenGl_Workspace::*)(bool)) &OpenGl_Workspace::SetAllowFaceCulling, "Allow or disallow face culling. This call does NOT affect current state of back face culling; ApplyAspectFace() should be called to update state.", py::arg("theToAllow"));
cls_OpenGl_Workspace.def("ToHighlight", (bool (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ToHighlight, "Return true if following structures should apply highlight color.");
cls_OpenGl_Workspace.def("HighlightStyle", (const opencascade::handle<Graphic3d_PresentationAttributes> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::HighlightStyle, "Return highlight style.");
cls_OpenGl_Workspace.def("SetHighlightStyle", (void (OpenGl_Workspace::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Workspace::SetHighlightStyle, "Set highlight style.", py::arg("theStyle"));
cls_OpenGl_Workspace.def("EdgeColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::EdgeColor, "Return edge color taking into account highlight flag.");
cls_OpenGl_Workspace.def("InteriorColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::InteriorColor, "Return Interior color taking into account highlight flag.");
cls_OpenGl_Workspace.def("TextColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::TextColor, "Return text color taking into account highlight flag.");
cls_OpenGl_Workspace.def("TextSubtitleColor", (const OpenGl_Vec4 & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::TextSubtitleColor, "Return text Subtitle color taking into account highlight flag.");
cls_OpenGl_Workspace.def("Aspects", (const OpenGl_Aspects * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::Aspects, "Currently set aspects (can differ from applied).");
cls_OpenGl_Workspace.def("SetAspects", (const OpenGl_Aspects * (OpenGl_Workspace::*)(const OpenGl_Aspects *)) &OpenGl_Workspace::SetAspects, "Assign new aspects (will be applied within ApplyAspects()).", py::arg("theAspect"));
cls_OpenGl_Workspace.def("ApplyAspects", (const OpenGl_Aspects * (OpenGl_Workspace::*)()) &OpenGl_Workspace::ApplyAspects, "Apply aspects.");
// cls_OpenGl_Workspace.def("ResetAppliedAspect", (void (OpenGl_Workspace::*)()) &OpenGl_Workspace::ResetAppliedAspect, "Clear the applied aspect state to default values.");
cls_OpenGl_Workspace.def("RenderFilter", (Standard_Integer (OpenGl_Workspace::*)() const) &OpenGl_Workspace::RenderFilter, "Get rendering filter.");
cls_OpenGl_Workspace.def("SetRenderFilter", (void (OpenGl_Workspace::*)(Standard_Integer)) &OpenGl_Workspace::SetRenderFilter, "Set filter for restricting rendering of particular elements.", py::arg("theFilter"));
cls_OpenGl_Workspace.def("ShouldRender", (bool (OpenGl_Workspace::*)(const OpenGl_Element *)) &OpenGl_Workspace::ShouldRender, "Checks whether the element can be rendered or not.", py::arg("theElement"));
cls_OpenGl_Workspace.def("NbSkippedTransparentElements", (Standard_Integer (OpenGl_Workspace::*)()) &OpenGl_Workspace::NbSkippedTransparentElements, "Return the number of skipped transparent elements within active OpenGl_RenderFilter_OpaqueOnly filter.");
cls_OpenGl_Workspace.def("ResetSkippedCounter", (void (OpenGl_Workspace::*)()) &OpenGl_Workspace::ResetSkippedCounter, "Reset skipped transparent elements counter.");
cls_OpenGl_Workspace.def("ViewMatrix", (const OpenGl_Matrix * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ViewMatrix, "Returns applied view matrix.");
cls_OpenGl_Workspace.def("ModelMatrix", (const OpenGl_Matrix * (OpenGl_Workspace::*)() const) &OpenGl_Workspace::ModelMatrix, "Returns applied model structure matrix.");
cls_OpenGl_Workspace.def("NoneCulling", (const OpenGl_Aspects & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::NoneCulling, "Returns face aspect for none culling mode.");
cls_OpenGl_Workspace.def("FrontCulling", (const OpenGl_Aspects & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::FrontCulling, "Returns face aspect for front face culling mode.");
cls_OpenGl_Workspace.def("SetEnvironmentTexture", (void (OpenGl_Workspace::*)(const opencascade::handle<OpenGl_TextureSet> &)) &OpenGl_Workspace::SetEnvironmentTexture, "Sets a new environment texture.", py::arg("theTexture"));
cls_OpenGl_Workspace.def("EnvironmentTexture", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::EnvironmentTexture, "Returns environment texture.");
cls_OpenGl_Workspace.def_static("get_type_name_", (const char * (*)()) &OpenGl_Workspace::get_type_name, "None");
cls_OpenGl_Workspace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Workspace::get_type_descriptor, "None");
cls_OpenGl_Workspace.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Workspace::*)() const) &OpenGl_Workspace::DynamicType, "None");
// cls_OpenGl_Workspace.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Workspace::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Workspace.def_static("operator delete_", (void (*)(void *)) &OpenGl_Workspace::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Workspace::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Workspace.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Workspace::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Workspace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Workspace.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Workspace::operator delete, "None", py::arg(""), py::arg(""));
*/

// CLASS: OPENGL_BACKGROUNDARRAY
py::class_<OpenGl_BackgroundArray, OpenGl_PrimitiveArray> cls_OpenGl_BackgroundArray(mod, "OpenGl_BackgroundArray", "Tool class for generating reusable data for gradient or texture background rendering.");

// Constructors
cls_OpenGl_BackgroundArray.def(py::init<const Graphic3d_TypeOfBackground>(), py::arg("theType"));

// Methods
cls_OpenGl_BackgroundArray.def("Render", (void (OpenGl_BackgroundArray::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_BackgroundArray::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_BackgroundArray.def("IsDefined", (bool (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::IsDefined, "Check if background parameters are set properly");
cls_OpenGl_BackgroundArray.def("SetTextureParameters", (void (OpenGl_BackgroundArray::*)(const Aspect_FillMethod)) &OpenGl_BackgroundArray::SetTextureParameters, "Sets background texture parameters", py::arg("theFillMethod"));
cls_OpenGl_BackgroundArray.def("SetTextureFillMethod", (void (OpenGl_BackgroundArray::*)(const Aspect_FillMethod)) &OpenGl_BackgroundArray::SetTextureFillMethod, "Sets texture fill method", py::arg("theFillMethod"));
cls_OpenGl_BackgroundArray.def("TextureFillMethod", (Aspect_FillMethod (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::TextureFillMethod, "Gets background texture fill method");
cls_OpenGl_BackgroundArray.def("GradientFillMethod", (Aspect_GradientFillMethod (OpenGl_BackgroundArray::*)() const) &OpenGl_BackgroundArray::GradientFillMethod, "Gets background gradient fill method");
cls_OpenGl_BackgroundArray.def("GradientColor", (const OpenGl_Vec4 & (OpenGl_BackgroundArray::*)(const Standard_Integer) const) &OpenGl_BackgroundArray::GradientColor, "Returns color of gradient background for the given index.", py::arg("theIndex"));
cls_OpenGl_BackgroundArray.def("SetGradientFillMethod", (void (OpenGl_BackgroundArray::*)(const Aspect_GradientFillMethod)) &OpenGl_BackgroundArray::SetGradientFillMethod, "Sets type of gradient fill method", py::arg("theType"));
cls_OpenGl_BackgroundArray.def("SetGradientParameters", (void (OpenGl_BackgroundArray::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &OpenGl_BackgroundArray::SetGradientParameters, "Sets background gradient parameters", py::arg("theColor1"), py::arg("theColor2"), py::arg("theType"));

// CLASS: OPENGL_CAPPINGPLANERESOURCE
py::class_<OpenGl_CappingPlaneResource, opencascade::handle<OpenGl_CappingPlaneResource>, OpenGl_Resource> cls_OpenGl_CappingPlaneResource(mod, "OpenGl_CappingPlaneResource", "Container of graphical resources for rendering capping plane associated to graphical clipping plane. This resource holds data necessary for OpenGl_CappingAlgo. This object is implemented as OpenGl resource for the following reasons: - one instance should be shared between contexts. - instance associated to Graphic3d_ClipPlane data by id. - should created and released within context (owns OpenGl elements and resources).");

// Constructors
cls_OpenGl_CappingPlaneResource.def(py::init<const opencascade::handle<Graphic3d_ClipPlane> &>(), py::arg("thePlane"));

// Methods
cls_OpenGl_CappingPlaneResource.def("Update", (void (OpenGl_CappingPlaneResource::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_Aspects> &)) &OpenGl_CappingPlaneResource::Update, "Update resource data in the passed context.", py::arg("theContext"), py::arg("theObjAspect"));
cls_OpenGl_CappingPlaneResource.def("Release", (void (OpenGl_CappingPlaneResource::*)(OpenGl_Context *)) &OpenGl_CappingPlaneResource::Release, "Release associated OpenGl resources.", py::arg("theContext"));
cls_OpenGl_CappingPlaneResource.def("EstimatedDataSize", (Standard_Size (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::EstimatedDataSize, "Returns estimated GPU memory usage - not implemented.");
cls_OpenGl_CappingPlaneResource.def("Plane", (const opencascade::handle<Graphic3d_ClipPlane> & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Plane, "Return parent clipping plane structure.");
cls_OpenGl_CappingPlaneResource.def("AspectFace", (const OpenGl_Aspects * (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::AspectFace, "Returns aspect face for rendering capping surface.");
cls_OpenGl_CappingPlaneResource.def("Orientation", (const OpenGl_Matrix * (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Orientation, "Returns evaluated orientation matrix to transform infinite plane.");
cls_OpenGl_CappingPlaneResource.def("Primitives", (const OpenGl_PrimitiveArray & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::Primitives, "Returns primitive array of vertices to render infinite plane.");
cls_OpenGl_CappingPlaneResource.def_static("get_type_name_", (const char * (*)()) &OpenGl_CappingPlaneResource::get_type_name, "None");
cls_OpenGl_CappingPlaneResource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_CappingPlaneResource::get_type_descriptor, "None");
cls_OpenGl_CappingPlaneResource.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_CappingPlaneResource::*)() const) &OpenGl_CappingPlaneResource::DynamicType, "None");

// CLASS: OPENGL_CLIPPINGITERATOR
py::class_<OpenGl_ClippingIterator> cls_OpenGl_ClippingIterator(mod, "OpenGl_ClippingIterator", "The iterator through clipping planes.");

// Constructors
cls_OpenGl_ClippingIterator.def(py::init<const OpenGl_Clipping &>(), py::arg("theClipping"));

// Methods
cls_OpenGl_ClippingIterator.def("More", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::More, "Return true if iterator points to the valid clipping plane.");
cls_OpenGl_ClippingIterator.def("Next", (void (OpenGl_ClippingIterator::*)()) &OpenGl_ClippingIterator::Next, "Go to the next clipping plane.");
cls_OpenGl_ClippingIterator.def("IsDisabled", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::IsDisabled, "Return true if plane has been temporarily disabled either by Graphic3d_ClipPlane->IsOn() property or by temporary filter. Beware that this method does NOT handle a Chain filter for Capping algorithm OpenGl_Clipping::CappedChain()!");
cls_OpenGl_ClippingIterator.def("Value", (const opencascade::handle<Graphic3d_ClipPlane> & (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::Value, "Return the plane at current iterator position.");
cls_OpenGl_ClippingIterator.def("IsGlobal", (bool (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::IsGlobal, "Return true if plane from the global (view) list.");
cls_OpenGl_ClippingIterator.def("PlaneIndex", (Standard_Integer (OpenGl_ClippingIterator::*)() const) &OpenGl_ClippingIterator::PlaneIndex, "Return the plane index.");

// CLASS: OPENGL_EXTGS
py::class_<OpenGl_ExtGS> cls_OpenGl_ExtGS(mod, "OpenGl_ExtGS", "Geometry shader as extension is available on OpenGL 2.0+");

// Constructors
cls_OpenGl_ExtGS.def(py::init<>());

// CLASS: OPENGL_FLIPPER
py::class_<OpenGl_Flipper, OpenGl_Element> cls_OpenGl_Flipper(mod, "OpenGl_Flipper", "Being rendered, the elements modifies current model-view matrix such that the axes of the specified reference system (in model space) become oriented in the following way: - X - heads to the right side of view. - Y - heads to the up side of view. - N(Z) - heads towards the screen. Originally, this element serves for need of flipping the 3D text of dimension presentations.");

// Constructors
cls_OpenGl_Flipper.def(py::init<const gp_Ax2 &>(), py::arg("theReferenceSystem"));

// Methods
cls_OpenGl_Flipper.def("SetOptions", (void (OpenGl_Flipper::*)(const Standard_Boolean)) &OpenGl_Flipper::SetOptions, "Set options for the element.", py::arg("theIsEnabled"));
cls_OpenGl_Flipper.def("Render", (void (OpenGl_Flipper::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Flipper::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Flipper.def("Release", (void (OpenGl_Flipper::*)(OpenGl_Context *)) &OpenGl_Flipper::Release, "None", py::arg("theCtx"));
// cls_OpenGl_Flipper.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Flipper::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Flipper.def_static("operator delete_", (void (*)(void *)) &OpenGl_Flipper::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Flipper::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Flipper.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Flipper::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Flipper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Flipper.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Flipper::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_FONT
py::class_<OpenGl_Font, opencascade::handle<OpenGl_Font>, OpenGl_Resource> cls_OpenGl_Font(mod, "OpenGl_Font", "Texture font.");

// Constructors
cls_OpenGl_Font.def(py::init<const opencascade::handle<Font_FTFont> &>(), py::arg("theFont"));
cls_OpenGl_Font.def(py::init<const opencascade::handle<Font_FTFont> &, const TCollection_AsciiString &>(), py::arg("theFont"), py::arg("theKey"));

// Methods
cls_OpenGl_Font.def("Release", (void (OpenGl_Font::*)(OpenGl_Context *)) &OpenGl_Font::Release, "Destroy object - will release GPU memory if any", py::arg("theCtx"));
cls_OpenGl_Font.def("EstimatedDataSize", (Standard_Size (OpenGl_Font::*)() const) &OpenGl_Font::EstimatedDataSize, "Returns estimated GPU memory usage.");
cls_OpenGl_Font.def("ResourceKey", (const TCollection_AsciiString & (OpenGl_Font::*)() const) &OpenGl_Font::ResourceKey, "Returns key of shared resource");
cls_OpenGl_Font.def("FTFont", (const opencascade::handle<Font_FTFont> & (OpenGl_Font::*)() const) &OpenGl_Font::FTFont, "Returns FreeType font instance specified on construction.");
cls_OpenGl_Font.def("IsValid", (bool (OpenGl_Font::*)() const) &OpenGl_Font::IsValid, "Returns true if font was loaded successfully.");
cls_OpenGl_Font.def("WasInitialized", (bool (OpenGl_Font::*)() const) &OpenGl_Font::WasInitialized, "Notice that this method doesn't return initialization success state. Use IsValid() instead.");
cls_OpenGl_Font.def("Init", (bool (OpenGl_Font::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Font::Init, "Initialize GL resources. FreeType font instance should be already initialized!", py::arg("theCtx"));
cls_OpenGl_Font.def("Ascender", (float (OpenGl_Font::*)() const) &OpenGl_Font::Ascender, "Returns vertical distance from the horizontal baseline to the highest character coordinate");
cls_OpenGl_Font.def("Descender", (float (OpenGl_Font::*)() const) &OpenGl_Font::Descender, "Returns vertical distance from the horizontal baseline to the lowest character coordinate");
cls_OpenGl_Font.def("RenderGlyph", (bool (OpenGl_Font::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Utf32Char, OpenGl_Font::Tile &)) &OpenGl_Font::RenderGlyph, "Render glyph to texture if not already.", py::arg("theCtx"), py::arg("theUChar"), py::arg("theGlyph"));
cls_OpenGl_Font.def_static("get_type_name_", (const char * (*)()) &OpenGl_Font::get_type_name, "None");
cls_OpenGl_Font.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Font::get_type_descriptor, "None");
cls_OpenGl_Font.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Font::*)() const) &OpenGl_Font::DynamicType, "None");

// CLASS: OPENGL_FRAMESTATS
py::class_<OpenGl_FrameStats, opencascade::handle<OpenGl_FrameStats>, Graphic3d_FrameStats> cls_OpenGl_FrameStats(mod, "OpenGl_FrameStats", "Class storing the frame statistics.");

// Constructors
cls_OpenGl_FrameStats.def(py::init<>());

// Methods
cls_OpenGl_FrameStats.def_static("get_type_name_", (const char * (*)()) &OpenGl_FrameStats::get_type_name, "None");
cls_OpenGl_FrameStats.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_FrameStats::get_type_descriptor, "None");
cls_OpenGl_FrameStats.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_FrameStats::*)() const) &OpenGl_FrameStats::DynamicType, "None");
cls_OpenGl_FrameStats.def("IsFrameUpdated", (bool (OpenGl_FrameStats::*)(opencascade::handle<OpenGl_FrameStats> &) const) &OpenGl_FrameStats::IsFrameUpdated, "Copy stats values into another instance (create new instance, if not exists). The main use of this method is to track changes in statistics (e.g. in conjunction with IsEqual() method).", py::arg("thePrev"));

// CLASS: OPENGL_TEXTBUILDER
py::class_<OpenGl_TextBuilder> cls_OpenGl_TextBuilder(mod, "OpenGl_TextBuilder", "This class generates primitive array required for rendering textured text using OpenGl_Font instance.");

// Constructors
cls_OpenGl_TextBuilder.def(py::init<>());

// Methods
cls_OpenGl_TextBuilder.def("Perform", (void (OpenGl_TextBuilder::*)(const Font_TextFormatter &, const opencascade::handle<OpenGl_Context> &, OpenGl_Font &, NCollection_Vector<GLuint> &, NCollection_Vector<opencascade::handle<OpenGl_VertexBuffer> > &, NCollection_Vector<opencascade::handle<OpenGl_VertexBuffer> > &)) &OpenGl_TextBuilder::Perform, "Creates texture quads for the given text.", py::arg("theFormatter"), py::arg("theContext"), py::arg("theFont"), py::arg("theTextures"), py::arg("theVertsPerTexture"), py::arg("theTCrdsPerTexture"));

// CLASS: OPENGL_TEXT
py::class_<OpenGl_Text, OpenGl_Element> cls_OpenGl_Text(mod, "OpenGl_Text", "Text rendering");

// Constructors
cls_OpenGl_Text.def(py::init<const opencascade::handle<Graphic3d_Text> &>(), py::arg("theTextParams"));
cls_OpenGl_Text.def(py::init<>());

// Methods
cls_OpenGl_Text.def("Reset", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Text::Reset, "Release cached VBO resources and the previous font if height changed. Cached structures will be refilled by the next render. Call Reset after modifying text parameters.", py::arg("theCtx"));
cls_OpenGl_Text.def("Text", (const opencascade::handle<Graphic3d_Text> & (OpenGl_Text::*)() const) &OpenGl_Text::Text, "Returns text parameters");
cls_OpenGl_Text.def("SetText", (void (OpenGl_Text::*)(const opencascade::handle<Graphic3d_Text> &)) &OpenGl_Text::SetText, "Sets text parameters", py::arg("theText"));
cls_OpenGl_Text.def("Is2D", (Standard_Boolean (OpenGl_Text::*)() const) &OpenGl_Text::Is2D, "Return true if text is 2D");
cls_OpenGl_Text.def("Set2D", (void (OpenGl_Text::*)(const Standard_Boolean)) &OpenGl_Text::Set2D, "Set true if text is 2D", py::arg("theEnable"));
cls_OpenGl_Text.def("SetFontSize", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Integer)) &OpenGl_Text::SetFontSize, "Setup new font size", py::arg("theContext"), py::arg("theFontSize"));
cls_OpenGl_Text.def("Render", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Text::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Text.def("Release", (void (OpenGl_Text::*)(OpenGl_Context *)) &OpenGl_Text::Release, "None", py::arg("theContext"));
cls_OpenGl_Text.def_static("FontKey_", (TCollection_AsciiString (*)(const OpenGl_Aspects &, Standard_Integer, unsigned int)) &OpenGl_Text::FontKey, "Create key for shared resource", py::arg("theAspect"), py::arg("theHeight"), py::arg("theResolution"));
cls_OpenGl_Text.def_static("FindFont_", (opencascade::handle<OpenGl_Font> (*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_Aspects &, Standard_Integer, unsigned int, const TCollection_AsciiString &)) &OpenGl_Text::FindFont, "Find shared resource for specified font or initialize new one", py::arg("theCtx"), py::arg("theAspect"), py::arg("theHeight"), py::arg("theResolution"), py::arg("theKey"));
cls_OpenGl_Text.def_static("StringSize_", (void (*)(const opencascade::handle<OpenGl_Context> &, const NCollection_String &, const OpenGl_Aspects &, const Standard_ShortReal, const unsigned int, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &)) &OpenGl_Text::StringSize, "Compute text width", py::arg("theCtx"), py::arg("theText"), py::arg("theTextAspect"), py::arg("theHeight"), py::arg("theResolution"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_OpenGl_Text.def("Render", [](OpenGl_Text &self, const opencascade::handle<OpenGl_Context> & a0, const OpenGl_Aspects & a1) -> void { return self.Render(a0, a1); });
cls_OpenGl_Text.def("Render", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_Aspects &, unsigned int) const) &OpenGl_Text::Render, "Perform rendering", py::arg("theCtx"), py::arg("theTextAspect"), py::arg("theResolution"));
cls_OpenGl_Text.def("Init", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Utf8Char *, const OpenGl_Vec3 &)) &OpenGl_Text::Init, "Setup new string and position", py::arg("theCtx"), py::arg("theText"), py::arg("thePoint"));
cls_OpenGl_Text.def("SetPosition", (void (OpenGl_Text::*)(const OpenGl_Vec3 &)) &OpenGl_Text::SetPosition, "Setup new position", py::arg("thePoint"));
// cls_OpenGl_Text.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Text::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Text.def_static("operator delete_", (void (*)(void *)) &OpenGl_Text::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Text::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Text.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Text::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Text::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Text::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: OPENGL_FRAMESTATSPRS
py::class_<OpenGl_FrameStatsPrs, OpenGl_Element> cls_OpenGl_FrameStatsPrs(mod, "OpenGl_FrameStatsPrs", "Element rendering frame statistics.");

// Constructors
cls_OpenGl_FrameStatsPrs.def(py::init<>());

// Methods
cls_OpenGl_FrameStatsPrs.def("Render", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_FrameStatsPrs::Render, "Render element.", py::arg("theWorkspace"));
cls_OpenGl_FrameStatsPrs.def("Release", (void (OpenGl_FrameStatsPrs::*)(OpenGl_Context *)) &OpenGl_FrameStatsPrs::Release, "Release OpenGL resources.", py::arg("theCtx"));
cls_OpenGl_FrameStatsPrs.def("Update", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<OpenGl_Workspace> &)) &OpenGl_FrameStatsPrs::Update, "Update text.", py::arg("theWorkspace"));
cls_OpenGl_FrameStatsPrs.def("SetTextAspect", (void (OpenGl_FrameStatsPrs::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &OpenGl_FrameStatsPrs::SetTextAspect, "Assign text aspect.", py::arg("theAspect"));

// TYPEDEF: OPENGL_GLCORE21
if (py::hasattr(mod, "OpenGl_GlCore21")) {
	mod.attr("OpenGl_GlCore21") = mod.attr("OpenGl_GlCore21");
}

// TYPEDEF: OPENGL_GLCORE21FWD
if (py::hasattr(mod, "OpenGl_GlCore21Fwd")) {
	mod.attr("OpenGl_GlCore21Fwd") = mod.attr("OpenGl_GlCore21Fwd");
}

// TYPEDEF: OPENGL_GLCORE30
if (py::hasattr(mod, "OpenGl_GlCore30")) {
	mod.attr("OpenGl_GlCore30") = mod.attr("OpenGl_GlCore30");
}

// TYPEDEF: OPENGL_GLCORE30FWD
if (py::hasattr(mod, "OpenGl_GlCore30Fwd")) {
	mod.attr("OpenGl_GlCore30Fwd") = mod.attr("OpenGl_GlCore30Fwd");
}

// TYPEDEF: OPENGL_GLCORE31BACK
if (py::hasattr(mod, "OpenGl_GlCore31Back")) {
	mod.attr("OpenGl_GlCore31Back") = mod.attr("OpenGl_GlCore31Back");
}

// TYPEDEF: OPENGL_GLCORE31
if (py::hasattr(mod, "OpenGl_GlCore31")) {
	mod.attr("OpenGl_GlCore31") = mod.attr("OpenGl_GlCore31");
}

// TYPEDEF: OPENGL_GLCORE32BACK
if (py::hasattr(mod, "OpenGl_GlCore32Back")) {
	mod.attr("OpenGl_GlCore32Back") = mod.attr("OpenGl_GlCore32Back");
}

// TYPEDEF: OPENGL_GLCORE32
if (py::hasattr(mod, "OpenGl_GlCore32")) {
	mod.attr("OpenGl_GlCore32") = mod.attr("OpenGl_GlCore32");
}

// TYPEDEF: OPENGL_GLCORE33BACK
if (py::hasattr(mod, "OpenGl_GlCore33Back")) {
	mod.attr("OpenGl_GlCore33Back") = mod.attr("OpenGl_GlCore33Back");
}

// TYPEDEF: OPENGL_GLCORE33
if (py::hasattr(mod, "OpenGl_GlCore33")) {
	mod.attr("OpenGl_GlCore33") = mod.attr("OpenGl_GlCore33");
}

// TYPEDEF: OPENGL_GLCORE40BACK
if (py::hasattr(mod, "OpenGl_GlCore40Back")) {
	mod.attr("OpenGl_GlCore40Back") = mod.attr("OpenGl_GlCore40Back");
}

// TYPEDEF: OPENGL_GLCORE40
if (py::hasattr(mod, "OpenGl_GlCore40")) {
	mod.attr("OpenGl_GlCore40") = mod.attr("OpenGl_GlCore40");
}

// TYPEDEF: OPENGL_GLCORE41BACK
if (py::hasattr(mod, "OpenGl_GlCore41Back")) {
	mod.attr("OpenGl_GlCore41Back") = mod.attr("OpenGl_GlCore41Back");
}

// TYPEDEF: OPENGL_GLCORE41
if (py::hasattr(mod, "OpenGl_GlCore41")) {
	mod.attr("OpenGl_GlCore41") = mod.attr("OpenGl_GlCore41");
}

// TYPEDEF: OPENGL_GLCORE42BACK
if (py::hasattr(mod, "OpenGl_GlCore42Back")) {
	mod.attr("OpenGl_GlCore42Back") = mod.attr("OpenGl_GlCore42Back");
}

// TYPEDEF: OPENGL_GLCORE42
if (py::hasattr(mod, "OpenGl_GlCore42")) {
	mod.attr("OpenGl_GlCore42") = mod.attr("OpenGl_GlCore42");
}

// TYPEDEF: OPENGL_GLCORE43BACK
if (py::hasattr(mod, "OpenGl_GlCore43Back")) {
	mod.attr("OpenGl_GlCore43Back") = mod.attr("OpenGl_GlCore43Back");
}

// TYPEDEF: OPENGL_GLCORE43
if (py::hasattr(mod, "OpenGl_GlCore43")) {
	mod.attr("OpenGl_GlCore43") = mod.attr("OpenGl_GlCore43");
}

// TYPEDEF: OPENGL_GLCORE44BACK
if (py::hasattr(mod, "OpenGl_GlCore44Back")) {
	mod.attr("OpenGl_GlCore44Back") = mod.attr("OpenGl_GlCore44Back");
}

// TYPEDEF: OPENGL_GLCORE44
if (py::hasattr(mod, "OpenGl_GlCore44")) {
	mod.attr("OpenGl_GlCore44") = mod.attr("OpenGl_GlCore44");
}

// TYPEDEF: OPENGL_GLCORE45BACK
if (py::hasattr(mod, "OpenGl_GlCore45Back")) {
	mod.attr("OpenGl_GlCore45Back") = mod.attr("OpenGl_GlCore45Back");
}

// TYPEDEF: OPENGL_GLCORE45
if (py::hasattr(mod, "OpenGl_GlCore45")) {
	mod.attr("OpenGl_GlCore45") = mod.attr("OpenGl_GlCore45");
}

// CLASS: OPENGL_GRADUATEDTRIHEDRON
/*
py::class_<OpenGl_GraduatedTrihedron, OpenGl_Element> cls_OpenGl_GraduatedTrihedron(mod, "OpenGl_GraduatedTrihedron", "This class allows to render Graduated Trihedron, i.e. trihedron with grid. it is based on Graphic3d_GraduatedTrihedron parameters and support its customization on construction level only.");

// Constructors
cls_OpenGl_GraduatedTrihedron.def(py::init<>());

// Methods
// cls_OpenGl_GraduatedTrihedron.def_static("operator new_", (void * (*)(size_t)) &OpenGl_GraduatedTrihedron::operator new, "None", py::arg("theSize"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete_", (void (*)(void *)) &OpenGl_GraduatedTrihedron::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_GraduatedTrihedron::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_GraduatedTrihedron::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_GraduatedTrihedron::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_GraduatedTrihedron::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_GraduatedTrihedron.def("Render", (void (OpenGl_GraduatedTrihedron::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_GraduatedTrihedron::Render, "Draw the element.", py::arg("theWorkspace"));
cls_OpenGl_GraduatedTrihedron.def("Release", (void (OpenGl_GraduatedTrihedron::*)(OpenGl_Context *)) &OpenGl_GraduatedTrihedron::Release, "Release OpenGL resources.", py::arg("theCtx"));
cls_OpenGl_GraduatedTrihedron.def("SetValues", (void (OpenGl_GraduatedTrihedron::*)(const Graphic3d_GraduatedTrihedron &)) &OpenGl_GraduatedTrihedron::SetValues, "Setup configuration.", py::arg("theData"));
cls_OpenGl_GraduatedTrihedron.def("SetMinMax", (void (OpenGl_GraduatedTrihedron::*)(const OpenGl_Vec3 &, const OpenGl_Vec3 &)) &OpenGl_GraduatedTrihedron::SetMinMax, "Sets up-to-date values of scene bounding box. Can be used in callback mechanism to get up-to-date values.", py::arg("theMin"), py::arg("theMax"));
*/

// CLASS: OPENGL_STATECOUNTER
py::class_<OpenGl_StateCounter> cls_OpenGl_StateCounter(mod, "OpenGl_StateCounter", "Tool class to implement consistent state counter for objects inside the same driver instance.");

// Constructors
cls_OpenGl_StateCounter.def(py::init<>());

// Methods
cls_OpenGl_StateCounter.def("Increment", (Standard_Size (OpenGl_StateCounter::*)()) &OpenGl_StateCounter::Increment, "None");

// CLASS: OPENGL_GRAPHICDRIVER
py::class_<OpenGl_GraphicDriver, opencascade::handle<OpenGl_GraphicDriver>, Graphic3d_GraphicDriver> cls_OpenGl_GraphicDriver(mod, "OpenGl_GraphicDriver", "This class defines an OpenGl graphic driver");

// Constructors
cls_OpenGl_GraphicDriver.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &>(), py::arg("theDisp"));
cls_OpenGl_GraphicDriver.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Standard_Boolean>(), py::arg("theDisp"), py::arg("theToInitialize"));

// Methods
cls_OpenGl_GraphicDriver.def_static("get_type_name_", (const char * (*)()) &OpenGl_GraphicDriver::get_type_name, "None");
cls_OpenGl_GraphicDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_GraphicDriver::get_type_descriptor, "None");
cls_OpenGl_GraphicDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::DynamicType, "None");
cls_OpenGl_GraphicDriver.def("ReleaseContext", (void (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::ReleaseContext, "Release default context.");
cls_OpenGl_GraphicDriver.def("InitContext", (Standard_Boolean (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::InitContext, "Perform initialization of default OpenGL context.");
cls_OpenGl_GraphicDriver.def("InquireLimit", (Standard_Integer (OpenGl_GraphicDriver::*)(const Graphic3d_TypeOfLimit) const) &OpenGl_GraphicDriver::InquireLimit, "Request limit of graphic resource of specific type.", py::arg("theType"));
cls_OpenGl_GraphicDriver.def("CreateStructure", (opencascade::handle<Graphic3d_CStructure> (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &OpenGl_GraphicDriver::CreateStructure, "None", py::arg("theManager"));
cls_OpenGl_GraphicDriver.def("RemoveStructure", (void (OpenGl_GraphicDriver::*)(opencascade::handle<Graphic3d_CStructure> &)) &OpenGl_GraphicDriver::RemoveStructure, "None", py::arg("theCStructure"));
cls_OpenGl_GraphicDriver.def("CreateView", (opencascade::handle<Graphic3d_CView> (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &OpenGl_GraphicDriver::CreateView, "None", py::arg("theMgr"));
cls_OpenGl_GraphicDriver.def("RemoveView", (void (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &)) &OpenGl_GraphicDriver::RemoveView, "None", py::arg("theView"));
cls_OpenGl_GraphicDriver.def("CreateRenderWindow", (opencascade::handle<OpenGl_Window> (OpenGl_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &OpenGl_GraphicDriver::CreateRenderWindow, "None", py::arg("theWindow"), py::arg("theContext"));
cls_OpenGl_GraphicDriver.def("TextSize", (void (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &, const Standard_CString, const Standard_ShortReal, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &OpenGl_GraphicDriver::TextSize, "None", py::arg("theView"), py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_OpenGl_GraphicDriver.def("DefaultTextHeight", (Standard_ShortReal (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::DefaultTextHeight, "None");
cls_OpenGl_GraphicDriver.def("ViewExists", (Standard_Boolean (OpenGl_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, opencascade::handle<Graphic3d_CView> &)) &OpenGl_GraphicDriver::ViewExists, "None", py::arg("theWindow"), py::arg("theView"));
cls_OpenGl_GraphicDriver.def("InsertLayerBefore", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::InsertLayerBefore, "Adds a layer to all views.", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerAfter"));
cls_OpenGl_GraphicDriver.def("InsertLayerAfter", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::InsertLayerAfter, "Adds a layer to all views.", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerBefore"));
cls_OpenGl_GraphicDriver.def("RemoveZLayer", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::RemoveZLayer, "Removes Z layer. All structures displayed at the moment in layer will be displayed in default layer (the bottom-level z layer). By default, there are always default bottom-level layer that can't be removed. The passed theLayerId should be not less than 0 (reserved for default layers that can not be removed).", py::arg("theLayerId"));
cls_OpenGl_GraphicDriver.def("SetZLayerSettings", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_GraphicDriver::SetZLayerSettings, "Sets the settings for a single Z layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_GraphicDriver.def("Options", (const OpenGl_Caps & (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::Options, "Returns the visualization options");
cls_OpenGl_GraphicDriver.def("ChangeOptions", (OpenGl_Caps & (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::ChangeOptions, "Returns the visualization options");
cls_OpenGl_GraphicDriver.def("SetBuffersNoSwap", (void (OpenGl_GraphicDriver::*)(const Standard_Boolean)) &OpenGl_GraphicDriver::SetBuffersNoSwap, "Specify swap buffer behavior.", py::arg("theIsNoSwap"));
cls_OpenGl_GraphicDriver.def("EnableVBO", (void (OpenGl_GraphicDriver::*)(const Standard_Boolean)) &OpenGl_GraphicDriver::EnableVBO, "VBO usage can be forbidden by this method even if it is supported by GL driver. Notice that disabling of VBO will cause rendering performance degradation. Warning! This method should be called only before any primitives are displayed in GL scene!", py::arg("theToTurnOn"));
cls_OpenGl_GraphicDriver.def("MemoryInfo", (Standard_Boolean (OpenGl_GraphicDriver::*)(Standard_Size &, TCollection_AsciiString &) const) &OpenGl_GraphicDriver::MemoryInfo, "Returns information about GPU memory usage. Please read OpenGl_Context::MemoryInfo() for more description.", py::arg("theFreeBytes"), py::arg("theInfo"));
cls_OpenGl_GraphicDriver.def("GetSharedContext", [](OpenGl_GraphicDriver &self) -> const opencascade::handle<OpenGl_Context> & { return self.GetSharedContext(); });
cls_OpenGl_GraphicDriver.def("GetSharedContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_GraphicDriver::*)(bool) const) &OpenGl_GraphicDriver::GetSharedContext, "Method to retrieve valid GL context. Could return NULL-handle if no window created by this driver.", py::arg("theBound"));
cls_OpenGl_GraphicDriver.def("setDeviceLost", (void (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::setDeviceLost, "Set device lost flag for redrawn views.");
cls_OpenGl_GraphicDriver.def("GetStateCounter", (OpenGl_StateCounter * (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::GetStateCounter, "State counter for OpenGl structures.");
cls_OpenGl_GraphicDriver.def("GetNextPrimitiveArrayUID", (Standard_Size (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::GetNextPrimitiveArrayUID, "Returns unique ID for primitive arrays.");

// CLASS: OPENGL_HALTONSAMPLER
py::class_<OpenGl_HaltonSampler> cls_OpenGl_HaltonSampler(mod, "OpenGl_HaltonSampler", "Compute points of the Halton sequence with with digit-permutations for different bases.");

// Constructors
cls_OpenGl_HaltonSampler.def(py::init<>());

// Methods
cls_OpenGl_HaltonSampler.def_static("get_num_dimensions_", (unsigned int (*)()) &OpenGl_HaltonSampler::get_num_dimensions, "Return the number of supported dimensions.");
cls_OpenGl_HaltonSampler.def("initFaure", (void (OpenGl_HaltonSampler::*)()) &OpenGl_HaltonSampler::initFaure, "Init the permutation arrays using Faure-permutations. Alternatively, initRandom() can be called before the sampling functionality can be used.");
cls_OpenGl_HaltonSampler.def("sample", (float (OpenGl_HaltonSampler::*)(unsigned int, unsigned int) const) &OpenGl_HaltonSampler::sample, "Return the Halton sample for the given dimension (component) and index. The client must have called initRandom or initFaure() at least once before. dimension must be smaller than the value returned by get_num_dimensions().", py::arg("theDimension"), py::arg("theIndex"));

// TYPEDEF: OPENGL_LAYER
/*
/*
py::class_<Graphic3d_Layer, opencascade::handle<Graphic3d_Layer>, Standard_Transient> cls_OpenGl_Layer(mod, "OpenGl_Layer", "Presentations list sorted within priorities.", py::module_local());

// Constructors
cls_OpenGl_Layer.def(py::init<Graphic3d_ZLayerId, Standard_Integer, const opencascade::handle<Select3D_BVHBuilder3d> &>(), py::arg("theId"), py::arg("theNbPriorities"), py::arg("theBuilder"));

// Methods
cls_OpenGl_Layer.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Layer::get_type_name, "None");
cls_OpenGl_Layer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Layer::get_type_descriptor, "None");
cls_OpenGl_Layer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::DynamicType, "None");
cls_OpenGl_Layer.def("LayerId", (Graphic3d_ZLayerId (Graphic3d_Layer::*)() const) &Graphic3d_Layer::LayerId, "Return layer id.");
cls_OpenGl_Layer.def("FrustumCullingBVHBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::FrustumCullingBVHBuilder, "Returns BVH tree builder for frustom culling.", py::call_guard<ImportSelect3D>());
cls_OpenGl_Layer.def("SetFrustumCullingBVHBuilder", (void (Graphic3d_Layer::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &Graphic3d_Layer::SetFrustumCullingBVHBuilder, "Assigns BVH tree builder for frustom culling.", py::arg("theBuilder"), py::call_guard<ImportSelect3D>());
cls_OpenGl_Layer.def("IsImmediate", (Standard_Boolean (Graphic3d_Layer::*)() const) &Graphic3d_Layer::IsImmediate, "Return true if layer was marked with immediate flag.");
cls_OpenGl_Layer.def("LayerSettings", (const Graphic3d_ZLayerSettings & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::LayerSettings, "Returns settings of the layer object.");
cls_OpenGl_Layer.def("SetLayerSettings", (void (Graphic3d_Layer::*)(const Graphic3d_ZLayerSettings &)) &Graphic3d_Layer::SetLayerSettings, "Sets settings of the layer object.", py::arg("theSettings"));
cls_OpenGl_Layer.def("Add", [](Graphic3d_Layer &self, const Graphic3d_CStructure * a0, Standard_Integer a1) -> void { return self.Add(a0, a1); });
cls_OpenGl_Layer.def("Add", (void (Graphic3d_Layer::*)(const Graphic3d_CStructure *, Standard_Integer, Standard_Boolean)) &Graphic3d_Layer::Add, "None", py::arg("theStruct"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_Layer.def("Remove", [](Graphic3d_Layer &self, const Graphic3d_CStructure * theStruct, Standard_Integer & thePriority, Standard_Boolean isForChangePriority){ bool rv = self.Remove(theStruct, thePriority, isForChangePriority); return std::tuple<bool, Standard_Integer &>(rv, thePriority); }, "Remove structure and returns its priority, if the structure is not found, method returns negative value", py::arg("theStruct"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_Layer.def("NbStructures", (Standard_Integer (Graphic3d_Layer::*)() const) &Graphic3d_Layer::NbStructures, "Returns the number of structures");
cls_OpenGl_Layer.def("NbStructuresNotCulled", (Standard_Integer (Graphic3d_Layer::*)() const) &Graphic3d_Layer::NbStructuresNotCulled, "Number of NOT culled structures in the layer.");
cls_OpenGl_Layer.def("NbPriorities", (Standard_Integer (Graphic3d_Layer::*)() const) &Graphic3d_Layer::NbPriorities, "Returns the number of available priority levels");
cls_OpenGl_Layer.def("Append", (Standard_Boolean (Graphic3d_Layer::*)(const Graphic3d_Layer &)) &Graphic3d_Layer::Append, "Append layer of acceptable type (with similar number of priorities or less). Returns Standard_False if the list can not be accepted.", py::arg("theOther"));
cls_OpenGl_Layer.def("ArrayOfStructures", (const Graphic3d_ArrayOfIndexedMapOfStructure & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::ArrayOfStructures, "Returns array of structures.");
cls_OpenGl_Layer.def("InvalidateBVHData", (void (Graphic3d_Layer::*)()) &Graphic3d_Layer::InvalidateBVHData, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.");
cls_OpenGl_Layer.def("InvalidateBoundingBox", (void (Graphic3d_Layer::*)() const) &Graphic3d_Layer::InvalidateBoundingBox, "Marks cached bounding box as obsolete.");
cls_OpenGl_Layer.def("BoundingBox", (Bnd_Box (Graphic3d_Layer::*)(Standard_Integer, const opencascade::handle<Graphic3d_Camera> &, Standard_Integer, Standard_Integer, Standard_Boolean) const) &Graphic3d_Layer::BoundingBox, "Returns layer bounding box.", py::arg("theViewId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"), py::arg("theToIncludeAuxiliary"));
cls_OpenGl_Layer.def("considerZoomPersistenceObjects", (Standard_Real (Graphic3d_Layer::*)(Standard_Integer, const opencascade::handle<Graphic3d_Camera> &, Standard_Integer, Standard_Integer) const) &Graphic3d_Layer::considerZoomPersistenceObjects, "Returns zoom-scale factor.", py::arg("theViewId"), py::arg("theCamera"), py::arg("theWindowWidth"), py::arg("theWindowHeight"));
cls_OpenGl_Layer.def("UpdateCulling", (void (Graphic3d_Layer::*)(Standard_Integer, const Graphic3d_CullingTool &, const Graphic3d_RenderingParams::FrustumCulling)) &Graphic3d_Layer::UpdateCulling, "Update culling state - should be called before rendering. Traverses through BVH tree to determine which structures are in view volume.", py::arg("theViewId"), py::arg("theSelector"), py::arg("theFrustumCullingState"));
cls_OpenGl_Layer.def("IsCulled", (bool (Graphic3d_Layer::*)() const) &Graphic3d_Layer::IsCulled, "Returns TRUE if layer is empty or has been discarded entirely by culling test.");
cls_OpenGl_Layer.def("NbOfTransformPersistenceObjects", (Standard_Integer (Graphic3d_Layer::*)() const) &Graphic3d_Layer::NbOfTransformPersistenceObjects, "Returns number of transform persistence objects.");
cls_OpenGl_Layer.def("CullableStructuresBVH", (const Graphic3d_BvhCStructureSet & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::CullableStructuresBVH, "Returns set of Graphic3d_CStructures structures for building BVH tree.");
cls_OpenGl_Layer.def("CullableTrsfPersStructuresBVH", (const Graphic3d_BvhCStructureSetTrsfPers & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::CullableTrsfPersStructuresBVH, "Returns set of transform persistent Graphic3d_CStructures for building BVH tree.");
cls_OpenGl_Layer.def("NonCullableStructures", (const NCollection_IndexedMap<const Graphic3d_CStructure *> & (Graphic3d_Layer::*)() const) &Graphic3d_Layer::NonCullableStructures, "Returns indexed map of always rendered structures.");
*/

// CLASS: OPENGL_LAYERLIST
/*
py::class_<OpenGl_LayerList> cls_OpenGl_LayerList(mod, "OpenGl_LayerList", "Class defining the list of layers.");

// Constructors
cls_OpenGl_LayerList.def(py::init<const Standard_Integer>(), py::arg("theNbPriorities"));

// Methods
cls_OpenGl_LayerList.def("NbPriorities", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbPriorities, "Method returns the number of available priorities");
cls_OpenGl_LayerList.def("NbStructures", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbStructures, "Number of displayed structures");
cls_OpenGl_LayerList.def("NbImmediateStructures", (Standard_Integer (OpenGl_LayerList::*)() const) &OpenGl_LayerList::NbImmediateStructures, "Return number of structures within immediate layers");
cls_OpenGl_LayerList.def("InsertLayerBefore", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_LayerList::InsertLayerBefore, "Insert a new layer with id.", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerAfter"));
cls_OpenGl_LayerList.def("InsertLayerAfter", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_LayerList::InsertLayerAfter, "Insert a new layer with id.", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerBefore"));
cls_OpenGl_LayerList.def("RemoveLayer", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::RemoveLayer, "Remove layer by its id.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("AddStructure", [](OpenGl_LayerList &self, const OpenGl_Structure * a0, const Graphic3d_ZLayerId a1, const Standard_Integer a2) -> void { return self.AddStructure(a0, a1, a2); });
cls_OpenGl_LayerList.def("AddStructure", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Standard_Integer, Standard_Boolean)) &OpenGl_LayerList::AddStructure, "Add structure to list with given priority. The structure will be inserted to specified layer. If the layer isn't found, the structure will be put to default bottom-level layer.", py::arg("theStruct"), py::arg("theLayerId"), py::arg("thePriority"), py::arg("isForChangePriority"));
cls_OpenGl_LayerList.def("RemoveStructure", (void (OpenGl_LayerList::*)(const OpenGl_Structure *)) &OpenGl_LayerList::RemoveStructure, "Remove structure from structure list and return its previous priority", py::arg("theStructure"));
cls_OpenGl_LayerList.def("ChangeLayer", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Graphic3d_ZLayerId)) &OpenGl_LayerList::ChangeLayer, "Change structure z layer If the new layer is not presented, the structure will be displayed in default z layer", py::arg("theStructure"), py::arg("theOldLayerId"), py::arg("theNewLayerId"));
cls_OpenGl_LayerList.def("ChangePriority", (void (OpenGl_LayerList::*)(const OpenGl_Structure *, const Graphic3d_ZLayerId, const Standard_Integer)) &OpenGl_LayerList::ChangePriority, "Changes structure priority within its ZLayer", py::arg("theStructure"), py::arg("theLayerId"), py::arg("theNewPriority"));
cls_OpenGl_LayerList.def("Layer", (OpenGl_Layer & (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::Layer, "Returns reference to the layer with given ID.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("Layer", (const OpenGl_Layer & (OpenGl_LayerList::*)(const Graphic3d_ZLayerId) const) &OpenGl_LayerList::Layer, "Returns reference to the layer with given ID.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("SetLayerSettings", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_LayerList::SetLayerSettings, "Assign new settings to the layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_LayerList.def("UpdateCulling", (void (OpenGl_LayerList::*)(const opencascade::handle<OpenGl_Workspace> &, const Standard_Boolean)) &OpenGl_LayerList::UpdateCulling, "Update culling state - should be called before rendering.", py::arg("theWorkspace"), py::arg("theToDrawImmediate"));
cls_OpenGl_LayerList.def("Render", (void (OpenGl_LayerList::*)(const opencascade::handle<OpenGl_Workspace> &, const Standard_Boolean, const OpenGl_LayerFilter, OpenGl_FrameBuffer *, OpenGl_FrameBuffer *) const) &OpenGl_LayerList::Render, "Render this element", py::arg("theWorkspace"), py::arg("theToDrawImmediate"), py::arg("theLayersToProcess"), py::arg("theReadDrawFbo"), py::arg("theOitAccumFbo"));
cls_OpenGl_LayerList.def("Layers", (const NCollection_List<opencascade::handle<Graphic3d_Layer> > & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::Layers, "Returns the set of OpenGL Z-layers.");
cls_OpenGl_LayerList.def("LayerIDs", (const NCollection_DataMap<Graphic3d_ZLayerId, opencascade::handle<Graphic3d_Layer> > & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::LayerIDs, "Returns the map of Z-layer IDs to indexes.");
cls_OpenGl_LayerList.def("InvalidateBVHData", (void (OpenGl_LayerList::*)(const Graphic3d_ZLayerId)) &OpenGl_LayerList::InvalidateBVHData, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.", py::arg("theLayerId"));
cls_OpenGl_LayerList.def("ModificationStateOfRaytracable", (Standard_Size (OpenGl_LayerList::*)() const) &OpenGl_LayerList::ModificationStateOfRaytracable, "Returns structure modification state (for ray-tracing).");
cls_OpenGl_LayerList.def("FrustumCullingBVHBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> & (OpenGl_LayerList::*)() const) &OpenGl_LayerList::FrustumCullingBVHBuilder, "Returns BVH tree builder for frustom culling.");
cls_OpenGl_LayerList.def("SetFrustumCullingBVHBuilder", (void (OpenGl_LayerList::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &OpenGl_LayerList::SetFrustumCullingBVHBuilder, "Assigns BVH tree builder for frustom culling.", py::arg("theBuilder"));
// cls_OpenGl_LayerList.def_static("operator new_", (void * (*)(size_t)) &OpenGl_LayerList::operator new, "None", py::arg("theSize"));
// cls_OpenGl_LayerList.def_static("operator delete_", (void (*)(void *)) &OpenGl_LayerList::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_LayerList::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_LayerList.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_LayerList::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_LayerList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_LayerList.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_LayerList::operator delete, "None", py::arg(""), py::arg(""));
*/

// CLASS: OPENGL_STATEINTERFACE
py::class_<OpenGl_StateInterface> cls_OpenGl_StateInterface(mod, "OpenGl_StateInterface", "Defines interface for OpenGL state.");

// Constructors
cls_OpenGl_StateInterface.def(py::init<>());

// Methods
cls_OpenGl_StateInterface.def("Index", (Standard_Size (OpenGl_StateInterface::*)() const) &OpenGl_StateInterface::Index, "Returns current state index.");
cls_OpenGl_StateInterface.def("Update", (void (OpenGl_StateInterface::*)()) &OpenGl_StateInterface::Update, "Increment current state.");

// CLASS: OPENGL_PROJECTIONSTATE
py::class_<OpenGl_ProjectionState, OpenGl_StateInterface> cls_OpenGl_ProjectionState(mod, "OpenGl_ProjectionState", "Defines state of OCCT projection transformation.");

// Constructors
cls_OpenGl_ProjectionState.def(py::init<>());

// Methods
cls_OpenGl_ProjectionState.def("Set", (void (OpenGl_ProjectionState::*)(const OpenGl_Mat4 &)) &OpenGl_ProjectionState::Set, "Sets new projection matrix.", py::arg("theProjectionMatrix"));
cls_OpenGl_ProjectionState.def("ProjectionMatrix", (const OpenGl_Mat4 & (OpenGl_ProjectionState::*)() const) &OpenGl_ProjectionState::ProjectionMatrix, "Returns current projection matrix.");
cls_OpenGl_ProjectionState.def("ProjectionMatrixInverse", (const OpenGl_Mat4 & (OpenGl_ProjectionState::*)() const) &OpenGl_ProjectionState::ProjectionMatrixInverse, "Returns inverse of current projection matrix.");

// CLASS: OPENGL_MODELWORLDSTATE
py::class_<OpenGl_ModelWorldState, OpenGl_StateInterface> cls_OpenGl_ModelWorldState(mod, "OpenGl_ModelWorldState", "Defines state of OCCT model-world transformation.");

// Constructors
cls_OpenGl_ModelWorldState.def(py::init<>());

// Methods
cls_OpenGl_ModelWorldState.def("Set", (void (OpenGl_ModelWorldState::*)(const OpenGl_Mat4 &)) &OpenGl_ModelWorldState::Set, "Sets new model-world matrix.", py::arg("theModelWorldMatrix"));
cls_OpenGl_ModelWorldState.def("ModelWorldMatrix", (const OpenGl_Mat4 & (OpenGl_ModelWorldState::*)() const) &OpenGl_ModelWorldState::ModelWorldMatrix, "Returns current model-world matrix.");
cls_OpenGl_ModelWorldState.def("ModelWorldMatrixInverse", (const OpenGl_Mat4 & (OpenGl_ModelWorldState::*)() const) &OpenGl_ModelWorldState::ModelWorldMatrixInverse, "Returns inverse of current model-world matrix.");

// CLASS: OPENGL_WORLDVIEWSTATE
py::class_<OpenGl_WorldViewState, OpenGl_StateInterface> cls_OpenGl_WorldViewState(mod, "OpenGl_WorldViewState", "Defines state of OCCT world-view transformation.");

// Constructors
cls_OpenGl_WorldViewState.def(py::init<>());

// Methods
cls_OpenGl_WorldViewState.def("Set", (void (OpenGl_WorldViewState::*)(const OpenGl_Mat4 &)) &OpenGl_WorldViewState::Set, "Sets new world-view matrix.", py::arg("theWorldViewMatrix"));
cls_OpenGl_WorldViewState.def("WorldViewMatrix", (const OpenGl_Mat4 & (OpenGl_WorldViewState::*)() const) &OpenGl_WorldViewState::WorldViewMatrix, "Returns current world-view matrix.");
cls_OpenGl_WorldViewState.def("WorldViewMatrixInverse", (const OpenGl_Mat4 & (OpenGl_WorldViewState::*)() const) &OpenGl_WorldViewState::WorldViewMatrixInverse, "Returns inverse of current world-view matrix.");

// CLASS: OPENGL_LIGHTSOURCESTATE
py::class_<OpenGl_LightSourceState, OpenGl_StateInterface> cls_OpenGl_LightSourceState(mod, "OpenGl_LightSourceState", "Defines state of OCCT light sources.");

// Constructors
cls_OpenGl_LightSourceState.def(py::init<>());

// Methods
cls_OpenGl_LightSourceState.def("Set", (void (OpenGl_LightSourceState::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_LightSourceState::Set, "Sets new light sources.", py::arg("theLightSources"));
cls_OpenGl_LightSourceState.def("LightSources", (const opencascade::handle<Graphic3d_LightSet> & (OpenGl_LightSourceState::*)() const) &OpenGl_LightSourceState::LightSources, "Returns current list of light sources.");

// CLASS: OPENGL_CLIPPINGSTATE
py::class_<OpenGl_ClippingState> cls_OpenGl_ClippingState(mod, "OpenGl_ClippingState", "Defines generic state of OCCT clipping state.");

// Constructors
cls_OpenGl_ClippingState.def(py::init<>());

// Methods
cls_OpenGl_ClippingState.def("Index", (Standard_Size (OpenGl_ClippingState::*)() const) &OpenGl_ClippingState::Index, "Returns current state index.");
cls_OpenGl_ClippingState.def("Update", (void (OpenGl_ClippingState::*)()) &OpenGl_ClippingState::Update, "Updates current state.");
cls_OpenGl_ClippingState.def("Revert", (void (OpenGl_ClippingState::*)()) &OpenGl_ClippingState::Revert, "Reverts current state.");

// CLASS: OPENGL_OITSTATE
py::class_<OpenGl_OitState, OpenGl_StateInterface> cls_OpenGl_OitState(mod, "OpenGl_OitState", "Defines generic state of order-independent transparency rendering properties.");

// Constructors
cls_OpenGl_OitState.def(py::init<>());

// Methods
cls_OpenGl_OitState.def("Set", (void (OpenGl_OitState::*)(const bool, const float)) &OpenGl_OitState::Set, "Sets the uniform values.", py::arg("theToEnableWrite"), py::arg("theDepthFactor"));
cls_OpenGl_OitState.def("ToEnableWrite", (bool (OpenGl_OitState::*)() const) &OpenGl_OitState::ToEnableWrite, "Returns flag indicating whether writing of output for OIT processing should be enabled/disabled.");
cls_OpenGl_OitState.def("DepthFactor", (float (OpenGl_OitState::*)() const) &OpenGl_OitState::DepthFactor, "Returns factor defining influence of depth component of a fragment to its final coverage coefficient.");

// CLASS: OPENGL_MATERIALSTATE
py::class_<OpenGl_MaterialState, OpenGl_StateInterface> cls_OpenGl_MaterialState(mod, "OpenGl_MaterialState", "Defines generic state of material properties.");

// Constructors
cls_OpenGl_MaterialState.def(py::init<>());

// Methods
cls_OpenGl_MaterialState.def("Set", (void (OpenGl_MaterialState::*)(const OpenGl_Material &, const OpenGl_Material &, const float, const bool, const bool)) &OpenGl_MaterialState::Set, "Sets new material aspect.", py::arg("theFrontMat"), py::arg("theBackMat"), py::arg("theAlphaCutoff"), py::arg("theToDistinguish"), py::arg("theToMapTexture"));
cls_OpenGl_MaterialState.def("FrontMaterial", (const OpenGl_Material & (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::FrontMaterial, "Return front material.");
cls_OpenGl_MaterialState.def("BackMaterial", (const OpenGl_Material & (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::BackMaterial, "Return back material.");
cls_OpenGl_MaterialState.def("AlphaCutoff", (float (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::AlphaCutoff, "Alpha cutoff value.");
cls_OpenGl_MaterialState.def("HasAlphaCutoff", (bool (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::HasAlphaCutoff, "Return TRUE if alpha test should be enabled.");
cls_OpenGl_MaterialState.def("ToDistinguish", (bool (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::ToDistinguish, "Distinguish front/back flag.");
cls_OpenGl_MaterialState.def("ToMapTexture", (bool (OpenGl_MaterialState::*)() const) &OpenGl_MaterialState::ToMapTexture, "Flag for mapping a texture.");

// CLASS: OPENGL_POINTSPRITE
py::class_<OpenGl_PointSprite, opencascade::handle<OpenGl_PointSprite>, OpenGl_Texture> cls_OpenGl_PointSprite(mod, "OpenGl_PointSprite", "Point sprite resource. On modern hardware it will be texture with extra parameters. On ancient hardware sprites will be drawn using bitmaps.");

// Constructors
cls_OpenGl_PointSprite.def(py::init<const TCollection_AsciiString &>(), py::arg("theResourceId"));

// Methods
cls_OpenGl_PointSprite.def_static("get_type_name_", (const char * (*)()) &OpenGl_PointSprite::get_type_name, "None");
cls_OpenGl_PointSprite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_PointSprite::get_type_descriptor, "None");
cls_OpenGl_PointSprite.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_PointSprite::*)() const) &OpenGl_PointSprite::DynamicType, "None");
cls_OpenGl_PointSprite.def("Release", (void (OpenGl_PointSprite::*)(OpenGl_Context *)) &OpenGl_PointSprite::Release, "Destroy object - will release GPU memory if any.", py::arg("theCtx"));
cls_OpenGl_PointSprite.def("IsPointSprite", (bool (OpenGl_PointSprite::*)() const) &OpenGl_PointSprite::IsPointSprite, "Returns TRUE for point sprite texture.");
cls_OpenGl_PointSprite.def("IsDisplayList", (Standard_Boolean (OpenGl_PointSprite::*)() const) &OpenGl_PointSprite::IsDisplayList, "Returns true if this is display list bitmap");
cls_OpenGl_PointSprite.def("DrawBitmap", (void (OpenGl_PointSprite::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_PointSprite::DrawBitmap, "Draw sprite using glBitmap. Please call glRasterPos3fv() before to setup sprite position.", py::arg("theCtx"));
cls_OpenGl_PointSprite.def("SetDisplayList", (void (OpenGl_PointSprite::*)(const opencascade::handle<OpenGl_Context> &, const GLuint)) &OpenGl_PointSprite::SetDisplayList, "Initialize point sprite as display list", py::arg("theCtx"), py::arg("theBitmapList"));

// CLASS: OPENGL_RAYTRACEMATERIAL
/*
py::class_<OpenGl_RaytraceMaterial> cls_OpenGl_RaytraceMaterial(mod, "OpenGl_RaytraceMaterial", "Stores properties of surface material.");

// Constructors
cls_OpenGl_RaytraceMaterial.def(py::init<>());

// Fields
cls_OpenGl_RaytraceMaterial.def_readwrite("Ambient", &OpenGl_RaytraceMaterial::Ambient, "Ambient reflection coefficient");
cls_OpenGl_RaytraceMaterial.def_readwrite("Diffuse", &OpenGl_RaytraceMaterial::Diffuse, "Diffuse reflection coefficient");
cls_OpenGl_RaytraceMaterial.def_readwrite("Specular", &OpenGl_RaytraceMaterial::Specular, "Glossy reflection coefficient");
cls_OpenGl_RaytraceMaterial.def_readwrite("Emission", &OpenGl_RaytraceMaterial::Emission, "Material emission");
cls_OpenGl_RaytraceMaterial.def_readwrite("Reflection", &OpenGl_RaytraceMaterial::Reflection, "Specular reflection coefficient");
cls_OpenGl_RaytraceMaterial.def_readwrite("Refraction", &OpenGl_RaytraceMaterial::Refraction, "Specular refraction coefficient");
cls_OpenGl_RaytraceMaterial.def_readwrite("Transparency", &OpenGl_RaytraceMaterial::Transparency, "Material transparency");
cls_OpenGl_RaytraceMaterial.def_readwrite("TextureTransform", &OpenGl_RaytraceMaterial::TextureTransform, "Texture transformation matrix");
cls_OpenGl_RaytraceMaterial.def_readwrite("BSDF", &OpenGl_RaytraceMaterial::BSDF, "None");

// Methods
cls_OpenGl_RaytraceMaterial.def("Packed", (const Standard_ShortReal * (OpenGl_RaytraceMaterial::*)()) &OpenGl_RaytraceMaterial::Packed, "Returns packed (serialized) representation of material.");
*/

// CLASS: OPENGL_RAYTRACELIGHT
py::class_<OpenGl_RaytraceLight> cls_OpenGl_RaytraceLight(mod, "OpenGl_RaytraceLight", "Stores properties of OpenGL light source.");

// Constructors
// cls_OpenGl_RaytraceLight.def(py::init<>());
// cls_OpenGl_RaytraceLight.def(py::init<const BVH_Vec4f &, const BVH_Vec4f &>(), py::arg("theEmission"), py::arg("thePosition"));

// Fields
cls_OpenGl_RaytraceLight.def_readwrite("Emission", &OpenGl_RaytraceLight::Emission, "Diffuse intensity (in terms of OpenGL)");
cls_OpenGl_RaytraceLight.def_readwrite("Position", &OpenGl_RaytraceLight::Position, "Position of light source (in terms of OpenGL)");

// Methods
cls_OpenGl_RaytraceLight.def("Packed", (const Standard_ShortReal * (OpenGl_RaytraceLight::*)()) &OpenGl_RaytraceLight::Packed, "Returns packed (serialized) representation of light source.");

// TYPEDEF: QUADBVHHANDLE
/*
bind_opencascade::handle<BVH_Tree<float, 3, BVH_QuadTree> >(mod, "QuadBvhHandle", py::module_local(false));
*/

// TYPEDEF: OPENGL_BVHTRIANGULATION3F
bind_BVH_Triangulation<float, 3>(mod, "OpenGl_BVHTriangulation3f", py::module_local(false));

// CLASS: OPENGL_TRIANGLESET
py::class_<OpenGl_TriangleSet, opencascade::handle<OpenGl_TriangleSet>> cls_OpenGl_TriangleSet(mod, "OpenGl_TriangleSet", "Triangulation of single OpenGL primitive array.");

// Constructors
// cls_OpenGl_TriangleSet.def(py::init<const Standard_Size, const opencascade::handle<BVH_Builder<Standard_ShortReal, 3> > &>(), py::arg("theArrayID"), py::arg("theBuilder"));

// Fields
cls_OpenGl_TriangleSet.def_readwrite("Normals", &OpenGl_TriangleSet::Normals, "Array of vertex normals.");
cls_OpenGl_TriangleSet.def_readwrite("TexCrds", &OpenGl_TriangleSet::TexCrds, "Array of texture coords.");

// Methods
cls_OpenGl_TriangleSet.def_static("get_type_name_", (const char * (*)()) &OpenGl_TriangleSet::get_type_name, "None");
cls_OpenGl_TriangleSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_TriangleSet::get_type_descriptor, "None");
cls_OpenGl_TriangleSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::DynamicType, "None");
cls_OpenGl_TriangleSet.def("AssociatedPArrayID", (Standard_Size (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::AssociatedPArrayID, "Returns ID of associated primitive array.");
cls_OpenGl_TriangleSet.def("MaterialIndex", (Standard_Integer (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::MaterialIndex, "Returns material index of triangle set.");
cls_OpenGl_TriangleSet.def("SetMaterialIndex", (void (OpenGl_TriangleSet::*)(Standard_Integer)) &OpenGl_TriangleSet::SetMaterialIndex, "Sets material index for entire triangle set.", py::arg("theMatID"));
cls_OpenGl_TriangleSet.def("Box", (BVH_Set<float, 3>::BVH_BoxNt (OpenGl_TriangleSet::*)() const) &OpenGl_TriangleSet::Box, "Returns AABB of primitive set.");
cls_OpenGl_TriangleSet.def("Center", (Standard_ShortReal (OpenGl_TriangleSet::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_TriangleSet::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
// cls_OpenGl_TriangleSet.def("QuadBVH", (const QuadBvhHandle & (OpenGl_TriangleSet::*)()) &OpenGl_TriangleSet::QuadBVH, "Returns quad BVH (QBVH) tree produced from binary BVH.");

// CLASS: OPENGL_RAYTRACEGEOMETRY
/*
bind_BVH_Geometry<Standard_ShortReal, 3>(mod, "BVH_Geometry_Standard_ShortReal3", py::module_local());

py::class_<OpenGl_RaytraceGeometry, BVH_Geometry<Standard_ShortReal, 3>> cls_OpenGl_RaytraceGeometry(mod, "OpenGl_RaytraceGeometry", "Stores geometry of ray-tracing scene.");

// Constructors
cls_OpenGl_RaytraceGeometry.def(py::init<>());

// Fields
cls_OpenGl_RaytraceGeometry.def_readwrite("Sources", &OpenGl_RaytraceGeometry::Sources, "Array of properties of light sources.");
cls_OpenGl_RaytraceGeometry.def_readwrite("Materials", &OpenGl_RaytraceGeometry::Materials, "Array of 'front' material properties.");
cls_OpenGl_RaytraceGeometry.def_readwrite("Ambient", &OpenGl_RaytraceGeometry::Ambient, "Global ambient from all light sources.");

// Methods
cls_OpenGl_RaytraceGeometry.def("ClearMaterials", (void (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::ClearMaterials, "Clears only ray-tracing materials.");
cls_OpenGl_RaytraceGeometry.def("Clear", (void (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::Clear, "Clears ray-tracing geometry.");
cls_OpenGl_RaytraceGeometry.def("ProcessAcceleration", (Standard_Boolean (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::ProcessAcceleration, "Performs post-processing of high-level scene BVH.");
cls_OpenGl_RaytraceGeometry.def("AccelerationOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::AccelerationOffset, "Returns offset of bottom-level BVH for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("VerticesOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::VerticesOffset, "Returns offset of triangulation vertices for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("ElementsOffset", (Standard_Integer (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::ElementsOffset, "Returns offset of triangulation elements for given leaf node. If the node index is not valid the function returns -1.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("TriangleSet", (OpenGl_TriangleSet * (OpenGl_RaytraceGeometry::*)(Standard_Integer)) &OpenGl_RaytraceGeometry::TriangleSet, "Returns triangulation data for given leaf node. If the node index is not valid the function returns NULL.", py::arg("theNodeIdx"));
cls_OpenGl_RaytraceGeometry.def("QuadBVH", (const QuadBvhHandle & (OpenGl_RaytraceGeometry::*)()) &OpenGl_RaytraceGeometry::QuadBVH, "Returns quad BVH (QBVH) tree produced from binary BVH.");
cls_OpenGl_RaytraceGeometry.def("HasTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::HasTextures, "Checks if scene contains textured objects.");
cls_OpenGl_RaytraceGeometry.def("AddTexture", (Standard_Integer (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Texture> &)) &OpenGl_RaytraceGeometry::AddTexture, "Adds new OpenGL texture to the scene and returns its index.", py::arg("theTexture"));
cls_OpenGl_RaytraceGeometry.def("UpdateTextureHandles", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::UpdateTextureHandles, "Updates unique 64-bit texture handles to use in shaders.", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("AcquireTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::AcquireTextures, "Makes the OpenGL texture handles resident (must be called before using).", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("ReleaseTextures", (Standard_Boolean (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_RaytraceGeometry::ReleaseTextures, "Makes the OpenGL texture handles non-resident (must be called after using).", py::arg("theContext"));
cls_OpenGl_RaytraceGeometry.def("TextureHandles", (const std::vector<GLuint64> & (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::TextureHandles, "Returns array of texture handles.");
cls_OpenGl_RaytraceGeometry.def("ReleaseResources", (void (OpenGl_RaytraceGeometry::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_RaytraceGeometry::ReleaseResources, "Releases OpenGL resources.", py::arg(""));
cls_OpenGl_RaytraceGeometry.def("TopLevelTreeDepth", (Standard_Integer (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::TopLevelTreeDepth, "Returns depth of top-level scene BVH from last build.");
cls_OpenGl_RaytraceGeometry.def("BotLevelTreeDepth", (Standard_Integer (OpenGl_RaytraceGeometry::*)() const) &OpenGl_RaytraceGeometry::BotLevelTreeDepth, "Returns maximum depth of bottom-level scene BVHs from last build.");
*/

// CLASS: OPENGL_SETOFPROGRAMS
py::class_<OpenGl_SetOfPrograms, opencascade::handle<OpenGl_SetOfPrograms>, Standard_Transient> cls_OpenGl_SetOfPrograms(mod, "OpenGl_SetOfPrograms", "Alias to programs array of predefined length");

// Constructors
cls_OpenGl_SetOfPrograms.def(py::init<>());

// Methods
cls_OpenGl_SetOfPrograms.def_static("get_type_name_", (const char * (*)()) &OpenGl_SetOfPrograms::get_type_name, "None");
cls_OpenGl_SetOfPrograms.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_SetOfPrograms::get_type_descriptor, "None");
cls_OpenGl_SetOfPrograms.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_SetOfPrograms::*)() const) &OpenGl_SetOfPrograms::DynamicType, "None");
cls_OpenGl_SetOfPrograms.def("ChangeValue", (opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_SetOfPrograms::*)(Standard_Integer)) &OpenGl_SetOfPrograms::ChangeValue, "Access program by index", py::arg("theProgramBits"));

// CLASS: OPENGL_SETOFSHADERPROGRAMS
py::class_<OpenGl_SetOfShaderPrograms, opencascade::handle<OpenGl_SetOfShaderPrograms>, Standard_Transient> cls_OpenGl_SetOfShaderPrograms(mod, "OpenGl_SetOfShaderPrograms", "Alias to 2D programs array of predefined length");

// Constructors
cls_OpenGl_SetOfShaderPrograms.def(py::init<>());
cls_OpenGl_SetOfShaderPrograms.def(py::init<const opencascade::handle<OpenGl_SetOfPrograms> &>(), py::arg("thePrograms"));

// Methods
cls_OpenGl_SetOfShaderPrograms.def_static("get_type_name_", (const char * (*)()) &OpenGl_SetOfShaderPrograms::get_type_name, "None");
cls_OpenGl_SetOfShaderPrograms.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_SetOfShaderPrograms::get_type_descriptor, "None");
cls_OpenGl_SetOfShaderPrograms.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_SetOfShaderPrograms::*)() const) &OpenGl_SetOfShaderPrograms::DynamicType, "None");
cls_OpenGl_SetOfShaderPrograms.def("ChangeValue", (opencascade::handle<OpenGl_ShaderProgram> & (OpenGl_SetOfShaderPrograms::*)(Graphic3d_TypeOfShadingModel, Standard_Integer)) &OpenGl_SetOfShaderPrograms::ChangeValue, "Access program by index", py::arg("theShadingModel"), py::arg("theProgramBits"));

// TYPEDEF: OPENGL_MAPOFSHADERPROGRAMS
bind_NCollection_DataMap<TCollection_AsciiString, opencascade::handle<OpenGl_SetOfShaderPrograms>, NCollection_DefaultHasher<TCollection_AsciiString> >(mod, "OpenGl_MapOfShaderPrograms", py::module_local(false));

// TYPEDEF: OPENGL_SHADERPROGRAMLIST
bind_NCollection_Sequence<opencascade::handle<OpenGl_ShaderProgram> >(mod, "OpenGl_ShaderProgramList", py::module_local(false));

// CLASS: OPENGL_SHADERMANAGER
py::class_<OpenGl_ShaderManager, opencascade::handle<OpenGl_ShaderManager>, Standard_Transient> cls_OpenGl_ShaderManager(mod, "OpenGl_ShaderManager", "This class is responsible for managing shader programs.");

// Constructors
cls_OpenGl_ShaderManager.def(py::init<OpenGl_Context *>(), py::arg("theContext"));

// Methods
cls_OpenGl_ShaderManager.def_static("get_type_name_", (const char * (*)()) &OpenGl_ShaderManager::get_type_name, "None");
cls_OpenGl_ShaderManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_ShaderManager::get_type_descriptor, "None");
cls_OpenGl_ShaderManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::DynamicType, "None");
cls_OpenGl_ShaderManager.def("clear", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::clear, "Release all resources.");
cls_OpenGl_ShaderManager.def("LocalOrigin", (const gp_XYZ & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::LocalOrigin, "Return local camera transformation.");
cls_OpenGl_ShaderManager.def("SetLocalOrigin", (void (OpenGl_ShaderManager::*)(const gp_XYZ &)) &OpenGl_ShaderManager::SetLocalOrigin, "Setup local camera transformation for compensating float precision issues.", py::arg("theOrigin"));
cls_OpenGl_ShaderManager.def("LocalClippingPlaneW", (Standard_Real (OpenGl_ShaderManager::*)(const Graphic3d_ClipPlane &) const) &OpenGl_ShaderManager::LocalClippingPlaneW, "Return clipping plane W equation value moved considering local camera transformation.", py::arg("thePlane"));
cls_OpenGl_ShaderManager.def("Create", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<Graphic3d_ShaderProgram> &, TCollection_AsciiString &, opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::Create, "Creates new shader program or re-use shared instance.", py::arg("theProxy"), py::arg("theShareKey"), py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("Unregister", (void (OpenGl_ShaderManager::*)(TCollection_AsciiString &, opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::Unregister, "Unregisters specified shader program.", py::arg("theShareKey"), py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ShaderPrograms", (const OpenGl_ShaderProgramList & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ShaderPrograms, "Returns list of registered shader programs.");
cls_OpenGl_ShaderManager.def("IsEmpty", (Standard_Boolean (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::IsEmpty, "Returns true if no program objects are registered in the manager.");
cls_OpenGl_ShaderManager.def("BindFaceProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, Graphic3d_TypeOfShadingModel, Graphic3d_AlphaMode, Standard_Boolean, Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindFaceProgram, "Bind program for filled primitives rendering", py::arg("theTextures"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theEnableEnvMap"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindFaceProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, Graphic3d_TypeOfShadingModel, Graphic3d_AlphaMode, Aspect_InteriorStyle, Standard_Boolean, Standard_Boolean, Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindFaceProgram, "Bind program for filled primitives rendering", py::arg("theTextures"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theInteriorStyle"), py::arg("theHasVertColor"), py::arg("theEnableEnvMap"), py::arg("theEnableMeshEdges"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindLineProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, const Aspect_TypeOfLine, const Graphic3d_TypeOfShadingModel, const Graphic3d_AlphaMode, const Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindLineProgram, "Bind program for line rendering", py::arg("theTextures"), py::arg("theLineType"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindMarkerProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_TextureSet> &, Graphic3d_TypeOfShadingModel, Graphic3d_AlphaMode, Standard_Boolean, const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindMarkerProgram, "Bind program for point rendering", py::arg("theTextures"), py::arg("theShadingModel"), py::arg("theAlphaMode"), py::arg("theHasVertColor"), py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindFontProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &)) &OpenGl_ShaderManager::BindFontProgram, "Bind program for rendering alpha-textured font.", py::arg("theCustomProgram"));
cls_OpenGl_ShaderManager.def("BindOutlineProgram", (Standard_Boolean (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::BindOutlineProgram, "Bind program for outline rendering");
cls_OpenGl_ShaderManager.def("BindFboBlitProgram", (Standard_Boolean (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::BindFboBlitProgram, "Bind program for FBO blit operation.");
cls_OpenGl_ShaderManager.def("BindOitCompositingProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const Standard_Boolean)) &OpenGl_ShaderManager::BindOitCompositingProgram, "Bind program for blended order-independent transparency buffers compositing.", py::arg("theIsMSAAEnabled"));
cls_OpenGl_ShaderManager.def("BindStereoProgram", (Standard_Boolean (OpenGl_ShaderManager::*)(const Graphic3d_StereoMode)) &OpenGl_ShaderManager::BindStereoProgram, "Bind program for rendering stereoscopic image.", py::arg("theStereoMode"));
cls_OpenGl_ShaderManager.def("BindBoundBoxProgram", (Standard_Boolean (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::BindBoundBoxProgram, "Bind program for rendering bounding box.");
cls_OpenGl_ShaderManager.def("BoundBoxVertBuffer", (const opencascade::handle<OpenGl_VertexBuffer> & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::BoundBoxVertBuffer, "Returns bounding box vertex buffer.");
cls_OpenGl_ShaderManager.def("GetBgCubeMapProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::GetBgCubeMapProgram, "Generates shader program to render environment cubemap as background.");
cls_OpenGl_ShaderManager.def("LightSourceState", (const OpenGl_LightSourceState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::LightSourceState, "Returns current state of OCCT light sources.");
cls_OpenGl_ShaderManager.def("UpdateLightSourceStateTo", (void (OpenGl_ShaderManager::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_ShaderManager::UpdateLightSourceStateTo, "Updates state of OCCT light sources.", py::arg("theLights"));
cls_OpenGl_ShaderManager.def("UpdateLightSourceState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateLightSourceState, "Invalidate state of OCCT light sources.");
cls_OpenGl_ShaderManager.def("PushLightSourceState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushLightSourceState, "Pushes current state of OCCT light sources to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushLightSourceState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushLightSourceState, "Pushes current state of OCCT light sources to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ProjectionState", (const OpenGl_ProjectionState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ProjectionState, "Returns current state of OCCT projection transform.");
cls_OpenGl_ShaderManager.def("UpdateProjectionStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateProjectionStateTo, "Updates state of OCCT projection transform.", py::arg("theProjectionMatrix"));
cls_OpenGl_ShaderManager.def("PushProjectionState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushProjectionState, "Pushes current state of OCCT projection transform to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushProjectionState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushProjectionState, "Pushes current state of OCCT projection transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("ModelWorldState", (const OpenGl_ModelWorldState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ModelWorldState, "Returns current state of OCCT model-world transform.");
cls_OpenGl_ShaderManager.def("UpdateModelWorldStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateModelWorldStateTo, "Updates state of OCCT model-world transform.", py::arg("theModelWorldMatrix"));
cls_OpenGl_ShaderManager.def("PushModelWorldState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushModelWorldState, "Pushes current state of OCCT model-world transform to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushModelWorldState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushModelWorldState, "Pushes current state of OCCT model-world transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("WorldViewState", (const OpenGl_WorldViewState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::WorldViewState, "Returns current state of OCCT world-view transform.");
cls_OpenGl_ShaderManager.def("UpdateWorldViewStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Mat4 &)) &OpenGl_ShaderManager::UpdateWorldViewStateTo, "Updates state of OCCT world-view transform.", py::arg("theWorldViewMatrix"));
cls_OpenGl_ShaderManager.def("PushWorldViewState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushWorldViewState, "Pushes current state of OCCT world-view transform to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushWorldViewState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushWorldViewState, "Pushes current state of OCCT world-view transform to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("UpdateClippingState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateClippingState, "Updates state of OCCT clipping planes.");
cls_OpenGl_ShaderManager.def("RevertClippingState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::RevertClippingState, "Reverts state of OCCT clipping planes.");
cls_OpenGl_ShaderManager.def("PushClippingState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushClippingState, "Pushes current state of OCCT clipping planes to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushClippingState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushClippingState, "Pushes current state of OCCT clipping planes to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("MaterialState", (const OpenGl_MaterialState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::MaterialState, "Returns current state of material.");
cls_OpenGl_ShaderManager.def("UpdateMaterialStateTo", (void (OpenGl_ShaderManager::*)(const OpenGl_Material &, const OpenGl_Material &, const float, const bool, const bool)) &OpenGl_ShaderManager::UpdateMaterialStateTo, "Updates state of material.", py::arg("theFrontMat"), py::arg("theBackMat"), py::arg("theAlphaCutoff"), py::arg("theToDistinguish"), py::arg("theToMapTexture"));
cls_OpenGl_ShaderManager.def("UpdateMaterialState", (void (OpenGl_ShaderManager::*)()) &OpenGl_ShaderManager::UpdateMaterialState, "Updates state of material.");
// cls_OpenGl_ShaderManager.def("PushMaterialState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushMaterialState, "Pushes current state of material to specified program (only on state change).", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushMaterialState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushMaterialState, "Pushes current state of material to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("PushInteriorState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &, const opencascade::handle<Graphic3d_Aspects> &) const) &OpenGl_ShaderManager::PushInteriorState, "Setup interior style line edges variables.", py::arg("theProgram"), py::arg("theAspect"));
cls_OpenGl_ShaderManager.def("OitState", (const OpenGl_OitState & (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::OitState, "Returns state of OIT uniforms.");
cls_OpenGl_ShaderManager.def("SetOitState", (void (OpenGl_ShaderManager::*)(const bool, const float)) &OpenGl_ShaderManager::SetOitState, "Set the state of OIT rendering pass (only on state change).", py::arg("theToEnableOitWrite"), py::arg("theDepthFactor"));
cls_OpenGl_ShaderManager.def("PushOitState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushOitState, "Pushes state of OIT uniforms to the specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("pushOitState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::pushOitState, "Pushes state of OIT uniforms to the specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("PushState", (void (OpenGl_ShaderManager::*)(const opencascade::handle<OpenGl_ShaderProgram> &) const) &OpenGl_ShaderManager::PushState, "Pushes current state of OCCT graphics parameters to specified program.", py::arg("theProgram"));
cls_OpenGl_ShaderManager.def("SetContext", (void (OpenGl_ShaderManager::*)(OpenGl_Context *)) &OpenGl_ShaderManager::SetContext, "Overwrites context", py::arg("theCtx"));
cls_OpenGl_ShaderManager.def("IsSameContext", (bool (OpenGl_ShaderManager::*)(OpenGl_Context *) const) &OpenGl_ShaderManager::IsSameContext, "Returns true when provided context is the same as used one by shader manager.", py::arg("theCtx"));
cls_OpenGl_ShaderManager.def("ChooseFaceShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseFaceShadingModel, "Choose Shading Model for filled primitives. Fallbacks to FACET model if there are no normal attributes.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ChooseLineShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseLineShadingModel, "Choose Shading Model for line primitives. Fallbacks to UNLIT model if there are no normal attributes.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ChooseMarkerShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)(Graphic3d_TypeOfShadingModel, bool) const) &OpenGl_ShaderManager::ChooseMarkerShadingModel, "Choose Shading Model for Marker primitives.", py::arg("theCustomModel"), py::arg("theHasNodalNormals"));
cls_OpenGl_ShaderManager.def("ShadingModel", (Graphic3d_TypeOfShadingModel (OpenGl_ShaderManager::*)() const) &OpenGl_ShaderManager::ShadingModel, "Returns default Shading Model.");
cls_OpenGl_ShaderManager.def("SetShadingModel", (void (OpenGl_ShaderManager::*)(const Graphic3d_TypeOfShadingModel)) &OpenGl_ShaderManager::SetShadingModel, "Sets shading model.", py::arg("theModel"));
cls_OpenGl_ShaderManager.def("SetLastView", (void (OpenGl_ShaderManager::*)(const OpenGl_View *)) &OpenGl_ShaderManager::SetLastView, "Sets last view manger used with. Helps to handle matrix states in multi-view configurations.", py::arg("theLastView"));
cls_OpenGl_ShaderManager.def("IsSameView", (bool (OpenGl_ShaderManager::*)(const OpenGl_View *) const) &OpenGl_ShaderManager::IsSameView, "Returns true when provided view is the same as cached one.", py::arg("theView"));

// CLASS: OPENGL_STENCILTEST
/*
py::class_<OpenGl_StencilTest, std::unique_ptr<OpenGl_StencilTest, py::nodelete>, OpenGl_Element> cls_OpenGl_StencilTest(mod, "OpenGl_StencilTest", "None");

// Constructors
cls_OpenGl_StencilTest.def(py::init<>());

// Methods
cls_OpenGl_StencilTest.def("Render", (void (OpenGl_StencilTest::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_StencilTest::Render, "Render primitives to the window", py::arg("theWorkspace"));
cls_OpenGl_StencilTest.def("Release", (void (OpenGl_StencilTest::*)(OpenGl_Context *)) &OpenGl_StencilTest::Release, "None", py::arg("theContext"));
cls_OpenGl_StencilTest.def("SetOptions", (void (OpenGl_StencilTest::*)(const Standard_Boolean)) &OpenGl_StencilTest::SetOptions, "None", py::arg("theIsEnabled"));
// cls_OpenGl_StencilTest.def_static("operator new_", (void * (*)(size_t)) &OpenGl_StencilTest::operator new, "None", py::arg("theSize"));
// cls_OpenGl_StencilTest.def_static("operator delete_", (void (*)(void *)) &OpenGl_StencilTest::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_StencilTest::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_StencilTest.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_StencilTest::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_StencilTest::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_StencilTest.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_StencilTest::operator delete, "None", py::arg(""), py::arg(""));
*/

// TYPEDEF: OPENGL_LISTOFSTRUCTURE
/*
bind_NCollection_List<const OpenGl_Structure *>(mod, "OpenGl_ListOfStructure", py::module_local(false));
*/

// CLASS: OPENGL_STRUCTURE
/*
py::class_<OpenGl_Structure, opencascade::handle<OpenGl_Structure>, Graphic3d_CStructure> cls_OpenGl_Structure(mod, "OpenGl_Structure", "Implementation of low-level graphic structure.");

// Constructors
cls_OpenGl_Structure.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theManager"));

// Methods
cls_OpenGl_Structure.def_static("get_type_name_", (const char * (*)()) &OpenGl_Structure::get_type_name, "None");
cls_OpenGl_Structure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Structure::get_type_descriptor, "None");
cls_OpenGl_Structure.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Structure::*)() const) &OpenGl_Structure::DynamicType, "None");
cls_OpenGl_Structure.def("OnVisibilityChanged", (void (OpenGl_Structure::*)()) &OpenGl_Structure::OnVisibilityChanged, "Setup structure graphic state");
cls_OpenGl_Structure.def("Clear", (void (OpenGl_Structure::*)()) &OpenGl_Structure::Clear, "Clear graphic data");
cls_OpenGl_Structure.def("Connect", (void (OpenGl_Structure::*)(Graphic3d_CStructure &)) &OpenGl_Structure::Connect, "Connect other structure to this one", py::arg("theStructure"));
cls_OpenGl_Structure.def("Disconnect", (void (OpenGl_Structure::*)(Graphic3d_CStructure &)) &OpenGl_Structure::Disconnect, "Disconnect other structure to this one", py::arg("theStructure"));
cls_OpenGl_Structure.def("SetTransformation", (void (OpenGl_Structure::*)(const opencascade::handle<Geom_Transformation> &)) &OpenGl_Structure::SetTransformation, "Synchronize structure transformation", py::arg("theTrsf"));
cls_OpenGl_Structure.def("SetTransformPersistence", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_TransformPers> &)) &OpenGl_Structure::SetTransformPersistence, "Set transformation persistence.", py::arg("theTrsfPers"));
cls_OpenGl_Structure.def("SetZLayer", (void (OpenGl_Structure::*)(const Graphic3d_ZLayerId)) &OpenGl_Structure::SetZLayer, "Set z layer ID to display the structure in specified layer", py::arg("theLayerIndex"));
cls_OpenGl_Structure.def("GraphicHighlight", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_PresentationAttributes> &)) &OpenGl_Structure::GraphicHighlight, "Highlights structure according to the given style and updates corresponding class fields (highlight status and style)", py::arg("theStyle"));
cls_OpenGl_Structure.def("GraphicUnhighlight", (void (OpenGl_Structure::*)()) &OpenGl_Structure::GraphicUnhighlight, "Unighlights structure and updates corresponding class fields (highlight status and style)");
cls_OpenGl_Structure.def("ShadowLink", (opencascade::handle<Graphic3d_CStructure> (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_StructureManager> &) const) &OpenGl_Structure::ShadowLink, "Create shadow link to this structure", py::arg("theManager"));
cls_OpenGl_Structure.def("NewGroup", (opencascade::handle<Graphic3d_Group> (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_Structure> &)) &OpenGl_Structure::NewGroup, "Create new group within this structure", py::arg("theStruct"));
cls_OpenGl_Structure.def("RemoveGroup", (void (OpenGl_Structure::*)(const opencascade::handle<Graphic3d_Group> &)) &OpenGl_Structure::RemoveGroup, "Remove group from this structure", py::arg("theGroup"));
cls_OpenGl_Structure.def("GlDriver", (OpenGl_GraphicDriver * (OpenGl_Structure::*)() const) &OpenGl_Structure::GlDriver, "Access graphic driver");
cls_OpenGl_Structure.def("Clear", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::Clear, "None", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("Render", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Structure::Render, "Renders the structure.", py::arg("theWorkspace"));
cls_OpenGl_Structure.def("Release", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::Release, "Releases structure resources.", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("ReleaseGlResources", (void (OpenGl_Structure::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Structure::ReleaseGlResources, "This method releases GL resources without actual elements destruction. As result structure could be correctly destroyed layer without GL context (after last window was closed for example).", py::arg("theGlCtx"));
cls_OpenGl_Structure.def("InstancedStructure", (const OpenGl_Structure * (OpenGl_Structure::*)() const) &OpenGl_Structure::InstancedStructure, "Returns instanced OpenGL structure.");
cls_OpenGl_Structure.def("ModificationState", (Standard_Size (OpenGl_Structure::*)() const) &OpenGl_Structure::ModificationState, "Returns structure modification state (for ray-tracing).");
cls_OpenGl_Structure.def("ResetModificationState", (void (OpenGl_Structure::*)() const) &OpenGl_Structure::ResetModificationState, "Resets structure modification state (for ray-tracing).");
cls_OpenGl_Structure.def("IsRaytracable", (Standard_Boolean (OpenGl_Structure::*)() const) &OpenGl_Structure::IsRaytracable, "Is the structure ray-tracable (contains ray-tracable elements)?");
cls_OpenGl_Structure.def("updateLayerTransformation", (void (OpenGl_Structure::*)()) &OpenGl_Structure::updateLayerTransformation, "Update render transformation matrix.");
*/

// CLASS: OPENGL_STRUCTURESHADOW
/*
py::class_<OpenGl_StructureShadow, opencascade::handle<OpenGl_StructureShadow>> cls_OpenGl_StructureShadow(mod, "OpenGl_StructureShadow", "Dummy structure which just redirects to groups of another structure.");

// Constructors
cls_OpenGl_StructureShadow.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<OpenGl_Structure> &>(), py::arg("theManager"), py::arg("theStructure"));

// Methods
cls_OpenGl_StructureShadow.def("Connect", (void (OpenGl_StructureShadow::*)(Graphic3d_CStructure &)) &OpenGl_StructureShadow::Connect, "Raise exception on API misuse.", py::arg(""));
cls_OpenGl_StructureShadow.def("Disconnect", (void (OpenGl_StructureShadow::*)(Graphic3d_CStructure &)) &OpenGl_StructureShadow::Disconnect, "Raise exception on API misuse.", py::arg(""));
cls_OpenGl_StructureShadow.def_static("get_type_name_", (const char * (*)()) &OpenGl_StructureShadow::get_type_name, "None");
cls_OpenGl_StructureShadow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_StructureShadow::get_type_descriptor, "None");
cls_OpenGl_StructureShadow.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_StructureShadow::*)() const) &OpenGl_StructureShadow::DynamicType, "None");
*/

// CLASS: OPENGL_TILESAMPLER
py::class_<OpenGl_TileSampler> cls_OpenGl_TileSampler(mod, "OpenGl_TileSampler", "Tool object used for sampling screen tiles according to estimated pixel variance (used in path tracing engine). To improve GPU thread coherency, rendering window is split into pixel blocks or tiles. The important feature of this approach is that it is possible to keep the same number of tiles for any screen resolution (e.g. 256 tiles can be used for both 512 x 512 window and 1920 x 1080 window). So, a smaller number of tiles allows to increase interactivity (FPS), but at the cost of higher per-frame variance ('noise'). On the contrary a larger number of tiles decrease interactivity, but leads to lower per-frame variance. Note that the total time needed to produce final final image is the same for both cases.");

// Constructors
cls_OpenGl_TileSampler.def(py::init<>());

// Methods
cls_OpenGl_TileSampler.def("TileSize", (Graphic3d_Vec2i (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::TileSize, "Size of individual tile in pixels.");
cls_OpenGl_TileSampler.def("VarianceScaleFactor", (float (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::VarianceScaleFactor, "Scale factor for quantization of visual error (float) into signed integer.");
cls_OpenGl_TileSampler.def("NbTilesX", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTilesX, "Returns number of tiles in X dimension.");
cls_OpenGl_TileSampler.def("NbTilesY", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTilesY, "Returns number of tiles in Y dimension.");
cls_OpenGl_TileSampler.def("NbTiles", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbTiles, "Returns total number of tiles in viewport.");
cls_OpenGl_TileSampler.def("ViewSize", (const Graphic3d_Vec2i & (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::ViewSize, "Returns ray-tracing viewport.");
cls_OpenGl_TileSampler.def("NbOffsetTiles", (Graphic3d_Vec2i (OpenGl_TileSampler::*)(bool) const) &OpenGl_TileSampler::NbOffsetTiles, "Number of tiles within offsets texture.", py::arg("theAdaptive"));
cls_OpenGl_TileSampler.def("NbOffsetTilesMax", (Graphic3d_Vec2i (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::NbOffsetTilesMax, "Maximum number of tiles within offsets texture.");
cls_OpenGl_TileSampler.def("OffsetTilesViewport", (Graphic3d_Vec2i (OpenGl_TileSampler::*)(bool) const) &OpenGl_TileSampler::OffsetTilesViewport, "Viewport for rendering using offsets texture.", py::arg("theAdaptive"));
cls_OpenGl_TileSampler.def("OffsetTilesViewportMax", (Graphic3d_Vec2i (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::OffsetTilesViewportMax, "Maximum viewport for rendering using offsets texture.");
cls_OpenGl_TileSampler.def("MaxTileSamples", (int (OpenGl_TileSampler::*)() const) &OpenGl_TileSampler::MaxTileSamples, "Return maximum number of samples per tile.");
cls_OpenGl_TileSampler.def("SetSize", (void (OpenGl_TileSampler::*)(const Graphic3d_RenderingParams &, const Graphic3d_Vec2i &)) &OpenGl_TileSampler::SetSize, "Specifies size of ray-tracing viewport and recomputes tile size.", py::arg("theParams"), py::arg("theSize"));
cls_OpenGl_TileSampler.def("GrabVarianceMap", (void (OpenGl_TileSampler::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_Texture> &)) &OpenGl_TileSampler::GrabVarianceMap, "Fetches current error estimation from the GPU and builds 2D discrete distribution for tile sampling.", py::arg("theContext"), py::arg("theTexture"));
cls_OpenGl_TileSampler.def("Reset", (void (OpenGl_TileSampler::*)()) &OpenGl_TileSampler::Reset, "Resets (restart) tile sampler to initial state.");
cls_OpenGl_TileSampler.def("UploadSamples", (bool (OpenGl_TileSampler::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_Texture> &, const bool)) &OpenGl_TileSampler::UploadSamples, "Uploads tile samples to the given OpenGL texture.", py::arg("theContext"), py::arg("theSamplesTexture"), py::arg("theAdaptive"));
cls_OpenGl_TileSampler.def("UploadOffsets", (bool (OpenGl_TileSampler::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<OpenGl_Texture> &, const bool)) &OpenGl_TileSampler::UploadOffsets, "Uploads offsets of sampled tiles to the given OpenGL texture.", py::arg("theContext"), py::arg("theOffsetsTexture"), py::arg("theAdaptive"));

// CLASS: OPENGL_VERTEXBUFFERCOMPAT
py::class_<OpenGl_VertexBufferCompat, opencascade::handle<OpenGl_VertexBufferCompat>, OpenGl_VertexBuffer> cls_OpenGl_VertexBufferCompat(mod, "OpenGl_VertexBufferCompat", "Compatibility layer for old OpenGL without VBO. Make sure to pass pointer from GetDataOffset() instead of NULL. Method GetDataOffset() returns pointer to real data in this class (while base class OpenGl_VertexBuffer always return NULL).");

// Constructors
cls_OpenGl_VertexBufferCompat.def(py::init<>());

// Methods
cls_OpenGl_VertexBufferCompat.def("IsVirtual", (bool (OpenGl_VertexBufferCompat::*)() const) &OpenGl_VertexBufferCompat::IsVirtual, "Return TRUE.");
cls_OpenGl_VertexBufferCompat.def("Create", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_VertexBufferCompat::Create, "Creates VBO name (id) if not yet generated. Data should be initialized by another method.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Release", (void (OpenGl_VertexBufferCompat::*)(OpenGl_Context *)) &OpenGl_VertexBufferCompat::Release, "Destroy object - will release memory if any.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Bind", (void (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBufferCompat::Bind, "Bind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("Unbind", (void (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &) const) &OpenGl_VertexBufferCompat::Unbind, "Unbind this VBO.", py::arg("theGlCtx"));
cls_OpenGl_VertexBufferCompat.def("initLink", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<NCollection_Buffer> &, const GLuint, const GLsizei, const GLenum)) &OpenGl_VertexBufferCompat::initLink, "Initialize buffer with existing data. Data will NOT be copied by this method!", py::arg("theData"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theDataType"));
cls_OpenGl_VertexBufferCompat.def("init", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &, const GLuint, const GLsizei, const void *, const GLenum, const GLsizei)) &OpenGl_VertexBufferCompat::init, "Initialize buffer with new data (data will be copied).", py::arg("theGlCtx"), py::arg("theComponentsNb"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"), py::arg("theStride"));
cls_OpenGl_VertexBufferCompat.def("subData", (bool (OpenGl_VertexBufferCompat::*)(const opencascade::handle<OpenGl_Context> &, const GLsizei, const GLsizei, const void *, const GLenum)) &OpenGl_VertexBufferCompat::subData, "Update part of the buffer with new data.", py::arg("theGlCtx"), py::arg("theElemFrom"), py::arg("theElemsNb"), py::arg("theData"), py::arg("theDataType"));
cls_OpenGl_VertexBufferCompat.def_static("get_type_name_", (const char * (*)()) &OpenGl_VertexBufferCompat::get_type_name, "None");
cls_OpenGl_VertexBufferCompat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_VertexBufferCompat::get_type_descriptor, "None");
cls_OpenGl_VertexBufferCompat.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_VertexBufferCompat::*)() const) &OpenGl_VertexBufferCompat::DynamicType, "None");

// CLASS: OPENGL_VIEW
/*
py::class_<OpenGl_View, opencascade::handle<OpenGl_View>, Graphic3d_CView> cls_OpenGl_View(mod, "OpenGl_View", "Implementation of OpenGl view.");

// Constructors
cls_OpenGl_View.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<OpenGl_GraphicDriver> &, const opencascade::handle<OpenGl_Caps> &, OpenGl_StateCounter *>(), py::arg("theMgr"), py::arg("theDriver"), py::arg("theCaps"), py::arg("theCounter"));

// Methods
cls_OpenGl_View.def("ReleaseGlResources", (void (OpenGl_View::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_View::ReleaseGlResources, "None", py::arg("theCtx"));
cls_OpenGl_View.def("Remove", (void (OpenGl_View::*)()) &OpenGl_View::Remove, "Deletes and erases the view.");
cls_OpenGl_View.def("SetImmediateModeDrawToFront", (Standard_Boolean (OpenGl_View::*)(const Standard_Boolean)) &OpenGl_View::SetImmediateModeDrawToFront, "Returns previous mode.", py::arg("theDrawToFrontBuffer"));
cls_OpenGl_View.def("SetWindow", (void (OpenGl_View::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &OpenGl_View::SetWindow, "Creates and maps rendering window to the view.", py::arg("theWindow"), py::arg("theContext"));
cls_OpenGl_View.def("Window", (opencascade::handle<Aspect_Window> (OpenGl_View::*)() const) &OpenGl_View::Window, "Returns window associated with the view.");
cls_OpenGl_View.def("IsDefined", (Standard_Boolean (OpenGl_View::*)() const) &OpenGl_View::IsDefined, "Returns True if the window associated to the view is defined.");
cls_OpenGl_View.def("Resized", (void (OpenGl_View::*)()) &OpenGl_View::Resized, "Handle changing size of the rendering window.");
cls_OpenGl_View.def("Redraw", (void (OpenGl_View::*)()) &OpenGl_View::Redraw, "Redraw content of the view.");
cls_OpenGl_View.def("RedrawImmediate", (void (OpenGl_View::*)()) &OpenGl_View::RedrawImmediate, "Redraw immediate content of the view.");
cls_OpenGl_View.def("Invalidate", (void (OpenGl_View::*)()) &OpenGl_View::Invalidate, "Marks BVH tree for given priority list as dirty and marks primitive set for rebuild.");
cls_OpenGl_View.def("IsInvalidated", (Standard_Boolean (OpenGl_View::*)()) &OpenGl_View::IsInvalidated, "Return true if view content cache has been invalidated.");
cls_OpenGl_View.def("BufferDump", (Standard_Boolean (OpenGl_View::*)(Image_PixMap &, const Graphic3d_BufferType &)) &OpenGl_View::BufferDump, "Dump active rendering buffer into specified memory buffer. In Ray-Tracing allow to get a raw HDR buffer using Graphic3d_BT_RGB_RayTraceHdrLeft buffer type, only Left view will be dumped ignoring stereoscopic parameter.", py::arg("theImage"), py::arg("theBufferType"));
cls_OpenGl_View.def("InvalidateBVHData", (void (OpenGl_View::*)(const Graphic3d_ZLayerId)) &OpenGl_View::InvalidateBVHData, "Marks BVH tree and the set of BVH primitives of correspondent priority list with id theLayerId as outdated.", py::arg("theLayerId"));
cls_OpenGl_View.def("InsertLayerBefore", (void (OpenGl_View::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_View::InsertLayerBefore, "Add a layer to the view.", py::arg("theLayerId"), py::arg("theSettings"), py::arg("theLayerAfter"));
cls_OpenGl_View.def("InsertLayerAfter", (void (OpenGl_View::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &OpenGl_View::InsertLayerAfter, "Add a layer to the view.", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerBefore"));
cls_OpenGl_View.def("RemoveZLayer", (void (OpenGl_View::*)(const Graphic3d_ZLayerId)) &OpenGl_View::RemoveZLayer, "Remove a z layer with the given ID.", py::arg("theLayerId"));
cls_OpenGl_View.def("SetZLayerSettings", (void (OpenGl_View::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_View::SetZLayerSettings, "Sets the settings for a single Z layer of specified view.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_View.def("ZLayerMax", (Standard_Integer (OpenGl_View::*)() const) &OpenGl_View::ZLayerMax, "Returns the maximum Z layer ID. First layer ID is Graphic3d_ZLayerId_Default, last ID is ZLayerMax().");
cls_OpenGl_View.def("Layers", (const NCollection_List<opencascade::handle<Graphic3d_Layer> > & (OpenGl_View::*)() const) &OpenGl_View::Layers, "Returns the list of layers.");
cls_OpenGl_View.def("Layer", (opencascade::handle<Graphic3d_Layer> (OpenGl_View::*)(const Graphic3d_ZLayerId) const) &OpenGl_View::Layer, "Returns layer with given ID or NULL if undefined.", py::arg("theLayerId"));
cls_OpenGl_View.def("MinMaxValues", (Bnd_Box (OpenGl_View::*)(const Standard_Boolean) const) &OpenGl_View::MinMaxValues, "Returns the bounding box of all structures displayed in the view. If theToIncludeAuxiliary is TRUE, then the boundary box also includes minimum and maximum limits of graphical elements forming parts of infinite and other auxiliary structures.", py::arg("theToIncludeAuxiliary"));
cls_OpenGl_View.def("FBO", (opencascade::handle<Standard_Transient> (OpenGl_View::*)() const) &OpenGl_View::FBO, "Returns pointer to an assigned framebuffer object.");
cls_OpenGl_View.def("SetFBO", (void (OpenGl_View::*)(const opencascade::handle<Standard_Transient> &)) &OpenGl_View::SetFBO, "Sets framebuffer object for offscreen rendering.", py::arg("theFbo"));
cls_OpenGl_View.def("FBOCreate", (opencascade::handle<Standard_Transient> (OpenGl_View::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_View::FBOCreate, "Generate offscreen FBO in the graphic library. If not supported on hardware returns NULL.", py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_View.def("FBORelease", (void (OpenGl_View::*)(opencascade::handle<Standard_Transient> &)) &OpenGl_View::FBORelease, "Remove offscreen FBO from the graphic library", py::arg("theFbo"));
cls_OpenGl_View.def("FBOGetDimensions", [](OpenGl_View &self, const opencascade::handle<Standard_Transient> & theFbo, Standard_Integer & theWidth, Standard_Integer & theHeight, Standard_Integer & theWidthMax, Standard_Integer & theHeightMax){ self.FBOGetDimensions(theFbo, theWidth, theHeight, theWidthMax, theHeightMax); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theWidth, theHeight, theWidthMax, theHeightMax); }, "Read offscreen FBO configuration.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theWidthMax"), py::arg("theHeightMax"));
cls_OpenGl_View.def("FBOChangeViewport", (void (OpenGl_View::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer)) &OpenGl_View::FBOChangeViewport, "Change offscreen FBO viewport.", py::arg("theFbo"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_View.def("GradientBackground", (Aspect_GradientBackground (OpenGl_View::*)() const) &OpenGl_View::GradientBackground, "Returns gradient background fill colors.");
cls_OpenGl_View.def("SetGradientBackground", (void (OpenGl_View::*)(const Aspect_GradientBackground &)) &OpenGl_View::SetGradientBackground, "Sets gradient background fill colors.", py::arg("theBackground"));
cls_OpenGl_View.def("BackgroundImage", (TCollection_AsciiString (OpenGl_View::*)()) &OpenGl_View::BackgroundImage, "Returns background image texture file path.");
cls_OpenGl_View.def("SetBackgroundImage", (void (OpenGl_View::*)(const TCollection_AsciiString &)) &OpenGl_View::SetBackgroundImage, "Sets background image texture file path.", py::arg("theFilePath"));
cls_OpenGl_View.def("BackgroundImageStyle", (Aspect_FillMethod (OpenGl_View::*)() const) &OpenGl_View::BackgroundImageStyle, "Returns background image fill style.");
cls_OpenGl_View.def("SetBackgroundImageStyle", (void (OpenGl_View::*)(const Aspect_FillMethod)) &OpenGl_View::SetBackgroundImageStyle, "Sets background image fill style.", py::arg("theFillStyle"));
cls_OpenGl_View.def("BackgroundCubeMap", (opencascade::handle<Graphic3d_CubeMap> (OpenGl_View::*)() const) &OpenGl_View::BackgroundCubeMap, "Returns cubemap being set last time on background.");
cls_OpenGl_View.def("SetBackgroundCubeMap", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_CubeMap> &)) &OpenGl_View::SetBackgroundCubeMap, "Sets environment cubemap as background.", py::arg("theCubeMap"));
cls_OpenGl_View.def("TextureEnv", (opencascade::handle<Graphic3d_TextureEnv> (OpenGl_View::*)() const) &OpenGl_View::TextureEnv, "Returns environment texture set for the view.");
cls_OpenGl_View.def("SetTextureEnv", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_TextureEnv> &)) &OpenGl_View::SetTextureEnv, "Sets environment texture for the view.", py::arg("theTextureEnv"));
cls_OpenGl_View.def("BackfacingModel", (Graphic3d_TypeOfBackfacingModel (OpenGl_View::*)() const) &OpenGl_View::BackfacingModel, "Return backfacing model used for the view.");
cls_OpenGl_View.def("SetBackfacingModel", (void (OpenGl_View::*)(const Graphic3d_TypeOfBackfacingModel)) &OpenGl_View::SetBackfacingModel, "Sets backfacing model for the view.", py::arg("theModel"));
cls_OpenGl_View.def("LocalOrigin", (const gp_XYZ & (OpenGl_View::*)() const) &OpenGl_View::LocalOrigin, "Returns local camera origin currently set for rendering, might be modified during rendering.");
cls_OpenGl_View.def("SetLocalOrigin", (void (OpenGl_View::*)(const gp_XYZ &)) &OpenGl_View::SetLocalOrigin, "Setup local camera origin currently set for rendering.", py::arg("theOrigin"));
cls_OpenGl_View.def("Lights", (const opencascade::handle<Graphic3d_LightSet> & (OpenGl_View::*)() const) &OpenGl_View::Lights, "Returns list of lights of the view.");
cls_OpenGl_View.def("SetLights", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_LightSet> &)) &OpenGl_View::SetLights, "Sets list of lights for the view.", py::arg("theLights"));
cls_OpenGl_View.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (OpenGl_View::*)() const) &OpenGl_View::ClipPlanes, "Returns list of clip planes set for the view.");
cls_OpenGl_View.def("SetClipPlanes", (void (OpenGl_View::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &OpenGl_View::SetClipPlanes, "Sets list of clip planes for the view.", py::arg("thePlanes"));
cls_OpenGl_View.def("DiagnosticInformation", (void (OpenGl_View::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &OpenGl_View::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));
cls_OpenGl_View.def("StatisticInformation", (TCollection_AsciiString (OpenGl_View::*)() const) &OpenGl_View::StatisticInformation, "Returns string with statistic performance info.");
cls_OpenGl_View.def("StatisticInformation", (void (OpenGl_View::*)(TColStd_IndexedDataMapOfStringString &) const) &OpenGl_View::StatisticInformation, "Fills in the dictionary with statistic performance info.", py::arg("theDict"));
cls_OpenGl_View.def("BackgroundColor", (const Quantity_ColorRGBA & (OpenGl_View::*)() const) &OpenGl_View::BackgroundColor, "Returns background color.");
cls_OpenGl_View.def("ChangeGraduatedTrihedron", (OpenGl_GraduatedTrihedron & (OpenGl_View::*)()) &OpenGl_View::ChangeGraduatedTrihedron, "Change graduated trihedron.");
cls_OpenGl_View.def("SetTextureEnv", (void (OpenGl_View::*)(const opencascade::handle<OpenGl_Context> &, const opencascade::handle<Graphic3d_TextureEnv> &)) &OpenGl_View::SetTextureEnv, "None", py::arg("theCtx"), py::arg("theTexture"));
cls_OpenGl_View.def("SetBackgroundTextureStyle", (void (OpenGl_View::*)(const Aspect_FillMethod)) &OpenGl_View::SetBackgroundTextureStyle, "None", py::arg("FillStyle"));
cls_OpenGl_View.def("SetBackgroundGradient", (void (OpenGl_View::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &OpenGl_View::SetBackgroundGradient, "None", py::arg("AColor1"), py::arg("AColor2"), py::arg("AType"));
cls_OpenGl_View.def("SetBackgroundGradientType", (void (OpenGl_View::*)(const Aspect_GradientFillMethod)) &OpenGl_View::SetBackgroundGradientType, "None", py::arg("AType"));
cls_OpenGl_View.def("LayerList", (const OpenGl_LayerList & (OpenGl_View::*)() const) &OpenGl_View::LayerList, "Returns list of OpenGL Z-layers.");
cls_OpenGl_View.def("GlWindow", (const opencascade::handle<OpenGl_Window> & (OpenGl_View::*)() const) &OpenGl_View::GlWindow, "Returns OpenGL window implementation.");
cls_OpenGl_View.def("GlTextureEnv", (const opencascade::handle<OpenGl_TextureSet> & (OpenGl_View::*)() const) &OpenGl_View::GlTextureEnv, "Returns OpenGL environment map.");
cls_OpenGl_View.def("BVHTreeSelector", (const Graphic3d_CullingTool & (OpenGl_View::*)() const) &OpenGl_View::BVHTreeSelector, "Returns selector for BVH tree, providing a possibility to store information about current view volume and to detect which objects are overlapping it.");
cls_OpenGl_View.def("HasImmediateStructures", (bool (OpenGl_View::*)() const) &OpenGl_View::HasImmediateStructures, "Returns true if there are immediate structures to display");
cls_OpenGl_View.def("GraduatedTrihedronDisplay", (void (OpenGl_View::*)(const Graphic3d_GraduatedTrihedron &)) &OpenGl_View::GraduatedTrihedronDisplay, "Displays Graduated Trihedron.", py::arg("theTrihedronData"));
cls_OpenGl_View.def("GraduatedTrihedronErase", (void (OpenGl_View::*)()) &OpenGl_View::GraduatedTrihedronErase, "Erases Graduated Trihedron.");
cls_OpenGl_View.def("GraduatedTrihedronMinMaxValues", (void (OpenGl_View::*)(const Graphic3d_Vec3, const Graphic3d_Vec3)) &OpenGl_View::GraduatedTrihedronMinMaxValues, "Sets minimum and maximum points of scene bounding box for Graduated Trihedron stored in graphic view object.", py::arg("theMin"), py::arg("theMax"));
// cls_OpenGl_View.def_static("operator new_", (void * (*)(size_t)) &OpenGl_View::operator new, "None", py::arg("theSize"));
// cls_OpenGl_View.def_static("operator delete_", (void (*)(void *)) &OpenGl_View::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_View::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_View.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_View::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_View::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_View.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_View::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_View.def_static("get_type_name_", (const char * (*)()) &OpenGl_View::get_type_name, "None");
cls_OpenGl_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_View::get_type_descriptor, "None");
cls_OpenGl_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_View::*)() const) &OpenGl_View::DynamicType, "None");
*/


}