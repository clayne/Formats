/* Copyright (c) 2020-2024 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
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

bool _sortItems(const XBinary::SCANSTRUCT &v1, const XBinary::SCANSTRUCT &v2)
{
    bool bResult = false;

    bResult = (v1.nPrio < v2.nPrio);

    return bResult;
}

XFormats::XFormats(QObject *pParent) : QObject(pParent)
{
}

XBinary::_MEMORY_MAP XFormats::getMemoryMap(XBinary::FT fileType, XBinary::MAPMODE mapMode, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress,
                                            XBinary::PDSTRUCT *pPdStruct)
{
    XBinary::_MEMORY_MAP result = {};

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        result = binary.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        result = com.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        result = msdos.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        result = ne.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        result = le.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        result = le.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        result = pe.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        result = elf.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        result = mach.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PNG, fileType)) {
        XPNG png(pDevice);
        result = png.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JPEG, fileType)) {
        XJpeg jpeg(pDevice);
        result = jpeg.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ICO, fileType)) {
        XIcon xicon(pDevice);
        result = xicon.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_BMP, fileType)) {
        XBMP xbmp(pDevice);
        result = xbmp.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GIF, fileType)) {
        XGif xgif(pDevice);
        result = xgif.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TIFF, fileType)) {
        XTiff xtiff(pDevice);
        result = xtiff.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP4, fileType)) {
        XMP4 xmp4(pDevice);
        result = xmp4.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP3, fileType)) {
        XMP3 xmp3(pDevice);
        result = xmp3.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RIFF, fileType)) {
        XRiff xriff(pDevice);
        result = xriff.getMemoryMap(mapMode, pPdStruct);
    }
#ifdef USE_DEX  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        result = dex.getMemoryMap(mapMode, pPdStruct);
    }
#endif
#ifdef USE_PDF  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        result = pdf.getMemoryMap(mapMode, pPdStruct);
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        result = zip.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JAR, fileType)) {
        XJAR jar(pDevice);
        result = jar.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_APK, fileType)) {
        XAPK apk(pDevice);
        result = apk.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_IPA, fileType)) {
        XIPA ipa(pDevice);
        result = ipa.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_APKS, fileType)) {
        XAPKS apks(pDevice);
        result = apks.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_7Z, fileType)) {
        XSevenZip sevenzip(pDevice);
        result = sevenzip.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_CAB, fileType)) {
        XCab xcab(pDevice);
        result = xcab.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RAR, fileType)) {
        XRar xrar(pDevice);
        result = xrar.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHOFAT, fileType)) {
        XMACHOFat xmachofat(pDevice);
        result = xmachofat.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NPM, fileType)) {
        XNPM xnpm(pDevice);
        result = xnpm.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TARGZ, fileType)) {
        XTGZ xtgz(pDevice);
        result = xtgz.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GZIP, fileType)) {
        XGzip xgzip(pDevice);
        result = xgzip.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ZLIB, fileType)) {
        XZlib xzlib(pDevice);
        result = xzlib.getMemoryMap(mapMode, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LHA, fileType)) {
        XLHA xlha(pDevice);
        result = xlha.getMemoryMap(mapMode, pPdStruct);
    }
#endif
    else {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        result = binary.getMemoryMap(mapMode, pPdStruct);
    }

    return result;
}

XBinary::_MEMORY_MAP XFormats::getMemoryMap(const QString &sFileName, XBinary::MAPMODE mapMode, bool bIsImage, XADDR nModuleAddress, XBinary::PDSTRUCT *pPdStruct)
{
    XBinary::_MEMORY_MAP result = {};

    QFile file;
    file.setFileName(sFileName);

    if (file.open(QIODevice::ReadOnly)) {
        result = getMemoryMap(XBinary::getPrefFileType(&file, true), mapMode, &file, bIsImage, nModuleAddress, pPdStruct);

        file.close();
    }

    return result;
}

QList<XBinary::MAPMODE> XFormats::getMapModesList(XBinary::FT fileType)
{
    QList<XBinary::MAPMODE> listResult;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        listResult = XBinary::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        listResult = XCOM::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        listResult = XMSDOS::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        listResult = XNE::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        listResult = XLE::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        listResult = XLE::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        listResult = XPE::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        listResult = XELF::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        listResult = XMACH::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_PNG, fileType)) {
        listResult = XPNG::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_JPEG, fileType)) {
        listResult = XJpeg::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_ICO, fileType)) {
        listResult = XIcon::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_BMP, fileType)) {
        listResult = XBMP::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_GIF, fileType)) {
        listResult = XGif::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_TIFF, fileType)) {
        listResult = XTiff::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_MP4, fileType)) {
        listResult = XMP4::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_MP3, fileType)) {
        listResult = XMP3::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_RIFF, fileType)) {
        listResult = XRiff::getMapModesList();
    }
#ifdef USE_DEX  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        listResult = XDEX::getMapModesList();
    }
#endif
#ifdef USE_PDF  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        listResult = XPDF::getMapModesList();
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        listResult = XZip::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_7Z, fileType)) {
        listResult = XSevenZip::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_CAB, fileType)) {
        listResult = XCab::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_RAR, fileType)) {
        listResult = XRar::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_MACHOFAT, fileType)) {
        listResult = XMACHOFat::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_GZIP, fileType)) {
        listResult = XGzip::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_ZLIB, fileType)) {
        listResult = XZlib::getMapModesList();
    } else if (XBinary::checkFileType(XBinary::FT_LHA, fileType)) {
        listResult = XLHA::getMapModesList();
    }
#endif
    else {
        listResult = XBinary::getMapModesList();
    }

    return listResult;
}

qint64 XFormats::getEntryPointAddress(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    // TODO pMemoryMap !!!
    qint64 nResult = 0;  // FT_DEX, FT_ZIP

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        nResult = binary.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        nResult = com.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        nResult = msdos.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        nResult = ne.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        nResult = le.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        nResult = le.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        nResult = pe.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        nResult = elf.getEntryPointAddress();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        nResult = mach.getEntryPointAddress();
    } else {
        nResult = 0;
    }

    return nResult;
}

qint64 XFormats::getEntryPointOffset(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    qint64 nResult = 0;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        nResult = binary._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        nResult = com._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        nResult = msdos._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        nResult = ne._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        nResult = le._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        nResult = le._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        nResult = pe._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        nResult = elf._getEntryPointOffset();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        nResult = mach._getEntryPointOffset();
    } else {
        nResult = 0;
    }

    return nResult;
}

bool XFormats::isBigEndian(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    bool bResult = false;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        bResult = binary.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        bResult = com.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        bResult = msdos.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        bResult = ne.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        bResult = le.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        bResult = le.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        bResult = pe.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        bResult = elf.isBigEndian();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        bResult = mach.isBigEndian();
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        bResult = dex.isBigEndian();
    }
#endif
#ifdef USE_PDF
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        bResult = pdf.isBigEndian();
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        bResult = zip.isBigEndian();
    }
#endif
    else {
        bResult = false;
    }

    return bResult;
}

QList<XBinary::HREGION> XFormats::getHRegions(XBinary::FT fileType, QIODevice *pDevice, XBinary::_MEMORY_MAP *pMemoryMap, bool bIsImage, XADDR nModuleAddress,
                                              XBinary::PDSTRUCT *pPdStruct)
{
    QList<XBinary::HREGION> listResult;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        listResult = binary.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        listResult = com.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        listResult = msdos.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        listResult = ne.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        listResult = le.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        listResult = le.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        listResult = pe.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        listResult = elf.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        listResult = mach.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PNG, fileType)) {
        XPNG png(pDevice);
        listResult = png.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JPEG, fileType)) {
        XJpeg jpeg(pDevice);
        listResult = jpeg.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ICO, fileType)) {
        XIcon xicon(pDevice);
        listResult = xicon.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_BMP, fileType)) {
        XBMP xbmp(pDevice);
        listResult = xbmp.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GIF, fileType)) {
        XGif xgif(pDevice);
        listResult = xgif.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TIFF, fileType)) {
        XTiff xtiff(pDevice);
        listResult = xtiff.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP4, fileType)) {
        XMP4 xmp4(pDevice);
        listResult = xmp4.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP3, fileType)) {
        XMP3 xmp3(pDevice);
        listResult = xmp3.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RIFF, fileType)) {
        XRiff xriff(pDevice);
        listResult = xriff.getHRegions(pMemoryMap, pPdStruct);
    }
#ifdef USE_DEX  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        listResult = dex.getHRegions(pMemoryMap, pPdStruct);
    }
#endif
#ifdef USE_PDF  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        listResult = pdf.getHRegions(pMemoryMap, pPdStruct);
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        listResult = zip.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_7Z, fileType)) {
        XSevenZip sevenzip(pDevice);
        listResult = sevenzip.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_CAB, fileType)) {
        XCab xcab(pDevice);
        listResult = xcab.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RAR, fileType)) {
        XRar xrar(pDevice);
        listResult = xrar.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHOFAT, fileType)) {
        XMACHOFat xmachofat(pDevice);
        listResult = xmachofat.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GZIP, fileType)) {
        XGzip xgzip(pDevice);
        listResult = xgzip.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ZLIB, fileType)) {
        XZlib xzlib(pDevice);
        listResult = xzlib.getHRegions(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LHA, fileType)) {
        XLHA xlha(pDevice);
        listResult = xlha.getHRegions(pMemoryMap, pPdStruct);
    }
#endif
    else {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        listResult = binary.getHRegions(pMemoryMap, pPdStruct);
    }

    return listResult;
}

QList<XBinary::HREGION> XFormats::getHighlights(XBinary::FT fileType, QIODevice *pDevice, XBinary::_MEMORY_MAP *pMemoryMap, bool bIsImage, XADDR nModuleAddress,
                                                XBinary::PDSTRUCT *pPdStruct)
{
    QList<XBinary::HREGION> listResult;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        listResult = binary.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        listResult = com.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        listResult = msdos.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        listResult = ne.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        listResult = le.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        listResult = le.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        listResult = pe.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        listResult = elf.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        listResult = mach.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PNG, fileType)) {
        XPNG png(pDevice);
        listResult = png.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JPEG, fileType)) {
        XJpeg jpeg(pDevice);
        listResult = jpeg.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ICO, fileType)) {
        XIcon xicon(pDevice);
        listResult = xicon.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_BMP, fileType)) {
        XBMP xbmp(pDevice);
        listResult = xbmp.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GIF, fileType)) {
        XGif xgif(pDevice);
        listResult = xgif.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TIFF, fileType)) {
        XTiff xtiff(pDevice);
        listResult = xtiff.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP4, fileType)) {
        XMP4 xmp4(pDevice);
        listResult = xmp4.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP3, fileType)) {
        XMP3 xmp3(pDevice);
        listResult = xmp3.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RIFF, fileType)) {
        XRiff xriff(pDevice);
        listResult = xriff.getHighlights(pMemoryMap, pPdStruct);
    }
#ifdef USE_DEX  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        listResult = dex.getHighlights(pMemoryMap, pPdStruct);
    }
#endif
#ifdef USE_PDF  // TODO Check !!!
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        listResult = pdf.getHighlights(pMemoryMap, pPdStruct);
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        listResult = zip.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_7Z, fileType)) {
        XSevenZip sevenzip(pDevice);
        listResult = sevenzip.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_CAB, fileType)) {
        XCab xcab(pDevice);
        listResult = xcab.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RAR, fileType)) {
        XRar xrar(pDevice);
        listResult = xrar.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHOFAT, fileType)) {
        XMACHOFat xmachofat(pDevice);
        listResult = xmachofat.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GZIP, fileType)) {
        XGzip xgzip(pDevice);
        listResult = xgzip.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ZLIB, fileType)) {
        XZlib xzlib(pDevice);
        listResult = xzlib.getHighlights(pMemoryMap, pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LHA, fileType)) {
        XLHA xlha(pDevice);
        listResult = xlha.getHighlights(pMemoryMap, pPdStruct);
    }
#endif
    else {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        listResult = binary.getHighlights(pMemoryMap, pPdStruct);
    }

    return listResult;
}

bool XFormats::isSigned(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    bool bResult = false;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        bResult = binary.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        bResult = com.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        bResult = msdos.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        bResult = ne.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        bResult = le.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        bResult = le.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        bResult = pe.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        bResult = elf.isSigned();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        bResult = mach.isSigned();
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        bResult = dex.isSigned();
    }
#endif
#ifdef USE_PDF
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        bResult = pdf.isSigned();
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        bResult = zip.isSigned();
    }
#endif
    else {
        bResult = false;
    }

    return bResult;
}

XBinary::OFFSETSIZE XFormats::getSignOffsetSize(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    XBinary::OFFSETSIZE osResult = {};

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);
        osResult = binary.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        osResult = com.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        osResult = msdos.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        osResult = ne.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        osResult = le.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        osResult = le.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        osResult = pe.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        osResult = elf.getSignOffsetSize();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        osResult = mach.getSignOffsetSize();
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        osResult = dex.getSignOffsetSize();
    }
#endif
#ifdef USE_PDF
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);
        osResult = pdf.getSignOffsetSize();
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);
        osResult = zip.getSignOffsetSize();
    }
#endif

    return osResult;
}

XBinary::OFFSETSIZE XFormats::getSignOffsetSize(const QString &sFileName)
{
    XBinary::OFFSETSIZE result = {};

    QFile file;
    file.setFileName(sFileName);

    if (file.open(QIODevice::ReadOnly)) {
        result = getSignOffsetSize(XBinary::getPrefFileType(&file, true), &file);

        file.close();
    }

    return result;
}

bool XFormats::isSigned(const QString &sFileName)
{
    bool bResult = false;

    QFile file;
    file.setFileName(sFileName);

    if (file.open(QIODevice::ReadOnly)) {
        bResult = isSigned(XBinary::getPrefFileType(&file, true), &file);

        file.close();
    }

    return bResult;
}

QList<XBinary::SYMBOL_RECORD> XFormats::getSymbolRecords(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress, XBinary::SYMBOL_TYPE symBolType)
{
    QList<XBinary::SYMBOL_RECORD> listResult;

    if (XBinary::checkFileType(XBinary::FT_BINARY, fileType)) {
        XBinary binary(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = binary.getMemoryMap();
        listResult = binary.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = com.getMemoryMap();
        listResult = com.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = msdos.getMemoryMap();
        listResult = msdos.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = ne.getMemoryMap();
        listResult = ne.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = le.getMemoryMap();
        listResult = le.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = le.getMemoryMap();
        listResult = le.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = pe.getMemoryMap();
        listResult = pe.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = elf.getMemoryMap();
        listResult = elf.getSymbolRecords(&memoryMap, symBolType);
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);

        XBinary::_MEMORY_MAP memoryMap = mach.getMemoryMap();
        listResult = mach.getSymbolRecords(&memoryMap, symBolType);
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);

        XBinary::_MEMORY_MAP memoryMap = dex.getMemoryMap();
        listResult = dex.getSymbolRecords(&memoryMap, symBolType);
    }
#endif
#ifdef USE_PDF
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(pDevice);

        XBinary::_MEMORY_MAP memoryMap = pdf.getMemoryMap();
        listResult = pdf.getSymbolRecords(&memoryMap, symBolType);
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(pDevice);

        XBinary::_MEMORY_MAP memoryMap = zip.getMemoryMap();
        listResult = zip.getSymbolRecords(&memoryMap, symBolType);
    }
#endif

    return listResult;
}

QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice, bool bExtra, XBinary::PDSTRUCT *pPdStruct)
{
    XBinary::PDSTRUCT pdStructEmpty = XBinary::createPdStruct();

    if (!pPdStruct) {
        pPdStruct = &pdStructEmpty;
    }

    return _getFileTypes(pDevice, bExtra, pPdStruct);
}

bool XFormats::saveAllPEIconsToDirectory(QIODevice *pDevice, const QString &sDirectoryName)
{
    bool bResult = false;

    XPE pe(pDevice);

    if (pe.isValid()) {
        QList<XPE::RESOURCE_RECORD> listResources = pe.getResources();
        QList<XPE::RESOURCE_RECORD> listIcons = pe.getResourceRecords(XPE_DEF::S_RT_GROUP_ICON, -1, &listResources);

        qint32 nNumberOfRecords = listIcons.count();

        for (qint32 i = 0; i < nNumberOfRecords; i++) {
            XPE::RESOURCE_RECORD resourceRecord = listIcons.at(i);

            QString sFileName = sDirectoryName + QDir::separator() + QString("%1.ico").arg(XBinary::convertFileNameSymbols(XPE::resourceRecordToString(resourceRecord)));

            XFormats::savePE_ICOToFile(pDevice, &listResources, resourceRecord, sFileName);
        }
    }

    return bResult;
}

bool XFormats::saveAllPECursorsToDirectory(QIODevice *pDevice, const QString &sDirectoryName)
{
    bool bResult = true;

    XPE pe(pDevice);

    if (pe.isValid()) {
        QList<XPE::RESOURCE_RECORD> listResources = pe.getResources();
        QList<XPE::RESOURCE_RECORD> listIcons = pe.getResourceRecords(XPE_DEF::S_RT_GROUP_CURSOR, -1, &listResources);

        qint32 nNumberOfRecords = listIcons.count();

        for (qint32 i = 0; i < nNumberOfRecords; i++) {
            XPE::RESOURCE_RECORD resourceRecord = listIcons.at(i);

            QString sFileName = sDirectoryName + QDir::separator() + QString("%1.cur").arg(XBinary::convertFileNameSymbols(XPE::resourceRecordToString(resourceRecord)));

            if (!XFormats::savePE_ICOToFile(pDevice, &listResources, resourceRecord, sFileName)) {
                bResult = false;
            }
        }
    }

    return bResult;
}

bool XFormats::savePE_ICOToFile(QIODevice *pDevice, QList<XPE::RESOURCE_RECORD> *pListResourceRecords, XPE::RESOURCE_RECORD resourceRecord, const QString &sFileName)
{
    bool bResult = false;

    qint32 nChunkType = XPE_DEF::S_RT_ICON;
    qint32 idType = 1;

    if (resourceRecord.irin[0].nID == XPE_DEF::S_RT_GROUP_CURSOR) {
        nChunkType = XPE_DEF::S_RT_CURSOR;
        idType = 2;
    }

    XPE xpe(pDevice);

    if (xpe.isValid()) {
        if (resourceRecord.nSize) {
            SubDevice sd(pDevice, resourceRecord.nOffset, resourceRecord.nSize);

            if (sd.open(QIODevice::ReadOnly)) {
                XIcon icon(&sd);

                if (icon.isValid()) {
                    QList<XPE::RESOURCE_RECORD> listChunkRecords;
                    qint64 nTotalDataSize = 0;

                    QList<XIcon::GRPICONDIRENTRY> listDirectories = icon.getIconGPRDirectories();

                    qint32 nNumberOfRecords = listDirectories.count();

                    for (qint32 i = 0; i < nNumberOfRecords; i++) {
                        XPE::RESOURCE_RECORD _resourceRecord = xpe.getResourceRecord(nChunkType, listDirectories.at(i).nID, pListResourceRecords);

                        listChunkRecords.append(_resourceRecord);

                        nTotalDataSize += _resourceRecord.nSize;
                    }

                    QFile file;
                    file.setFileName(sFileName);

                    if (file.open(QIODevice::ReadWrite)) {
                        file.resize(sizeof(XIcon::ICONDIR) + sizeof(XIcon::ICONDIRENTRY) * nNumberOfRecords + nTotalDataSize);

                        XBinary binaryNew(&file);

                        binaryNew.write_uint16(offsetof(XIcon::ICONDIR, idReserved), 0);
                        binaryNew.write_uint16(offsetof(XIcon::ICONDIR, idType), idType);
                        binaryNew.write_uint16(offsetof(XIcon::ICONDIR, idCount), nNumberOfRecords);

                        qint64 nCurrentTableOffset = sizeof(XIcon::ICONDIR);
                        qint64 nCurrentDataOffset = sizeof(XIcon::ICONDIR) + sizeof(XIcon::ICONDIRENTRY) * nNumberOfRecords;

                        for (qint32 i = 0; i < nNumberOfRecords; i++) {
                            binaryNew.write_uint8(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, bWidth), listDirectories.at(i).bWidth);
                            binaryNew.write_uint8(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, bHeight), listDirectories.at(i).bHeight);
                            binaryNew.write_uint8(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, bColorCount), listDirectories.at(i).bColorCount);
                            binaryNew.write_uint8(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, bReserved), listDirectories.at(i).bReserved);
                            binaryNew.write_uint16(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, wPlanes), listDirectories.at(i).wPlanes);
                            binaryNew.write_uint16(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, wBitCount), listDirectories.at(i).wBitCount);
                            binaryNew.write_uint32(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, dwBytesInRes), listDirectories.at(i).dwBytesInRes);
                            binaryNew.write_uint32(nCurrentTableOffset + offsetof(XIcon::ICONDIRENTRY, dwImageOffset), nCurrentDataOffset);

                            XBinary::copyDeviceMemory(pDevice, listChunkRecords.at(i).nOffset, &file, nCurrentDataOffset, listDirectories.at(i).dwBytesInRes);

                            nCurrentTableOffset += sizeof(XIcon::ICONDIRENTRY);
                            nCurrentDataOffset += listDirectories.at(i).dwBytesInRes;
                        }

                        file.close();
                    }
                }

                sd.close();
            }
        }
    }

    return bResult;
}

Qt::GlobalColor XFormats::typeToColor(const QString &sType)
{
    QString _sType = sType;
    Qt::GlobalColor result = Qt::transparent;

    _sType = _sType.toLower().remove("~");

    // TODO more
    if ((_sType == "installer") || (_sType == "sfx") || (_sType == "archive")) {
        result = Qt::blue;
    } else if (isProtection(_sType)) {
        result = Qt::red;
    } else if ((_sType == "pe tool") || (_sType == "apk tool")) {
        result = Qt::green;
    } else if ((_sType == "operation system") || (_sType == "virtual machine")) {
        result = Qt::darkYellow;
    } else if ((_sType == "sign tool") || (_sType == "certificate")) {
        result = Qt::darkMagenta;
    } else if (_sType == "language") {
        result = Qt::darkCyan;
    } else if ((_sType == "virus") || (_sType == "trojan") || (_sType == "malware")) {
        result = Qt::darkRed;
    } else {
        result = Qt::transparent;
    }

    return result;
}

qint32 XFormats::typeToPrio(const QString &sType)
{
    qint32 nResult = 0;
    QString _sType = sType.toLower().remove("~");

    if ((_sType == "operation system") || (_sType == "virtual machine")) nResult = 10;
    else if (_sType == "linker") nResult = 20;
    else if (_sType == "compiler") nResult = 30;
    else if (_sType == "language") nResult = 40;
    else if (_sType == "library") nResult = 50;
    else if ((_sType == "tool") || (_sType == "pe tool") || (_sType == "sign tool") || (_sType == "apk tool")) nResult = 60;
    else if ((_sType == "protector") || (_sType == "cryptor") || (_sType == "crypter")) nResult = 70;
    else if ((_sType == ".net obfuscator") || (_sType == "apk obfuscator") || (_sType == "jar obfuscator")) nResult = 80;
    else if ((_sType == "dongle protection") || (_sType == "protection")) nResult = 90;
    else if ((_sType == "packer") || (_sType == ".net compressor")) nResult = 100;
    else if (_sType == "joiner") nResult = 110;
    else if ((_sType == "sfx") || (_sType == "installer")) nResult = 120;
    else if ((_sType == "virus") || (_sType == "malware") || (_sType == "trojan")) nResult = 70;
    else nResult = 1000;

    return nResult;
}

QString XFormats::translateType(const QString &sType)
{
    QString sResult;

    QString _sType = sType;
    bool bHeur = false;

    if (_sType.size() > 0) {
        if (_sType[0] == QChar('~')) {
            bHeur = true;
            _sType.remove(0, 1);
        }
    }

    sResult = _translate(_sType);

    if (sResult.size()) {
        sResult[0] = sResult.at(0).toUpper();
    }

    if (bHeur) {
        sResult = QString("(Heur)%1").arg(sResult);
    }

    return sResult;
}

QString XFormats::_translate(const QString &sString)
{
    QString sResult;

    if (sString != "") {
        bool bIsUpper = false;
        sString.at(0).isUpper();
        QString _sString = sString.toLower();

        if (_sString == "apk obfuscator") {
            sResult = QString("APK %1").arg(tr("obfuscator"));
        } else if (_sString == "apk tool") {
            sResult = QString("APK %1").arg(tr("Tool"));
        } else if (_sString == "archive") {
            sResult = tr("Archive");
        } else if (_sString == "certificate") {
            sResult = tr("Certificate");
        } else if (_sString == "compiler") {
            sResult = tr("Compiler");
        } else if (_sString == "converter") {
            sResult = tr("Converter");
        } else if (_sString == "crypter") {
            sResult = tr("Crypter");
        } else if (_sString == "cryptor") {
            sResult = tr("Cryptor");
        } else if (_sString == "data") {
            sResult = tr("Data");
        } else if (_sString == "database") {
            sResult = tr("Database");
        } else if (_sString == "debug data") {
            sResult = tr("Debug data");
        } else if (_sString == "dongle protection") {
            sResult = QString("Dongle %1").arg(tr("protection"));
        } else if (_sString == "dos extender") {
            sResult = QString("DOS %1").arg(tr("extender"));
        } else if (_sString == "format") {
            sResult = tr("Format");
        } else if (_sString == "generic") {
            sResult = tr("Generic");
        } else if (_sString == "image") {
            sResult = tr("Image");
        } else if (_sString == "installer") {
            sResult = tr("Installer");
        } else if (_sString == "installer data") {
            sResult = tr("Installer data");
        } else if (_sString == "jar obfuscator") {
            sResult = QString("JAR %1").arg(tr("obfuscator"));
        } else if (_sString == "joiner") {
            sResult = tr("Joiner");
        } else if (_sString == "language") {
            sResult = tr("Language");
        } else if (_sString == "library") {
            sResult = tr("Library");
        } else if (_sString == "linker") {
            sResult = tr("Linker");
        } else if (_sString == ".net compressor") {
            sResult = QString(".NET %1").arg(tr("compressor"));
        } else if (_sString == ".net obfuscator") {
            sResult = QString(".NET %1").arg(tr("obfuscator"));
        } else if (_sString == "operation system") {
            sResult = tr("Operation system");
        } else if (_sString == "overlay") {
            sResult = tr("Overlay");
        } else if (_sString == "packer") {
            sResult = tr("Packer");
        } else if (_sString == "pe tool") {
            sResult = QString("PE %1").arg(tr("Tool"));
        } else if (_sString == "player") {
            sResult = tr("Player");
        } else if (_sString == "protection") {
            sResult = tr("Protection");
        } else if (_sString == "protector") {
            sResult = tr("Protector");
        } else if (_sString == "protector data") {
            sResult = tr("Protector data");
        } else if (_sString == "sfx data") {
            sResult = QString("SFX %1").arg(tr("data"));
        } else if (_sString == "sign tool") {
            sResult = tr("Sign tool");
        } else if (_sString == "source code") {
            sResult = tr("Source code");
        } else if (_sString == "stub") {
            sResult = tr("Stub");
        } else if (_sString == "tool") {
            sResult = tr("Tool");
        } else if (_sString == "virtual machine") {
            sResult = tr("Virtual machine");
        } else if (_sString == "virus") {
            sResult = tr("Virus");
        } else if (_sString == "trojan") {
            sResult = tr("Trojan");
        } else if (_sString == "malware") {
            sResult = tr("Malware");
        } else if (_sString == "package") {
            sResult = tr("Package");
        } else {
            sResult = _sString;
        }

        if (bIsUpper) {
            sResult[0] = sResult.at(0).toUpper();
        } else {
            sResult[0] = sResult.at(0).toLower();
        }
    }

    return sResult;
}

void XFormats::sortRecords(QList<XBinary::SCANSTRUCT> *pListRecords)
{
    std::sort(pListRecords->begin(), pListRecords->end(), _sortItems);
}

QString XFormats::getProtection(QList<XBinary::SCANSTRUCT> *pListRecords)
{
    QString sResult;

    qint32 nNumberOfRecords = pListRecords->count();

    for (qint32 i = 0; i < nNumberOfRecords; i++) {
        if (pListRecords->at(i).bIsProtection) {
            XBinary::SCANSTRUCT scanStruct = pListRecords->at(i);
            sResult = XBinary::createResultString2(&scanStruct);
            break;
        }
    }

    return sResult;
}

bool XFormats::isProtection(const QString &sType)
{
    bool bResult = false;

    QString _sType = sType;
    _sType = _sType.toLower();

    if ((_sType == "protector") || (_sType == "apk obfuscator") || (_sType == "jar obfuscator") || (_sType == ".net obfuscator") || (_sType == ".net compressor") ||
        (_sType == "dongle protection") || (_sType == "joiner") || (_sType == "packer") || (_sType == "protection") || (_sType == "crypter") || (_sType == "cryptor")) {
        bResult = true;
    }

    return bResult;
}

QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice, qint64 nOffset, qint64 nSize, bool bExtra)
{
    QSet<XBinary::FT> result;

    if (nOffset >= 0) {
        SubDevice sd(pDevice, nOffset, nSize);

        if (sd.open(QIODevice::ReadOnly)) {
            result = getFileTypes(&sd, bExtra);

            sd.close();
        }
    }

    return result;
}

QSet<XBinary::FT> XFormats::getFileTypes(const QString &sFileName, bool bExtra, XBinary::PDSTRUCT *pPdStruct)
{
    QSet<XBinary::FT> stResult;

    QFile file;
    file.setFileName(sFileName);

    if (file.open(QIODevice::ReadOnly)) {
        stResult = getFileTypes(&file, bExtra, pPdStruct);

        file.close();
    }

    return stResult;
}

QSet<XBinary::FT> XFormats::getFileTypes(QByteArray *pbaData, bool bExtra)
{
    QSet<XBinary::FT> stResult;

    QBuffer buffer;

    buffer.setBuffer(pbaData);

    if (buffer.open(QIODevice::ReadOnly)) {
        stResult = getFileTypes(&buffer, bExtra);

        buffer.close();
    }

    return stResult;
}

XBinary::OSINFO XFormats::getOsInfo(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress)
{
    XBinary::OSINFO result = {};

    if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(pDevice, bIsImage, nModuleAddress);
        result = com.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(pDevice, bIsImage, nModuleAddress);
        result = msdos.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(pDevice, bIsImage, nModuleAddress);
        result = ne.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        result = le.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(pDevice, bIsImage, nModuleAddress);
        result = le.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(pDevice, bIsImage, nModuleAddress);
        result = pe.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(pDevice, bIsImage, nModuleAddress);
        result = elf.getOsInfo();
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(pDevice, bIsImage, nModuleAddress);
        result = mach.getOsInfo();
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(pDevice);
        result = dex.getOsInfo();
    }
#endif

    return result;
}

XBinary::FILEFORMATINFO XFormats::getFileFormatInfo(XBinary::FT fileType, QIODevice *pDevice, bool bIsImage, XADDR nModuleAddress, XBinary::PDSTRUCT *pPdStruct,
                                                    qint64 nOffset, qint64 nSize)
{
    XBinary::FILEFORMATINFO result = {};

    QIODevice *_pDevice = nullptr;
    SubDevice *pSubDevice = nullptr;

    if (nOffset != 0) {
        pSubDevice = new SubDevice(pDevice, nOffset, nSize);
        pSubDevice->open(QIODevice::ReadOnly);
        _pDevice = pSubDevice;
    } else {
        _pDevice = pDevice;
    }

    if (XBinary::checkFileType(XBinary::FT_COM, fileType)) {
        XCOM com(_pDevice, bIsImage, nModuleAddress);
        result = com.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MSDOS, fileType)) {
        XMSDOS msdos(_pDevice, bIsImage, nModuleAddress);
        result = msdos.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NE, fileType)) {
        XNE ne(_pDevice, bIsImage, nModuleAddress);
        result = ne.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LE, fileType)) {
        XLE le(_pDevice, bIsImage, nModuleAddress);
        result = le.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LX, fileType)) {
        XLE le(_pDevice, bIsImage, nModuleAddress);
        result = le.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PE, fileType)) {
        XPE pe(_pDevice, bIsImage, nModuleAddress);
        result = pe.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ELF, fileType)) {
        XELF elf(_pDevice, bIsImage, nModuleAddress);
        result = elf.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHO, fileType)) {
        XMACH mach(_pDevice, bIsImage, nModuleAddress);
        result = mach.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_PNG, fileType)) {
        XPNG png(_pDevice);
        result = png.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JPEG, fileType)) {
        XJpeg jpeg(_pDevice);
        result = jpeg.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ICO, fileType)) {
        XIcon xicon(_pDevice);
        result = xicon.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_BMP, fileType)) {
        XBMP xbmp(_pDevice);
        result = xbmp.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GIF, fileType)) {
        XGif xgif(_pDevice);
        result = xgif.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TIFF, fileType)) {
        XTiff xtiff(_pDevice);
        result = xtiff.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP4, fileType)) {
        XMP4 xmp4(_pDevice);
        result = xmp4.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MP3, fileType)) {
        XMP3 xmp3(_pDevice);
        result = xmp3.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RIFF, fileType)) {
        XRiff xriff(_pDevice);
        result = xriff.getFileFormatInfo(pPdStruct);
    }
#ifdef USE_DEX
    else if (XBinary::checkFileType(XBinary::FT_DEX, fileType)) {
        XDEX dex(_pDevice);
        result = dex.getFileFormatInfo(pPdStruct);
    }
#endif
#ifdef USE_PDF
    else if (XBinary::checkFileType(XBinary::FT_PDF, fileType)) {
        XPDF pdf(_pDevice);
        result = pdf.getFileFormatInfo(pPdStruct);
    }
#endif
#ifdef USE_ARCHIVE
    else if (XBinary::checkFileType(XBinary::FT_ZIP, fileType)) {
        XZip zip(_pDevice);
        result = zip.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_JAR, fileType)) {
        XJAR jar(_pDevice);
        result = jar.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_APK, fileType)) {
        XAPK apk(_pDevice);
        result = apk.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_IPA, fileType)) {
        XIPA ipa(_pDevice);
        result = ipa.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_APKS, fileType)) {
        XAPKS apks(_pDevice);
        result = apks.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_AR, fileType)) {
        X_Ar xar(_pDevice);
        result = xar.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_7Z, fileType)) {
        XSevenZip sevenzip(_pDevice);
        result = sevenzip.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_CAB, fileType)) {
        XCab xcab(_pDevice);
        result = xcab.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_RAR, fileType)) {
        XRar xrar(_pDevice);
        result = xrar.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_MACHOFAT, fileType)) {
        XMACHOFat xmachofat(_pDevice);
        result = xmachofat.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_GZIP, fileType)) {
        XGzip xgzip(_pDevice);
        result = xgzip.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TAR, fileType)) {
        XTAR xtar(_pDevice);
        result = xtar.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_TARGZ, fileType)) {
        XTGZ xtgz(_pDevice);
        result = xtgz.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_NPM, fileType)) {
        XNPM xnpm(_pDevice);
        result = xnpm.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_ZLIB, fileType)) {
        XZlib xzlib(_pDevice);
        result = xzlib.getFileFormatInfo(pPdStruct);
    } else if (XBinary::checkFileType(XBinary::FT_LHA, fileType)) {
        XLHA xlha(_pDevice);
        result = xlha.getFileFormatInfo(pPdStruct);
    }
#endif
    else {
        XBinary binary(_pDevice);
        result = binary.getFileFormatInfo(pPdStruct);
    }

    if (pSubDevice) {
        pSubDevice->close();
        delete pSubDevice;
    }

    return result;
}
#ifdef USE_ARCHIVE
QSet<XBinary::FT> XFormats::getFileTypes(QIODevice *pDevice, XArchive::RECORD *pRecord, bool bExtra)
{
    QSet<XBinary::FT> stResult;

    QByteArray baData = XArchives::decompress(pDevice, pRecord, 0, 0, 0x200);

    stResult = XFormats::getFileTypes(&baData, bExtra);

    return stResult;
}
#endif
#ifdef USE_ARCHIVE
QSet<XBinary::FT> XFormats::getFileTypesZIP(QIODevice *pDevice, QList<XArchive::RECORD> *pListRecords, XBinary::PDSTRUCT *pPdStruct)
{
    Q_UNUSED(pDevice)  // TODO

    QSet<XBinary::FT> stResult;

    // XBinary::FT fileType = XZip::_getFileType(pDevice, pListRecords, true);
    stResult.insert(XBinary::FT_ZIP);

    if (XAPK::isValid(pListRecords, pPdStruct)) {
        stResult.insert(XBinary::FT_APK);
        stResult.insert(XBinary::FT_JAR);
    } else if (XIPA::isValid(pListRecords, pPdStruct)) {
        stResult.insert(XBinary::FT_IPA);
    } else if (XJAR::isValid(pListRecords, pPdStruct)) {
        stResult.insert(XBinary::FT_JAR);
    }
    // TODO APKS

    return stResult;
}
#endif
#ifdef USE_ARCHIVE
QSet<XBinary::FT> XFormats::getFileTypesTGZ(QIODevice *pDevice, QList<XArchive::RECORD> *pListRecords, XBinary::PDSTRUCT *pPdStruct)
{
    Q_UNUSED(pDevice)  // TODO

    QSet<XBinary::FT> stResult;

    stResult.insert(XBinary::FT_TARGZ);

    if (XNPM::isValid(pListRecords, pPdStruct)) {
        stResult.insert(XBinary::FT_NPM);
    }

    return stResult;
}

#endif
QSet<XBinary::FT> XFormats::_getFileTypes(QIODevice *pDevice, bool bExtra, XBinary::PDSTRUCT *pPdStruct)
{
    QSet<XBinary::FT> stResult = XBinary::getFileTypes(pDevice, bExtra);
#ifdef USE_ARCHIVE
    if (stResult.contains(XBinary::FT_ZIP)) {
             XZip xzip(pDevice);

        if (xzip.isValid(pPdStruct)) {
            QList<XArchive::RECORD> listArchiveRecords = xzip.getRecords(20000, pPdStruct);

            stResult += getFileTypesZIP(pDevice, &listArchiveRecords, pPdStruct);
        }
    } else if (stResult.contains(XBinary::FT_GZIP)) {
        XGzip xgzip(pDevice);

        if (xgzip.isValid(pPdStruct)) {
            QList<XArchive::RECORD> listArchiveRecords = xgzip.getRecords(1, pPdStruct);

            if (listArchiveRecords.count()) {
                XArchive::RECORD record = listArchiveRecords.at(0);
                QByteArray baData = XArchives::decompress(pDevice, &record, pPdStruct, 0, 0x200);

                QSet<XBinary::FT> _ft = getFileTypes(&baData, true);

                if (_ft.contains(XBinary::FT_TAR)) {
                    XTGZ xtgz(pDevice);
                    QList<XArchive::RECORD> listArchiveRecords = xtgz.getRecords(20000, pPdStruct);

                    stResult += getFileTypesTGZ(pDevice, &listArchiveRecords, pPdStruct);
                }
            }
        }
    }
#endif

    return stResult;
}

#ifdef QT_GUI_LIB
XBinary::FT XFormats::setFileTypeComboBox(XBinary::FT fileType, QIODevice *pDevice, QComboBox *pComboBox, XBinary::TL_OPTION tlOption)
{
    const bool bBlocked1 = pComboBox->blockSignals(true);

    QList<XBinary::FT> listFileTypes;

    if (fileType != XBinary::FT_REGION) {
        QSet<XBinary::FT> stFileType = XFormats::getFileTypes(pDevice, true);

        listFileTypes = XBinary::_getFileTypeListFromSet(stFileType, tlOption);
    } else {
        listFileTypes.append(XBinary::FT_REGION);
    }

    pComboBox->clear();

    qint32 nNumberOfListTypes = listFileTypes.count();

    for (qint32 i = 0; i < nNumberOfListTypes; i++) {
        XBinary::FT fileType = listFileTypes.at(i);
        pComboBox->addItem(XBinary::fileTypeIdToString(fileType), fileType);
    }

    if (nNumberOfListTypes) {
        if (fileType == XBinary::FT_UNKNOWN) {
            if (pComboBox->itemData(nNumberOfListTypes - 1).toUInt() != XBinary::FT_COM) {
                pComboBox->setCurrentIndex(nNumberOfListTypes - 1);
            }
        } else {
            qint32 nNumberOfItems = pComboBox->count();

            for (qint32 i = 0; i < nNumberOfItems; i++) {
                if (pComboBox->itemData(i).toUInt() == fileType) {
                    pComboBox->setCurrentIndex(i);

                    break;
                }
            }
        }
    }

    pComboBox->blockSignals(bBlocked1);

    return (XBinary::FT)(pComboBox->currentData().toUInt());
}
#endif
#ifdef QT_GUI_LIB
XBinary::FT XFormats::setFileTypeComboBox(XBinary::FT fileType, const QString &sFileName, QComboBox *pComboBox, XBinary::TL_OPTION tlOption)
{
    XBinary::FT result = XBinary::FT_UNKNOWN;

    QFile file;
    file.setFileName(sFileName);

    if (file.open(QIODevice::ReadOnly)) {
        result = setFileTypeComboBox(fileType, &file, pComboBox, tlOption);

        file.close();
    }

    return result;
}
#endif
#ifdef QT_GUI_LIB
bool XFormats::setEndiannessComboBox(QComboBox *pComboBox, XBinary::ENDIAN endian)
{
    const bool bBlocked1 = pComboBox->blockSignals(true);

    bool bResult = endian;

    pComboBox->clear();

    pComboBox->addItem(XBinary::endianToString(XBinary::ENDIAN_LITTLE), XBinary::ENDIAN_LITTLE);
    pComboBox->addItem(XBinary::endianToString(XBinary::ENDIAN_BIG), XBinary::ENDIAN_BIG);

    if (endian == XBinary::ENDIAN_BIG) {
        pComboBox->setCurrentIndex(1);
    }

    pComboBox->blockSignals(bBlocked1);

    return bResult;
}
#endif
#ifdef QT_GUI_LIB
XBinary::MAPMODE XFormats::getMapModesList(XBinary::FT fileType, QComboBox *pComboBox)
{
    XBinary::MAPMODE result = XBinary::MAPMODE_UNKNOWN;

    const bool bBlocked1 = pComboBox->blockSignals(true);

    pComboBox->clear();

    QList<XBinary::MAPMODE> listMapModes = getMapModesList(fileType);

    qint32 nNumberOfRecords = listMapModes.count();

    if (nNumberOfRecords) {
        result = listMapModes.at(0);

        for (qint32 i = 0; i < nNumberOfRecords; i++) {
            XBinary::MAPMODE record = listMapModes.at(i);
            pComboBox->addItem(XBinary::mapModeToString(record), record);
        }
    }

    pComboBox->blockSignals(bBlocked1);

    return result;
}
#endif
#ifdef QT_GUI_LIB
void XFormats::setProgressBar(QProgressBar *pProgressBar, XBinary::PDRECORD pdRecord)
{
    if ((pdRecord.nTotal) || (pdRecord.sStatus != "")) {
        pProgressBar->show();

        if (pdRecord.nTotal) {
            pProgressBar->setMaximum(pdRecord.nTotal);
            pProgressBar->setValue(pdRecord.nCurrent);
        }

        if (pdRecord.sStatus != "") {
            pProgressBar->setFormat(pdRecord.sStatus);
        }
    } else {
        pProgressBar->hide();
    }
}
#endif
