#pragma once

/* Default arena size depending on platform. */

#if (defined(SKY))
#define rwRESOURCESDEFAULTARENASIZE (8 << 20)
#elif (defined(_XBOX))
#define rwRESOURCESDEFAULTARENASIZE (8 << 20)
#elif (defined(DOLPHIN))
#define rwRESOURCESDEFAULTARENASIZE (4 << 20)
#elif (defined(D3D8_DRVMODEL_H))
#define rwRESOURCESDEFAULTARENASIZE (4 << 20)
#elif (defined(OPENGL_DRVMODEL_H))
#if (defined(macintosh))
#define rwRESOURCESDEFAULTARENASIZE (2 << 20)
#else
#define rwRESOURCESDEFAULTARENASIZE (16 << 20)
#endif
#else
#define rwRESOURCESDEFAULTARENASIZE (16 << 20)
#endif

/* Debug */
#define RwObjectGetType(o) (((const RwObject *)(o))->type)

#define rwObjectSetType(o, t) (((RwObject *)(o))->type) = (RwUInt8)(t)

/* Sub type */
#define rwObjectGetSubType(o) (((const RwObject *)(o))->subType)
#define rwObjectSetSubType(o, t) (((RwObject *)(o))->subType) = (RwUInt8)(t)

/* Flags */
#define rwObjectGetFlags(o) (((const RwObject *)(o))->flags)
#define rwObjectSetFlags(o, f) (((RwObject *)(o))->flags) = (RwUInt8)(f)
#define rwObjectTestFlags(o, f) ((((const RwObject *)(o))->flags) & (RwUInt8)(f))

/* Private flags */
#define rwObjectGetPrivateFlags(c) (((const RwObject *)(c))->privateFlags)
#define rwObjectSetPrivateFlags(c,f) (((RwObject *)(c))->privateFlags) = (RwUInt8)(f)
#define rwObjectTestPrivateFlags(c,flag) ((((const RwObject *)(c))->privateFlags) & (RwUInt8)(flag))

/* Hierarchy */
#define rwObjectGetParent(object) (((const RwObject *)(object))->parent)
#define rwObjectSetParent(c,p) (((RwObject *)(c))->parent) = (void *)(p)

#define RpClumpGetFrameMacro(_clump) ((RwFrame *) rwObjectGetParent(_clump))
#define RpClumpGetFrame(_clump) RpClumpGetFrameMacro(_clump)


#define rwID_DATABASE 0x64617462     /* datb */

#define MAKECHUNKID(vendorID, chunkID) (((vendorID & 0xFFFFFF) << 8) | (chunkID & 0xFF))
#define GETOBJECTID(chunkID) (chunkID & 0xFF)
#define GETVENDORID(chunkID) ((chunkID >> 8) & 0xFFFFFF)



// Enums //

/***
 *** These are the vendor IDs.  A customer must reserve a vendor ID in order
 *** to be able to write toolkits (this prevents clashes between toolkits).
 *** We reserve some for our own use as shown below.  These are all 24 bit.
 ***
 *** IMPORTANT NOTE: DO NOT UNDER ANY CIRCUMSTANCES CHANGE THESE VALUES. IF
 ***                 YOU ARE ADDING A NEW ONE, APPEND IT!
 ***
 *** They must all be unique.
 ***/

enum RwPluginVendor
{
	rwVENDORID_CORE = 0x000000L,
	rwVENDORID_CRITERIONTK = 0x000001L,
	rwVENDORID_REDLINERACER = 0x000002L,
	rwVENDORID_CSLRD = 0x000003L,
	rwVENDORID_CRITERIONINT = 0x000004L,
	rwVENDORID_CRITERIONWORLD = 0x000005L,
	rwVENDORID_BETA = 0x000006L,
	rwVENDORID_CRITERIONRM = 0x000007L,
	rwVENDORID_CRITERIONRWA = 0x000008L, /* RenderWare Audio */
};


enum RsEvent
{
#ifdef RWSPLASH
	rsDISPLAYSPLASH,
#endif
	rsCAMERASIZE,
	rsCOMMANDLINE,
	rsFILELOAD,
	rsINITDEBUG,
	rsINPUTDEVICEATTACH,
	rsLEFTBUTTONDOWN,
	rsLEFTBUTTONUP,
	rsMOUSEMOVE,
	rsMOUSEWHEELMOVE,
	rsPLUGINATTACH,
	rsREGISTERIMAGELOADER,
	rsRIGHTBUTTONDOWN,
	rsRIGHTBUTTONUP,
	rsRWINITIALIZE,
	rsRWTERMINATE,
	rsSELECTDEVICE,
	rsINITIALIZE,
	rsTERMINATE,
	rsIDLE,
	rsKEYDOWN,
	rsKEYUP,
	rsQUITAPP,
	rsPADBUTTONDOWN,
	rsPADBUTTONUP,
	rsPADANALOGUELEFT,
	rsPADANALOGUELEFTRESET,
	rsPADANALOGUERIGHT,
	rsPADANALOGUERIGHTRESET,
	rsPREINITCOMMANDLINE,
	rsACTIVATE
};


enum RwPrimitiveType
{
	rwPRIMTYPENAPRIMTYPE = 0x0,
	rwPRIMTYPELINELIST = 0x1,
	rwPRIMTYPEPOLYLINE = 0x2,
	rwPRIMTYPETRILIST = 0x3,
	rwPRIMTYPETRISTRIP = 0x4,
	rwPRIMTYPETRIFAN = 0x5,
	rwPRIMTYPEPOINTLIST = 0x6,
};


enum RwRenderState
{
	rwRENDERSTATENARENDERSTATE = 0,
	rwRENDERSTATETEXTURERASTER = 1,
	rwRENDERSTATETEXTUREADDRESS = 2,
	rwRENDERSTATETEXTUREADDRESSU = 3,
	rwRENDERSTATETEXTUREADDRESSV = 4,
	rwRENDERSTATETEXTUREPERSPECTIVE = 5,
	rwRENDERSTATEZTESTENABLE = 6,
	rwRENDERSTATESHADEMODE = 7,
	rwRENDERSTATEZWRITEENABLE = 8,
	rwRENDERSTATETEXTUREFILTER = 9,
	rwRENDERSTATESRCBLEND = 10,
	rwRENDERSTATEDESTBLEND = 11,
	rwRENDERSTATEVERTEXALPHAENABLE = 12,
	rwRENDERSTATEBORDERCOLOR = 13,
	rwRENDERSTATEFOGENABLE = 14,
	rwRENDERSTATEFOGCOLOR = 15,
	rwRENDERSTATEFOGTYPE = 16,
	rwRENDERSTATEFOGDENSITY = 17,
	rwRENDERSTATECULLMODE = 20,
	rwRENDERSTATESTENCILENABLE = 21,
	rwRENDERSTATESTENCILFAIL = 22,
	rwRENDERSTATESTENCILZFAIL = 23,
	rwRENDERSTATESTENCILPASS = 24,
	rwRENDERSTATESTENCILFUNCTION = 25,
	rwRENDERSTATESTENCILFUNCTIONREF = 26,
	rwRENDERSTATESTENCILFUNCTIONMASK = 27,
	rwRENDERSTATESTENCILFUNCTIONWRITEMASK = 28,
};

