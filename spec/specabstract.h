﻿// Copyright (c) 2017 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef SPECABSTRACT_H
#define SPECABSTRACT_H

#include <QObject>
#include <QSet>
#include <QDataStream>
#include <QElapsedTimer>
#include "qpe.h"

class SpecAbstract : public QObject
{
    Q_OBJECT
public:
    enum RECORD_FILETYPES
    {
        RECORD_FILETYPE_UNKNOWN=0,
        RECORD_FILETYPE_BINARY,
        RECORD_FILETYPE_MSDOS,
        RECORD_FILETYPE_PE,
        RECORD_FILETYPE_PE32,
        RECORD_FILETYPE_PE64,
        RECORD_FILETYPE_PEOVERLAY // ???
    };
    enum RECORD_TYPES
    {
        RECORD_TYPE_UNKNOWN=0,
        RECORD_TYPE_ARCHIVE,
        RECORD_TYPE_COMPILER,
        RECORD_TYPE_CONVERTER,
        RECORD_TYPE_FORMAT,
        RECORD_TYPE_INSTALLER,
        RECORD_TYPE_LIBRARY,
        RECORD_TYPE_LINKER,
        RECORD_TYPE_PACKER,
        RECORD_TYPE_PROTECTOR,
        RECORD_TYPE_TOOL
    };
    enum RECORD_NAMES
    {
        RECORD_NAME_UNKNOWN=0,
        RECORD_NAME_32LITE,
        RECORD_NAME_7Z,
        RECORD_NAME_ANDPAKK2,
        RECORD_NAME_ASDPACK,
        RECORD_NAME_ASM,
        RECORD_NAME_ASPACK,
        RECORD_NAME_BORLANDCPP,
        RECORD_NAME_BORLANDCPPBUILDER,
        RECORD_NAME_BORLANDDELPHI,
        RECORD_NAME_BORLANDDELPHIDOTNET,
        RECORD_NAME_C,
        RECORD_NAME_CIL,
        RECORD_NAME_CODEGEARCPP,
        RECORD_NAME_CODEGEARCPPBUILDER,
        RECORD_NAME_CODEGEARDELPHI,
        RECORD_NAME_CPP,
        RECORD_NAME_DEB,
        RECORD_NAME_DOTFUSCATOR,
        RECORD_NAME_DOTNET,
        RECORD_NAME_DVCLAL,
        RECORD_NAME_EMBARCADEROCPP,
        RECORD_NAME_EMBARCADEROCPPBUILDER,
        RECORD_NAME_EMBARCADERODELPHI,
        RECORD_NAME_EMBARCADERODELPHIDOTNET,
        RECORD_NAME_ENIGMA,
        RECORD_NAME_ACPROTECT,
        RECORD_NAME_ALLOY,
        RECORD_NAME_ALEXPROTECTOR,
        RECORD_NAME_EXPORT,
        RECORD_NAME_FASM,
        RECORD_NAME_GCC,
        RECORD_NAME_FPC,
        RECORD_NAME_FLEXLM,
        RECORD_NAME_FLEXNET,
        RECORD_NAME_FSG,
        RECORD_NAME_GENERIC,
        RECORD_NAME_GENERICLINKER,
        RECORD_NAME_GNULINKER,
        RECORD_NAME_GZIP,
        RECORD_NAME_HXS,
        RECORD_NAME_IMPORT,
        RECORD_NAME_INNOSETUP,
        RECORD_NAME_MASM,
        RECORD_NAME_MASM32,
        RECORD_NAME_MFC,
        RECORD_NAME_MICROSOFTC,
        RECORD_NAME_MICROSOFTCPP,
        RECORD_NAME_MICROSOFTLINKER,
        RECORD_NAME_MICROSOFTVISUALSTUDIO,
        RECORD_NAME_MINGW,
        RECORD_NAME_MSYS,
        RECORD_NAME_MSYS2,
        RECORD_NAME_MPRESS,
        RECORD_NAME_NSPACK,
        RECORD_NAME_OBJECTPASCAL,
        RECORD_NAME_BORLANDOBJECTPASCAL,
        RECORD_NAME_CODEGEAROBJECTPASCAL,
        RECORD_NAME_EMBARCADEROOBJECTPASCAL,
        RECORD_NAME_PEX,
        RECORD_NAME_PKLITE32,
        RECORD_NAME_PYTHON,
        RECORD_NAME_QT,
        RECORD_NAME_RESOURCE,
        RECORD_NAME_TURBOLINKER,
        RECORD_NAME_UPX,
        RECORD_NAME_YANO,
        RECORD_NAME_VCL,
        RECORD_NAME_VCLPACKAGEINFO,
        RECORD_NAME_VISUALBASIC,
        RECORD_NAME_VBNET,
        RECORD_NAME_VISUALCPP,
        RECORD_NAME_WINUPACK,
        RECORD_NAME_WWPACK32,
        RECORD_NAME_ZIP,
        RECORD_NAME_CYGWIN,
        RECORD_NAME_DYAMAR
    };

