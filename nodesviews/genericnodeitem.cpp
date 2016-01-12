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

#include "genericnodeitem.h"

#include <QPainter>
#include <QTimer>

#include "nodes/abstractnode.h"
#include "nodesviews/customitems.h"
#include "nodesviews/plugitem.h"


GenericNodeItem::GenericNodeItem(AbstractNode *node, QGraphicsItem *parent) :
    QGraphicsItem(parent),
    _node(node),
    _inputPlugs(),
    _outputPlugs()
{
    foreach(Plug *input, _node->getInputs())
    {
        _inputPlugs << new PlugItem(input, this);
    }

    foreach(Plug *output, _node->getOutputs())
    {
        _outputPlugs << new PlugItem(output, this);
    }

    QTimer::singleShot(0, this, SLOT(updatePlugs()));
}

int GenericNodeItem::type() const
{
    return CustomItems::Node;
}

const AbstractNode *GenericNodeItem::getNode() const
{
    return _node;
}

const QList<PlugItem *> &GenericNodeItem::getInputs() const
{
    return _inputPlugs;
}

const QList<PlugItem *> &GenericNodeItem::getOutputs() const
{
    return _outputPlugs;
}

QRectF GenericNodeItem::boundingRect() const
{
    return QRectF(0, 0, 100, 30);
}

void GenericNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect());
    painter->drawText(boundingRect().adjusted(0, 5, 0, 0),
                      Qt::AlignHCenter | Qt::AlignTop,
                      _node->getUserReadableName());
}

void GenericNodeItem::updatePlugs()
{
    for(quint8 i = 0 ; i < _node->getNbInputs() ; i++)
    {
        _inputPlugs[i]->setPos(QPointF(boundingRect().left(), ((i + 1.0) / (_node->getNbInputs() + 1)) * boundingRect().height()));
    }

    for(quint8 i = 0 ; i < _node->getNbOutputs() ; i++)
    {
        _outputPlugs[i]->setPos(QPointF(boundingRect().right(), ((i + 1.0) / (_node->getNbOutputs() + 1)) * boundingRect().height()));
    }
}