enum RwRasterType
{
	rwRASTERTYPENORMAL = 0,
	rwRASTERTYPEZBUFFER = 1,
	rwRASTERTYPECAMERA = 2,
	rwRASTERTYPETEXTURE = 4,
	rwRASTERTYPECAMERATEXTURE = 5,
	rwRASTERTYPEMASK = 7,
	rwRASTERDONTALLOCATE = 128,
};

enum RwMatrixFlag
{
	rwMATRIXINTERNALIDENTITY = 0x20000,
};

enum RxNodeDefEditable
{
	rxNODEDEFCONST = 0x0,
	rxNODEDEFEDITABLE = 0x1,
};

enum RxClusterForcePresent
{
	rxCLALLOWABSENT = 0x0,
	rxCLFORCEPRESENT = 0x1,
};

enum RxClusterValid
{
	rxCLVALID_NOCHANGE = 0x0,
	rxCLVALID_VALID = 0x1,
	rxCLVALID_INVALID = 0x2,
};

enum RxClusterValidityReq
{
	rxCLREQ_DONTWANT = 0x0,
	rxCLREQ_REQUIRED = 0x1,
	rxCLREQ_OPTIONAL = 0x2,
};

enum rxEmbeddedPacketState
{
	rxPKST_PACKETLESS = 0x0,
	rxPKST_UNUSED = 0x1,
	rxPKST_INUSE = 0x2,
	rxPKST_PENDING = 0x3,
};

enum RwEngineInitFlag
{
	rwENGINEINITFREELISTS = 0x0,
	rwENGINEINITNOFREELISTS = 0x1,
};

enum RwEngineStatus
{
	rwENGINESTATUSIDLE = 0x0,
	rwENGINESTATUSINITED = 0x1,
	rwENGINESTATUSOPENED = 0x2,
	rwENGINESTATUSSTARTED = 0x3,
};

enum RwOpCombineType
{
	rwCOMBINEREPLACE = 0x0,
	rwCOMBINEPRECONCA = 0x1,
	rwCOMBINEPOSTCONCAT = 0x2,
};

enum RwStreamType
{
	rwNASTREAM = 0,     /**<Invalid stream type */
	rwSTREAMFILE,       /**<File */
	rwSTREAMFILENAME,   /**<File name */
	rwSTREAMMEMORY,     /**<Memory*/
	rwSTREAMCUSTOM,     /**<Custom */
};

enum RwStreamAccessType
{
	rwNASTREAMACCESS = 0,   /**<Invalid stream access */
	rwSTREAMREAD,           /**<Read */
	rwSTREAMWRITE,          /**<Write */
	rwSTREAMAPPEND,         /**<Append */
};


enum RwBlendFunction
{
	rwBLENDNABLEND = 0,
	rwBLENDZERO,            /**<(0,    0,    0,    0   ) */
	rwBLENDONE,             /**<(1,    1,    1,    1   ) */
	rwBLENDSRCCOLOR,        /**<(Rs,   Gs,   Bs,   As  ) */
	rwBLENDINVSRCCOLOR,     /**<(1-Rs, 1-Gs, 1-Bs, 1-As) */
	rwBLENDSRCALPHA,        /**<(As,   As,   As,   As  ) */
	rwBLENDINVSRCALPHA,     /**<(1-As, 1-As, 1-As, 1-As) */
	rwBLENDDESTALPHA,       /**<(Ad,   Ad,   Ad,   Ad  ) */
	rwBLENDINVDESTALPHA,    /**<(1-Ad, 1-Ad, 1-Ad, 1-Ad) */
	rwBLENDDESTCOLOR,       /**<(Rd,   Gd,   Bd,   Ad  ) */
	rwBLENDINVDESTCOLOR,    /**<(1-Rd, 1-Gd, 1-Bd, 1-Ad) */
	rwBLENDSRCALPHASAT,     /**<(f,    f,    f,    1   )  f = min (As, 1-Ad) */
};


enum RwCameraProjection
{
	rwNACAMERAPROJECTION = 0x0,
	rwPERSPECTIVE = 0x1,
	rwPARALLEL = 0x2
};


enum RwCorePluginID
{
	rwID_NAOBJECT = 0x00,
	rwID_STRUCT = 0x01,
	rwID_STRING = 0x02,
	rwID_EXTENSION = 0x03,

	rwID_CAMERA = 0x05,
	/**< RwCamera chunk. See \ref RwCameraStreamRead */

	rwID_TEXTURE = 0x06,
	/**< RwTexture chunk. See \ref RwTextureStreamRead */

	rwID_MATERIAL = 0x07,
	/**< RpMaterial chunk. See \ref RpMaterialStreamRead. */

	rwID_MATLIST = 0x08,
	rwID_ATOMICSECT = 0x09,
	rwID_PLANESECT = 0x0A,

	rwID_WORLD = 0x0B,
	/**< RpWorld chunk. See \ref RpWorldStreamRead. */

	rwID_SPLINE = 0x0C,
	/**< RpSpline chunk. See \ref RpSplineStreamRead */

	rwID_MATRIX = 0x0D,
	/**< RwMatrix chunk. See \ref RwMatrixStreamRead */

	rwID_FRAMELIST = 0x0E,

	rwID_GEOMETRY = 0x0F,
	/**< RpGeometry chunk. See \ref RpGeometryStreamRead. */

	rwID_CLUMP = 0x10,
	/**< RpClump chunk. See \ref RpClumpStreamRead. */

	rwID_LIGHT = 0x12,
	/**< RpLight chunk. See \ref RpLightStreamRead. */

	rwID_UNICODESTRING = 0x13,

	rwID_ATOMIC = 0x14,
	/**< RpAtomic chunk. See \ref RpAtomicStreamRead */

