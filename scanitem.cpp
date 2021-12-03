// Copyright (c) 2017-2021 hors<horsicq@gmail.com>
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
#include "scanitem.h"

ScanItem::ScanItem(const QString &sString, ScanItem *pParentItem, qint32 nNumberOfColumns)
{
    this->g_pParentItem=pParentItem;
    this->g_sString=sString;
    this->g_nNumberOfColumns=nNumberOfColumns;
}

ScanItem::~ScanItem()
{
    qDeleteAll(g_listChildItems);
}

void ScanItem::appendChild(ScanItem *pChild)
{
    g_listChildItems.append(pChild);
}

ScanItem *ScanItem::child(int nRow)
{
    return g_listChildItems.value(nRow);
}

int ScanItem::childCount() const
{
    return g_listChildItems.count();
}

int ScanItem::columnCount() const
{
    return g_nNumberOfColumns;
}

QVariant ScanItem::data(int nColumn) const
{
    QVariant result;

    if(nColumn==0)
    {
        result=g_sString;
    }

    return result;
}

void ScanItem::setScanStruct(const XBinary::SCANSTRUCT &scanStruct)
{
    this->g_scanStruct=scanStruct;
}

XBinary::SCANSTRUCT ScanItem::scanStruct() const
{
    return g_scanStruct;
}

int ScanItem::row() const
{
    int nResult=0;

    if(g_pParentItem)
    {
        nResult=g_pParentItem->g_listChildItems.indexOf(const_cast<ScanItem*>(this));
    }

    return nResult;
}

ScanItem *ScanItem::getParentItem()
{
    return g_pParentItem;
}
