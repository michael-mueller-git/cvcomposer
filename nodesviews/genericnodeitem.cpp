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

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QPainter>
#include <QTimer>

#include "genericnode.h"
#include "nodesviews/customitems.h"
#include "nodesviews/plugitem.h"
#include "nodesviews/genericnodewidget.h"
#include "plug.h"


GenericNodeItem::GenericNodeItem(GenericNode *node, QGraphicsItem *parent) :
    QGraphicsItem(parent),
    _node(node),
    _widget(new GenericNodeWidget()),
    _inputPlugs(),
    _outputPlugs()
{
    _widget->setPlugs(node->getInputs(), node->getOutputs());
    _widget->setFixedSize(_widget->sizeHint());
    _widget->setAutoFillBackground(false);
    _widget->setAttribute(Qt::WA_NoBackground, true);

    connect(_widget, SIGNAL(propertyChanged(QString,QVariant)),
            node,    SLOT(setProperty(QString,QVariant)));
    connect(node,    SIGNAL(processDone(Properties,Properties)),
            _widget, SLOT(onProcessDone(Properties,Properties)));
    connect(node,    SIGNAL(processUnavailable()),
            _widget, SLOT(onProcessUnavailable()));

    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(_widget);
    proxy->setPos(2 * PlugItem::radius, 30 + PlugItem::radius);

    foreach(Plug *plug, _node->getInputs())
    {
        if(PlugType::isInputPluggable(plug->getDefinition().type) != PlugType::ManualOnly)
        {
            _inputPlugs << new PlugItem(plug, this);
            connect(plug, SIGNAL(connectionChanged(const Plug*)),
                          SLOT(onPlugConnectionChanged(const Plug*)));
        }
    }
    foreach(Plug *plug, _node->getOutputs())
    {
        _outputPlugs << new PlugItem(plug, this);
    }

    QTimer::singleShot(0, this, SLOT(updatePlugs()));
}

int GenericNodeItem::type() const
{
    return CustomItems::Node;
}

const GenericNode *GenericNodeItem::getNode() const
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
    if(_widget)
    {
        return QRectF(0,
                      0,
                      _widget->sizeHint().width() + 4 * PlugItem::radius,
                      30 + _widget->sizeHint().height() + 2 * PlugItem::radius);
    }
    else
    {
        return QRectF(0, 0, 100, 30);
    }
}

void GenericNodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    qreal semiWidth = painter->pen().widthF() / 2;

    painter->setBrush(Qt::white);
    painter->drawRect(boundingRect().adjusted(semiWidth, semiWidth, -semiWidth, -semiWidth));
    painter->drawText(boundingRect().adjusted(0, 5, 0, 0),
                      Qt::AlignHCenter | Qt::AlignTop,
                      _node->getUserReadableName());
}

void GenericNodeItem::updatePlugs()
{
    foreach(PlugItem *plug, _inputPlugs)
    {
        plug->setPos(QPointF(boundingRect().left(),
                              _widget->y() + _widget->getPlugPosY(plug->getPlug()->getDefinition().name)));
    }
    foreach(PlugItem *plug, _outputPlugs)
    {
        plug->setPos(QPointF(boundingRect().right(),
                              _widget->y() + _widget->getPlugPosY(plug->getPlug()->getDefinition().name)));
    }
}

void GenericNodeItem::onPlugConnectionChanged(const Plug *connectedTo)
{
    Plug *plug = qobject_cast<Plug *>(sender());
    if(plug)
    {
        _widget->setInputPlugged(plug->getDefinition().name, connectedTo != NULL);
    }
    else
    {
        qCritical() << "GenericNodeItem::onPlugConnectionChanged" << "Sender is not a Plug";
    }
}