	rwID_TEXTURENATIVE = 0x15,

	rwID_TEXDICTIONARY = 0x16,
	/**< RwTexDictionary - platform specific texture dictionary.
	 * See \ref RwTexDictionaryStreamRead. */

	rwID_ANIMDATABASE = 0x17,

	rwID_IMAGE = 0x18,
	/**< RwImage chunk. See \ref RwImageStreamRead */

	rwID_SKINANIMATION = 0x19,
	rwID_GEOMETRYLIST = 0x1A,

	rwID_HANIMANIMATION = 0x1B,
	/**< RtAnimAnimation chunk. See \ref RtAnimAnimationStreamRead. */

	rwID_TEAM = 0x1C,
	/**< \ref RpTeam chunk. See \ref RpTeamStreamRead */
	rwID_CROWD = 0x1D,

	rwID_DMORPHANIMATION = 0x1E,
	/**< RpDMorphAnimation - delta morph animation chunk. See \ref RpDMorphAnimationStreamRead */

	rwID_RIGHTTORENDER = 0x1f,

	rwID_MTEFFECTNATIVE = 0x20,
	/**< \if xbox RpMTEffect - multi-texture effect chunk. See \ref RpMTEffectStreamRead \endif */
	/**< \if gcn  RpMTEffect - multi-texture effect chunk. See \ref RpMTEffectStreamRead \endif */

	rwID_MTEFFECTDICT = 0x21,
	/**< \if xbox RpMTEffectDict - multi-texture effect dictionary chunk. See \ref RpMTEffectDictStreamRead \endif */
	/**< \if gcn  RpMTEffectDict - multi-texture effect dictionary chunk. See \ref RpMTEffectDictStreamRead \endif */

	rwID_TEAMDICTIONARY = 0x22,
	/**< \ref RpTeamDictionary chunk. See \ref RpTeamDictionaryStreamRead */

	rwID_PITEXDICTIONARY = 0x23,
	/**< RwTexDictionary - platform independent texture dictionary. See \ref RtPITexDictionaryStreamRead. */

	rwID_TOC = 0x24,
	/**< RtTOC chunk. See \ref RtTOCStreamRead */

	rwID_PRTSTDGLOBALDATA = 0x25,
	/**< RpPrtStdEmitterClass, RpPrtStdParticleClass and RpPrtStdPropertyTable chunks.
	 *   See \ref RpPrtStdEClassStreamRead, \ref RpPrtStdPClassStreamRead
	 *   \ref RpPrtStdPropTabStreamRead and \ref RpPrtStdGlobalDataStreamRead */

	rwID_ALTPIPE = 0x26,
	rwID_PIPEDS = 0x27,
	rwID_PATCHMESH = 0x28,
	/**< RpPatchMesh chunk. See \ref RpPatchMeshStreamRead */

	/* Insert before MAX and increment MAX */
	rwID_COREPLUGINIDMAX = 0x29,
};


enum RwCullMode
{
	rwCULLMODENACULLMODE = 0,

	rwCULLMODECULLNONE,
	/**<Both front and back-facing triangles are drawn. */
	rwCULLMODECULLBACK,
	/**<Only front-facing triangles are drawn */
	rwCULLMODECULLFRONT
	/**<Only back-facing triangles are drawn */
};


enum RwFrustumTestResult
{
	rwSPHEREOUTSIDE = 0,    /**<Outside the frustum */
	rwSPHEREBOUNDARY = 1,   /**<On the boundary of the frustum */
	rwSPHEREINSIDE = 2     /**<Inside the frustum */
};
// ~Enums~ //


// Incomplete Types //
typedef void* Rt2dPath;
typedef void* _rt2dFontDictionaryNode;
// Incomplete Types //


// Struct Forward Declarations //
struct RwV3d;
struct sAngle;
struct RwRGBAReal;
struct RwD3D82DVertexFields;
union RwD3D82DVertexAlignmentOverlay;
struct RwD3D82DVertex;
struct RwLLLink;
struct RwLinkList;
struct RwFileFunctions;
struct RwStringFunctions;
struct RwMemoryFunctions;
struct RwFreeList;
struct RwMetrics;
struct RwDevice;
struct RwFrame;
struct RwRaster;
struct RwGlobals;
struct RsGlobalStruct;
struct RxPipelineNode;
struct RxPipelineNodeParam;
struct RxNodeDefinition;
struct RxPipelineCluster;
struct RxIoSpec;
struct RxClusterRef;
struct RxClusterDefinition;
struct RxNodeMethods;
struct RxHeap;
struct rxHeapBlockHeader;
struct rxHeapFreeBlock;
struct rxHeapSuperBlockDescriptor;
struct RwTexture;
struct RwTexDictionary;
struct RwObject;
struct RxPipelineNodeTopSortData;
struct RxCluster;
struct RxPacket;
struct RxPipelineRequiresCluster;
struct RxPipeline;
struct RwSurfaceProperties;
struct RpMaterial;
struct RpMaterialList;
struct RpTriangle;
struct RwTexCoords;
struct RpMeshHeader;
struct RwResEntry;
struct RwSphere;
struct RpMorphTarget;
struct RpGeometry;
struct RwRGBA;
struct RwSList;
struct _rt2dShapeRep;
struct RwObjectHasFrame;
struct RpClump;
struct RpInterpolator;
struct RpAtomic;
struct _rt2dShape;
struct _rt2dScene;
struct Rt2dBBox;
struct _rt2dPickRegion;
struct RwV2d;
struct rt2dShadeParameters;
struct Rt2dBrush;
struct _rt2dObjectString;
union _rt2dObjectdata;
struct Rt2dObject;
struct RwStreamMemory;
union RwStreamFile;
struct RwStreamCustom;
union RwStreamUnion;
struct RwStream;
struct RwChunkHeaderInfo;
struct _RxObjSpace3DVertex;
struct RwCamera;
struct Rt2dMaestro;
// Struct Forward Declarations //


// Typedefs //
typedef char RwChar;
typedef unsigned __int8 RwUInt8;
typedef __int16 RwInt16;
typedef unsigned __int16 RwUInt16;
typedef int RwInt32;
typedef unsigned int RwUInt32;
typedef RwInt32 RwBool;
typedef float RwReal;

typedef RwUInt16 RxVertexIndex;
typedef RxVertexIndex RwImVertexIndex;
typedef RwD3D82DVertex RwIm2DVertex;




