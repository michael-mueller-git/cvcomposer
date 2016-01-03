#include "nodestypesmanager.h"

#include <QDebug>

#include "nodes/blurnode.h"
#include "nodes/imagefilenode.h"
#include "nodes/imagepreviewernode.h"


NodesTypesManager *NodesTypesManager::_instance = NULL;

NodesTypesManager::NodesTypesManager()
{
}

NodesTypesManager *NodesTypesManager::get()
{
    if(_instance == NULL)
    {
        _instance = new NodesTypesManager();
    }

    return _instance;
}

QList<QTreeWidgetItem *> NodesTypesManager::getTreeItems()
{
    QList<QTreeWidgetItem *> result;

    QTreeWidgetItem *inputs = new QTreeWidgetItem(QStringList() << tr("Inputs"));
    inputs->setFlags(inputs->flags() & ~Qt::ItemIsDragEnabled);
    QTreeWidgetItem *itemFile = new QTreeWidgetItem(inputs, QStringList() << tr("Image from file"));
    itemFile->setData(0, Qt::UserRole, "imagefile");
    result << inputs;

    QTreeWidgetItem *viewers = new QTreeWidgetItem(QStringList() << tr("Viewers"));
    viewers->setFlags(viewers->flags() & ~Qt::ItemIsDragEnabled);
    QTreeWidgetItem *itemDockableViewer = new QTreeWidgetItem(viewers, QStringList() << tr("Dockable image viewer"));
    itemDockableViewer->setData(0, Qt::UserRole, "dockableimageviewer");
    QTreeWidgetItem *itemPreviewer = new QTreeWidgetItem(viewers, QStringList() << tr("Image previewer"));
    itemPreviewer->setData(0, Qt::UserRole, "imagepreviewer");
    result << viewers;

    QTreeWidgetItem *filters = new QTreeWidgetItem(QStringList() << tr("Filters"));
    filters->setFlags(viewers->flags() & ~Qt::ItemIsDragEnabled);
    QTreeWidgetItem *itemBlur = new QTreeWidgetItem(filters, QStringList() << tr("Blur"));
    itemBlur->setData(0, Qt::UserRole, "blur");
    QTreeWidgetItem *itemGaussianBlur = new QTreeWidgetItem(filters, QStringList() << tr("Gaussian blur"));
    itemGaussianBlur->setData(0, Qt::UserRole, "gaussianblur");
    result << filters;

    return result;
}

AbstractNode *NodesTypesManager::createNode(const QString &type)
{
    if(type == "imagepreviewer")
    {
        return new ImagePreviewerNode();
    }
    else if(type == "blur")
    {
        return new BlurNode();
    }
    else if(type == "imagefile")
    {
        return new ImageFileNode();
    }
    else
    {
        qCritical() << "Unable to instantiate node for type" << type;
        return NULL;
    }
}