    struct ID
    {
        qint64 nOffset;
        RECORD_FILETYPES filetype;
    };

    // TODO flags(static scan/emul/heur)
    struct SCAN_STRUCT
    {
        qint64 nSize;
        ID id;
        ID parentId;
        RECORD_TYPES type;
        RECORD_NAMES name;
        QString sVersion;
        QString sInfo;
        QByteArray baExtra;
        //        union EXTRA_INFO
        //        {
        //            struct PE_INFO
        //            {
        //                quint32 nEntryPoint;
        //            } pe_info;
        //            struct PE_PROTECTOR_INFO
        //            {
        //                qint64 nImageBase; // TODO!!!!!
        //                qint64 nOriginalEntryPoint;
        //                qint64 nWriteImport;
        //            } pe_protector_info;
        //            struct ARCHIVE_INFO
        //            {
        //                qint64 nNumberOfFiles;
        //                //TODO
        //            } archive_info;
        //        } extra_info;
    };

    struct SCANS_STRUCT
    {
        quint32 nVariant;
        RECORD_FILETYPES filetype;
        RECORD_TYPES type;
        RECORD_NAMES name;
        QString sVersion;
        QString sInfo;

        qint64 nOffset;
    };

    struct SCAN_RECORD
    {
        RECORD_FILETYPES filetype;
        RECORD_TYPES type;
        RECORD_NAMES name;
        QString sVersion;
        QString sInfo;
    };

    struct BASIC_PE_INFO
    {
        quint32 nEntryPoint;
    };

    struct BASIC_INFO
    {
        qint64 nElapsedTime;
        ID parentId;
        ID id;
        qint64 nSize;
        //        RECORD_FILETYPES filetype;
        QString sHeaderSignature;
    };


    struct PEINFO_STRUCT
    {
        BASIC_INFO basic_info;
        QString sEntryPointSignature;
        QString sOverlaySignature;
        qint64 nOverlaySize;
        S_IMAGE_FILE_HEADER fileHeader;
        union OPTIONAL_HEADER
        {
            S_IMAGE_OPTIONAL_HEADER32 optionalHeader32;
            S_IMAGE_OPTIONAL_HEADER64 optionalHeader64;
        } optional_header;
        QList<S_IMAGE_SECTION_HEADER> listSections;
        QList<QPE::IMPORT_HEADER> listImports;
        QPE::EXPORT_HEADER export_header;
        QList<QPE::RESOURCE_HEADER> listResources;
        QList<QPE::RICH_RECORD> listRichSignatures;

        QPE::CLI_INFO cliInfo;

        QMap<RECORD_NAMES,SCANS_STRUCT> mapCodeSectionScanDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapDataSectionScanDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapHeaderScanDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapHeaderDetects;
        QMap<RECORD_NAMES,SCANS_STRUCT> mapOverlayDetects;
        QMap<RECORD_NAMES,SCANS_STRUCT> mapEntryPointDetects;
        QMap<RECORD_NAMES,SCANS_STRUCT> mapImportDetects;
        QMap<RECORD_NAMES,SCANS_STRUCT> _mapImportDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapExportDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapRichDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapResourcesDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapDotAnsistringsDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapDotUnicodestringsDetects; // Obsolete
        QMap<RECORD_NAMES,SCANS_STRUCT> mapSpecialDetects; // Obsolete

        qint32 nEntryPointSection;
        qint32 nResourceSection;
        qint32 nImportSection;
        qint32 nCodeSection;
        qint32 nDataSection;
        qint32 nConstDataSection;

        QString sEntryPointSectionName;

        // TODO import
        qint64 nEntryPointAddress;
        qint64 nImageBaseAddress;
        quint8 nMinorLinkerVersion;
        quint8 nMajorLinkerVersion;
        bool bIs64;

        qint64 nHeaderOffset;
        qint64 nHeaderSize;
        qint64 nEntryPointSectionOffset;
        qint64 nEntryPointSectionSize;
        qint64 nCodeSectionOffset;
        qint64 nCodeSectionSize;
        qint64 nDataSectionOffset;
        qint64 nDataSectionSize;
        qint64 nConstDataSectionOffset;
        qint64 nConstDataSectionSize;
        qint64 nImportSectionOffset;
        qint64 nImportSectionSize;

        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultLinkers;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultCompilers;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultLibraries;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultTools;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultProtectors;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultPackers;
        QMap<RECORD_NAMES,SCAN_STRUCT> mapResultInstallers;