typedef int (*vecSprintfFunc)(RwChar* buffer, const RwChar* format, ...);
typedef int(__cdecl* vecVsprintfFunc)(RwChar* buffer, const RwChar* format, va_list argptr);
typedef RwChar* (__cdecl* vecStrcpyFunc)(RwChar* dest, const RwChar* srce);
typedef RwChar* (__cdecl* vecStrncpyFunc)(RwChar* dest, const RwChar* srce, size_t size);
typedef RwChar* (__cdecl* vecStrcatFunc)(RwChar* dest, const RwChar* srce);
typedef RwChar* (__cdecl* vecStrncatFunc)(RwChar* dest, const RwChar* srce, size_t size);
typedef RwChar* (__cdecl* vecStrrchrFunc)(const RwChar* string, int findThis);
typedef RwChar* (__cdecl* vecStrchrFunc)(const RwChar* string, int findThis);
typedef RwChar* (__cdecl* vecStrstrFunc)(const RwChar* string, const RwChar* findThis);
typedef int(__cdecl* vecStrcmpFunc)(const RwChar* string1, const RwChar* string2);
typedef int(__cdecl* vecStrncmpFunc)(const RwChar* string1, const RwChar* string2, size_t max_size);
typedef int(__cdecl* vecStricmpFunc)(const RwChar* string1, const RwChar* string2);
typedef size_t(__cdecl* vecStrlenFunc)(const RwChar* string);
typedef RwChar* (__cdecl* vecStruprFunc)(RwChar* string);
typedef RwChar* (__cdecl* vecStrlwrFunc)(RwChar* string);
typedef RwChar* (__cdecl* vecStrtokFunc)(RwChar* string, const RwChar* delimit);
typedef int (*vecSscanfFunc)(const RwChar* buffer, const RwChar* format, ...);

typedef RwBool(__cdecl* RwStandardFunc)(void* pOut, void* pInOut, RwInt32 nI);
typedef void* (__cdecl* RwMemoryAllocFn)(RwFreeList* fl);
typedef RwFreeList* (__cdecl* RwMemoryFreeFn)(RwFreeList* fl, void* pData);
typedef RwBool(__cdecl* RwRenderStateSetFunction)(RwRenderState nState, void* pParam);
typedef RwBool(__cdecl* RwRenderStateGetFunction)(RwRenderState nState, void* pParam);
typedef RwBool(__cdecl* RwIm2DRenderLineFunction)(RwIm2DVertex* vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2);
typedef RwBool(__cdecl* RwIm2DRenderTriangleFunction)(RwIm2DVertex* vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2, RwInt32 vert3);
typedef RwBool(__cdecl* RwIm2DRenderPrimitiveFunction)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices);
typedef RwBool(__cdecl* RwIm2DRenderIndexedPrimitiveFunction)(RwPrimitiveType primType, RwIm2DVertex* vertices, RwInt32 numVertices, RwImVertexIndex* indices, RwInt32 numIndices);
typedef RwBool(__cdecl* RwIm3DRenderLineFunction)(RwInt32 vert1, RwInt32 vert2);
typedef RwBool(__cdecl* RwIm3DRenderTriangleFunction)(RwInt32 vert1, RwInt32 vert2, RwInt32 vert3);
typedef RwBool(__cdecl* RwIm3DRenderPrimitiveFunction)(RwPrimitiveType primType);
typedef RwBool(__cdecl* RwIm3DRenderIndexedPrimitiveFunction)(RwPrimitiveType primtype, RwImVertexIndex* indices, RwInt32 numIndices);

typedef RwBool(__cdecl* RwSystemFunc)(RwInt32 nOption, void* pOut, void* pInOut, RwInt32 nIn);
typedef RwBool(__cdecl* rwFnFexist)(const RwChar* name);
typedef void* (__cdecl* rwFnFopen)(const RwChar* name, const RwChar* access);
typedef int(__cdecl* rwFnFclose)(void* fptr);
typedef size_t(__cdecl* rwFnFread)(void* addr, size_t size, size_t count, void* fptr);
typedef size_t(__cdecl* rwFnFwrite)(const void* addr, size_t size, size_t count, void* fptr);
typedef RwChar* (__cdecl* rwFnFgets)(RwChar* buffer, int maxLen, void* fptr);
typedef int(__cdecl* rwFnFputs)(const RwChar* buffer, void* fptr);
typedef int(__cdecl* rwFnFeof)(void* fptr);
typedef int(__cdecl* rwFnFseek)(void* fptr, int offset, int origin);
typedef int(__cdecl* rwFnFflush)(void* fptr);
typedef int(__cdecl* rwFnFtell)(void* fptr);

typedef RwBool(__cdecl* RxNodeBodyFn)(RxPipelineNode* self, const RxPipelineNodeParam* params);
typedef RwBool(__cdecl* RxNodeInitFn)(RxNodeDefinition* self);
typedef void(__cdecl* RxNodeTermFn)(RxNodeDefinition* self);
typedef RwBool(__cdecl* RxPipelineNodeInitFn)(RxPipelineNode* self);
typedef void(__cdecl* RxPipelineNodeTermFn)(RxPipelineNode* self);
typedef RwBool(__cdecl* RxPipelineNodeConfigFn)(RxPipelineNode* self, RxPipeline* pipeline);
typedef RwUInt32(__cdecl* RxConfigMsgHandlerFn)(RxPipelineNode* self, RwUInt32 msg, RwUInt32 intparam, void* ptrparam);
typedef void* rxReq;
typedef void(__cdecl* RwResEntryDestroyNotify)(RwResEntry* resEntry);
typedef RwObjectHasFrame* (__cdecl* RwObjectHasFrameSyncFunction)(RwObjectHasFrame* object);
typedef RpClump* (__cdecl* RpClumpCallBack)(RpClump* clump, void* data);
typedef RpAtomic* (__cdecl* RpAtomicCallBackRender)(RpAtomic* atomic);

/* Custom stream function pointer types */
typedef RwBool(*rwCustomStreamFnClose) (void* data);
typedef RwUInt32(*rwCustomStreamFnRead) (void* data, void* buffer, RwUInt32 length);
typedef RwBool(*rwCustomStreamFnWrite) (void* data, const void* buffer, RwUInt32 length);
typedef RwBool(*rwCustomStreamFnSkip) (void* data, RwUInt32 offset);
typedef RwCamera* (__cdecl* RwCameraBeginUpdateFunc)(RwCamera* camera);
typedef RwCamera* (__cdecl* RwCameraEndUpdateFunc)(RwCamera* camera);
typedef _RxObjSpace3DVertex RxObjSpace3DVertex;
typedef RxObjSpace3DVertex RxObjSpace3DLitVertex;
typedef RxObjSpace3DLitVertex RwIm3DVertex;
// ~Typedefs~ //


