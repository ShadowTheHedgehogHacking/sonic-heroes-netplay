#pragma once



// Struct Definitions //
struct ONEFILE
{
	static signed int CheckFileID(ONEFILE* a1, char* fileName);
	static int OpenData(ONEFILE* a1, RwUInt32 type, void* addressToDecompressTo);
	static RpClump* OneFileLoadClump(int fileIndex, void* addressToDecompressTo, ONEFILE* ONEFILE);
	static int LoadOneFile(ONEFILE* a1, char* fileName);
	static signed int ReleaseOneFile(ONEFILE* a1);


	char fileName[64];
	int addressToDecompressFileTo;
	int fileNameSectionPointer;
	void* startOfFilePointer;
	int dword4C;
	int initialized;
	int after0CHeaderPointer;
	int fileSize;
};
// ~Struct Definitions~ //

int Expand2(unsigned char* a1, unsigned char* a2);