        QList<SpecAbstract::SCAN_STRUCT> listDetects;
    };

    struct SCAN_OPTIONS
    {
        bool bEmulate;
    };

    struct UNPACK_OPTIONS
    {
        // PE/PE+
        bool bCopyOverlay;     // In
    };

    struct SIGNATURE_RECORD
    {
        int nVariant;
        const RECORD_FILETYPES filetype;
        const RECORD_TYPES type;
        const RECORD_NAMES name;
        const char *pszVersion;
        const char *pszInfo;
        const char *pszSignature;
    };

    struct SCANMEMORY_RECORD
    {
        int nVariant;
        const RECORD_FILETYPES filetype;
        const RECORD_TYPES type;
        const RECORD_NAMES name;
        const char *pszVersion;
        const char *pszInfo;
        const char *pData;
        int nSize;
    };

    struct RESOURCES_RECORD
    {
        int nVariant;
        const RECORD_FILETYPES filetype;
        const RECORD_TYPES type;
        const RECORD_NAMES name;
        const char *pszVersion;
        const char *pszInfo;
        bool bIsString1;
        const char *pszName1;
        quint32 nID1;
        bool bIsString2;
        const char *pszName2;
        quint32 nID2;
    };

    struct VCL_STRUCT
    {
        quint32 nValue;
        quint32 nOffset;
        bool bIs64;
    };

    struct VCL_PACKAGEINFO_MODULE
    {
        quint8 nFlags;
        quint8 nHashCode;
        QString sName;
    };

    struct VCL_PACKAGEINFO
    {
        quint32 nFlags;
        quint32 nUnknown;
        quint32 nRequiresCount;
        QList<VCL_PACKAGEINFO_MODULE> listModules;
    };

    enum RESULT_PRIOS
    {
        RESULT_PRIO_UNKNOWN=0,
        RESULT_PRIO_CODESECTIONSCAN,
        RESULT_PRIO_DATASECTIONSCAN,
        RESULT_PRIO_HEADERSCAN,
        RESULT_PRIO_HEADER,
        RESULT_PRIO_OVERLAY,
        RESULT_PRIO_ENTRYPOINT,
        RESULT_PRIO_IMPORT,
        RESULT_PRIO_EXPORT,
        RESULT_PRIO_RICH,
        RESULT_PRIO_RESOURCES,
        RESULT_PRIO_DOTANSISTRINGS,
        RESULT_PRIO_DOTUNICODESTRINGS,
        RESULT_PRIO_SPECIAL
    };

    struct VI_STRUCT
    {
        QString sVersion;
        QString sInfo;
    };

    //    enum RESULT_TYPES
    //    {
    //        RESULT_TYPE_UNKNOWN=0,
    //        RESULT_TYPE_LINKERS,
    //        RESULT_TYPE_COMPILERS,
    //        RESULT_TYPE_LIBRARIES,
    //        RESULT_TYPE_TOOLS,
    //        RESULT_TYPE_PROTECTORS
    //    };

    explicit SpecAbstract(QObject *parent = 0);
    static QString append(QString sResult,QString sString);
    static QString recordFiletypeIdToString(RECORD_FILETYPES id);
    static QString recordTypeIdToString(RECORD_TYPES id);
    static QString recordNameIdToString(RECORD_NAMES id);

    static QList<SCAN_STRUCT> scanBinary(QBinary *pBinary,SCAN_OPTIONS *pOptions,qint64 nStartOffset,SpecAbstract::ID parentId);
    static QList<SCAN_STRUCT> scanPE(QPE *pPE,SCAN_OPTIONS *pOptions,qint64 nStartOffset,SpecAbstract::ID parentId);
    virtual bool unpack(UNPACK_OPTIONS *pUnpOptions,QIODevice *pDevice,QString sOutFileName);

    static SpecAbstract::UNPACK_OPTIONS getPossibleUnpackOptions(QIODevice *pDevice);

    static QString createResultString(const SCAN_STRUCT *pScanStruct);
    static QString createResultString2(const SCAN_STRUCT *pScanStruct);

    static QString findEnigmaVersion(QIODevice *pDevice,qint64 nOffset,qint64 nSize);

    static PEINFO_STRUCT getPEInfo(QIODevice *pDevice); // TODO options
    static void handle_Rich(PEINFO_STRUCT *pPEInfo);

    static SCANS_STRUCT getScansStruct(quint32 nVariant,RECORD_FILETYPES filetype,RECORD_TYPES type,RECORD_NAMES name,QString sVersion,QString sInfo,qint64 nOffset);