// Struct Definitions //
struct RwV3d
{
	RwReal x;
	RwReal y;
	RwReal z;
};

struct sAngle
{
	int x;
	int y;
	int z;
};

struct sRealAngle3
{
	RwReal x;
	RwReal y;
	RwReal z;


	sRealAngle3* operator=(sAngle const& angle);
};

struct RwRGBA
{
	RwUInt8 red;
	RwUInt8 green;
	RwUInt8 blue;
	RwUInt8 alpha;
};

struct RwRGBAReal
{
	RwReal red;
	RwReal green;
	RwReal blue;
	RwReal alpha;
};


struct RwD3D82DVertexFields
{
	RwV3d scrVertex;
	RwReal camVertex_z;
	RwReal u;
	RwReal v;
	RwReal recipZ;
	RwReal pad1;
	RwRGBAReal color;
	RwV3d objNormal;
	RwReal pad2;
};


union RwD3D82DVertexAlignmentOverlay
{
	RwD3D82DVertexFields els;
	unsigned int qWords[16]; //unsigned __int128 qWords[4]; - No 128-bit data type
};


struct RwD3D82DVertex
{
	RwD3D82DVertexAlignmentOverlay u;
};


struct RwLLLink
{
	RwLLLink* next;
	RwLLLink* prev;
};


struct RwLinkList
{
	RwLLLink link;
};


struct RwFileFunctions
{
	rwFnFexist rwfexist;
	rwFnFopen rwfopen;
	rwFnFclose rwfclose;
	rwFnFread rwfread;
	rwFnFwrite rwfwrite;
	rwFnFgets rwfgets;
	rwFnFputs rwfputs;
	rwFnFeof rwfeof;
	rwFnFseek rwfseek;
	rwFnFflush rwfflush;
	rwFnFtell rwftell;
};


struct RwStringFunctions
{
	vecSprintfFunc vecSprintf;
	vecVsprintfFunc vecVsprintf;
	vecStrcpyFunc vecStrcpy;
	vecStrncpyFunc vecStrncpy;
	vecStrcatFunc vecStrcat;
	vecStrncatFunc vecStrncat;
	vecStrrchrFunc vecStrrchr;
	vecStrchrFunc vecStrchr;
	vecStrstrFunc vecStrstr;
	vecStrcmpFunc vecStrcmp;
	vecStrncmpFunc vecStrncmp;
	vecStricmpFunc vecStricmp;
	vecStrlenFunc vecStrlen;
	vecStruprFunc vecStrupr;
	vecStrlwrFunc vecStrlwr;
	vecStrtokFunc vecStrtok;
	vecSscanfFunc vecSscanf;
};


struct RwMemoryFunctions
{
	void* (__cdecl* rwmalloc)(size_t size);
	void(__cdecl* rwfree)(void* mem);
	void* (__cdecl* rwrealloc)(void* mem, size_t newSize);
	void* (__cdecl* rwcalloc)(size_t numObj, size_t sizeObj);
};


struct RwFreeList
{
	RwUInt32 entrySize;
	RwUInt32 entriesPerBlock;
	RwUInt32 heapSize;
	RwUInt32 alignment;
	RwLinkList blockList;
	RwUInt32 flags;
	RwLLLink link;
};


struct RwObject
{
	RwUInt8 type;
	RwUInt8 subType;
	RwUInt8 flags;
	RwUInt8 privateFlags;
	void* parent;
};


struct RwMatrix
{
	RwV3d right;
	RwMatrixFlag flags;
	RwV3d up;
	RwUInt32 pad1;
	RwV3d at;
	RwUInt32 pad2;
	RwV3d pos;
	RwUInt32 pad3;
};


struct RwFrame
{
	RwObject object;
	RwLLLink inDirtyListLink;
	RwMatrix modelling;
	RwMatrix ltm;
	RwLinkList objectList;
	struct RwFrame* child;
	struct RwFrame* next;
	struct RwFrame* root;
};


struct RwMetrics
{
	RwUInt32 numTriangles;
	RwUInt32 numProcTriangles;
	RwUInt32 numVertices;
	RwUInt32 numTextureUploads;
	RwUInt32 sizeTextureUploads;
	RwUInt32 numResourceAllocs;
	void* devSpecificMetrics;
};


struct RwDevice
{
	RwReal gammaCorrection;
	RwSystemFunc fpSystem;
	RwReal zBufferNear;
	RwReal zBufferFar;
	RwRenderStateSetFunction fpRenderStateSet;
	RwRenderStateGetFunction fpRenderStateGet;
	RwIm2DRenderLineFunction fpIm2DRenderLine;
	RwIm2DRenderTriangleFunction fpIm2DRenderTriangle;
	RwIm2DRenderPrimitiveFunction fpIm2DRenderPrimitive;
	RwIm2DRenderIndexedPrimitiveFunction fpIm2DRenderIndexedPrimitive;
	RwIm3DRenderLineFunction fpIm3DRenderLine;
	RwIm3DRenderTriangleFunction fpIm3DRenderTriangle;
	RwIm3DRenderPrimitiveFunction fpIm3DRenderPrimitive;
	RwIm3DRenderIndexedPrimitiveFunction fpIm3DRenderIndexedPrimitive;
};


struct RwRaster
{
	RwRaster* parent;
	RwUInt8* cpPixels;
	RwUInt8* palette;
	RwInt32 width;
	RwInt32 height;
	RwInt32 depth;
	RwInt32 stride;
	RwInt16 nOffsetX;
	RwInt16 nOffsetY;
	RwUInt8 cType;
	RwRasterType cFlags;
	RwUInt8 privateFlags;
	RwUInt8 cFormat;
	RwUInt8* originalPixels;
	RwInt32 originalWidth;
	RwInt32 originalHeight;
	int originalStride;
};


struct RwGlobals
{
	void* curCamera;
	void* curWorld;
	RwUInt16 renderFrame;
	RwUInt16 lightFrame;
	RwUInt16 pad[2];
	RwDevice dOpenDevice;
	RwStandardFunc stdFunc[29];
	RwLinkList dirtyFrameList;
	RwFileFunctions fileFuncs;
	RwStringFunctions stringFuncs;
	RwMemoryFunctions memoryFuncs;
	RwMemoryAllocFn memoryAlloc;
	RwMemoryFreeFn memoryFree;
	RwMetrics* metrics;
	RwEngineStatus engineStatus;
	RwUInt32 resArenaInitSize;
};


