// Copyright 2016 Erwan MATHIEU <wawanbreton@gmail.com>
//
// This file is part of CvComposer.
//
// CvComposer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CvComposer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CvComposer.  If not, see <http://www.gnu.org/licenses/>.

#include "plugitem.h"

#include <QBrush>
#include <QCursor>

#include "nodesviews/customitems.h"


PlugItem::PlugItem(Plug *plug, QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent),
    _plug(plug)
{
    setRect(-radius, -radius, radius * 2, radius * 2);
    setBrush(Qt::white);
}

int PlugItem::type() const
{
    return CustomItems::Plug;
}

Plug *PlugItem::getPlug() const
{
    return _plug;
}
