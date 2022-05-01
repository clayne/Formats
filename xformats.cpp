/* Copyright (c) 2020-2022 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "xformats.h"

XFormats::XFormats(QObject *pParent) : QObject(pParent)
{

}

XBinary::_MEMORY_MAP XFormats::getMemoryMap(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    XBinary::_MEMORY_MAP result={};

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        result=binary.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        result=com.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        result=msdos.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        result=ne.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        result=le.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        result=le.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        result=pe.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        result=elf.getMemoryMap();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        result=mach.getMemoryMap();
    }
#ifdef USE_DEX // TODO Check !!!
    else if(XBinary::checkFileType(XBinary::FT_DEX,fileType))
    {
        XDEX dex(pDevice);
        result=dex.getMemoryMap();
    }
#endif
#ifdef USE_PDF // TODO Check !!!
    else if(XBinary::checkFileType(XBinary::FT_PDF,fileType))
    {
        XPDF pdf(pDevice);
        result=pdf.getMemoryMap();
    }
#endif
#ifdef USE_ARCHIVE
    else if(XBinary::checkFileType(XBinary::FT_ZIP,fileType))
    {
        XZip zip(pDevice);
        result=zip.getMemoryMap();
    }
#endif
    else
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        result=binary.getMemoryMap();
    }

    return result;
}

XBinary::_MEMORY_MAP XFormats::getMemoryMap(QString sFileName,bool bIsImage,XADDR nModuleAddress)
{
    XBinary::_MEMORY_MAP result={};

    QFile file;

    file.setFileName(sFileName);

    if(file.open(QIODevice::ReadOnly))
    {
        result=getMemoryMap(XBinary::getPrefFileType(&file,true),&file,bIsImage,nModuleAddress);

        file.close();
    }

    return result;
}

qint64 XFormats::getEntryPointAddress(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    // TODO pMemoryMap
    qint64 nResult=0; // FT_DEX, FT_ZIP

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        nResult=binary.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        nResult=com.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        nResult=msdos.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        nResult=ne.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        nResult=le.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        nResult=le.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        nResult=pe.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        nResult=elf.getEntryPointAddress();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        nResult=mach.getEntryPointAddress();
    }
    else
    {
        nResult=0;
    }

    return nResult;
}

qint64 XFormats::getEntryPointOffset(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    qint64 nResult=0;

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        nResult=binary._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        nResult=com._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        nResult=msdos._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        nResult=ne._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        nResult=le._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        nResult=le._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        nResult=pe._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        nResult=elf._getEntryPointOffset();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        nResult=mach._getEntryPointOffset();
    }
    else
    {
        nResult=0;
    }

    return nResult;
}

bool XFormats::isBigEndian(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    bool bResult=false;

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        bResult=binary.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        bResult=com.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        bResult=msdos.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        bResult=ne.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        bResult=le.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        bResult=le.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        bResult=pe.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        bResult=elf.isBigEndian();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        bResult=mach.isBigEndian();
    }
#ifdef USE_DEX
    else if(XBinary::checkFileType(XBinary::FT_DEX,fileType))
    {
        XDEX dex(pDevice);
        bResult=dex.isBigEndian();
    }
#endif
#ifdef USE_PDF
    else if(XBinary::checkFileType(XBinary::FT_PDF,fileType))
    {
        XPDF pdf(pDevice);
        bResult=pdf.isBigEndian();
    }
#endif
#ifdef USE_ARCHIVE
    else if(XBinary::checkFileType(XBinary::FT_ZIP,fileType))
    {
        XZip zip(pDevice);
        bResult=zip.isBigEndian();
    }
#endif
    else
    {
        bResult=false;
    }

    return bResult;
}

bool XFormats::isSigned(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    bool bResult=false;

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        bResult=binary.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        bResult=com.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        bResult=msdos.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        bResult=ne.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        bResult=le.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        bResult=le.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        bResult=pe.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        bResult=elf.isSigned();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        bResult=mach.isSigned();
    }
#ifdef USE_DEX
    else if(XBinary::checkFileType(XBinary::FT_DEX,fileType))
    {
        XDEX dex(pDevice);
        bResult=dex.isSigned();
    }
#endif
#ifdef USE_PDF
    else if(XBinary::checkFileType(XBinary::FT_PDF,fileType))
    {
        XPDF pdf(pDevice);
        bResult=pdf.isSigned();
    }
#endif
#ifdef USE_ARCHIVE
    else if(XBinary::checkFileType(XBinary::FT_ZIP,fileType))
    {
        XZip zip(pDevice);
        bResult=zip.isSigned();
    }
#endif
    else
    {
        bResult=false;
    }

    return bResult;
}

XBinary::OFFSETSIZE XFormats::getSignOffsetSize(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress)
{
    XBinary::OFFSETSIZE osResult={};

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);
        osResult=binary.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);
        osResult=com.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);
        osResult=msdos.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);
        osResult=ne.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        osResult=le.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);
        osResult=le.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);
        osResult=pe.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);
        osResult=elf.getSignOffsetSize();
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);
        osResult=mach.getSignOffsetSize();
    }
#ifdef USE_DEX
    else if(XBinary::checkFileType(XBinary::FT_DEX,fileType))
    {
        XDEX dex(pDevice);
        osResult=dex.getSignOffsetSize();
    }
#endif
#ifdef USE_PDF
    else if(XBinary::checkFileType(XBinary::FT_PDF,fileType))
    {
        XPDF pdf(pDevice);
        osResult=pdf.getSignOffsetSize();
    }
#endif
#ifdef USE_ARCHIVE
    else if(XBinary::checkFileType(XBinary::FT_ZIP,fileType))
    {
        XZip zip(pDevice);
        osResult=zip.getSignOffsetSize();
    }
#endif

    return osResult;
}

XBinary::OFFSETSIZE XFormats::getSignOffsetSize(QString sFileName)
{
    XBinary::OFFSETSIZE result={};

    QFile file;

    file.setFileName(sFileName);

    if(file.open(QIODevice::ReadOnly))
    {
        result=getSignOffsetSize(XBinary::getPrefFileType(&file,true),&file);

        file.close();
    }

    return result;
}

bool XFormats::isSigned(QString sFileName)
{
    bool bResult=false;

    QFile file;

    file.setFileName(sFileName);

    if(file.open(QIODevice::ReadOnly))
    {
        bResult=isSigned(XBinary::getPrefFileType(&file,true),&file);

        file.close();
    }

    return bResult;
}

QList<XBinary::SYMBOL_RECORD> XFormats::getSymbolRecords(XBinary::FT fileType,QIODevice *pDevice,bool bIsImage,XADDR nModuleAddress,XBinary::SYMBOL_TYPE symBolType)
{
    QList<XBinary::SYMBOL_RECORD> listResult;

    if(XBinary::checkFileType(XBinary::FT_BINARY,fileType))
    {
        XBinary binary(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=binary.getMemoryMap();
        listResult=binary.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_COM,fileType))
    {
        XCOM com(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=com.getMemoryMap();
        listResult=com.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_MSDOS,fileType))
    {
        XMSDOS msdos(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=msdos.getMemoryMap();
        listResult=msdos.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_NE,fileType))
    {
        XNE ne(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=ne.getMemoryMap();
        listResult=ne.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_LE,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=le.getMemoryMap();
        listResult=le.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_LX,fileType))
    {
        XLE le(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=le.getMemoryMap();
        listResult=le.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_PE,fileType))
    {
        XPE pe(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=pe.getMemoryMap();
        listResult=pe.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_ELF,fileType))
    {
        XELF elf(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=elf.getMemoryMap();
        listResult=elf.getSymbolRecords(&memoryMap,symBolType);
    }
    else if(XBinary::checkFileType(XBinary::FT_MACHO,fileType))
    {
        XMACH mach(pDevice,bIsImage,nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap=mach.getMemoryMap();
        listResult=mach.getSymbolRecords(&memoryMap,symBolType);
    }
#ifdef USE_DEX
    else if(XBinary::checkFileType(XBinary::FT_DEX,fileType))
    {
        XDEX dex(pDevice);

        XBinary::_MEMORY_MAP memoryMap=dex.getMemoryMap();
        listResult=dex.getSymbolRecords(&memoryMap,symBolType);
    }
#endif
#ifdef USE_PDF
    else if(XBinary::checkFileType(XBinary::FT_PDF,fileType))
    {
        XPDF pdf(pDevice);

        XBinary::_MEMORY_MAP memoryMap=pdf.getMemoryMap();
        listResult=pdf.getSymbolRecords(&memoryMap,symBolType);
    }
#endif
#ifdef USE_ARCHIVE
    else if(XBinary::checkFileType(XBinary::FT_ZIP,fileType))
    {
        XZip zip(pDevice);

        XBinary::_MEMORY_MAP memoryMap=zip.getMemoryMap();
        listResult=zip.getSymbolRecords(&memoryMap,symBolType);
    }
#endif

    return listResult;
}

QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice,bool bExtra)
{
    return _getFileTypes(pDevice,bExtra,0);
}

QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice, qint64 nOffset, qint64 nSize, bool bExtra)
{
    QSet<XBinary::FT> result;

    if(nOffset>=0)
    {
        SubDevice sd(pDevice,nOffset,nSize);

        if(sd.open(QIODevice::ReadOnly))
        {
            result=getFileTypes(&sd,bExtra);

            sd.close();
        }
    }

    return result;
}

QSet<XBinary::FT> XFormats::getFileTypes(QString sFileName, bool bExtra)
{
    QSet<XBinary::FT> stResult;

    QFile file;

    file.setFileName(sFileName);

    if(file.open(QIODevice::ReadOnly))
    {
        stResult=getFileTypes(&file,bExtra);

        file.close();
    }

    return stResult;
}

QSet<XBinary::FT> XFormats::getFileTypes(QByteArray *pbaData, bool bExtra)
{
    QSet<XBinary::FT> stResult;

    QBuffer buffer;

    buffer.setBuffer(pbaData);

    if(buffer.open(QIODevice::ReadOnly))
    {
        stResult=getFileTypes(&buffer,bExtra);

        buffer.close();
    }

    return stResult;
}
#ifdef USE_ARCHIVE
QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice, XArchive::RECORD *pRecord, bool bExtra)
{
    QSet<XBinary::FT> stResult;

    QByteArray baData=XArchives::decompress(pDevice,pRecord,true);

    stResult=XFormats::getFileTypes(&baData,bExtra);

    return stResult;
}
#endif
#ifdef USE_ARCHIVE
QSet<XBinary::FT> XFormats::getFileTypesZIP(QIODevice *pDevice, QList<XArchive::RECORD> *pListRecords, qint32 nLevel)
{
    QSet<XBinary::FT> stResult;

    if(XArchive::isArchiveRecordPresent("META-INF/MANIFEST.MF",pListRecords))
    {
        stResult.insert(XBinary::FT_JAR);
    }

    if(XArchive::isArchiveRecordPresent("classes.dex",pListRecords)||XArchive::isArchiveRecordPresent("AndroidManifest.xml",pListRecords))
    {
        stResult.insert(XBinary::FT_APK);
    }

    if(XArchive::isArchiveRecordPresent("Payload/",pListRecords))
    {
        stResult.insert(XBinary::FT_IPA);
    }

    if(nLevel==0)
    {
        if( (!stResult.contains(XBinary::FT_JAR))&&
            (!stResult.contains(XBinary::FT_APK))&&
            (!stResult.contains(XBinary::FT_IPA)))
        {
            qint32 nNumberOfRecords=pListRecords->count();

            bool bAPKS=false;

            if(nNumberOfRecords)
            {
                bAPKS=true;
            }

            for(qint32 i=0;i<nNumberOfRecords;i++)
            {
                if(pListRecords->at(i).compressMethod==XArchive::COMPRESS_METHOD_STORE)
                {
                    XArchive::RECORD record=pListRecords->at(i);

                    SubDevice subDevice(pDevice,record.nDataOffset,record.nUncompressedSize);

                    if(subDevice.open(QIODevice::ReadOnly))
                    {
                        QSet<XBinary::FT> _stResult=_getFileTypes(&subDevice,true,nLevel+1);

                        if(!(_stResult.contains(XBinary::FT_APK)))
                        {
                            bAPKS=false;
                        }

                        subDevice.close();
                    }
                }
                else
                {
                    bAPKS=false;
                }

                if(!bAPKS)
                {
                    break;
                }
            }

            if(bAPKS)
            {
                stResult.insert(XBinary::FT_APKS);
            }
        }
    }

    return stResult;
}
#endif
QSet<XBinary::FT> XFormats::_getFileTypes(QIODevice *pDevice, bool bExtra, qint32 nLevel)
{
#ifndef USE_ARCHIVE
    Q_UNUSED(nLevel);
#endif

    QSet<XBinary::FT> stResult=XBinary::getFileTypes(pDevice,bExtra);
#ifdef USE_ARCHIVE
    if(stResult.contains(XBinary::FT_ZIP))
    {
        XZip xzip(pDevice);

        if(xzip.isValid())
        {
            QList<XArchive::RECORD> listArchiveRecords=xzip.getRecords();

            stResult+=getFileTypesZIP(pDevice,&listArchiveRecords,nLevel);
        }
    }
#endif

    return stResult;
}

#ifdef QT_GUI_LIB
XBinary::FT XFormats::setFileTypeComboBox(XBinary::FT fileType, QIODevice *pDevice, QComboBox *pComboBox)
{
#if QT_VERSION >= QT_VERSION_CHECK(5,3,0)
    const QSignalBlocker block(pComboBox);
#else
    const bool bBlocked1=pComboBox->blockSignals(true);
#endif

    QList<XBinary::FT> listFileTypes;

    if(fileType!=XBinary::FT_REGION)
    {
        QSet<XBinary::FT> stFileType=XFormats::getFileTypes(pDevice,true);

        listFileTypes=XBinary::_getFileTypeListFromSet(stFileType);
    }
    else
    {
        listFileTypes.append(XBinary::FT_REGION);
    }

    pComboBox->clear();

    qint32 nNumberOfListTypes=listFileTypes.count();

    for(qint32 i=0;i<nNumberOfListTypes;i++)
    {
        XBinary::FT fileType=listFileTypes.at(i);
        pComboBox->addItem(XBinary::fileTypeIdToString(fileType),fileType);
    }

    if(nNumberOfListTypes)
    {
        if(fileType==XBinary::FT_UNKNOWN)
        {
            if(pComboBox->itemData(nNumberOfListTypes-1).toUInt()!=XBinary::FT_COM)
            {
                pComboBox->setCurrentIndex(nNumberOfListTypes-1);
            }
        }
        else
        {
            qint32 nNumberOfItems=pComboBox->count();

            for(qint32 i=0;i<nNumberOfItems;i++)
            {
                if(pComboBox->itemData(i).toUInt()==fileType)
                {
                    pComboBox->setCurrentIndex(i);

                    break;
                }
            }
        }
    }

#if QT_VERSION < QT_VERSION_CHECK(5,3,0)
    pComboBox->blockSignals(bBlocked1);
#endif

    return (XBinary::FT)(pComboBox->currentData().toUInt());
}
#endif
#ifdef QT_GUI_LIB
XBinary::FT XFormats::setFileTypeComboBox(QString sFileName,QComboBox *pComboBox)
{
    XBinary::FT result=XBinary::FT_UNKNOWN;

    QFile file;
    file.setFileName(sFileName);

    if(file.open(QIODevice::ReadOnly))
    {
        result=setFileTypeComboBox(XBinary::FT_UNKNOWN,&file,pComboBox);

        file.close();
    }

    return result;
}
#endif
#ifdef QT_GUI_LIB
bool XFormats::setEndiannessComboBox(QComboBox *pComboBox, bool bIsBigEndian)
{ 
#if QT_VERSION >= QT_VERSION_CHECK(5,3,0)
    const QSignalBlocker blocker(pComboBox);
#else
    const bool bBlocked1=pComboBox->blockSignals(true);
#endif

    bool bResult=bIsBigEndian;

    pComboBox->clear();

    pComboBox->addItem("LE",false);
    pComboBox->addItem("BE",true);

    if(bIsBigEndian)
    {
        pComboBox->setCurrentIndex(1);
    }

#if QT_VERSION < QT_VERSION_CHECK(5,3,0)
    pComboBox->blockSignals(bBlocked1);
#endif

    return bResult;
}
#endif