struct RsGlobalStruct
{
	LPCSTR lpWindowName;
	int windowWidth;
	int windowHeight;
	int field_C;
	int hasConfirmedExit;
	HWND* HWND;
	int field_18;
	int field_1C;
	int(__cdecl* field_20)(int, int);
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	void* field_3C;
};


struct RwTexDictionary
{
	RwObject object;
	RwLinkList texturesInDict;
	RwLLLink lInInstance;
};


struct RwTexture
{
	RwRaster* raster;
	RwTexDictionary* dict;
	RwLLLink lInDictionary;
	RwChar name[32];
	RwChar mask[32];
	RwUInt32 filterAddressing;
	RwInt32 refCount;
};


struct rxHeapSuperBlockDescriptor
{
	void* start;
	RwUInt32 size;
	rxHeapSuperBlockDescriptor* next;
};


struct rxHeapFreeBlock
{
	RwUInt32 size;
	rxHeapBlockHeader* ptr;
};


struct rxHeapBlockHeader
{
	rxHeapBlockHeader* prev;
	rxHeapBlockHeader* next;
	RwUInt32 size;
	rxHeapFreeBlock* freeEntry;
	RwUInt32 pad[4];
};


struct RxHeap
{
	RwUInt32 superBlockSize;
	rxHeapSuperBlockDescriptor* head;
	rxHeapBlockHeader* headBlock;
	rxHeapFreeBlock* freeBlocks;
	RwUInt32 entriesAlloced;
	RwUInt32 entriesUsed;
	RwBool dirty;
};


struct RxPipelineNodeParam
{
	void* dataParam;
	RxHeap* heap;
};


struct RxNodeMethods
{
	RxNodeBodyFn nodeBody;
	RxNodeInitFn nodeInit;
	RxNodeTermFn nodeTerm;
	RxPipelineNodeInitFn pipelineNodeInit;
	RxPipelineNodeTermFn pipelineNodeTerm;
	RxPipelineNodeConfigFn pipelineNodeConfig;
	RxConfigMsgHandlerFn configMsgHandler;
};


struct RxClusterDefinition
{
	RwChar* name;
	RwUInt32 defaultStride;
	RwUInt32 defaultAttributes;
	const RwChar* attributeSet;
};


struct RxClusterRef
{
	RxClusterDefinition* clusterDef;
	RxClusterForcePresent forcePresent;
	RwUInt32 reserved;
};


struct RxOutputSpec
{
	RwChar* name;
	RxClusterValid* outputClusters;
	RxClusterValid allOtherClusters;
};


struct RxIoSpec
{
	RwUInt32 numClustersOfInterest;
	RxClusterRef* clustersOfInterest;
	RxClusterValidityReq* inputRequirements;
	RwUInt32 numOutputs;
	RxOutputSpec* outputs;
};


struct RxNodeDefinition
{
	RwChar* name;
	RxNodeMethods nodeMethods;
	RxIoSpec io;
	RwUInt32 pipelineNodePrivateDataSize;
	RxNodeDefEditable editable;
	RwInt32 InputPipesCnt;
};


struct RxPipelineCluster
{
	RxClusterDefinition* clusterRef;
	RwUInt32 creationAttributes;
};


struct RxPipelineNodeTopSortData
{
	RwUInt32 numIns;
	RwUInt32 numInsVisited;
	rxReq* req;
};


struct RxPipelineNode
{
	RxNodeDefinition* nodeDef;
	RwUInt32 numOutputs;
	RwUInt32* outputs;
	RxPipelineCluster** slotClusterRefs;
	RwUInt32* slotsContinue;
	void* privateData;
	RwUInt32* inputToClusterSlot;
	RxPipelineNodeTopSortData* topSortData;
	void* initializationData;
	RwUInt32 initializationDataSize;
};


struct RxCluster
{
	RwUInt16 flags;
	RwUInt16 stride;
	void* data;
	void* currentData;
	RwUInt32 numAlloced;
	RwUInt32 numUsed;
	RxPipelineCluster* clusterRef;
	RwUInt32 attributes;
	RwUInt32 pad[1];
};


struct RxPacket
{
	RwUInt16 flags;
	RwUInt16 numClusters;
	RxPipeline* pipeline;
	RwUInt32* inputToClusterSlot;
	RwUInt32* slotsContinue;
	RxPipelineCluster** slotClusterRefs;
	RwUInt32 pad[3];
	RxCluster clusters[1];
};


struct RxPipelineRequiresCluster
{
	RxClusterDefinition* clusterDef;
	RxClusterValidityReq rqdOrOpt;
	RwUInt32 slotIndex;
};


struct RxPipeline
{
	RwBool locked;
	RwUInt32 numNodes;
	RxPipelineNode* nodes;
	RwUInt32 packetNumClusterSlots;
	rxEmbeddedPacketState embeddedPacketState;
	RxPacket* embeddedPacket;
	RwUInt32 numInputRequirements;
	RxPipelineRequiresCluster* inputRequirements;
	void* superBlock;
	RwUInt32 superBlockSize;
	RwUInt32 entryPoint;
	RwUInt32 pluginId;
	RwUInt32 pluginData;
};


struct RwSurfaceProperties
{
	RwReal ambient;
	RwReal specular;
	RwReal diffuse;
};


struct RpMaterial
{
	RwTexture* texture;
	RwRGBA color;
	RxPipeline* pipeline;
	RwSurfaceProperties surfaceProps;
	RwInt16 refCount;
	RwInt16 pad;
};


struct RpMaterialList
{
	RpMaterial** materials;
	RwInt32 numMaterials;
	RwInt32 space;
};


struct RpTriangle
{
	RwUInt16 vertIndex[3];
	RwInt16 matIndex;
};


struct RwTexCoords
{
	RwReal u;
	RwReal v;
};


struct RpMeshHeader
{
	RwUInt32 flags;
	RwUInt16 numMeshes;
	RwUInt16 serialNum;
	RwUInt32 totalIndicesInMesh;
	RwUInt32 firstMeshOffset;
};


struct RwResEntry
{
	RwLLLink link;
	RwInt32 size;
	void* owner;
	RwResEntry** ownerRef;
	RwResEntryDestroyNotify destroyNotify;
};