    static void handle_import(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_protection(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_libraries(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_Microsoft(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_Borland(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_Tools(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static void handle_Installers(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);

    static void handle_ENIGMA(QIODevice *pDevice,SpecAbstract::PEINFO_STRUCT *pPEInfo);
    static void handle_DotNet(PEINFO_STRUCT *pPEInfo);
    static void handle(PEINFO_STRUCT *pPEInfo,RECORD_NAMES name,RESULT_PRIOS prio0,RESULT_PRIOS prio1=RESULT_PRIO_UNKNOWN,RESULT_PRIOS prio2=RESULT_PRIO_UNKNOWN);
    static QMap<RECORD_NAMES,SCANS_STRUCT> *getDetectsMap(PEINFO_STRUCT *pPEInfo,RESULT_PRIOS prio);
    //    static handle_ObjectPascal(PEINFO_STRUCT *pPEInfo);
    //    static handle_BorlandCPP(PEINFO_STRUCT *pPEInfo);
    //    static handle_Qt(PEINFO_STRUCT *pPEInfo);
    //    static handle_FASM(PEINFO_STRUCT *pPEInfo);
    //    static handle_MinGW(PEINFO_STRUCT *pPEInfo);
    //    static handle_MFC(PEINFO_STRUCT *pPEInfo);
    //    static handle_VisualBasic(PEINFO_STRUCT *pPEInfo);
    static void fixDetects(PEINFO_STRUCT *pPEInfo);
    static void fixResult(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);

    static void updateVersion(QMap<RECORD_NAMES,SCAN_STRUCT> *map,RECORD_NAMES name,QString sVersion);
    static void updateInfo(QMap<RECORD_NAMES,SCAN_STRUCT> *map,RECORD_NAMES name,QString sInfo);
    static void updateVersionAndInfo(QMap<RECORD_NAMES,SCAN_STRUCT> *map,RECORD_NAMES name,QString sVersion,QString sInfo);


    static bool isScanStructPresent(QList<SpecAbstract::SCAN_STRUCT> *pList,RECORD_FILETYPES filetype,RECORD_TYPES type,RECORD_NAMES name,QString sVersion,QString sInfo);

    static bool checkVersionString(QString sVersion);
    static VI_STRUCT get_TurboLinker_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_FASM_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_UPX_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_WWPack32_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_InnoSetup_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_mslink_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_MFC_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_vc_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_BorlandCpp_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_EmbarcaderoCpp_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_CodegearCpp_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_FlexLM_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);
    static VI_STRUCT get_FlexNet_vi(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);

    static bool isValid_UPX(QIODevice *pDevice,PEINFO_STRUCT *pPEInfo);

    static QList<SCAN_STRUCT> mapToList(QMap<RECORD_NAMES,SCAN_STRUCT> *pMapRecords);
    //    static SCAN_STRUCT getScanStruct(QMap<RECORD_NAMES,SCANS_STRUCT> *pMapDetects,BASIC_INFO *pBasicInfo,RECORD_NAMES recordName);

    static SCAN_STRUCT scansToScan(BASIC_INFO *pBasicInfo,SCANS_STRUCT *pScansStruct);

    static QByteArray _BasicPEInfoToArray(BASIC_PE_INFO *pInfo);
    static BASIC_PE_INFO _ArrayToBasicPEInfo(const QByteArray *pbaArray);
    static void memoryScan(QMap<RECORD_NAMES,SCANS_STRUCT> *pMapRecords,QIODevice *pDevice,qint64 nOffset,qint64 nSize,SpecAbstract::SCANMEMORY_RECORD *pRecords, int nRecordsSize, SpecAbstract::RECORD_FILETYPES fileType1, SpecAbstract::RECORD_FILETYPES fileType2);
    static void signatureScan(QMap<RECORD_NAMES,SCANS_STRUCT> *pMapRecords,QString sSignature,SIGNATURE_RECORD *pRecords,int nRecordsSize,RECORD_FILETYPES fileType1,RECORD_FILETYPES fileType2);
    static void resourcesScan(QMap<RECORD_NAMES,SCANS_STRUCT> *pMapRecords,QList<QPE::RESOURCE_HEADER> *pListResources,RESOURCES_RECORD *pRecords,int nRecordsSize,RECORD_FILETYPES fileType1,RECORD_FILETYPES fileType2);
    static QList<VCL_STRUCT> getVCLstruct(QIODevice *pDevice,qint64 nOffset,qint64 nSize,bool bIs64);
    static VCL_PACKAGEINFO getVCLPackageInfo(QIODevice *pDevice,QList<QPE::RESOURCE_HEADER> *pListResources);
    static SpecAbstract::SCANS_STRUCT getRichSignatureDescription(quint32 nRichID);
protected:
    void _errorMessage(QString sMessage);
    void _infoMessage(QString sMessage);
signals:
    void errorMessage(QString sMessage);
    void infoMessage(QString sMessage);
};

#endif // SPECABSTRACT_H