struct RwSphere
{
	RwV3d position;
	float radius;
};


struct RpMorphTarget
{
	RpGeometry* parentGeom;
	RwSphere boundingSphere;
	RwV3d* verts;
	RwV3d* normals;
};


struct RpGeometry
{
	RwObject object;
	RwUInt32 flags;
	RwUInt16 lockedSinceLastInst;
	RwInt16 refCount;
	RwInt32 numTriangles;
	RwInt32 numVertices;
	RwInt32 numMorphTargets;
	RwInt32 numTexCoordSets;
	RpMaterialList matList;
	RpTriangle* triangles;
	RwRGBA* preLitLum;
	RwTexCoords* texCoords[8];
	RpMeshHeader* mesh;
	RwResEntry* repEntry;
	RpMorphTarget* morphTarget;
};


struct RwSList
{
	RwUInt8* listElements;
	RwInt32 numElementsFilled;
	RwInt32 numElementsAlloced;
	RwInt32 entrySize;
};


struct _rt2dShapeRep
{
	RwSList* nodes;         /* individual stroked/filled regions of the shape */
	RwUInt32 refCount;      /* number of shapes referencing this rep */
	RpGeometry* geometry;      /* Shareable geometry */
};


struct RwObjectHasFrame
{
	RwObject object;
	RwLLLink lFrame;
	RwObjectHasFrameSyncFunction sync;
};


struct RpClump
{
	RwObject object;
	RwLinkList atomicList;
	RwLinkList lightList;
	RwLinkList cameraList;
	RwLLLink inWorldLink;
	RpClumpCallBack callback;
};


struct RpInterpolator
{
	RwInt32 flags;
	RwInt16 startMorphTarget;
	RwInt16 endMorphTarget;
	RwReal time;
	RwReal recipTime;
	RwReal position;
};


struct RpAtomic
{
	RwObjectHasFrame object;
	RwResEntry* repEntry;
	RpGeometry* geometry;
	RwSphere boundingSphere;
	RwSphere worldBoundingSphere;
	RpClump* clump;
	RwLLLink inClumpLink;
	RpAtomicCallBackRender renderCallBack;
	RpInterpolator interpolator;
	RwUInt16 renderFrame;
	RwUInt16 pad;
	RwLinkList llWorldSectorsInAtomic;
	RxPipeline* pipeline;
};


struct _RxObjSpace3DVertex
{
	RwV3d          objVertex;              /* Object space vertex */
	union
	{
		RwRGBA     preLitColor;            /* Vertex pre-lighting values */
		RwRGBA     color;                  /* Immediate mode vertex color */
	}
	c;
	RwV3d          objNormal;              /* Object space normal */
	RwReal         u, v;                   /* Vertex tex coords */
};


struct _rt2dShape
{
	_rt2dShapeRep* rep;
	RwRGBA* colorCache;    /* Shape's color cache */
	RpAtomic* atomic;        /* Atomic repn */
};


struct _rt2dScene
{
	RwSList* objects;       /* collection of objects in scene */
	RwInt32 objectCount;   /* number of objects  */
	RwSList* depths;        /* depths for depthsort */
	RwBool isDirtyDepths; /* depthsort needs updating */
};


struct Rt2dBBox
{
	RwReal x;  /**< x-coordinate of lower-left corner */
	RwReal y;  /**< y-coordinate of lower-left corner */
	RwReal w;  /**< Width */
	RwReal h;  /**< Height */
};


struct _rt2dPickRegion
{
	Rt2dPath* path;    /* path that defines region for testing */
	Rt2dBBox bbox;     /* bounding box of path */
	RwMatrix transformation;
	/* ivnert transformation used to place the pick region */
};


struct RwV2d
{
	RwReal x;
	RwReal y;
};


struct rt2dShadeParameters
{
	RwRGBAReal col;    /* col */
	RwV2d uv;     /* uv */
};


struct Rt2dBrush
{
	rt2dShadeParameters top;
	rt2dShadeParameters dtop;
	rt2dShadeParameters bottom;
	rt2dShadeParameters dbottom;
	RwRGBA colorCache;
	RwInt32 flag;
	RwTexture* texture;
	RpMaterial* material;
	RwReal halfwidth;
	RwInt32 refCount;
};


struct _rt2dObjectString
{
	RwChar* textString; /* Text string to be rendered */
	Rt2dBrush* brush;      /* Brush to be used to draw text */
	RwInt32 maxLength;   /* Maximum string length before reallocation, excluding null */
	RwReal height;      /* Font rendering Height */
	_rt2dFontDictionaryNode* font; /* Dictionary node identifying font to be used */
};


union _rt2dObjectdata
{
	_rt2dShape shape;
	_rt2dScene scene;
	_rt2dPickRegion pickRegion;
	_rt2dObjectString objectString;
};


struct Rt2dObject
{
	RwInt32 type;            /* tag identifying type of object */
	RwInt32 depth;           /* z-order of object under parent */
	RwInt32 flag;            /* ... */
	RwMatrix MTM;             /* local transformation matrix for object */
	RwMatrix LTM;             /* global transformation matrix for object */
	RwRGBAReal colorMult;       /* color multiply applied to object  */
	RwRGBAReal colorOffs;       /* color offset applied to object    */
	_rt2dObjectdata data;
};


struct Rt2dMaestro
{
	int flagsMaybe;
	char gap4[4];
	RwSList* animations;
	const char** stringLabels;
	void* buttons;
	char gap14[4];
	void* messageList;
	void* byteBucketMaybe;
	void* messageQueue;
	Rt2dObject* scene;
	int(__cdecl* callbackMaybe)(int, int);
	float float_2C;
	float float_30;
	char gap34[4];
	RwV3d camRelated;
	int field_44;
	Rt2dBBox bbox;
	void* stateTransTable;
};


struct RwStreamMemory
{
	RwUInt32 position; /* Current 'memory' position 0 is first byte */
	RwUInt32 nSize;  /* Space allocated currently */
	RwUInt8* memBlock; /* Current memory block pointer */
};


union RwStreamFile
{
	void* fpFile;               /**< file pointer */
	const void* constfpFile;    /**< const file pointer */
};


struct RwStreamCustom
{
	rwCustomStreamFnClose sfnclose;
	rwCustomStreamFnRead sfnread;
	rwCustomStreamFnWrite sfnwrite;
	rwCustomStreamFnSkip sfnskip;
	void* data;
};


union RwStreamUnion
{
	RwStreamMemory memory; /**< memory */
	RwStreamFile file; /**< file */
	RwStreamCustom custom; /**< custom */
};


struct RwStream
{
	RwStreamType type;
	RwStreamAccessType accessType;
	RwInt32 position;
	RwStreamUnion Type;
	RwBool rwOwned;
};


struct RwBBox
{
	RwV3d sup;
	RwV3d inf;
};


struct RwPlane
{
	RwV3d normal;
	RwReal distance;
};


struct RwFrustumPlane
{
	RwPlane plane;
	RwUInt8 closestX;
	RwUInt8 closestY;
	RwUInt8 closestZ;
	RwUInt8 pad;
};


struct RwCamera
{
	RwObjectHasFrame object;
	RwCameraProjection projectionType;
	RwCameraBeginUpdateFunc beginUpdate;
	RwCameraEndUpdateFunc endUpdate;
	RwMatrix viewMatrix;
	RwRaster* frameBuffer;
	RwRaster* zBuffer;
	RwV2d viewWindow;
	RwV2d recipViewWindow;
	RwV2d viewOffset;
	RwReal nearPlane;
	RwReal farPlane;
	RwReal fogPlane;
	RwReal zScale;
	RwReal zShift;
	RwFrustumPlane frustumPlanes[6];
	RwBBox frustumBoundBox;
	RwV3d frustumCorners[8];
};


struct RwError
{
	RwInt32 pluginID;
	RwInt32 errorCode;
};


struct RwChunkHeaderInfo
{
	RwUInt32 type;      /**< chunk ID - see \ref RwStreamFindChunk */
	RwUInt32 length;    /**< length of the chunk data in bytes */
	RwUInt32 version;   /**< version of the chunk data.
						 *   See \ref RwEngineGetVersion. */
	RwUInt32 buildNum;  /**< build number of the RenderWare libraries
						 *   previously used to stream out the data */
	RwBool isComplex;   /**< Internal Use */
};
// ~Struct Definitions~ //



// Function Prototypes //
signed int Initialize();
signed int RsInitialize();
char* RsPathnameCreate(const char* relativeFilePath);
RwFileFunctions* RwOsGetFileInterface();
void* __cdecl private_calloc(int a1, int a2);
RwBool FreeListCreate(int a1, int a2, signed int a3, int a4, int a5);
RwMatrix* RwMatrixTranslate(RwMatrix* matrix, RwV3d* translation, RwOpCombineType combineOp);
RwError* RwErrorSet(RwError* code);
int _rwerror(int a1);
RwMatrix* RwMatrixRotateOneMinusCosineSine(RwMatrix* matrix, RwV3d* const unitAxis, RwReal oneMinusCosine, RwReal sine, RwOpCombineType combineOp);
Rt2dObject* Rt2dObjectMTMTranslate(Rt2dObject* object, RwReal x, RwReal y);
RwMatrix* __cdecl RwMatrixScale(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp);
RwMatrix* RwMatrixInvert(RwMatrix* dst, RwMatrix* src);
RwMatrix* RwMatrixMultiply(RwMatrix* dst, const RwMatrix* src1, const RwMatrix* src2);
RwMatrix* MatrixInvertGeneric(RwMatrix* a1, RwMatrix* a2);
RwMatrix* RwFrameGetLTM(RwFrame* frame);
int FrameSyncHierarchyLTMRecurse(int a1, int a2);
char _rwFrameSyncHierarchyLTM(int a1);
RwV3d* __cdecl RwV3dTransformPoints(RwV3d* pointsOut, RwV3d* pointsIn, RwInt32 numPoints, const RwMatrix* matrix);
int __cdecl RwV3dTransformVectors(int a1, int a2, int a3, int a4);
int RwRenderStateGet(RwRenderState state, void* value);
int RwRenderStateSet(RwRenderState state, void* value);
RpClump* RpClumpRender(RpClump* a1);
RwTexDictionary* __cdecl RwTexDictionarySetCurrent(RwTexDictionary* dict);
void* __cdecl RwStreamOpen(int type, int accessType, const void* pData);
RwStream* __cdecl RwStreamReadChunkHeaderInfo(RwStream* stream, RwChunkHeaderInfo* chunkHeaderInfo);
signed int __cdecl rwStreamReadChunkHeader(RwStream* stream, int* type, RwUInt32* length, int* version, int* buildNum);
signed int __cdecl ChunkIsComplex(RwChunkHeaderInfo* chunkHeaderInfo);
int __cdecl RwStreamRead(RwStream* stream, void* buffer, RwInt32 length);
BOOL __cdecl RwStreamClose(int a1, int a2);
signed int __cdecl RwStreamFindChunk(RwStream* stream, RwUInt32 type, RwUInt32 lengthOut, RwUInt32* versionOut);
RwStream* __cdecl RwStreamSkip(RwStream* stream, RwUInt32 offset);
int* __cdecl RpClumpStreamRead(int a1);
RwReal __cdecl RwV3dNormalize(RwV3d* out, const RwV3d* in);
RwFrustumTestResult __cdecl RwCameraFrustumTestSphere(const RwCamera* camera, const RwSphere* sphere);
// ~Function Prototypes~ //



// Global Variables //
extern int& FreeListsEnabled;
extern const RwChar* fopen_rb;
extern const RwChar* fopen_wb;
extern const RwChar* fopen_ab;
extern int& rpTieFreeListBlockSize;
extern int& rpTieFreeListPreallocBlocks;
extern int& rpMatFXMaterialDataFreeListBlockSize;
extern int& rpMatFXMaterialDataFreeListPreallocBlocks;
extern int& rpSkinFreeListBlockSize;
extern int& rpSkinFreeListPreallocBlocks;
extern char** bobArrow;
extern int& freeListList;
extern int& dword_8E0868;
extern int& masterFreeList;
extern int& freeListModuleOpen;
extern int& masterFreeListPtr;
extern RwGlobals& staticGlobals;
extern int (*fpAllocWrapper)(int* a1);
extern int (*fpFreeWrapper)(int a1, void* a2);
extern RwGlobals* &RwEngineInstance;
extern RwChunkHeaderInfo& savedChunkHdrInfo;
extern int& dword_8E0A58;
extern int& dword_8E0A5C;
extern int& dword_8E0A60;
extern int* streamModule;
extern int* textureModule;
extern int* matrixModule;
extern int* vectorModule;
extern int& errorModule;
extern RsGlobalStruct &RsGlobal;

extern char rwCameraFreeList[36];
// ~Global Variables~ //